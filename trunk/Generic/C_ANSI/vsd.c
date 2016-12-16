/*
 * File: vsd.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 16-Dec-2016 20:24:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "vsd_emxutil.h"
#include "abs.h"
#include "fft.h"
#include "emd.h"

/* Function Definitions */

/*
 * Fs = length(input);
 * The code has fixed length anyway, so it wont work with different
 * sample rate anyway
 * Arguments    : const double input[8192]
 * Return Type  : double
 */
double vsd(const double input[8192])
{
  emxArray_real_T *imf;
  int ixstart;
  emxArray_creal_T *Y;
  emxArray_creal_T *r0;
  int i0;
  int loop_ub;
  emxArray_creal_T *b_Y;
  double Y_re;
  emxArray_real_T *P2;
  double mtmp;
  double P1_data[4097];
  int itmp;
  double tmp_data[4096];
  int ix;
  boolean_T exitg1;
  emxInit_real_T(&imf, 2);
  emd(input, imf);
  if ((imf->size[0] == 0) || (imf->size[1] == 0)) {
    ixstart = 0;
  } else {
    ixstart = imf->size[1];
  }

  emxInit_creal_T(&Y, 2);
  emxInit_creal_T(&r0, 2);

  /* fft starts here */
  /* dirty hack because matlab only generates fft code for power of 2 */
  /* nPointDFT=nextpow2(L); */
  /* remember that nPointDFT should be a power of 2 or matlab coder wont */
  /* generate anything */
  fft(imf, r0);
  i0 = Y->size[0] * Y->size[1];
  Y->size[0] = 8192;
  Y->size[1] = r0->size[1];
  emxEnsureCapacity((emxArray__common *)Y, i0, (int)sizeof(creal_T));
  loop_ub = r0->size[0] * r0->size[1];
  emxFree_real_T(&imf);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Y->data[i0] = r0->data[i0];
  }

  emxFree_creal_T(&r0);
  emxInit_creal_T(&b_Y, 2);

  /* fft ends here */
  i0 = b_Y->size[0] * b_Y->size[1];
  b_Y->size[0] = Y->size[0];
  b_Y->size[1] = Y->size[1];
  emxEnsureCapacity((emxArray__common *)b_Y, i0, (int)sizeof(creal_T));
  loop_ub = Y->size[0] * Y->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Y_re = Y->data[i0].re;
    mtmp = Y->data[i0].im;
    if (mtmp == 0.0) {
      b_Y->data[i0].re = Y_re / (double)ixstart;
      b_Y->data[i0].im = 0.0;
    } else if (Y_re == 0.0) {
      b_Y->data[i0].re = 0.0;
      b_Y->data[i0].im = mtmp / (double)ixstart;
    } else {
      b_Y->data[i0].re = Y_re / (double)ixstart;
      b_Y->data[i0].im = mtmp / (double)ixstart;
    }
  }

  emxFree_creal_T(&Y);
  emxInit_real_T(&P2, 2);
  b_abs(b_Y, P2);
  Y_re = (double)ixstart / 2.0 + 1.0;
  loop_ub = (int)Y_re;
  emxFree_creal_T(&b_Y);
  for (i0 = 0; i0 < loop_ub; i0++) {
    P1_data[i0] = P2->data[i0];
  }

  emxFree_real_T(&P2);
  if (2 > (int)Y_re - 1) {
    i0 = 0;
    ixstart = 0;
    itmp = 0;
  } else {
    i0 = 1;
    ixstart = (int)Y_re - 1;
    itmp = 1;
  }

  loop_ub = ixstart - i0;
  for (ix = 0; ix < loop_ub; ix++) {
    tmp_data[ix] = 2.0 * P1_data[i0 + ix];
  }

  loop_ub = ixstart - i0;
  for (i0 = 0; i0 < loop_ub; i0++) {
    P1_data[itmp + i0] = tmp_data[i0];
  }

  ixstart = 1;
  mtmp = P1_data[0];
  itmp = 1;
  if ((int)Y_re > 1) {
    if (rtIsNaN(P1_data[0])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= (int)Y_re)) {
        ixstart = ix;
        if (!rtIsNaN(P1_data[ix - 1])) {
          mtmp = P1_data[ix - 1];
          itmp = ix;
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < (int)Y_re) {
      while (ixstart + 1 <= (int)Y_re) {
        if (P1_data[ixstart] > mtmp) {
          mtmp = P1_data[ixstart];
          itmp = ixstart + 1;
        }

        ixstart++;
      }
    }
  }

  return (double)itmp - 1.0;
}

/*
 * File trailer for vsd.c
 *
 * [EOF]
 */
