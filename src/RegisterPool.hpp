#pragma once

#include <map>

class SymbolTable;

class RegisterPool {
    std::map<std::string, bool> registers;
    std::map<std::string, bool> argumentRegisters;

public:
    RegisterPool();

    std::string getRegister();

    std::string getArgRegister();

    void freeRegister(const std::string &);

    void clearArgRegisters();

    void saveRegisters(SymbolTable &) const;

    void loadRegisters(SymbolTable &) const;
};