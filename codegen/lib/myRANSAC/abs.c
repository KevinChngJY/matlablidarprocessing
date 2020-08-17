/*
 * File: abs.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 25-Aug-2019 11:14:33
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "myRANSAC.h"
#include "abs.h"
#include "myRANSAC_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real32_T *x
 *                emxArray_real32_T *y
 * Return Type  : void
 */
void b_abs(const emxArray_real32_T *x, emxArray_real32_T *y)
{
  int nx;
  int k;
  nx = x->size[1];
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (unsigned short)x->size[1];
  emxEnsureCapacity_real32_T(y, k);
  for (k = 0; k < nx; k++) {
    y->data[k] = fabsf(x->data[k]);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
