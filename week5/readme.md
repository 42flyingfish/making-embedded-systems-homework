### Basic Console for RP2040


### Notes on compiling
This is based on the pico-sdk
Make sure to have PICO_SDK_PATH defined before compiling

### Notes on hookup
main.c calls the sdk function setup_default_uart()

| This will set the following |
| --- | --- |
| TX |GPIO 0 |
| RX |GPIO 1 |
| baudrate | 115200 |

### Notes on debugging the rp2040 with swd
For this project, I decided to learn to use my Segger J-Link mini edu.

If you have the appropriate software installed, this can be started with the command
```console
foo@bar:~$ JLinkGDBServer -if SWD -device RP2040_M0_0
```

In another terminal you can connect to this with the following command

```console
foo@bar:~$ gdb-multiarch console.elf
(gdb) target remote localhost:2331
```
