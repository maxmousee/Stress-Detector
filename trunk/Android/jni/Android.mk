LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := VSD
LOCAL_SRC_FILES := VSD.cpp

include $(BUILD_SHARED_LIBRARY)
