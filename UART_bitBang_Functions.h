#ifndef PICO_UART_BITBANG_UART_BITBANG_FUNCTIONS_H
#define PICO_UART_BITBANG_UART_BITBANG_FUNCTIONS_H
#endif //PICO_UART_BITBANG_UART_BITBANG_FUNCTIONS_H

void sendByte(int bitPeriod, int dataPin, uint8_t byte); //function declaration
void sendMessage(int bitPeriod,int dataPin, char* message); //function declaration

