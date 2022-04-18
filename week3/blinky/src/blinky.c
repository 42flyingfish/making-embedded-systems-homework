#include "pico/stdlib.h"

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void button_callback(uint gpio, uint32_t events);

int main() {

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // I am using GPIO pin 15 for the push button. This can be changed
    const uint PUSHBUTTON_PIN = 15;
    gpio_init(PUSHBUTTON_PIN);
    gpio_set_dir(PUSHBUTTON_PIN, GPIO_IN);
    gpio_pull_up(PUSHBUTTON_PIN);

    // I am initializing with the led off
    gpio_put(LED_PIN, false);


    gpio_set_irq_enabled_with_callback(PUSHBUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);


    while (true) {}
}

void button_callback(uint gpio, uint32_t events) {
    gpio_xor_mask(1 << LED_PIN);
}