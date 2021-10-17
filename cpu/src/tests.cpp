#include "../include/tests.h"

int Tests::run() {
    addTest();
    subTest();
    setTest();
    return 0;
}

Tests::Tests() {
    auto program_data = new char[0];
    cpu = new CPU(program_data, 0);
}

int Tests::addTest() {
    load_program("test_programs/add1.se");
    auto rc = cpu->Start();
    std::cout << "Starting ADD test 1 RC: " << (int)rc << ", " << ((8 == rc) ? " PASS" : " FAIL") << std::endl;
    load_program("test_programs/add2.se");
    rc = cpu->Start();
    std::cout << "Starting ADD test 2 RC: " << (int)rc << ", " << ((33 == rc) ? " PASS" : " FAIL") << std::endl;
    load_program("test_programs/add3.se");
    rc = cpu->Start();
    std::cout << "Starting ADD test 3 RC: " << (int)rc << ", " << ((16 == rc) ? " PASS" : " FAIL") << std::endl;
    load_program("test_programs/add4.se");
    rc = cpu->Start();
    std::cout << "Starting ADD test 4 RC: " << (int)rc << ", " << ((326 == rc) ? " PASS" : " FAIL") << std::endl;
    return 0;
}

int Tests::subTest() {
    load_program("test_programs/sub.se");
    auto rc = cpu->Start();
    std::cout << "Starting SUB test RC: " << rc << ", " << ((2 == rc) ? " PASS" : " FAIL") << std::endl;
    return 0;
}

int Tests::setTest() {
    load_program("test_programs/set1.se");
    auto rc = cpu->Start();
    std::cout << "Starting SET test 1 RC: " << rc << ", " << ((276 == rc) ? " PASS" : " FAIL") << std::endl;
    return 0;
}

void Tests::load_program(const std::string& file_name) {
    std::ifstream bin_file(file_name, std::ios::binary);

    int length;
    char*  program_data = new char[200];
    if (bin_file.is_open()) {
        length = dump(bin_file, program_data);
        bin_file.close();
        cpu = new CPU(program_data, length);
    }
}

int Tests::dump(std::istream& ins, char* program_data ) {
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
