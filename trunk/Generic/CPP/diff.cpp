//
// File: diff.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "diff.h"
#include "vsd_rtwutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable Definitions
static rtBoundsCheckInfo m_emlrtBCI = { 1,// iFirst
  8000,                                // iLast
  107,                                 // lineNo
  27,                                  // colNo
  "",                                  // aName
  "diff",                              // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/datafun/diff.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo n_emlrtBCI = { 1,// iFirst
  7999,                                // iLast
  114,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "diff",                              // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/datafun/diff.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo o_emlrtBCI = { 1,// iFirst
  7999,                                // iLast
  107,                                 // lineNo
  27,                                  // colNo
  "",                                  // aName
  "diff",                              // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/datafun/diff.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo p_emlrtBCI = { 1,// iFirst
  7998,                                // iLast
  114,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "diff",                              // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/datafun/diff.m",// pName 
  0                                    // checkKind
};

// Function Definitions

//
// Arguments    : const boolean_T x[7999]
//                double y[7998]
// Return Type  : void
//
void b_diff(const boolean_T x[7999], double y[7998])
{
  int ixLead;
  int iyLead;
  int work;
  int m;
  int tmp2;
  ixLead = 1;
  iyLead = 1;
  work = x[0];
  for (m = 0; m < 7998; m++) {
    if (!((ixLead + 1 >= 1) && (ixLead + 1 <= 7999))) {
      rtDynamicBoundsError(ixLead + 1, 1, 7999, &o_emlrtBCI);
    }

    tmp2 = work;
    work = x[ixLead];
    tmp2 = x[ixLead] - tmp2;
    ixLead++;
    if (!((iyLead >= 1) && (iyLead <= 7998))) {
      rtDynamicBoundsError(iyLead, 1, 7998, &p_emlrtBCI);
    }

    y[iyLead - 1] = tmp2;
    iyLead++;
  }
}

//
// Arguments    : const double x[8000]
//                double y[7999]
// Return Type  : void
//
void diff(const double x[8000], double y[7999])
{
  int ixLead;
  int iyLead;
  double work;
  int m;
  double tmp2;
  ixLead = 1;
  iyLead = 1;
  work = x[0];
  for (m = 0; m < 7999; m++) {
    if (!((ixLead + 1 >= 1) && (ixLead + 1 <= 8000))) {
      rtDynamicBoundsError(ixLead + 1, 1, 8000, &m_emlrtBCI);
    }

    tmp2 = work;
    work = x[ixLead];
    tmp2 = x[ixLead] - tmp2;
    ixLead++;
    if (!((iyLead >= 1) && (iyLead <= 7999))) {
      rtDynamicBoundsError(iyLead, 1, 7999, &n_emlrtBCI);
    }

    y[iyLead - 1] = tmp2;
    iyLead++;
  }
}

//
// File trailer for diff.cpp
//
// [EOF]
//
