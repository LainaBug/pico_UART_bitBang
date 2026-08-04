#include "pico/stdlib.h"
#include "string.h"
#include "pico/cyw43_arch.h"
#include "pico/time.h"

#include "uartResources.h"
#include "timerInterrupts.h"


#define DATA_PIN 0
#define BIT_PERIOD_US (-104)//-104
#define BLINK_TIME_MS 250
#define IDLE_PERIOD_MS 3000



repeating_timer_t interruptTimer;
int uartTimerID = UART_TIMER_ID;
repeating_timer_t idleTimer;
int idleTimerID = IDLE_TIMER_ID;


uartData data = {UART_READY, DATA_PIN,  "Hello World!"};



int main(void) {

    // Initializations
    stdio_init_all();
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed");
        return -1;
    }
    gpio_init(DATA_PIN);
    gpio_set_dir(DATA_PIN, GPIO_OUT);
    gpio_put(DATA_PIN, 1);

    add_repeating_timer_us(BIT_PERIOD_US, interruptHandler, &uartTimerID, &interruptTimer);
    add_repeating_timer_ms(IDLE_PERIOD_MS, interruptHandler, &idleTimerID, &idleTimer);


    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(BLINK_TIME_MS);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(BLINK_TIME_MS);
    }
}
