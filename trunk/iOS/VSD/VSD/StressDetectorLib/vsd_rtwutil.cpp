//
// File: vsd_rtwutil.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "vsd_rtwutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations
static void rtAddSizeString(char * aBuf, const int aDim);
static void rtGenSizeString(const int aNDims, const int *aDims, char *aBuf);
static boolean_T rtIsNullOrEmptyString(const char *aString);
static void rtReportErrorLocation(const char * aFcnName, const int aLineNo);

// Function Definitions

//
// Arguments    : char * aBuf
//                const int aDim
// Return Type  : void
//
static void rtAddSizeString(char * aBuf, const int aDim)
{
  char dimStr[1024];
  sprintf(dimStr, "[%d]", aDim);
  if (strlen(aBuf) + strlen(dimStr) < 1024) {
    strcat(aBuf, dimStr);
  }
}

//
// Arguments    : const int aNDims
//                const int *aDims
//                char *aBuf
// Return Type  : void
//
static void rtGenSizeString(const int aNDims, const int *aDims, char *aBuf)
{
  int i;
  aBuf[0] = '\x00';
  for (i = 0; i < aNDims; i++) {
    rtAddSizeString(aBuf, aDims[i]);
  }
}

//
// Arguments    : const char *aString
// Return Type  : boolean_T
//
static boolean_T rtIsNullOrEmptyString(const char *aString)
{
  return (aString == NULL) || (*aString == '\x00');
}

//
// Arguments    : const char * aFcnName
//                const int aLineNo
// Return Type  : void
//
static void rtReportErrorLocation(const char * aFcnName, const int aLineNo)
{
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNo);
  fprintf(stderr, "\n");
}

//
// Arguments    : const rtRunTimeErrorInfo *aInfo
// Return Type  : void
//
void b_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo)
{
  fprintf(stderr, "Assertion failed.");
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

//
// Arguments    : const rtRunTimeErrorInfo *aInfo
// Return Type  : void
//
void c_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo)
{
  fprintf(stderr, "NaN\'s cannot be converted to logicals.");
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

//
// Arguments    : const int b
//                const int c
//                const rtRunTimeErrorInfo *aInfo
// Return Type  : void
//
void d_rtErrorWithMessageID(const int b, const int c, const rtRunTimeErrorInfo
  *aInfo)
{
  fprintf(stderr,
          "The number of sites, %d, is incompatible with the number of values, %d.",
          b, c);
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

//
// Arguments    : const rtRunTimeErrorInfo *aInfo
// Return Type  : void
//
void e_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo)
{
  fprintf(stderr, "NaN values in Y are not supported for code generation.");
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

//
// Arguments    : const rtRunTimeErrorInfo *aInfo
// Return Type  : void
//
void f_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo)
{
  fprintf(stderr, "X must be finite and strictly increasing.");
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

//
// Arguments    : const rtRunTimeErrorInfo *aInfo
// Return Type  : void
//
void g_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo)
{
  fprintf(stderr, "There should be at least two data points.");
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

//
// Arguments    : const rtRunTimeErrorInfo *aInfo
// Return Type  : void
//
void h_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo)
{
  fprintf(stderr,
          "Code generation assumption about size violated. Unexpected run-time vector changed predicted orientation.");
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

//
// Arguments    : int aIndexValue
//                int aLoBound
//                int aHiBound
//                const rtBoundsCheckInfo *aInfo
// Return Type  : void
//
void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound, const
  rtBoundsCheckInfo *aInfo)
{
  if (aLoBound == 0) {
    aIndexValue++;
    aLoBound = 1;
    aHiBound++;
  }

  if (rtIsNullOrEmptyString(aInfo->aName)) {
    fprintf(stderr,
            "Index exceeds array dimensions.  Index value %d exceeds valid range [%d-%d].",
            aIndexValue, aLoBound, aHiBound);
    fprintf(stderr, "\n");
  } else {
    fprintf(stderr,
            "Index exceeds array dimensions.  Index value %d exceeds valid range [%d-%d] of array %s.",
            aIndexValue, aLoBound, aHiBound, aInfo->aName);
    fprintf(stderr, "\n");
  }

  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

//
// Arguments    : const rtRunTimeErrorInfo *aInfo
// Return Type  : void
//
void rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo)
{
  fprintf(stderr,
          "The working dimension was selected automatically, is variable-length, and has length 1 at run time. This is not supported. Manua"
          "lly select the working dimension by supplying the DIM argument.");
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

//
// Arguments    : const double aInteger
//                const rtDoubleCheckInfo *aInfo
// Return Type  : void
//
void rtIntegerError(const double aInteger, const rtDoubleCheckInfo *aInfo)
{
  fprintf(stderr,
          "Expected a value representable in the C type \'int\'.  Found %g instead.",
          aInteger);
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

//
// Arguments    : const double aPositive
//                const rtDoubleCheckInfo *aInfo
// Return Type  : void
//
void rtNonNegativeError(const double aPositive, const rtDoubleCheckInfo *aInfo)
{
  fprintf(stderr,
          "Value %g is not greater than or equal to zero.\nExiting to prevent memory corruption.",
          aPositive);
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

//
// Arguments    : const int aDim1
//                const int aDim2
//                const rtEqualityCheckInfo *aInfo
// Return Type  : void
//
void rtSizeEq1DError(const int aDim1, const int aDim2, const rtEqualityCheckInfo
                     *aInfo)
{
  fprintf(stderr, "Sizes mismatch: %d ~= %d.", aDim1, aDim2);
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

//
// Arguments    : const int *aDims1
//                const int *aDims2
//                const rtEqualityCheckInfo *aInfo
// Return Type  : void
//
void rtSizeEqNDCheck(const int *aDims1, const int *aDims2, const
                     rtEqualityCheckInfo *aInfo)
{
  int i;
  char dims1Str[1024];
  char dims2Str[1024];
  for (i = 0; i < aInfo->nDims; i++) {
    if (aDims1[i] != aDims2[i]) {
      rtGenSizeString(aInfo->nDims, aDims1, dims1Str);
      rtGenSizeString(aInfo->nDims, aDims2, dims2Str);
      fprintf(stderr, "Sizes mismatch: %s ~= %s.", dims1Str, dims2Str);
      fprintf(stderr, "\n");
      if (aInfo != NULL) {
        rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
      }

      fflush(stderr);
      abort();
    }
  }
}

//
// File trailer for vsd_rtwutil.cpp
//
// [EOF]
//
