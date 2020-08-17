%% Ground Plane and Obstacle Detection Using Lidar
% This example shows how to process 3-D Lidar data from a sensor mounted on
% a vehicle by segmenting the ground plane and finding nearby obstacles.
% This can facilitate drivable path planning for vehicle navigation. The
% example also shows how to visualize streaming Lidar data.
%
% Copyright 2016-2018 The MathWorks, Inc.
clear all
clc
%% Create a VelodyneFileReader
% The Lidar data used in this example was recorded using a Velodyne HDL32E
% sensor mounted on a vehicle. Setup a <matlab:doc('velodyneFileReader') |velodyneFileReader|> object to read
% the recorded PCAP file.

fileName    = 'lidarData_ConstructionRoad.pcap';
deviceModel = 'HDL32E';

veloReader = velodyneFileReader(fileName, deviceModel);

%% Read a Lidar scan
% Each scan of Lidar data is stored as a 3-D point cloud. Efficiently
% processing this data using fast indexing and search is key to the
% performance of the sensor processing pipeline. This efficiency is
% achieved using the <matlab:doc('pointCloud') |pointCloud|> object, which internally organizes the
% data using a K-d tree data structure. 
%
% The |veloReader| constructs an organized |pointCloud| for each Lidar
% scan. The |Location| property of the |pointCloud| is an M-by-N-by-3
% matrix, containing the XYZ coordinates of points in meters. The point
% intensities are stored in |Intensity|.

% Read a scan of Lidar data
ptCloud = readFrame(veloReader) %#ok<NOPTS>

%% Setup Streaming Point Cloud Display
% The |pcplayer| can be used to visualize streaming point cloud data. Setup
% the region around the vehicle to display by configuring
% <matlab:doc('pcplayer') |pcplayer|>.

% Specify limits of point cloud display
xlimits = [-25 45]; % meters
ylimits = [-25 45];
zlimits = [-20 20];

% Create a pcplayer
lidarViewer = pcplayer(xlimits, ylimits, zlimits);

% Customize player axes labels
xlabel(lidarViewer.Axes, 'X (m)')
ylabel(lidarViewer.Axes, 'Y (m)')
zlabel(lidarViewer.Axes, 'Z (m)')

% Display the raw Lidar scan
view(lidarViewer, ptCloud)

%%
% In this example, we will be segmenting points belonging to the ground
% plane, the ego vehicle and nearby obstacles. Set the colormap for
% labeling these points.

% Define labels to use for segmented points
colorLabels = [...
    0      0.4470 0.7410; ... % Unlabeled points, specified as [R,G,B]
    0.4660 0.6740 0.1880; ... % Ground points
    0.9290 0.6940 0.1250; ... % Ego points
    0.6350 0.0780 0.1840];    % Obstacle points

% Define indices for each label
colors.Unlabeled = 1;
colors.Ground    = 2;
colors.Ego       = 3;
colors.Obstacle  = 4;

% Set the colormap
colormap(lidarViewer.Axes, colorLabels)

%% Segment the Ego Vehicle
% The Lidar is mounted on top of the vehicle, and the point cloud may
% contain points belonging to the vehicle itself, such as on the roof or
% hood. Knowing the dimensions of the vehicle, we can segment out points
% that are closest to the vehicle.

%%
% Create a <matlab:doc('vehicleDimensions') |vehicleDimensions|> object for
% storing dimensions of the vehicle.
vehicleDims = vehicleDimensions(); % Typical vehicle 4.7m by 1.8m by 1.4m

%%
% Specify the mounting location of the Lidar in the vehicle coordinate
% system. The vehicle coordinate system is centered at the center of the
% rear-axle, on the ground, with positive X direction pointing forward,
% positive Y towards the left, and positive Z upwards. In this example, the
% Lidar is mounted on the top center of the vehicle, parallel to the
% ground. 

mountLocation = [...
    vehicleDims.Length/2 - vehicleDims.RearOverhang, ... % x
    0, ...                                               % y
    vehicleDims.Height];                                 % z

%%
% Segment the ego vehicle using the helper function
% |helperSegmentEgoFromLidarData|. This function segments all points within
% the cuboid defined by the ego vehicle. Store the segmented points in a
% struct |points|.
points = struct();
points.EgoPoints = helperSegmentEgoFromLidarData(ptCloud, vehicleDims, mountLocation);

%
% Visualize the point cloud with segmented ego vehicle. Use the
% |helperUpdateView| helper function.
closePlayer = false;
helperUpdateView(lidarViewer, ptCloud, points, colors, closePlayer);

% Segment Ground Plane and Nearby Obstacles
% In order to identify obstacles from the Lidar data, first segment the
% ground plane using the <matlab:doc('segmentGroundFromLidarData')
% |segmentGroundFromLidarData|> function to accomplish this. This function
% segments points belonging to ground from organized Lidar data.
elevationDelta = 10;
GroundPoints1 = segmentGroundFromLidarData(ptCloud, 'ElevationAngleDelta', elevationDelta);

x = reshape(ptCloud.Location(:,:,1),1,ptCloud.Count);
y = reshape(ptCloud.Location(:,:,2),1,ptCloud.Count);
z = reshape(ptCloud.Location(:,:,3),1,ptCloud.Count);

distanceTol = 0.6;
MaxIterations = 300;
points.GroundPoints = reshape(myRANSAC(x,y,z,MaxIterations,distanceTol),32,1083);

% Verify the difference between Mathworks Shipped Function Versus my
% function
hold off
plot(reshape(GroundPoints1(1:100),1,100),'x')
hold on
plot(reshape(points.GroundPoints(1:100),1,100),'o')

% Visualize the segmented ground plane.
helperUpdateView(lidarViewer, ptCloud, points, colors, closePlayer);

%%
% Remove points belonging to the ego vehicle and the ground plane using the
% <matlab:doc('pointCloud/select') |select|> function. Specify the
% |'OutputSize'| as |'full'| to retain the organized nature of the
% point cloud.
nonEgoGroundPoints = ~points.EgoPoints & ~points.GroundPoints;
ptCloudSegmented = select(ptCloud, nonEgoGroundPoints, 'OutputSize', 'full');

%%
% Next, segment nearby obstacles by looking for all points that are not
% part of the ground or ego vehicle within some radius from the ego
% vehicle. This radius can be determined based on the range of the Lidar
% and area of interest for further processing.
sensorLocation  = [0, 0, 0]; % Sensor is at the center of the coordinate system
radius          = 40; % meters

points.ObstaclePoints = findNeighborsInRadius(ptCloudSegmented, ...
    sensorLocation, radius);

% Visualize the segmented obstacles
helperUpdateView(lidarViewer, ptCloud, points, colors, closePlayer);

%% Process Lidar sequence
% Now that the point cloud processing pipeline for a single Lidar scan has
% been laid out, put this all together to process 30 seconds from the
% sequence of recorded data. The code below is shortened since the key
% parameters have been defined in the previous steps. Here, the parameters
% are used without further explanation.

% Rewind the |veloReader| to start from the beginning of the sequence
reset(veloReader);

% Stop processing after 30 seconds
stopTime = veloReader.StartTime + seconds(30);

isPlayerOpen = true;
while hasFrame(veloReader) && veloReader.CurrentTime < stopTime && isPlayerOpen
    
    % Grab the next Lidar scan
    ptCloud = readFrame(veloReader);
    [a1 b1 c1] = size(ptCloud.Location);
    
    % Segment points belonging to the ego vehicle
    points.EgoPoints = helperSegmentEgoFromLidarData(ptCloud, vehicleDims, mountLocation);
    
    % Segment points belonging to the ground plane
        x = reshape(ptCloud.Location(:,:,1),1,ptCloud.Count);
        y = reshape(ptCloud.Location(:,:,2),1,ptCloud.Count);
        z = reshape(ptCloud.Location(:,:,3),1,ptCloud.Count);
        distanceTol = 0.3;
        MaxIterations = 300;
        % MATLAB Function
        %points.GroundPoints = reshape(myRANSAC(x,y,z,MaxIterations,distanceTol),32,b1);
        % MATLAB Coder
        points.GroundPoints = reshape(myRANSAC_mex(x,y,z,MaxIterations,distanceTol),32,b1);
    
    % Mathworks own code
        %points.GroundPoints = segmentGroundFromLidarData(ptCloud, 'ElevationAngleDelta', elevationDelta);
    
    % Remove points belonging to the ego vehicle and ground plane
    nonEgoGroundPoints = ~points.EgoPoints & ~points.GroundPoints;
    ptCloudSegmented = select(ptCloud, nonEgoGroundPoints, 'OutputSize', 'full');
    
    % Segment obstacles
    points.ObstaclePoints = findNeighborsInRadius(ptCloudSegmented, sensorLocation, radius);
    
    closePlayer = ~hasFrame(veloReader);
    
    % Update Lidar display
    isPlayerOpen = helperUpdateView(lidarViewer, ptCloud, points, colors, closePlayer);
end
snapnow

%% Supporting Functions
% |helperSegmentEgoFromLidarData| segments points belonging to the ego
% vehicle given the dimensions of the vehicle and mounting location.
function egoPoints = helperSegmentEgoFromLidarData(ptCloud, vehicleDims, mountLocation)
%helperSegmentEgoFromLidarData segment ego vehicle points from Lidar data
%   egoPoints = helperSegmentEgoFromLidarData(ptCloud,vehicleDims,mountLocation)
%   segments points belonging to the ego vehicle of dimensions vehicleDims
%   from the Lidar scan ptCloud. The Lidar is mounted at location specified
%   by mountLocation in the vehicle coordinate system. ptCloud is a
%   pointCloud object. vehicleDimensions is a vehicleDimensions object.
%   mountLocation is a 3-element vector specifying XYZ location of the
%   Lidar in the vehicle coordinate system.
%
%   This function assumes that the Lidar is mounted parallel to the ground
%   plane, with positive X direction pointing ahead of the vehicle,
%   positive Y direction pointing to the left of the vehicle in a
%   right-handed system.

% Buffer around ego vehicle 
bufferZone = [0.1, 0.1, 0.1]; % in meters

% Define ego vehicle limits in vehicle coordinates
egoXMin = -vehicleDims.RearOverhang - bufferZone(1);
egoXMax = egoXMin + vehicleDims.Length + bufferZone(1);
egoYMin = -vehicleDims.Width/2 - bufferZone(2);
egoYMax = egoYMin + vehicleDims.Width + bufferZone(2);
egoZMin = 0 - bufferZone(3);
egoZMax = egoZMin + vehicleDims.Height + bufferZone(3);

egoXLimits = [egoXMin, egoXMax];
egoYLimits = [egoYMin, egoYMax];
egoZLimits = [egoZMin, egoZMax];

% Transform to Lidar coordinates
egoXLimits = egoXLimits - mountLocation(1);
egoYLimits = egoYLimits - mountLocation(2);
egoZLimits = egoZLimits - mountLocation(3);

% Use logical indexing to select points inside ego vehicle cube
egoPoints = ptCloud.Location(:,:,1) > egoXLimits(1) ...
    & ptCloud.Location(:,:,1) < egoXLimits(2) ...
    & ptCloud.Location(:,:,2) > egoYLimits(1) ...
    & ptCloud.Location(:,:,2) < egoYLimits(2) ...
    & ptCloud.Location(:,:,3) > egoZLimits(1) ...
    & ptCloud.Location(:,:,3) < egoZLimits(2);
end

%%
% |helperUpdateView| updates the streaming point cloud display with the
% latest point cloud and associated color labels.
function isPlayerOpen = helperUpdateView(lidarViewer, ptCloud, points, colors, closePlayer)
%helperUpdateView update streaming point cloud display
%   isPlayerOpen = helperUpdateView(lidarViewer, ptCloud, points, colors, closePlayers)
%   updates the pcplayer object specified in lidarViewer with a new point
%   cloud ptCloud. Points specified in the struct points are colored
%   according to the colormap of lidarViewer using the labels specified by
%   the struct colors. closePlayer is a flag indicating whether to close
%   the lidarViewer.

if closePlayer
    hide(lidarViewer);
    isPlayerOpen = false;
    return;
end
    
scanSize = size(ptCloud.Location);
scanSize = scanSize(1:2);

% Initialize colormap
colormapValues = ones(scanSize, 'like', ptCloud.Location) * colors.Unlabeled;

if isfield(points, 'GroundPoints')
    colormapValues(points.GroundPoints) = colors.Ground;
end

if isfield(points, 'EgoPoints')
    colormapValues(points.EgoPoints) = colors.Ego;
end

if isfield(points, 'ObstaclePoints')
    colormapValues(points.ObstaclePoints) = colors.Obstacle;
end

% Update view
view(lidarViewer, ptCloud.Location, colormapValues)

% Check if player is open
isPlayerOpen = isOpen(lidarViewer);

end
