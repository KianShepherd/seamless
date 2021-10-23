# Seamless

## What is it
Seamless is a toolchain to go from code -> assembly -> opcodes -> cpu -> output. 

CPU and Compiler versions 1.0 implement all the opcodes and have each been fully unit tested.

<br>

### Seamless CPU v1.0
The seamless CPU emulator is based off a modified version of the Chip-8 instruction set, but with 4 64 bit registers. 

<br>

### Seamless SASM Compiler v1.0
The SASM compiler compiles SASM(Simple-Assembly) files into the opcodes that the CPU emulator will later use to run the program. 

<br>

### Seamless Language
Not yet implemented.
The seamless language will be compiled into Simple-Assembly to be used later in the toolchain.

<br>

## Assembly & OP Code Specification
### Legend
* `VX or VY`  denotes the register index [0, 1, 2, 3]
* `$KK uSize` denotes an unsigned value with max size denoted by the value of Size
* `NNN` denotes a 3 nibble value in hex

<br>

### Assembly & OP Codes
* `0x00E0`: CLS (Close: exits the program)
* `0x00EE`: RET (Return: returns from function call)

<br>

* `0x1NNN`: JMP NNN (Jump: sets program counter to value NNN)
* `0x21XY`: JE VX, VY, $KK u8 (Jump Equal: If reg X == reg Y jump to $KK)
* `0x22XY`: JNE VX, VY, $KK u8 (Jump Not Equal: If reg X != reg Y jump to $KK)
* `0x23XY`: JGT VX, VY, $KK u8 (Jump Greater Than: If reg X > reg Y jump to $KK)
* `0x240X`: JZ VX, $KK u8 (Jump Zero: If reg X == 0 jump to $KK)

<br>

* `0x300X`: PRNT VX (Print: Print decimal value of reg X)
* `0x301X`: PRNT_CHAR VX (Print Char: Print ASCII value of reg X)

<br>

* `0x4NNN`: CALL NNN (Call function: Call function at location NNN)

<br>

* `0x5X00`: SET VX, $KK u8 (Set: Sets reg X to u8 $KK)
* `0x5X01`: SET VX, $KK u16 (Set: Sets reg X to u16 $KK)
* `0x5X02`: SET VX, $KK u32 (Set: Sets reg X to u32 $KK)
* `0x5X03`: SET VX, $KK u64 (Set: Sets reg X to u64 $KK)
* `0x6X01`: LOAD VX, $KK u16 (Load: Loads reg X with value at memory location $KK)
* `0x6X11`: STORE VX, $KK u16 (Store: Stores reg X at memory location $KK)

<br>

* `0x7X00`: RND VX (Random: Stores random value in reg X)
* `0x8XY0`: ADD VX, VY (Add: Add reg X and reg Y)
* `0x8XY1`: OR VX, VY (Or: Or reg X and reg Y)
* `0x8XY2`: AND VX, VY (And: And reg X and reg Y)
* `0x8XY3`: XOR VX, VY (Xor: Xor reg X and reg Y)
* `0x8XY4`: SUB VX, VY (Sub: Sub reg X and reg Y)
* `0x8XY5`: MUL VX, VY (Mul: Mul reg X and reg Y)
* `0x8XY6`: DIV VX, VY (Div: Div reg X and reg Y)

<br>

* `0x90X0`: SKZ VX (Skip zero: Skip next instruction if reg X == 0)
* `0x90X1`: SKNZ VX (Skip not zero: Skip next instruction if reg X != 0)
* `0x91XY`: SKE VX, VY (Skip equal: Skip next instruction if reg X == reg Y)
* `0x92XY`: SKNE VX, VY (Skip not equal: Skip next instruction if reg X != reg Y)
* `0x93XY`: SKGT VX, VY (Skip equal: Skip next instruction if reg X > reg Y)

<br>

* `0xAXY0`: LD VX, VY (Load: Load value at reg Y into reg X)
* `0xFFFX`: DBG VX (Debug: Return with return code equal to value at reg X)

<br>
