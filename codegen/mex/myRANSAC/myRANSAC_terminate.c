/*
 * myRANSAC_terminate.c
 *
 * Code generation for function 'myRANSAC_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myRANSAC.h"
#include "myRANSAC_terminate.h"
#include "_coder_myRANSAC_mex.h"
#include "myRANSAC_data.h"

/* Function Definitions */
void myRANSAC_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void myRANSAC_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (myRANSAC_terminate.c) */
