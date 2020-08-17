/*
 * myRANSAC.h
 *
 * Code generation for function 'myRANSAC'
 *
 */

#ifndef MYRANSAC_H
#define MYRANSAC_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "myRANSAC_types.h"

/* Function Declarations */
extern void myRANSAC(const emlrtStack *sp, const emxArray_real32_T *x, const
                     emxArray_real32_T *y, const emxArray_real32_T *z, real_T
                     MaxIterations, real_T distanceTol, boolean_T
                     idx_inliers_saved_data[], int32_T idx_inliers_saved_size[2]);

#endif

/* End of code generation (myRANSAC.h) */
