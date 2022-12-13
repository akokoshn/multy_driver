//
// Created by akokoshn on 6/12/2022.
//

#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <memory>

#include "adapter.h"
#include "device.h"

class DeviceManager
{
	std::vector<DeviceDescriptor> descriptors;
	std::shared_ptr<Adapter> adapter;
	std::shared_ptr<Device> device;
	static DeviceManager* instance;

	DeviceManager();
public:
	static DeviceManager* getInstance();
	std::vector<DeviceDescriptor> findDevices();
	int sparing(const DeviceDescriptor& descriptor);
	std::shared_ptr<Device> getDevice() const;
};

#endif //DEVICE_MANAGER_H
