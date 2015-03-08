LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := BufferManager
LOCAL_SRC_FILES := BufferManager.c emd.c processAudio_emxutil.c processAudio.c processAudio_initialize.c processAudio_terminate.c pwchcore.c spline.c

include $(BUILD_SHARED_LIBRARY)
