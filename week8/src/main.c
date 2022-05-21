#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"


#define UART_NUM uart0
#define UART_TX 0
#define UART_RX 1
#define BAUD 115200

extern uint __bss_start__;
extern uint __bss_end__;
extern uint __HeapLimit;
extern uint __end__;
extern uint __stack;
extern uint __StackLimit;
extern uint __data_start__;
extern uint __data_end__;

uint32_t aGlobal;
uint32_t aGlobalInit = 42;

void printVariableInFunction(void);
void printStatic(void);

int main() {

	stdio_uart_init();

	while(true) {
		printf("Uninitialized global variable: 0x%p\n", &aGlobal);
		printf("Initialized global variable: 0x%p\n", &aGlobalInit);
		printVariableInFunction();
		printStatic();
		puts("");
		printf(".data start 0x%p\n", &__data_start__);
		printf(".data end 0x%p\n", &__data_start__);
		puts("");
		printf(".bss start 0x%p\n", &__bss_start__);
		printf(".bss end 0x%p\n", &__bss_end__);
		sleep_ms(5000);
	}

}

void printVariableInFunction(void) {
	uint32_t variable;
	printf("Non-static variable in function: 0x%p\n", &variable);
}

void printStatic(void) {
	static uint32_t variable;
	printf("Static variable in a function: 0x%p\n", &variable);
}
