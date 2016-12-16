/*
 * File: vsd.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 16-Dec-2016 08:11:00
 */

#ifndef VSD_H
#define VSD_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "vsd_types.h"
#include <jni.h>

/* Function Declarations */
//extern double vsd(const double input[8000]);
JNIEXPORT jdouble JNICALL Java_com_nfsindustries_vsd_Realtime_vsd(JNIEnv *, jobject, jdoubleArray jInput);

#endif

/*
 * File trailer for vsd.h
 *
 * [EOF]
 */
