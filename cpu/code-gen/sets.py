print("// ------------------------------- SET u8 ------------------------------------------------")
for i in range(4):
    string = "        case 0x5{}00:\n" \
             "            registers[{}] = stack[pc + 2];\n" \
             "            pc++;\n" \
             "            break;".format(i, i)
    print(string)
print("// ------------------------------- SET u16 ------------------------------------------------")
for i in range(4):
    print("        case 0x5{}01:".format(i))
    print("            temp_short = 0;")
    print("            for (int i = 2; i < 4; i++) {")
    print("                temp_short += stack[pc + i];")
    print("                if (i != 3) {")
    print("                    temp_short = temp_short << 8;")
    print("                }")
    print("            }")
    print("            registers[{}] = temp_short;".format(i))
    print("            pc++;pc++;")
    print("            break;")

print("// ------------------------------- SET u32 ------------------------------------------------")
for i in range(4):
    string = "        case 0x5{}02:\n" \
             "            temp_int = 0;\n" \
             "            for (int i = 2; i < 6; i++) {{\n" \
             "                temp_int += stack[pc + i];\n" \
             "                if (i != 5) {{\n" \
             "                    temp_int = temp_int << 8;\n" \
             "                }}\n" \
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
             "                if (i != 9) {{\n" \
             "                    temp_long = temp_long << 8;\n" \
             "                }}\n" \
             "            }}\n" \
             "            registers[{}] = temp_long;\n" \
             "            pc++;pc++;pc++;pc++;pc++;pc++;pc++;pc++;\n" \
             "            break;".format(i, i)
    print(string)
