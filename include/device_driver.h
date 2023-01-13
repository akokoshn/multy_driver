//
// Created by akokoshn on 5/28/2022.
//

#ifndef DEVICE_DRIVER_H
#define DEVICE_DRIVER_H

#include <string>
#include <vector>

#include "internal_types.h"

std::vector<DeviceDescriptor> getDevices();
int sparing(const std::string& name);
bool isConnected();
DeviceData getData();

#include "android.h"

/*JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    LOGI("OnLoad: vm = %p\n", vm);
    return JNI_VERSION_1_6;
}*/

extern "C" JNIEXPORT jstring JNICALL
Java_com_devicemonitor_MainActivity_getDevices(JNIEnv* env,
    jobject instance)
{
    LOGI("getDevices: env = %p\n", env);
    std::vector<DeviceDescriptor> devices = getDevices();
    std::string res = "Names: ";
    for (const auto& it : devices) {
        res += it.name;
    }
    return env->NewStringUTF(res.c_str());
}

#define DEVICE_DRIVER_H

#endif //CROSSFITTIMER_DEVICE_DRIVER_H
