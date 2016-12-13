/*
 * pwchcore.c
 *
 * Code generation for function 'pwchcore'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "pwchcore.h"
#include "vsd_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo e_emlrtRTEI = { 1, 15, "pwchcore",
  "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchcore.m"
};

/* Function Definitions */
void b_pwchcore(const emlrtStack *sp, const real_T x_data[], const int32_T
                x_size[2], const real_T y_data[], int32_T yoffset, const real_T
                s_data[], const real_T dx_data[], const real_T divdif_data[],
                real_T pp_breaks_data[], int32_T pp_breaks_size[2],
                emxArray_real_T *pp_coefs)
{
  int32_T nx;
  int32_T nxm1;
  int32_T j;
  int32_T i11;
  real_T dzzdx;
  real_T dzdxdx;
  nx = x_size[1] - 1;
  nxm1 = x_size[1] - 1;
  pp_breaks_size[0] = 1;
  pp_breaks_size[1] = x_size[1];
  j = x_size[1];
  for (i11 = 0; i11 < j; i11++) {
    pp_breaks_data[pp_breaks_size[0] * i11] = x_data[i11];
  }

  i11 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
  pp_coefs->size[0] = 1;
  pp_coefs->size[1] = (int16_T)(x_size[1] - 1);
  pp_coefs->size[2] = 4;
  emxEnsureCapacity(sp, (emxArray__common *)pp_coefs, i11, (int32_T)sizeof
                    (real_T), &e_emlrtRTEI);
  for (j = 0; j + 1 <= nx; j++) {
    dzzdx = (divdif_data[j] - s_data[j]) / dx_data[j];
    dzdxdx = (s_data[j + 1] - divdif_data[j]) / dx_data[j];
    pp_coefs->data[j] = (dzdxdx - dzzdx) / dx_data[j];
    pp_coefs->data[nx + j] = 2.0 * dzzdx - dzdxdx;
    pp_coefs->data[(nxm1 << 1) + j] = s_data[j];
    pp_coefs->data[3 * nxm1 + j] = y_data[yoffset + j];
  }
}

void pwchcore(const real_T x_data[], const int32_T x_size[2], const real_T
              y_data[], const real_T s[2], real_T pp_breaks_data[], int32_T
              pp_breaks_size[2], real_T pp_coefs[4])
{
  int32_T j;
  int32_T i10;
  real_T dxj;
  real_T divdifij;
  real_T dzzdx;
  pp_breaks_size[0] = 1;
  pp_breaks_size[1] = x_size[1];
  j = x_size[1];
  for (i10 = 0; i10 < j; i10++) {
    pp_breaks_data[i10] = x_data[i10];
  }

  for (j = 1; j < x_size[1]; j++) {
    dxj = x_data[j] - x_data[j - 1];
    divdifij = (y_data[j + 1] - y_data[j]) / dxj;
    dzzdx = (divdifij - s[j - 1]) / dxj;
    divdifij = (s[1] - divdifij) / dxj;
    pp_coefs[j - 1] = (divdifij - dzzdx) / dxj;
    pp_coefs[j] = 2.0 * dzzdx - divdifij;
    pp_coefs[j + 1] = s[j - 1];
    pp_coefs[3] = y_data[j];
  }
}

/* End of code generation (pwchcore.c) */
