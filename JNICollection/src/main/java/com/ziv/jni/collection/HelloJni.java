package com.ziv.jni.collection;

/**
 * JNI创建Java对象
 *
 * Created by ziv on 17-6-16.
 */

public class HelloJni {
    static {
        System.loadLibrary("jni-collection");
    }

    public native String getAJNIString();
    public native int[][] getTwoArray(int dimon);
}
