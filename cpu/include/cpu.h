#pragma once

#include <iostream>
#include <stdlib.h>
#include <stack>

#define MAX_REGISTERS 4
#define MAX_STACK 2 * 1024 


class CPU {
    public:
        void Dump();
        CPU(unsigned char* program, int program_size);
        ~CPU();
        int Start();
    private:
        int Update();
        int pc;
        long* registers;
        unsigned char* stack;
        std::stack<long> pc_stack;
};
