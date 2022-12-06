//
// Created by akokoshn on 6/12/2022.
//

#include <string>

#include "device_manager.h"

DeviceManager::DeviceManager()
{
	device = std::make_shared<Device>();
}

std::vector<DeviceDescriptor> DeviceManager::findDevices()
{
	return descriptors;
}

int DeviceManager::sparing(const DeviceDescriptor& descriptor)
{
	return -1;
}

std::shared_ptr<Device> DeviceManager::getDevice() const
{
	return device;
}