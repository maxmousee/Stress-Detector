/*
 * bluestein_setup.c
 *
 * Code generation for function 'bluestein_setup'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "bluestein_setup.h"
#include "vsd_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo t_emlrtRTEI = { 9, 7, "bluestein_setup",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\bluestein_setup.m"
};

/* Function Definitions */
void bluestein_setup(const emlrtStack *sp, int32_T nRows, emxArray_creal_T *wwc)
{
  int32_T nInt2m1;
  int32_T idx;
  int32_T rt;
  int32_T nInt2;
  int32_T k;
  int32_T y;
  real_T x_im;
  nInt2m1 = (nRows + nRows) - 1;
  idx = wwc->size[0];
  wwc->size[0] = nInt2m1;
  emxEnsureCapacity(sp, (emxArray__common *)wwc, idx, (int32_T)sizeof(creal_T),
                    &t_emlrtRTEI);
  idx = nRows;
  rt = 0;
  wwc->data[nRows - 1].re = 1.0;
  wwc->data[nRows - 1].im = 0.0;
  nInt2 = nRows << 1;
  for (k = 1; k < nRows; k++) {
    y = (k << 1) - 1;
    if (nInt2 - rt <= y) {
      rt += y - nInt2;
    } else {
      rt += y;
    }

    x_im = -3.1415926535897931 * (real_T)rt / (real_T)nRows;
    wwc->data[idx - 2].re = muDoubleScalarCos(x_im);
    wwc->data[idx - 2].im = -muDoubleScalarSin(x_im);
    idx--;
  }

  idx = 0;
  for (k = nInt2m1 - 1; k >= nRows; k--) {
    wwc->data[k] = wwc->data[idx];
    idx++;
  }
}

/* End of code generation (bluestein_setup.c) */
