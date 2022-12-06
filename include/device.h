//
// Created by akokoshn on 6/12/2022.
//

#ifndef DEVICE_H
#define DEVICE_H

#include <string>

#include "internal_types.h"

class Device
{
	ConnectionType connectionType;
	std::string name;
	Capabilities capabilities;
	bool isConnected;
	DeviceData data;
public:
	Device();
	virtual int Init(const DeviceDescriptor& descriptor);
	virtual bool checkConnection() const;
	std::string getName() const;
	ConnectionType getConnectionType() const;
	Capabilities getCapabilities() const;
	DeviceData getData() const;
};

#endif //DEVICE_H
