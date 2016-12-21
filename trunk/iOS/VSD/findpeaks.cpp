/*
 * File: findpeaks.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 16-Dec-2016 20:24:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "findpeaks.h"
#include "diff.h"

/* Function Definitions */

/*
 * Find peaks.
 *  n = findpeaks(x)
 * Arguments    : const double x[8192]
 *                double n_data[]
 *                int n_size[2]
 * Return Type  : void
 */
void findpeaks(const double x[8192], double n_data[], int n_size[2])
{
  static double dv2[8191];
  boolean_T bv0[8191];
  int i3;
  static double dv3[8190];
  boolean_T b_x[8190];
  int idx;
  int ii_data[8190];
  int ii_size[2];
  int ii;
  static const short iv0[2] = { 1, 8190 };

  boolean_T exitg2;
  boolean_T guard2 = false;
  int i4;
  boolean_T x_data[8190];
  boolean_T exitg1;
  boolean_T guard1 = false;
  short b_n_data[8190];
  int u_data[8190];
  diff(x, dv2);
  for (i3 = 0; i3 < 8191; i3++) {
    bv0[i3] = (dv2[i3] > 0.0);
  }

  b_diff(bv0, dv3);
  for (i3 = 0; i3 < 8190; i3++) {
    b_x[i3] = (dv3[i3] < 0.0);
  }

  idx = 0;
  for (i3 = 0; i3 < 2; i3++) {
    ii_size[i3] = iv0[i3];
  }

  ii = 1;
  exitg2 = false;
  while ((!exitg2) && (ii < 8191)) {
    guard2 = false;
    if (b_x[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= 8190) {
        exitg2 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      ii++;
    }
  }

  if (1 > idx) {
    i3 = 0;
  } else {
    i3 = idx;
  }

  n_size[0] = 1;
  n_size[1] = i3;
  ii = ii_size[0] * i3;
  for (i4 = 0; i4 < ii; i4++) {
    n_data[i4] = ii_data[i4];
  }

  if (1 > idx) {
    ii = 0;
  } else {
    ii = idx;
  }

  for (i4 = 0; i4 < ii; i4++) {
    x_data[i4] = (x[(int)n_data[i4]] > x[(int)n_data[i4] - 1]);
  }

  idx = 0;
  ii_size[1] = i3;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= i3)) {
    guard1 = false;
    if (x_data[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= i3) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
    }
  }

  if (i3 == 1) {
    if (idx == 0) {
      ii_size[1] = 0;
    }
  } else if (1 > idx) {
    ii_size[1] = 0;
  } else {
    ii_size[1] = idx;
  }

  ii = ii_size[1];
  for (i3 = 0; i3 < ii; i3++) {
    u_data[i3] = ii_data[i3];
  }

  ii = ii_size[1];
  for (i3 = 0; i3 < ii; i3++) {
    b_n_data[i3] = (short)((int)n_data[u_data[i3] - 1] + 1);
  }

  ii = ii_size[1];
  for (i3 = 0; i3 < ii; i3++) {
    n_data[u_data[i3] - 1] = b_n_data[i3];
  }
}

/*
 * File trailer for findpeaks.c
 *
 * [EOF]
 */
