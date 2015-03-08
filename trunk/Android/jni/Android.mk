LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := BufferManager
LOCAL_SRC_FILES := BufferManager.cpp

include $(BUILD_SHARED_LIBRARY)
