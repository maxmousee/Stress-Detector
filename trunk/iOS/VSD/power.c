/*
 * File: power.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 16-Dec-2016 20:24:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "power.h"

/* Function Definitions */

/*
 * Arguments    : const double a[8192]
 *                double y[8192]
 * Return Type  : void
 */
void power(const double a[8192], double y[8192])
{
  int k;
  for (k = 0; k < 8192; k++) {
    y[k] = a[k] * a[k];
  }
}

/*
 * File trailer for power.c
 *
 * [EOF]
 */
