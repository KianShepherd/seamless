#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "../include/cpu.h"
class Tests {
public:
    Tests();
    void load_program(const std::string& file_name);
    int run();
private:
    CPU *cpu;
    int addTest();
    int subTest();
    int setTest();
    int dump(std::istream& ins, char* program_data );
};


