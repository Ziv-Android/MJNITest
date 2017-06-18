package com.ziv.jnitest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.ziv.jni.collection.HelloJni;
import com.ziv.memory.MemoryTestAPI;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    private static final String TAG = MainActivity.class.getSimpleName();
    private TextView jniText;
    private Button jniErrorBtn;
    private Button jniArrayBtn;
    private Button jniInnerClassBtn;
    private MemoryTestAPI memoryTestAPI;
    private HelloJni helloJni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        initView();
        initSDK();
    }

    private void initView() {
        jniText = (TextView) findViewById(R.id.jni_text);
        jniText.setOnClickListener(this);
        jniErrorBtn = (Button) findViewById(R.id.jni_error);
        jniArrayBtn = (Button) findViewById(R.id.jni_array);
        jniInnerClassBtn = (Button) findViewById(R.id.jni_inner_class);
        jniErrorBtn.setOnClickListener(this);
        jniArrayBtn.setOnClickListener(this);
        jniInnerClassBtn.setOnClickListener(this);
    }

    private void initSDK() {
        memoryTestAPI = new MemoryTestAPI();
        helloJni = new HelloJni();
    }

    @Override
    public void onClick(View v) {
        int id = v.getId();
        switch (id) {
            case R.id.jni_text:
                jniText.setText(helloJni.getAJNIString());
                break;
            case R.id.jni_array:
                int[][] twoArray = helloJni.getTwoArray(3, 4);
                Log.e(TAG, "length = " + twoArray.length);
                Log.e(TAG, "twoArray[2][2] = " + twoArray[2][2]);
                break;
            case R.id.jni_error:
                memoryTestAPI.valgrindTest();
                break;
            case R.id.jni_inner_class:
                HelloJni.Name name = helloJni.new Name();
                name.setNewName();
                Log.e(TAG, "New name is " + name.getNewName());
            default:
                break;
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        Log.e(TAG, "onCreateOptionsMenu");
        getMenuInflater().inflate(R.menu.menu_main, menu);
        MenuItem item = menu.findItem(R.id.connect);
        if (item != null) {
            int itemId = item.getItemId();
            Log.e(TAG, "onCreateOptionsMenu item connect id is " + itemId);
        } else {
            Log.e(TAG, "onCreateOptionsMenu item get failed!");
        }
        return true;
    }

    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
        Log.e(TAG, "onPrepareOptionsMenu");
        return super.onPrepareOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        Log.e(TAG, "onOptionsItemSelected");
        switch (item.getItemId()) {
            case R.id.connect:
                Toast.makeText(getApplicationContext(), "连接……", Toast.LENGTH_SHORT).show();
                return true;
            case R.id.disconnect:
                Toast.makeText(getApplicationContext(), "断开……", Toast.LENGTH_SHORT).show();
                return true;
            case R.id.search:
                Toast.makeText(getApplicationContext(), "搜索……", Toast.LENGTH_SHORT).show();
                return true;
            case R.id.view:
                Toast.makeText(getApplicationContext(), "查看……", Toast.LENGTH_SHORT).show();
                return true;
            case R.id.help:
                Toast.makeText(getApplicationContext(), "帮助……", Toast.LENGTH_SHORT).show();
                return true;
            case R.id.exit:
                Toast.makeText(getApplicationContext(), "退出……", Toast.LENGTH_SHORT).show();
                return true;
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onOptionsMenuClosed(Menu menu) {
        Log.e(TAG, "onOptionsMenuClosed");
        super.onOptionsMenuClosed(menu);
    }
}
