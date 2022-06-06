#ifndef DRAW_H
#define DRAW_H

#include <stdint.h>

uint16_t getCursorX(void);
uint16_t getCursorY(void);
void setCursorX(uint16_t);
void setCursorY(uint16_t);
void drawPixel(void);

#endif
