/*
 * File: sum.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 16-Dec-2016 20:24:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "sum.h"

/* Function Definitions */

/*
 * Arguments    : const double x[8192]
 * Return Type  : double
 */
double b_sum(const double x[8192])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 8191; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * Arguments    : const boolean_T x[8191]
 * Return Type  : double
 */
double sum(const boolean_T x[8191])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 8190; k++) {
    y += (double)x[k + 1];
  }

  return y;
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
