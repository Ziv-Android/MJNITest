//
// Created by ziv on 17-5-22.
//
#include "android/log.h"

int Hello(){
    char *a[4];
    for(int i = 0; i<4 ; ++i){
        *a[i] = i;
    }
    float *b;
    b=(float)*a;
    __android_log_print(ANDROID_LOG_ERROR, "Memory", "B is %f", b);
}