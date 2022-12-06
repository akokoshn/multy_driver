//
// Created by akokoshn on 6/12/2022.
//

#ifndef INTERNAL_TYPES_H
#define INTERNAL_TYPES_H

#include <string>
#include <vector>

typedef enum {
	BLUETOOTH,
	ANT
} ConnectionType;

struct Capabilities {
	bool HRSupport;
};

struct DeviceDescriptor {
	std::string name;
	ConnectionType type;
	Capabilities cpabilities;
};

struct DeviceData {
	unsigned int HR;
};

#endif //INTERNAL_TYPES_H
