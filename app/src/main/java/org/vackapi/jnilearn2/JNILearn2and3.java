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

    public native  void test(Context context,String str);
}
