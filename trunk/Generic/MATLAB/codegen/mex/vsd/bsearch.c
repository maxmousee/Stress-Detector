/*
 * bsearch.c
 *
 * Code generation for function 'bsearch'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "bsearch.h"

/* Function Definitions */
int32_T b_bsearch(const real_T x_data[], const int32_T x_size[2], real_T xi)
{
  int32_T n;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  n = 1;
  low_ip1 = 2;
  high_i = x_size[1];
  while (high_i > low_ip1) {
    mid_i = (n >> 1) + (high_i >> 1);
    if (((n & 1) == 1) && ((high_i & 1) == 1)) {
      mid_i++;
    }

    if (xi >= x_data[mid_i - 1]) {
      n = mid_i;
      low_ip1 = mid_i + 1;
    } else {
      high_i = mid_i;
    }
  }

  return n;
}

/* End of code generation (bsearch.c) */
