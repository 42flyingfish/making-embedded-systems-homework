# Week2 Assignment

## Project Board: Adafruit's Adafruit Feather RP2040
![image of Adafruit's board](https://cdn-learn.adafruit.com/assets/assets/000/100/340/medium800/adafruit_products_FeatherRP_top.jpg?1614788806)

## Questions

### What kind of processor is it?
RP2040 featuring Dual 32-bit Cortex ARM M0+ cores

### How much Flash and RAM does it have? Any other memory types?
* 8  MB SPI FLASH: The RP2040 does not have flash itself.
* 264 KB RAM

### Does it have any special peripherals? (List 3-5 that you find interesting.)

* 2 SPI controllers
* 2 I2C controllers
* 16 PWM channels
* 8 PIO state machines (Custom hardware logic, but this does mean using assembly)


### If it has an ADC, what are the features?
Acording to the [this page on the pico sdk docs][pico adc]
* Four 12 bit ADCs
* 500 kS/s (Using an independent 48MHz clock)
* Interrupt generation
* DMA interface

### How much does the board cost vs what the processor costs? Is the processor in stock anywhere? (Try Digikey, Mouser, Octopart, Google, and so on.)
Product page for board on [Adafruit][feather on adafruit]
The board is currently available on Adafruit in a Pink PCB version for $11.95

Product page for processor on [Mouser][rp2040 on Mouser]
In stock
| Quantity | Unit Price | Ext Price  |
| ---------|:----------:|-----------:|
|        1 | 	    $1.25 |	     $1.25 |

Product page for processor on [Digikey][rp2040 on Digikey]
In stock
| Quantity | Unit Price | Ext Price  |
| ---------|:----------:|-----------:|
|        1 | 	       $1 |	        $1 |
|      500 |	      $1	|       $500 |

### Application Note
* The [Pico SDK][pico sdk] has App notes under appendix a

---

## Assigned Board: SparkFun Photon RedBoard
![Image of redboard](https://cdn.sparkfun.com//assets/parts/1/0/6/0/9/13321-01.jpg "Arduino Formfactor")

## Questions

### What kind of processor is it?
STM32F205RGY6 32-bit ARM Cortex-M3 microcontroller [stm.com][processor on stm]

You can see more information about the STM32F205 [here on stm.com][processor on stm]

### How much Flash and RAM does it have? Any other memory types?
* 1MB flash
* 128KB RAM

### Does it have any special peripherals? (List 3-5 that you find interesting.)
* Broadcom BCM43362 Wi-Fi chip with support for 802.11b/g/n Wi-Fi
* I2S
* SPI
* I2C
* DAC

### If it has an ADC, what are the features?
* 12 bit ADC
* 2 MSPS or 6 MSPS in interleaved mode

### How much does the board cost vs what the processor costs? Is the processor in stock anywhere? (Try Digikey, Mouser, Octopart, Google, and so on.)

Product page for board on [SparkFun][board on SparkFun]
* Is currently available as of 3/18/22 at the price of $41.95 for 1 unit

Product page for processor on [Mouser][processor on Mouser]
* Currently sold out as of 3/18/22

| Quantity | Unit Price | Ext Price  |
| ---------|:----------:|-----------:|
|        1 | 	   $13.90 |	    $13.90 |
|       10 |	   $12.57	|    $125.70 |
|       25 |	   $11.98 |	   $299.50 |
|      100 |     $10.41 |  $1,041.00 |
|      250 |	    $9.94 |	 $2,485.00 |
|      500 |    	$9.06 |	 $4,530.00 |
|    1,000 |    	$7.80 |	 $7,800.00 |
|    3,000 |      $7.79 | $23,370.00 |

Product page for processor on [Digikey][processor on Digikey]
* Currently sold out as of 3/18/22

| Quantity | Unit Price | Ext Price  |
| ---------|:----------:|-----------:|
|    3,000 |   $9.73900 | $29,217.00 |

### Application Note
* The video on the product page explains that this could be used in home automation do to its connectivity
* There is a hookup guide feature basic usage of wifi 



[board on SparkFun]: https://www.sparkfun.com/products/13321
[processor on stm]: https://www.st.com/en/microcontrollers-microprocessors/stm32f2x5.html
[processor on Mouser]: https://www.mouser.com/ProductDetail/STMicroelectronics/STM32F205RGY6TR?qs=%2Fha2pyFadugaMGnmcN3fMp8I7ptw%252BflKwi%2F%252B1SLP6OoH7wAuNZ9Xiw%3D%3D
[pico adc]: https://raspberrypi.github.io/pico-sdk-doxygen/group__hardware__adc.html
[processor on Digikey]: https://www.digikey.com/en/products/detail/stmicroelectronics/STM32F205RGY6TR/2796954?s=N4IgTCBcDaIMoBUCyBmMAxMAGArAJQHEBNANgTwAIQBdAXyA
[rp2040 on Digikey]: https://www.digikey.com/en/products/detail/raspberry-pi/SC0914-7/14306009
[rp2040 on Mouser]: https://www.mouser.com/ProductDetail/Raspberry-Pi/RPI-Chip-RP2040-7-500?qs=QNEnbhJQKvaZH1bqQMV2YA%3D%3D
[feather on adafruit]: https://www.adafruit.com/product/4884
[pico c sdk]: https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf
