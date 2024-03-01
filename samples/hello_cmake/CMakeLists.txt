cmake_minimum_required(VERSION 3.0)

if(DEFINED ENV{PS5_PAYLOAD_SDK})
  set(CMAKE_TOOLCHAIN_FILE $ENV{PS5_PAYLOAD_SDK}/cmake/toolchain.cmake)
else()
  message(FATAL_ERROR "PS5_PAYLOAD_SDK is undefined")
endif()

project(hello_cmake C)
add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} kernel_web)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.elf")
