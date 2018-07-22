/*
 * File: pwchcore.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "vsd.h"
#include "pwchcore.h"
#include "vsd_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const double y_data[]
 *                int yoffset
 *                const double s_data[]
 *                const double dx_data[]
 *                const double divdif_data[]
 *                double pp_breaks_data[]
 *                int pp_breaks_size[2]
 *                emxArray_real_T *pp_coefs
 * Return Type  : void
 */
void b_pwchcore(const double x_data[], const int x_size[2], const double y_data[],
                int yoffset, const double s_data[], const double dx_data[],
                const double divdif_data[], double pp_breaks_data[], int
                pp_breaks_size[2], emxArray_real_T *pp_coefs)
{
  int nx;
  int nxm1;
  int loop_ub;
  int i4;
  double dzzdx;
  double dzdxdx;
  nx = x_size[1] - 1;
  nxm1 = x_size[1] - 1;
  pp_breaks_size[0] = 1;
  pp_breaks_size[1] = x_size[1];
  loop_ub = x_size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    pp_breaks_data[pp_breaks_size[0] * i4] = x_data[i4];
  }

  i4 = pp_coefs->size[0] * pp_coefs->size[1] * pp_coefs->size[2];
  pp_coefs->size[0] = 1;
  pp_coefs->size[1] = (short)(x_size[1] - 1);
  pp_coefs->size[2] = 4;
  emxEnsureCapacity_real_T(pp_coefs, i4);
  for (loop_ub = 0; loop_ub < nx; loop_ub++) {
    dzzdx = (divdif_data[loop_ub] - s_data[loop_ub]) / dx_data[loop_ub];
    dzdxdx = (s_data[loop_ub + 1] - divdif_data[loop_ub]) / dx_data[loop_ub];
    pp_coefs->data[loop_ub] = (dzdxdx - dzzdx) / dx_data[loop_ub];
    pp_coefs->data[nx + loop_ub] = 2.0 * dzzdx - dzdxdx;
    pp_coefs->data[(nxm1 << 1) + loop_ub] = s_data[loop_ub];
    pp_coefs->data[3 * nxm1 + loop_ub] = y_data[yoffset + loop_ub];
  }
}

/*
 * Arguments    : const double x_data[]
 *                const int x_size[2]
 *                const double y_data[]
 *                const double s[2]
 *                double pp_breaks_data[]
 *                int pp_breaks_size[2]
 *                double pp_coefs[4]
 * Return Type  : void
 */
void pwchcore(const double x_data[], const int x_size[2], const double y_data[],
              const double s[2], double pp_breaks_data[], int pp_breaks_size[2],
              double pp_coefs[4])
{
  int loop_ub;
  double dxj;
  double divdifij;
  double dzzdx;
  pp_breaks_size[0] = 1;
  pp_breaks_size[1] = x_size[1];
  loop_ub = x_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&pp_breaks_data[0], &x_data[0], (unsigned int)(loop_ub * (int)sizeof
            (double)));
  }

  for (loop_ub = 1; loop_ub < x_size[1]; loop_ub++) {
    dxj = x_data[loop_ub] - x_data[loop_ub - 1];
    divdifij = (y_data[loop_ub + 1] - y_data[loop_ub]) / dxj;
    dzzdx = (divdifij - s[loop_ub - 1]) / dxj;
    divdifij = (s[1] - divdifij) / dxj;
    pp_coefs[loop_ub - 1] = (divdifij - dzzdx) / dxj;
    pp_coefs[loop_ub] = 2.0 * dzzdx - divdifij;
    pp_coefs[loop_ub + 1] = s[loop_ub - 1];
    pp_coefs[3] = y_data[loop_ub];
  }
}

/*
 * File trailer for pwchcore.c
 *
 * [EOF]
 */
