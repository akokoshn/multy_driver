cmake_minimum_required(VERSION 3.14)

project(device_driver)

set(SOURCE_FILES
    ${CMAKE_CURRENT_LIST_DIR}/src/device_driver.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/device.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/device_manager.cpp
)

add_library(device_driver SHARED ${SOURCE_FILES})

target_include_directories(device_driver PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR})
install(TARGETS device_driver DESTINATION lib)

option(BUILD_TEST_APP "Build the test application" ON)
if(BUILD_TEST_APP)
    add_subdirectory(test)
endif()
