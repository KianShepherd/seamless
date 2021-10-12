
for i in range(0, 4):
    print("        case 0x7{}00:".format(i))
    print("            registers[{}] = rand() % 101 + 1;".format(i))
    print("            break;")

for i in range(0, 4):
    for j in range(0, 4):
        print("        case 0xA{}{}0:".format(i, j))
        print("            registers[{}] = registers[{}];".format(i, j))
        print("            break;")