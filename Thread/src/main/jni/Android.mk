LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := jni-collection
LOCAL_SRC_FILES := com_ziv_thread_NativeThread.cpp
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include

LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)