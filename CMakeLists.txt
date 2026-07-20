cmake_minimum_required(VERSION 4.2)

set(PICO_BOARD pico_w)
include(pico_sdk_import.cmake)

project(pico_UART_bitBang C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(pico_UART_bitBang
        main.c
        UART_bitBang_Functions.h
        UART_BitBang_Functions.c)

target_link_libraries(pico_UART_bitBang pico_stdlib hardware_uart) # Necessary for the stdlib.h to work

pico_add_extra_outputs(pico_UART_bitBang) # Generates files such as .uf2 and others rather than just a .elf file when built


pico_enable_stdio_usb(pico_UART_bitBang 0) # Enables/Disables stdio(standard input/output) functions over usb
pico_enable_stdio_uart(pico_UART_bitBang 0) # Enables/Disables stdio functions over uart
