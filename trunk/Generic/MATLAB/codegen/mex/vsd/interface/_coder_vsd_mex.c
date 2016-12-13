/*
 * _coder_vsd_mex.c
 *
 * Code generation for function '_coder_vsd_mex'
 *
 */

/* Include files */
#include "vsd.h"
#include "_coder_vsd_mex.h"
#include "vsd_terminate.h"
#include "_coder_vsd_api.h"
#include "vsd_initialize.h"
#include "vsd_data.h"

/* Variable Definitions */
static vsdStackData *vsdStackDataGlobal = NULL;

/* Function Declarations */
static void vsd_mexFunction(vsdStackData *SD, int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
static void vsd_mexFunction(vsdStackData *SD, int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[1])
{
  int32_T n;
  const mxArray *inputs[1];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4, 3,
                        "vsd");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 3,
                        "vsd");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  vsd_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  vsd_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  vsdStackDataGlobal = (vsdStackData *)mxCalloc(1, 1U * sizeof(vsdStackData));
  mexAtExit(vsd_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  vsd_initialize();

  /* Dispatch the entry-point. */
  vsd_mexFunction(vsdStackDataGlobal, nlhs, plhs, nrhs, prhs);
  mxFree(vsdStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_vsd_mex.c) */
