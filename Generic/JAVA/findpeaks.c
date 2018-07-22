/*
 * File: findpeaks.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "vsd.h"
#include "findpeaks.h"
#include "diff.h"

/* Function Definitions */

/*
 * Find peaks.
 *  n = findpeaks(x)
 * Arguments    : const double x[8000]
 *                double n_data[]
 *                int n_size[2]
 * Return Type  : void
 */
void findpeaks(const double x[8000], double n_data[], int n_size[2])
{
  static double dv2[7999];
  int i2;
  boolean_T bv0[7999];
  static double dv3[7998];
  int idx;
  boolean_T b_x[7998];
  int ii;
  boolean_T exitg1;
  int loop_ub;
  int ii_data[7998];
  boolean_T x_data[7998];
  int u_data[7998];
  short b_n_data[7998];
  diff(x, dv2);
  for (i2 = 0; i2 < 7999; i2++) {
    bv0[i2] = (dv2[i2] > 0.0);
  }

  b_diff(bv0, dv3);
  for (i2 = 0; i2 < 7998; i2++) {
    b_x[i2] = (dv3[i2] < 0.0);
  }

  idx = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 7999)) {
    if (b_x[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= 7998) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (1 > idx) {
    loop_ub = 0;
  } else {
    loop_ub = idx;
  }

  n_size[0] = 1;
  n_size[1] = loop_ub;
  for (i2 = 0; i2 < loop_ub; i2++) {
    n_data[i2] = ii_data[i2];
  }

  if (1 > idx) {
    ii = 0;
  } else {
    ii = idx;
  }

  for (i2 = 0; i2 < ii; i2++) {
    x_data[i2] = (x[(int)n_data[i2]] > x[(int)n_data[i2] - 1]);
  }

  idx = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= loop_ub)) {
    if (x_data[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= loop_ub) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (loop_ub == 1) {
    if (idx == 0) {
      loop_ub = 0;
    }
  } else if (1 > idx) {
    loop_ub = 0;
  } else {
    loop_ub = idx;
  }

  if (0 <= loop_ub - 1) {
    memcpy(&u_data[0], &ii_data[0], (unsigned int)(loop_ub * (int)sizeof(int)));
  }

  for (i2 = 0; i2 < loop_ub; i2++) {
    b_n_data[i2] = (short)((int)n_data[u_data[i2] - 1] + 1);
  }

  for (i2 = 0; i2 < loop_ub; i2++) {
    n_data[u_data[i2] - 1] = b_n_data[i2];
  }
}

/*
 * File trailer for findpeaks.c
 *
 * [EOF]
 */
