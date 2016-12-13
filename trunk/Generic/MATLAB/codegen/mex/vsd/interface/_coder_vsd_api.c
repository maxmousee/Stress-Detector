/*
 * _coder_vsd_api.c
 *
 * Code generation for function '_coder_vsd_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "_coder_vsd_api.h"
#include "vsd_data.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[8000];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8000];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *input,
  const char_T *identifier))[8000];
static const mxArray *emlrt_marshallOut(const real_T u);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[8000]
{
  real_T (*y)[8000];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[8000]
{
  real_T (*ret)[8000];
  static const int32_T dims[1] = { 8000 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[8000])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *input,
  const char_T *identifier))[8000]
{
  real_T (*y)[8000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(input), &thisId);
  emlrtDestroyArray(&input);
  return y;
}
  static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m0);
  return y;
}

void vsd_api(vsdStackData *SD, const mxArray * const prhs[1], const mxArray
             *plhs[1])
{
  real_T (*input)[8000];
  real_T stressFreq;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  input = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "input");

  /* Invoke the target function */
  stressFreq = vsd(SD, &st, *input);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(stressFreq);
}

/* End of code generation (_coder_vsd_api.c) */
