#include "hardware/adc.h"
#include "pico/stdlib.h"
#include "console/console.h"
#include "draw.h"
#include "hardware/adc.h"




int main() {

    /* ADC info
    */
    adc_init();
    adc_gpio_init(26);
    adc_gpio_init(27);



    drawInit();
    ConsoleInit();



    while (true) {
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
