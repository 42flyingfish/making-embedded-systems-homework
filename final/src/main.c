#include "pico/stdlib.h"
#include "console.h"

int main() {

    ConsoleInit();

    while (true) {
	    ConsoleProcess();
	    //uart_puts(uart0, "What is this nonsense\n\r");
	    sleep_ms(2);
    }
}
