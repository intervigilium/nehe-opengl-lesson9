LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

GLTUTORIAL_SRC := $(wildcard $(LOCAL_PATH)/*.c)

LOCAL_MODULE := gltutorial

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../libzip $(LOCAL_PATH)/../libpng
LOCAL_STATIC_LIBRARIES := libzip libpng

LOCAL_CFLAGS := -DANDROID_NDK -Wno-psabi -std=c99

LOCAL_SRC_FILES := $(GLTUTORIAL_SRC:$(LOCAL_PATH)/%=%)

LOCAL_LDLIBS := -lGLESv1_CM -ldl -llog -lz

include $(BUILD_SHARED_LIBRARY)