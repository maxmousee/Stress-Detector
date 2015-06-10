/*
 * File: processAudio.c
 *
 * MATLAB Coder version            : 2.7
 * C/C++ source code generated on  : 26-May-2015 20:44:52
 */

/* Include Files */
#include <jni.h>
#include "rt_nonfinite.h"
#include "processAudio.h"
#include "processAudio_emxutil.h"
#include "fft.h"
#include "emd.h"

/* Function Declarations */
static double rt_roundd_snf(double u);

/* Function Definitions */

/*
 * Arguments    : double u
 * Return Type  : double
 */
static double rt_roundd_snf(double u)
{
	double y;
	if (fabs(u) < 4.503599627370496E+15) {
		if (u >= 0.5) {
			y = floor(u + 0.5);
		} else if (u > -0.5) {
			y = u * 0.0;
		} else {
			y = ceil(u - 0.5);
		}
	} else {
		y = u;
	}

	return y;
}

/*
 * Arguments    : const double y[8000]
 *                int L
 *                int Fs
 * Return Type  : double
 */
JNIEXPORT jdouble JNICALL Java_com_nfsindustries_vsd_LiveStressActivity_processAudio( JNIEnv* env, jobject thiz, jdoubleArray arr, jint L, jint Fs)
{
	double y[L];
	int j = 0;
	jdouble *body = (*env)->GetDoubleArrayElements(env, arr, 0);
	for (j = 0; j < (*env)->GetArrayLength(env, arr); j++) {
		y[j] = body[j];
	}
	(*env)->ReleaseDoubleArrayElements(env, arr, body, 0);
	double stress;
	emxArray_real_T *imf;
	int i;
	emxArray_creal_T *Y;
	emxArray_creal_T *xdft;
	emxArray_int32_T *freq;
	emxArray_real_T *b_y;
	boolean_T exitg1;
	static double b_imf[8000];
	int k;
	int saturatedUnaryMinus;
	unsigned int c_y;
	unsigned int d_y;
	unsigned int q;
	int e_y;
	int n;
	unsigned int f_y;
	int yk;
	double mtmp;
	boolean_T exitg2;
	emxInit_real_T(&imf, 2);
	emd(y, imf);
	stress = 0.0;
	i = 0;
	emxInit_creal_T(&Y, 2);
	emxInit_creal_T(&xdft, 2);
	emxInit_int32_T(&freq, 2);
	emxInit_real_T(&b_y, 2);
	exitg1 = false;
	while ((!exitg1) && (i <= imf->size[0] - 3)) {
		for (k = 0; k < 8000; k++) {
			b_imf[k] = imf->data[i + imf->size[0] * k];
		}

		fft(b_imf, L, Y);
		if (L == 0) {
			if (Fs == 0) {
				saturatedUnaryMinus = 0;
			} else if (Fs < 0) {
				saturatedUnaryMinus = MIN_int32_T;
			} else {
				saturatedUnaryMinus = MAX_int32_T;
			}
		} else if (L == 1) {
			saturatedUnaryMinus = Fs;
		} else if (L == -1) {
			if (Fs <= MIN_int32_T) {
				saturatedUnaryMinus = MAX_int32_T;
			} else {
				saturatedUnaryMinus = -Fs;
			}
		} else {
			if (Fs >= 0) {
				c_y = (unsigned int)Fs;
			} else if (Fs == MIN_int32_T) {
				c_y = 2147483648U;
			} else {
				c_y = (unsigned int)-Fs;
			}

			if (L >= 0) {
				d_y = (unsigned int)L;
			} else if (L == MIN_int32_T) {
				d_y = 2147483648U;
			} else {
				d_y = (unsigned int)-L;
			}

			if (d_y == 0U) {
				q = MAX_uint32_T;
			} else {
				q = c_y / d_y;
			}

			c_y -= q * d_y;
			if ((c_y > 0U) && (c_y >= (d_y >> 1U) + (d_y & 1U))) {
				q++;
			}

			saturatedUnaryMinus = (int)q;
			if ((Fs < 0) != (L < 0)) {
				saturatedUnaryMinus = -(int)q;
			}
		}

		e_y = (int)rt_roundd_snf((double)Fs / 2.0);
		if (saturatedUnaryMinus < 0) {
			if (saturatedUnaryMinus == MIN_int32_T) {
				if (0 < e_y) {
					n = 0;
				} else {
					n = 1;
				}
			} else if (0 < e_y) {
				n = 0;
			} else {
				c_y = (unsigned int)-saturatedUnaryMinus;
				if (e_y < 0) {
					f_y = (unsigned int)-e_y;
				} else {
					f_y = 0U;
				}

				n = (int)(f_y / c_y) + 1;
			}
		} else if ((saturatedUnaryMinus <= 0) || (e_y < 0)) {
			n = 0;
		} else {
			c_y = (unsigned int)saturatedUnaryMinus;
			n = (int)(e_y / c_y) + 1;
		}

		k = freq->size[0] * freq->size[1];
		freq->size[0] = 1;
		freq->size[1] = n;
		emxEnsureCapacity((emxArray__common *)freq, k, (int)sizeof(int));
		if (n > 0) {
			freq->data[0] = 0;
			yk = 0;
			for (k = 2; k <= n; k++) {
				yk += saturatedUnaryMinus;
				freq->data[k - 1] = yk;
			}
		}

		e_y = (int)rt_roundd_snf((double)L / 2.0);
		yk = (int)rt_roundd_snf((double)L / 2.0);
		k = xdft->size[0] * xdft->size[1];
		xdft->size[0] = 1;
		xdft->size[1] = yk + 1;
		emxEnsureCapacity((emxArray__common *)xdft, k, (int)sizeof(creal_T));
		for (k = 0; k <= yk; k++) {
			xdft->data[xdft->size[0] * k] = Y->data[k];
		}

		k = b_y->size[0] * b_y->size[1];
		b_y->size[0] = 1;
		b_y->size[1] = e_y + 1;
		emxEnsureCapacity((emxArray__common *)b_y, k, (int)sizeof(double));
		for (k = 0; k <= e_y; k++) {
			b_y->data[k] = hypot(xdft->data[k].re, xdft->data[k].im);
		}

		yk = 1;
		n = b_y->size[1];
		mtmp = b_y->data[0];
		k = 0;
		if (b_y->size[1] > 1) {
			if (rtIsNaN(b_y->data[0])) {
				e_y = 2;
				exitg2 = false;
				while ((!exitg2) && (e_y <= n)) {
					yk = e_y;
					if (!rtIsNaN(b_y->data[e_y - 1])) {
						mtmp = b_y->data[e_y - 1];
						k = e_y - 1;
						exitg2 = true;
					} else {
						e_y++;
					}
				}
			}

			if (yk < b_y->size[1]) {
				while (yk + 1 <= n) {
					if (b_y->data[yk] > mtmp) {
						mtmp = b_y->data[yk];
						k = yk;
					}

					yk++;
				}
			}
		}

		stress = freq->data[k];
		if ((freq->data[k] >= 8) && (freq->data[k] <= 12)) {
			exitg1 = true;
		} else {
			i++;
		}
	}

	emxFree_real_T(&b_y);
	emxFree_int32_T(&freq);
	emxFree_creal_T(&xdft);
	emxFree_creal_T(&Y);
	emxFree_real_T(&imf);
	return stress;
}

/*
 * File trailer for processAudio.c
 *
 * [EOF]
 */
