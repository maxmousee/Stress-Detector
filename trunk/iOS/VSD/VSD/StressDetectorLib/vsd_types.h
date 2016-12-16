//
// File: vsd_types.h
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//
#ifndef VSD_TYPES_H
#define VSD_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray__common

#ifndef struct_emxArray_creal_T
#define struct_emxArray_creal_T

struct emxArray_creal_T
{
  creal_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_creal_T

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_real_T

typedef struct {
  int iFirst;
  int iLast;
  int lineNo;
  int colNo;
  const char * aName;
  const char * fName;
  const char * pName;
  int checkKind;
} rtBoundsCheckInfo;

typedef struct {
  int lineNo;
  int colNo;
  const char * fName;
  const char * pName;
  int checkKind;
} rtDoubleCheckInfo;

typedef struct {
  int nDims;
  int lineNo;
  int colNo;
  const char * fName;
  const char * pName;
} rtEqualityCheckInfo;

typedef struct {
  int lineNo;
  int colNo;
  const char * fName;
  const char * pName;
} rtRunTimeErrorInfo;

#endif

//
// File trailer for vsd_types.h
//
// [EOF]
//
