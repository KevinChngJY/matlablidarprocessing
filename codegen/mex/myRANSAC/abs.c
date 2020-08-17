/*
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "myRANSAC.h"
#include "abs.h"
#include "myRANSAC_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo f_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "abs",                               /* fName */
  "C:\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m"/* pName */
};

/* Function Definitions */
void b_abs(const emlrtStack *sp, const emxArray_real32_T *x, emxArray_real32_T
           *y)
{
  int32_T nx;
  int32_T k;
  nx = x->size[1];
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (uint16_T)x->size[1];
  emxEnsureCapacity_real32_T(sp, y, k, &f_emlrtRTEI);
  for (k = 0; k < nx; k++) {
    y->data[k] = muSingleScalarAbs(x->data[k]);
  }
}

/* End of code generation (abs.c) */
