/*
 * File: fft.c
 *
 * MATLAB Coder version            : 2.7
 * C/C++ source code generated on  : 26-May-2015 20:44:52
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "processAudio.h"
#include "fft.h"
#include "processAudio_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const double x[8000]
 *                int varargin_1
 *                emxArray_creal_T *y
 * Return Type  : void
 */
void fft(const double x[8000], int varargin_1, emxArray_creal_T *y)
{
  emxArray_creal_T *b_y1;
  int ju;
  int minval;
  int ixDelta;
  emxArray_real_T *costab1q;
  int nRowsD2;
  int nRowsD4;
  double e;
  int nd2;
  int k;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  int n;
  int ix;
  int chanStart;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  int iDelta2;
  int iheight;
  int ihi;
  double twid_im;
  b_emxInit_creal_T(&b_y1, 1);
  ju = b_y1->size[0];
  b_y1->size[0] = varargin_1;
  emxEnsureCapacity((emxArray__common *)b_y1, ju, (int)sizeof(creal_T));
  if (varargin_1 > 8000) {
    ju = b_y1->size[0];
    b_y1->size[0] = varargin_1;
    emxEnsureCapacity((emxArray__common *)b_y1, ju, (int)sizeof(creal_T));
    for (ju = 0; ju < varargin_1; ju++) {
      b_y1->data[ju].re = 0.0;
      b_y1->data[ju].im = 0.0;
    }
  }

  if (varargin_1 <= 8000) {
    minval = varargin_1;
  } else {
    minval = 8000;
  }

  if (1 >= 8001 - minval) {
    ixDelta = 1;
  } else {
    ixDelta = 8001 - minval;
  }

  emxInit_real_T(&costab1q, 2);
  nRowsD2 = (varargin_1 + (varargin_1 < 0)) >> 1;
  nRowsD4 = (nRowsD2 + (nRowsD2 < 0)) >> 1;
  e = 6.2831853071795862 / (double)varargin_1;
  ju = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = nRowsD4 + 1;
  emxEnsureCapacity((emxArray__common *)costab1q, ju, (int)sizeof(double));
  costab1q->data[0] = 1.0;
  nd2 = (nRowsD4 + (nRowsD4 < 0)) >> 1;
  for (k = 1; k <= nd2; k++) {
    costab1q->data[k] = cos(e * (double)k);
  }

  for (k = nd2 + 1; k < nRowsD4; k++) {
    costab1q->data[k] = sin(e * (double)(nRowsD4 - k));
  }

  emxInit_real_T(&costab, 2);
  emxInit_real_T(&sintab, 2);
  costab1q->data[nRowsD4] = 0.0;
  n = costab1q->size[1] - 1;
  nd2 = (costab1q->size[1] - 1) << 1;
  ju = costab->size[0] * costab->size[1];
  costab->size[0] = 1;
  costab->size[1] = nd2 + 1;
  emxEnsureCapacity((emxArray__common *)costab, ju, (int)sizeof(double));
  ju = sintab->size[0] * sintab->size[1];
  sintab->size[0] = 1;
  sintab->size[1] = nd2 + 1;
  emxEnsureCapacity((emxArray__common *)sintab, ju, (int)sizeof(double));
  costab->data[0] = 1.0;
  sintab->data[0] = 0.0;
  for (k = 1; k <= n; k++) {
    costab->data[k] = costab1q->data[k];
    sintab->data[k] = -costab1q->data[n - k];
  }

  for (k = costab1q->size[1]; k <= nd2; k++) {
    costab->data[k] = -costab1q->data[nd2 - k];
    sintab->data[k] = -costab1q->data[k - n];
  }

  emxFree_real_T(&costab1q);
  ix = 0;
  chanStart = 0;
  while (((varargin_1 > 0) && (chanStart <= 0)) || ((varargin_1 < 0) &&
          (chanStart >= 0))) {
    ju = 0;
    nd2 = chanStart;
    for (i = 1; i < minval; i++) {
      b_y1->data[nd2].re = x[ix];
      b_y1->data[nd2].im = 0.0;
      n = varargin_1;
      tst = true;
      while (tst) {
        n >>= 1;
        ju ^= n;
        tst = ((ju & n) == 0);
      }

      nd2 = chanStart + ju;
      ix++;
    }

    b_y1->data[nd2].re = x[ix];
    b_y1->data[nd2].im = 0.0;
    ix += ixDelta;
    nd2 = (chanStart + varargin_1) - 2;
    if (varargin_1 > 1) {
      for (i = chanStart; i <= nd2; i += 2) {
        temp_re = b_y1->data[i + 1].re;
        temp_im = b_y1->data[i + 1].im;
        b_y1->data[i + 1].re = b_y1->data[i].re - b_y1->data[i + 1].re;
        b_y1->data[i + 1].im = b_y1->data[i].im - b_y1->data[i + 1].im;
        b_y1->data[i].re += temp_re;
        b_y1->data[i].im += temp_im;
      }
    }

    n = 2;
    iDelta2 = 4;
    k = nRowsD4;
    iheight = 1 + ((nRowsD4 - 1) << 2);
    while (k > 0) {
      i = chanStart;
      ihi = chanStart + iheight;
      while (i < ihi) {
        nd2 = i + n;
        temp_re = b_y1->data[nd2].re;
        temp_im = b_y1->data[nd2].im;
        b_y1->data[i + n].re = b_y1->data[i].re - b_y1->data[nd2].re;
        b_y1->data[i + n].im = b_y1->data[i].im - b_y1->data[nd2].im;
        b_y1->data[i].re += temp_re;
        b_y1->data[i].im += temp_im;
        i += iDelta2;
      }

      nd2 = chanStart + 1;
      for (ju = k; ju < nRowsD2; ju += k) {
        e = costab->data[ju];
        twid_im = sintab->data[ju];
        i = nd2;
        ihi = nd2 + iheight;
        while (i < ihi) {
          temp_re = e * b_y1->data[i + n].re - twid_im * b_y1->data[i + n].im;
          temp_im = e * b_y1->data[i + n].im + twid_im * b_y1->data[i + n].re;
          b_y1->data[i + n].re = b_y1->data[i].re - temp_re;
          b_y1->data[i + n].im = b_y1->data[i].im - temp_im;
          b_y1->data[i].re += temp_re;
          b_y1->data[i].im += temp_im;
          i += iDelta2;
        }

        nd2++;
      }

      k >>= 1;
      n = iDelta2;
      iDelta2 <<= 1;
      iheight -= n;
    }

    chanStart += varargin_1;
  }

  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
  ju = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_y1->size[0];
  emxEnsureCapacity((emxArray__common *)y, ju, (int)sizeof(creal_T));
  nd2 = b_y1->size[0];
  for (ju = 0; ju < nd2; ju++) {
    y->data[y->size[0] * ju] = b_y1->data[ju];
  }

  emxFree_creal_T(&b_y1);
}

/*
 * File trailer for fft.c
 *
 * [EOF]
 */
