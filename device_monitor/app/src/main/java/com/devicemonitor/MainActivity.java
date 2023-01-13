package com.devicemonitor;

import androidx.appcompat.app.AppCompatActivity;

import android.Manifest;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Button;
import android.content.pm.PackageManager;
import android.app.Activity;
import org.qtproject.qt5.android.*;
import dalvik.system.DexClassLoader;

import android.util.Log;

public class MainActivity extends AppCompatActivity {

    TextView msgView;
    ListView devicesListView;
    Button runButton;
    boolean isSearching;

    final String[] perms = {Manifest.permission.BLUETOOTH_SCAN,
                            Manifest.permission.BLUETOOTH_CONNECT,
                            "android.bluetooth.adapter.action.REQUEST_DISCOVERABLE"};

    int permsRequestCode = 200;

    public void loadApplication()
    {
        DexClassLoader classLoader = new DexClassLoader("/data/app", // .jar/.apk files
                "/tmp", // directory where optimized DEX files should be written.
                null, getClass().getClassLoader()); // parent loader
        QtNative.setClassLoader(classLoader);
    }

    private boolean hasPermission(String permission) {
        if (checkCallingOrSelfPermission(permission) != PackageManager.PERMISSION_GRANTED) {
            String[] perm = {permission};
            requestPermissions(perm, permsRequestCode);
            Log.i("DEBUG", "request permissions " +  permission);
            if (checkCallingOrSelfPermission(permission) != PackageManager.PERMISSION_GRANTED) {
                Log.d("PERMISSIONS", "Permission is not granted: " + permission);
                return true;//false;
            }
        }
        Log.d("PERMISSIONS", "Permission already granted: " + permission);
        return true;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        loadApplication();
        System.loadLibrary("device_driver");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        msgView = (TextView) findViewById(R.id.MSG);
        devicesListView = (ListView) findViewById(R.id.deviceList);
        runButton = (Button) findViewById(R.id.button);
        isSearching = false;
    }

    @Override
    public void onResume() {
        super.onResume();
    }

    @Override
    public void onPause () {
        super.onPause();
    }

    public void addDevice(String name) {
        TextView deviceName = new TextView(getApplicationContext());
        deviceName.setText(name);
        devicesListView.addFooterView(deviceName);
    }

    public void run(View view) {
        if (hasPermission(Manifest.permission.BLUETOOTH_SCAN)) {
            Log.i("DEBUG", "permissions granted");
            String res = getDevices();
            String[] devices = res.split("\n");

            for (String device : devices) {
                Log.i("DEBUG", "DEVICE = " + device);
                if (!device.isEmpty()) {
                    addDevice(device);
                }
            }
            msgView.setText("SEARCHING");
        } else {
            Log.e("DEBUG", "No BLUETOOTH required permissions");
        }
    }

    /*static {
        System.loadLibrary("device_driver");
    }*/
    public native String getDevices();
}
