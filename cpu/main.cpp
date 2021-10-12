#include "include/cpu.h"
#include <string.h>
#include <iostream>

int main(int argc, char** argv) {
    bool dump_cpu = false;

    for (int i = 0; i < argc; i++) {
        if (strcmp("-d", argv[i]) == 0) {
            dump_cpu = true;
        }
    }

    int program_size = 14;
    unsigned char* program_data = new unsigned char[program_size];
    program_data[0] = 0x10;
    program_data[1] = 0x04;
    program_data[2] = 0x00;
    program_data[3] = 0x00;
    program_data[4] = 0x50;
    program_data[5] = 0x00;
    program_data[6] = 0x10;
    program_data[7] = 0x51;
    program_data[8] = 0x00;
    program_data[9] = 0x0a;
    program_data[10] = 0x30;
    program_data[11] = 0x00;
    program_data[12] = 0x00;
    program_data[13] = 0xE0;

    int rc = 0;
    CPU* cpu = new CPU(program_data, program_size);

    
    if (dump_cpu)
        cpu->Dump();

    rc = cpu->Start();
    if (dump_cpu)
        cpu->Dump();

    //std::cout << rc << std::endl;

    return rc;
}