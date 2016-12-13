/*
 * fft.c
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "fft.h"
#include "vsd_emxutil.h"
#include "bluestein_setup.h"

/* Variable Definitions */
static emlrtRSInfo t_emlrtRSI = { 14, "fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m"
};

static emlrtRSInfo u_emlrtRSI = { 73, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 67, 9, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 1, 14, "fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 135, 13, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 128, 13, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 115, 40, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 435, 13, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 417, 14, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo m_emlrtRTEI = { 440, 13, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 293, 9, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo o_emlrtRTEI = { 261, 14, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo p_emlrtRTEI = { 169, 13, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo q_emlrtRTEI = { 156, 14, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo r_emlrtRTEI = { 160, 1, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo s_emlrtRTEI = { 172, 13, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo u_emlrtRTEI = { 205, 9, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo v_emlrtRTEI = { 184, 14, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo w_emlrtRTEI = { 231, 5, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo x_emlrtRTEI = { 296, 9, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo eb_emlrtRTEI = { 18, 19, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

static emlrtRTEInfo fb_emlrtRTEI = { 109, 5, "eml_fft",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fft.m"
};

/* Function Declarations */
static void b_r2br_r2dit_trig(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T n1_unsigned, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, emxArray_creal_T *y);
static void b_r2br_r2dit_trig_impl(const emlrtStack *sp, const emxArray_creal_T *
  x, int32_T unsigned_nRows, const emxArray_real_T *costab, const
  emxArray_real_T *sintab, emxArray_creal_T *y);
static void bluestein(const emlrtStack *sp, const real_T x_data[], const int32_T
                      x_size[2], int32_T xoffInit, int32_T nfft, int32_T nRows,
                      const emxArray_real_T *costab, const emxArray_real_T
                      *sintab, const emxArray_real_T *costabinv, const
                      emxArray_real_T *sintabinv, const emxArray_creal_T *wwc,
                      emxArray_creal_T *y);
static void c_r2br_r2dit_trig(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T n1_unsigned, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, emxArray_creal_T *y);
static void dobluesteinfft(const emlrtStack *sp, const real_T x_data[], const
  int32_T x_size[2], int32_T N2, int32_T n1, const emxArray_real_T *costab,
  const emxArray_real_T *sintab, const emxArray_real_T *sintabinv,
  emxArray_creal_T *y);
static void generate_twiddle_tables(const emlrtStack *sp, int32_T nRows,
  boolean_T useRadix2, emxArray_real_T *costab, emxArray_real_T *sintab,
  emxArray_real_T *sintabinv);
static void get_algo_sizes(const emlrtStack *sp, int32_T n1, boolean_T useRadix2,
  int32_T *N2blue, int32_T *nRows);
static void r2br_r2dit_trig(const emlrtStack *sp, const real_T x_data[], const
  int32_T x_size[2], int32_T n1_unsigned, const emxArray_real_T *costab, const
  emxArray_real_T *sintab, emxArray_creal_T *y);
static void r2br_r2dit_trig_impl(const emlrtStack *sp, const real_T x_data[],
  const int32_T x_size[2], int32_T xoffInit, int32_T unsigned_nRows, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T *y);

/* Function Definitions */
static void b_r2br_r2dit_trig(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T n1_unsigned, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, emxArray_creal_T *y)
{
  int32_T SZ1;
  int32_T istart;
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T ix;
  int32_T ju;
  int32_T i;
  boolean_T tst;
  real_T temp_re;
  real_T temp_im;
  int32_T j;
  real_T twid_re;
  real_T twid_im;
  int32_T ihi;
  SZ1 = x->size[0];
  istart = muIntScalarMin_sint32(SZ1, n1_unsigned);
  nRowsD2 = n1_unsigned / 2;
  nRowsD4 = nRowsD2 / 2;
  SZ1 = y->size[0];
  y->size[0] = n1_unsigned;
  emxEnsureCapacity(sp, (emxArray__common *)y, SZ1, (int32_T)sizeof(creal_T),
                    &x_emlrtRTEI);
  if (n1_unsigned > x->size[0]) {
    ix = y->size[0];
    SZ1 = y->size[0];
    y->size[0] = ix;
    emxEnsureCapacity(sp, (emxArray__common *)y, SZ1, (int32_T)sizeof(creal_T),
                      &l_emlrtRTEI);
    for (SZ1 = 0; SZ1 < ix; SZ1++) {
      y->data[SZ1].re = 0.0;
      y->data[SZ1].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  SZ1 = 0;
  for (i = 1; i < istart; i++) {
    y->data[SZ1] = x->data[ix];
    SZ1 = n1_unsigned;
    tst = true;
    while (tst) {
      SZ1 >>= 1;
      ju ^= SZ1;
      tst = ((ju & SZ1) == 0);
    }

    SZ1 = ju;
    ix++;
  }

  y->data[SZ1] = x->data[ix];
  if (n1_unsigned > 1) {
    for (i = 0; i <= n1_unsigned - 2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  SZ1 = 2;
  ix = 4;
  ju = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ju; i += ix) {
      temp_re = y->data[i + SZ1].re;
      temp_im = y->data[i + SZ1].im;
      y->data[i + SZ1].re = y->data[i].re - temp_re;
      y->data[i + SZ1].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    istart = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = istart;
      ihi = istart + ju;
      while (i < ihi) {
        temp_re = twid_re * y->data[i + SZ1].re - twid_im * y->data[i + SZ1].im;
        temp_im = twid_re * y->data[i + SZ1].im + twid_im * y->data[i + SZ1].re;
        y->data[i + SZ1].re = y->data[i].re - temp_re;
        y->data[i + SZ1].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    nRowsD4 /= 2;
    SZ1 = ix;
    ix <<= 1;
    ju -= SZ1;
  }
}

static void b_r2br_r2dit_trig_impl(const emlrtStack *sp, const emxArray_creal_T *
  x, int32_T unsigned_nRows, const emxArray_real_T *costab, const
  emxArray_real_T *sintab, emxArray_creal_T *y)
{
  int32_T SZ1;
  int32_T istart;
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T ix;
  int32_T ju;
  int32_T i;
  boolean_T tst;
  real_T temp_re;
  real_T temp_im;
  int32_T j;
  real_T twid_re;
  real_T twid_im;
  int32_T ihi;
  SZ1 = x->size[0];
  istart = muIntScalarMin_sint32(SZ1, unsigned_nRows);
  nRowsD2 = unsigned_nRows / 2;
  nRowsD4 = nRowsD2 / 2;
  SZ1 = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity(sp, (emxArray__common *)y, SZ1, (int32_T)sizeof(creal_T),
                    &n_emlrtRTEI);
  SZ1 = x->size[0];
  if (unsigned_nRows > SZ1) {
    ix = y->size[0];
    SZ1 = y->size[0];
    y->size[0] = ix;
    emxEnsureCapacity(sp, (emxArray__common *)y, SZ1, (int32_T)sizeof(creal_T),
                      &o_emlrtRTEI);
    for (SZ1 = 0; SZ1 < ix; SZ1++) {
      y->data[SZ1].re = 0.0;
      y->data[SZ1].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  SZ1 = 0;
  for (i = 1; i < istart; i++) {
    y->data[SZ1] = x->data[ix];
    SZ1 = unsigned_nRows;
    tst = true;
    while (tst) {
      SZ1 >>= 1;
      ju ^= SZ1;
      tst = ((ju & SZ1) == 0);
    }

    SZ1 = ju;
    ix++;
  }

  y->data[SZ1] = x->data[ix];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= unsigned_nRows - 2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  SZ1 = 2;
  ix = 4;
  ju = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ju; i += ix) {
      temp_re = y->data[i + SZ1].re;
      temp_im = y->data[i + SZ1].im;
      y->data[i + SZ1].re = y->data[i].re - temp_re;
      y->data[i + SZ1].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    istart = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = istart;
      ihi = istart + ju;
      while (i < ihi) {
        temp_re = twid_re * y->data[i + SZ1].re - twid_im * y->data[i + SZ1].im;
        temp_im = twid_re * y->data[i + SZ1].im + twid_im * y->data[i + SZ1].re;
        y->data[i + SZ1].re = y->data[i].re - temp_re;
        y->data[i + SZ1].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    nRowsD4 /= 2;
    SZ1 = ix;
    ix <<= 1;
    ju -= SZ1;
  }
}

static void bluestein(const emlrtStack *sp, const real_T x_data[], const int32_T
                      x_size[2], int32_T xoffInit, int32_T nfft, int32_T nRows,
                      const emxArray_real_T *costab, const emxArray_real_T
                      *sintab, const emxArray_real_T *costabinv, const
                      emxArray_real_T *sintabinv, const emxArray_creal_T *wwc,
                      emxArray_creal_T *y)
{
  int32_T minNrowsNx;
  int32_T k;
  int32_T xidx;
  real_T wwc_re;
  real_T wwc_im;
  emxArray_creal_T *fv;
  emxArray_creal_T *r0;
  emxArray_creal_T *b_fv;
  real_T fv_re;
  real_T fv_im;
  real_T b_wwc_re;
  real_T b_fv_im;
  real_T b_wwc_im;
  real_T b_fv_re;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  minNrowsNx = muIntScalarMin_sint32(nRows, x_size[0]);
  k = y->size[0];
  y->size[0] = nRows;
  emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(creal_T),
                    &u_emlrtRTEI);
  if (nRows > x_size[0]) {
    xidx = y->size[0];
    k = y->size[0];
    y->size[0] = xidx;
    emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(creal_T),
                      &v_emlrtRTEI);
    for (k = 0; k < xidx; k++) {
      y->data[k].re = 0.0;
      y->data[k].im = 0.0;
    }
  }

  xidx = xoffInit;
  k = 1;
  while (k <= minNrowsNx) {
    wwc_re = wwc->data[nRows - 1].re;
    wwc_im = wwc->data[nRows - 1].im;
    y->data[0].re = wwc_re * x_data[xidx];
    y->data[0].im = wwc_im * -x_data[xidx];
    xidx++;
    k = 2;
  }

  while (minNrowsNx + 1 <= nRows) {
    y->data[minNrowsNx].re = 0.0;
    y->data[minNrowsNx].im = 0.0;
    minNrowsNx++;
  }

  emxInit_creal_T1(sp, &fv, 1, &w_emlrtRTEI, true);
  emxInit_creal_T1(sp, &r0, 1, &v_emlrtRTEI, true);
  emxInit_creal_T1(sp, &b_fv, 1, &v_emlrtRTEI, true);
  b_r2br_r2dit_trig_impl(sp, y, nfft, costab, sintab, fv);
  b_r2br_r2dit_trig(sp, wwc, nfft, costab, sintab, r0);
  k = b_fv->size[0];
  b_fv->size[0] = fv->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_fv, k, (int32_T)sizeof(creal_T),
                    &v_emlrtRTEI);
  xidx = fv->size[0];
  for (k = 0; k < xidx; k++) {
    fv_re = fv->data[k].re;
    fv_im = fv->data[k].im;
    wwc_re = r0->data[k].re;
    wwc_im = r0->data[k].im;
    b_fv->data[k].re = fv_re * wwc_re - fv_im * wwc_im;
    b_fv->data[k].im = fv_re * wwc_im + fv_im * wwc_re;
  }

  emxFree_creal_T(&r0);
  c_r2br_r2dit_trig(sp, b_fv, nfft, costabinv, sintabinv, fv);
  xidx = 0;
  k = nRows - 1;
  emxFree_creal_T(&b_fv);
  while (k + 1 <= wwc->size[0]) {
    wwc_re = wwc->data[k].re;
    fv_re = fv->data[k].re;
    wwc_im = wwc->data[k].im;
    fv_im = fv->data[k].im;
    b_wwc_re = wwc->data[k].re;
    b_fv_im = fv->data[k].im;
    b_wwc_im = wwc->data[k].im;
    b_fv_re = fv->data[k].re;
    y->data[xidx].re = wwc_re * fv_re + wwc_im * fv_im;
    y->data[xidx].im = b_wwc_re * b_fv_im - b_wwc_im * b_fv_re;
    xidx++;
    k++;
  }

  emxFree_creal_T(&fv);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void c_r2br_r2dit_trig(const emlrtStack *sp, const emxArray_creal_T *x,
  int32_T n1_unsigned, const emxArray_real_T *costab, const emxArray_real_T
  *sintab, emxArray_creal_T *y)
{
  int32_T SZ1;
  int32_T istart;
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T ix;
  int32_T ju;
  int32_T i;
  boolean_T tst;
  real_T temp_re;
  real_T temp_im;
  real_T r;
  int32_T j;
  real_T twid_im;
  int32_T ihi;
  SZ1 = x->size[0];
  istart = muIntScalarMin_sint32(SZ1, n1_unsigned);
  nRowsD2 = n1_unsigned / 2;
  nRowsD4 = nRowsD2 / 2;
  ix = y->size[0];
  y->size[0] = n1_unsigned;
  emxEnsureCapacity(sp, (emxArray__common *)y, ix, (int32_T)sizeof(creal_T),
                    &x_emlrtRTEI);
  if (n1_unsigned > x->size[0]) {
    SZ1 = y->size[0];
    ix = y->size[0];
    y->size[0] = SZ1;
    emxEnsureCapacity(sp, (emxArray__common *)y, ix, (int32_T)sizeof(creal_T),
                      &l_emlrtRTEI);
    for (ix = 0; ix < SZ1; ix++) {
      y->data[ix].re = 0.0;
      y->data[ix].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  SZ1 = 0;
  for (i = 1; i < istart; i++) {
    y->data[SZ1] = x->data[ix];
    SZ1 = n1_unsigned;
    tst = true;
    while (tst) {
      SZ1 >>= 1;
      ju ^= SZ1;
      tst = ((ju & SZ1) == 0);
    }

    SZ1 = ju;
    ix++;
  }

  y->data[SZ1] = x->data[ix];
  if (n1_unsigned > 1) {
    for (i = 0; i <= n1_unsigned - 2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  SZ1 = 2;
  ix = 4;
  ju = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ju; i += ix) {
      temp_re = y->data[i + SZ1].re;
      temp_im = y->data[i + SZ1].im;
      y->data[i + SZ1].re = y->data[i].re - temp_re;
      y->data[i + SZ1].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    istart = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      r = costab->data[j];
      twid_im = sintab->data[j];
      i = istart;
      ihi = istart + ju;
      while (i < ihi) {
        temp_re = r * y->data[i + SZ1].re - twid_im * y->data[i + SZ1].im;
        temp_im = r * y->data[i + SZ1].im + twid_im * y->data[i + SZ1].re;
        y->data[i + SZ1].re = y->data[i].re - temp_re;
        y->data[i + SZ1].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    nRowsD4 /= 2;
    SZ1 = ix;
    ix <<= 1;
    ju -= SZ1;
  }

  if (y->size[0] > 1) {
    r = 1.0 / (real_T)y->size[0];
    ix = y->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)y, ix, (int32_T)sizeof(creal_T),
                      &l_emlrtRTEI);
    SZ1 = y->size[0];
    for (ix = 0; ix < SZ1; ix++) {
      y->data[ix].re *= r;
      y->data[ix].im *= r;
    }
  }
}

static void dobluesteinfft(const emlrtStack *sp, const real_T x_data[], const
  int32_T x_size[2], int32_T N2, int32_T n1, const emxArray_real_T *costab,
  const emxArray_real_T *sintab, const emxArray_real_T *sintabinv,
  emxArray_creal_T *y)
{
  int16_T sx[2];
  int32_T k;
  emxArray_creal_T *wwc;
  int32_T sz[2];
  emxArray_creal_T *rwork;
  int32_T l;
  int32_T loop_ub;
  int32_T i14;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  for (k = 0; k < 2; k++) {
    sx[k] = (int16_T)x_size[k];
  }

  emxInit_creal_T1(sp, &wwc, 1, &r_emlrtRTEI, true);
  bluestein_setup(sp, n1, wwc);
  for (k = 0; k < 2; k++) {
    sz[k] = x_size[k];
  }

  k = y->size[0] * y->size[1];
  y->size[0] = n1;
  y->size[1] = sz[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(creal_T),
                    &p_emlrtRTEI);
  if (n1 > x_size[0]) {
    k = y->size[0] * y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(creal_T),
                      &q_emlrtRTEI);
    l = y->size[1];
    for (k = 0; k < l; k++) {
      loop_ub = y->size[0];
      for (i14 = 0; i14 < loop_ub; i14++) {
        y->data[i14 + y->size[0] * k].re = 0.0;
        y->data[i14 + y->size[0] * k].im = 0.0;
      }
    }
  }

  k = 0;
  emxInit_creal_T1(sp, &rwork, 1, &s_emlrtRTEI, true);
  while (k + 1 <= sx[1]) {
    bluestein(sp, x_data, x_size, k * x_size[0], N2, n1, costab, sintab, costab,
              sintabinv, wwc, rwork);
    for (l = 0; l + 1 <= n1; l++) {
      y->data[l + y->size[0] * k] = rwork->data[l];
    }

    k++;
  }

  emxFree_creal_T(&rwork);
  emxFree_creal_T(&wwc);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void generate_twiddle_tables(const emlrtStack *sp, int32_T nRows,
  boolean_T useRadix2, emxArray_real_T *costab, emxArray_real_T *sintab,
  emxArray_real_T *sintabinv)
{
  real_T e;
  int32_T nRowsD4;
  real_T costab1q_data[8001];
  int32_T nd2;
  int32_T k;
  int32_T n2;
  e = 6.2831853071795862 / (real_T)nRows;
  nRowsD4 = nRows / 2 / 2;
  costab1q_data[0] = 1.0;
  nd2 = nRowsD4 / 2;
  for (k = 1; k <= nd2; k++) {
    costab1q_data[k] = muDoubleScalarCos(e * (real_T)k);
  }

  for (k = nd2 + 1; k < nRowsD4; k++) {
    costab1q_data[k] = muDoubleScalarSin(e * (real_T)(nRowsD4 - k));
  }

  costab1q_data[nRowsD4] = 0.0;
  if (!useRadix2) {
    n2 = nRowsD4 << 1;
    nd2 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = n2 + 1;
    emxEnsureCapacity(sp, (emxArray__common *)costab, nd2, (int32_T)sizeof
                      (real_T), &i_emlrtRTEI);
    nd2 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = n2 + 1;
    emxEnsureCapacity(sp, (emxArray__common *)sintab, nd2, (int32_T)sizeof
                      (real_T), &i_emlrtRTEI);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    nd2 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = n2 + 1;
    emxEnsureCapacity(sp, (emxArray__common *)sintabinv, nd2, (int32_T)sizeof
                      (real_T), &i_emlrtRTEI);
    for (k = 1; k <= nRowsD4; k++) {
      sintabinv->data[k] = costab1q_data[nRowsD4 - k];
    }

    for (k = nRowsD4 + 1; k <= n2; k++) {
      sintabinv->data[k] = costab1q_data[k - nRowsD4];
    }

    for (k = 1; k <= nRowsD4; k++) {
      costab->data[k] = costab1q_data[k];
      sintab->data[k] = -costab1q_data[nRowsD4 - k];
    }

    for (k = nRowsD4 + 1; k <= n2; k++) {
      costab->data[k] = -costab1q_data[n2 - k];
      sintab->data[k] = -costab1q_data[k - nRowsD4];
    }
  } else {
    n2 = nRowsD4 << 1;
    nd2 = costab->size[0] * costab->size[1];
    costab->size[0] = 1;
    costab->size[1] = n2 + 1;
    emxEnsureCapacity(sp, (emxArray__common *)costab, nd2, (int32_T)sizeof
                      (real_T), &h_emlrtRTEI);
    nd2 = sintab->size[0] * sintab->size[1];
    sintab->size[0] = 1;
    sintab->size[1] = n2 + 1;
    emxEnsureCapacity(sp, (emxArray__common *)sintab, nd2, (int32_T)sizeof
                      (real_T), &h_emlrtRTEI);
    costab->data[0] = 1.0;
    sintab->data[0] = 0.0;
    for (k = 1; k <= nRowsD4; k++) {
      costab->data[k] = costab1q_data[k];
      sintab->data[k] = -costab1q_data[nRowsD4 - k];
    }

    for (k = nRowsD4 + 1; k <= n2; k++) {
      costab->data[k] = -costab1q_data[n2 - k];
      sintab->data[k] = -costab1q_data[k - nRowsD4];
    }

    nd2 = sintabinv->size[0] * sintabinv->size[1];
    sintabinv->size[0] = 1;
    sintabinv->size[1] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)sintabinv, nd2, (int32_T)sizeof
                      (real_T), &j_emlrtRTEI);
  }
}

static void get_algo_sizes(const emlrtStack *sp, int32_T n1, boolean_T useRadix2,
  int32_T *N2blue, int32_T *nRows)
{
  int32_T nn1m1;
  int32_T pmax;
  int32_T pmin;
  boolean_T exitg1;
  int32_T p;
  int32_T pow2p;
  *N2blue = 1;
  if (useRadix2) {
    *nRows = n1;
  } else {
    nn1m1 = (n1 + n1) - 1;
    pmax = 31;
    if (nn1m1 <= 1) {
      pmax = 0;
    } else {
      pmin = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax - pmin > 1)) {
        p = (pmin + pmax) >> 1;
        pow2p = 1 << p;
        if (pow2p == nn1m1) {
          pmax = p;
          exitg1 = true;
        } else if (pow2p > nn1m1) {
          pmax = p;
        } else {
          pmin = p;
        }
      }
    }

    *N2blue = 1 << pmax;
    nn1m1 = n1 << 2;
    if (*N2blue <= muIntScalarMax_sint32(nn1m1, 1)) {
    } else {
      emlrtErrorWithMessageIdR2012b(sp, &fb_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    *nRows = *N2blue;
  }
}

static void r2br_r2dit_trig(const emlrtStack *sp, const real_T x_data[], const
  int32_T x_size[2], int32_T n1_unsigned, const emxArray_real_T *costab, const
  emxArray_real_T *sintab, emxArray_creal_T *y)
{
  int16_T sx[2];
  int32_T sz[2];
  int32_T k;
  emxArray_creal_T *rwork;
  int32_T l;
  int32_T loop_ub;
  int32_T i13;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  for (k = 0; k < 2; k++) {
    sx[k] = (int16_T)x_size[k];
    sz[k] = x_size[k];
  }

  k = y->size[0] * y->size[1];
  y->size[0] = n1_unsigned;
  y->size[1] = sz[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(creal_T),
                    &k_emlrtRTEI);
  if (n1_unsigned > x_size[0]) {
    k = y->size[0] * y->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)y, k, (int32_T)sizeof(creal_T),
                      &l_emlrtRTEI);
    l = y->size[1];
    for (k = 0; k < l; k++) {
      loop_ub = y->size[0];
      for (i13 = 0; i13 < loop_ub; i13++) {
        y->data[i13 + y->size[0] * k].re = 0.0;
        y->data[i13 + y->size[0] * k].im = 0.0;
      }
    }
  }

  k = 0;
  emxInit_creal_T1(sp, &rwork, 1, &m_emlrtRTEI, true);
  while (k + 1 <= sx[1]) {
    r2br_r2dit_trig_impl(sp, x_data, x_size, k * x_size[0], n1_unsigned, costab,
                         sintab, rwork);
    for (l = 0; l + 1 <= n1_unsigned; l++) {
      y->data[l + y->size[0] * k] = rwork->data[l];
    }

    k++;
  }

  emxFree_creal_T(&rwork);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void r2br_r2dit_trig_impl(const emlrtStack *sp, const real_T x_data[],
  const int32_T x_size[2], int32_T xoffInit, int32_T unsigned_nRows, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T *y)
{
  int32_T nRowsD2;
  int32_T nRowsD4;
  int32_T i;
  int32_T iDelta;
  int32_T iDelta2;
  int32_T iheight;
  real_T temp_re;
  real_T temp_im;
  int32_T istart;
  int32_T j;
  real_T twid_re;
  real_T twid_im;
  int32_T ihi;
  nRowsD2 = unsigned_nRows / 2;
  nRowsD4 = nRowsD2 / 2;
  i = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(creal_T),
                    &n_emlrtRTEI);
  if (unsigned_nRows > x_size[0]) {
    iDelta = y->size[0];
    i = y->size[0];
    y->size[0] = iDelta;
    emxEnsureCapacity(sp, (emxArray__common *)y, i, (int32_T)sizeof(creal_T),
                      &o_emlrtRTEI);
    for (i = 0; i < iDelta; i++) {
      y->data[i].re = 0.0;
      y->data[i].im = 0.0;
    }
  }

  y->data[0].re = x_data[xoffInit];
  y->data[0].im = 0.0;
  if (unsigned_nRows > 1) {
    for (i = 0; i <= unsigned_nRows - 2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  iDelta = 2;
  iDelta2 = 4;
  iheight = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < iheight; i += iDelta2) {
      temp_re = y->data[i + iDelta].re;
      temp_im = y->data[i + iDelta].im;
      y->data[i + iDelta].re = y->data[i].re - temp_re;
      y->data[i + iDelta].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    istart = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re = twid_re * y->data[i + iDelta].re - twid_im * y->data[i +
          iDelta].im;
        temp_im = twid_re * y->data[i + iDelta].im + twid_im * y->data[i +
          iDelta].re;
        y->data[i + iDelta].re = y->data[i].re - temp_re;
        y->data[i + iDelta].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += iDelta2;
      }

      istart++;
    }

    nRowsD4 /= 2;
    iDelta = iDelta2;
    iDelta2 <<= 1;
    iheight -= iDelta;
  }
}

void fft(const emlrtStack *sp, const real_T x_data[], const int32_T x_size[2],
         real_T varargin_1, emxArray_creal_T *y)
{
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  boolean_T useRadix2;
  int32_T sz[2];
  int32_T N2blue;
  int32_T nRows;
  int32_T loop_ub;
  int32_T i12;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &t_emlrtRSI;
  if (x_size[0] != 1) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &eb_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  emxInit_real_T(&st, &costab, 2, &g_emlrtRTEI, true);
  emxInit_real_T(&st, &sintab, 2, &g_emlrtRTEI, true);
  emxInit_real_T(&st, &sintabinv, 2, &g_emlrtRTEI, true);
  if ((x_size[0] == 0) || (x_size[1] == 0) || ((int32_T)varargin_1 == 0)) {
    for (N2blue = 0; N2blue < 2; N2blue++) {
      sz[N2blue] = x_size[N2blue];
    }

    N2blue = y->size[0] * y->size[1];
    y->size[0] = (int32_T)varargin_1;
    y->size[1] = sz[1];
    emxEnsureCapacity(&st, (emxArray__common *)y, N2blue, (int32_T)sizeof
                      (creal_T), &f_emlrtRTEI);
    if ((int32_T)varargin_1 > x_size[0]) {
      N2blue = y->size[0] * y->size[1];
      emxEnsureCapacity(&st, (emxArray__common *)y, N2blue, (int32_T)sizeof
                        (creal_T), &g_emlrtRTEI);
      nRows = y->size[1];
      for (N2blue = 0; N2blue < nRows; N2blue++) {
        loop_ub = y->size[0];
        for (i12 = 0; i12 < loop_ub; i12++) {
          y->data[i12 + y->size[0] * N2blue].re = 0.0;
          y->data[i12 + y->size[0] * N2blue].im = 0.0;
        }
      }
    }
  } else {
    useRadix2 = (((int32_T)varargin_1 & ((int32_T)varargin_1 - 1)) == 0);
    b_st.site = &u_emlrtRSI;
    get_algo_sizes(&b_st, (int32_T)varargin_1, useRadix2, &N2blue, &nRows);
    generate_twiddle_tables(&st, nRows, useRadix2, costab, sintab, sintabinv);
    if (useRadix2) {
      r2br_r2dit_trig(&st, x_data, x_size, (int32_T)varargin_1, costab, sintab,
                      y);
    } else {
      dobluesteinfft(&st, x_data, x_size, N2blue, (int32_T)varargin_1, costab,
                     sintab, sintabinv, y);
    }
  }

  emxFree_real_T(&sintabinv);
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (fft.c) */
