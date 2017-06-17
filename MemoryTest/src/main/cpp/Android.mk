LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := jni-memory
LOCAL_SRC_FILES := read/ReadMemary.cpp crash/OverSize.cpp valgrind/ErrorSimples.cpp \
                   com_ziv_memory_MemoryTestAPI.cpp
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include

LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)