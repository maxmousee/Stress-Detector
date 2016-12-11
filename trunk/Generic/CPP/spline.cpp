/*
 * File: spline.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 06-Jun-2014 20:32:45
 */

/* Include files */
#include "processAudio.h"
#include "spline.h"
#include "processAudio_emxutil.h"
#include "pwchcore.h"

/* Function Declarations */
static void splinepp(const emxArray_real_T *x, const emxArray_real_T *y,
                     emxArray_real_T *pp_breaks, emxArray_real_T *pp_coefs);

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                emxArray_real_T *pp_breaks
 *                emxArray_real_T *pp_coefs
 * Return Type  : void
 */
static void splinepp(const emxArray_real_T *x, const emxArray_real_T *y,
                     emxArray_real_T *pp_breaks, emxArray_real_T *pp_coefs)
{
  boolean_T has_endslopes;
  emxArray_real_T *dx;
  double szdvdf[2];
  double t0_coefs[4];
  int i0;
  int k;
  emxArray_real_T *dvdf;
  emxArray_real_T *s;
  emxArray_real_T *md;
  emxArray_real_T *t1_breaks;
  emxArray_real_T *t1_coefs;
  double d31;
  double dnnm2;
  double c[3];
  int szs[2];
  int yoffset;
  double r;
  int cpage;
  has_endslopes = (y->size[1] == x->size[1] + 2);
  if (x->size[1] == 2) {
    if (has_endslopes) {
      emxInit_real_T(&dx, 2);
      szdvdf[0] = y->data[0];
      szdvdf[1] = y->data[y->size[1] - 1];
      pwchcore(x, y, szdvdf, dx, t0_coefs);
      i0 = pp_breaks->size[0] * pp_breaks->size[1];
      pp_breaks->size[0] = 1;
      pp_breaks->size[1] = dx->size[1];
      emxEnsureCapacity((emxArray__common *)pp_breaks, i0, (int)sizeof(double));
      k = dx->size[0] * dx->size[1];
      for (i0 = 0; i0 < k; i0++) {
        pp_breaks->data[i0] = dx->data[i0];
      }

      emxFree_real_T(&dx);
      i0 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 4;
      pp_coefs->size[2] = 1;
      emxEnsureCapacity((emxArray__common *)pp_coefs, i0, (int)sizeof(double));
      for (i0 = 0; i0 < 4; i0++) {
        pp_coefs->data[i0] = t0_coefs[i0];
      }
    } else {
      emxInit_real_T(&dx, 2);
      szdvdf[0] = (y->data[1] - y->data[0]) / (x->data[1] - x->data[0]);
      szdvdf[1] = y->data[0];
      i0 = dx->size[0] * dx->size[1];
      dx->size[0] = 1;
      dx->size[1] = 2;
      emxEnsureCapacity((emxArray__common *)dx, i0, (int)sizeof(double));
      for (i0 = 0; i0 < 2; i0++) {
        dx->data[dx->size[0] * i0] = x->data[i0];
      }

      i0 = pp_breaks->size[0] * pp_breaks->size[1];
      pp_breaks->size[0] = 1;
      pp_breaks->size[1] = dx->size[1];
      emxEnsureCapacity((emxArray__common *)pp_breaks, i0, (int)sizeof(double));
      k = dx->size[0] * dx->size[1];
      for (i0 = 0; i0 < k; i0++) {
        pp_breaks->data[i0] = dx->data[i0];
      }

      emxFree_real_T(&dx);
      i0 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 2;
      pp_coefs->size[2] = 1;
      emxEnsureCapacity((emxArray__common *)pp_coefs, i0, (int)sizeof(double));
      for (i0 = 0; i0 < 2; i0++) {
        pp_coefs->data[i0] = szdvdf[i0];
      }
    }
  } else {
    emxInit_real_T(&dx, 2);
    emxInit_real_T(&dvdf, 2);
    emxInit_real_T(&s, 2);
    emxInit_real_T(&md, 2);
    emxInit_real_T(&t1_breaks, 2);
    b_emxInit_real_T(&t1_coefs, 3);
    if ((x->size[1] == 3) && (!has_endslopes)) {
      d31 = x->data[1] - x->data[0];
      dnnm2 = (y->data[1] - y->data[0]) / d31;
      c[0] = ((y->data[2] - y->data[1]) / (x->data[2] - x->data[1]) - dnnm2) /
        (x->data[2] - x->data[0]);
      c[1] = dnnm2 - c[0] * d31;
      c[2] = y->data[0];
      szdvdf[0] = x->data[0];
      szdvdf[1] = x->data[2];
      i0 = pp_breaks->size[0] * pp_breaks->size[1];
      pp_breaks->size[0] = 1;
      pp_breaks->size[1] = 2;
      emxEnsureCapacity((emxArray__common *)pp_breaks, i0, (int)sizeof(double));
      for (i0 = 0; i0 < 2; i0++) {
        pp_breaks->data[pp_breaks->size[0] * i0] = szdvdf[i0];
      }

      i0 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 3;
      pp_coefs->size[2] = 1;
      emxEnsureCapacity((emxArray__common *)pp_coefs, i0, (int)sizeof(double));
      for (i0 = 0; i0 < 3; i0++) {
        pp_coefs->data[i0] = c[i0];
      }
    } else {
      if (has_endslopes) {
        szdvdf[1] = (double)y->size[1] - 3.0;
        szs[1] = y->size[1] - 2;
        yoffset = 1;
      } else {
        szdvdf[1] = (double)y->size[1] - 1.0;
        for (i0 = 0; i0 < 2; i0++) {
          szs[i0] = y->size[i0];
        }

        yoffset = 0;
      }

      if (1 > x->size[1] - 1) {
        i0 = 1;
      } else {
        i0 = x->size[1];
      }

      k = dx->size[0] * dx->size[1];
      dx->size[0] = 1;
      dx->size[1] = i0 - 1;
      emxEnsureCapacity((emxArray__common *)dx, k, (int)sizeof(double));
      i0 = dvdf->size[0] * dvdf->size[1];
      dvdf->size[0] = 1;
      dvdf->size[1] = (int)szdvdf[1];
      emxEnsureCapacity((emxArray__common *)dvdf, i0, (int)sizeof(double));
      i0 = s->size[0] * s->size[1];
      s->size[0] = 1;
      s->size[1] = szs[1];
      emxEnsureCapacity((emxArray__common *)s, i0, (int)sizeof(double));
      for (k = 0; k + 1 < x->size[1]; k++) {
        dx->data[k] = x->data[k + 1] - x->data[k];
        d31 = y->data[(yoffset + k) + 1] - y->data[yoffset + k];
        dvdf->data[k] = d31 / dx->data[k];
      }

      for (k = 1; k + 1 < x->size[1]; k++) {
        s->data[k] = 3.0 * (dx->data[k] * dvdf->data[k - 1] + dx->data[k - 1] *
                            dvdf->data[k]);
      }

      if (has_endslopes) {
        d31 = 0.0;
        dnnm2 = 0.0;
        s->data[0] = dx->data[1] * y->data[0];
        s->data[x->size[1] - 1] = dx->data[x->size[1] - 3] * y->data[x->size[1]
          + 1];
      } else {
        d31 = x->data[2] - x->data[0];
        dnnm2 = x->data[x->size[1] - 1] - x->data[x->size[1] - 3];
        s->data[0] = ((dx->data[0] + 2.0 * d31) * dx->data[1] * dvdf->data[0] +
                      dx->data[0] * dx->data[0] * dvdf->data[1]) / d31;
        s->data[x->size[1] - 1] = ((dx->data[x->size[1] - 2] + 2.0 * dnnm2) *
          dx->data[x->size[1] - 3] * dvdf->data[x->size[1] - 2] + dx->data
          [x->size[1] - 2] * dx->data[x->size[1] - 2] * dvdf->data[x->size[1] -
          3]) / dnnm2;
      }

      for (i0 = 0; i0 < 2; i0++) {
        k = md->size[0] * md->size[1];
        md->size[i0] = x->size[i0];
        emxEnsureCapacity((emxArray__common *)md, k, (int)sizeof(double));
      }

      md->data[0] = dx->data[1];
      md->data[x->size[1] - 1] = dx->data[x->size[1] - 3];
      for (k = 1; k + 1 < x->size[1]; k++) {
        md->data[k] = 2.0 * (dx->data[k] + dx->data[k - 1]);
      }

      r = dx->data[1] / md->data[0];
      md->data[1] -= r * d31;
      s->data[1] -= r * s->data[0];
      for (k = 2; k + 1 < x->size[1]; k++) {
        r = dx->data[k] / md->data[k - 1];
        md->data[k] -= r * dx->data[k - 2];
        s->data[k] -= r * s->data[k - 1];
      }

      r = dnnm2 / md->data[x->size[1] - 2];
      md->data[x->size[1] - 1] -= r * dx->data[x->size[1] - 3];
      s->data[x->size[1] - 1] -= r * s->data[x->size[1] - 2];
      s->data[x->size[1] - 1] /= md->data[x->size[1] - 1];
      for (k = x->size[1] - 2; k + 1 > 1; k--) {
        s->data[k] = (s->data[k] - dx->data[k - 1] * s->data[k + 1]) / md->
          data[k];
      }

      s->data[0] = (s->data[0] - d31 * s->data[1]) / md->data[0];
      k = x->size[1];
      i0 = t1_breaks->size[0] * t1_breaks->size[1];
      t1_breaks->size[0] = 1;
      t1_breaks->size[1] = k;
      emxEnsureCapacity((emxArray__common *)t1_breaks, i0, (int)sizeof(double));
      for (i0 = 0; i0 < k; i0++) {
        t1_breaks->data[t1_breaks->size[0] * i0] = x->data[i0];
      }

      cpage = x->size[1] - 1;
      i0 = t1_coefs->size[0] * t1_coefs->size[1] * t1_coefs->size[2];
      t1_coefs->size[0] = 1;
      t1_coefs->size[1] = x->size[1] - 1;
      t1_coefs->size[2] = 4;
      emxEnsureCapacity((emxArray__common *)t1_coefs, i0, (int)sizeof(double));
      for (k = 0; k + 1 < x->size[1]; k++) {
        d31 = dvdf->data[k] - s->data[k];
        dnnm2 = d31 / dx->data[k];
        d31 = s->data[k + 1] - dvdf->data[k];
        d31 /= dx->data[k];
        t1_coefs->data[k] = (d31 - dnnm2) / dx->data[k];
        t1_coefs->data[cpage + k] = 2.0 * dnnm2 - d31;
        t1_coefs->data[(cpage << 1) + k] = s->data[k];
        t1_coefs->data[3 * cpage + k] = y->data[yoffset + k];
      }

      i0 = pp_breaks->size[0] * pp_breaks->size[1];
      pp_breaks->size[0] = 1;
      pp_breaks->size[1] = t1_breaks->size[1];
      emxEnsureCapacity((emxArray__common *)pp_breaks, i0, (int)sizeof(double));
      k = t1_breaks->size[0] * t1_breaks->size[1];
      for (i0 = 0; i0 < k; i0++) {
        pp_breaks->data[i0] = t1_breaks->data[i0];
      }

      i0 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = t1_coefs->size[0];
      pp_coefs->size[1] = t1_coefs->size[1];
      pp_coefs->size[2] = 4;
      emxEnsureCapacity((emxArray__common *)pp_coefs, i0, (int)sizeof(double));
      k = t1_coefs->size[0] * t1_coefs->size[1] * t1_coefs->size[2];
      for (i0 = 0; i0 < k; i0++) {
        pp_coefs->data[i0] = t1_coefs->data[i0];
      }
    }

    emxFree_real_T(&t1_coefs);
    emxFree_real_T(&t1_breaks);
    emxFree_real_T(&md);
    emxFree_real_T(&s);
    emxFree_real_T(&dvdf);
    emxFree_real_T(&dx);
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                emxArray_real_T *output
 * Return Type  : void
 */
void spline(const emxArray_real_T *x, const emxArray_real_T *y, emxArray_real_T *
            output)
{
  emxArray_real_T *pp_breaks;
  emxArray_real_T *pp_coefs;
  int elementsPerPage;
  int coefStride;
  int low_ip1;
  int ix;
  int iv0;
  int low_i;
  int high_i;
  int ic0;
  int icp;
  double xloc;
  emxInit_real_T(&pp_breaks, 2);
  b_emxInit_real_T(&pp_coefs, 3);
  splinepp(x, y, pp_breaks, pp_coefs);
  elementsPerPage = pp_coefs->size[0];
  coefStride = elementsPerPage * (pp_breaks->size[1] - 1);
  low_ip1 = output->size[0] * output->size[1];
  output->size[0] = pp_coefs->size[0];
  output->size[1] = 8192;
  emxEnsureCapacity((emxArray__common *)output, low_ip1, (int)sizeof(double));
  for (ix = 0; ix < 8192; ix++) {
    iv0 = ix * elementsPerPage;
    low_i = 1;
    low_ip1 = 2;
    high_i = pp_breaks->size[1];
    while (high_i > low_ip1) {
      ic0 = (low_i >> 1) + (high_i >> 1);
      if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
        ic0++;
      }

      if (1.0 + (((double)ix + 1.0) - 1.0) >= pp_breaks->data[ic0 - 1]) {
        low_i = ic0;
        low_ip1 = ic0 + 1;
      } else {
        high_i = ic0;
      }
    }

    icp = (low_i - 1) * elementsPerPage;
    xloc = (1.0 + (((double)ix + 1.0) - 1.0)) - pp_breaks->data[low_i - 1];
    for (low_ip1 = 0; low_ip1 + 1 <= elementsPerPage; low_ip1++) {
      output->data[iv0 + low_ip1] = pp_coefs->data[icp + low_ip1];
    }

    for (high_i = 2; high_i <= pp_coefs->size[2]; high_i++) {
      ic0 = icp + (high_i - 1) * coefStride;
      for (low_ip1 = 0; low_ip1 + 1 <= elementsPerPage; low_ip1++) {
        output->data[iv0 + low_ip1] = xloc * output->data[iv0 + low_ip1] +
          pp_coefs->data[ic0 + low_ip1];
      }
    }
  }

  emxFree_real_T(&pp_coefs);
  emxFree_real_T(&pp_breaks);
}

/*
 * File trailer for spline.c
 *
 * [EOF]
 */
