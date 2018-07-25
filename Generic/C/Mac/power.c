/*
 * File: power.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "power.h"

/* Function Definitions */

/*
 * Arguments    : const double a[8000]
 *                double y[8000]
 * Return Type  : void
 */
void power(const double a[8000], double y[8000])
{
  int k;
  for (k = 0; k < 8000; k++) {
    y[k] = a[k] * a[k];
  }
}

/*
 * File trailer for power.c
 *
 * [EOF]
 */
