#include "pico/stdlib.h"
#include "console/console.h"

int main() {

    ConsoleInit();

    while (true) {
	    ConsoleProcess();
	    sleep_ms(2);
    }
}
