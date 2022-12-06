//
// Created by akokoshn on 6/12/2022.
//

#include "device.h"

Device::Device()
{}

int Device::Init(const DeviceDescriptor& descriptor)
{
	connectionType = descriptor.type;
	name = descriptor.name;
	isConnected = false;
	capabilities.HRSupport = true;
	return 0;
}

bool Device::checkConnection() const
{
	return isConnected;
}

std::string Device::getName() const
{
	return name;
}

ConnectionType Device::getConnectionType() const
{
	return connectionType;
}

Capabilities Device::getCapabilities() const
{
	return capabilities;
}

DeviceData Device::getData() const
{
	return data;
}