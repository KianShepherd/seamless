import sys
import os
ops = dict()

hex_vals = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
registers = ['0', '1', '2', '3']
nums = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

ops['CLS'] = "00E0"
ops['RET'] = "00EE"


for i in nums:
    for j in nums:
        for k in nums:
            pc = int(str(i+j+k))
            pc = (hex(pc)[2:]).upper()
            while len(pc) < 3:
                pc = "0" + pc
            ops["JMP " + i + j + k] = "4" + pc
            

for i in registers:
    ops["PRNT " + i] = "300" + i

for i in registers:
    ops["PRNT_CHAR " + i] = "301" + i

for i in nums:
    for j in nums:
        for k in nums:
            pc = int(str(i+j+k))
            pc = (hex(pc)[2:]).upper()
            while len(pc) < 3:
                pc = "0" + pc
            ops["CALL " + i + j + k] = "4" + pc

for i in registers:
    ops["RND " + i] = "7" + i + "00"

for i in registers:
    for j in registers:
        ops["ADD " + i + ", " + j] = "8" + i + j + "0"

for i in registers:
    for j in registers:
        ops["OR " + i + ", " + j] = "8" + i + j + "1"

for i in registers:
    for j in registers:
        ops["AND " + i + ", " + j] = "8" + i + j + "2"

for i in registers:
    for j in registers:
        ops["XOR " + i + ", " + j] = "8" + i + j + "3"

for i in registers:
    for j in registers:
        ops["SUB " + i + ", " + j] = "8" + i + j + "4"

for i in registers:
    for j in registers:
        ops["MUL " + i + ", " + j] = "8" + i + j + "5"

for i in registers:
    for j in registers:
        ops["DIV " + i + ", " + j] = "8" + i + j + "6"

for i in registers:
    ops["SKZ " + i] = "90" + i + "0"

for i in registers:
    ops["SKNZ " + i] = "90" + i + "1"

for i in registers:
    for j in registers:
        ops["SKE " + i + ", " + j] = "91" + i + j

for i in registers:
    for j in registers:
        ops["SKNE " + i + ", " + j] = "92" + i + j

for i in registers:
    for j in registers:
        ops["SKGT " + i + ", " + j] = "93" + i + j

for i in registers:
    for j in registers:
        ops["LD " + i + ", " + j] = "A" + i + j + "0"

for i in registers:
    ops["DBG " + i] = "FFF" + i

def handle_SET(sasm_str):
    split_str = sasm_str.split()
    if split_str[0] == "SET":
        ret_str = "5" + split_str[1][:-1]
        value = int(split_str[2])
        if value <= 255:
            value = str(hex(value))
            value = value[2:].upper()
            if len(value) < 2:
                value = "0" + value
            ret_str = ret_str + "00"
        elif value <= 65535:
            value = str(hex(value))
            value = value[2:].upper()
            while len(value) < 4:
                value = "0" + value
            ret_str = ret_str + "01"
        elif value <= 4294967295:
            value = str(hex(value))
            value = value[2:].upper()
            while len(value) < 8:
                value = "0" + value
            ret_str = ret_str + "02"
        else:
            value = str(hex(value))
            value = (value[2:].upper())[:16]
            while len(value) < 16:
                value = "0" + value
            ret_str = ret_str + "03"
        return ret_str + str(value)
    else:
        return ""


def handle_LOAD(sasm_str):
    # "SET 1, 99"
    split_str = sasm_str.split()
    if split_str[0] == "LOAD":
        ret_str = "6" + split_str[1][:-1]
        value = int(split_str[2])
        if value <= 255:
            value = str(hex(value))
            value = value[2:].upper()
            if len(value) < 2:
                value = "0" + value
            ret_str = ret_str + "00"
        elif value <= 65535:
            value = str(hex(value))
            value = value[2:].upper()
            while len(value) < 4:
                value = "0" + value
            ret_str = ret_str + "01"
        elif value <= 4294967295:
            value = str(hex(value))
            value = value[2:].upper()
            while len(value) < 8:
                value = "0" + value
            ret_str = ret_str + "02"
        else:
            value = str(hex(value))
            value = (value[2:].upper())[:16]
            while len(value) < 16:
                value = "0" + value
            ret_str = ret_str + "03"
        return ret_str + str(value)
    else:
        return ""


def handle_STORE(sasm_str):
    # "SET 1, 99"
    split_str = sasm_str.split()
    if split_str[0] == "STORE":
        ret_str = "6" + split_str[1][:-1]
        value = int(split_str[2])
        if value <= 255:
            value = str(hex(value))
            value = value[2:].upper()
            if len(value) < 2:
                value = "0" + value
            ret_str = ret_str + "10"
        elif value <= 65535:
            value = str(hex(value))
            value = value[2:].upper()
            while len(value) < 4:
                value = "0" + value
            ret_str = ret_str + "11"
        elif value <= 4294967295:
            value = str(hex(value))
            value = value[2:].upper()
            while len(value) < 8:
                value = "0" + value
            ret_str = ret_str + "12"
        else:
            value = str(hex(value))
            value = (value[2:].upper())[:16]
            while len(value) < 16:
                value = "0" + value
            ret_str = ret_str + "13"
        return ret_str + str(value)
    else:
        return ""

def handle_JUMP(sasm_str):
    split_str = sasm_str.split()
    ret_str = "2"
    first_reg = split_str[1][:-1]
    second_reg = split_str[2][:-1]
    if len(split_str) < 4:
        jump_location = str(hex(int(split_str[2])))
    else:
        jump_location = str(hex(int(split_str[3])))
    jump_location = jump_location[2:].upper()
    while len(jump_location) < 2:
        jump_location = "0" + jump_location
    if split_str[0] == "JE":
        ret_str = ret_str + "1" + first_reg + second_reg + str(jump_location)
    elif split_str[0] == "JNE":
        ret_str = ret_str + "2" + first_reg + second_reg + str(jump_location)
    elif split_str[0] == "JGT":
        ret_str = ret_str + "3" + first_reg + second_reg + str(jump_location)
    elif split_str[0] == "JZ":
        ret_str = ret_str + "40" + first_reg + str(jump_location)
    else: 
        return "";
    return ret_str;

if __name__ == "__main__":
    if len(sys.argv) > 1:
        for i in range(1, len(sys.argv)):
            out = ""
            filename = sys.argv[i]
            extension = os.path.splitext(filename)[1]
            basename = os.path.splitext(filename)[0]
            if extension != ".sasm":
                print("Unknown filetype, only .sasm files will be processed.")
            f = open(filename, 'r')
            for line in f.readlines():
                line = line.strip().upper()
                if line in ops.keys():
                    out = out + ops[line]
                else:
                    temp = handle_SET(line) + handle_STORE(line) + handle_LOAD(line) + handle_JUMP(line)
                    if len(temp) > 0:
                        out = out + temp
                    else:
                        print("Line not known: {}".format(line))
            f.close()
            print(out)
            f = open(basename + ".se", 'wb')
            bytes_arr = []
            for j in range(0, len(out) - 1, 2):
                bytes_arr.append(int(out[j] + out[j + 1], 16))
            f.write(bytearray(bytes_arr))
            f.close()
