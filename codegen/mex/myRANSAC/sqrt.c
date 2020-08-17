/*
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "myRANSAC.h"
#include "sqrt.h"

/* Variable Definitions */
static emlrtRTEInfo j_emlrtRTEI = { 12,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

/* Function Definitions */
void b_sqrt(const emlrtStack *sp, real32_T *x)
{
  if (*x < 0.0F) {
    emlrtErrorWithMessageIdR2018a(sp, &j_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  *x = muSingleScalarSqrt(*x);
}

/* End of code generation (sqrt.c) */
