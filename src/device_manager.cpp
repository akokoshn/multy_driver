//
// Created by akokoshn on 6/12/2022.
//

#include <string>

#include "device_manager.h"
#include "bluetooth_adapter.h"

DeviceManager* DeviceManager::instance = NULL;

DeviceManager::DeviceManager()
{
	device = std::make_shared<Device>();
	adapter = std::shared_ptr<Adapter>((Adapter*)(new BluetoothAdapter()));
}

DeviceManager* DeviceManager::getInstance()
{
	if (!instance) {
		instance = new DeviceManager();
	}
	return instance;
}

std::vector<DeviceDescriptor> DeviceManager::findDevices()
{
	descriptors = adapter->findDevices();
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