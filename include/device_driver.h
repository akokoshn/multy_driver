//
// Created by akokoshn on 5/28/2022.
//

#ifndef CROSSFITTIMER_DEVICE_DRIVER_H

#include <string>
#include <vector>

struct DeviceDescriptor {
std::string name;
};

std::vector<DeviceDescriptor> getDevices();
int sparing(const std::string &name);
int getHR();

#define CROSSFITTIMER_DEVICE_DRIVER_H

#endif //CROSSFITTIMER_DEVICE_DRIVER_H
