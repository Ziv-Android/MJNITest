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

/*
 * Class:     com_ziv_jni_collection_HelloJni
 * Method:    putHumanToNative
 * Signature: (Lcom/ziv/jni/collection/Human;)V
 */
#define HUMAN_CLASS "com/ziv/jni/collection/Human"
#define TEACHER_CLASS "com/ziv/jni/collection/Human$Teacher"
#define WORKER_CLASS "com/ziv/jni/collection/Human$Worker"
//#define FIND_CLASS
JNIEXPORT void JNICALL Java_com_ziv_jni_collection_HelloJni_putHumanToNative
        (JNIEnv *env, jobject obj, jobject human_obj) {
#ifdef FIND_CLASS
    jclass human_cls = env->FindClass(HUMAN_CLASS);
#else
    jclass human_cls = env->GetObjectClass(human_obj);
#endif
    if (human_cls == NULL) {
        LOGE("Get human class failed.");
        return;
    }
    jfieldID name_field = env->GetFieldID(human_cls, "name", "Ljava/lang/String;");
    jfieldID age_field = env->GetFieldID(human_cls, "age", "I");
    // 获取属性值
    jint age = env->GetIntField(human_obj, age_field);
    jstring name = (jstring) env->GetObjectField(human_obj, name_field);
    const char *c_name = env->GetStringUTFChars(name, JNI_FALSE);

    LOGE("Human name is %s, age is %d.", c_name, age);

    jclass teacher_cls = env->FindClass(TEACHER_CLASS);
    if (teacher_cls == NULL) {
        LOGE("Get teacher class failed.");
    } else {
        jmethodID teacher_init = env->GetMethodID(teacher_cls, "<init>", "(Lcom/ziv/jni/collection/Human;)V");
        if (teacher_init == NULL) {
            LOGE("Get teacher_init method failed.");
        }
        jobject teacher_obj = env->NewObject(teacher_cls, teacher_init, NULL);
        jfieldID subject_field = env->GetFieldID(teacher_cls, "subject", "Ljava/lang/String;");
        jstring subject = (jstring) env->GetObjectField(teacher_obj, subject_field);
        const char *c_subject = env->GetStringUTFChars(subject, false);

        LOGE("Teacher subject is %s.", c_subject);
    }
    jclass worker_cls = env->FindClass(WORKER_CLASS);
    if (worker_cls == NULL) {
        LOGE("Get worker class failed.");
    } else {
        jmethodID worker_init = env->GetMethodID(worker_cls, "<init>", "(Lcom/ziv/jni/collection/Human;)V");
        jobject worker_obj = env->NewObject(worker_cls, worker_init, NULL);
        jfieldID type_field = env->GetFieldID(worker_cls, "type", "Ljava/lang/String;");
        jstring type = (jstring) env->GetObjectField(worker_obj, type_field);
        const char *c_type = env->GetStringUTFChars(type, false);

        LOGE("Worker type is %s.", c_type);
    }
}

/*
 * Class:     com_ziv_jni_collection_HelloJni
 * Method:    getStudentList
 * Signature: ()Ljava/util/ArrayList;
 */
JNIEXPORT jobject JNICALL Java_com_ziv_jni_collection_HelloJni_getStudentList
        (JNIEnv *env, jobject obj){
    jclass list_cls = env->FindClass("java/util/ArrayList");
    if (list_cls == NULL) {
        LOGE("List class not fount.");
        return NULL;
    }
    jmethodID list_init = env->GetMethodID(list_cls, "<init>", "()V");
    jobject list_obj = env->NewObject(list_cls, list_init);
    // boolean add(Object object);
    jmethodID list_add = env->GetMethodID(list_cls, "add", "(Ljava/lang/Object;)Z");

    jclass stu_cls = env->FindClass("com/ziv/jni/collection/Student");
    jmethodID stu_init = env->GetMethodID(stu_cls, "<init>", "(ILjava/lang/String;)V");

    for (int i = 0; i < 3; ++i) {
        jstring str = env->NewStringUTF("Native");
        jobject stu_obj = env->NewObject(stu_cls, stu_init, 10, str);
        env->CallBooleanMethod(list_obj, list_add, stu_obj);
    }
    return list_obj;
}