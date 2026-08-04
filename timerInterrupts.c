#include "pico/stdlib.h"
#include "pico/time.h"

#include "timerInterrupts.h"

#include <stdio.h>

#include "uartResources.h"


//The following function will be called every bit period
bool interruptHandler(repeating_timer_t *repeatingTimer) {
    int *ID = repeatingTimer->user_data;
    switch (*ID) {
        case UART_TIMER_ID:
            /* case where the UART timer has occurred -
             * IF the UART state is "ready" or "transmitting".
             */
            if (data.state == UART_READY || data.state == UART_TRANSMITTING) {
                data.state = UART_TRANSMITTING;
                sendNextBit(&data);
            }
            break;
        case IDLE_TIMER_ID:
            /* case where the Idle Timer has occurred -
             * indicates that the message should be sent via UART again IE uart state is "ready"
             */
            data.state = UART_READY;
            break;
        default: break;
    }
    //sets flag when transmission is finished!
    return true; //returning true is necessary for the timer to continue repeating...
}
