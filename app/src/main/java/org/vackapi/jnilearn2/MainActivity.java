package org.vackapi.jnilearn2;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        JNILearn jniLearn=new JNILearn();
        jniLearn.say();
        new JNILearn2and3().dataType();
    }
}
