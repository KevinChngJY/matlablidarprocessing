/*
 * File: myRANSAC.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 25-Aug-2019 11:14:33
 */

#ifndef MYRANSAC_H
#define MYRANSAC_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "myRANSAC_types.h"

/* Function Declarations */
extern void myRANSAC(const emxArray_real32_T *x, const emxArray_real32_T *y,
                     const emxArray_real32_T *z, double MaxIterations, double
                     distanceTol, bool idx_inliers_saved_data[], int
                     idx_inliers_saved_size[2]);

#endif

/*
 * File trailer for myRANSAC.h
 *
 * [EOF]
 */
