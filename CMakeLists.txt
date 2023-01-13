cmake_minimum_required(VERSION 3.14)

#set(CMAKE_MAKE_PROGRAM $ENV{NINJA_PATH}/ninja)
set(CMAKE_TOOLCHAIN_FILE $ENV{ANDROID_NDK_ROOT}/build/cmake/android.toolchain.cmake)
set(ANDROID_ABI arm64-v8a)#x86_64
set(ANDROID_PLATFORM android-33)
set(ANDROID_STL c++_static)

#set(CMAKE_PREFIX_PATH ${QT_DIR}/qtbase/bin/install/lib/cmake/Qt5)

#find_package(QT NAMES Qt6 Qt5 COMPONENTS Bluetooth REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Bluetooth REQUIRED)
#message("Qt5_FOUND = ${Qt5_FOUND}")
#message("Qt5_NOT_FOUND_MESSAGE = ${Qt5_NOT_FOUND_MESSAGE}")

project(device_driver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
    ${CMAKE_CURRENT_LIST_DIR}/src/device_driver.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/device.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/device_manager.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/bluetooth_adapter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/bluetooth_adapter_native_android.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/qt_bluetooth_server.cpp
)

add_library(device_driver SHARED ${SOURCE_FILES})

target_include_directories(device_driver PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${QT_DIR}/qtbase/bin/install/include
    ${QT_DIR}/qtbase/bin/install/include/QtCore
    ${QT_DIR}/qtbase/bin/install/include/QtCore/5.15.8
    ${QT_DIR}/qtbase/bin/install/include/QtCore/5.15.8/QtCore/private
)

target_link_directories(device_driver PRIVATE
    ${QT_DIR}/qtbase/bin/install/lib
)

target_link_libraries(device_driver PRIVATE
    libQt5Bluetooth_arm64-v8a.a
    libQt5Core_arm64-v8a.a
    libQt5AndroidExtras_arm64-v8a.a
    libqtpcre2_arm64-v8a.a
    log
    z
)

target_compile_definitions(device_driver PRIVATE DEVICE_DRIVER_LIBRARY)


set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR})
install(TARGETS device_driver DESTINATION lib)

option(BUILD_TEST_APP "Build the test application" ON)
if(BUILD_TEST_APP)
    add_subdirectory(test)
endif()