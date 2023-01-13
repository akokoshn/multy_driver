//
// Created by akokoshn on 12/12/2022.
//

#ifndef BLUETOOTH_ADAPTER_H
#define BLUETOOTH_ADAPTER_H

#include "adapter.h"
#include "qt_bluetooth_server.h"

class BluetoothAdapter
{
public:
    virtual bool findDevices(std::vector<DeviceDescriptor>& deviceDescriptors);
	virtual ~BluetoothAdapter();
};

class BluetoothAdapterNativeAndroid
{
public:
    virtual bool findDevices(std::vector<DeviceDescriptor>& deviceDescriptors);
    virtual ~BluetoothAdapterNativeAndroid();
private:
    QtBluetoothServer bluetoothServer;
};

#endif //BLUETOOTH_ADAPTER_H
