#libdvbtest写到call里面
SUBDIR_MAKEFILES := $(call all-named-subdir-makefiles,libdvbtest)

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := libcutils liblog

LOCAL_INCLUDES += $(LOCAL_PATH)

LOCAL_CFLAGS  += -DQEMU_HARDWARE
QEMU_HARDWARE := true

LOCAL_SHARED_LIBRARIES += libdl

LOCAL_SRC_FILES += yang.c

LOCAL_MODULE:= yang
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)
include $(BUILD_EXECUTABLE)

include $(SUBDIR_MAKEFILES)
