/*
 * chckxy.c
 *
 * Code generation for function 'chckxy'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "chckxy.h"

/* Variable Definitions */
static emlrtRTEInfo bb_emlrtRTEI = { 36, 15, "chckxy",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m"
};

static emlrtRTEInfo cb_emlrtRTEI = { 38, 1, "chckxy",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m"
};

static emlrtRTEInfo db_emlrtRTEI = { 42, 19, "chckxy",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m"
};

/* Function Definitions */
void chckxy(const emlrtStack *sp, const real_T x_data[], const int32_T x_size[2],
            const real_T y_data[], const int32_T y_size[2])
{
  boolean_T p;
  int32_T k;
  boolean_T exitg2;
  boolean_T exitg1;
  p = true;
  k = 0;
  exitg2 = false;
  while ((!exitg2) && (k <= x_size[1] - 2)) {
    if (!(x_data[k] < x_data[k + 1])) {
      p = false;
      exitg2 = true;
    } else {
      k++;
    }
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &bb_emlrtRTEI,
      "Coder:toolbox:MustBeFiniteAndStrictlyIncreasing", 0);
  }

  p = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= y_size[1] - 1)) {
    if (muDoubleScalarIsNaN(y_data[k])) {
      p = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!p) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &cb_emlrtRTEI,
      "Coder:toolbox:UnsupportedNaN", 0);
  }

  if ((y_size[1] != x_size[1]) && (!(y_size[1] == x_size[1] + 2))) {
    emlrtErrorWithMessageIdR2012b(sp, &db_emlrtRTEI,
      "MATLAB:chckxy:NumSitesMismatchValues", 4, 12, x_size[1], 12, y_size[1]);
  }
}

/* End of code generation (chckxy.c) */
