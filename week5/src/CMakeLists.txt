cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(console_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(console
	main.c
	console.h
	console.c
	consoleIo.h
	consoleIo.c
	consoleCommands.h
	consoleCommands.c
	version.h
)
pico_add_extra_outputs(console)
target_link_libraries(console pico_stdlib)

# enable uart output and disable usb output
pico_enable_stdio_usb(console 0)
pico_enable_stdio_uart(console 1)
