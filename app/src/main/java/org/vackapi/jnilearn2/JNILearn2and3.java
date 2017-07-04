package org.vackapi.jnilearn2;

import android.content.Context;

import java.nio.ByteBuffer;

/**
 * Created by Administrator on 2016/9/8.
 */
public class JNILearn2and3 {
    {
        System.loadLibrary("JNILearn2and3");
    }
    private String instanceField="Instance Field";
    private static String staticField="Static Field";
    private Object instanceMethod(){
        return "Instance Method";
    }
    private static Object staticMethod(){
        return "Static Method";
    }

    public native void dataType();
    //引用数据类型的操作
    public native void yinYongShuJu_opear();
    //3.4.1字符串操作
    //1.创建一个java字符串
    public native String newJAVAString();
    //2.将java字符串转成c的字符串
    //3.释放字符串
    public native void java2CString(String str);
    //3.4.2数组操作
    public native int[] operaArray123();
    public native void operaArray4(int[] array);
    //3.4.3 NIO(原生io)操作,
    public native void createBuffer();
    public native void getBuffer(ByteBuffer obj);
    //3.4.4访问域
    // java有两类域:实例域和静态域,每个实例有实例域副本,而一个类的所有实例共享一个静态域
    public native void useField();
    //3.4.5调用方法
    //和域一样,java有两类方法:实例方法和静态方法.JNI提供访问两类方法的函数
    public native void useJavaMethod();
}
