print("// ------------------------------- SET u8 ------------------------------------------------")
for i in range(4):
    string = "        case 0x5{}00:\n" \
             "            registers[{}] = stack[pc + 2];\n" \
             "            pc++;\n" \
             "            break;".format(i, i)
    print(string)
print("// ------------------------------- SET u16 ------------------------------------------------")
for i in range(4):
    string = "        case 0x5{}01:\n" \
             "            temp_short = 0;\n" \
             "            for (int i = 2; i < 4; i++) {{\n" \
             "                temp_int += stack[pc + i];\n" \
             "            }}\n" \
             "            registers[{}] = temp_int;\n" \
             "            pc++;pc++;pc++;pc++;\n" \
             "            break;".format(i, i)
    print(string)
print("// ------------------------------- SET u32 ------------------------------------------------")
for i in range(4):
    string = "        case 0x5{}02:\n" \
             "            temp_int = 0;\n" \
             "            for (int i = 2; i < 6; i++) {{\n" \
             "                temp_int += stack[pc + i];\n" \
             "            }}\n" \
             "            registers[{}] = temp_int;\n" \
             "            pc++;pc++;pc++;pc++;\n" \
             "            break;".format(i, i)
    print(string)

print("// ------------------------------- SET u64 ------------------------------------------------")
for i in range(4):
    string = "        case 0x5{}03:\n" \
             "            temp_long = 0;\n" \
             "            for (int i = 2; i < 10; i++) {{\n" \
             "                temp_long += stack[pc + i];\n" \
             "            }}\n" \
             "            registers[{}] = temp_long;\n" \
             "            pc++;pc++;pc++;pc++;pc++;pc++;pc++;pc++;\n" \
             "            break;".format(i, i)
    print(string)
