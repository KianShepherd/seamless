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
    unsigned long long run();
private:
    
    
    unsigned long long run_test(std::string file_name, unsigned long long rc_to_compare, bool debug=false);
    CPU *cpu;
    unsigned long long mathTests();
    unsigned long long addTest();
    unsigned long long subTest();
    unsigned long long mulTest();
    unsigned long long andTest();
    unsigned long long orTest();
    unsigned long long xorTest();
    unsigned long long setTests();
    unsigned long long jumpTests();
    static int dump(std::istream& ins, char* program_data );
};

unsigned char hex_char_to_int( char c );
unsigned char string_to_vector(std::basic_string<char> str);