//
// File: spline.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "spline.h"
#include "vsd_emxutil.h"
#include "pwchcore.h"
#include "vsd_rtwutil.h"
#include "chckxy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable Definitions
static rtBoundsCheckInfo t_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  193,                                 // lineNo
  9,                                   // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo u_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  193,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo v_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  193,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo w_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  189,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo x_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  189,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo y_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  189,                                 // lineNo
  26,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo ab_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  187,                                 // lineNo
  14,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo bb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  182,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo cb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  182,                                 // lineNo
  21,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo db_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  172,                                 // lineNo
  15,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo eb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  164,                                 // lineNo
  19,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo fb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  164,                                 // lineNo
  13,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo gb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  161,                                 // lineNo
  9,                                   // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo hb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  161,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo ib_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  161,                                 // lineNo
  24,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo jb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  136,                                 // lineNo
  13,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo kb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  123,                                 // lineNo
  13,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo lb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  144,                                 // lineNo
  66,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo mb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  144,                                 // lineNo
  43,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo nb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  142,                                 // lineNo
  14,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo ob_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  141,                                 // lineNo
  14,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo pb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  136,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo qb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  136,                                 // lineNo
  37,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo rb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  14,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo sb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  14,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo tb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  107,                                 // lineNo
  55,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo ub_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  98,                                  // lineNo
  25,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo vb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  77,                                  // lineNo
  18,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtDoubleCheckInfo b_emlrtDCI = { 99,// lineNo
  33,                                  // colNo
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  4                                    // checkKind
};

static rtBoundsCheckInfo wb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  132,                                 // lineNo
  25,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo xb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  144,                                 // lineNo
  13,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo yb_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  128,                                 // lineNo
  29,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo ac_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  128,                                 // lineNo
  38,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo bc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  128,                                 // lineNo
  13,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo cc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  149,                                 // lineNo
  14,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo dc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  173,                                 // lineNo
  14,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo ec_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  173,                                 // lineNo
  25,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo fc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  173,                                 // lineNo
  5,                                   // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo gc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  177,                                 // lineNo
  21,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo hc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  177,                                 // lineNo
  35,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo ic_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  177,                                 // lineNo
  9,                                   // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo jc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  182,                                 // lineNo
  9,                                   // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo kc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  189,                                 // lineNo
  13,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo lc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  165,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo mc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  165,                                 // lineNo
  27,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo nc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  165,                                 // lineNo
  9,                                   // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo oc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  169,                                 // lineNo
  25,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo pc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  169,                                 // lineNo
  39,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo qc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  169,                                 // lineNo
  13,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo rc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  151,                                 // lineNo
  20,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo sc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  151,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo tc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  151,                                 // lineNo
  9,                                   // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo uc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  116,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo vc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  116,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo wc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  116,                                 // lineNo
  13,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo xc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  102,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo yc_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  102,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo ad_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  102,                                 // lineNo
  9,                                   // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo bd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  107,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo cd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  107,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo dd_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  107,                                 // lineNo
  13,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

static rtBoundsCheckInfo ed_emlrtBCI = { -1,// iFirst
  -1,                                  // iLast
  52,                                  // lineNo
  36,                                  // colNo
  "",                                  // aName
  "spline",                            // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/lib/matlab/polyfun/spline.m",// pName 
  0                                    // checkKind
};

// Function Definitions

//
// Arguments    : const double x_data[]
//                const int x_size[2]
//                const double y_data[]
//                const int y_size[2]
//                double pp_breaks_data[]
//                int pp_breaks_size[2]
//                emxArray_real_T *pp_coefs
// Return Type  : void
//
void splinepp(const double x_data[], const int x_size[2], const double y_data[],
              const int y_size[2], double pp_breaks_data[], int pp_breaks_size[2],
              emxArray_real_T *pp_coefs)
{
  int nx;
  boolean_T has_endslopes;
  emxArray_real_T *t0_coefs;
  double szdvdf[2];
  double d31;
  double dnnm2;
  int k;
  short szs[2];
  int i10;
  static double s_data[8000];
  int dx_size[2];
  double t2_coefs[4];
  double c_data[3];
  int yoffset;
  double dx_data[7999];
  int i11;
  double dvdf_data[7999];
  int dvdf_size[2];
  int s_size[2];
  int i12;
  static double md_data[8000];
  int md_size[2];
  double r;
  static double t0_breaks_data[8000];
  int t0_breaks_size[2];
  chckxy(x_data, x_size, y_data, y_size);
  nx = x_size[1] - 1;
  has_endslopes = (y_size[1] == x_size[1] + 2);
  if (x_size[1] <= 2) {
    if (has_endslopes) {
      szdvdf[0] = y_data[0];
      if (!(y_size[1] >= 1)) {
        rtDynamicBoundsError(y_size[1], 1, y_size[1], &ed_emlrtBCI);
      }

      szdvdf[1] = y_data[y_size[1] - 1];
      pwchcore(x_data, x_size, y_data, y_size, szdvdf, s_data, dx_size, t2_coefs);
      pp_breaks_size[0] = 1;
      pp_breaks_size[1] = dx_size[1];
      k = dx_size[0] * dx_size[1];
      for (i10 = 0; i10 < k; i10++) {
        pp_breaks_data[i10] = s_data[i10];
      }

      i10 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 4;
      pp_coefs->size[2] = 1;
      emxEnsureCapacity((emxArray__common *)pp_coefs, i10, (int)sizeof(double));
      for (i10 = 0; i10 < 4; i10++) {
        pp_coefs->data[i10] = t2_coefs[i10];
      }
    } else {
      szdvdf[0] = (y_data[1] - y_data[0]) / (x_data[1] - x_data[0]);
      szdvdf[1] = y_data[0];
      k = x_size[1];
      for (i10 = 0; i10 < k; i10++) {
        s_data[i10] = x_data[i10];
      }

      pp_breaks_size[0] = 1;
      pp_breaks_size[1] = x_size[1];
      k = x_size[1];
      for (i10 = 0; i10 < k; i10++) {
        pp_breaks_data[i10] = s_data[i10];
      }

      i10 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 1;
      pp_coefs->size[2] = 2;
      emxEnsureCapacity((emxArray__common *)pp_coefs, i10, (int)sizeof(double));
      for (i10 = 0; i10 < 2; i10++) {
        pp_coefs->data[i10] = szdvdf[i10];
      }
    }
  } else {
    emxInit_real_T1(&t0_coefs, 3);
    if ((x_size[1] == 3) && (!has_endslopes)) {
      d31 = x_data[1] - x_data[0];
      dnnm2 = (y_data[1] - y_data[0]) / d31;
      if (!(3 <= y_size[1])) {
        rtDynamicBoundsError(3, 1, y_size[1], &vb_emlrtBCI);
      }

      c_data[0] = ((y_data[2] - y_data[1]) / (x_data[2] - x_data[1]) - dnnm2) /
        (x_data[2] - x_data[0]);
      c_data[1] = dnnm2 - c_data[0] * d31;
      c_data[2] = y_data[0];
      szdvdf[0] = x_data[0];
      szdvdf[1] = x_data[2];
      pp_breaks_size[0] = 1;
      pp_breaks_size[1] = 2;
      for (i10 = 0; i10 < 2; i10++) {
        pp_breaks_data[pp_breaks_size[0] * i10] = szdvdf[i10];
      }

      i10 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 1;
      pp_coefs->size[2] = 3;
      emxEnsureCapacity((emxArray__common *)pp_coefs, i10, (int)sizeof(double));
      for (i10 = 0; i10 < 3; i10++) {
        pp_coefs->data[i10] = c_data[i10];
      }
    } else {
      if (has_endslopes) {
        for (i10 = 0; i10 < 2; i10++) {
          szdvdf[i10] = y_size[i10];
        }

        szdvdf[1] = (double)y_size[1] - 3.0;
        szs[1] = (short)(y_size[1] - 2);
        yoffset = 1;
      } else {
        for (i10 = 0; i10 < 2; i10++) {
          szdvdf[i10] = y_size[i10];
          szs[i10] = (short)y_size[i10];
        }

        szdvdf[1] = (double)y_size[1] - 1.0;
        yoffset = 0;
      }

      i10 = x_size[1] - 1;
      if (!(i10 <= x_size[1])) {
        rtDynamicBoundsError(i10, 1, x_size[1], &ub_emlrtBCI);
      }

      i10 = x_size[1];
      dx_size[0] = 1;
      dx_size[1] = x_size[1] - 1;
      for (i11 = 0; i11 < 2; i11++) {
        if (!(szdvdf[i11] >= 0.0)) {
          rtNonNegativeError(szdvdf[i11], &b_emlrtDCI);
        }
      }

      dvdf_size[0] = 1;
      dvdf_size[1] = (int)szdvdf[1];
      s_size[0] = 1;
      s_size[1] = szs[1];
      for (k = 1; k <= nx; k++) {
        if (!((k + 1 >= 1) && (k + 1 <= x_size[1]))) {
          rtDynamicBoundsError(k + 1, 1, x_size[1], &xc_emlrtBCI);
        }

        if (!((k >= 1) && (k <= x_size[1]))) {
          rtDynamicBoundsError(k, 1, x_size[1], &yc_emlrtBCI);
        }

        i11 = i10 - 1;
        if (!((k >= 1) && (k <= i11))) {
          rtDynamicBoundsError(k, 1, i11, &ad_emlrtBCI);
        }

        dx_data[k - 1] = x_data[k] - x_data[k - 1];
        i11 = (yoffset + k) + 1;
        if (!((i11 >= 1) && (i11 <= y_size[1]))) {
          rtDynamicBoundsError(i11, 1, y_size[1], &bd_emlrtBCI);
        }

        i12 = yoffset + k;
        if (!((i12 >= 1) && (i12 <= y_size[1]))) {
          rtDynamicBoundsError(i12, 1, y_size[1], &cd_emlrtBCI);
        }

        d31 = y_data[i11 - 1] - y_data[i12 - 1];
        i11 = i10 - 1;
        if (!((k >= 1) && (k <= i11))) {
          rtDynamicBoundsError(k, 1, i11, &tb_emlrtBCI);
        }

        if (!((k >= 1) && (k <= dvdf_size[1]))) {
          rtDynamicBoundsError(k, 1, dvdf_size[1], &dd_emlrtBCI);
        }

        dvdf_data[k - 1] = d31 / dx_data[k - 1];
      }

      for (k = 2; k <= nx; k++) {
        i11 = i10 - 1;
        if (!(k <= i11)) {
          rtDynamicBoundsError(k, 1, i11, &sb_emlrtBCI);
        }

        i11 = i10 - 1;
        i12 = k - 1;
        if (!(i12 <= i11)) {
          rtDynamicBoundsError(i12, 1, i11, &rb_emlrtBCI);
        }

        i11 = k - 1;
        if (!(i11 <= dvdf_size[1])) {
          rtDynamicBoundsError(i11, 1, dvdf_size[1], &uc_emlrtBCI);
        }

        if (!(k <= dvdf_size[1])) {
          rtDynamicBoundsError(k, 1, dvdf_size[1], &vc_emlrtBCI);
        }

        if (!(k <= s_size[1])) {
          rtDynamicBoundsError(k, 1, s_size[1], &wc_emlrtBCI);
        }

        s_data[k - 1] = 3.0 * (dx_data[k - 1] * dvdf_data[i11 - 1] + dx_data[k -
          2] * dvdf_data[k - 1]);
      }

      if (has_endslopes) {
        d31 = 0.0;
        dnnm2 = 0.0;
        i11 = szs[1];
        if (!(1 <= i11)) {
          rtDynamicBoundsError(1, 1, i11, &kb_emlrtBCI);
        }

        s_data[0] = dx_data[1] * y_data[0];
        i11 = x_size[1] - 1;
        i12 = x_size[1] - 2;
        if (!(i12 <= i11)) {
          rtDynamicBoundsError(i12, 1, i11, &yb_emlrtBCI);
        }

        i11 = x_size[1] + 2;
        if (!((i11 >= 1) && (i11 <= y_size[1]))) {
          rtDynamicBoundsError(i11, 1, y_size[1], &ac_emlrtBCI);
        }

        k = szs[1];
        if (!(x_size[1] <= k)) {
          rtDynamicBoundsError(x_size[1], 1, k, &bc_emlrtBCI);
        }

        s_data[x_size[1] - 1] = dx_data[i12 - 1] * y_data[i11 - 1];
      } else {
        d31 = x_data[2] - x_data[0];
        i11 = x_size[1] - 2;
        if (!(i11 <= x_size[1])) {
          rtDynamicBoundsError(i11, 1, x_size[1], &wb_emlrtBCI);
        }

        dnnm2 = x_data[x_size[1] - 1] - x_data[i11 - 1];
        i11 = szs[1];
        if (!(1 <= i11)) {
          rtDynamicBoundsError(1, 1, i11, &jb_emlrtBCI);
        }

        i11 = (int)szdvdf[1];
        if (!(1 <= i11)) {
          rtDynamicBoundsError(1, 1, i11, &qb_emlrtBCI);
        }

        i11 = (int)szdvdf[1];
        if (!(2 <= i11)) {
          rtDynamicBoundsError(2, 1, i11, &pb_emlrtBCI);
        }

        s_data[0] = ((dx_data[0] + 2.0 * d31) * dx_data[1] * dvdf_data[0] +
                     dx_data[0] * dx_data[0] * dvdf_data[1]) / d31;
        i11 = x_size[1] - 1;
        i12 = x_size[1] - 1;
        if (!(i12 <= i11)) {
          rtDynamicBoundsError(i12, 1, i11, &ob_emlrtBCI);
        }

        i11 = x_size[1] - 1;
        i12 = x_size[1] - 2;
        if (!(i12 <= i11)) {
          rtDynamicBoundsError(i12, 1, i11, &nb_emlrtBCI);
        }

        i11 = (int)szdvdf[1];
        i12 = x_size[1] - 1;
        if (!(i12 <= i11)) {
          rtDynamicBoundsError(i12, 1, i11, &mb_emlrtBCI);
        }

        i11 = (int)szdvdf[1];
        i12 = x_size[1] - 2;
        if (!(i12 <= i11)) {
          rtDynamicBoundsError(i12, 1, i11, &lb_emlrtBCI);
        }

        i11 = szs[1];
        if (!(x_size[1] <= i11)) {
          rtDynamicBoundsError(x_size[1], 1, i11, &xb_emlrtBCI);
        }

        s_data[x_size[1] - 1] = ((dx_data[x_size[1] - 2] + 2.0 * dnnm2) *
          dx_data[x_size[1] - 3] * dvdf_data[x_size[1] - 2] + dx_data[x_size[1]
          - 2] * dx_data[x_size[1] - 2] * dvdf_data[x_size[1] - 3]) / dnnm2;
      }

      for (i11 = 0; i11 < 2; i11++) {
        md_size[i11] = x_size[i11];
      }

      md_data[0] = dx_data[1];
      i11 = x_size[1] - 1;
      i12 = x_size[1] - 2;
      if (!(i12 <= i11)) {
        rtDynamicBoundsError(i12, 1, i11, &cc_emlrtBCI);
      }

      md_data[x_size[1] - 1] = dx_data[i12 - 1];
      for (k = 2; k <= nx; k++) {
        i11 = i10 - 1;
        if (!(k <= i11)) {
          rtDynamicBoundsError(k, 1, i11, &rc_emlrtBCI);
        }

        i11 = i10 - 1;
        i12 = k - 1;
        if (!(i12 <= i11)) {
          rtDynamicBoundsError(i12, 1, i11, &sc_emlrtBCI);
        }

        if (!(k <= md_size[1])) {
          rtDynamicBoundsError(k, 1, md_size[1], &tc_emlrtBCI);
        }

        md_data[k - 1] = 2.0 * (dx_data[k - 1] + dx_data[i12 - 1]);
      }

      r = dx_data[1] / md_data[0];
      md_data[1] -= r * d31;
      i11 = szs[1];
      if (!(2 <= i11)) {
        rtDynamicBoundsError(2, 1, i11, &gb_emlrtBCI);
      }

      i11 = szs[1];
      if (!(2 <= i11)) {
        rtDynamicBoundsError(2, 1, i11, &ib_emlrtBCI);
      }

      i11 = szs[1];
      if (!(1 <= i11)) {
        rtDynamicBoundsError(1, 1, i11, &hb_emlrtBCI);
      }

      s_data[1] -= r * s_data[0];
      for (k = 3; k <= nx; k++) {
        i11 = i10 - 1;
        if (!(k <= i11)) {
          rtDynamicBoundsError(k, 1, i11, &fb_emlrtBCI);
        }

        i11 = k - 1;
        if (!(i11 <= md_size[1])) {
          rtDynamicBoundsError(i11, 1, md_size[1], &eb_emlrtBCI);
        }

        r = dx_data[k - 1] / md_data[k - 2];
        if (!(k <= md_size[1])) {
          rtDynamicBoundsError(k, 1, md_size[1], &lc_emlrtBCI);
        }

        i11 = i10 - 1;
        i12 = k - 2;
        if (!(i12 <= i11)) {
          rtDynamicBoundsError(i12, 1, i11, &mc_emlrtBCI);
        }

        if (!(k <= md_size[1])) {
          rtDynamicBoundsError(k, 1, md_size[1], &nc_emlrtBCI);
        }

        md_data[k - 1] -= r * dx_data[i12 - 1];
        if (!(k <= s_size[1])) {
          rtDynamicBoundsError(k, 1, s_size[1], &oc_emlrtBCI);
        }

        i11 = k - 1;
        if (!(i11 <= s_size[1])) {
          rtDynamicBoundsError(i11, 1, s_size[1], &pc_emlrtBCI);
        }

        if (!(k <= s_size[1])) {
          rtDynamicBoundsError(k, 1, s_size[1], &qc_emlrtBCI);
        }

        s_data[k - 1] -= r * s_data[i11 - 1];
      }

      i11 = x_size[1] - 1;
      if (!(i11 <= md_size[1])) {
        rtDynamicBoundsError(i11, 1, md_size[1], &db_emlrtBCI);
      }

      r = dnnm2 / md_data[x_size[1] - 2];
      if (!(x_size[1] <= md_size[1])) {
        rtDynamicBoundsError(x_size[1], 1, md_size[1], &dc_emlrtBCI);
      }

      i11 = x_size[1] - 1;
      i12 = x_size[1] - 2;
      if (!(i12 <= i11)) {
        rtDynamicBoundsError(i12, 1, i11, &ec_emlrtBCI);
      }

      if (!(x_size[1] <= md_size[1])) {
        rtDynamicBoundsError(x_size[1], 1, md_size[1], &fc_emlrtBCI);
      }

      md_data[x_size[1] - 1] -= r * dx_data[i12 - 1];
      i11 = szs[1];
      if (!(x_size[1] <= i11)) {
        rtDynamicBoundsError(x_size[1], 1, i11, &gc_emlrtBCI);
      }

      i11 = szs[1];
      i12 = x_size[1] - 1;
      if (!(i12 <= i11)) {
        rtDynamicBoundsError(i12, 1, i11, &hc_emlrtBCI);
      }

      i11 = szs[1];
      if (!(x_size[1] <= i11)) {
        rtDynamicBoundsError(x_size[1], 1, i11, &ic_emlrtBCI);
      }

      s_data[x_size[1] - 1] -= r * s_data[i12 - 1];
      i11 = szs[1];
      if (!(x_size[1] <= i11)) {
        rtDynamicBoundsError(x_size[1], 1, i11, &cb_emlrtBCI);
      }

      if (!(x_size[1] <= md_size[1])) {
        rtDynamicBoundsError(x_size[1], 1, md_size[1], &bb_emlrtBCI);
      }

      i11 = szs[1];
      if (!(x_size[1] <= i11)) {
        rtDynamicBoundsError(x_size[1], 1, i11, &jc_emlrtBCI);
      }

      s_data[x_size[1] - 1] /= md_data[x_size[1] - 1];
      for (k = x_size[1] - 1; k > 1; k--) {
        i11 = i10 - 1;
        i12 = k - 1;
        if (!(i12 <= i11)) {
          rtDynamicBoundsError(i12, 1, i11, &ab_emlrtBCI);
        }

        if (!(k <= s_size[1])) {
          rtDynamicBoundsError(k, 1, s_size[1], &y_emlrtBCI);
        }

        if (!(k + 1 <= s_size[1])) {
          rtDynamicBoundsError(k + 1, 1, s_size[1], &x_emlrtBCI);
        }

        if (!(k <= md_size[1])) {
          rtDynamicBoundsError(k, 1, md_size[1], &w_emlrtBCI);
        }

        if (!(k <= s_size[1])) {
          rtDynamicBoundsError(k, 1, s_size[1], &kc_emlrtBCI);
        }

        s_data[k - 1] = (s_data[k - 1] - dx_data[k - 2] * s_data[k]) / md_data[k
          - 1];
      }

      i10 = szs[1];
      if (!(1 <= i10)) {
        rtDynamicBoundsError(1, 1, i10, &t_emlrtBCI);
      }

      i10 = szs[1];
      if (!(1 <= i10)) {
        rtDynamicBoundsError(1, 1, i10, &v_emlrtBCI);
      }

      i10 = szs[1];
      if (!(2 <= i10)) {
        rtDynamicBoundsError(2, 1, i10, &u_emlrtBCI);
      }

      s_data[0] = (s_data[0] - d31 * s_data[1]) / md_data[0];
      b_pwchcore(x_data, x_size, y_data, y_size, yoffset, s_data, s_size,
                 dx_data, dx_size, dvdf_data, dvdf_size, t0_breaks_data,
                 t0_breaks_size, t0_coefs);
      pp_breaks_size[0] = 1;
      pp_breaks_size[1] = t0_breaks_size[1];
      k = t0_breaks_size[0] * t0_breaks_size[1];
      for (i10 = 0; i10 < k; i10++) {
        pp_breaks_data[i10] = t0_breaks_data[i10];
      }

      i10 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = t0_coefs->size[1];
      pp_coefs->size[2] = 4;
      emxEnsureCapacity((emxArray__common *)pp_coefs, i10, (int)sizeof(double));
      k = t0_coefs->size[0] * t0_coefs->size[1] * t0_coefs->size[2];
      for (i10 = 0; i10 < k; i10++) {
        pp_coefs->data[i10] = t0_coefs->data[i10];
      }
    }

    emxFree_real_T(&t0_coefs);
  }
}

//
// File trailer for spline.cpp
//
// [EOF]
//
