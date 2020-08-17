function  idx_inliers_saved = myRANSAC(x,y,z,MaxIterations,distanceTol)
sizeOfliners = 0;
idx_inliers_saved = false(1,length(x));

for cnt = 1:MaxIterations
    pt1 = randi(length(x));
    pt2 = randi(length(x));
    pt3 = randi(length(x));

    %Some of the data are NaN, if it is so i will generate another random
    %value to pick for that specific point. I would assume that in real
    %world scenario this has been already filtered out.
    while(isnan(x(pt1))||isnan(y(pt1))||isnan(z(pt1)))
        pt1 = randi(length(x));
        %display([x(pt1) y(pt1) z(pt1)]);
    end
    while(isnan(x(pt2))||isnan(y(pt2))||isnan(z(pt2)))
        pt2 = randi(length(x));
        %display([x(pt2) y(pt2) z(pt2)]);
    end
    while(isnan(x(pt3))||isnan(y(pt3))||isnan(z(pt3)))
        pt3 = randi(length(x));
        %display([x(pt3) y(pt3) z(pt3)]);
    end

    % assign point 1
    x1 = x(pt1);
    y1 = y(pt1);
    z1 = z(pt1);
    
    % assign point 2
    x2 = x(pt2);
    y2 = y(pt2);
    z2 = z(pt2);
    
    % assign point 3
    x3 = x(pt3);
    y3 = y(pt3);
    z3 = z(pt3);
    
    %display([x1 y1 z1])
    %display([x2 y2 z2])
    %display([x3 y3 z3])

    v1_1 = x2-x1;
    v1_2 = y2-y1;
    v1_3 = z2-z1;

    v2_1 = x3-x1;
    v2_2 = y3-y1;
    v2_3 = z3-z1;

    A = (v1_2*v1_3 - v1_3*v1_2);
    B = (v1_1*v2_3 - v1_3*v2_1);
    C = (v1_1*v2_2 - v1_2*v2_1);
    D = -1*(A*x1 + B*y1 + C*z1);


    d = abs(A*x + B*y + C*z + D)/sqrt(A*A + B*B + C*C);
    
    % Easy vector operation by MATLAB
    idx_inliers = d <= distanceTol;

    % This will try to record the who among the MaxIterations holds the
    % most number of inliers.
    if sizeOfliners < sum(idx_inliers)
        sizeOfliners = sum(idx_inliers);
        idx_inliers_saved = idx_inliers;
        %display(sizeOfliners)
    end
end