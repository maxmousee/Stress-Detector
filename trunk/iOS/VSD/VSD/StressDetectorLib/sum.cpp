//
// File: sum.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "sum.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Definitions

//
// Arguments    : const double x[8000]
// Return Type  : double
//
double b_sum(const double x[8000])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 7999; k++) {
    y += x[k + 1];
  }

  return y;
}

//
// Arguments    : const boolean_T x[7999]
// Return Type  : double
//
double sum(const boolean_T x[7999])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 7998; k++) {
    y += (double)x[k + 1];
  }

  return y;
}

//
// File trailer for sum.cpp
//
// [EOF]
//
