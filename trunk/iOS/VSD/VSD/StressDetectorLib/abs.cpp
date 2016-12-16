//
// File: abs.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "abs.h"
#include "vsd_rtwutil.h"
#include "vsd_emxutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable Definitions
static rtBoundsCheckInfo oe_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  68,                                  // lineNo
  35,                                  // colNo
  "",                                  // aName
  "applyScalarFunction",               // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo pe_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  68,                                  // lineNo
  17,                                  // colNo
  "",                                  // aName
  "applyScalarFunction",               // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m",// pName 
  0                                    // checkKind
};

// Function Declarations
static double rt_hypotd_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_hypotd_snf(double u0, double u1)
{
  double y;
  double a;
  double b;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = b * std::sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * std::sqrt(b * b + 1.0);
  } else if (rtIsNaN(b)) {
    y = b;
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

//
// Arguments    : const emxArray_creal_T *x
//                emxArray_real_T *y
// Return Type  : void
//
void b_abs(const emxArray_creal_T *x, emxArray_real_T *y)
{
  int i23;
  int n;
  int k;
  i23 = y->size[0] * y->size[1];
  y->size[0] = 8192;
  y->size[1] = (short)x->size[1];
  emxEnsureCapacity((emxArray__common *)y, i23, (int)sizeof(double));
  n = x->size[1] << 13;
  for (k = 1; k <= n; k++) {
    i23 = x->size[1] << 13;
    if (!((k >= 1) && (k <= i23))) {
      rtDynamicBoundsError(k, 1, i23, &oe_emlrtBCI);
    }

    i23 = y->size[1] << 13;
    if (!((k >= 1) && (k <= i23))) {
      rtDynamicBoundsError(k, 1, i23, &pe_emlrtBCI);
    }

    y->data[k - 1] = rt_hypotd_snf(x->data[k - 1].re, x->data[k - 1].im);
  }
}

//
// File trailer for abs.cpp
//
// [EOF]
//
