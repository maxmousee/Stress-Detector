/*
 * File: bsearch.c
 *
 * MATLAB Coder version            : 2.7
 * C/C++ source code generated on  : 26-May-2015 20:44:52
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "processAudio.h"
#include "bsearch.h"

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                double xi
 * Return Type  : int
 */
int b_bsearch(const double x_data[], const int x_size[2], double xi)
{
  int n;
  int low_ip1;
  int high_i;
  int mid_i;
  n = 1;
  low_ip1 = 2;
  high_i = x_size[1];
  while (high_i > low_ip1) {
    mid_i = (n >> 1) + 1;
    if ((n & 1) == 1) {
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

/*
 * File trailer for bsearch.c
 *
 * [EOF]
 */
