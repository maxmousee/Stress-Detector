/*
 * spline.c
 *
 * Code generation for function 'spline'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "spline.h"
#include "vsd_emxutil.h"
#include "pwchcore.h"
#include "chckxy.h"
#include "ppval.h"

/* Variable Definitions */
static emlrtRSInfo q_emlrtRSI = { 20, "spline",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\spline.m"
};

static emlrtRSInfo r_emlrtRSI = { 33, "spline",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\spline.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 1, 19, "spline",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\spline.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 32, 15, "spline",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\spline.m"
};

static emlrtDCInfo b_emlrtDCI = { 99, 33, "spline",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\spline.m",
  4 };

/* Function Declarations */
static void splinepp(vsdStackData *SD, const emlrtStack *sp, const real_T
                     x_data[], const int32_T x_size[2], const real_T y_data[],
                     const int32_T y_size[2], real_T pp_breaks_data[], int32_T
                     pp_breaks_size[2], emxArray_real_T *pp_coefs);

/* Function Definitions */
static void splinepp(vsdStackData *SD, const emlrtStack *sp, const real_T
                     x_data[], const int32_T x_size[2], const real_T y_data[],
                     const int32_T y_size[2], real_T pp_breaks_data[], int32_T
                     pp_breaks_size[2], emxArray_real_T *pp_coefs)
{
  int32_T nx;
  boolean_T has_endslopes;
  emxArray_real_T *t0_coefs;
  real_T szdvdf[2];
  real_T d31;
  real_T dnnm2;
  int32_T k;
  int32_T t0_breaks_size[2];
  real_T t2_coefs[4];
  int32_T i9;
  real_T c_data[3];
  int32_T yoffset;
  real_T dx_data[7999];
  real_T dvdf_data[7999];
  real_T r;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &r_emlrtRSI;
  chckxy(&st, x_data, x_size, y_data, y_size);
  nx = x_size[1] - 1;
  has_endslopes = (y_size[1] == x_size[1] + 2);
  if (x_size[1] <= 2) {
    if (has_endslopes) {
      szdvdf[0] = y_data[0];
      szdvdf[1] = y_data[y_size[1] - 1];
      pwchcore(x_data, x_size, y_data, szdvdf, SD->u1.f0.s_data, t0_breaks_size,
               t2_coefs);
      pp_breaks_size[0] = 1;
      pp_breaks_size[1] = t0_breaks_size[1];
      k = t0_breaks_size[0] * t0_breaks_size[1];
      for (i9 = 0; i9 < k; i9++) {
        pp_breaks_data[i9] = SD->u1.f0.s_data[i9];
      }

      i9 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 4;
      pp_coefs->size[2] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)pp_coefs, i9, (int32_T)sizeof
                        (real_T), &d_emlrtRTEI);
      for (i9 = 0; i9 < 4; i9++) {
        pp_coefs->data[i9] = t2_coefs[i9];
      }
    } else {
      szdvdf[0] = (y_data[1] - y_data[0]) / (x_data[1] - x_data[0]);
      szdvdf[1] = y_data[0];
      k = x_size[1];
      for (i9 = 0; i9 < k; i9++) {
        SD->u1.f0.s_data[i9] = x_data[i9];
      }

      pp_breaks_size[0] = 1;
      pp_breaks_size[1] = x_size[1];
      k = x_size[1];
      for (i9 = 0; i9 < k; i9++) {
        pp_breaks_data[i9] = SD->u1.f0.s_data[i9];
      }

      i9 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 1;
      pp_coefs->size[2] = 2;
      emxEnsureCapacity(sp, (emxArray__common *)pp_coefs, i9, (int32_T)sizeof
                        (real_T), &d_emlrtRTEI);
      for (i9 = 0; i9 < 2; i9++) {
        pp_coefs->data[i9] = szdvdf[i9];
      }
    }
  } else {
    emxInit_real_T1(sp, &t0_coefs, 3, &d_emlrtRTEI, true);
    if ((x_size[1] == 3) && (!has_endslopes)) {
      d31 = x_data[1] - x_data[0];
      dnnm2 = (y_data[1] - y_data[0]) / d31;
      c_data[0] = ((y_data[2] - y_data[1]) / (x_data[2] - x_data[1]) - dnnm2) /
        (x_data[2] - x_data[0]);
      c_data[1] = dnnm2 - c_data[0] * d31;
      c_data[2] = y_data[0];
      szdvdf[0] = x_data[0];
      szdvdf[1] = x_data[2];
      pp_breaks_size[0] = 1;
      pp_breaks_size[1] = 2;
      for (i9 = 0; i9 < 2; i9++) {
        pp_breaks_data[pp_breaks_size[0] * i9] = szdvdf[i9];
      }

      i9 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = 1;
      pp_coefs->size[2] = 3;
      emxEnsureCapacity(sp, (emxArray__common *)pp_coefs, i9, (int32_T)sizeof
                        (real_T), &d_emlrtRTEI);
      for (i9 = 0; i9 < 3; i9++) {
        pp_coefs->data[i9] = c_data[i9];
      }
    } else {
      if (has_endslopes) {
        for (i9 = 0; i9 < 2; i9++) {
          szdvdf[i9] = y_size[i9];
        }

        szdvdf[1] = (real_T)y_size[1] - 3.0;
        yoffset = 1;
      } else {
        for (i9 = 0; i9 < 2; i9++) {
          szdvdf[i9] = y_size[i9];
        }

        szdvdf[1] = (real_T)y_size[1] - 1.0;
        yoffset = 0;
      }

      for (i9 = 0; i9 < 2; i9++) {
        if (!(szdvdf[i9] >= 0.0)) {
          emlrtNonNegativeCheckR2012b(szdvdf[i9], &b_emlrtDCI, sp);
        }
      }

      for (k = 0; k + 1 <= nx; k++) {
        dx_data[k] = x_data[k + 1] - x_data[k];
        dvdf_data[k] = (y_data[(yoffset + k) + 1] - y_data[yoffset + k]) /
          dx_data[k];
      }

      for (k = 1; k + 1 <= nx; k++) {
        SD->u1.f0.s_data[k] = 3.0 * (dx_data[k] * dvdf_data[k - 1] + dx_data[k -
          1] * dvdf_data[k]);
      }

      if (has_endslopes) {
        d31 = 0.0;
        dnnm2 = 0.0;
        SD->u1.f0.s_data[0] = dx_data[1] * y_data[0];
        SD->u1.f0.s_data[x_size[1] - 1] = dx_data[x_size[1] - 3] *
          y_data[x_size[1] + 1];
      } else {
        d31 = x_data[2] - x_data[0];
        dnnm2 = x_data[x_size[1] - 1] - x_data[x_size[1] - 3];
        SD->u1.f0.s_data[0] = ((dx_data[0] + 2.0 * d31) * dx_data[1] *
          dvdf_data[0] + dx_data[0] * dx_data[0] * dvdf_data[1]) / d31;
        SD->u1.f0.s_data[x_size[1] - 1] = ((dx_data[x_size[1] - 2] + 2.0 * dnnm2)
          * dx_data[x_size[1] - 3] * dvdf_data[x_size[1] - 2] + dx_data[x_size[1]
          - 2] * dx_data[x_size[1] - 2] * dvdf_data[x_size[1] - 3]) / dnnm2;
      }

      SD->u1.f0.md_data[0] = dx_data[1];
      SD->u1.f0.md_data[x_size[1] - 1] = dx_data[x_size[1] - 3];
      for (k = 1; k + 1 <= nx; k++) {
        SD->u1.f0.md_data[k] = 2.0 * (dx_data[k] + dx_data[k - 1]);
      }

      r = dx_data[1] / SD->u1.f0.md_data[0];
      SD->u1.f0.md_data[1] -= r * d31;
      SD->u1.f0.s_data[1] -= r * SD->u1.f0.s_data[0];
      for (k = 2; k + 1 <= nx; k++) {
        r = dx_data[k] / SD->u1.f0.md_data[k - 1];
        SD->u1.f0.md_data[k] -= r * dx_data[k - 2];
        SD->u1.f0.s_data[k] -= r * SD->u1.f0.s_data[k - 1];
      }

      r = dnnm2 / SD->u1.f0.md_data[x_size[1] - 2];
      SD->u1.f0.md_data[x_size[1] - 1] -= r * dx_data[x_size[1] - 3];
      SD->u1.f0.s_data[x_size[1] - 1] -= r * SD->u1.f0.s_data[x_size[1] - 2];
      SD->u1.f0.s_data[x_size[1] - 1] /= SD->u1.f0.md_data[x_size[1] - 1];
      for (k = x_size[1] - 2; k + 1 > 1; k--) {
        SD->u1.f0.s_data[k] = (SD->u1.f0.s_data[k] - dx_data[k - 1] *
          SD->u1.f0.s_data[k + 1]) / SD->u1.f0.md_data[k];
      }

      SD->u1.f0.s_data[0] = (SD->u1.f0.s_data[0] - d31 * SD->u1.f0.s_data[1]) /
        SD->u1.f0.md_data[0];
      b_pwchcore(sp, x_data, x_size, y_data, yoffset, SD->u1.f0.s_data, dx_data,
                 dvdf_data, SD->u1.f0.t0_breaks_data, t0_breaks_size, t0_coefs);
      pp_breaks_size[0] = 1;
      pp_breaks_size[1] = t0_breaks_size[1];
      k = t0_breaks_size[0] * t0_breaks_size[1];
      for (i9 = 0; i9 < k; i9++) {
        pp_breaks_data[i9] = SD->u1.f0.t0_breaks_data[i9];
      }

      i9 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
      pp_coefs->size[0] = 1;
      pp_coefs->size[1] = t0_coefs->size[1];
      pp_coefs->size[2] = 4;
      emxEnsureCapacity(sp, (emxArray__common *)pp_coefs, i9, (int32_T)sizeof
                        (real_T), &d_emlrtRTEI);
      k = t0_coefs->size[0] * t0_coefs->size[1] * t0_coefs->size[2];
      for (i9 = 0; i9 < k; i9++) {
        pp_coefs->data[i9] = t0_coefs->data[i9];
      }
    }

    emxFree_real_T(&t0_coefs);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void spline(vsdStackData *SD, const emlrtStack *sp, const real_T x_data[], const
            int32_T x_size[2], const real_T y_data[], const int32_T y_size[2],
            real_T output_data[], int32_T output_size[2])
{
  emxArray_real_T *pp_coefs;
  int32_T pp_breaks_size[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &pp_coefs, 3, &c_emlrtRTEI, true);
  st.site = &q_emlrtRSI;
  splinepp(SD, &st, x_data, x_size, y_data, y_size, SD->u2.f2.pp_breaks_data,
           pp_breaks_size, pp_coefs);
  ppval(SD->u2.f2.pp_breaks_data, pp_breaks_size, pp_coefs, output_data,
        output_size);
  emxFree_real_T(&pp_coefs);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (spline.c) */
