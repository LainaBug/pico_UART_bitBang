#include <pico/stdlib.h>
#include "uartResources.h"
#include "string.h"

#define DATA_PIN 0
#define BIT_PERIOD 104

int main(void) {
    // Initializations
    stdio_init_all();
    gpio_init(DATA_PIN);
    gpio_set_dir(DATA_PIN, GPIO_OUT);
    gpio_put(DATA_PIN, 1);

    // prep data to be sent thru uart
    struct uartData* data = uartDataInit(BIT_PERIOD, DATA_PIN, "Laina is Awesome! :)");

    while (true) {
        sendMessage(data);
        sleep_ms(500);
    }
}
