//
// Created by Laina Galayde on 7/15/26.
//

#ifndef PICO_UART_BITBANG_UART_BITBANG_FUNCTIONS_H
#define PICO_UART_BITBANG_UART_BITBANG_FUNCTIONS_H

#endif //PICO_UART_BITBANG_UART_BITBANG_FUNCTIONS_H

uint8_t asciiToDecimal(char ascii);
bool decimalToBinary(uint8_t decimal, bool binary);
void sendByte(int TX_PIN, uint8_t byte); //function declaration
