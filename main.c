#include <pico/stdlib.h>
#include "UART_bitBang_Functions.h"
#include "string.h"

#define DATA_PIN 0

int main(void) {
    stdio_init_all();
    gpio_init(DATA_PIN);
    gpio_set_dir(DATA_PIN, GPIO_OUT);
    gpio_put(DATA_PIN, 1);

    while (true) {
        sendMessage(DATA_PIN, "Hello World");
        sleep_ms(500);
    }
}
