#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>

class My_CPU 
{
public:
    My_CPU();
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
    std::map<std::string, void(My_CPU::*)(std::string&, std::string&)> ist;
    std::map<std::string, std::string> rg;
    std::map<std::string, void(My_CPU::*)(std::string&)> is;
};
