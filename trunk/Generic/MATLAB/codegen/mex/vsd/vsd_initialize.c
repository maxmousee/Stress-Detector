/*
 * vsd_initialize.c
 *
 * Code generation for function 'vsd_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "vsd_initialize.h"
#include "_coder_vsd_mex.h"
#include "vsd_data.h"

/* Function Definitions */
void vsd_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (vsd_initialize.c) */
