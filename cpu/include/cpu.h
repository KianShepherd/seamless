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
        int Start();
    private:
        int Ops0000(unsigned short op);
        int Ops1000(unsigned short op);
        int Ops2000(unsigned short op);
        int Ops3000(unsigned short op);
        int Ops4000(unsigned short op);
        int Ops5000(unsigned short op);
        int Ops6000(unsigned short op);
        int Ops7000(unsigned short op);
        int Ops8000(unsigned short op);
        int Ops9000(unsigned short op);
        int OpsA000(unsigned short op);
        int OpsF000(unsigned short op);

        int Update();
        int pc;
        long long* registers;
        char* stack;
        std::stack<long> pc_stack;
};
