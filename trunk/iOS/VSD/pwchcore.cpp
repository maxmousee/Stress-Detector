/*
 * File: pwchcore.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 16-Dec-2016 20:24:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "pwchcore.h"
#include "vsd_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                int yoffset
 *                const emxArray_real_T *s
 *                const double dx_data[]
 *                const double divdif_data[]
 *                emxArray_real_T *pp_breaks
 *                emxArray_real_T *pp_coefs
 * Return Type  : void
 */
void b_pwchcore(const emxArray_real_T *x, const emxArray_real_T *y, int yoffset,
                const emxArray_real_T *s, const double dx_data[], const double
                divdif_data[], emxArray_real_T *pp_breaks, emxArray_real_T
                *pp_coefs)
{
  int nx;
  int nxm1;
  int x_idx_0;
  int i8;
  short szc_idx_1;
  double dzzdx;
  double dzdxdx;
  nx = x->size[1] - 1;
  nxm1 = x->size[1] - 1;
  x_idx_0 = x->size[1];
  i8 = pp_breaks->size[0] * pp_breaks->size[1];
  pp_breaks->size[0] = 1;
  pp_breaks->size[1] = x_idx_0;
  emxEnsureCapacity((emxArray__common *)pp_breaks, i8, (int)sizeof(double));
  for (i8 = 0; i8 < x_idx_0; i8++) {
    pp_breaks->data[pp_breaks->size[0] * i8] = x->data[i8];
  }

  szc_idx_1 = (short)(x->size[1] - 1);
  i8 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
  pp_coefs->size[0] = 1;
  pp_coefs->size[1] = szc_idx_1;
  pp_coefs->size[2] = 4;
  emxEnsureCapacity((emxArray__common *)pp_coefs, i8, (int)sizeof(double));
  for (x_idx_0 = 0; x_idx_0 + 1 <= nx; x_idx_0++) {
    dzzdx = (divdif_data[x_idx_0] - s->data[x_idx_0]) / dx_data[x_idx_0];
    dzdxdx = (s->data[x_idx_0 + 1] - divdif_data[x_idx_0]) / dx_data[x_idx_0];
    pp_coefs->data[x_idx_0] = (dzdxdx - dzzdx) / dx_data[x_idx_0];
    pp_coefs->data[nx + x_idx_0] = 2.0 * dzzdx - dzdxdx;
    pp_coefs->data[(nxm1 << 1) + x_idx_0] = s->data[x_idx_0];
    pp_coefs->data[3 * nxm1 + x_idx_0] = y->data[yoffset + x_idx_0];
  }
}

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                const double s[2]
 *                emxArray_real_T *pp_breaks
 *                double pp_coefs[4]
 * Return Type  : void
 */
void pwchcore(const emxArray_real_T *x, const emxArray_real_T *y, const double
              s[2], emxArray_real_T *pp_breaks, double pp_coefs[4])
{
  int x_idx_0;
  int i7;
  double dxj;
  double divdifij;
  double dzzdx;
  x_idx_0 = x->size[1];
  i7 = pp_breaks->size[0] * pp_breaks->size[1];
  pp_breaks->size[0] = 1;
  pp_breaks->size[1] = x_idx_0;
  emxEnsureCapacity((emxArray__common *)pp_breaks, i7, (int)sizeof(double));
  for (i7 = 0; i7 < x_idx_0; i7++) {
    pp_breaks->data[pp_breaks->size[0] * i7] = x->data[i7];
  }

  for (x_idx_0 = 1; x_idx_0 < x->size[1]; x_idx_0++) {
    dxj = x->data[x_idx_0] - x->data[x_idx_0 - 1];
    divdifij = (y->data[x_idx_0 + 1] - y->data[x_idx_0]) / dxj;
    dzzdx = (divdifij - s[x_idx_0 - 1]) / dxj;
    divdifij = (s[1] - divdifij) / dxj;
    pp_coefs[x_idx_0 - 1] = (divdifij - dzzdx) / dxj;
    pp_coefs[x_idx_0] = 2.0 * dzzdx - divdifij;
    pp_coefs[x_idx_0 + 1] = s[x_idx_0 - 1];
    pp_coefs[3] = y->data[x_idx_0];
  }
}

/*
 * File trailer for pwchcore.c
 *
 * [EOF]
 */
