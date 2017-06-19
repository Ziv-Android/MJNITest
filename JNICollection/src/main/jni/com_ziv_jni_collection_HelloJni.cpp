#include <com_ziv_jni_collection_HelloJni.h>

/*
 * Class:     com_ziv_jni_collection_HelloJni
 * Method:    getAJNIString
 * Signature: ()V
 */
JNIEXPORT jstring JNICALL Java_com_ziv_jni_collection_HelloJni_getAJNIString
        (JNIEnv *env, jobject obj) {
    jstring str = env->NewStringUTF("Hello from jni");
    return str;
}

/*
 * Class:     com_ziv_jni_collection_HelloJni
 * Method:    getTwoArray
 * Signature: (I)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_com_ziv_jni_collection_HelloJni_getTwoArray
        (JNIEnv *env, jobject obj, jint dimionX, jint dimionY) {
    // 获取一维数组的类引用，即jintArray类型
    jclass intArrayClass = env->FindClass("[I");
    // 构造一个指向jintArray类一维数组的对象数组，该对象数组的初始大小为dimion
    jobjectArray objIntArray = env->NewObjectArray(dimionX, intArrayClass, NULL);
    // 构建一个一维数组，将它作为二维数组的对象
    for (int i = 0; i < dimionX; ++i) {
        // 构建jint型数组
        jintArray intArray = env->NewIntArray(dimionX);
        // 初始化一个容器
        jint temp[dimionY];
        for (int j = 0; j < dimionY; ++j) {
            temp[j] = i + j;
        }
        // 设置一维数组的值
        env->SetIntArrayRegion(intArray, 0, dimionX, temp);
        env->SetObjectArrayElement(objIntArray, i, intArray);
        // 删除局部引用
        env->DeleteLocalRef(intArray);
    }
    return objIntArray;
}

/*
 * Class:     com_ziv_jni_collection_HelloJni_Name
 * Method:    setNewName
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ziv_jni_collection_HelloJni_00024Name_setNewName
        (JNIEnv *env, jobject obj) {
    // obj代表了执行此JNI操作的类实例引用
    jfieldID nameFieldId;
    // 获取Java层该对象实例的类引用，HelloJni内部类Name
    jclass clazz = env->GetObjectClass(obj);
    // 获取属性句柄
    nameFieldId = env->GetFieldID(clazz, "name", "Ljava/lang/String;");
    if (nameFieldId == NULL) {
        LOGE("Get name field id is failed.");
    }
    // 获取该属性的值
    jstring javaNameStr = (jstring) env->GetObjectField(obj, nameFieldId);
    // 转换为char*类型
    const char *c_javaName = env->GetStringUTFChars(javaNameStr, 0);
    LOGE("Name is %s", c_javaName);
    // 释放局部引用
    env->ReleaseStringUTFChars(javaNameStr, c_javaName);

    // 构造一个jstring对象
    const char *c_ptr_name = "native";
    jstring cName = env->NewStringUTF(c_ptr_name);
    // 设置该字段值
    env->SetObjectField(obj, nameFieldId, cName);
    env->DeleteLocalRef(cName);
}

/*
 * Class:     com_ziv_jni_collection_HelloJni
 * Method:    doCallBack
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_ziv_jni_collection_HelloJni_doCallBack
        (JNIEnv *env, jobject obj) {
    jclass clazz = env->GetObjectClass(obj);
    jmethodID callbackMethod = env->GetMethodID(clazz, "callback", "(Ljava/lang/String;)V");

    if (callbackMethod == NULL) {
        LOGE("Get callback method id is failed.");
    }

    jstring native_string = env->NewStringUTF("I am native");
    //回调该方法，并且传递参数值
    env->CallVoidMethod(obj, callbackMethod, native_string);
}

/*
 * Class:     com_ziv_jni_collection_HelloJni
 * Method:    getStudentInfo
 * Signature: ()Lcom/ziv/jni/collection/Student;
 */
#define STUDENT_CLASS "com/ziv/jni/collection/Student"
#define INIT_WITH_DATA
JNIEXPORT jobject JNICALL Java_com_ziv_jni_collection_HelloJni_getStudentInfo
        (JNIEnv *env, jobject obj) {
    // 关于包描述符理论上, Lcom/ziv/jni/collection/Student; 与 com/ziv/jni/collection/Student 等价
    // 但实测Nexus6 Android7.0不可用 Lcom/ziv/jni/collection/Student; ,crash信息如下
    // JNI DETECTED ERROR IN APPLICATION: illegal class name
    // (should be of the form 'package/Class', [Lpackage/Class;' or '[[B') in call to FindClass

    // 获得Student类引用
    jclass stucls = env->FindClass(STUDENT_CLASS);
    if (stucls == NULL) {
        LOGE("Find student class is failed.");
    }

    jstring str = env->NewStringUTF("Native");
#ifdef INIT_WITH_DATA
    jmethodID stu_data_init = env->GetMethodID(stucls, "<init>", "(ILjava/lang/String;)V");
    if (stu_data_init == NULL) {
        LOGE("Find student init function with data is failed.");
    }

    // 使用包含带参数的构造函数创建对象
    jobject stu_obj = env->NewObject(stucls, stu_data_init, 11, str);
#else
    jmethodID stu_init = env->GetMethodID(stucls, "<init>", "()V");
    if (stu_init == NULL) {
        LOGE("Find student init function is failed.");
    }
    jobject stu_obj = env->NewObject(stucls, stu_init, NULL);
    jfieldID field_age = env->GetFieldID(stucls, "age", "I");
    if (field_age == NULL) {
        LOGE("field age id get failed.");
    }
    jfieldID field_name = env->GetFieldID(stucls, "name", "Ljava/lang/String;");
    if (field_name == NULL) {
        LOGE("field name id get failed.");
    }
    env->SetIntField(stu_obj, field_age, 21);
    env->SetObjectField(stu_obj, field_name, str);
#endif
    return stu_obj;
}