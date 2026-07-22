#include <stdio.h>
#include <pico/stdlib.h>
#include <hardware/uart.h>
#include "UART_bitBang_Functions.h"
#include "string.h"

#define UART_ID uart0
#define BAUDRATE 9600     //for 9600 baud, each bit period is 104 microseconds
#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY UART_PARITY_NONE

#define UART_TX_PIN 0
#define UART_RX_PIN 1


int main(void) {

    // uart_init(UART_ID, BAUDRATE); //initialize the uart
    //
    // gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);  //set the function of the gpio pin!
    // gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    // /*
    //  * Note above...
    //  * 1) The gpio_set_function() takes a gpio pin number and then a function. the "GPIO_FUNC_UART" is
    //  * an enum! IE it's a constant value that has been assigned to a "wordy" variable. Makes it easier
    //  * as the programmer does not need to remember the specific value.
    //  * 2) Rather than "GPIO_FUNC_UART" you can also use "UART_FUNCSEL_NUM" which is a macro that
    //  * takes inputs of (uart, gpio) and returns the correct function based on platform and pin number.
    //  * According to uart.h:170-183 (where the function is defined - when using rp2040 it will always
    //  * default to the "GPIO_FUNC_UART" function, so it would be useless in our case.
    //  */
    //
    // // Set our data format
    // uart_set_format(UART_ID, DATA_BITS, STOP_BITS, PARITY);
    //
    // // Turn off FIFO's - we want to do this character by character
    // uart_set_fifo_enabled(UART_ID, false);
    stdio_init_all();
    gpio_init(UART_TX_PIN);
    gpio_set_dir(UART_TX_PIN, GPIO_OUT);
    gpio_put(UART_TX_PIN, 1);

    // while (true) {
    //     gpio_put(UART_TX_PIN, 0);
    //     sleep_ms(1000);
    //     gpio_put(UART_TX_PIN, 1);
    //     sleep_ms(1000);
    // }

    while (true) {
        sendMessage(UART_TX_PIN, "Hello World");
        sleep_ms(500);
    }




}
