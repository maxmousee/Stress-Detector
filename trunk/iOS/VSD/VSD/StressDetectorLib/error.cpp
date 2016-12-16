//
// File: error.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "error.h"
#include "vsd_rtwutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable Definitions
static rtRunTimeErrorInfo b_emlrtRTEI = { 17,// lineNo
  9,                                   // colNo
  "error",                             // fName
  "/Applications/MATLAB/MATLAB_R2016b.app/toolbox/eml/eml/+coder/+internal/error.m"// pName 
};

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void error()
{
  c_rtErrorWithMessageID(&b_emlrtRTEI);
}

//
// File trailer for error.cpp
//
// [EOF]
//
