#pragma once

#include <map>

class RegisterPool {
    std::map<std::string, bool> registers;

public:
    RegisterPool();

    std::string getRegister();

    void freeRegister(const std::string &);
};