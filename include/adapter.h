//
// Created by akokoshn on 12/12/2022.
//

#ifndef ADAPTER_H
#define ADAPTER_H

#include "internal_types.h"

class Adapter
{
public:
	virtual bool findDevices(std::vector<DeviceDescriptor>& deviceDescriptors) = 0;
	virtual ~Adapter() = 0;
};

#endif //ADAPTER_H
