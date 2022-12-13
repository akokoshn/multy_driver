//
// Created by akokoshn on 12/12/2022.
//

#include "bluetooth_adapter.h"
#include "java_helper.h"

std::vector<DeviceDescriptor> BluetoothAdapter::findDevices()
{
    printf("findDevices\n");
    return JavaHelper::findDevices();
}

BluetoothAdapter::~BluetoothAdapter()
{

}