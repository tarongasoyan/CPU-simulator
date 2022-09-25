#include <iostream>
#include <string>
#include <map>
#include <fstream>

class My_CPU 
{
public:
    My_CPU() {
        ist["mov"] = &My_CPU::mov;
        ist["add"] = &My_CPU::add;
        ist["div"] = &My_CPU::div;
        ist["mul"] = &My_CPU::mul;
        ist["sub"] = &My_CPU::sub;
        is["inc"] = &My_CPU::inc;
        is["dec"] = &My_CPU::dec;
        // is["jmp"] = &My_CPU::jmp;
        //ist["cmp"] = &My_CPU::cmp;
    }
    void read(std::ifstream&);
    void mov(std::string&, std::string&);
    void add(std::string&, std::string&);
    void div(std::string&, std::string&);
    void mul(std::string&, std::string&);
    void sub(std::string&, std::string&);
    bool cmp(std::string&, std::string&);
    void inc(std::string&);
    void dec(std::string&);
    void jmp(std::string&);
    bool is_register(std::string&);
    bool is_operator(std::string&);
    bool is_jle(std::string&,std::string&);
private:
    std::map<std::string,void(My_CPU::*)(std::string&,std::string&)> ist;
    std::map<std::string,std::string> rg;
    std::map<std::string,void(My_CPU::*)(std::string&)> is;
};

void My_CPU::dec(std::string& reg) {
    int register1 = std::stoi(rg[reg]);
    register1 += 1;
    rg[reg] = std::to_string(register1);
}

void My_CPU::inc(std::string& reg) {
    int register1 = std::stoi(rg[reg]);
    register1 += 1;
    rg[reg] = std::to_string(register1);
}

bool My_CPU::is_jle(std::string& reg1, std::string& reg2) {
    if (is_register(reg2)) {
        int register1 = std::stoi(rg[reg1]);
        int register2 = std::stoi(rg[reg2]);
        if (register1 <= register2) {
            return true;
        }
    } else {
        int register1 = std::stoi(rg[reg1]);
        int register2 = std::stoi(reg2);
        if (register1 <= register2) {
            return true;
        }
    }
    return false;
}



void My_CPU::sub(std::string& reg1, std::string& reg2) {
    if (is_register(reg2)) {
    int register1 = std::stoi(rg[reg1]);
    int register2 = std::stoi(rg[reg2]);
    register1 -= register2;
    rg[reg1] = std::to_string(register1);
    } else {
        int register1 = std::stoi(rg[reg1]);
        int register2 = std::stoi(reg2);
        register1 -= register2;
        rg[reg1] = std::to_string(register1);
    }
}

void My_CPU::mul(std::string& reg1, std::string& reg2) {
    if (is_register(reg2)) {
    int register1 = std::stoi(rg[reg1]);
    int register2 = std::stoi(rg[reg2]);
    register1 *= register2;
    rg[reg1] = std::to_string(register1);
    } else {
        int register1 = std::stoi(rg[reg1]);
        int register2 = std::stoi(reg2);
        register1 *= register2;
        rg[reg1] = std::to_string(register1);
    }
}

void My_CPU::div(std::string& reg1, std::string& reg2) {
    if (is_register(reg2)) {
    int register1 = std::stoi(rg[reg1]);
    int register2 = std::stoi(rg[reg2]);
    register1 /= register2;
    rg[reg1] = std::to_string(register1);
    } else {
        int register1 = std::stoi(rg[reg1]);
        int register2 = std::stoi(reg2);
        register1 /= register2;
        rg[reg1] = std::to_string(register1);
    }
}

void My_CPU::add(std::string& reg1, std::string& reg2) {
    if (is_register(reg2)) {
    int register1 = std::stoi(rg[reg1]);
    int register2 = std::stoi(rg[reg2]);
    register1 += register2;
    rg[reg1] = std::to_string(register1);
    } else {
        int register1 = std::stoi(rg[reg1]);
        int register2 = std::stoi(reg2);
        register1 += register2;
        rg[reg1] = std::to_string(register1);
    }
}

void My_CPU::mov(std::string& reg, std::string& operand) {
    rg[reg] = operand;
}

bool My_CPU::is_operator(std::string& oper) {
    if (oper == "r1") {
        return 1;
    } else if (oper == "mov") {
        return 2;
    } else if (oper == "add") {
        return 3;
    } else if (oper == "mul") {
        return 4;
    } else if (oper == "div") {
        return 5;
    } else if (oper == "sub") {
        return 6;
    } else if (oper == "cmp") {
        return 7;
    } else if (oper == "jmp") {
        return 8;
    } else if (oper == "jle") {
        return 9;
    } else if (oper == "jge") {
        return 10;
    } 
    return 0;
}

bool My_CPU::is_register(std::string& reg) {
    if (reg == "r1") {
        return 1;
    } else if (reg == "r2") {
        return 2;
    } else if (reg == "r3") {
        return 3;
    } else if (reg == "r4") {
        return 4;
    } else if (reg == "r5") {
        return 5;
    } else if (reg == "r6") {
        return 6;
    } else if (reg == "r7") {
        return 7;
    } else if (reg == "r8") {
        return 8;
    } else if (reg == "r9") {
        return 9;
    } else if (reg == "r10") {
        return 10;
    } 
    return 0;
}

void My_CPU::read(std::ifstream& fin) {
    fin.open("in.txt");
    if (!fin.is_open()) {
        std::cout << "File isn't open:" << std::endl;
    } else {
        std::string oper;
        std::string reg;
        std::string operand;
        
        while (!fin.eof()) {
            fin >> oper;
            fin >> reg;
            fin >> operand;
            if (oper == "inc" || oper == "dec" || oper == "jmp") {
                (this->*is[oper])(reg);
            }
            else if (is_register(reg) == 0 || is_operator(oper) == 0) {
                    std::cout << "Program undifined" << std::endl;
                    break;
            } else {
                (this->*ist[oper])(reg,operand);
            }
        }
        
        std::cout << rg["r1"];
    }
    fin.close();
}

int main() {
    My_CPU cpu;
    std::ifstream fin;
    cpu.read(fin);
    
    return 0;
}
