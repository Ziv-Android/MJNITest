#include <com_ziv_jni_log_LogPrint.h>
#include "jni_log_util.h"

#define TAG "JNILog"

JNIEXPORT void JNICALL Java_com_ziv_jni_log_LogPrint_print
        (JNIEnv *env, jclass clazz, jstring msg) {
    const char *str;
    if (msg) {
        str = env->GetStringUTFChars(msg, false);
        __android_log_print(ANDROID_LOG_ERROR, TAG, "%s", str);
        LOGD("%s", str);
    } else {
        LOGE("error Error_Msg is null");
    }
}
