for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x8{}{}0:".format(i, j))
        print("            registers[{}] += registers[{}];".format(i, j))
        print("            break;")

for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x8{}{}1:".format(i, j))
        print("            registers[{}] |= registers[{}];".format(i, j))
        print("            break;")

for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x8{}{}2:".format(i, j))
        print("            registers[{}] &= registers[{}];".format(i, j))
        print("            break;")

for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x8{}{}3:".format(i, j))
        print("            registers[{}] ^= registers[{}];".format(i, j))
        print("            break;")

for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x8{}{}4:".format(i, j))
        print("            registers[{}] -= registers[{}];".format(i, j))
        print("            break;")

for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x8{}{}5:".format(i, j))
        print("            registers[{}] *= registers[{}];".format(i, j))
        print("            break;")

for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0x8{}{}6:".format(i, j))
        print("            registers[{}] /= registers[{}];".format(i, j))
        print("            break;")