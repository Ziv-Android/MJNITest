/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "jni_log_util.h"
#include "com_ziv_jni_collection_HelloJni_Name.h"
/* Header for class com_ziv_jni_collection_HelloJni */

#ifndef _Included_com_ziv_jni_collection_HelloJni
#define _Included_com_ziv_jni_collection_HelloJni
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_ziv_jni_collection_HelloJni
 * Method:    getAJNIString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ziv_jni_collection_HelloJni_getAJNIString
  (JNIEnv *, jobject);

/*
 * Class:     com_ziv_jni_collection_HelloJni
 * Method:    getTwoArray
 * Signature: (II)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_com_ziv_jni_collection_HelloJni_getTwoArray
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     com_ziv_jni_collection_HelloJni
 * Method:    doCallBack
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ziv_jni_collection_HelloJni_doCallBack
  (JNIEnv *, jobject);

/*
 * Class:     com_ziv_jni_collection_HelloJni
 * Method:    getStudentInfo
 * Signature: ()Lcom/ziv/jni/collection/Student;
 */
JNIEXPORT jobject JNICALL Java_com_ziv_jni_collection_HelloJni_getStudentInfo
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
