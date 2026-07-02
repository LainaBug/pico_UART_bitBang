cmake_minimum_required(VERSION 4.2)

include(pico_sdk_import.cmake)

set(PICO_BOARD pico)

project(pico_UART_bitBang C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(pico_UART_bitBang
        main.c)

target_link_libraries(pico_UART_bitBang pico_stdlib)
pico_add_extra_outputs(pico_UART_bitBang)