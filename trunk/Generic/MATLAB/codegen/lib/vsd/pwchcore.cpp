//
// File: pwchcore.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "pwchcore.h"
#include "vsd_rtwutil.h"
#include "vsd_emxutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable Definitions
static rtBoundsCheckInfo jd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  54,                                  // lineNo
  17,                                  // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo kd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  55,                                  // lineNo
  17,                                  // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo ld_emlrtBCI = { 1,// iFirst
  2,                                   // iLast
  60,                                  // lineNo
  29,                                  // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo md_emlrtBCI = { 1,// iFirst
  2,                                   // iLast
  61,                                  // lineNo
  19,                                  // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo nd_emlrtBCI = { 1,// iFirst
  4,                                   // iLast
  65,                                  // lineNo
  9,                                   // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo od_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  46,                                  // lineNo
  15,                                  // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo pd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  46,                                  // lineNo
  26,                                  // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo qd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  65,                                  // lineNo
  43,                                  // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo rd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  58,                                  // lineNo
  24,                                  // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo sd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  60,                                  // lineNo
  29,                                  // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo td_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  61,                                  // lineNo
  19,                                  // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo ud_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  48,                                  // lineNo
  15,                                  // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo vd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  62,                                  // lineNo
  9,                                   // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo wd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  63,                                  // lineNo
  9,                                   // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo xd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  64,                                  // lineNo
  43,                                  // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo yd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  64,                                  // lineNo
  9,                                   // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo ae_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  65,                                  // lineNo
  9,                                   // colNo
  "",                                  // aName
  "pwchcore",                          // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/private/pwchcore.m",// pName 
  0                                    // checkKind
};

// Function Definitions

//
// Arguments    : const double x_data[]
//                const int x_size[2]
//                const double y_data[]
//                const int y_size[2]
//                int yoffset
//                const double s_data[]
//                const int s_size[2]
//                const double dx_data[]
//                const int dx_size[2]
//                const double divdif_data[]
//                const int divdif_size[2]
//                double pp_breaks_data[]
//                int pp_breaks_size[2]
//                emxArray_real_T *pp_coefs
// Return Type  : void
//
void b_pwchcore(const double x_data[], const int x_size[2], const double y_data[],
                const int y_size[2], int yoffset, const double s_data[], const
                int s_size[2], const double dx_data[], const int dx_size[2],
                const double divdif_data[], const int divdif_size[2], double
                pp_breaks_data[], int pp_breaks_size[2], emxArray_real_T
                *pp_coefs)
{
  int nx;
  int nxm1;
  int loop_ub;
  int i15;
  double dzzdx;
  double dzdxdx;
  int i16;
  int i17;
  nx = x_size[1] - 1;
  nxm1 = x_size[1] - 1;
  pp_breaks_size[0] = 1;
  pp_breaks_size[1] = x_size[1];
  loop_ub = x_size[1];
  for (i15 = 0; i15 < loop_ub; i15++) {
    pp_breaks_data[pp_breaks_size[0] * i15] = x_data[i15];
  }

  i15 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
  pp_coefs->size[0] = 1;
  pp_coefs->size[1] = (short)(x_size[1] - 1);
  pp_coefs->size[2] = 4;
  emxEnsureCapacity((emxArray__common *)pp_coefs, i15, (int)sizeof(double));
  for (loop_ub = 1; loop_ub <= nx; loop_ub++) {
    if (!((loop_ub >= 1) && (loop_ub <= dx_size[1]))) {
      rtDynamicBoundsError(loop_ub, 1, dx_size[1], &ud_emlrtBCI);
    }

    if (!((loop_ub >= 1) && (loop_ub <= divdif_size[1]))) {
      rtDynamicBoundsError(loop_ub, 1, divdif_size[1], &rd_emlrtBCI);
    }

    if (!((loop_ub >= 1) && (loop_ub <= s_size[1]))) {
      rtDynamicBoundsError(loop_ub, 1, s_size[1], &sd_emlrtBCI);
    }

    dzzdx = (divdif_data[loop_ub - 1] - s_data[loop_ub - 1]) / dx_data[loop_ub -
      1];
    if (!((loop_ub + 1 >= 1) && (loop_ub + 1 <= s_size[1]))) {
      rtDynamicBoundsError(loop_ub + 1, 1, s_size[1], &td_emlrtBCI);
    }

    dzdxdx = (s_data[loop_ub] - divdif_data[loop_ub - 1]) / dx_data[loop_ub - 1];
    i15 = pp_coefs->size[1] << 2;
    if (!((loop_ub >= 1) && (loop_ub <= i15))) {
      rtDynamicBoundsError(loop_ub, 1, i15, &vd_emlrtBCI);
    }

    pp_coefs->data[loop_ub - 1] = (dzdxdx - dzzdx) / dx_data[loop_ub - 1];
    i15 = pp_coefs->size[1] << 2;
    i16 = nx + loop_ub;
    if (!((i16 >= 1) && (i16 <= i15))) {
      rtDynamicBoundsError(i16, 1, i15, &wd_emlrtBCI);
    }

    pp_coefs->data[i16 - 1] = 2.0 * dzzdx - dzdxdx;
    if (!((loop_ub >= 1) && (loop_ub <= s_size[1]))) {
      rtDynamicBoundsError(loop_ub, 1, s_size[1], &xd_emlrtBCI);
    }

    i15 = pp_coefs->size[1] << 2;
    i16 = (nxm1 << 1) + loop_ub;
    if (!((i16 >= 1) && (i16 <= i15))) {
      rtDynamicBoundsError(i16, 1, i15, &yd_emlrtBCI);
    }

    pp_coefs->data[i16 - 1] = s_data[loop_ub - 1];
    i15 = yoffset + loop_ub;
    if (!((i15 >= 1) && (i15 <= y_size[1]))) {
      rtDynamicBoundsError(i15, 1, y_size[1], &qd_emlrtBCI);
    }

    i16 = pp_coefs->size[1] << 2;
    i17 = 3 * nxm1 + loop_ub;
    if (!((i17 >= 1) && (i17 <= i16))) {
      rtDynamicBoundsError(i17, 1, i16, &ae_emlrtBCI);
    }

    pp_coefs->data[i17 - 1] = y_data[i15 - 1];
  }
}

//
// Arguments    : const double x_data[]
//                const int x_size[2]
//                const double y_data[]
//                const int y_size[2]
//                const double s[2]
//                double pp_breaks_data[]
//                int pp_breaks_size[2]
//                double pp_coefs[4]
// Return Type  : void
//
void pwchcore(const double x_data[], const int x_size[2], const double y_data[],
              const int y_size[2], const double s[2], double pp_breaks_data[],
              int pp_breaks_size[2], double pp_coefs[4])
{
  int loop_ub;
  int i14;
  double dxj;
  double divdifij;
  double dzzdx;
  pp_breaks_size[0] = 1;
  pp_breaks_size[1] = x_size[1];
  loop_ub = x_size[1];
  for (i14 = 0; i14 < loop_ub; i14++) {
    pp_breaks_data[i14] = x_data[i14];
  }

  for (loop_ub = 2; loop_ub - 1 < x_size[1]; loop_ub++) {
    if (!((loop_ub >= 1) && (loop_ub <= x_size[1]))) {
      rtDynamicBoundsError(loop_ub, 1, x_size[1], &od_emlrtBCI);
    }

    i14 = loop_ub - 1;
    if (!((i14 >= 1) && (i14 <= x_size[1]))) {
      rtDynamicBoundsError(i14, 1, x_size[1], &pd_emlrtBCI);
    }

    dxj = x_data[loop_ub - 1] - x_data[i14 - 1];
    if (!((loop_ub + 1 >= 1) && (loop_ub + 1 <= y_size[1]))) {
      rtDynamicBoundsError(loop_ub + 1, 1, y_size[1], &jd_emlrtBCI);
    }

    if (!((loop_ub >= 1) && (loop_ub <= y_size[1]))) {
      rtDynamicBoundsError(loop_ub, 1, y_size[1], &kd_emlrtBCI);
    }

    divdifij = (y_data[loop_ub] - y_data[loop_ub - 1]) / dxj;
    i14 = loop_ub - 1;
    if (!((i14 >= 1) && (i14 <= 2))) {
      rtDynamicBoundsError(i14, 1, 2, &ld_emlrtBCI);
    }

    dzzdx = (divdifij - s[loop_ub - 2]) / dxj;
    if (!((loop_ub >= 1) && (loop_ub <= 2))) {
      rtDynamicBoundsError(loop_ub, 1, 2, &md_emlrtBCI);
    }

    divdifij = (s[1] - divdifij) / dxj;
    pp_coefs[loop_ub - 2] = (divdifij - dzzdx) / dxj;
    pp_coefs[loop_ub - 1] = 2.0 * dzzdx - divdifij;
    pp_coefs[loop_ub] = s[loop_ub - 2];
    if (!((loop_ub + 2 >= 1) && (loop_ub + 2 <= 4))) {
      rtDynamicBoundsError(loop_ub + 2, 1, 4, &nd_emlrtBCI);
    }

    if (!((loop_ub >= 1) && (loop_ub <= y_size[1]))) {
      rtDynamicBoundsError(loop_ub, 1, y_size[1], &qd_emlrtBCI);
    }

    pp_coefs[3] = y_data[loop_ub - 1];
  }
}

//
// File trailer for pwchcore.cpp
//
// [EOF]
//
