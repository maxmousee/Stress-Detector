/*
 * File: fft1.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

#ifndef FFT1_H
#define FFT1_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "vsd_types.h"

/* Function Declarations */
extern void dobluesteinfft(const double x_data[], const int x_size[2], const
  double costab[8193], const double sintab[8193], const double sintabinv[8193],
  emxArray_creal_T *y);
extern void generate_twiddle_tables(double costab[8193], double sintab[8193],
  double sintabinv[8193]);

#endif

/*
 * File trailer for fft1.h
 *
 * [EOF]
 */
