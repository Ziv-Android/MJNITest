#include <com_ziv_thread_NativeThread.h>

/*
 * Class:     com_ziv_thread_NativeThread
 * Method:    start
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ziv_thread_NativeThread_start
        (JNIEnv *env, jobject obj) {
    JavaVM *jvm;
    env->GetJavaVM(&jvm);
    int getEnvStat = jvm->AttachCurrentThread(&env, NULL);
    if (getEnvStat == JNI_EDETACHED) {
        LOGE("");
    }
    jvm->DetachCurrentThread();
}