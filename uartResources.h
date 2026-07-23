#ifndef PICO_UART_BITBANG_UART_BITBANG_FUNCTIONS_H
#define PICO_UART_BITBANG_UART_BITBANG_FUNCTIONS_H
#endif //PICO_UART_BITBANG_UART_BITBANG_FUNCTIONS_H

//declare the uartData struct
struct uartData {
    int bitPeriod;
    int dataPin;
    int messageLength;
    int structSize;
    char message[]; //note that flexible arrays declared in a struct should be put at the end!
};

// Function that allocates memory and initializes the uartData struct for the user
struct uartData* uartDataInit(int bitPeriod, int dataPin, char message[]);
/* In the above "uartData*" is a pointer to a uartData struct...
 */

// Function that sends a byte of data to the uart data pin
void sendByte(int bitPeriod, int dataPin, int8_t data);

// Function that sends a message to the uart data pin
void sendMessage(struct uartData *data);

