#include <com_ziv_memory_MemoryTestAPI.h>
#include "common.h"
/*
 * Class:     com_ziv_memory_MemoryTestAPI
 * Method:    stringFromJNI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ziv_memory_MemoryTestAPI_stringFromJNI
  (JNIEnv *env, jobject obj){

    return NULL;
}

/*
 * Class:     com_ziv_memory_MemoryTestAPI
 * Method:    readMemory
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ziv_memory_MemoryTestAPI_readMemory
  (JNIEnv *env, jobject obj){

    return NULL;
}

/*
 * Class:     com_ziv_memory_MemoryTestAPI
 * Method:    writeMemory
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ziv_memory_MemoryTestAPI_writeMemory
  (JNIEnv *env, jobject obj){

    return NULL;
}

/*
 * Class:     com_ziv_memory_MemoryTestAPI
 * Method:    valgrindTest
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ziv_memory_MemoryTestAPI_valgrindTest
  (JNIEnv *env, jobject obj){
    memoryNoFreeLeak();
    LOGE("Finish memoryNoFreeLeak");

    memoryLeak();
    LOGE("Finish memoryLeak");

    memoryOverrunError();
    LOGE("Finish memoryOverrunError");

    strcpyOverrunError();
    LOGE("Finish strcpyOverrunError");

    memoryDoubleFree();
    LOGE("Finish memoryDoubleFree");

//    useWildPointer();
//    LOGE("Finish useWildPointer");

    memoryFreeWildPointer();
    LOGE("Finish memoryFreeWildPointer");
}
