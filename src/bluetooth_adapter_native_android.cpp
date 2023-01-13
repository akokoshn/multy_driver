//
// Created by akokoshn on 12/12/2022.
//

#include "bluetooth_adapter.h"
#include "android.h"

#include <thread>
#include <chrono>

bool BluetoothAdapterNativeAndroid::findDevices(std::vector<DeviceDescriptor>& deviceDescriptors)
{
    bluetoothServer.startSearching(&deviceDescriptors);

    while(true) {
        LOGI("WAIT");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    bluetoothServer.stopSearching();


    return true;
}

BluetoothAdapterNativeAndroid::~BluetoothAdapterNativeAndroid()
{

}
