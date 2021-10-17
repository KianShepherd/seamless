#include "include/cpu.h"
#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <ciso646>
#include <iomanip>
#include <string>

int dump(std::istream& ins, char* program_data ) {
    std::cout << std::setfill( '0' ) << std::hex << std::uppercase;
    int program_size = 0;

    while (ins) {
        char s[16];
        std::size_t n, i;
        ins.read(s, sizeof(s));
        n = ins.gcount();

        for (i = 0; i < n; i++) {
            program_data[program_size] = (int)(s[i]);
            //std::string temp(1, s[i]);
            program_size++;
        }
    }

    return program_size;
}


int main(int argc, char** argv) {
    bool dump_cpu = false;
    auto file_names = new std::string[10];
    int file_count = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp("-d", argv[i]) == 0) {
            dump_cpu = true;
        } else {
            file_names[file_count++] = argv[i];
        }
    }

    int rc = 0;
    for (int i = 0; i < file_count; i++) {
        //std::cout << file_names[i] << std::endl;
        std::ifstream bin_file(file_names[i], std::ios::binary);

        int length;
        char*  program_data = new char[200];
        if (bin_file.is_open()) {
            length = dump(bin_file,  program_data);
            bin_file.close();
            CPU* cpu = new CPU(program_data, length);

            if (dump_cpu)
                cpu->Dump();

            rc = cpu->Start();

            if (dump_cpu)
                cpu->Dump();

            //std::cout << rc << std::endl;
        } else {
            std::cout << "Failed to open file: " << file_names[0] << std::endl;
            throw std::exception();
        }
    }

    return rc;
}