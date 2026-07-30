#include "pico/stdlib.h"
#include "string.h"
#include "pico/cyw43_arch.h"
#include "pico/time.h"

#include "uartResources.h"
#include "timerInterrupts.h"


#define DATA_PIN 0
#define BIT_PERIOD_US 104
#define BLINK_TIME_MS 250
#define PRINTF_TEST_PERIOD_MS 1000

repeating_timer_t interruptTimer;
uartData data = {DATA_PIN,  "hello!"};


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

    add_repeating_timer_ms(BIT_PERIOD_US, interruptHandler, NULL, &interruptTimer);

    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(BLINK_TIME_MS);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(BLINK_TIME_MS);
        // sendNextBit(&data);
        // sleep_us(BIT_PERIOD_US);
    }
}
