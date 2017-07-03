package org.vackapi.jnilearn2;

import android.content.Context;

/**
 * Created by Administrator on 2016/9/8.
 */
public class JNILearn2and3 {
    {
        System.loadLibrary("JNILearn2and3");
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
}
