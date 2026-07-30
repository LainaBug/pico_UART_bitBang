#ifndef PICO_UART_BITBANG_UART_BITBANG_FUNCTIONS_H
#define PICO_UART_BITBANG_UART_BITBANG_FUNCTIONS_H
#endif //PICO_UART_BITBANG_UART_BITBANG_FUNCTIONS_H

//declare the uartData struct
typedef struct uartData {
    const int dataPin;
    const char* message;
} uartData;

extern uartData data;

// Function that sets the GPIO TX pin to high or low accordingly
bool sendBit(int dataPin, int8_t byte);

// Function to send the UART message, bit by bit
void sendNextBit(const uartData *userData);

void gpioToggleTest(const uartData *userData);