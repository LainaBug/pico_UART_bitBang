#include <pico/stdlib.h>
#include "string.h"

#include "uartResources.h"

#include <stdio.h>


bool sendBit(const int dataPin, const int8_t byte) { // bitIndex should only go from 0-9
    const uint16_t mask1 = 512;
    const uint16_t mask2 = 1;
    static int bitIndex = 0;
    const uint16_t byte16 = (uint16_t) byte;
    const uint16_t updatedData =(byte16 << 1) | mask1;
    bool data_bit = (updatedData >> bitIndex) & mask2;
    gpio_put(dataPin, data_bit);
    //printf("%d\n",data_bit);
    if (bitIndex < 9) {
       (bitIndex)++;
        return false;
    }
    bitIndex = 0;
    //printf("Starting Next Byte...\n");
    return true;
}

void sendNextBit(const uartData *userData) {
    const uint8_t *messageDecimal = (uint8_t *) userData->message; // the (uint8_t) is a "cast" and turns the message char into uint8_t data type!
    static int byteIndex = 0;
    if (sendBit(userData->dataPin, messageDecimal[byteIndex])) {
        byteIndex++;
    }
    if (byteIndex == strlen(userData->message)) {
        byteIndex = 0;
        //printf("-----Restarting Message!----------------\n\n\n");
    }
}

void gpioToggleTest(const uartData *userData) {
    gpio_xor_mask(1ul << userData->dataPin);
}