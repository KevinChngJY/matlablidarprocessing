/*
 * File: _coder_myRANSAC_api.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 25-Aug-2019 11:14:33
 */

#ifndef _CODER_MYRANSAC_API_H
#define _CODER_MYRANSAC_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_myRANSAC_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T

struct emxArray_real32_T
{
  real32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real32_T*/

#ifndef typedef_emxArray_real32_T
#define typedef_emxArray_real32_T

typedef struct emxArray_real32_T emxArray_real32_T;

#endif                                 /*typedef_emxArray_real32_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void myRANSAC(emxArray_real32_T *x, emxArray_real32_T *y,
                     emxArray_real32_T *z, real_T MaxIterations, real_T
                     distanceTol, boolean_T idx_inliers_saved_data[], int32_T
                     idx_inliers_saved_size[2]);
extern void myRANSAC_api(const mxArray * const prhs[5], int32_T nlhs, const
  mxArray *plhs[1]);
extern void myRANSAC_atexit(void);
extern void myRANSAC_initialize(void);
extern void myRANSAC_terminate(void);
extern void myRANSAC_xil_shutdown(void);
extern void myRANSAC_xil_terminate(void);

#endif

/*
 * File trailer for _coder_myRANSAC_api.h
 *
 * [EOF]
 */
