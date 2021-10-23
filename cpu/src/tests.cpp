#include <vector>
#include <string.h>
#include "../include/tests.h"

Tests::Tests() {
    auto program_data = new unsigned char[0];
    cpu = new CPU(program_data, 0, false);
}

unsigned long long Tests::run() {
    int passes = 0;
    std::cout << "RUNNING ALL TESTS" << std::endl;
    passes += setTests();
    passes += controlFlowTests();
    passes += mathTests();
    std::cout << "ALL TESTS " << passes << "/3" << std::endl;
    run_test("test_programs/print.se", 9, true);

    return 0;
}

unsigned long long Tests::controlFlowTests() {
    int passes = 0;
    std::cout << "    Running Control Flow tests" << std::endl;
    passes += functionTests();
    passes += jumpTests();
    passes += skipTests();
    std::cout << "    Control Flow tests " << passes << "/3" << std::endl << std::endl;
    return (passes == 3) ? 1 : 0;
}

unsigned long long Tests::functionTests() {
    int passes = 0;
    std::cout << "        Running CALL tests" << std::endl;
    passes += run_test("test_programs/function1.se", 1);
    passes += run_test("test_programs/function2.se", 2);
    std::cout << "            CALL tests: " << passes << "/2" << std::endl;

    return (passes == 2) ? 1 : 0;
}

unsigned long long Tests::mathTests() {
    int passes = 0;
    std::cout << "    Running Math Tests" << std::endl;
    passes += addTest();
    passes += subTest();
    passes += mulTest();
    passes += andTest();
    passes += orTest();
    passes += xorTest();
    passes += randTests();

    std::cout << "    Math tests: " << passes << "/7" << std::endl << std::endl;

    return (passes == 7) ? 1 : 0;
}

unsigned long long Tests::randTests() {
    int passes = 0;
    std::cout << "        Running RAND tests" << std::endl;
    passes += run_test("test_programs/rand1.se", 5, true) == 1;
    passes += run_test("test_programs/rand1.se", 5, true) == 1;
    std::cout << "        RAND tests: " << passes << "/2" << std::endl;

    return (passes == 2) ? 1 : 0;
}

unsigned long long Tests::addTest() {
    int passes = 0;
    std::cout << "        Running ADD tests" << std::endl;
    passes += run_test("test_programs/add1.se", 8);
    passes += run_test("test_programs/add2.se", 33);
    passes += run_test("test_programs/add3.se", 16);
    passes += run_test("test_programs/add4.se", 326);
    passes += run_test("test_programs/add5.se", 1);
    std::cout << "            ADD tests: " << passes << "/5" << std::endl;

    return (passes == 5) ? 1 : 0;
}

unsigned long long Tests::subTest() {
    int passes = 0;
    std::cout << "        Running SUB tests" << std::endl;
    passes += run_test("test_programs/sub1.se", 2);
    passes += run_test("test_programs/sub2.se", 7);
    passes += run_test("test_programs/sub3.se", 253);
    passes += run_test("test_programs/sub4.se", 5);
    passes += run_test("test_programs/sub5.se", 18446744073709551615u);

    std::cout << "            SUB tests: " << passes << "/5" << std::endl;

    return (passes == 5) ? 1 : 0;
}

unsigned long long Tests::mulTest() {
    int passes = 0;
    std::cout << "        Running MUL tests" << std::endl;
    passes += run_test("test_programs/mul1.se", 15);
    passes += run_test("test_programs/mul2.se", 270);
    passes += run_test("test_programs/mul3.se", 63);
    passes += run_test("test_programs/mul4.se", 13800);
    passes += run_test("test_programs/mul5.se", 18446744073709551614u);
    std::cout << "            MUL tests: " << passes << "/5" << std::endl;

    return (passes == 5) ? 1 : 0;
}

unsigned long long Tests::andTest() {
    int passes = 0;
    std::cout << "        Running AND tests" << std::endl;
    passes += run_test("test_programs/and1.se", 8);
    passes += run_test("test_programs/and2.se", 0);
    passes += run_test("test_programs/and3.se", 0);
    passes += run_test("test_programs/and.se", 0);
    std::cout << "            AND tests: " << passes << "/4" << std::endl;

    return (passes == 4) ? 1 : 0;
}

unsigned long long Tests::orTest() {
    int passes = 0;
    std::cout << "        Running OR tests" << std::endl;
    passes += run_test("test_programs/or1.se", 15);
    passes += run_test("test_programs/or2.se", 3);
    passes += run_test("test_programs/or3.se", 2);
    passes += run_test("test_programs/or4.se", 255);
    std::cout << "            OR tests: " << passes << "/4" << std::endl;

    return (passes == 4) ? 1 : 0;
}

unsigned long long Tests::xorTest() {
    int passes = 0;
    std::cout << "        Running XOR tests" << std::endl;
    passes += run_test("test_programs/xor1.se", 7);
    passes += run_test("test_programs/xor2.se", 3);
    passes += run_test("test_programs/xor3.se", 2);
    passes += run_test("test_programs/xor4.se", 255);
    std::cout << "            XOR tests: " << passes << "/4" << std::endl;

    return (passes == 4) ? 1 : 0;
}

unsigned long long Tests::setTests() {
    int passes = 0;
    std::cout << "        Running Set tests" << std::endl;
    passes += run_test("test_programs/set1.se", 276);
    passes += run_test("test_programs/set2.se", 2);
    passes += run_test("test_programs/set3.se", 65530);
    passes += run_test("test_programs/set4.se", 65540);
    passes += run_test("test_programs/set5.se", 4294967290);
    passes += run_test("test_programs/set6.se", 4294967300);
    passes += run_test("test_programs/set7.se", 18446744073709551613u);
    passes += run_test("test_programs/set8.se", 255);
    passes += run_test("test_programs/load1.se", 255);
    std::cout << "        Set tests: " << passes << "/9" << std::endl << std::endl;

    return (passes == 9) ? 1 : 0;
}

unsigned long long Tests::jumpTests() {
    int passes = 0;
    std::cout << "    Running JUMP tests" << std::endl;
    passes += run_test("test_programs/jump1.se", 0);

    std::cout << "        JUMP tests: " << passes << "/1" << std::endl;

    return (passes == 1) ? 1 : 0;
}

unsigned long long Tests::skipTests() {
    int passes = 0;
    std::cout << "    Running SKIP tests" << std::endl;
    passes += run_test("test_programs/ske1.se", 0);
    passes += run_test("test_programs/ske2.se", 255);
    passes += run_test("test_programs/skne1.se", 255);
    passes += run_test("test_programs/skne2.se", 1);

    passes += run_test("test_programs/skz1.se", 255);
    passes += run_test("test_programs/skz2.se", 5);
    passes += run_test("test_programs/sknz1.se", 0);
    passes += run_test("test_programs/sknz2.se", 255);
    passes += run_test("test_programs/skgt1.se", 255);
    passes += run_test("test_programs/skgt2.se", 1);

    std::cout << "        SKIP tests: " << passes << "/10" << std::endl;

    return (passes == 10) ? 1 : 0;
}

unsigned long long Tests::run_test(std::string file_name, unsigned long long rc_to_compare, bool should_fail, bool debug) {
    load_program(file_name);
    if (debug) {
        cpu->Dump();
    }
    auto rc = cpu->Start();
    if (rc_to_compare == rc || (should_fail && rc_to_compare != rc)) {
        std::cout << "            " << file_name << " PASS" << std::endl;
        return 1;
    } else {
        if (debug) {
            cpu->Dump();
        }
        std::cout << "            " << file_name << " RC: " << std::hex << (long long)rc << ", FAIL" << std::endl;
        return 0;
    }
}

void Tests::load_program(const std::string& file_name) {
    std::ifstream bin_file(file_name, std::ios::binary);

    int length;
    unsigned char*  program_data = new unsigned char[200];
    std::ostringstream ret;
    if (bin_file.is_open()) {
        length = dump(bin_file, program_data);
        bin_file.close();
        //std::cout << "SEARCH FOR ME" << std::endl;
        for (int i = 0; i < length; i++){
            //std::cout << "char" << std::endl;
            ret.str(std::string());
            //std::cout << program_data[i] << std::endl;
            ret << std::hex << std::setfill('0') << std::setw(2) << std::uppercase << (int) program_data[i];
            //std::cout << ret.str().substr(0, 2) << std::endl;
            //std::cout << (int)program_data[i] << std::endl << std::endl << std::endl;
            std::string temp_str = ret.str();
            temp_str = temp_str.substr(temp_str.length() - 2, temp_str.length());
            program_data[i] = (unsigned char)string_to_vector(temp_str);
            //std::cout << std::dec << (long long)((unsigned char)program_data[i]) << " " << (((unsigned char)program_data[i] > 255) ? "TRUE" : "FALSE") << std::endl << temp_str << std::endl << std::endl;
        }
        cpu = new CPU(program_data, length, false);
    }
}

unsigned char string_to_vector(std::basic_string<char> str) {
    unsigned char number = 0;
    number += hex_char_to_int( str[0] );
    number = (number << 4);
    unsigned char number2 = 0;
    number2 += hex_char_to_int( str[1] );
    number2 = number2 << 4;
    number2 = number2 >> 4;
    number = number + number2;

    return number;
}

unsigned char hex_char_to_int(char c) {
    unsigned char result = 0;
    if (('0' <= c) && (c <= '9')) {
        result = c - '0';
    } else if(('A' <= c) && (c <= 'F')) {
        result = 10 + c - 'A';
    }
    return result;
}

int Tests::dump(std::istream& ins, unsigned char* program_data) {
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
