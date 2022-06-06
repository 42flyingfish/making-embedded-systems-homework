#include "draw.h"
#include "pico/st7789.h"

#define LCD_WITH 240
#define LCD_HEIGHT 320

static uint16_t cursorX = 0;
static uint16_t cursorY = 0;

uint16_t getCursorX(void) {
	return cursorX;
}

uint16_t getCursorY(void) {
	return cursorY;
}

void setCursorX(uint16_t value) {
	cursorX = value % LCD_WITH;
}

void setCursorY(uint16_t value) {
	cursorY = value % LCD_HEIGHT;
}

void drawPixel(void) {
    st7789_set_cursor(cursorX, cursorY);
    st7789_put(0xffff);
}
