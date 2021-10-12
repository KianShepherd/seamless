for i in range(0, 4):
    print("        case 0x90{}0:".format(i))
    print("            if (registers[{}] == 0) ".format(i))
    print("                pc += 2;")
    print("            break;")

for i in range(0, 4):
    print("        case 0x90{}1:".format(i))
    print("            if (registers[{}] != 0) ".format(i))
    print("                pc += 2;")
    print("            break;")

for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x91{}{}:".format(i, j))
        print("            if (registers[{}] == registers[{}]) ".format(i, j))
        print("                pc += 2;")
        print("            break;")

for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x92{}{}:".format(i, j))
        print("            if (registers[{}] != registers[{}]) ".format(i, j))
        print("                pc += 2;")
        print("            break;")

for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x93{}{}:".format(i, j))
        print("            if (registers[{}] > registers[{}]) ".format(i, j))
        print("                pc += 2;")
        print("            break;")