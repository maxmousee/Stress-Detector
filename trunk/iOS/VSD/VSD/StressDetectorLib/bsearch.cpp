//
// File: bsearch.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "bsearch.h"
#include "vsd_rtwutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable Definitions
static rtBoundsCheckInfo be_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  60,                                  // lineNo
  25,                                  // colNo
  "",                                  // aName
  "bsearch",                           // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/eml/+coder/+internal/bsearch.m",// pName 
  0                                    // checkKind
};

// Function Definitions

//
// Arguments    : const double x_data[]
//                const int x_size[2]
//                double xi
// Return Type  : int
//
int b_bsearch(const double x_data[], const int x_size[2], double xi)
{
  int n;
  int low_ip1;
  int high_i;
  int mid_i;
  n = 1;
  low_ip1 = 2;
  high_i = x_size[1];
  while (high_i > low_ip1) {
    mid_i = (n >> 1) + (high_i >> 1);
    if (((n & 1) == 1) && ((high_i & 1) == 1)) {
      mid_i++;
    }

    if (!((mid_i >= 1) && (mid_i <= x_size[1]))) {
      rtDynamicBoundsError(mid_i, 1, x_size[1], &be_emlrtBCI);
    }

    if (xi >= x_data[mid_i - 1]) {
      n = mid_i;
      low_ip1 = mid_i + 1;
    } else {
      high_i = mid_i;
    }
  }

  return n;
}

//
// File trailer for bsearch.cpp
//
// [EOF]
//
