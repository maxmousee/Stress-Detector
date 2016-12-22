//
// File: vsd.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 21-Dec-2016 23:54:03
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "vsd_emxutil.h"
#include "abs.h"
#include "fft.h"
#include "emd.h"

// Function Definitions

//
// Fs = length(input);
// The code has fixed length anyway, so it wont work with different
// sample rate anyway
// Arguments    : const double input[1024]
// Return Type  : double
//
double vsd(const double input[1024])
{
  emxArray_real_T *imf;
  emxArray_creal_T *Y;
  emxArray_creal_T *r0;
  int ixstart;
  int loop_ub;
  emxArray_creal_T *b_Y;
  double mtmp;
  emxArray_real_T *P2;
  double Y_im;
  double P1[513];
  int ix;
  boolean_T exitg1;
  emxInit_real_T(&imf, 2);
  emxInit_creal_T(&Y, 2);
  emxInit_creal_T(&r0, 2);
  emd(*(double (*)[8192])&input[0], imf);

  // fft starts here
  // dirty hack because matlab only generates fft code for power of 2
  // nPointDFT=nextpow2(L);
  // remember that nPointDFT should be a power of 2 or matlab coder wont
  // generate anything
  fft(imf, r0);
  ixstart = Y->size[0] * Y->size[1];
  Y->size[0] = 8192;
  Y->size[1] = r0->size[1];
  emxEnsureCapacity((emxArray__common *)Y, ixstart, (int)sizeof(creal_T));
  loop_ub = r0->size[0] * r0->size[1];
  emxFree_real_T(&imf);
  for (ixstart = 0; ixstart < loop_ub; ixstart++) {
    Y->data[ixstart] = r0->data[ixstart];
  }

  emxFree_creal_T(&r0);
  emxInit_creal_T(&b_Y, 2);

  // fft ends here
  ixstart = b_Y->size[0] * b_Y->size[1];
  b_Y->size[0] = Y->size[0];
  b_Y->size[1] = Y->size[1];
  emxEnsureCapacity((emxArray__common *)b_Y, ixstart, (int)sizeof(creal_T));
  loop_ub = Y->size[0] * Y->size[1];
  for (ixstart = 0; ixstart < loop_ub; ixstart++) {
    mtmp = Y->data[ixstart].re;
    Y_im = Y->data[ixstart].im;
    if (Y_im == 0.0) {
      b_Y->data[ixstart].re = mtmp / 1024.0;
      b_Y->data[ixstart].im = 0.0;
    } else if (mtmp == 0.0) {
      b_Y->data[ixstart].re = 0.0;
      b_Y->data[ixstart].im = Y_im / 1024.0;
    } else {
      b_Y->data[ixstart].re = mtmp / 1024.0;
      b_Y->data[ixstart].im = Y_im / 1024.0;
    }
  }

  emxFree_creal_T(&Y);
  emxInit_real_T(&P2, 2);
  b_abs(b_Y, P2);
  emxFree_creal_T(&b_Y);
  for (ixstart = 0; ixstart < 513; ixstart++) {
    P1[ixstart] = P2->data[ixstart];
  }

  emxFree_real_T(&P2);
  for (ixstart = 0; ixstart < 511; ixstart++) {
    P1[1 + ixstart] *= 2.0;
  }

  ixstart = 1;
  mtmp = P1[0];
  loop_ub = 1;
  if (rtIsNaN(P1[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 514)) {
      ixstart = ix;
      if (!rtIsNaN(P1[ix - 1])) {
        mtmp = P1[ix - 1];
        loop_ub = ix;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 513) {
    while (ixstart + 1 < 514) {
      if (P1[ixstart] > mtmp) {
        mtmp = P1[ixstart];
        loop_ub = ixstart + 1;
      }

      ixstart++;
    }
  }

  return (double)loop_ub - 1.0;
}

//
// File trailer for vsd.cpp
//
// [EOF]
//
