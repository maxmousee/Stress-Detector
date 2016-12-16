/*
 * File: spline.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 16-Dec-2016 08:11:00
 */

#ifndef SPLINE_H
#define SPLINE_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "vsd_types.h"

/* Function Declarations */
extern void splinepp(const double x_data[], const int x_size[2], const double
                     y_data[], const int y_size[2], double pp_breaks_data[], int
                     pp_breaks_size[2], emxArray_real_T *pp_coefs);

#endif

/*
 * File trailer for spline.h
 *
 * [EOF]
 */
