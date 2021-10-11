#include "include/cpu.h"

int main() {
    int program_size = 5;
    unsigned char* program_data = new unsigned char[program_size];
    program_data[0] = 0;
    program_data[1] = 2;
    program_data[2] = 4;
    program_data[3] = 17;
    program_data[4] = 9;

    int rc = 0;
    CPU* cpu = new CPU(program_data, program_size);

    cpu->Dump();

    return rc;
}