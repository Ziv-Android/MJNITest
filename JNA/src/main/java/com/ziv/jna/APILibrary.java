package com.ziv.jna;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Pointer;

/**
 * 使用JNA加载native library，声明接口
 * <p>
 * 注：
 *  此时接口不在需要声明native
 *  调用耗时会比传统JNI慢一点
 *  需特别注意JNI与JNA数据类型的对应关系
 * <p>
 * Created by ziv on 17-5-16.
 */

public interface APILibrary extends Library {
    APILibrary INSTANCE = (APILibrary) Native.loadLibrary("libraryName", APILibrary.class);

    Pointer create(String filePath);
}
