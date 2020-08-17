/*
 * randi.c
 *
 * Code generation for function 'randi'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "myRANSAC.h"
#include "randi.h"
#include "rand.h"

/* Function Definitions */
real_T randi(real_T lowhigh)
{
  real_T r;
  r = b_rand();
  return 1.0 + muDoubleScalarFloor(r * lowhigh);
}

/* End of code generation (randi.c) */
