#include "hardware/adc.h"
#include "pico/stdlib.h"
#include "console/console.h"
#include "pico/st7789.h"
#include "draw.h"
#include "hardware/adc.h"


const struct st7789_config lcd_config = {
    .spi      = PICO_DEFAULT_SPI_INSTANCE,
    .gpio_din = PICO_DEFAULT_SPI_TX_PIN,
    .gpio_clk = PICO_DEFAULT_SPI_SCK_PIN,
    .gpio_cs  = PICO_DEFAULT_SPI_CSN_PIN,
    .gpio_dc  = 20,
    .gpio_rst = 21,
    .gpio_bl  = 22,
};

const int lcd_width = 240;
const int lcd_height = 320;

int main() {

    /* ADC info
    */
    adc_init();
    adc_gpio_init(26);
    adc_gpio_init(27);


    ConsoleInit();
    st7789_init(&lcd_config, lcd_width, lcd_height);
    st7789_fill(0xf800);



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
