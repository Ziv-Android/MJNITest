LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := jni-log
LOCAL_SRC_FILES := com_ziv_jni_log_LogPrint.cpp
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include

LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)