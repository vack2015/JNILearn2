LOCAL_PATH:=$(call my-dir)

include $(CLEARS_VARS)

LOCAL_LDLIBS := -llog
LOCAL_CPP_FLAGS := -fno-rtti

LOCAL_MODULE := JNILearn
LOCAL_MODULE_FILENAME:=libJNILearn
LOCAL_SRC_FILES := JNILearn.c org_vackapi_jnilearn2_JNILearn.h

LOCAL_MODULE := JNILearn2and3
LOCAL_MODULE_FILENAME:=libJNILearn2and3
LOCAL_SRC_FILES := JNILearn2and3.c org_vackapi_jnilearn2_JNILearn2and3.h

include $(BUILD_SHARED_LIBRARY)