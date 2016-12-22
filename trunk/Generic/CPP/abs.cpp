//
// File: abs.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 21-Dec-2016 23:54:03
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "abs.h"
#include "vsd_emxutil.h"

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
  int n;
  int k;
  n = y->size[0] * y->size[1];
  y->size[0] = 8192;
  y->size[1] = (short)x->size[1];
  emxEnsureCapacity((emxArray__common *)y, n, (int)sizeof(double));
  n = x->size[1] << 13;
  for (k = 0; k + 1 <= n; k++) {
    y->data[k] = rt_hypotd_snf(x->data[k].re, x->data[k].im);
  }
}

//
// File trailer for abs.cpp
//
// [EOF]
//
