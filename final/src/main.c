#include "hardware/adc.h"
#include "pico/stdlib.h"
#include "console/console.h"
#include "draw.h"
#include "hardware/adc.h"

enum States {Fill, NextColour, Default};

const uint PUSHBUTTON_PIN = 15;
enum States CurrentState = Default;
bool ignore = false;

static void callback(uint gpio,uint32_t events);

int main() {

    // Setting up ADC for joystick
    adc_init();
    adc_gpio_init(26);
    adc_gpio_init(27);


    // Setting up drawing and screen
    // Warning: The init function must be called before others
    drawInit();
    ConsoleInit();

    gpio_init(PUSHBUTTON_PIN);
    gpio_set_dir(PUSHBUTTON_PIN, GPIO_IN);
    gpio_pull_up(PUSHBUTTON_PIN);

    gpio_set_irq_enabled_with_callback(PUSHBUTTON_PIN,GPIO_IRQ_EDGE_FALL,true,&callback);



    while (true) {
        switch (CurrentState) {
        case Fill: {
            fillScreen();
            CurrentState = Default;
            break;
        }
        case NextColour: {
            nextColor();
            CurrentState = Fill;
            break;
        }
        case Default: {
            ignore = false;
            break;
        }
        default:{
            CurrentState = Default;
            break;
        }

        }
        ConsoleProcess();
        adc_select_input(0);
        uint adc_x_raw = adc_read();
        adc_select_input(1);
        uint adc_y_raw = adc_read();
        // directions
        if (adc_x_raw < 0xf70) {
            incrementCursorX();
            drawPixel();
        }
        if (adc_x_raw > 0x010) {
            decrementCursorX();
            drawPixel();
        }
        if (adc_y_raw > 0xfa0) {
            decrementCursorY();
            drawPixel();
        }
        if (adc_y_raw < 0x010) {
            incrementCursorY();
            drawPixel();
        }
        sleep_ms(2);
    }
}

static void callback(uint gpio,uint32_t events) {
    //gpio_set_irq_enabled_with_callback(PUSHBUTTON_PIN,GPIO_IRQ_EDGE_FALL,false,&callback);
    if (ignore) return;
    ignore = true;
    CurrentState = NextColour;

}
