#include <com_ziv_jni_collection_HelloJni.h>

/*
 * Class:     com_ziv_jni_collection_HelloJni
 * Method:    getAJNIString
 * Signature: ()V
 */
JNIEXPORT jstring JNICALL Java_com_ziv_jni_collection_HelloJni_getAJNIString
        (JNIEnv *env, jobject obj) {
    jstring str = env->NewStringUTF("Hello from jni");
    return str;
}

/*
 * Class:     com_ziv_jni_collection_HelloJni
 * Method:    getTwoArray
 * Signature: (I)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_com_ziv_jni_collection_HelloJni_getTwoArray
        (JNIEnv *env, jobject obj, jint dimion){
    // 获取一维数组的类引用，即jintArray类型
    jclass intArrayClass = env->FindClass("[I");
    // 构造一个指向jintArray类一维数组的对象数组，该对象数组的初始大小为dimion
    jobjectArray objIntArray = env->NewObjectArray(dimion, intArrayClass, NULL);
    // 构建一个一维数组，将它作为二维数组的对象

}