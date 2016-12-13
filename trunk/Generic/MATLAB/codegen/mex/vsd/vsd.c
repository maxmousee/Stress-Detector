/*
 * vsd.c
 *
 * Code generation for function 'vsd'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "vsd_emxutil.h"
#include "abs.h"
#include "emd.h"
#include "indexShapeCheck.h"
#include "fft.h"

/* Variable Definitions */
static emlrtRSInfo c_emlrtRSI = { 9, "vsd",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\vsd.m" };

static emlrtRSInfo d_emlrtRSI = { 7, "vsd",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\vsd.m" };

static emlrtRSInfo e_emlrtRSI = { 3, "vsd",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\vsd.m" };

static emlrtRTEInfo emlrtRTEI = { 1, 23, "vsd",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\vsd.m" };

static emlrtRTEInfo b_emlrtRTEI = { 8, 2, "vsd",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\vsd.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 9, 7, "P2", "vsd",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\vsd.m", 0 };

static emlrtDCInfo emlrtDCI = { 9, 7, "vsd",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\vsd.m", 1 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 10, 18, "P1", "vsd",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\vsd.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 10, 2, "P1", "vsd",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\vsd.m", 0 };

static emlrtECInfo emlrtECI = { -1, 10, 2, "vsd",
  "C:\\Users\\maxmo\\repo\\Stress-Detector\\trunk\\Generic\\MATLAB\\vsd.m" };

/* Function Definitions */
real_T vsd(vsdStackData *SD, const emlrtStack *sp, const real_T input[8000])
{
  real_T stressFreq;
  int32_T imf_size[2];
  int32_T ixstart;
  emxArray_creal_T *A;
  emxArray_creal_T *b_A;
  int32_T i0;
  int32_T itmp;
  real_T mtmp;
  emxArray_real_T *P2;
  real_T A_im;
  real_T d0;
  int32_T ix;
  int32_T iv0[2];
  real_T P1_data[4001];
  int32_T i1;
  int32_T i2;
  real_T y_data[4001];
  boolean_T exitg1;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &e_emlrtRSI;
  emd(SD, &st, input, SD->f7.imf_data, imf_size);
  if ((imf_size[0] == 0) || (imf_size[1] == 0)) {
    ixstart = 0;
  } else {
    ixstart = imf_size[1];
  }

  emxInit_creal_T(sp, &A, 2, &emlrtRTEI, true);
  emxInit_creal_T(sp, &b_A, 2, &emlrtRTEI, true);
  st.site = &d_emlrtRSI;
  fft(&st, SD->f7.imf_data, imf_size, ixstart, A);
  i0 = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)b_A, i0, (int32_T)sizeof(creal_T),
                    &emlrtRTEI);
  itmp = A->size[0] * A->size[1];
  for (i0 = 0; i0 < itmp; i0++) {
    mtmp = A->data[i0].re;
    A_im = A->data[i0].im;
    if (A_im == 0.0) {
      b_A->data[i0].re = mtmp / (real_T)ixstart;
      b_A->data[i0].im = 0.0;
    } else if (mtmp == 0.0) {
      b_A->data[i0].re = 0.0;
      b_A->data[i0].im = A_im / (real_T)ixstart;
    } else {
      b_A->data[i0].re = mtmp / (real_T)ixstart;
      b_A->data[i0].im = A_im / (real_T)ixstart;
    }
  }

  emxFree_creal_T(&A);
  emxInit_real_T(sp, &P2, 2, &b_emlrtRTEI, true);
  b_abs(sp, b_A, P2);
  mtmp = (real_T)ixstart / 2.0;
  d0 = (real_T)ixstart / 2.0 + 1.0;
  i0 = P2->size[0] * P2->size[1];
  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, &emlrtBCI, sp);
  }

  A_im = (real_T)ixstart / 2.0 + 1.0;
  if (A_im != muDoubleScalarFloor(A_im)) {
    emlrtIntegerCheckR2012b(A_im, &emlrtDCI, sp);
  }

  ix = (int32_T)A_im;
  if (!((ix >= 1) && (ix <= i0))) {
    emlrtDynamicBoundsCheckR2012b(ix, 1, i0, &emlrtBCI, sp);
  }

  iv0[0] = 1;
  iv0[1] = (int32_T)d0;
  st.site = &c_emlrtRSI;
  indexShapeCheck(&st, *(int32_T (*)[2])P2->size, iv0);
  itmp = (int32_T)d0;
  emxFree_creal_T(&b_A);
  for (i0 = 0; i0 < itmp; i0++) {
    P1_data[i0] = P2->data[i0];
  }

  emxFree_real_T(&P2);
  if (2 > (int32_T)d0 - 1) {
    i0 = 0;
    i1 = 0;
  } else {
    i0 = (int32_T)(mtmp + 1.0);
    if (!(2 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i0, &b_emlrtBCI, sp);
    }

    i0 = 1;
    ix = (int32_T)(mtmp + 1.0);
    i1 = (int32_T)d0 - 1;
    if (!((i1 >= 1) && (i1 <= ix))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, ix, &b_emlrtBCI, sp);
    }
  }

  if (2 > (int32_T)d0 - 1) {
    ix = 0;
    i2 = 1;
  } else {
    ix = (int32_T)(mtmp + 1.0);
    if (!(2 <= ix)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, ix, &c_emlrtBCI, sp);
    }

    ix = 1;
    i2 = (int32_T)(mtmp + 1.0);
    ixstart = (int32_T)d0 - 1;
    if (!((ixstart >= 1) && (ixstart <= i2))) {
      emlrtDynamicBoundsCheckR2012b(ixstart, 1, i2, &c_emlrtBCI, sp);
    }

    i2 = ixstart + 1;
  }

  ixstart = i1 - i0;
  itmp = i1 - i0;
  for (i1 = 0; i1 < itmp; i1++) {
    y_data[i1] = 2.0 * P1_data[i0 + i1];
  }

  i0 = (i2 - ix) - 1;
  if (i0 != ixstart) {
    emlrtSizeEqCheck1DR2012b(i0, ixstart, &emlrtECI, sp);
  }

  for (i0 = 0; i0 < ixstart; i0++) {
    P1_data[ix + i0] = y_data[i0];
  }

  ixstart = 1;
  mtmp = P1_data[0];
  itmp = 1;
  if ((int32_T)d0 > 1) {
    if (muDoubleScalarIsNaN(P1_data[0])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= (int32_T)d0)) {
        ixstart = ix;
        if (!muDoubleScalarIsNaN(P1_data[ix - 1])) {
          mtmp = P1_data[ix - 1];
          itmp = ix;
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < (int32_T)d0) {
      while (ixstart + 1 <= (int32_T)d0) {
        if (P1_data[ixstart] > mtmp) {
          mtmp = P1_data[ixstart];
          itmp = ixstart + 1;
        }

        ixstart++;
      }
    }
  }

  stressFreq = (real_T)itmp - 1.0;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return stressFreq;
}

/* End of code generation (vsd.c) */
