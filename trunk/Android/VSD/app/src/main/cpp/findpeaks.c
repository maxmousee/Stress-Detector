/*
 * File: findpeaks.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 16-Dec-2016 08:11:00
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "findpeaks.h"
#include "vsd_rtwutil.h"
#include "diff.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Variable Definitions */
static rtBoundsCheckInfo h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  253,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "find",                              /* fName */
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/elmat/find.m",/* pName */
  0                                    /* checkKind */
};

static rtRunTimeErrorInfo emlrtRTEI = { 243,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static rtEqualityCheckInfo b_emlrtECI = { 2,/* nDims */
  6,                                   /* lineNo */
  13,                                  /* colNo */
  "findpeaks",                         /* fName */
  "/Users/maxmousee/repo/Stress-Detector/trunk/Generic/MATLAB/findpeaks.m"/* pName */
};

static rtBoundsCheckInfo i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  235,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "find",                              /* fName */
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/elmat/find.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  237,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "find",                              /* fName */
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/elmat/find.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  1,                                   /* colNo */
  "n",                                 /* aName */
  "findpeaks",                         /* fName */
  "/Users/maxmousee/repo/Stress-Detector/trunk/Generic/MATLAB/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  7,                                   /* lineNo */
  8,                                   /* colNo */
  "n",                                 /* aName */
  "findpeaks",                         /* fName */
  "/Users/maxmousee/repo/Stress-Detector/trunk/Generic/MATLAB/findpeaks.m",/* pName */
  0                                    /* checkKind */
};

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
  boolean_T bv0[7999];
  int i5;
  static double dv3[7998];
  boolean_T b_x[7998];
  int idx;
  int ii_data[7998];
  int ii_size[2];
  int ii;
  static const short iv1[2] = { 1, 7998 };

  boolean_T exitg2;
  boolean_T guard2 = false;
  int i6;
  int n[2];
  int b_n[2];
  int x_size_idx_1;
  boolean_T x_data[7998];
  boolean_T exitg1;
  boolean_T guard1 = false;
  int u_data[7998];
  short b_n_data[7998];
  diff(x, dv2);
  for (i5 = 0; i5 < 7999; i5++) {
    bv0[i5] = (dv2[i5] > 0.0);
  }

  b_diff(bv0, dv3);
  for (i5 = 0; i5 < 7998; i5++) {
    b_x[i5] = (dv3[i5] < 0.0);
  }

  idx = 0;
  for (i5 = 0; i5 < 2; i5++) {
    ii_size[i5] = iv1[i5];
  }

  ii = 1;
  exitg2 = false;
  while ((!exitg2) && (ii < 7999)) {
    guard2 = false;
    if (b_x[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= 7998) {
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
    i5 = 0;
    ii_size[1] = 0;
  } else {
    i5 = idx;
    ii_size[1] = idx;
  }

  n_size[0] = 1;
  n_size[1] = i5;
  ii = ii_size[0] * i5;
  for (i6 = 0; i6 < ii; i6++) {
    n_data[i6] = ii_data[i6];
  }

  for (i6 = 0; i6 < 2; i6++) {
    n[i6] = n_size[i6];
    b_n[i6] = n_size[i6];
  }

  if ((n[0] != b_n[0]) || (n[1] != b_n[1])) {
    rtSizeEqNDCheck(&n[0], &b_n[0], &b_emlrtECI);
  }

  x_size_idx_1 = ii_size[1];
  ii = ii_size[1];
  for (i6 = 0; i6 < ii; i6++) {
    x_data[i6] = (x[(int)n_data[i6]] > x[(int)n_data[i6] - 1]);
  }

  idx = 0;
  ii_size[1] = i5;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= i5)) {
    if (!((ii >= 1) && (ii <= x_size_idx_1))) {
      rtDynamicBoundsError(ii, 1, x_size_idx_1, &i_emlrtBCI);
    }

    guard1 = false;
    if (x_data[ii - 1]) {
      idx++;
      if (!((idx >= 1) && (idx <= i5))) {
        rtDynamicBoundsError(idx, 1, i5, &j_emlrtBCI);
      }

      ii_data[idx - 1] = ii;
      if (idx >= i5) {
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

  if (!(idx <= i5)) {
    b_rtErrorWithMessageID(&emlrtRTEI);
  }

  if (i5 == 1) {
    if (idx == 0) {
      ii_size[1] = 0;
    }
  } else {
    if (1 > idx) {
      idx = 0;
    } else {
      if (!(1 <= x_size_idx_1)) {
        rtDynamicBoundsError(1, 1, x_size_idx_1, &h_emlrtBCI);
      }

      if (!(idx <= x_size_idx_1)) {
        rtDynamicBoundsError(idx, 1, x_size_idx_1, &h_emlrtBCI);
      }
    }

    ii_size[1] = idx;
  }

  ii = ii_size[1];
  for (i6 = 0; i6 < ii; i6++) {
    u_data[i6] = ii_data[i6];
  }

  ii = ii_size[1];
  for (i6 = 0; i6 < ii; i6++) {
    if (!((u_data[i6] >= 1) && (u_data[i6] <= i5))) {
      rtDynamicBoundsError(u_data[i6], 1, i5, &k_emlrtBCI);
    }

    ii_data[i6] = u_data[i6];
  }

  ii = ii_size[1];
  for (i6 = 0; i6 < ii; i6++) {
    idx = u_data[i6];
    if (!((idx >= 1) && (idx <= i5))) {
      rtDynamicBoundsError(idx, 1, i5, &l_emlrtBCI);
    }
  }

  ii = ii_size[1];
  for (i5 = 0; i5 < ii; i5++) {
    b_n_data[i5] = (short)((int)n_data[u_data[i5] - 1] + 1);
  }

  ii = ii_size[1];
  for (i5 = 0; i5 < ii; i5++) {
    n_data[ii_data[i5] - 1] = b_n_data[i5];
  }
}

/*
 * File trailer for findpeaks.c
 *
 * [EOF]
 */
