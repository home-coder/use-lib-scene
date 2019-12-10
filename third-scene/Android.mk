LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_PREBUILT_LIBS := libtest.so   
include $(PREBUILT_SHARED_LIBRARY)  
include $(BUILD_MULTI_PREBUILT)

include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := libcutils liblog libtest

LOCAL_CFLAGS  += -DQEMU_HARDWARE
QEMU_HARDWARE := true

LOCAL_SRC_FILES += yang.c

LOCAL_MODULE:= yang
LOCAL_MODULE_PATH := $(TARGET_OUT_EXECUTABLES)

include $(BUILD_EXECUTABLE)
