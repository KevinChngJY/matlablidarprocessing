/*
 * File: myRANSAC_initialize.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 25-Aug-2019 11:14:33
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "myRANSAC.h"
#include "myRANSAC_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void myRANSAC_initialize(void)
{
  rt_InitInfAndNaN(8U);
  c_eml_rand_mt19937ar_stateful_i();
}

/*
 * File trailer for myRANSAC_initialize.c
 *
 * [EOF]
 */
