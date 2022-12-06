//
// Created by akokoshn on 5/28/2022.
//

#ifndef CROSSFITTIMER_DEVICE_DRIVER_H

#include <string>
#include <vector>

#include "internal_types.h"

std::vector<DeviceDescriptor> getDevices();
int sparing(const std::string &name);
bool isConnected();
DeviceData getData();

#define CROSSFITTIMER_DEVICE_DRIVER_H

#endif //CROSSFITTIMER_DEVICE_DRIVER_H
