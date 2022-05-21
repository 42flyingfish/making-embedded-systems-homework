### Exercise 8: Resource Constraints

This is a basic project that prints the adresses of a few variables. The only thing that currently isn't done is printing both the stack and heap pointers. Despite that, I was able to play with the link file with sucess.


### Notes on compiling and altering the link file
This is based on the pico-sdk.

Make sure that you have PICO_SDK_PATH environmental variable defined before compiling.

I altered the link file by making a copy of the [default link file provided by the SDK](https://github.com/raspberrypi/pico-sdk/blob/426e46126b5a1efaea4544cdb71ab81b61983034/src/rp2_common/pico_standard_link/memmap_default.ld) and swapping the .bss and .data sections in the script. I'm still new to cmake, but it turns out that the [SDK provides a function](https://github.com/raspberrypi/pico-sdk/blob/426e46126b5a1efaea4544cdb71ab81b61983034/src/rp2_common/pico_standard_link/CMakeLists.txt#L36) for using your own link file. Using what I found, I made a CmakeList.txt that produces a binary for the default link file and the moddified link file. The defaultLinker.uf2 and swappedLinker.uf2 built use memmap_default.ld and swapped.ld respectively.

## defaultLinker output
```console
Uninitialized global variable: 0x2000055C
Initialized global variable: 0x20000178
Non-static variable in function: 0x20041FD4
Static variable in a function: 0x20000614

.data start 0x200000C0
.data end 0x200000C0

.bss start 0x20000240
.bss end 0x2000061C
```

## swappedLinker output
```console
Uninitialized global variable: 0x200003DC
Initialized global variable: 0x20000558
Non-static variable in function: 0x20041FD4
Static variable in a function: 0x20000494

.data start 0x200004A0
.data end 0x200004A0

.bss start 0x200000C0
.bss end 0x2000049C
```


## Observations
* The changes to output seems to make sense. 
* There are a few sections between the .data and .bss in the linker file that I left untouched. There might be a few unintended consequences caused by my actions that I might have caused.

### Notes on hookup
Everything is printed over uart.

| This will set the following|  |
| --- | --- |
| TX | GPIO 0 |
| RX | GPIO 1 |
| baudrate | 115200 |
| uart | uart0 |

