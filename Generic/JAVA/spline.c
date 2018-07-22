/*
 * File: spline.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "vsd.h"
#include "spline.h"
#include "vsd_emxutil.h"
#include "pwchcore.h"

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const double y_data[]
 *                const int y_size[2]
 *                double pp_breaks_data[]
 *                int pp_breaks_size[2]
 *                emxArray_real_T *pp_coefs
 * Return Type  : void
 */
void splinepp(const double x_data[], const int x_size[2], const double y_data[],
              const int y_size[2], double pp_breaks_data[], int pp_breaks_size[2],
              emxArray_real_T *pp_coefs)
{
  int nx;
  boolean_T has_endslopes;
  emxArray_real_T *t2_coefs;
  double c_data[2];
  int yoffset;
  double d31;
  int k;
  double dnnm2;
  static double s_data[8000];
  int t2_breaks_size[2];
  double t0_coefs[4];
  double b_c_data[3];
  double dx_data[7999];
  double dvdf_data[7999];
  static double md_data[8000];
  double r;
  static double t2_breaks_data[8000];
  nx = x_size[1] - 1;
  has_endslopes = (y_size[1] == x_size[1] + 2);
  if (x_size[1] <= 2) {
    if (has_endslopes) {
      c_data[0] = y_data[0];
      c_data[1] = y_data[y_size[1] - 1];
      pwchcore(x_data, x_size, y_data, c_data, s_data, t2_breaks_size, t0_coefs);
      pp_breaks_size[0] = 1;
      pp_breaks_size[1] = t2_breaks_size[1];
      nx = t2_breaks_size[0] * t2_breaks_size[1];
      if (0 <= nx - 1) {
        memcpy(&pp_breaks_data[0], &s_data[0], (unsigned int)(nx * (int)sizeof
                (double)));
      }

      yoffset = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 4;
      pp_coefs->size[2] = 1;
      emxEnsureCapacity_real_T(pp_coefs, yoffset);
      for (yoffset = 0; yoffset < 4; yoffset++) {
        pp_coefs->data[yoffset] = t0_coefs[yoffset];
      }
    } else {
      c_data[0] = (y_data[1] - y_data[0]) / (x_data[1] - x_data[0]);
      c_data[1] = y_data[0];
      nx = x_size[1];
      if (0 <= nx - 1) {
        memcpy(&s_data[0], &x_data[0], (unsigned int)(nx * (int)sizeof(double)));
      }

      pp_breaks_size[0] = 1;
      pp_breaks_size[1] = x_size[1];
      nx = x_size[1];
      if (0 <= nx - 1) {
        memcpy(&pp_breaks_data[0], &s_data[0], (unsigned int)(nx * (int)sizeof
                (double)));
      }

      yoffset = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 1;
      pp_coefs->size[2] = 2;
      emxEnsureCapacity_real_T(pp_coefs, yoffset);
      for (yoffset = 0; yoffset < 2; yoffset++) {
        pp_coefs->data[yoffset] = c_data[yoffset];
      }
    }
  } else {
    emxInit_real_T(&t2_coefs, 3);
    if ((x_size[1] == 3) && (!has_endslopes)) {
      d31 = x_data[1] - x_data[0];
      dnnm2 = (y_data[1] - y_data[0]) / d31;
      b_c_data[0] = ((y_data[2] - y_data[1]) / (x_data[2] - x_data[1]) - dnnm2) /
        (x_data[2] - x_data[0]);
      b_c_data[1] = dnnm2 - b_c_data[0] * d31;
      b_c_data[2] = y_data[0];
      c_data[0] = x_data[0];
      c_data[1] = x_data[2];
      pp_breaks_size[0] = 1;
      pp_breaks_size[1] = 2;
      for (yoffset = 0; yoffset < 2; yoffset++) {
        pp_breaks_data[pp_breaks_size[0] * yoffset] = c_data[yoffset];
      }

      yoffset = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 1;
      pp_coefs->size[2] = 3;
      emxEnsureCapacity_real_T(pp_coefs, yoffset);
      for (yoffset = 0; yoffset < 3; yoffset++) {
        pp_coefs->data[yoffset] = b_c_data[yoffset];
      }
    } else {
      yoffset = has_endslopes;
      for (k = 0; k < nx; k++) {
        dx_data[k] = x_data[k + 1] - x_data[k];
        dvdf_data[k] = (y_data[(yoffset + k) + 1] - y_data[yoffset + k]) /
          dx_data[k];
      }

      for (k = 1; k < nx; k++) {
        s_data[k] = 3.0 * (dx_data[k] * dvdf_data[k - 1] + dx_data[k - 1] *
                           dvdf_data[k]);
      }

      if (has_endslopes) {
        d31 = 0.0;
        dnnm2 = 0.0;
        s_data[0] = dx_data[1] * y_data[0];
        s_data[x_size[1] - 1] = dx_data[x_size[1] - 3] * y_data[x_size[1] + 1];
      } else {
        d31 = x_data[2] - x_data[0];
        dnnm2 = x_data[x_size[1] - 1] - x_data[x_size[1] - 3];
        s_data[0] = ((dx_data[0] + 2.0 * d31) * dx_data[1] * dvdf_data[0] +
                     dx_data[0] * dx_data[0] * dvdf_data[1]) / d31;
        s_data[x_size[1] - 1] = ((dx_data[x_size[1] - 2] + 2.0 * dnnm2) *
          dx_data[x_size[1] - 3] * dvdf_data[x_size[1] - 2] + dx_data[x_size[1]
          - 2] * dx_data[x_size[1] - 2] * dvdf_data[x_size[1] - 3]) / dnnm2;
      }

      md_data[0] = dx_data[1];
      md_data[x_size[1] - 1] = dx_data[x_size[1] - 3];
      for (k = 1; k < nx; k++) {
        md_data[k] = 2.0 * (dx_data[k] + dx_data[k - 1]);
      }

      r = dx_data[1] / md_data[0];
      md_data[1] -= r * d31;
      s_data[1] -= r * s_data[0];
      for (k = 2; k < nx; k++) {
        r = dx_data[k] / md_data[k - 1];
        md_data[k] -= r * dx_data[k - 2];
        s_data[k] -= r * s_data[k - 1];
      }

      r = dnnm2 / md_data[x_size[1] - 2];
      md_data[x_size[1] - 1] -= r * dx_data[x_size[1] - 3];
      s_data[x_size[1] - 1] -= r * s_data[x_size[1] - 2];
      s_data[x_size[1] - 1] /= md_data[x_size[1] - 1];
      for (k = x_size[1] - 2; k + 1 > 1; k--) {
        s_data[k] = (s_data[k] - dx_data[k - 1] * s_data[k + 1]) / md_data[k];
      }

      s_data[0] = (s_data[0] - d31 * s_data[1]) / md_data[0];
      b_pwchcore(x_data, x_size, y_data, yoffset, s_data, dx_data, dvdf_data,
                 t2_breaks_data, t2_breaks_size, t2_coefs);
      pp_breaks_size[0] = 1;
      pp_breaks_size[1] = t2_breaks_size[1];
      nx = t2_breaks_size[0] * t2_breaks_size[1];
      if (0 <= nx - 1) {
        memcpy(&pp_breaks_data[0], &t2_breaks_data[0], (unsigned int)(nx * (int)
                sizeof(double)));
      }

      yoffset = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = t2_coefs->size[1];
      pp_coefs->size[2] = 4;
      emxEnsureCapacity_real_T(pp_coefs, yoffset);
      nx = t2_coefs->size[0] * t2_coefs->size[1] * t2_coefs->size[2];
      for (yoffset = 0; yoffset < nx; yoffset++) {
        pp_coefs->data[yoffset] = t2_coefs->data[yoffset];
      }
    }

    emxFree_real_T(&t2_coefs);
  }
}

/*
 * File trailer for spline.c
 *
 * [EOF]
 */
