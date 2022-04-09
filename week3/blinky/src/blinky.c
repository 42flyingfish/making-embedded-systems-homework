#include "pico/stdlib.h"

const uint LED_PIN = PICO_DEFAULT_LED_PIN;
const uint PUSHBUTTON_PIN = 14;
volatile bool LED_STATE;

void button_callback(uint gpio, uint32_t events);

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(PUSHBUTTON_PIN);
    gpio_set_dir(PUSHBUTTON_PIN, GPIO_IN);
    gpio_pull_up(PUSHBUTTON_PIN);

    LED_STATE = false;
    gpio_put(LED_PIN, LED_STATE);


    gpio_set_irq_enabled_with_callback(PUSHBUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);


    while (true) {}
}

void button_callback(uint gpio, uint32_t events) {
    LED_STATE = !LED_STATE;
    gpio_put(LED_PIN, LED_STATE);
}