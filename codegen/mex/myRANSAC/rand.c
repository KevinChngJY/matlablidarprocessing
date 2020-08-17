/*
 * rand.c
 *
 * Code generation for function 'rand'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myRANSAC.h"
#include "rand.h"

/* Function Definitions */
real_T b_rand(void)
{
  real_T r;
  emlrtRandu(&r, 1);
  return r;
}

/* End of code generation (rand.c) */
