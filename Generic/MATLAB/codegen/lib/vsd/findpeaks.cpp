//
// File: findpeaks.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 21-Dec-2016 23:54:03
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "findpeaks.h"
#include "diff.h"

// Function Definitions

//
// Find peaks.
//  n = findpeaks(x)
// Arguments    : const double x[8192]
//                double n_data[]
//                int n_size[2]
// Return Type  : void
//
void findpeaks(const double x[8192], double n_data[], int n_size[2])
{
  static double dv2[8191];
  boolean_T bv0[8191];
  int i2;
  double dv3[8190];
  boolean_T b_x[8190];
  int idx;
  int ii_data[8190];
  int ii_size[2];
  int ii;
  static const short iv0[2] = { 1, 8190 };

  boolean_T exitg2;
  boolean_T guard2 = false;
  int i3;
  boolean_T x_data[8190];
  boolean_T exitg1;
  boolean_T guard1 = false;
  short b_n_data[8190];
  int u_data[8190];
  diff(x, dv2);
  for (i2 = 0; i2 < 8191; i2++) {
    bv0[i2] = (dv2[i2] > 0.0);
  }

  b_diff(bv0, dv3);
  for (i2 = 0; i2 < 8190; i2++) {
    b_x[i2] = (dv3[i2] < 0.0);
  }

  idx = 0;
  for (i2 = 0; i2 < 2; i2++) {
    ii_size[i2] = iv0[i2];
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
    i2 = 0;
  } else {
    i2 = idx;
  }

  n_size[0] = 1;
  n_size[1] = i2;
  ii = ii_size[0] * i2;
  for (i3 = 0; i3 < ii; i3++) {
    n_data[i3] = ii_data[i3];
  }

  if (1 > idx) {
    ii = 0;
  } else {
    ii = idx;
  }

  for (i3 = 0; i3 < ii; i3++) {
    x_data[i3] = (x[(int)n_data[i3]] > x[(int)n_data[i3] - 1]);
  }

  idx = 0;
  ii_size[1] = i2;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= i2)) {
    guard1 = false;
    if (x_data[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= i2) {
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

  if (i2 == 1) {
    if (idx == 0) {
      ii_size[1] = 0;
    }
  } else if (1 > idx) {
    ii_size[1] = 0;
  } else {
    ii_size[1] = idx;
  }

  ii = ii_size[1];
  for (i2 = 0; i2 < ii; i2++) {
    u_data[i2] = ii_data[i2];
  }

  ii = ii_size[1];
  for (i2 = 0; i2 < ii; i2++) {
    b_n_data[i2] = (short)((int)n_data[u_data[i2] - 1] + 1);
  }

  ii = ii_size[1];
  for (i2 = 0; i2 < ii; i2++) {
    n_data[u_data[i2] - 1] = b_n_data[i2];
  }
}

//
// File trailer for findpeaks.cpp
//
// [EOF]
//
