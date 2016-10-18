package org.vackapi.jnilearn2;

/**
 * Created by Administrator on 2016/9/6.
 */
public class JNILearn {
    {
        System.loadLibrary("JNILearn");
    }
    public native void say();
}
