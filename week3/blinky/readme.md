# Blinky on the Raspberry Pi Pico
0. The Board in question:
Rasberry Pi Pico
1. What build environment are you using?
The pico sdk with Visual Studio Code

My environment setup largely follows the guide from the document [Getting started with Raspberry Pi Pico](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).

There are a few things to note
* I have added a button to the board. This button is connected to Pin 20 of the board or GPIO 15 and Pin 18 or Ground.
* I am using the default on board LED. The sdk defines the macro PICO_DEFAULT_LED_PIN which expands to 25.

2. Can you step through the code to see what each line does?

You can get GDB running with Raspberry Pi's tool picoprobe. You can also use SWD.

4. What are the hardware registers that cause the LED to turn on and off? (From the  
processor manual, don’t worry about initialization.)

According to what I can find in the datasheet, there is a GPIO_OUT register. This starts at an offset of 0x010 from the SIO 0xd0000000. Interestingly, there seems to be a register for just toggling a GPIO output that could be right for toggling and LED. 

4. What are the registers that you read in order to find out the state of the button?

The answer to this is likely GPIO_IN Register at offset 0x004.

6. Can you read the register directly and see the button change in a debugger or by  
printing out the value of the memory at the register’s address?

I will eventually. Stay tuned for an update. Believe it or not, I was originally using Adafruit's rp2040 feather instead of the. I even got cmake setup to compile blinky for this as the pico SDK does provide board configuration files for it. I killed it trying to solder on the SWD Pitch Connector.

---
## Extras
Uses an IRQ but does not debounce.

## Build instructions

This relies on the Raspberry Pi SDK. Remember to set the environment variable PICO_SDK_PATH to the location of the sdk before running cmake.
