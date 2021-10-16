

for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x21{}{}:".format(i, j))
        print("            if (registers[{}] == registers[{}]) {{".format(i, j))
        print("                pc = (int)registers[pc + 2];")
        print("            } else {")
        print("                pc++;")
        print("            }")
        print("            break;")




for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x22{}{}:".format(i, j))
        print("            if (registers[{}] != registers[{}]) {{".format(i, j))
        print("                pc = (int)registers[pc + 2];")
        print("            } else {")
        print("                pc++;")
        print("            }")
        print("            break;")
        


for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x23{}{}:".format(i, j))
        print("            if (registers[{}] > registers[{}]) {{".format(i, j))
        print("                pc = (int)registers[pc + 2];")
        print("            } else {")
        print("                pc++;")
        print("            }")
        print("            break;")



for i in range(0, 4):
        print("        case 0x240{}:".format(i))
        print("            if (registers[{}] == 0) {{\n                pc = (int)registers[pc + 2];\n            }} else {{\n                pc++;\n            }}\n            break;".format(i))
