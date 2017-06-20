//
// Created by ziv on 17-5-24.
//
#include <stdlib.h>
#include <string.h>
#include "jni_log_util.h"

/**
 * 常见的内存使用问题
 * 1. 动态内存泄露；
 * 2. 资源泄露，这里以文件描述符为例；
 * 3. 动态内存越界；
 * 4. 数组内存越界；
 * 5. 动态内存double free；
 * 6. 使用野指针，即未初始化的指针（会直接导致crash）；
 * 7. 释放野指针，即未初始化的指针；
 */
void memoryNoFreeLeak() {
    char *p = (char *) malloc(1);
}

void memoryLeak() {
    FILE *fp = fopen("test.txt", "w");
}

void memoryOverrunError() {
    char *p = (char *) malloc(1);
    *(short *) p = 2;

    free(p);
}

void strcpyOverrunError() {
    char array[1];
    strcpy(array, "hello");
}

void memoryDoubleFree() {
    char *p = (char *) malloc(1000);
    *p = 1;
    for (int i = 0; i < 10; ++i) {
        free(p);
        LOGE("memoryDoubleFree free %d", i);
        if (p == NULL){
            LOGE("memoryDoubleFree p is Null");
        } else{
            LOGE("--> memoryDoubleFree p is %d.", p);
        }
    }
    /********/
    char *q = new char[100];
    delete []q;
    delete []q;
}

void useWildPointer() {
    char *p = (char *) ((void *) 0x80184800);
    *p = 1;
}

void memoryFreeWildPointer() {
    char *p;
    free(p);
}

