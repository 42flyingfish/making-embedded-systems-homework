cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(memory_fun C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(defaultLinker
	main.c
)

# Note that this is the default file copied from the PICO SDK.
# This is ultimately not needed
pico_set_linker_script(defaultLinker ${CMAKE_CURRENT_SOURCE_DIR}/memmap_default.ld)
pico_add_extra_outputs(defaultLinker)
target_link_libraries(defaultLinker pico_stdlib)

# enable uart output and disable usb output
pico_enable_stdio_usb(defaultLinker 0)
pico_enable_stdio_uart(defaultLinker 1)


add_executable(swappedLinker
	main.c
)

# Note this is the same as above but with the .data and .bss segments swapped
pico_set_linker_script(swappedLinker ${CMAKE_CURRENT_SOURCE_DIR}/swapped.ld)
pico_add_extra_outputs(swappedLinker)
target_link_libraries(swappedLinker pico_stdlib)

# enable uart output and disable usb output
pico_enable_stdio_usb(swappedLinker 0)
pico_enable_stdio_uart(swappedLinker 1)
