# Coloured Etch-A-Sketch

## Application description
This project is based on a mechanical toy from the 1960s. My project is a digital recreation with the addition of colour. With a push of a button, a user is able to cycle between multiple colours 
## Hardware description

### The board itself
The device is based around the rp2040 microcontroller. For this project, that board is the Adafruit RP2040 Feather. The board features an RGB neopixel that is used as an indicator of what colour will be drawn when the cursor moves.

### User Inputs
Hooked up to the board is a series of push buttons. One button simply cycles through the available colours. On each button press, the RGB Led will change to reflect the current colour. The other buttons are used to move the cursor along the x and y axis. Finally, a tilt sensor exists to clear the display and reset the device. This is intended to mimic the etch-a-sketch's shake feature.

### TFT Display
A coloured display will be used to display the drawing.

## Software description
The code for this project is primarily written in C. Due to the requirements of the SDK, the build system is cmake. Sections that utilize the rp2040's PIO features such as the neopixel will use the associated assembly language. With regards to the PIO, the SDK will generate extra files such as headers that are included with the source files.
### Modified
* I have modified the neopixel example from the SDK to suit my needs for this project. The example code was licensed under BSD-3.
### Limitations and Considerations - TODO
In regards to PIO there are a number of examples of using it to drive a display, but is it the best choice? The rp2040 features eight state machines divided up for the two PIO instances. Each Instance can have its own code. One will go for the Neopixel and the other for the display. The state machines have their own PC registers, but the project does not need extra displays or pixels.
## Diagrams

### State Machine examples

## Build instructions
This makes use of the [Pico SDK](https://github.com/raspberrypi/pico-sdk), as such, the instructions to build this will be similar. This project was developed on Ubuntu 22.04 and the instructions are as follows.
1. You will need git, atleast cmake 3.13, gcc for arm.
2. Clone this repository
3. You will need the [Pico SDK](https://github.com/raspberrypi/pico-sdk)
4. Since this project uses the board from Adafruit you will need to set this variable before building; otherwise, this will default to building for the Raspberry Pi Pico.
```shell
export PICO_BOARD=adafruit_rp2040_feather
```
5. Make a folder to build this and run cmake

### Debugging and Testing
#### Debugging
* The board has SWD which allows me to use GDB with my Segger mini edu
* A simple command line over UART allows me to run commands using an FTDI cable
#### Testing - Todo
* Since the project uses cmake, I could potentially take the time to learn to use ctest
#### Powering - Todo
* The board features a connector for connecting a battery as well as using USB to supply power.

## Future
1. Design a dedicated case and circuit board for this.
2. Some displays and even some alternative rp2040 boards like the SparkFun Thing Plus feature a slot for a micro SD card. Perhaps a child would like to save their picture to a file. Perhaps a child would like to doodle over a picture.
3. Currently, when someone draws over anything else, the display will simply replace what was before. Another idea was to blend the colours. For example, if someone were to draw over red with blue, the display would show purple at that location instead. I am not sure if this is a good idea to explore.

## Grading
TODO

## Concerns
* I have failed multiple times to solder on the 10 pin connector for SWD debugging. I am using a breakout board at the moment. My only experience with soldering is with a torch with silver.
* Should this entirely be in C? I was a C++ person in school. Constructors and Destructors can be handy for organization.
* There are already example code for using a display; however, it is rather small. I might not have the experience to implement my own.
