/*
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "power.h"

/* Function Definitions */
void power(const real_T a[8000], real_T y[8000])
{
  int32_T k;
  for (k = 0; k < 8000; k++) {
    y[k] = a[k] * a[k];
  }
}

/* End of code generation (power.c) */
