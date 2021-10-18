#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip>

#include "../include/cpu.h"
class Tests {
public:
    Tests();
    void load_program(const std::string& file_name);
    int run();
private:
    unsigned char string_to_vector(std::basic_string<char> str);
    unsigned char hex_char_to_int( char c );
    int run_test(std::string file_name, long long rc_to_compare, bool debug=false);
    CPU *cpu;
    int mathTests();
    int addTest();
    int subTest();
    int setTests();
    int jumpTests();
    static int dump(std::istream& ins, char* program_data );
};


