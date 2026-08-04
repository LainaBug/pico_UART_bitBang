#ifndef PICO_UART_BITBANG_TIMERINTERRUPTS_H
#define PICO_UART_BITBANG_TIMERINTERRUPTS_H

#endif //PICO_UART_BITBANG_TIMERINTERRUPTS_H

#define UART_DONE 0
#define UART_READY 1
#define UART_TRANSMITTING 2

#define UART_TIMER_ID 10
#define IDLE_TIMER_ID 20

bool interruptHandler(repeating_timer_t *repeatingTimer);
