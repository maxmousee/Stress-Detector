//
// File: spline.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 21-Dec-2016 23:54:03
//

// Include Files
#include "rt_nonfinite.h"
#include "vsd.h"
#include "spline.h"
#include "vsd_emxutil.h"
#include "pwchcore.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *x
//                const emxArray_real_T *y
//                emxArray_real_T *pp_breaks
//                emxArray_real_T *pp_coefs
// Return Type  : void
//
void splinepp(const emxArray_real_T *x, const emxArray_real_T *y,
              emxArray_real_T *pp_breaks, emxArray_real_T *pp_coefs)
{
  int nx;
  boolean_T has_endslopes;
  emxArray_real_T *s;
  emxArray_real_T *md;
  emxArray_real_T *t0_breaks;
  double c_data[2];
  emxArray_real_T *t0_coefs;
  int k;
  double t2_coefs[4];
  double d31;
  int i5;
  short szs[2];
  double dnnm2;
  int yoffset;
  double b_c_data[3];
  double dx_data[8191];
  double dvdf_data[8191];
  double r;
  nx = x->size[1] - 1;
  has_endslopes = (y->size[1] == x->size[1] + 2);
  if (x->size[1] <= 2) {
    if (has_endslopes) {
      emxInit_real_T(&s, 2);
      c_data[0] = y->data[0];
      c_data[1] = y->data[y->size[1] - 1];
      pwchcore(x, y, c_data, s, t2_coefs);
      i5 = pp_breaks->size[0] * pp_breaks->size[1];
      pp_breaks->size[0] = 1;
      pp_breaks->size[1] = s->size[1];
      emxEnsureCapacity((emxArray__common *)pp_breaks, i5, (int)sizeof(double));
      k = s->size[0] * s->size[1];
      for (i5 = 0; i5 < k; i5++) {
        pp_breaks->data[i5] = s->data[i5];
      }

      emxFree_real_T(&s);
      i5 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 4;
      pp_coefs->size[2] = 1;
      emxEnsureCapacity((emxArray__common *)pp_coefs, i5, (int)sizeof(double));
      for (i5 = 0; i5 < 4; i5++) {
        pp_coefs->data[i5] = t2_coefs[i5];
      }
    } else {
      emxInit_real_T(&s, 2);
      c_data[0] = (y->data[1] - y->data[0]) / (x->data[1] - x->data[0]);
      c_data[1] = y->data[0];
      k = x->size[1];
      i5 = s->size[0] * s->size[1];
      s->size[0] = 1;
      s->size[1] = k;
      emxEnsureCapacity((emxArray__common *)s, i5, (int)sizeof(double));
      for (i5 = 0; i5 < k; i5++) {
        s->data[s->size[0] * i5] = x->data[i5];
      }

      i5 = pp_breaks->size[0] * pp_breaks->size[1];
      pp_breaks->size[0] = 1;
      pp_breaks->size[1] = s->size[1];
      emxEnsureCapacity((emxArray__common *)pp_breaks, i5, (int)sizeof(double));
      k = s->size[0] * s->size[1];
      for (i5 = 0; i5 < k; i5++) {
        pp_breaks->data[i5] = s->data[i5];
      }

      emxFree_real_T(&s);
      i5 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 1;
      pp_coefs->size[2] = 2;
      emxEnsureCapacity((emxArray__common *)pp_coefs, i5, (int)sizeof(double));
      for (i5 = 0; i5 < 2; i5++) {
        pp_coefs->data[i5] = c_data[i5];
      }
    }
  } else {
    emxInit_real_T(&s, 2);
    emxInit_real_T(&md, 2);
    emxInit_real_T(&t0_breaks, 2);
    emxInit_real_T1(&t0_coefs, 3);
    if ((x->size[1] == 3) && (!has_endslopes)) {
      d31 = x->data[1] - x->data[0];
      dnnm2 = (y->data[1] - y->data[0]) / d31;
      b_c_data[0] = ((y->data[2] - y->data[1]) / (x->data[2] - x->data[1]) -
                     dnnm2) / (x->data[2] - x->data[0]);
      b_c_data[1] = dnnm2 - b_c_data[0] * d31;
      b_c_data[2] = y->data[0];
      c_data[0] = x->data[0];
      c_data[1] = x->data[2];
      i5 = pp_breaks->size[0] * pp_breaks->size[1];
      pp_breaks->size[0] = 1;
      pp_breaks->size[1] = 2;
      emxEnsureCapacity((emxArray__common *)pp_breaks, i5, (int)sizeof(double));
      for (i5 = 0; i5 < 2; i5++) {
        pp_breaks->data[pp_breaks->size[0] * i5] = c_data[i5];
      }

      i5 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 1;
      pp_coefs->size[2] = 3;
      emxEnsureCapacity((emxArray__common *)pp_coefs, i5, (int)sizeof(double));
      for (i5 = 0; i5 < 3; i5++) {
        pp_coefs->data[i5] = b_c_data[i5];
      }
    } else {
      if (has_endslopes) {
        szs[1] = (short)(y->size[1] - 2);
        yoffset = 1;
      } else {
        for (i5 = 0; i5 < 2; i5++) {
          szs[i5] = (short)y->size[i5];
        }

        yoffset = 0;
      }

      i5 = s->size[0] * s->size[1];
      s->size[0] = 1;
      s->size[1] = szs[1];
      emxEnsureCapacity((emxArray__common *)s, i5, (int)sizeof(double));
      for (k = 0; k + 1 <= nx; k++) {
        dx_data[k] = x->data[k + 1] - x->data[k];
        d31 = y->data[(yoffset + k) + 1] - y->data[yoffset + k];
        dvdf_data[k] = d31 / dx_data[k];
      }

      for (k = 1; k + 1 <= nx; k++) {
        s->data[k] = 3.0 * (dx_data[k] * dvdf_data[k - 1] + dx_data[k - 1] *
                            dvdf_data[k]);
      }

      if (has_endslopes) {
        d31 = 0.0;
        dnnm2 = 0.0;
        s->data[0] = dx_data[1] * y->data[0];
        s->data[x->size[1] - 1] = dx_data[x->size[1] - 3] * y->data[x->size[1] +
          1];
      } else {
        d31 = x->data[2] - x->data[0];
        dnnm2 = x->data[x->size[1] - 1] - x->data[x->size[1] - 3];
        s->data[0] = ((dx_data[0] + 2.0 * d31) * dx_data[1] * dvdf_data[0] +
                      dx_data[0] * dx_data[0] * dvdf_data[1]) / d31;
        s->data[x->size[1] - 1] = ((dx_data[x->size[1] - 2] + 2.0 * dnnm2) *
          dx_data[x->size[1] - 3] * dvdf_data[x->size[1] - 2] + dx_data[x->size
          [1] - 2] * dx_data[x->size[1] - 2] * dvdf_data[x->size[1] - 3]) /
          dnnm2;
      }

      for (i5 = 0; i5 < 2; i5++) {
        k = md->size[0] * md->size[1];
        md->size[i5] = x->size[i5];
        emxEnsureCapacity((emxArray__common *)md, k, (int)sizeof(double));
      }

      md->data[0] = dx_data[1];
      md->data[x->size[1] - 1] = dx_data[x->size[1] - 3];
      for (k = 1; k + 1 <= nx; k++) {
        md->data[k] = 2.0 * (dx_data[k] + dx_data[k - 1]);
      }

      r = dx_data[1] / md->data[0];
      md->data[1] -= r * d31;
      s->data[1] -= r * s->data[0];
      for (k = 2; k + 1 <= nx; k++) {
        r = dx_data[k] / md->data[k - 1];
        md->data[k] -= r * dx_data[k - 2];
        s->data[k] -= r * s->data[k - 1];
      }

      r = dnnm2 / md->data[x->size[1] - 2];
      md->data[x->size[1] - 1] -= r * dx_data[x->size[1] - 3];
      s->data[x->size[1] - 1] -= r * s->data[x->size[1] - 2];
      s->data[x->size[1] - 1] /= md->data[x->size[1] - 1];
      for (k = x->size[1] - 2; k + 1 > 1; k--) {
        s->data[k] = (s->data[k] - dx_data[k - 1] * s->data[k + 1]) / md->data[k];
      }

      s->data[0] = (s->data[0] - d31 * s->data[1]) / md->data[0];
      b_pwchcore(x, y, yoffset, s, dx_data, dvdf_data, t0_breaks, t0_coefs);
      i5 = pp_breaks->size[0] * pp_breaks->size[1];
      pp_breaks->size[0] = 1;
      pp_breaks->size[1] = t0_breaks->size[1];
      emxEnsureCapacity((emxArray__common *)pp_breaks, i5, (int)sizeof(double));
      k = t0_breaks->size[0] * t0_breaks->size[1];
      for (i5 = 0; i5 < k; i5++) {
        pp_breaks->data[i5] = t0_breaks->data[i5];
      }

      i5 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = t0_coefs->size[1];
      pp_coefs->size[2] = 4;
      emxEnsureCapacity((emxArray__common *)pp_coefs, i5, (int)sizeof(double));
      k = t0_coefs->size[0] * t0_coefs->size[1] * t0_coefs->size[2];
      for (i5 = 0; i5 < k; i5++) {
        pp_coefs->data[i5] = t0_coefs->data[i5];
      }
    }

    emxFree_real_T(&t0_coefs);
    emxFree_real_T(&t0_breaks);
    emxFree_real_T(&md);
    emxFree_real_T(&s);
  }
}

//
// File trailer for spline.cpp
//
// [EOF]
//
