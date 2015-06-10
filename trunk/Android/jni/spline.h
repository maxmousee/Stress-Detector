/*
 * File: spline.h
 *
 * MATLAB Coder version            : 2.7
 * C/C++ source code generated on  : 26-May-2015 20:44:52
 */

#ifndef __SPLINE_H__
#define __SPLINE_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "processAudio_types.h"

/* Function Declarations */
extern void spline(const double x_data[], const int x_size[2], const double
                   y_data[], double output_data[], int output_size[2]);

#endif

/*
 * File trailer for spline.h
 *
 * [EOF]
 */
