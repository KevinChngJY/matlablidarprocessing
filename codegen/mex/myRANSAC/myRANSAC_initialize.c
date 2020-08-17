/*
 * myRANSAC_initialize.c
 *
 * Code generation for function 'myRANSAC_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myRANSAC.h"
#include "myRANSAC_initialize.h"
#include "_coder_myRANSAC_mex.h"
#include "myRANSAC_data.h"

/* Function Definitions */
void myRANSAC_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (myRANSAC_initialize.c) */
