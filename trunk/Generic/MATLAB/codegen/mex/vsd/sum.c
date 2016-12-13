/*
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "sum.h"

/* Function Definitions */
real_T b_sum(const real_T x[8000])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 7999; k++) {
    y += x[k + 1];
  }

  return y;
}

real_T sum(const boolean_T x[7999])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 7998; k++) {
    y += (real_T)x[k + 1];
  }

  return y;
}

/* End of code generation (sum.c) */
