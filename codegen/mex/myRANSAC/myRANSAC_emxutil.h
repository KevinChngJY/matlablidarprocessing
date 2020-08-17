/*
 * myRANSAC_emxutil.h
 *
 * Code generation for function 'myRANSAC_emxutil'
 *
 */

#ifndef MYRANSAC_EMXUTIL_H
#define MYRANSAC_EMXUTIL_H

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
extern void emxEnsureCapacity_real32_T(const emlrtStack *sp, emxArray_real32_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxFree_real32_T(emxArray_real32_T **pEmxArray);
extern void emxInit_real32_T(const emlrtStack *sp, emxArray_real32_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);

#endif

/* End of code generation (myRANSAC_emxutil.h) */
