#pragma once

#define MAX_REGISTERS 4
#define MAX_STACK 2 * 1024 


class CPU {
    public:
        void Dump();
        CPU(unsigned char* program, int program_size);
        ~CPU();
    private:
        int pc;
        long* registers;
        unsigned char* stack;
};
