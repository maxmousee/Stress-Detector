//
// File: chckxy.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "chckxy.h"
#include "vsd_rtwutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable Definitions
static rtBoundsCheckInfo fd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  51,                                  // lineNo
  14,                                  // colNo
  "",                                  // aName
  "chckxy",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/chckxy.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo gd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  70,                                  // lineNo
  17,                                  // colNo
  "",                                  // aName
  "chckxy",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/chckxy.m",// pName 
  0                                    // checkKind
};

static rtRunTimeErrorInfo c_emlrtRTEI = { 42,// lineNo
  19,                                  // colNo
  "chckxy",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/chckxy.m"// pName 
};

static rtRunTimeErrorInfo d_emlrtRTEI = { 38,// lineNo
  1,                                   // colNo
  "chckxy",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/chckxy.m"// pName 
};

static rtRunTimeErrorInfo e_emlrtRTEI = { 36,// lineNo
  15,                                  // colNo
  "chckxy",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/chckxy.m"// pName 
};

static rtRunTimeErrorInfo f_emlrtRTEI = { 32,// lineNo
  15,                                  // colNo
  "chckxy",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/chckxy.m"// pName 
};

static rtBoundsCheckInfo hd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  64,                                  // lineNo
  14,                                  // colNo
  "",                                  // aName
  "chckxy",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/chckxy.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo id_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  64,                                  // lineNo
  23,                                  // colNo
  "",                                  // aName
  "chckxy",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/chckxy.m",// pName 
  0                                    // checkKind
};

// Function Definitions

//
// Arguments    : const double x_data[]
//                const int x_size[2]
//                const double y_data[]
//                const int y_size[2]
// Return Type  : void
//
void chckxy(const double x_data[], const int x_size[2], const double y_data[],
            const int y_size[2])
{
  boolean_T p;
  int k;
  boolean_T exitg2;
  int i13;
  boolean_T exitg1;
  if (!(x_size[1] >= 2)) {
    g_rtErrorWithMessageID(&f_emlrtRTEI);
  }

  p = true;
  k = 0;
  exitg2 = false;
  while ((!exitg2) && (k <= x_size[1] - 2)) {
    if (!((k + 1 >= 1) && (k + 1 <= x_size[1]))) {
      rtDynamicBoundsError(k + 1, 1, x_size[1], &hd_emlrtBCI);
    }

    i13 = 2 + k;
    if (!((i13 >= 1) && (i13 <= x_size[1]))) {
      rtDynamicBoundsError(i13, 1, x_size[1], &id_emlrtBCI);
    }

    if (!(x_data[k] < x_data[i13 - 1])) {
      p = false;
      exitg2 = true;
    } else {
      k++;
    }
  }

  if (p) {
    i13 = x_size[1];
    if (!((i13 >= 1) && (i13 <= x_size[1]))) {
      rtDynamicBoundsError(i13, 1, x_size[1], &gd_emlrtBCI);
    }

    p = true;
  } else {
    p = false;
  }

  if (!p) {
    f_rtErrorWithMessageID(&e_emlrtRTEI);
  }

  p = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= y_size[1] - 1)) {
    i13 = k + 1;
    if (!((i13 >= 1) && (i13 <= y_size[1]))) {
      rtDynamicBoundsError(i13, 1, y_size[1], &fd_emlrtBCI);
    }

    if (rtIsNaN(y_data[k])) {
      p = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (p) {
    e_rtErrorWithMessageID(&d_emlrtRTEI);
  }

  if ((y_size[1] != x_size[1]) && (y_size[1] != x_size[1] + 2)) {
    d_rtErrorWithMessageID(x_size[1], y_size[1], &c_emlrtRTEI);
  }
}

//
// File trailer for chckxy.cpp
//
// [EOF]
//
