#include "pico/stdlib.h"
#include "pico/time.h"

#include "timerInterrupts.h"
#include "uartResources.h"


//The following function will be called every bit period
bool interruptHandler(repeating_timer_t *repeatingTimer) {
    sendNextBit(&data);
    //gpioToggleTest(&data);
    return true; //returning true is necessary for the timer to continue repeating...
}

