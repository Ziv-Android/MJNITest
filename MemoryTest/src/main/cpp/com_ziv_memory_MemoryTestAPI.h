/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "jni_log_util.h"
/* Header for class com_ziv_memory_MemoryTestAPI */

#ifndef _Included_com_ziv_memory_MemoryTestAPI
#define _Included_com_ziv_memory_MemoryTestAPI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_ziv_memory_MemoryTestAPI
 * Method:    stringFromJNI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ziv_memory_MemoryTestAPI_stringFromJNI
  (JNIEnv *, jobject);

/*
 * Class:     com_ziv_memory_MemoryTestAPI
 * Method:    readMemory
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ziv_memory_MemoryTestAPI_readMemory
  (JNIEnv *, jobject);

/*
 * Class:     com_ziv_memory_MemoryTestAPI
 * Method:    writeMemory
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ziv_memory_MemoryTestAPI_writeMemory
  (JNIEnv *, jobject);

/*
 * Class:     com_ziv_memory_MemoryTestAPI
 * Method:    valgrindTest
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ziv_memory_MemoryTestAPI_valgrindTest
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif