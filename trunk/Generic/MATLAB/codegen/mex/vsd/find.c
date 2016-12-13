/*
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "find.h"

/* Variable Definitions */
static emlrtRTEInfo ab_emlrtRTEI = { 243, 9, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

/* Function Definitions */
void eml_find(const emlrtStack *sp, const boolean_T x_data[], const int32_T
              x_size[2], int32_T i_data[], int32_T i_size[2])
{
  int32_T nx;
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  nx = x_size[1];
  idx = 0;
  i_size[0] = 1;
  i_size[1] = x_size[1];
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx)) {
    guard1 = false;
    if (x_data[ii - 1]) {
      idx++;
      i_data[idx - 1] = ii;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
    }
  }

  if (idx <= x_size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &ab_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x_size[1] == 1) {
    if (idx == 0) {
      i_size[0] = 1;
      i_size[1] = 0;
    }
  } else if (1 > idx) {
    i_size[1] = 0;
  } else {
    i_size[1] = idx;
  }
}

/* End of code generation (find.c) */
