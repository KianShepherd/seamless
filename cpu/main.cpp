#include "include/cpu.h"
#include "include/tests.h"
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
        char s[1];
        ins.read(s, sizeof(s));

        int temp = (s[0]) << 24;
        temp = temp >> 24;
        //std::cout <<  temp << " ";
        program_data[program_size] = temp;
        //std::cout << std::hex << temp << std::endl;
        program_size++;
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
        } else if (strcmp("-t", argv[i]) == 0) {
            dump_cpu = true;
            auto tests = new Tests();
            return tests->run();
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
        std::ostringstream ret;
        if (bin_file.is_open()) {
            length = dump(bin_file,  program_data);
            bin_file.close();

            for (int i = 0; i < length; i++){
                //std::cout << "char" << std::endl;
                ret.str(std::string());
                //std::cout << program_data[i] << std::endl;
                ret << std::hex << std::setfill('0') << std::setw(2) << std::uppercase << (int) program_data[i];
                //std::cout << ret.str().substr(0, 2) << std::endl;
                //std::cout << (int)program_data[i] << std::endl << std::endl << std::endl;
                std::string temp_str = ret.str();
                temp_str = temp_str.substr(temp_str.length() - 2, temp_str.length());
                program_data[i] = (long long)((unsigned char)string_to_vector(temp_str));
                //std::cout << std::dec << (long long)((unsigned char)program_data[i]) << " " << (((unsigned char)program_data[i] > 255) ? "TRUE" : "FALSE") << std::endl << temp_str << std::endl << std::endl;
            }





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