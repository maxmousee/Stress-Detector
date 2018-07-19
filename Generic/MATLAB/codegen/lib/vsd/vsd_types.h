//
// File: vsd_types.h
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jul-2018 21:01:46
//
#ifndef VSD_TYPES_H
#define VSD_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
typedef struct {
  creal_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;

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
#endif

//
// File trailer for vsd_types.h
//
// [EOF]
//
