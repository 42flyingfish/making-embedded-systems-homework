# Coloured Etch-a-sketch

# Overview

The project is to make a etch-a-sketch with a muliti-coloured display.  I will be using the rp2040. Since the board that I am using features a neopixel, I can use that to display the current colour to be drawn to the screen.

## Inputs
* Up
* Down
* Left
* Right
* Change colour
* Reset (Might be an IMU to shake to clear the screen)

## Outputs
* Display
* Neopixel

## Important Variables
* position_x
* position_y
* max_x
* max_y
* colour


### The colour to draw will change on each button press
```mermaid
graph LR;
Red --> Orange;
Orange --> Yellow;
Yellow --> Green;
Green --> Blue;
Blue --> Purple;
Purple --> Violet;
Violet --> Red;
```

### States

```mermaid
graph TD;
Start --> Init;
Init --> Ready;
Ready -- Change colour --> ChangeColour;
Ready -- Direction Button Press --> MoveCursor;
Ready -- Reset --> Init;

ChangeColour[Next Colour] --> SetNeopixel;
SetNeopixel[Set Neopixel] --> Ready;


MoveCursor[Move Cursor] --> PassedEdge;
PassedEdge{Cursor Beyond Screen} -- Yes --> AdjustCursor;
PassedEdge -- No --> UpdateScreen;
AdjustCursor[Fix Cursor] --> UpdateScreen;
UpdateScreen[Update Screen] --> ButtonsHeld;
ButtonsHeld{Button held} -- Yes --> MoveCursor;
ButtonsHeld -- No --> Ready;
```