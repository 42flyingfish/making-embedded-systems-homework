cmake_minimum_required(VERSION 3.13)
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(blinky_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(blinky
	blinky.c
)
pico_add_extra_outputs(blinky)
target_link_libraries(blinky pico_stdlib)
