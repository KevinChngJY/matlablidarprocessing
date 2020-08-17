/*
 * _coder_myRANSAC_mex.c
 *
 * Code generation for function '_coder_myRANSAC_mex'
 *
 */

/* Include files */
#include "myRANSAC.h"
#include "_coder_myRANSAC_mex.h"
#include "myRANSAC_terminate.h"
#include "_coder_myRANSAC_api.h"
#include "myRANSAC_initialize.h"
#include "myRANSAC_data.h"

/* Function Declarations */
static void myRANSAC_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[5]);

/* Function Definitions */
static void myRANSAC_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[5])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4, 8,
                        "myRANSAC");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 8,
                        "myRANSAC");
  }

  /* Call the function. */
  myRANSAC_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(myRANSAC_atexit);

  /* Module initialization. */
  myRANSAC_initialize();

  /* Dispatch the entry-point. */
  myRANSAC_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  myRANSAC_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_myRANSAC_mex.c) */
