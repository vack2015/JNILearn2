//
// Created by Administrator on 2016/9/8.
//

#include <jni.h>
#include <android/log.h>

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

}

JNIEXPORT void JNICALL
Java_org_vackapi_jnilearn2_JNILearn2and3_test(JNIEnv *env, jobject instance, jobject context,
                                              jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);

    // TODO

    env->ReleaseStringUTFChars(str_, str);
}