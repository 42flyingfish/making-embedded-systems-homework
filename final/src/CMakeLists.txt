cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(console_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(final
	main.c
)

add_subdirectory(st7789)
add_subdirectory(drawing)
target_link_libraries(Drawing INTERFACE pico_st7789)

add_subdirectory(console)
target_link_libraries(Console PRIVATE pico_stdlib Drawing)




pico_add_extra_outputs(final)
target_link_libraries(final PRIVATE Console pico_stdlib pico_st7789 Drawing hardware_adc)

# enable uart output and disable usb output
pico_enable_stdio_usb(final 0)
pico_enable_stdio_uart(final 1)
