#pragma once

#include <iostream>
#include <stdlib.h>
#include <stack>

#define MAX_REGISTERS 4
#define MAX_STACK 2 * 1024 


class CPU {
    public:
        void Dump();
        CPU(const char* program, int program_size);
        ~CPU();
        long long  Start();
    private:
        long long  Ops0000(unsigned short op);
        long long  Ops1000(unsigned short op);
        long long  Ops2000(unsigned short op);
        long long  Ops3000(unsigned short op);
        long long  Ops4000(unsigned short op);
        long long  Ops5000(unsigned short op);
        long long  Ops6000(unsigned short op);
        long long  Ops7000(unsigned short op);
        long long  Ops8000(unsigned short op);
        long long  Ops9000(unsigned short op);
        long long  OpsA000(unsigned short op);
        long long  OpsF000(unsigned short op);

        long long Update();
        int pc;
        unsigned long long* registers;
        unsigned char* stack;
        std::stack<long> pc_stack;
};
