#include "../include/cpu.h"

CPU::CPU(unsigned char* program, int program_size) {
    pc = 0;
    registers = new long[MAX_REGISTERS];
    for (int i = 0; i < MAX_REGISTERS; i++)
        registers[i] = 0;
    
    stack = new unsigned char[MAX_STACK];
    for (int i = 0; i < MAX_STACK; i++) {
        if (i < program_size) {
            stack[i] = program[i];
        } else {
        stack[i] = 0;
        }
    }
        
}

CPU::~CPU() {

}

int NotImplemented(short op) {
    std::cout << "OP not implemented: " << std::hex << op << std::endl;
    return -1;
}

int CPU::Start() {
    return Update();
}

int CPU::Update() {
    if (pc + 1 >= 20)
        return 50;
    unsigned char first_half = stack[pc];
    unsigned char second_half = stack[pc + 1];
    unsigned short op = first_half;
    op = op << 8;
    op += second_half;

    if (op >= 0x1000 && op <= 0x1FFF) {
        unsigned short jmp = (op << 4);
        jmp = (jmp >> 4);
        pc = jmp;
        //std::cout << "OP: " <<  std::hex << op << std::endl << "PC: " <<  (int)pc << std::endl;
        return Update();
    }

    if (op >= 0x4000 && op <= 0x4FFF) {
        return NotImplemented(op);
    }

    std::cout << "OP: " <<  std::hex << op << std::endl;
    switch (op) {
        case 0x00E0: // Exit
            return 0;
        case 0x00EE: // Return
            return NotImplemented(op);
// ------------------------------- JUMPS ------------------------------------------------
        case 0x2100:
            pc = registers[pc + 2];
            break;
        case 0x2101:
            if (registers[0] == registers[1]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2102:
            if (registers[0] == registers[2]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2103:
            if (registers[0] == registers[3]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2110:
            if (registers[1] == registers[0]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2111:
            pc = registers[pc + 2];
            break;
        case 0x2112:
            if (registers[1] == registers[2]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2113:
            if (registers[1] == registers[3]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2120:
            if (registers[2] == registers[0]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2121:
            if (registers[2] == registers[1]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2122:
            pc = registers[pc + 2];
            break;
        case 0x2123:
            if (registers[2] == registers[3]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2130:
            if (registers[3] == registers[0]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2131:
            if (registers[3] == registers[1]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2132:
            if (registers[3] == registers[2]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2133:
            pc = registers[pc + 2];
            break;
        case 0x2200:
            pc++;
            break;
        case 0x2201:
            if (registers[0] != registers[1]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2202:
            if (registers[0] != registers[2]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2203:
            if (registers[0] != registers[3]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2210:
            if (registers[1] != registers[0]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2211:
            pc++;
            break;
        case 0x2212:
            if (registers[1] != registers[2]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2213:
            if (registers[1] != registers[3]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2220:
            if (registers[2] != registers[0]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2221:
            if (registers[2] != registers[1]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2222:
            pc++;
            break;
        case 0x2223:
            if (registers[2] != registers[3]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2230:
            if (registers[3] != registers[0]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2231:
            if (registers[3] != registers[1]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2232:
            if (registers[3] != registers[2]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2233:
            pc++;
            break;
        case 0x2300:
            pc++;
            break;
        case 0x2301:
            if (registers[0] > registers[1]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2302:
            if (registers[0] > registers[2]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2303:
            if (registers[0] > registers[3]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2310:
            if (registers[1] > registers[0]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2311:
            pc++;
            break;
        case 0x2312:
            if (registers[1] > registers[2]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2313:
            if (registers[1] > registers[3]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2320:
            if (registers[2] > registers[0]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2321:
            if (registers[2] > registers[1]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2322:
            pc++;
            break;
        case 0x2323:
            if (registers[2] > registers[3]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2330:
            if (registers[3] > registers[0]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2331:
            if (registers[3] > registers[1]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2332:
            if (registers[3] > registers[2]) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2333:
            pc++;
            break;
        case 0x2400:
            if (registers[0] == 0) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2401:
            if (registers[1] == 0) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2402:
            if (registers[2] == 0) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x2403:
            if (registers[3] == 0) {
                pc = registers[pc + 2];
            } else {
                pc++;
            }
            break;
        case 0x3000:
            std::cout << (int)registers[0] << std::endl;
            break;
        case 0x3001:
            std::cout << (int)registers[1] << std::endl;
            break;
        case 0x3002:
            std::cout << (int)registers[2] << std::endl;
            break;
        case 0x3003:
            std::cout << (int)registers[3] << std::endl;
            break;
// ------------------------------- SET REGISTER ------------------------------------------------
        case 0x5000:
            registers[0] = stack[pc + 2];
            pc++;
            break;
        case 0x5100:
            registers[1] = stack[pc + 2];
            pc++;
            break;
        case 0x5200:
            registers[2] = stack[pc + 2];
            pc++;
            break;
        case 0x5300:
            registers[3] = stack[pc + 2];
            pc++;
            break;
// ------------------------------- RANDOM ------------------------------------------------
        case 0x7000:
            registers[0] = rand() % 101 + 1;
            break;
        case 0x7100:
            registers[1] = rand() % 101 + 1;
            break;
        case 0x7200:
            registers[2] = rand() % 101 + 1;
            break;
        case 0x7300:
            registers[3] = rand() % 101 + 1;
            break;
// ------------------------------- MATH ------------------------------------------------
        case 0x8000:
            registers[0] += registers[0];
            break;
        case 0x8010:
            registers[0] += registers[1];
            break;
        case 0x8020:
            registers[0] += registers[2];
            break;
        case 0x8030:
            registers[0] += registers[3];
            break;
        case 0x8100:
            registers[1] += registers[0];
            break;
        case 0x8110:
            registers[1] += registers[1];
            break;
        case 0x8120:
            registers[1] += registers[2];
            break;
        case 0x8130:
            registers[1] += registers[3];
            break;
        case 0x8200:
            registers[2] += registers[0];
            break;
        case 0x8210:
            registers[2] += registers[1];
            break;
        case 0x8220:
            registers[2] += registers[2];
            break;
        case 0x8230:
            registers[2] += registers[3];
            break;
        case 0x8300:
            registers[3] += registers[0];
            break;
        case 0x8310:
            registers[3] += registers[1];
            break;
        case 0x8320:
            registers[3] += registers[2];
            break;
        case 0x8330:
            registers[3] += registers[3];
            break;
        case 0x8001:
            registers[0] |= registers[0];
            break;
        case 0x8011:
            registers[0] |= registers[1];
            break;
        case 0x8021:
            registers[0] |= registers[2];
            break;
        case 0x8031:
            registers[0] |= registers[3];
            break;
        case 0x8101:
            registers[1] |= registers[0];
            break;
        case 0x8111:
            registers[1] |= registers[1];
            break;
        case 0x8121:
            registers[1] |= registers[2];
            break;
        case 0x8131:
            registers[1] |= registers[3];
            break;
        case 0x8201:
            registers[2] |= registers[0];
            break;
        case 0x8211:
            registers[2] |= registers[1];
            break;
        case 0x8221:
            registers[2] |= registers[2];
            break;
        case 0x8231:
            registers[2] |= registers[3];
            break;
        case 0x8301:
            registers[3] |= registers[0];
            break;
        case 0x8311:
            registers[3] |= registers[1];
            break;
        case 0x8321:
            registers[3] |= registers[2];
            break;
        case 0x8331:
            registers[3] |= registers[3];
            break;
        case 0x8002:
            registers[0] &= registers[0];
            break;
        case 0x8012:
            registers[0] &= registers[1];
            break;
        case 0x8022:
            registers[0] &= registers[2];
            break;
        case 0x8032:
            registers[0] &= registers[3];
            break;
        case 0x8102:
            registers[1] &= registers[0];
            break;
        case 0x8112:
            registers[1] &= registers[1];
            break;
        case 0x8122:
            registers[1] &= registers[2];
            break;
        case 0x8132:
            registers[1] &= registers[3];
            break;
        case 0x8202:
            registers[2] &= registers[0];
            break;
        case 0x8212:
            registers[2] &= registers[1];
            break;
        case 0x8222:
            registers[2] &= registers[2];
            break;
        case 0x8232:
            registers[2] &= registers[3];
            break;
        case 0x8302:
            registers[3] &= registers[0];
            break;
        case 0x8312:
            registers[3] &= registers[1];
            break;
        case 0x8322:
            registers[3] &= registers[2];
            break;
        case 0x8332:
            registers[3] &= registers[3];
            break;
        case 0x8003:
            registers[0] ^= registers[0];
            break;
        case 0x8013:
            registers[0] ^= registers[1];
            break;
        case 0x8023:
            registers[0] ^= registers[2];
            break;
        case 0x8033:
            registers[0] ^= registers[3];
            break;
        case 0x8103:
            registers[1] ^= registers[0];
            break;
        case 0x8113:
            registers[1] ^= registers[1];
            break;
        case 0x8123:
            registers[1] ^= registers[2];
            break;
        case 0x8133:
            registers[1] ^= registers[3];
            break;
        case 0x8203:
            registers[2] ^= registers[0];
            break;
        case 0x8213:
            registers[2] ^= registers[1];
            break;
        case 0x8223:
            registers[2] ^= registers[2];
            break;
        case 0x8233:
            registers[2] ^= registers[3];
            break;
        case 0x8303:
            registers[3] ^= registers[0];
            break;
        case 0x8313:
            registers[3] ^= registers[1];
            break;
        case 0x8323:
            registers[3] ^= registers[2];
            break;
        case 0x8333:
            registers[3] ^= registers[3];
            break;
        case 0x8004:
            registers[0] -= registers[0];
            break;
        case 0x8014:
            registers[0] -= registers[1];
            break;
        case 0x8024:
            registers[0] -= registers[2];
            break;
        case 0x8034:
            registers[0] -= registers[3];
            break;
        case 0x8104:
            registers[1] -= registers[0];
            break;
        case 0x8114:
            registers[1] -= registers[1];
            break;
        case 0x8124:
            registers[1] -= registers[2];
            break;
        case 0x8134:
            registers[1] -= registers[3];
            break;
        case 0x8204:
            registers[2] -= registers[0];
            break;
        case 0x8214:
            registers[2] -= registers[1];
            break;
        case 0x8224:
            registers[2] -= registers[2];
            break;
        case 0x8234:
            registers[2] -= registers[3];
            break;
        case 0x8304:
            registers[3] -= registers[0];
            break;
        case 0x8314:
            registers[3] -= registers[1];
            break;
        case 0x8324:
            registers[3] -= registers[2];
            break;
        case 0x8334:
            registers[3] -= registers[3];
            break;
        case 0x8005:
            registers[0] *= registers[0];
            break;
        case 0x8015:
            registers[0] *= registers[1];
            break;
        case 0x8025:
            registers[0] *= registers[2];
            break;
        case 0x8035:
            registers[0] *= registers[3];
            break;
        case 0x8105:
            registers[1] *= registers[0];
            break;
        case 0x8115:
            registers[1] *= registers[1];
            break;
        case 0x8125:
            registers[1] *= registers[2];
            break;
        case 0x8135:
            registers[1] *= registers[3];
            break;
        case 0x8205:
            registers[2] *= registers[0];
            break;
        case 0x8215:
            registers[2] *= registers[1];
            break;
        case 0x8225:
            registers[2] *= registers[2];
            break;
        case 0x8235:
            registers[2] *= registers[3];
            break;
        case 0x8305:
            registers[3] *= registers[0];
            break;
        case 0x8315:
            registers[3] *= registers[1];
            break;
        case 0x8325:
            registers[3] *= registers[2];
            break;
        case 0x8335:
            registers[3] *= registers[3];
            break;
        case 0x8006:
            registers[0] /= registers[0];
            break;
        case 0x8016:
            registers[0] /= registers[1];
            break;
        case 0x8026:
            registers[0] /= registers[2];
            break;
        case 0x8036:
            registers[0] /= registers[3];
            break;
        case 0x8106:
            registers[1] /= registers[0];
            break;
        case 0x8116:
            registers[1] /= registers[1];
            break;
        case 0x8126:
            registers[1] /= registers[2];
            break;
        case 0x8136:
            registers[1] /= registers[3];
            break;
        case 0x8206:
            registers[2] /= registers[0];
            break;
        case 0x8216:
            registers[2] /= registers[1];
            break;
        case 0x8226:
            registers[2] /= registers[2];
            break;
        case 0x8236:
            registers[2] /= registers[3];
            break;
        case 0x8306:
            registers[3] /= registers[0];
            break;
        case 0x8316:
            registers[3] /= registers[1];
            break;
        case 0x8326:
            registers[3] /= registers[2];
            break;
        case 0x8336:
            registers[3] /= registers[3];
            break;
// ------------------------------- SKIPS ------------------------------------------------
        case 0x9000:
            if (registers[0] == 0)
                pc += 2;
            break;
        case 0x9010:
            if (registers[1] == 0)
                pc += 2;
            break;
        case 0x9020:
            if (registers[2] == 0)
                pc += 2;
            break;
        case 0x9030:
            if (registers[3] == 0)
                pc += 2;
            break;
        case 0x9001:
            if (registers[0] != 0)
                pc += 2;
            break;
        case 0x9011:
            if (registers[1] != 0)
                pc += 2;
            break;
        case 0x9021:
            if (registers[2] != 0)
                pc += 2;
            break;
        case 0x9031:
            if (registers[3] != 0)
                pc += 2;
            break;
        case 0x9100:
            pc += 2;
            break;
        case 0x9101:
            if (registers[0] == registers[1])
                pc += 2;
            break;
        case 0x9102:
            if (registers[0] == registers[2])
                pc += 2;
            break;
        case 0x9103:
            if (registers[0] == registers[3])
                pc += 2;
            break;
        case 0x9110:
            if (registers[1] == registers[0])
                pc += 2;
            break;
        case 0x9111:
            pc += 2;
            break;
        case 0x9112:
            if (registers[1] == registers[2])
                pc += 2;
            break;
        case 0x9113:
            if (registers[1] == registers[3])
                pc += 2;
            break;
        case 0x9120:
            if (registers[2] == registers[0])
                pc += 2;
            break;
        case 0x9121:
            if (registers[2] == registers[1])
                pc += 2;
            break;
        case 0x9122:
            pc += 2;
            break;
        case 0x9123:
            if (registers[2] == registers[3])
                pc += 2;
            break;
        case 0x9130:
            if (registers[3] == registers[0])
                pc += 2;
            break;
        case 0x9131:
            if (registers[3] == registers[1])
                pc += 2;
            break;
        case 0x9132:
            if (registers[3] == registers[2])
                pc += 2;
            break;
        case 0x9133:
            pc += 2;
            break;
        case 0x9200:
            break;
        case 0x9201:
            if (registers[0] != registers[1])
                pc += 2;
            break;
        case 0x9202:
            if (registers[0] != registers[2])
                pc += 2;
            break;
        case 0x9203:
            if (registers[0] != registers[3])
                pc += 2;
            break;
        case 0x9210:
            if (registers[1] != registers[0])
                pc += 2;
            break;
        case 0x9211:
            break;
        case 0x9212:
            if (registers[1] != registers[2])
                pc += 2;
            break;
        case 0x9213:
            if (registers[1] != registers[3])
                pc += 2;
            break;
        case 0x9220:
            if (registers[2] != registers[0])
                pc += 2;
            break;
        case 0x9221:
            if (registers[2] != registers[1])
                pc += 2;
            break;
        case 0x9222:
            break;
        case 0x9223:
            if (registers[2] != registers[3])
                pc += 2;
            break;
        case 0x9230:
            if (registers[3] != registers[0])
                pc += 2;
            break;
        case 0x9231:
            if (registers[3] != registers[1])
                pc += 2;
            break;
        case 0x9232:
            if (registers[3] != registers[2])
                pc += 2;
            break;
        case 0x9233:
            break;
        case 0x9300:
            break;
        case 0x9301:
            if (registers[0] > registers[1])
                pc += 2;
            break;
        case 0x9302:
            if (registers[0] > registers[2])
                pc += 2;
            break;
        case 0x9303:
            if (registers[0] > registers[3])
                pc += 2;
            break;
        case 0x9310:
            if (registers[1] > registers[0])
                pc += 2;
            break;
        case 0x9311:
            break;
        case 0x9312:
            if (registers[1] > registers[2])
                pc += 2;
            break;
        case 0x9313:
            if (registers[1] > registers[3])
                pc += 2;
            break;
        case 0x9320:
            if (registers[2] > registers[0])
                pc += 2;
            break;
        case 0x9321:
            if (registers[2] > registers[1])
                pc += 2;
            break;
        case 0x9322:
            break;
        case 0x9323:
            if (registers[2] > registers[3])
                pc += 2;
            break;
        case 0x9330:
            if (registers[3] > registers[0])
                pc += 2;
            break;
        case 0x9331:
            if (registers[3] > registers[1])
                pc += 2;
            break;
        case 0x9332:
            if (registers[3] > registers[2])
                pc += 2;
            break;
        case 0x9333:
            break;
// ------------------------------- LOADS ------------------------------------------------
        case 0xA000:
            break;
        case 0xA010:
            registers[0] = registers[1];
            break;
        case 0xA020:
            registers[0] = registers[2];
            break;
        case 0xA030:
            registers[0] = registers[3];
            break;
        case 0xA100:
            registers[1] = registers[0];
            break;
        case 0xA110:
            break;
        case 0xA120:
            registers[1] = registers[2];
            break;
        case 0xA130:
            registers[1] = registers[3];
            break;
        case 0xA200:
            registers[2] = registers[0];
            break;
        case 0xA210:
            registers[2] = registers[1];
            break;
        case 0xA220:
            break;
        case 0xA230:
            registers[2] = registers[3];
            break;
        case 0xA300:
            registers[3] = registers[0];
            break;
        case 0xA310:
            registers[3] = registers[1];
            break;
        case 0xA320:
            registers[3] = registers[2];
            break;
        case 0xA330:
            break;
        default:
            return NotImplemented(op);
    }

    pc += 2;
    return Update();
}

void CPU::Dump() {
    std::cout << std::endl << std::endl  << "Program Counter: " << (int)pc << std::endl << "Registers: [";

    for (int i = 0; i < MAX_REGISTERS; i++) {
        std::cout << registers[i];
        if (i < MAX_REGISTERS - 1) {
            std::cout << ", ";
        }
    }
        
    std::cout << "]" << std::endl << "Stack: [";

    for (int i = 0; i < MAX_STACK / 10; i++) {
        std::cout << std::hex << (int)stack[i];
        if (i < ((MAX_STACK / 10) - 1)) {
            std::cout << ", ";
        }
        if (i % 25 == 0 && i != 0) {
            std::cout << std::endl;
        }
    }
        

    std::cout << "]" << std::endl << std::endl << std::endl;
}