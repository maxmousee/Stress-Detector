/*
 * vsd_terminate.c
 *
 * Code generation for function 'vsd_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "vsd_terminate.h"
#include "_coder_vsd_mex.h"
#include "vsd_data.h"

/* Function Definitions */
void vsd_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void vsd_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (vsd_terminate.c) */
