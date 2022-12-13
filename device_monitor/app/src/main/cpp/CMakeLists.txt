cmake_minimum_required(VERSION 3.4.1)

project(“device_driver”)

add_library(device_driver SHARED IMPORTED)
set_target_properties (device_driver
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libdevice_driver.so)