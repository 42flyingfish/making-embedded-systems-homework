#include "pico/stdlib.h"
#include "console.h"

int main() {
    //stdio_init_all();
    /*
     * Sets up default urart
     * TX on GPIO 0
     * RX on GPIO 1
     * UART 0
     * baudrate 115200
     */

    setup_default_uart();
    ConsoleInit();

    while (true) {
	    ConsoleProcess();
	    //uart_puts(uart0, "What is this nonsense\n\r");
	    sleep_ms(2);
    }
}
