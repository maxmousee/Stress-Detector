//
// File: spline.h
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 21-Dec-2016 23:54:03
//
#ifndef SPLINE_H
#define SPLINE_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "vsd_types.h"

// Function Declarations
extern void splinepp(const emxArray_real_T *x, const emxArray_real_T *y,
                     emxArray_real_T *pp_breaks, emxArray_real_T *pp_coefs);

#endif

//
// File trailer for spline.h
//
// [EOF]
//
