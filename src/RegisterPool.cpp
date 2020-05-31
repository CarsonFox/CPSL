#include "RegisterPool.hpp"

#include <iostream>

RegisterPool::RegisterPool() {
    registers = {
            {"$t0", false},
            {"$t1", false},
            {"$t2", false},
            {"$t3", false},
            {"$t4", false},
            {"$t5", false},
            {"$t6", false},
            {"$t7", false},};

    argumentRegisters = {
            {"$a0", false},
            {"$a1", false},
            {"$a2", false},
            {"$a3", false},
            //Fall back on the saved registers when passing arguments
            {"$s0", false},
            {"$s1", false},
            {"$s2", false},
            {"$s3", false},
            {"$s4", false},
            {"$s5", false},
            {"$s6", false},
            {"$s7", false},};
}

std::string RegisterPool::getRegister() {
    for (const auto &[reg, inUse]: registers) {
        if (!inUse) {
            registers[reg] = true;
            return reg;
        }
    }
    std::cerr << "All temporary registers in use\n";
    std::exit(3);
}

std::string RegisterPool::getArgRegister() {
    for (const auto &[reg, inUse]: argumentRegisters) {
        if (!inUse) {
            registers[reg] = true;
            return reg;
        }
    }
    std::cerr << "All argument registers in use\n";
    std::exit(15);
}

void RegisterPool::freeRegister(const std::string &reg) {
    registers[reg] = false;
}

void RegisterPool::clearArgRegisters() {
    for (auto &it: argumentRegisters) {
        it.second = false;
    }
}

/*
 * In a subroutine, mark all registers used. Then at the beginning of the subroutine,
 * emit code to save those registers' values to the stack. At the end or in a return statement,
 * load those values back into registers.
 */