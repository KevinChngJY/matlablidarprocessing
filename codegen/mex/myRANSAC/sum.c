/*
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myRANSAC.h"
#include "sum.h"

/* Function Definitions */
real_T sum(const boolean_T x_data[], const int32_T x_size[2])
{
  real_T y;
  int32_T vlen;
  int32_T k;
  vlen = x_size[1];
  if (x_size[1] == 0) {
    y = 0.0;
  } else {
    y = x_data[0];
    for (k = 2; k <= vlen; k++) {
      y += (real_T)x_data[k - 1];
    }
  }

  return y;
}

/* End of code generation (sum.c) */
