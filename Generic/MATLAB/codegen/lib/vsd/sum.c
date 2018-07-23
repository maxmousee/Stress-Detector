/*
 * File: sum.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "sum.h"

/* Function Definitions */

/*
 * Arguments    : const double x[8000]
 * Return Type  : double
 */
double b_sum(const double x[8000])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 7999; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * Arguments    : const boolean_T x[7999]
 * Return Type  : double
 */
double sum(const boolean_T x[7999])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 7998; k++) {
    y += (double)x[k + 1];
  }

  return y;
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
