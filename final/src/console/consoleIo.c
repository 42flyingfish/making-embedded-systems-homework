// Console IO is a wrapper between the actual in and output and the console code
// In an embedded system, this might interface to a UART driver.

#include "consoleIo.h"
//#include <stdio.h>
#include "hardware/uart.h"
#include "pico/stdlib.h"

#define UART_NUM uart0
#define UART_TX 0
#define UART_RX 1
#define BAUD 115200

eConsoleError ConsoleIoInit(void)
{
	/*
	 * Sets up default urart
	 * TX on GPIO 0
	 * RX on GPIO 1
	 * UART 0
	 * baudrate 115200
	 */

	uart_init(UART_NUM, BAUD);
	gpio_set_function(UART_TX, GPIO_FUNC_UART);
	gpio_set_function(UART_RX, GPIO_FUNC_UART);
	return CONSOLE_SUCCESS;
}

eConsoleError ConsoleIoReceive(uint8_t *buffer, const uint32_t bufferLength, uint32_t *readLength)
{
	uint32_t i = 0;
	char ch;

	while ( uart_is_readable(uart0)) {
		ch = uart_getc(uart0);
		buffer[i] = (uint8_t) ch;
		++i;
	}

	uart_puts(UART_NUM, buffer);
	*readLength = i;
	return CONSOLE_SUCCESS;
}

eConsoleError ConsoleIoSendString(const char *buffer)
{
	uart_puts(UART_NUM, buffer);
	return CONSOLE_SUCCESS;
}
