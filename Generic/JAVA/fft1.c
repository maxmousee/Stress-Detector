/*
 * File: fft1.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "vsd.h"
#include "fft1.h"
#include "vsd_emxutil.h"
#include "bluesteinSetup.h"

/* Function Declarations */
static void b_r2br_r2dit_trig(const creal_T x[16384], const double costab[8193],
  const double sintab[8193], creal_T y[16384]);
static void bluestein(const double x_data[], const int x_size[2], const double
                      costab[8193], const double sintab[8193], const double
                      costabinv[8193], const double sintabinv[8193], const
                      creal_T wwc[15999], creal_T y[8000]);
static void r2br_r2dit_trig(const creal_T x[15999], const double costab[8193],
  const double sintab[8193], creal_T y[16384]);
static void r2br_r2dit_trig_impl(const creal_T x[8000], const double costab[8193],
  const double sintab[8193], creal_T y[16384]);

/* Function Definitions */

/*
 * Arguments    : const creal_T x[16384]
 *                const double costab[8193]
 *                const double sintab[8193]
 *                creal_T y[16384]
 * Return Type  : void
 */
static void b_r2br_r2dit_trig(const creal_T x[16384], const double costab[8193],
  const double sintab[8193], creal_T y[16384])
{
  int ix;
  int ju;
  int iy;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int iheight;
  int istart;
  int j;
  double twid_re;
  double twid_im;
  int ihi;
  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i < 16383; i++) {
    y[iy] = x[ix];
    iy = 16384;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy] = x[ix];
  for (i = 0; i <= 16383; i += 2) {
    temp_re = y[i + 1].re;
    temp_im = y[i + 1].im;
    y[i + 1].re = y[i].re - y[i + 1].re;
    y[i + 1].im = y[i].im - y[i + 1].im;
    y[i].re += temp_re;
    y[i].im += temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 4096;
  iheight = 16381;
  while (ju > 0) {
    for (i = 0; i < iheight; i += ix) {
      temp_re = y[i + iy].re;
      temp_im = y[i + iy].im;
      y[i + iy].re = y[i].re - temp_re;
      y[i + iy].im = y[i].im - temp_im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 8192; j += ju) {
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re = twid_re * y[i + iy].re - twid_im * y[i + iy].im;
        temp_im = twid_re * y[i + iy].im + twid_im * y[i + iy].re;
        y[i + iy].re = y[i].re - temp_re;
        y[i + iy].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju >>= 1;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }

  for (iy = 0; iy < 16384; iy++) {
    y[iy].re *= 6.103515625E-5;
    y[iy].im *= 6.103515625E-5;
  }
}

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const double costab[8193]
 *                const double sintab[8193]
 *                const double costabinv[8193]
 *                const double sintabinv[8193]
 *                const creal_T wwc[15999]
 *                creal_T y[8000]
 * Return Type  : void
 */
static void bluestein(const double x_data[], const int x_size[2], const double
                      costab[8193], const double sintab[8193], const double
                      costabinv[8193], const double sintabinv[8193], const
                      creal_T wwc[15999], creal_T y[8000])
{
  int i;
  int k;
  static creal_T fv[16384];
  static creal_T dcv0[16384];
  static creal_T b_fv[16384];
  if (8000 > x_size[0]) {
    for (i = 0; i < 8000; i++) {
      y[i].re = 0.0;
      y[i].im = 0.0;
    }
  }

  i = 0;
  for (k = 7999; k - 7998 <= x_size[0]; k++) {
    y[k - 7999].re = wwc[k].re * x_data[i];
    y[k - 7999].im = wwc[k].im * -x_data[i];
    i++;
  }

  for (k = x_size[0]; k + 1 < 8001; k++) {
    y[k].re = 0.0;
    y[k].im = 0.0;
  }

  r2br_r2dit_trig_impl(y, costab, sintab, fv);
  r2br_r2dit_trig(wwc, costab, sintab, dcv0);
  for (i = 0; i < 16384; i++) {
    b_fv[i].re = fv[i].re * dcv0[i].re - fv[i].im * dcv0[i].im;
    b_fv[i].im = fv[i].re * dcv0[i].im + fv[i].im * dcv0[i].re;
  }

  b_r2br_r2dit_trig(b_fv, costabinv, sintabinv, fv);
  i = 0;
  for (k = 0; k < 8000; k++) {
    y[i].re = wwc[k + 7999].re * fv[k + 7999].re + wwc[k + 7999].im * fv[k +
      7999].im;
    y[i].im = wwc[k + 7999].re * fv[k + 7999].im - wwc[k + 7999].im * fv[k +
      7999].re;
    i++;
  }
}

/*
 * Arguments    : const creal_T x[15999]
 *                const double costab[8193]
 *                const double sintab[8193]
 *                creal_T y[16384]
 * Return Type  : void
 */
static void r2br_r2dit_trig(const creal_T x[15999], const double costab[8193],
  const double sintab[8193], creal_T y[16384])
{
  int i;
  int ix;
  int ju;
  int iy;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int iheight;
  int istart;
  int j;
  double twid_re;
  double twid_im;
  int ihi;
  for (i = 0; i < 16384; i++) {
    y[i].re = 0.0;
    y[i].im = 0.0;
  }

  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i < 15998; i++) {
    y[iy] = x[ix];
    iy = 16384;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy] = x[ix];
  for (i = 0; i <= 16383; i += 2) {
    temp_re = y[i + 1].re;
    temp_im = y[i + 1].im;
    y[i + 1].re = y[i].re - y[i + 1].re;
    y[i + 1].im = y[i].im - y[i + 1].im;
    y[i].re += temp_re;
    y[i].im += temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 4096;
  iheight = 16381;
  while (ju > 0) {
    for (i = 0; i < iheight; i += ix) {
      temp_re = y[i + iy].re;
      temp_im = y[i + iy].im;
      y[i + iy].re = y[i].re - temp_re;
      y[i + iy].im = y[i].im - temp_im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 8192; j += ju) {
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re = twid_re * y[i + iy].re - twid_im * y[i + iy].im;
        temp_im = twid_re * y[i + iy].im + twid_im * y[i + iy].re;
        y[i + iy].re = y[i].re - temp_re;
        y[i + iy].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju >>= 1;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }
}

/*
 * Arguments    : const creal_T x[8000]
 *                const double costab[8193]
 *                const double sintab[8193]
 *                creal_T y[16384]
 * Return Type  : void
 */
static void r2br_r2dit_trig_impl(const creal_T x[8000], const double costab[8193],
  const double sintab[8193], creal_T y[16384])
{
  int i;
  int ix;
  int ju;
  int iy;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int iheight;
  int istart;
  int j;
  double twid_re;
  double twid_im;
  int ihi;
  for (i = 0; i < 16384; i++) {
    y[i].re = 0.0;
    y[i].im = 0.0;
  }

  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i < 7999; i++) {
    y[iy] = x[ix];
    iy = 16384;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy] = x[ix];
  for (i = 0; i <= 16383; i += 2) {
    temp_re = y[i + 1].re;
    temp_im = y[i + 1].im;
    y[i + 1].re = y[i].re - y[i + 1].re;
    y[i + 1].im = y[i].im - y[i + 1].im;
    y[i].re += temp_re;
    y[i].im += temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 4096;
  iheight = 16381;
  while (ju > 0) {
    for (i = 0; i < iheight; i += ix) {
      temp_re = y[i + iy].re;
      temp_im = y[i + iy].im;
      y[i + iy].re = y[i].re - temp_re;
      y[i + iy].im = y[i].im - temp_im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 8192; j += ju) {
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re = twid_re * y[i + iy].re - twid_im * y[i + iy].im;
        temp_im = twid_re * y[i + iy].im + twid_im * y[i + iy].re;
        y[i + iy].re = y[i].re - temp_re;
        y[i + iy].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju >>= 1;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }
}

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const double costab[8193]
 *                const double sintab[8193]
 *                const double sintabinv[8193]
 *                emxArray_creal_T *y
 * Return Type  : void
 */
void dobluesteinfft(const double x_data[], const int x_size[2], const double
                    costab[8193], const double sintab[8193], const double
                    sintabinv[8193], emxArray_creal_T *y)
{
  static creal_T wwc[15999];
  int k;
  short sx[2];
  short sz[2];
  int loop_ub;
  static creal_T rwork[8000];
  int i7;
  bluesteinSetup(wwc);
  for (k = 0; k < 2; k++) {
    sx[k] = (short)x_size[k];
    sz[k] = (short)x_size[k];
  }

  k = y->size[0] * y->size[1];
  y->size[0] = 8000;
  y->size[1] = sz[1];
  emxEnsureCapacity_creal_T(y, k);
  if (8000 > x_size[0]) {
    k = y->size[0] * y->size[1];
    y->size[0] = 8000;
    emxEnsureCapacity_creal_T(y, k);
    loop_ub = y->size[1];
    for (k = 0; k < loop_ub; k++) {
      for (i7 = 0; i7 < 8000; i7++) {
        y->data[i7 + y->size[0] * k].re = 0.0;
        y->data[i7 + y->size[0] * k].im = 0.0;
      }
    }
  }

  k = 1;
  while (k <= sx[1]) {
    bluestein(x_data, x_size, costab, sintab, costab, sintabinv, wwc, rwork);
    for (k = 0; k < 8000; k++) {
      y->data[k] = rwork[k];
    }

    k = 2;
  }
}

/*
 * Arguments    : double costab[8193]
 *                double sintab[8193]
 *                double sintabinv[8193]
 * Return Type  : void
 */
void generate_twiddle_tables(double costab[8193], double sintab[8193], double
  sintabinv[8193])
{
  double costab1q[4097];
  int k;
  costab1q[0] = 1.0;
  for (k = 0; k < 2048; k++) {
    costab1q[k + 1] = cos(0.00038349519697141029 * ((double)k + 1.0));
  }

  for (k = 0; k < 2047; k++) {
    costab1q[k + 2049] = sin(0.00038349519697141029 * (4096.0 - ((double)k +
      2049.0)));
  }

  costab1q[4096] = 0.0;
  costab[0] = 1.0;
  sintab[0] = 0.0;
  for (k = 0; k < 4096; k++) {
    sintabinv[k + 1] = costab1q[4095 - k];
    sintabinv[k + 4097] = costab1q[k + 1];
    costab[k + 1] = costab1q[k + 1];
    sintab[k + 1] = -costab1q[4095 - k];
    costab[k + 4097] = -costab1q[4095 - k];
    sintab[k + 4097] = -costab1q[k + 1];
  }
}

/*
 * File trailer for fft1.c
 *
 * [EOF]
 */
