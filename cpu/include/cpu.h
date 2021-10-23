#pragma once

#include <iostream>
#include <stdlib.h>
#include <stack>

#define MAX_REGISTERS 4
#define MAX_STACK 4 * 1024 


class CPU {
    public:
        void Dump();
        CPU(const char* program, int program_size, bool debug);
        ~CPU();
        unsigned long long  Start();
    private:
        unsigned long long  Ops0000(unsigned short op);
        unsigned long long  Ops1000(unsigned short op);
        unsigned long long  Ops2000(unsigned short op);
        unsigned long long  Ops3000(unsigned short op);
        unsigned long long  Ops4000(unsigned short op);
        unsigned long long  Ops5000(unsigned short op);
        unsigned long long  Ops6000(unsigned short op);
        unsigned long long  Ops7000(unsigned short op);
        unsigned long long  Ops8000(unsigned short op);
        unsigned long long  Ops9000(unsigned short op);
        unsigned long long  OpsA000(unsigned short op);
        unsigned long long  OpsF000(unsigned short op);

        unsigned long long Update();
        bool debugging;
        int pc;
        unsigned long long* registers;
        unsigned char* stack;
        std::stack<long> pc_stack;
};
