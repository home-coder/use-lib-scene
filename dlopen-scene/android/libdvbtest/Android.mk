SUBDIR_MAKEFILES := $(call all-named-subdir-makefiles,modules tests)

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := libcutils liblog

LOCAL_INCLUDES += $(LOCAL_PATH)

LOCAL_CFLAGS  += -DQEMU_HARDWARE
QEMU_HARDWARE := true

#LOCAL_SHARED_LIBRARIES += libtest libdl

LOCAL_SRC_FILES += dvbtest.c

LOCAL_MODULE:= dvbtest
include $(BUILD_EXECUTABLE)
#include $(BUILD_SHARED_LIBRARY)
#
#include $(SUBDIR_MAKEFILES)

