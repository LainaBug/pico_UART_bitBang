#include <stdio.h>
#include <stdlib.h>
#include <pico/stdlib.h>
#include "string.h"
#include "uartResources.h"


// Function that allocates memory and initializes the uartData struct for the user - Reference: https://www.geeksforgeeks.org/c/flexible-array-members-structure-c/
struct uartData* uartDataInit(const int bitPeriod, const int dataPin, char message[]) {
    // Allocate memory for the struct and the flexible array member
    /* The following creates a pointer to a uartData struct named "data"-
     * malloc() will return a pointer to memory in the heap that is the desired size-
     * That memory will be accessible using "data" because it will store the pointer returned by malloc()-
     */
    struct uartData *data = malloc(sizeof(*data) + sizeof(char) * (strlen(message) + 1)); // +1 for null terminator
    if (data == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    /* The following assigns the variables passed to the uartDataInit function, to the
     * appropriate variables in the uartData pointer.
     */
    data->bitPeriod = bitPeriod;
    data->dataPin = dataPin;
    data->messageLength = strlen(message);
    strcpy(data->message, message); // Copy the message into the flexible array member
    data->structSize = sizeof(*data) + sizeof(char) * (strlen(data->message) + 1); // Assign size according to the size of message
    return data; //return the pointer to the uartData struct named "data" :)
}

void sendByte(int bitPeriod, int dataPin, int8_t data) {
    //set tx line low for one bit period (start bit!)
    gpio_put(dataPin, 0);
    sleep_us(bitPeriod);
    //send all 8 data bits at a time (each one bit period)
    for (int i = 0; i < 8; i++) {
        const uint8_t mask = 1;
        bool data_bit = (data >> i) & mask;
        gpio_put(dataPin, data_bit);
        sleep_us(bitPeriod);
    }
    //let the line be idle (high!) for a bit period (Stop bit!)
    gpio_put(dataPin, 1);
    sleep_us(bitPeriod);
}

/* sendMessage takes a pointer to a uartData struct - "pointer" can be loosely translated to "address...
* thus it is looking for a &var which would be the address of variable var.
*/
void sendMessage(struct uartData *data) {
    uint8_t *messageDecimal = (uint8_t *) data->message;
    for (int i = 0; i < strlen(messageDecimal); i++) {
        sendByte(data->bitPeriod, data->dataPin, messageDecimal[i]);
    }
}
