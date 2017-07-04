package org.vackapi.jnilearn2;

import android.animation.ObjectAnimator;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import java.nio.ByteBuffer;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        JNILearn jniLearn=new JNILearn();
        jniLearn.say();

        operaChapter3();
    }

    /**
     * 第三章的主要代码
     */
    private void operaChapter3(){
        JNILearn2and3 jni2and3=new JNILearn2and3();
        jni2and3.dataType();
        Log.e("VACK","JAVA SAY: "+ jni2and3.newJAVAString());
        jni2and3.java2CString("JAVA String to C String");
        int[] temp=jni2and3.operaArray123();
        for (int i = 0; i < temp.length; i++) {
            Log.e("VACK", String.format("JAVA Say array[%d]=%d",i,temp[i]));
        }
        int[] arr={789,461,561,56,1,6,415};
        jni2and3.operaArray4(arr);

        jni2and3.createBuffer();
        ByteBuffer bb=ByteBuffer.allocate(1024);
        jni2and3.getBuffer(bb);

        jni2and3.useField();
        jni2and3.useJavaMethod();
    }
}
