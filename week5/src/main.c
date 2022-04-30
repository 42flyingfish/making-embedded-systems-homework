#include "pico/stdlib.h"

int main() {
    stdio_init_all();

    while (true) {
	    puts("Hello world");
	    sleep_ms(5000);
    }
}
