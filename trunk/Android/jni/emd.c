/*
 * File: emd.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 06-Jun-2014 20:32:45
 */

/* Include files */
#include "processAudio.h"
#include "emd.h"
#include "processAudio_emxutil.h"
#include "spline.h"

/* Function Definitions */

/*
 * Arguments    : const double x[8192]
 *                emxArray_real_T *imf
 * Return Type  : void
 */
void emd(const double x[8192], emxArray_real_T *imf)
{
  static double c[8192];
  emxArray_real_T *maxmin;
  int m;
  emxArray_real_T *maxes;
  emxArray_real_T *mins;
  emxArray_real_T *maxenv;
  emxArray_real_T *minenv;
  emxArray_real_T *h;
  emxArray_real_T *b_h;
  emxArray_real_T *r0;
  emxArray_real_T *r1;
  emxArray_real_T *b_imf;
  int32_T exitg1;
  static double c_h[8192];
  double SD;
  boolean_T exitg2;
  double b_y1[8191];
  int ixLead;
  int iyLead;
  double work;
  double c_y1;
  double d_y1;
  static double prevh[8192];
  double y[8192];

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
  memcpy(&c[0], &x[0], sizeof(double) << 13);
  emxInit_real_T(&maxmin, 2);

  /*  copy of the input signal (as a row vector) */
  m = maxmin->size[0] * maxmin->size[1];
  maxmin->size[0] = 1;
  maxmin->size[1] = 8192;
  emxEnsureCapacity((emxArray__common *)maxmin, m, (int)sizeof(double));
  for (m = 0; m < 8192; m++) {
    maxmin->data[m] = 0.0;
  }

  /* ------------------------------------------------------------------------- */
  /*  loop to decompose the input signal into successive IMF */
  m = imf->size[0] * imf->size[1];
  imf->size[0] = 1;
  imf->size[1] = 8192;
  emxEnsureCapacity((emxArray__common *)imf, m, (int)sizeof(double));
  for (m = 0; m < 8192; m++) {
    imf->data[m] = 0.0;
  }

  /*  Matrix which will contain the successive IMF, and the residue */
  emxInit_real_T(&maxes, 2);
  emxInit_real_T(&mins, 2);
  emxInit_real_T(&maxenv, 2);
  emxInit_real_T(&minenv, 2);
  emxInit_real_T(&h, 2);
  emxInit_real_T(&b_h, 2);
  emxInit_real_T(&r0, 2);
  emxInit_real_T(&r1, 2);
  emxInit_real_T(&b_imf, 2);
  do {
    exitg1 = 0;

    /*  the stop criterion is tested at the end of the loop */
    /* ------------------------------------------------------------------------- */
    /*  inner loop to find each imf */
    memcpy(&c_h[0], &c[0], sizeof(double) << 13);

    /*  at the beginning of the sifting process, h is the signal */
    SD = 1.0;

    /*  Standard deviation which will be used to stop the sifting process */
    exitg2 = false;
    while ((!exitg2) && (SD > 0.3)) {
      /*  while the standard deviation is higher than 0.3 (typical value) */
      /*  find local max/min points */
      ixLead = 1;
      iyLead = 0;
      work = c_h[0];
      for (m = 0; m < 8191; m++) {
        SD = work;
        work = c_h[ixLead];
        SD = c_h[ixLead] - SD;
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
      for (ixLead = 0; ixLead < 8190; ixLead++) {
        if (b_y1[ixLead] == 0.0) {
          /*  we are on a zero */
          iyLead = maxmin->size[0]; //1
          m = maxmin->size[0] * maxmin->size[1];
          maxmin->size[1] = iyLead + 1;
          emxEnsureCapacity((emxArray__common *)maxmin, m, (int)sizeof(double));
          maxmin->data[iyLead] = 1.0 + (double)ixLead;
        } else {
          if (b_y1[ixLead] < 0.0) {
            c_y1 = -1.0;
          } else if (b_y1[ixLead] > 0.0) {
            c_y1 = 1.0;
          } else {
            c_y1 = b_y1[ixLead];
          }

          if (b_y1[1 + ixLead] < 0.0) {
            d_y1 = -1.0;
          } else if (b_y1[1 + ixLead] > 0.0) {
            d_y1 = 1.0;
          } else {
            d_y1 = b_y1[1 + ixLead];
          }

          if (c_y1 != d_y1) {
            /*  we are straddling a zero so */
            iyLead = maxmin->size[0]; //1
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
        if (maxmin->data[0] > maxmin->data[1]) {
          /*  first one is a max not a min */
          m = maxes->size[0] * maxes->size[1];
          maxes->size[0] = 1;
          maxes->size[1] = 0;
          emxEnsureCapacity((emxArray__common *)maxes, m, (int)sizeof(double));
          m = mins->size[0] * mins->size[1];
          mins->size[0] = 1;
          mins->size[1] = 0;
          emxEnsureCapacity((emxArray__common *)mins, m, (int)sizeof(double));
        } else {
          /*  is the other way around */
          m = maxes->size[0] * maxes->size[1];
          maxes->size[0] = 1;
          maxes->size[1] = 0;
          emxEnsureCapacity((emxArray__common *)maxes, m, (int)sizeof(double));
          m = mins->size[0] * mins->size[1];
          mins->size[0] = 1;
          mins->size[1] = 0;
          emxEnsureCapacity((emxArray__common *)mins, m, (int)sizeof(double));
        }

        /*  make endpoints both maxes and mins */
        m = r0->size[0] * r0->size[1];
        r0->size[0] = 1;
        r0->size[1] = 2 + maxes->size[1];
        emxEnsureCapacity((emxArray__common *)r0, m, (int)sizeof(double));
        r0->data[0] = 1.0;
        ixLead = maxes->size[1];
        for (m = 0; m < ixLead; m++) {
          r0->data[r0->size[0] * (m + 1)] = maxes->data[maxes->size[0] * m];
        }

        r0->data[r0->size[0] * (1 + maxes->size[1])] = 8192.0;
        m = maxes->size[0] * maxes->size[1];
        maxes->size[0] = 1;
        maxes->size[1] = r0->size[1];
        emxEnsureCapacity((emxArray__common *)maxes, m, (int)sizeof(double));
        ixLead = r0->size[1];
        for (m = 0; m < ixLead; m++) {
          maxes->data[maxes->size[0] * m] = r0->data[r0->size[0] * m];
        }

        m = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        r1->size[1] = 2 + mins->size[1];
        emxEnsureCapacity((emxArray__common *)r1, m, (int)sizeof(double));
        r1->data[0] = 1.0;
        ixLead = mins->size[1];
        for (m = 0; m < ixLead; m++) {
          r1->data[r1->size[0] * (m + 1)] = mins->data[mins->size[0] * m];
        }

        r1->data[r1->size[0] * (1 + mins->size[1])] = 8192.0;
        m = mins->size[0] * mins->size[1];
        mins->size[0] = 1;
        mins->size[1] = r1->size[1];
        emxEnsureCapacity((emxArray__common *)mins, m, (int)sizeof(double));
        ixLead = r1->size[1];
        for (m = 0; m < ixLead; m++) {
          mins->data[mins->size[0] * m] = r1->data[r1->size[0] * m];
        }

        /* ------------------------------------------------------------------------- */
        /*  spline interpolate to get max and min envelopes; form imf */
        m = b_h->size[0] * b_h->size[1];
        b_h->size[0] = 1;
        b_h->size[1] = maxes->size[1];
        emxEnsureCapacity((emxArray__common *)b_h, m, (int)sizeof(double));
        ixLead = maxes->size[0] * maxes->size[1];
        for (m = 0; m < ixLead; m++) {
          b_h->data[m] = c_h[(int)maxes->data[m] - 1];
        }

        spline(maxes, b_h, maxenv);
        m = h->size[0] * h->size[1];
        h->size[0] = 1;
        h->size[1] = mins->size[1];
        emxEnsureCapacity((emxArray__common *)h, m, (int)sizeof(double));
        ixLead = mins->size[0] * mins->size[1];
        for (m = 0; m < ixLead; m++) {
          h->data[m] = c_h[(int)mins->data[m] - 1];
        }

        spline(mins, h, minenv);

        /*  mean of max and min enveloppes */
        memcpy(&prevh[0], &c_h[0], sizeof(double) << 13);

        /*  copy of the previous value of h before modifying it */
        for (m = 0; m < 8192; m++) {
          SD = c_h[m] - (maxenv->data[m] + minenv->data[m]) / 2.0;
          c_h[m] = SD;
        }

        /*  substract mean to h */
        /*  calculate standard deviation */
        /*  to avoid zero values */
        for (m = 0; m < 8192; m++) {
          SD = prevh[m] - c_h[m];
          y[m] = SD * SD / (prevh[m] * prevh[m] + 1.0E-7);
        }

        SD = y[0];
        for (ixLead = 0; ixLead < 8191; ixLead++) {
          SD += y[ixLead + 1];
        }
      }
    }

    m = b_imf->size[0] * b_imf->size[1];
    b_imf->size[0] = imf->size[0] + 1;
    b_imf->size[1] = 8192;
    emxEnsureCapacity((emxArray__common *)b_imf, m, (int)sizeof(double));
    for (m = 0; m < 8192; m++) {
      ixLead = imf->size[0];
      for (iyLead = 0; iyLead < ixLead; iyLead++) {
        b_imf->data[iyLead + b_imf->size[0] * m] = imf->data[iyLead + imf->size
          [0] * m];
      }
    }

    for (m = 0; m < 8192; m++) {
      b_imf->data[imf->size[0] + b_imf->size[0] * m] = c_h[m];
    }

    m = imf->size[0] * imf->size[1];
    imf->size[0] = b_imf->size[0];
    imf->size[1] = 8192;
    emxEnsureCapacity((emxArray__common *)imf, m, (int)sizeof(double));
    for (m = 0; m < 8192; m++) {
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
      for (m = 0; m < 8192; m++) {
        c[m] -= c_h[m];
      }

      /*  substract the extracted IMF from the signal */
    }
  } while (exitg1 == 0);

  emxFree_real_T(&b_imf);
  emxFree_real_T(&r1);
  emxFree_real_T(&r0);
  emxFree_real_T(&b_h);
  emxFree_real_T(&h);
  emxFree_real_T(&minenv);
  emxFree_real_T(&maxenv);
  emxFree_real_T(&mins);
  emxFree_real_T(&maxes);
  emxFree_real_T(&maxmin);
}

/*
 * File trailer for emd.c
 *
 * [EOF]
 */
