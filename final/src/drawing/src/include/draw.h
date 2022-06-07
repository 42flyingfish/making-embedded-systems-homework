#ifndef DRAW_H
#define DRAW_H

#include <stdint.h>

enum Color {Red, Orange, Yellow, Green, Cyan, Blue, Violet, Black, White};

uint16_t getCursorX(void);
uint16_t getCursorY(void);
void setCursorX(uint16_t);
void setCursorY(uint16_t);
void drawPixel(void);
void decrementCursorX(void);
void decrementCursorY(void);
void incrementCursorX(void);
void incrementCursorY(void);
uint16_t getColorValue(void);
void nextColor(void);

#endif
