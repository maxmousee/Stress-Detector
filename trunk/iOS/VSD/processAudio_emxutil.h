/*
 * File: processAudio_emxutil.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 06-Jun-2014 20:32:45
 */

#ifndef __PROCESSAUDIO_EMXUTIL_H__
#define __PROCESSAUDIO_EMXUTIL_H__

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "processAudio_types.h"

/* Function Declarations */
extern void b_emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, int
  elementSize);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for processAudio_emxutil.h
 *
 * [EOF]
 */
