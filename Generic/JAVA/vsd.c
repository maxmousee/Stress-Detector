/*
 * File: vsd.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

/* Include Files */
#include <string.h>
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
 * Arguments    : const double input_data[]
 *                const int input_size
 * Return Type  : double
 */
double vsd(const double input_data[], const int input_size)
{
  emxArray_creal_T *r0;
  emxArray_creal_T *r1;
  static double imf_data[8000];
  int imf_size[2];
  int idx;
  int loop_ub;
  double re;
  double im;
  double P1[4001];
  boolean_T exitg1;
  (void)input_size;
  emxInit_creal_T(&r0, 2);
  emxInit_creal_T(&r1, 2);
  emd(*(double (*)[8000])&input_data[0], imf_data, imf_size);

  /* fft starts here */
  /* dirty hack because matlab only generates fft code for power of 2 */
  /* nPointDFT=nextpow2(L); */
  /* remember that nPointDFT should be a power of 2 or matlab coder wont */
  /* generate anything */
  /* fft ends here */
  fft(imf_data, imf_size, r0);
  idx = r1->size[0] * r1->size[1];
  r1->size[0] = r0->size[0];
  r1->size[1] = 8000;
  emxEnsureCapacity_creal_T(r1, idx);
  loop_ub = r0->size[0] * r0->size[1];
  for (idx = 0; idx < loop_ub; idx++) {
    re = r0->data[idx].re;
    im = r0->data[idx].im;
    if (im == 0.0) {
      r1->data[idx].re = re / 8000.0;
      r1->data[idx].im = 0.0;
    } else if (re == 0.0) {
      r1->data[idx].re = 0.0;
      r1->data[idx].im = im / 8000.0;
    } else {
      r1->data[idx].re = re / 8000.0;
      r1->data[idx].im = im / 8000.0;
    }
  }

  emxFree_creal_T(&r0);
  b_abs(r1, imf_data, imf_size);
  emxFree_creal_T(&r1);
  memcpy(&P1[0], &imf_data[0], 4001U * sizeof(double));
  for (idx = 0; idx < 3999; idx++) {
    P1[1 + idx] *= 2.0;
  }

  if (!rtIsNaN(P1[0])) {
    idx = 1;
  } else {
    idx = 0;
    loop_ub = 2;
    exitg1 = false;
    while ((!exitg1) && (loop_ub < 4002)) {
      if (!rtIsNaN(P1[loop_ub - 1])) {
        idx = loop_ub;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
  }

  if (idx == 0) {
    idx = 1;
  } else {
    re = P1[idx - 1];
    for (loop_ub = idx; loop_ub + 1 < 4002; loop_ub++) {
      if (re < P1[loop_ub]) {
        re = P1[loop_ub];
        idx = loop_ub + 1;
      }
    }
  }

  return (double)idx - 1.0;
}

/*
 * File trailer for vsd.c
 *
 * [EOF]
 */
