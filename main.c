#include "pico/stdlib.h"
#include "uartResources.h"
#include "string.h"
#include "pico/cyw43_arch.h"

#define DATA_PIN 0
#define BIT_PERIOD 104

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


    // prep data to be sent thru uart
    struct uartData* data = uartDataInit(BIT_PERIOD, DATA_PIN, "Laina is Awesome! :)");

    while (true) {
        sendMessage(data);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(250);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(250);
    }
}
