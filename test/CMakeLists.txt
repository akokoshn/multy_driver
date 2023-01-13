cmake_minimum_required(VERSION 3.14)

project(device_driver_test)

set(TEST_SOURCE_FILES
    ${CMAKE_CURRENT_LIST_DIR}/test_app.cpp
)

add_executable(test ${TEST_SOURCE_FILES})

target_include_directories(test PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/../include
)

target_link_directories(test PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../lib)

target_link_libraries(test PRIVATE
    device_driver
    log
)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR})
install(TARGETS test DESTINATION bin)
