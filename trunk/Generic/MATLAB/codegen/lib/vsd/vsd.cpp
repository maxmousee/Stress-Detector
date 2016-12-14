//
// File: vsd.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "vsd_rtwutil.h"
#include "vsd_emxutil.h"
#include "indexShapeCheck.h"
#include "abs.h"
#include "fft.h"
#include "emd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable Definitions
static rtBoundsCheckInfo emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  353,                                 // lineNo
  27,                                  // colNo
  "",                                  // aName
  "minOrMax",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo b_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  394,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "minOrMax",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo c_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  20,                                  // lineNo
  7,                                   // colNo
  "P2",                                // aName
  "vsd",                               // fName
  "/Users/maxmousee/repo/Stress-Detector/trunk/Generic/MATLAB/vsd.m",// pName
  0                                    // checkKind
};

static rtDoubleCheckInfo emlrtDCI = { 20,// lineNo
  7,                                   // colNo
  "vsd",                               // fName
  "/Users/maxmousee/repo/Stress-Detector/trunk/Generic/MATLAB/vsd.m",// pName
  1                                    // checkKind
};

static rtBoundsCheckInfo d_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  21,                                  // lineNo
  18,                                  // colNo
  "P1",                                // aName
  "vsd",                               // fName
  "/Users/maxmousee/repo/Stress-Detector/trunk/Generic/MATLAB/vsd.m",// pName
  0                                    // checkKind
};

static rtBoundsCheckInfo e_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  21,                                  // lineNo
  2,                                   // colNo
  "P1",                                // aName
  "vsd",                               // fName
  "/Users/maxmousee/repo/Stress-Detector/trunk/Generic/MATLAB/vsd.m",// pName
  0                                    // checkKind
};

static rtEqualityCheckInfo emlrtECI = { -1,// nDims
  21,                                  // lineNo
  2,                                   // colNo
  "vsd",                               // fName
  "/Users/maxmousee/repo/Stress-Detector/trunk/Generic/MATLAB/vsd.m"// pName
};

static rtBoundsCheckInfo f_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  354,                                 // lineNo
  32,                                  // colNo
  "",                                  // aName
  "minOrMax",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo g_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  395,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "minOrMax",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m",// pName 
  0                                    // checkKind
};

// Function Definitions

//
// Fs = length(input);
// The code has fixed length anyway, so it wont work with different
// sample rate anyway
// Arguments    : const double input[8000]
// Return Type  : double
//
double vsd(const double input[8000])
{
  static double imf_data[8000];
  int imf_size[2];
  int ixstart;
  emxArray_creal_T *Y;
  emxArray_creal_T *r0;
  int i0;
  int loop_ub;
  emxArray_creal_T *b_Y;
  double y;
  emxArray_real_T *P2;
  double Y_im;
  double d0;
  int ix;
  int iv0[2];
  double P1_data[4001];
  int i1;
  int i2;
  double y_data[4001];
  boolean_T exitg1;
  emd(input, imf_data, imf_size);
  if ((imf_size[0] == 0) || (imf_size[1] == 0)) {
    ixstart = 0;
  } else {
    ixstart = imf_size[1];
  }

  emxInit_creal_T(&Y, 2);
  emxInit_creal_T(&r0, 2);

  // fft starts here
  // dirty hack because matlab only generates fft code for power of 2
  // nPointDFT=nextpow2(L);
  // remember that nPointDFT should be a power of 2 or matlab coder wont
  // generate anything
  // nPointDFT=8192;
  // Y=fft(stressComponentArray, nPointDFT);
  fft(imf_data, imf_size, r0);
  i0 = Y->size[0] * Y->size[1];
  Y->size[0] = 8192;
  Y->size[1] = r0->size[1];
  emxEnsureCapacity((emxArray__common *)Y, i0, (int)sizeof(creal_T));
  loop_ub = r0->size[0] * r0->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Y->data[i0] = r0->data[i0];
  }

  emxFree_creal_T(&r0);
  emxInit_creal_T(&b_Y, 2);

  // fft ends here
  i0 = b_Y->size[0] * b_Y->size[1];
  b_Y->size[0] = Y->size[0];
  b_Y->size[1] = Y->size[1];
  emxEnsureCapacity((emxArray__common *)b_Y, i0, (int)sizeof(creal_T));
  loop_ub = Y->size[0] * Y->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    y = Y->data[i0].re;
    Y_im = Y->data[i0].im;
    if (Y_im == 0.0) {
      b_Y->data[i0].re = y / (double)ixstart;
      b_Y->data[i0].im = 0.0;
    } else if (y == 0.0) {
      b_Y->data[i0].re = 0.0;
      b_Y->data[i0].im = Y_im / (double)ixstart;
    } else {
      b_Y->data[i0].re = y / (double)ixstart;
      b_Y->data[i0].im = Y_im / (double)ixstart;
    }
  }

  emxFree_creal_T(&Y);
  emxInit_real_T(&P2, 2);
  b_abs(b_Y, P2);
  y = (double)ixstart / 2.0;
  d0 = (double)ixstart / 2.0 + 1.0;
  i0 = P2->size[1] << 13;
  if (!(1 <= i0)) {
    rtDynamicBoundsError(1, 1, i0, &c_emlrtBCI);
  }

  Y_im = (double)ixstart / 2.0 + 1.0;
  if (Y_im != std::floor(Y_im)) {
    rtIntegerError(Y_im, &emlrtDCI);
  }

  ix = (int)Y_im;
  if (!((ix >= 1) && (ix <= i0))) {
    rtDynamicBoundsError(ix, 1, i0, &c_emlrtBCI);
  }

  iv0[0] = 1;
  iv0[1] = (int)d0;
  indexShapeCheck(*(int (*)[2])P2->size, iv0);
  loop_ub = (int)d0;
  emxFree_creal_T(&b_Y);
  for (i0 = 0; i0 < loop_ub; i0++) {
    P1_data[i0] = P2->data[i0];
  }

  emxFree_real_T(&P2);
  if (2 > (int)d0 - 1) {
    i0 = 0;
    i1 = 0;
    ix = 0;
    i2 = 1;
  } else {
    i0 = (int)(y + 1.0);
    if (!(2 <= i0)) {
      rtDynamicBoundsError(2, 1, i0, &d_emlrtBCI);
    }

    i0 = 1;
    ix = (int)(y + 1.0);
    i1 = (int)d0 - 1;
    if (!((i1 >= 1) && (i1 <= ix))) {
      rtDynamicBoundsError(i1, 1, ix, &d_emlrtBCI);
    }

    ix = (int)(y + 1.0);
    if (!(2 <= ix)) {
      rtDynamicBoundsError(2, 1, ix, &e_emlrtBCI);
    }

    ix = 1;
    i2 = (int)(y + 1.0);
    ixstart = (int)d0 - 1;
    if (!((ixstart >= 1) && (ixstart <= i2))) {
      rtDynamicBoundsError(ixstart, 1, i2, &e_emlrtBCI);
    }

    i2 = ixstart + 1;
  }

  ixstart = i1 - i0;
  loop_ub = i1 - i0;
  for (i1 = 0; i1 < loop_ub; i1++) {
    y_data[i1] = 2.0 * P1_data[i0 + i1];
  }

  i0 = (i2 - ix) - 1;
  if (i0 != ixstart) {
    rtSizeEq1DError(i0, ixstart, &emlrtECI);
  }

  for (i0 = 0; i0 < ixstart; i0++) {
    P1_data[ix + i0] = y_data[i0];
  }

  ixstart = 1;
  y = P1_data[0];
  loop_ub = 1;
  if ((int)d0 > 1) {
    if (rtIsNaN(P1_data[0])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix <= (int)d0)) {
        ixstart = ix;
        i0 = (int)d0;
        if (!(ix <= i0)) {
          rtDynamicBoundsError(ix, 1, i0, &emlrtBCI);
        }

        if (!rtIsNaN(P1_data[ix - 1])) {
          i0 = (int)d0;
          if (!(ix <= i0)) {
            rtDynamicBoundsError(ix, 1, i0, &f_emlrtBCI);
          }

          y = P1_data[ix - 1];
          loop_ub = ix;
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < (int)d0) {
      for (ix = ixstart + 1; ix <= (int)d0; ix++) {
        i0 = (int)d0;
        if (!(ix <= i0)) {
          rtDynamicBoundsError(ix, 1, i0, &b_emlrtBCI);
        }

        if (P1_data[ix - 1] > y) {
          i0 = (int)d0;
          if (!(ix <= i0)) {
            rtDynamicBoundsError(ix, 1, i0, &g_emlrtBCI);
          }

          y = P1_data[ix - 1];
          loop_ub = ix;
        }
      }
    }
  }

  return (double)loop_ub - 1.0;
}

//
// File trailer for vsd.cpp
//
// [EOF]
//
