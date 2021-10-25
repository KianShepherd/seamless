# Seamless Toolchain: SASM compiler

A compiler for SASM(simple assembly). This compiler turns .sasm files into .se files to be used by the seamless cpu emulator.

Currently all opcodes for seamless 1.0 have been implemented, and tested.

Since almost all of the assembly calls can be turned into their respective opcodes directly this compiler makes a dictionary between lines of assembly and the opcode to output. Some lines can not be handled directly like this (SET, LOAD, STORE, and various JMP commands) so they are dealt with ater the fact if the line was not found in the dictionaries keys.
