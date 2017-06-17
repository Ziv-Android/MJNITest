package com.ziv.memory;

/**
 * jni memory check
 *
 * Created by ziv on 17-6-16.
 */

public class MemoryTestAPI {
    static {
        System.loadLibrary("jni-memory");
    }

    // Debug
    public native String stringFromJNI();

    // ReadAndWrite
    public native String readMemory();
    public native String writeMemory();

    // valgrind
    public native void valgrindTest();
}
