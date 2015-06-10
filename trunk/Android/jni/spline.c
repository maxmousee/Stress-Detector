/*
 * File: spline.c
 *
 * MATLAB Coder version            : 2.7
 * C/C++ source code generated on  : 26-May-2015 20:44:52
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "processAudio.h"
#include "spline.h"
#include "bsearch.h"

/* Function Declarations */
static void splinepp(const double x_data[], const int x_size[2], const double
                     y_data[], double pp_breaks_data[], int pp_breaks_size[2],
                     double pp_coefs_data[], int pp_coefs_size[3]);

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const double y_data[]
 *                double pp_breaks_data[]
 *                int pp_breaks_size[2]
 *                double pp_coefs_data[]
 *                int pp_coefs_size[3]
 * Return Type  : void
 */
static void splinepp(const double x_data[], const int x_size[2], const double
                     y_data[], double pp_breaks_data[], int pp_breaks_size[2],
                     double pp_coefs_data[], int pp_coefs_size[3])
{
  double c[2];
  int i0;
  double b_c[3];
  double d21;
  double dvdf1;
  if (x_size[1] == 2) {
    c[0] = (y_data[1] - y_data[0]) / (x_data[1] - x_data[0]);
    c[1] = y_data[0];
    for (i0 = 0; i0 < 2; i0++) {
      b_c[i0] = x_data[i0];
    }

    pp_breaks_size[0] = 1;
    pp_breaks_size[1] = 2;
    for (i0 = 0; i0 < 2; i0++) {
      pp_breaks_data[i0] = b_c[i0];
    }

    pp_coefs_size[0] = 1;
    pp_coefs_size[1] = 2;
    pp_coefs_size[2] = 1;
    for (i0 = 0; i0 < 2; i0++) {
      pp_coefs_data[i0] = c[i0];
    }
  } else {
    d21 = x_data[1] - x_data[0];
    dvdf1 = (y_data[1] - y_data[0]) / d21;
    b_c[0] = ((y_data[2] - y_data[1]) / (x_data[2] - x_data[1]) - dvdf1) /
      (x_data[2] - x_data[0]);
    b_c[1] = dvdf1 - b_c[0] * d21;
    b_c[2] = y_data[0];
    c[0] = x_data[0];
    c[1] = x_data[2];
    pp_breaks_size[0] = 1;
    pp_breaks_size[1] = 2;
    for (i0 = 0; i0 < 2; i0++) {
      pp_breaks_data[i0] = c[i0];
    }

    pp_coefs_size[0] = 1;
    pp_coefs_size[1] = 3;
    pp_coefs_size[2] = 1;
    for (i0 = 0; i0 < 3; i0++) {
      pp_coefs_data[i0] = b_c[i0];
    }
  }
}

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const double y_data[]
 *                double output_data[]
 *                int output_size[2]
 * Return Type  : void
 */
void spline(const double x_data[], const int x_size[2], const double y_data[],
            double output_data[], int output_size[2])
{
  int pp_coefs_size[3];
  double pp_coefs_data[16];
  int pp_breaks_size[2];
  double pp_breaks_data[3];
  int ix;
  static const short iv0[2] = { 1, 8000 };

  int ip;
  double xloc;
  int ic;
  splinepp(x_data, x_size, y_data, pp_breaks_data, pp_breaks_size, pp_coefs_data,
           pp_coefs_size);
  for (ix = 0; ix < 2; ix++) {
    output_size[ix] = iv0[ix];
  }

  for (ix = 0; ix < 8000; ix++) {
    ip = b_bsearch(pp_breaks_data, pp_breaks_size, 1.0 + (((double)ix + 1.0) -
      1.0)) - 1;
    xloc = (1.0 + (((double)ix + 1.0) - 1.0)) - pp_breaks_data[ip];
    output_data[ix] = pp_coefs_data[ip];
    for (ic = 2; ic <= pp_coefs_size[2]; ic++) {
      output_data[ix] = xloc * output_data[ix] + pp_coefs_data[ip + (ic - 1) *
        (pp_breaks_size[1] - 1)];
    }
  }
}

/*
 * File trailer for spline.c
 *
 * [EOF]
 */
