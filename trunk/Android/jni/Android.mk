LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := processAudio
LOCAL_SRC_FILES := processAudio.c bsearch.c emd.c fft.c processAudio_emxutil.c processAudio_initialize.c processAudio_terminate.c rtGetInf.c rtGetNaN.c rt_nonfinite.c spline.c

include $(BUILD_SHARED_LIBRARY)