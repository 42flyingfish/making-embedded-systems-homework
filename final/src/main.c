#include "pico/stdlib.h"
#include "console/console.h"
#include "pico/st7789.h"


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

    ConsoleInit();
    st7789_init(&lcd_config, lcd_width, lcd_height);
    st7789_fill(0xf0ff);



    while (true) {
	    ConsoleProcess();
	    sleep_ms(2);
    }
}
