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
        (JNIEnv *env, jobject obj, jint dimionX, jint dimionY){
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
        (JNIEnv *env, jobject obj){
    // obj代表了执行此JNI操作的类实例引用
    jfieldID nameFieldId;
    // 获取Java层该对象实例的类引用，HelloJni内部类Name
    jclass clazz = env->GetObjectClass(obj);
    // 获取属性句柄
    nameFieldId = env->GetFieldID(clazz, "name", "Ljava/lang/String;");
    if (nameFieldId == NULL){
        LOGE("Get name field id is failed.");
    }
    // 获取该属性的值
    jstring javaNameStr = (jstring) env->GetObjectField(obj, nameFieldId);
    // 转换为char*类型
    const char * c_javaName = env->GetStringUTFChars(javaNameStr, 0);
    LOGE("Name is %s",c_javaName);
    // 释放局部引用
    env->ReleaseStringUTFChars(javaNameStr, c_javaName);

    // 构造一个jstring对象
    const char *c_ptr_name = "native";
    jstring cName = env->NewStringUTF(c_ptr_name);
    // 设置该字段值
    env->SetObjectField(obj, nameFieldId, cName);
    env->DeleteLocalRef(cName);
}