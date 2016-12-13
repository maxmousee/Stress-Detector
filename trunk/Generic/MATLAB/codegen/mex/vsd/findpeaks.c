/*
 * findpeaks.c
 *
 * Code generation for function 'findpeaks'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "findpeaks.h"
#include "find.h"
#include "diff.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 6, "findpeaks",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\findpeaks.m"
};

static emlrtRSInfo m_emlrtRSI = { 44, "find",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"
};

static emlrtECInfo b_emlrtECI = { 2, 6, 13, "findpeaks",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\findpeaks.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 7, 1, "n", "findpeaks",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\findpeaks.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 7, 8, "n", "findpeaks",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\findpeaks.m",
  0 };

/* Function Definitions */
void findpeaks(vsdStackData *SD, const emlrtStack *sp, const real_T x[8000],
               real_T n_data[], int32_T n_size[2])
{
  boolean_T bv0[7999];
  int32_T i5;
  boolean_T b_x[7998];
  int32_T idx;
  int32_T ii_data[7998];
  int32_T ii_size[2];
  int32_T ii;
  static const int16_T iv1[2] = { 1, 7998 };

  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T n[2];
  int32_T b_n[2];
  int32_T x_size[2];
  int32_T u_data[7998];
  int32_T i6;
  int16_T b_n_data[7998];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*  Find peaks. */
  /*  n = findpeaks(x) */
  diff(x, SD->u1.f1.dv1);
  for (i5 = 0; i5 < 7999; i5++) {
    bv0[i5] = (SD->u1.f1.dv1[i5] > 0.0);
  }

  b_diff(bv0, SD->u1.f1.dv2);
  for (i5 = 0; i5 < 7998; i5++) {
    b_x[i5] = (SD->u1.f1.dv2[i5] < 0.0);
  }

  idx = 0;
  for (i5 = 0; i5 < 2; i5++) {
    ii_size[i5] = iv1[i5];
  }

  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 7999)) {
    guard1 = false;
    if (b_x[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= 7998) {
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

  if (1 > idx) {
    i5 = 0;
  } else {
    i5 = idx;
  }

  if (1 > idx) {
    ii_size[1] = 0;
  } else {
    ii_size[1] = idx;
  }

  n_size[0] = 1;
  n_size[1] = i5;
  ii = ii_size[0] * i5;
  for (idx = 0; idx < ii; idx++) {
    n_data[idx] = ii_data[idx];
  }

  for (idx = 0; idx < 2; idx++) {
    n[idx] = n_size[idx];
    b_n[idx] = n_size[idx];
  }

  if ((n[0] != b_n[0]) || (n[1] != b_n[1])) {
    emlrtSizeEqCheckNDR2012b(&n[0], &b_n[0], &b_emlrtECI, sp);
  }

  st.site = &l_emlrtRSI;
  x_size[0] = 1;
  x_size[1] = ii_size[1];
  ii = ii_size[1];
  for (idx = 0; idx < ii; idx++) {
    b_x[idx] = (x[(int32_T)n_data[idx]] > x[(int32_T)n_data[idx] - 1]);
  }

  b_st.site = &m_emlrtRSI;
  eml_find(&b_st, b_x, x_size, ii_data, ii_size);
  ii = ii_size[0] * ii_size[1];
  for (idx = 0; idx < ii; idx++) {
    u_data[idx] = ii_data[idx];
  }

  ii = ii_size[1];
  for (idx = 0; idx < ii; idx++) {
    i6 = u_data[idx];
    if (!((i6 >= 1) && (i6 <= i5))) {
      emlrtDynamicBoundsCheckR2012b(i6, 1, i5, &d_emlrtBCI, sp);
    }

    ii_data[idx] = i6;
  }

  ii = ii_size[1];
  for (idx = 0; idx < ii; idx++) {
    i6 = u_data[idx];
    if (!((i6 >= 1) && (i6 <= i5))) {
      emlrtDynamicBoundsCheckR2012b(i6, 1, i5, &e_emlrtBCI, sp);
    }
  }

  ii = ii_size[1];
  for (i5 = 0; i5 < ii; i5++) {
    b_n_data[i5] = (int16_T)((int32_T)n_data[u_data[i5] - 1] + 1);
  }

  ii = ii_size[1];
  for (i5 = 0; i5 < ii; i5++) {
    n_data[ii_data[i5] - 1] = b_n_data[i5];
  }
}

/* End of code generation (findpeaks.c) */
