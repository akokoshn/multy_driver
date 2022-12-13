package bluetoothhelper;

import android.os.Build;

import androidx.annotation.Keep;
import android.util.Log;
import java.util.ArrayList;
import java.util.Set;

import android.content.Context;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothManager;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Intent;
import android.content.IntentFilter;

import com.devicemonitor.MainActivity;

public class BluethoothHelper {

    private final String TAG = "BluethoothHelper";
    private final static int REQUEST_ENABLE_BT = 1;

    private BluetoothAdapter mBTAdapter;
    private Set<BluetoothDevice> mPairedDevices;
    private static ArrayList<String> mBTArrayAdapter;

    final BroadcastReceiver blReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            if (BluetoothDevice.ACTION_FOUND.equals(action)) {
                //BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
                //mBTArrayAdapter.add(device.getName() + " : " + device.getAddress());
                //Log.i(TAG, "Found: " + device.getName() + " : " + device.getAddress());
                Log.i(TAG, "Found: ");
            }
        }
    };

    public BluethoothHelper() {
        Context context = MainActivity.getContext();
        BluetoothManager bluetoothManager = (BluetoothManager)context.getSystemService(Context.BLUETOOTH_SERVICE);
        mBTAdapter = bluetoothManager.getAdapter();
        if (mBTAdapter == null) {
            Log.e(TAG, "Bluetooth not supported on device");
        }
        mBTArrayAdapter = new ArrayList<String>();
        bluetoothOn();
    }

    private void bluetoothOn() {
        if (!mBTAdapter.isEnabled()) {
            Log.e(TAG, "Bluetooth not enabled");
            //Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            //startActivityForResult(enableBtIntent, REQUEST_ENABLE_BT);
        }
        Log.i(TAG, "Bluetooth enable deprecated");
    }

    private void bluetoothOff() {
        //mBTAdapter.disable();
        Log.i(TAG, "Bluetooth disable deprecated");
    }

    public void discover(){
        // Check if the device is already discovering
        Log.i(TAG, "start discover");
        if(mBTAdapter.isDiscovering()){
            mBTAdapter.cancelDiscovery();
        }
        if(mBTAdapter.isEnabled()) {
            mBTArrayAdapter.clear();
            /*int requestCode = 1;
            Intent discoverableIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE);
            //discoverableIntent.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, 300);
            startActivityForResult(discoverableIntent, requestCode);*/
            boolean is_discovering = mBTAdapter.startDiscovery();
            Log.i(TAG, String.valueOf(is_discovering));
            Context context = MainActivity.getContext();
            context.registerReceiver(blReceiver, new IntentFilter(BluetoothDevice.ACTION_FOUND));
        } else {
            Log.e(TAG, "Bluetooth adapter not enabled");
        }
        for (int i = 0; i < mBTArrayAdapter.size(); i++) {
            Log.i(TAG, mBTArrayAdapter.get(i));
        }
    }

    protected void onDestroy() {
        Context context = MainActivity.getContext();
        context.unregisterReceiver(blReceiver);
    }

    @Keep
    static public String getBuildVersion() {
        return Build.VERSION.RELEASE;
    }

    @Keep
    static public String getDevices() {
        return "";
    }
}