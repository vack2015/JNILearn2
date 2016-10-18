#include <jni.h>
#include <android/log.h>
#include <string.h>

JNIEXPORT void JNICALL
Java_org_vackapi_jnilearn2_JNILearn_say(JNIEnv *env, jobject instance) {
    jstring say = (*env)->NewStringUTF(env,
                                       "    这里我把《Android C++ 高级编程--使用ndk》这本书的程序清单打一下;\n第一第二章基本都是一些配置问题，书上用的是eclipse和mk文件，我们这边则用了AndroisStudio和bulid.gradle和mk文件，所以我就不做赘述;\n mk文件的问题，你们可以到网上找");
    jboolean change=JNI_FALSE;
    jbyte *str=(*env)->GetStringUTFChars(env,say,&change);
    if(str!=0){
        if(change){
            __android_log_print(ANDROID_LOG_ERROR,"VACK",str);
        }
        (*env)->ReleaseStringChars(env,say,str);
    }

}