//
// Created by akokoshn on 5/28/2022.
//

#include "device_driver.h"
#include "device_manager.h"

std::vector<DeviceDescriptor> getDevices()
{
    std::vector<DeviceDescriptor> list;
    list = DeviceManager::getInstance()->findDevices();
    return list;
}

int sparing(const std::string &name)
{
    return 0;
}

bool isConnected()
{
    return false;
}

DeviceData getData()
{
    DeviceData data;
    data.HR = 0;
    return data;
}
