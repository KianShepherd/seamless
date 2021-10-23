# Seamless

## What is it
Seamless is a toolchain to go from code -> assembly -> opcodes -> cpu -> output. 

### Seamless CPU
The seamless cpu emulator is based off a modified version of the chip-8 instruction set, but made to have more registers and to allow for larger sized values (64-bits). 

### Seamless SASM compiler
The SASM compiler compiles SASM(Simple-Assembly) files into the opcodes that the CPU emulator will later use to run the program. 

### Seamless Language
Not yet implemented.
The seamless language will be compiled into Simple-Assembly to be used later in the toolchain.
