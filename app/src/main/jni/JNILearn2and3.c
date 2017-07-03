//
// Created by Administrator on 2016/9/8.
//

#include <jni.h>
#include <android/log.h>
#include <stddef.h>

JNIEXPORT void JNICALL
Java_org_vackapi_jnilearn2_JNILearn2and3_dataType(JNIEnv *env, jobject instance) {
    /**
     * 第二章主要说了Android.mk、Application.mk的配置和ndk-build脚本，网上很好找，ndk的Simple也有参考，不说；
     * ndk-build脚本去看app/build.gradle的50行开始的内容
     * 我们让java的编译任务跟在 task CopyToJniLibs（把so库复制到jniLibs目录）后面，然后让 task  CopyToJniLibs跟在ndkBuild后面
     * 这样我们就由ndk-build来编译生成so库再移到jniLibs
     */
    //第三章  用JNI实现与原生代码的通信
    /**
     * 3.1什么是JNI  （介绍而已，莫要激动）
     *    JNI是Java程序设计语言功能最强的特征，它允许Java类的某些方法原生实现，同时能让他们能够像普通java方法一样被调用和使用。
     *    这些原生方法也可以使用Java对象，使用代码与Java使用Java对象的方法相同。原生方法可以创建新的Java对象或者使用Java应用程
     *    序创建的对象，这些Java应用程序可以检查、修改和调用这些对象的方法以执行任务
     *    （好像没啥用-_-#）
     */
    /**
     * 3.2以一个示例开始  （就是一HelloWorld）看过我上一个github的一定没问题了:https://github.com/vack2015/JNILearn
     * 就酱，下课
     * 不！下一课
     */
    //                            3.3   数据类型
//                                     基本数据类型
//            java                  jni                   c/c++               大小
//           Boolean              Jboolean             unsigned char        无符号8位
//           Byte                 Jbyte                     char            有符号8位
//           Char                 Jchar                unsigned short       无符号16位
//           Short                Jshort                   short            有符号16位
//           Int                  Jint                      int             有符号32位
//           Long                 Jlong                   long long         有符号64位
//           Float                Jfloat                   float               32位
//           Double               Jdouble                  double              64位

//                                   引用数据类型
// 与基本数据类型不同引用数据类型对原生方法是不公开的
//             java类型                                         原生类型
//          java.lang.Class                                      jclass
//        java.lang.Throwable                                  jthrowable
//         java.lang.String                                      jstring
//           Other object                                        jobject
//        java.lang.Object[]                                   jobjectArray
//             boolean[]                                      jbooleanArray
//               byte[]                                         jbyteArray
//               char[]                                         jcharArray
//              short[]                                        jshortArray
//               int[]                                          jintArray
//              long[]                                         jlongArray
//              float[]                                        jfloatArray
//             double[]                                        jdoubleArray
//             Other array                                        Jarray
//
    __android_log_print(ANDROID_LOG_ERROR,"VACK","程序不关键，看注释");
}

JNIEXPORT void JNICALL
Java_org_vackapi_jnilearn2_JNILearn2and3_yinYongShuJu_1opear(JNIEnv *env, jobject instance) {
    //3.4以前基本都在介绍基本数据类型
    //3.4以后介绍的是引用数据类新
}

/**
 * 3.4.1-1 创建一个字符串
 */
JNIEXPORT jstring JNICALL
Java_org_vackapi_jnilearn2_JNILearn2and3_newJAVAString(JNIEnv *env, jobject instance) {
    jstring javaString=(*env)->NewStringUTF(env,"New a JAVA String");
    return javaString;
}
/**
 * 3.4.1-2 java字符串转C字符串, 3.4.1-2释放字符串
 */
JNIEXPORT void JNICALL
Java_org_vackapi_jnilearn2_JNILearn2and3_java2CString(JNIEnv *env, jobject instance, jstring str_) {
    const char *str = (*env)->GetStringUTFChars(env,str_, NULL);
    __android_log_print(ANDROID_LOG_ERROR,"VACK",str);
    (*env)->ReleaseStringUTFChars(env,str_, str);//释放字符串
}

/**
 * 3.4.2数组操作
 */

JNIEXPORT jintArray JNICALL
Java_org_vackapi_jnilearn2_JNILearn2and3_operaArray123(JNIEnv *env, jobject instance) {
    // 1.创建数组,通过New<Type>Array函数可以在原生代码中创建数组实例,其中Type可以是Int,Char,Boolean
    jintArray javaArray=(*env)->NewIntArray(env,10);
    //在内存溢出的情况下New<Type>Array会返回NULL,所以判空
    jint nativeArray[10];
    if (0!=javaArray){
        //现在可以使用数组
        // 2.访问数组元素,JNI提供两种访问数组元素的方法,一种是将数组复制成C数组,另一种是让JNI提供直接指向数组元素的指针
        // 3.对副本的操作,Get<Type>ArrayRegion函数将给定的的基本Java数组复制到给定的C数组中

        (*env)->GetIntArrayRegion(env,javaArray,0,10,nativeArray);
        //这样原生代码就可以像修改普通C数组一样修改数组元素了
        int i;
        for (i=0;i< sizeof(nativeArray)/sizeof(nativeArray[0]);i++){
            nativeArray[i]=i;
        }
        //当修改完成可以使用Set<Type>ArrayRegion将C数组复制回给Java数组
        (*env)->SetIntArrayRegion(env,javaArray,0,10,nativeArray);
    }
    return javaArray;
    //当数组很大时,为了对java数组操作而复制数组会引发性能问题,在这种情况下,如果可能,原生代码应该只获取或设置数组元素区域而不是整个数组.
    //另外,JNI提供了不同的函数集以获取数组元素而非其副本的指针
}

/*JNIEXPORT jintArray JNICALL
Java_org_vackapi_jnilearn2_JNILearn2and3_operaArray123(JNIEnv *env, jobject instance) {

}*/

JNIEXPORT void JNICALL
Java_org_vackapi_jnilearn2_JNILearn2and3_operaArray4(JNIEnv *env, jobject instance, jintArray array_) {
    //4.直接对指针的操作,Get<Type>ArrayElements函数获取指向该数组元素的直接指针
    jboolean isCopy;
    jint* nativeDirectArray=(*env)->GetIntArrayElements(env,array_,&isCopy);
    //JNI没有提供直接访问数组元素的指针,JNI要求原生代码用完后立即释放指针,并提供Release<Type>ArrayElements函数
    int arrCount= (*env)->GetArrayLength(env,array_);
    int i;
    for(i=0;i<arrCount;i++){
        __android_log_print(ANDROID_LOG_ERROR,"VACK","array[%d]=%d",i,nativeDirectArray[i]);
    }
    (*env)->ReleaseIntArrayElements(env,array_,nativeDirectArray,0);
}



















