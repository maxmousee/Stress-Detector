/*
 * File: fft.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "fft.h"
#include "vsd_emxutil.h"
#include "fft1.h"

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                emxArray_creal_T *y
 * Return Type  : void
 */
void fft(const double x_data[], const int x_size[2], emxArray_creal_T *y)
{
  int b_size[2];
  int loop_ub;
  int i5;
  emxArray_creal_T *b_y1;
  int b_loop_ub;
  int i6;
  static double costab[8193];
  static double sintab[8193];
  double sintabinv[8193];
  double b_data[8000];
  short sz[2];
  b_size[0] = x_size[1];
  b_size[1] = x_size[0];
  loop_ub = x_size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    b_loop_ub = x_size[1];
    for (i6 = 0; i6 < b_loop_ub; i6++) {
      b_data[i6 + b_size[0] * i5] = x_data[i5 + x_size[0] * i6];
    }
  }

  emxInit_creal_T(&b_y1, 2);
  if ((x_size[1] == 0) || (x_size[0] == 0)) {
    for (i5 = 0; i5 < 2; i5++) {
      sz[i5] = (short)b_size[i5];
    }

    i5 = b_y1->size[0] * b_y1->size[1];
    b_y1->size[0] = 8000;
    b_y1->size[1] = sz[1];
    emxEnsureCapacity_creal_T(b_y1, i5);
    if (8000 > x_size[1]) {
      i5 = b_y1->size[0] * b_y1->size[1];
      b_y1->size[0] = 8000;
      emxEnsureCapacity_creal_T(b_y1, i5);
      loop_ub = b_y1->size[1];
      for (i5 = 0; i5 < loop_ub; i5++) {
        for (i6 = 0; i6 < 8000; i6++) {
          b_y1->data[i6 + b_y1->size[0] * i5].re = 0.0;
          b_y1->data[i6 + b_y1->size[0] * i5].im = 0.0;
        }
      }
    }
  } else {
    generate_twiddle_tables(costab, sintab, sintabinv);
    dobluesteinfft(b_data, b_size, costab, sintab, sintabinv, b_y1);
  }

  i5 = y->size[0] * y->size[1];
  y->size[0] = b_y1->size[1];
  y->size[1] = 8000;
  emxEnsureCapacity_creal_T(y, i5);
  for (i5 = 0; i5 < 8000; i5++) {
    loop_ub = b_y1->size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      y->data[i6 + y->size[0] * i5] = b_y1->data[i5 + b_y1->size[0] * i6];
    }
  }

  emxFree_creal_T(&b_y1);
}

/*
 * File trailer for fft.c
 *
 * [EOF]
 */
