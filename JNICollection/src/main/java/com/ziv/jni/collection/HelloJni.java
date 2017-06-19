package com.ziv.jni.collection;

import android.util.Log;

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

    public native int[][] getTwoArray(int dimionX, int dimionY);

    public class Name {
        private String name = "Java";

        public native void setNewName();
        public String getNewName(){
            return name;
        }
    }

    public void callback(String fromNative){
        Log.e("HelloJni", "Native call java method and return string is ###### " + fromNative);
    }
    public native void doCallBack();

    public native Student getStudentInfo();

    public native void putHumanToNative();
}
