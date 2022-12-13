package com.devicemonitor;

import androidx.annotation.Keep;
import androidx.appcompat.app.AppCompatActivity;

import android.Manifest;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Button;
import android.content.pm.PackageManager;

import bluetoothhelper.BluethoothHelper;
import android.content.Intent;
import android.bluetooth.BluetoothAdapter;

import java.util.ArrayList;
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

    private static Context instance_context;

    public static Context getContext(){
        return instance_context;
    }

    private boolean hasPermission(String permission) {
        if (checkCallingOrSelfPermission(permission) != PackageManager.PERMISSION_GRANTED) {
                    Log.d("PERMISSIONS", "Permission is not granted: " + permission);
                    return false;
        }
        Log.d("PERMISSIONS", "Permission already granted: " + permission);
        return true;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        msgView = (TextView) findViewById(R.id.MSG);
        devicesListView = (ListView) findViewById(R.id.deviceList);
        runButton = (Button) findViewById(R.id.button);
        isSearching = false;

        instance_context = getApplicationContext();

        requestPermissions(perms, permsRequestCode);
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
        TextView deviceName = new TextView(instance_context);
        deviceName.setText(name);
        devicesListView.addFooterView(deviceName);
    }

    public void run(View view) {
        if (isSearching) {
            String res = getDevices();
            String[] devices = res.split("\n");

            for (String device : devices) {
                Log.i("DEBUG", "DEVICE = " + device);
                if (!device.isEmpty()) {
                    addDevice(device);
                }
            }
            return;
        }
        if (hasPermission(Manifest.permission.BLUETOOTH_SCAN)/* && hasPermission(Manifest.permission.BLUETOOTH_ADVERTISE)*/) {
            Log.i("DEBUG", "permissions granted");
            int requestCode = 1;
            Intent discoverableIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE);
            discoverableIntent.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, 300);
            startActivityForResult(discoverableIntent, requestCode);
            BluethoothHelper helper = new BluethoothHelper();
            helper.discover();
            isSearching = true;
            msgView.setText("SEARCHING");
        } else {
            Log.e("DEBUG", "No BLUETOOTH required permissions");
        }
    }

    static {
        System.loadLibrary("device_driver");
    }
    public native String getDevices();
}
