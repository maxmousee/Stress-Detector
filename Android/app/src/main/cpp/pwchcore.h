/*
 * File: pwchcore.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

#ifndef PWCHCORE_H
#define PWCHCORE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "vsd_types.h"

/* Function Declarations */
extern void b_pwchcore(const double x_data[], const int x_size[2], const double
  y_data[], int yoffset, const double s_data[], const double dx_data[], const
  double divdif_data[], double pp_breaks_data[], int pp_breaks_size[2],
  emxArray_real_T *pp_coefs);
extern void pwchcore(const double x_data[], const int x_size[2], const double
                     y_data[], const double s[2], double pp_breaks_data[], int
                     pp_breaks_size[2], double pp_coefs[4]);

#endif

/*
 * File trailer for pwchcore.h
 *
 * [EOF]
 */
