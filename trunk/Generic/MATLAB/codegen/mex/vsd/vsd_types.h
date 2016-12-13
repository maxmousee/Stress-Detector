/*
 * vsd_types.h
 *
 * Code generation for function 'vsd'
 *
 */

#ifndef VSD_TYPES_H
#define VSD_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

#ifndef struct_emxArray_creal_T
#define struct_emxArray_creal_T

struct emxArray_creal_T
{
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_creal_T*/

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T

typedef struct emxArray_creal_T emxArray_creal_T;

#endif                                 /*typedef_emxArray_creal_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_vsdStackData
#define typedef_vsdStackData

typedef struct {
  union
  {
    struct {
      real_T s_data[8000];
      real_T md_data[8000];
      real_T t0_breaks_data[8000];
    } f0;

    struct {
      real_T dv1[7999];
      real_T dv2[7998];
    } f1;
  } u1;

  union
  {
    struct {
      real_T pp_breaks_data[8000];
    } f2;

    struct {
      real_T x[8000];
      real_T tmp_data[7998];
    } f3;

    struct {
      real_T x[8000];
      real_T tmp_data[7998];
    } f4;
  } u2;

  struct {
    real_T tmp_data[8000];
    real_T b_tmp_data[8000];
    real_T p_data[7998];
  } f5;

  struct {
    real_T x[8000];
    real_T x1[8000];
    real_T s1_data[8000];
    real_T b_x1[8000];
    real_T s2_data[8000];
    real_T x2[8000];
    real_T dv0[8000];
  } f6;

  struct {
    real_T imf_data[8000];
  } f7;
} vsdStackData;

#endif                                 /*typedef_vsdStackData*/
#endif

/* End of code generation (vsd_types.h) */
