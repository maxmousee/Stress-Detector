/*
 * File: abs.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "vsd.h"
#include "abs.h"

/* Function Declarations */
static double rt_hypotd_snf(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd_snf(double u0, double u1)
{
  double y;
  double a;
  double b;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = b * sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * sqrt(b * b + 1.0);
  } else if (rtIsNaN(b)) {
    y = b;
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/*
 * Arguments    : const emxArray_creal_T *x
 *                double y_data[]
 *                int y_size[2]
 * Return Type  : void
 */
void b_abs(const emxArray_creal_T *x, double y_data[], int y_size[2])
{
  int nx;
  int k;
  nx = x->size[0] * 8000;
  y_size[0] = (short)x->size[0];
  y_size[1] = 8000;
  for (k = 0; k < nx; k++) {
    y_data[k] = rt_hypotd_snf(x->data[k].re, x->data[k].im);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
