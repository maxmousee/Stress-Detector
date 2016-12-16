//
// File: vsd_rtwutil.h
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//
#ifndef VSD_RTWUTIL_H
#define VSD_RTWUTIL_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "vsd_types.h"

// Function Declarations
extern void b_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo);
extern void c_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo);
extern void d_rtErrorWithMessageID(const int b, const int c, const
  rtRunTimeErrorInfo *aInfo);
extern void e_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo);
extern void f_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo);
extern void g_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo);
extern void h_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo);
extern void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
  const rtBoundsCheckInfo *aInfo);
extern void rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo);
extern void rtIntegerError(const double aInteger, const rtDoubleCheckInfo *aInfo);
extern void rtNonNegativeError(const double aPositive, const rtDoubleCheckInfo
  *aInfo);
extern void rtSizeEq1DError(const int aDim1, const int aDim2, const
  rtEqualityCheckInfo *aInfo);
extern void rtSizeEqNDCheck(const int *aDims1, const int *aDims2, const
  rtEqualityCheckInfo *aInfo);

#endif

//
// File trailer for vsd_rtwutil.h
//
// [EOF]
//
