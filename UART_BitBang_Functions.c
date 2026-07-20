//
// Created by Laina Galayde on 7/15/26.
//

//This .c file is used to define all functions for uart bit banging

#include <stdio.h>
#include <pico/stdlib.h>
#include "string.h"

#define BITPERIOD 104

void sendByte(int TX_PIN, uint8_t byte) {

    //set tx line low for one bit period (start bit!)
    gpio_put(TX_PIN, 0);
    sleep_us(BITPERIOD);

    //send all 8 data bits at a time (each one bit period ~104 microseconds for 9.6k baud)
    for (int i = 0; i < 8; i++) {
        uint8_t mask = 1;
        bool data_bit = (byte >> i) & mask;
        gpio_put(TX_PIN, data_bit);
        sleep_us(BITPERIOD);
    }

    //let the line be idle (high!) for a bit period (Stop bit!)
    gpio_put(TX_PIN, 1);
    sleep_us(BITPERIOD);
}

