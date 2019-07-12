/*
 * File: vsd_emxutil.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

#ifndef VSD_EMXUTIL_H
#define VSD_EMXUTIL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "vsd_types.h"

/* Function Declarations */
extern void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxFree_creal_T(emxArray_creal_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_creal_T(emxArray_creal_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for vsd_emxutil.h
 *
 * [EOF]
 */
