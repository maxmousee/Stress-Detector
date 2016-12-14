//
// File: pwchcore.h
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 13-Dec-2016 23:51:29
//
#ifndef PWCHCORE_H
#define PWCHCORE_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "vsd_types.h"

// Function Declarations
extern void b_pwchcore(const double x_data[], const int x_size[2], const double
  y_data[], const int y_size[2], int yoffset, const double s_data[], const int
  s_size[2], const double dx_data[], const int dx_size[2], const double
  divdif_data[], const int divdif_size[2], double pp_breaks_data[], int
  pp_breaks_size[2], emxArray_real_T *pp_coefs);
extern void pwchcore(const double x_data[], const int x_size[2], const double
                     y_data[], const int y_size[2], const double s[2], double
                     pp_breaks_data[], int pp_breaks_size[2], double pp_coefs[4]);

#endif

//
// File trailer for pwchcore.h
//
// [EOF]
//
