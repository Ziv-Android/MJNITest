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
    public native int[][] getTwoArray(int dimionX, int dimionY);

//    public Name name;
//    public HelloJni() {
//        name = new Name();
//    }

    public class Name {
        private String name = "Java";

        public native void setNewName();
        public String getNewName(){
            return name;
        }
    }
}
