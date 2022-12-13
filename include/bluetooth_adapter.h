//
// Created by akokoshn on 12/12/2022.
//

#ifndef BLUETOOTH_ADAPTER_H
#define BLUETOOTH_ADAPTER_H

#include "adapter.h"

class BluetoothAdapter
{
public:
	virtual std::vector<DeviceDescriptor> findDevices();
	virtual ~BluetoothAdapter();
};

#endif //BLUETOOTH_ADAPTER_H
