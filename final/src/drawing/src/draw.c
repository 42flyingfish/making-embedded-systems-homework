#include "draw.h"
#include "pico/st7789.h"

#define LCD_WIDTH 240
#define LCD_HEIGHT 320

static uint16_t cursorX = 0;
static uint16_t cursorY = 0;
static uint16_t colorValue = 0xffff;
static enum Color currentColor = White;

uint16_t getCursorX(void) {
	return cursorX;
}

uint16_t getCursorY(void) {
	return cursorY;
}

void setCursorX(uint16_t value) {
    cursorX = value % LCD_WIDTH;
}

void setCursorY(uint16_t value) {
	cursorY = value % LCD_HEIGHT;
}

void drawPixel(void) {
    st7789_set_cursor(cursorX, cursorY);
    st7789_put(colorValue);
}

void decrementCursorX(void) {
    --cursorX;
    cursorX %= LCD_WIDTH;
}

void decrementCursorY(void) {
    --cursorY;
    cursorY %= LCD_WIDTH;
}

void incrementCursorX(void) {
    ++cursorX;
    cursorX %= LCD_HEIGHT;
}

void incrementCursorY(void) {
    ++cursorY;
    cursorY %= LCD_HEIGHT;
}

uint16_t getColorValue(void) {
    return colorValue;
}

void nextColor(void) {
    switch(currentColor) {
    case Red: {
        currentColor = Orange;
        colorValue = 0xFC00;
        break;
    }
    case Orange: {
        currentColor = Yellow;
        colorValue = 0xFFE0;
        break;
    }
    case Yellow: {
        currentColor = Green;
        colorValue = 0x07E0;
        break;
    }
    case Green: {
        currentColor = Cyan;
        colorValue = 0x07FF;
        break;
    }
    case Cyan: {
        currentColor = Blue;
        colorValue = 0x001F;
        break;
    }
    case Blue: {
        currentColor = Violet;
        colorValue = 0x801F;
        break;
    }
    case Violet: {
        currentColor = White;
        colorValue = 0xffff;
        break;
    }
    case White: {
        currentColor = Black;
        colorValue = 0x0000;
        break;
    }
    case Black: {
        currentColor = Red;
        colorValue = 0xf800;
        break;
    }
    default: {
        // This shouldn't be possible, but I will set it to white
        currentColor = White;
        colorValue = 0xffff;
        break;
    }
    }
}
