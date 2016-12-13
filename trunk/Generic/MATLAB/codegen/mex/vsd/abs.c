/*
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "abs.h"
#include "vsd_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo y_emlrtRTEI = { 16, 5, "abs",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m" };

/* Function Definitions */
void b_abs(const emlrtStack *sp, const emxArray_creal_T *x, emxArray_real_T *y)
{
  int16_T iv4[2];
  int32_T n;
  int32_T k;
  for (n = 0; n < 2; n++) {
    iv4[n] = (int16_T)x->size[n];
  }

  n = y->size[0] * y->size[1];
  y->size[0] = iv4[0];
  y->size[1] = iv4[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                    &y_emlrtRTEI);
  n = x->size[0] * x->size[1];
  for (k = 0; k + 1 <= n; k++) {
    y->data[k] = muDoubleScalarHypot(x->data[k].re, x->data[k].im);
  }
}

/* End of code generation (abs.c) */
