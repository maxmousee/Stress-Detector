/*
 * File: emd.c
 *
 * MATLAB Coder version            : 2.7
 * C/C++ source code generated on  : 26-May-2015 20:44:52
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "processAudio.h"
#include "emd.h"
#include "processAudio_emxutil.h"
#include "spline.h"

/* Function Definitions */

/*
 * Arguments    : const double x[8000]
 *                emxArray_real_T *imf
 * Return Type  : void
 */
void emd(const double x[8000], emxArray_real_T *imf)
{
  static double c[8000];
  emxArray_real_T *maxmin;
  int m;
  emxArray_real_T *b_imf;
  int32_T exitg1;
  static double h[8000];
  double SD;
  boolean_T exitg2;
  double b_y1[7999];
  int ixLead;
  int iyLead;
  double work;
  double c_y1;
  double d_y1;
  short tmp_data[3];
  int maxes_size[2];
  double maxes_data[3];
  int mins_size[2];
  double mins_data[3];
  double h_data[3];
  int maxenv_size[2];
  static double maxenv_data[8000];
  double minenv_data[8000];
  double y[8000];

  /*  EMD:  Emprical mode decomposition */
  /*  */
  /*  imf = emd(x) */
  /*  */
  /*  x   - input signal (must be a column vector) */
  /*  */
  /*  This version will calculate all the imf's (longer) */
  /*  */
  /*  imf - Matrix of intrinsic mode functions (each as a row) */
  /*        with residual in last row. */
  /*  */
  /*  See:  Huang et al, Royal Society Proceedings on Math, Physical,  */
  /*        and Engineering Sciences, vol. 454, no. 1971, pp. 903-995,  */
  /*        8 March 1998 */
  /*  */
  /*  Author: Ivan Magrin-Chagnolleau  <ivan@ieee.org> */
  /*   */
  memcpy(&c[0], &x[0], 8000U * sizeof(double));
  emxInit_real_T(&maxmin, 2);

  /*  copy of the input signal (as a row vector) */
  m = maxmin->size[0] * maxmin->size[1];
  maxmin->size[0] = 1;
  maxmin->size[1] = 1;
  emxEnsureCapacity((emxArray__common *)maxmin, m, (int)sizeof(double));
  maxmin->data[0] = 0.0;

  /* ------------------------------------------------------------------------- */
  /*  loop to decompose the input signal into successive IMF */
  m = imf->size[0] * imf->size[1];
  imf->size[0] = 1;
  imf->size[1] = 8000;
  emxEnsureCapacity((emxArray__common *)imf, m, (int)sizeof(double));
  for (m = 0; m < 8000; m++) {
    imf->data[m] = 0.0;
  }

  /*  Matrix which will contain the successive IMF, and the residue */
  emxInit_real_T(&b_imf, 2);
  do {
    exitg1 = 0;

    /*  the stop criterion is tested at the end of the loop */
    /* ------------------------------------------------------------------------- */
    /*  inner loop to find each imf */
    memcpy(&h[0], &c[0], 8000U * sizeof(double));

    /*  at the beginning of the sifting process, h is the signal */
    SD = 1.0;

    /*  Standard deviation which will be used to stop the sifting process */
    exitg2 = false;
    while ((!exitg2) && (SD > 0.3)) {
      /*  while the standard deviation is higher than 0.3 (typical value) */
      /*  find local max/min points */
      ixLead = 1;
      iyLead = 0;
      work = h[0];
      for (m = 0; m < 7999; m++) {
        SD = work;
        work = h[ixLead];
        SD = h[ixLead] - SD;
        ixLead++;
        b_y1[iyLead] = SD;
        iyLead++;
      }

      /*  approximate derivative */
      m = maxmin->size[0] * maxmin->size[1];
      maxmin->size[0] = 0;
      maxmin->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)maxmin, m, (int)sizeof(double));

      /*  to store the optima (min and max without distinction so far) */
      for (ixLead = 0; ixLead < 7998; ixLead++) {
        if (b_y1[ixLead] == 0.0) {
          /*  we are on a zero */
          iyLead = maxmin->size[1];
          m = maxmin->size[0] * maxmin->size[1];
          maxmin->size[1] = iyLead + 1;
          emxEnsureCapacity((emxArray__common *)maxmin, m, (int)sizeof(double));
          maxmin->data[iyLead] = 1.0 + (double)ixLead;
        } else {
          if (b_y1[ixLead] < 0.0) {
            c_y1 = -1.0;
          } else if (b_y1[ixLead] > 0.0) {
            c_y1 = 1.0;
          } else if (b_y1[ixLead] == 0.0) {
            c_y1 = 0.0;
          } else {
            c_y1 = b_y1[ixLead];
          }

          if (b_y1[1 + ixLead] < 0.0) {
            d_y1 = -1.0;
          } else if (b_y1[1 + ixLead] > 0.0) {
            d_y1 = 1.0;
          } else if (b_y1[1 + ixLead] == 0.0) {
            d_y1 = 0.0;
          } else {
            d_y1 = b_y1[1 + ixLead];
          }

          if (c_y1 != d_y1) {
            /*  we are straddling a zero so */
            iyLead = maxmin->size[1];
            m = maxmin->size[0] * maxmin->size[1];
            maxmin->size[1] = iyLead + 1;
            emxEnsureCapacity((emxArray__common *)maxmin, m, (int)sizeof(double));
            maxmin->data[iyLead] = (1.0 + (double)ixLead) + 1.0;

            /*  define zero as at i+1 (not i) */
          }
        }
      }

      if (maxmin->size[1] < 2) {
        /*  then it is the residue */
        exitg2 = true;
      } else {
        /*  divide maxmin into maxes and mins */
        /*  make endpoints both maxes and mins */
        tmp_data[0] = 1;
        tmp_data[1] = 8000;
        maxes_size[0] = 1;
        maxes_size[1] = 2;
        for (m = 0; m < 2; m++) {
          maxes_data[m] = tmp_data[m];
        }

        tmp_data[0] = 1;
        tmp_data[1] = 8000;
        mins_size[0] = 1;
        mins_size[1] = 2;
        for (m = 0; m < 2; m++) {
          mins_data[m] = tmp_data[m];
        }

        /* ------------------------------------------------------------------------- */
        /*  spline interpolate to get max and min envelopes; form imf */
        for (m = 0; m < 2; m++) {
          h_data[m] = h[(int)maxes_data[m] - 1];
        }

        spline(maxes_data, maxes_size, h_data, maxenv_data, maxenv_size);
        for (m = 0; m < 2; m++) {
          h_data[m] = h[(int)mins_data[m] - 1];
        }

        spline(mins_data, mins_size, h_data, minenv_data, maxenv_size);

        /*  mean of max and min enveloppes */
        for (m = 0; m < 8000; m++) {
          /*  copy of the previous value of h before modifying it */
          work = h[m] - (maxenv_data[m] + minenv_data[m]) / 2.0;

          /*  substract mean to h */
          /*  calculate standard deviation */
          /*  to avoid zero values */
          SD = h[m] - work;
          SD = SD * SD / (h[m] * h[m] + 1.0E-7);
          h[m] = work;
          y[m] = SD;
        }

        SD = y[0];
        for (ixLead = 0; ixLead < 7999; ixLead++) {
          SD += y[ixLead + 1];
        }
      }
    }

    m = b_imf->size[0] * b_imf->size[1];
    b_imf->size[0] = imf->size[0] + 1;
    b_imf->size[1] = 8000;
    emxEnsureCapacity((emxArray__common *)b_imf, m, (int)sizeof(double));
    for (m = 0; m < 8000; m++) {
      ixLead = imf->size[0];
      for (iyLead = 0; iyLead < ixLead; iyLead++) {
        b_imf->data[iyLead + b_imf->size[0] * m] = imf->data[iyLead + imf->size
          [0] * m];
      }
    }

    for (m = 0; m < 8000; m++) {
      b_imf->data[imf->size[0] + b_imf->size[0] * m] = h[m];
    }

    m = imf->size[0] * imf->size[1];
    imf->size[0] = b_imf->size[0];
    imf->size[1] = 8000;
    emxEnsureCapacity((emxArray__common *)imf, m, (int)sizeof(double));
    for (m = 0; m < 8000; m++) {
      ixLead = b_imf->size[0];
      for (iyLead = 0; iyLead < ixLead; iyLead++) {
        imf->data[iyLead + imf->size[0] * m] = b_imf->data[iyLead + b_imf->size
          [0] * m];
      }
    }

    /*  store the extracted IMF in the matrix imf */
    /*  if size(maxmin,2)<2, then h is the residue */
    /*  stop criterion of the algo. */
    if (maxmin->size[1] < 2) {
      exitg1 = 1;
    } else {
      for (m = 0; m < 8000; m++) {
        c[m] -= h[m];
      }

      /*  substract the extracted IMF from the signal */
    }
  } while (exitg1 == 0);

  emxFree_real_T(&b_imf);
  emxFree_real_T(&maxmin);
}

/*
 * File trailer for emd.c
 *
 * [EOF]
 */
