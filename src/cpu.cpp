#include "../include/cpu.h"
#include <iostream>

CPU::CPU(unsigned char* program, int program_size) {
    pc = 0;
    registers = new long[MAX_REGISTERS];
    for (int i = 0; i < MAX_REGISTERS; i++)
        registers[i] = 0;
    
    stack = new unsigned char[MAX_STACK];
    for (int i = 0; i < MAX_STACK; i++) {
        if (i < program_size) {
            stack[i] = program[i];
        } else {
        stack[i] = 0;
        }
    }
        
}

CPU::~CPU() {

}

void CPU::Dump() {
    std::cout << pc << std::endl << "Registers: [";

    for (int i = 0; i < MAX_REGISTERS; i++)
        std::cout << registers[i] << ", ";
        
    std::cout << "]" << std::endl << "Stack: [";

    for (int i = 0; i < MAX_STACK / 10; i++)
        std::cout << std::hex << (int)stack[i] << ", ";

    std::cout << "]" << std::endl;
}