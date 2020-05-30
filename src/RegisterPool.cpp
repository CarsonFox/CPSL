#include "RegisterPool.hpp"

#include <iostream>

RegisterPool::RegisterPool() : registers({
                                                 {"$t0", false},
                                                 {"$t1", false},
                                                 {"$t2", false},
                                                 {"$t3", false},
                                                 {"$t4", false},
                                                 {"$t5", false},
                                                 {"$t6", false},
                                                 {"$t7", false},
                                                 {"$s0", false},
                                                 {"$s1", false},
                                                 {"$s2", false},
                                                 {"$s3", false},
                                                 {"$s4", false},
                                                 {"$s5", false},
                                                 {"$s6", false},
                                                 {"$s7", false},
                                         }) {}

std::string RegisterPool::getRegister() {
    for (const auto &[reg, inUse]: registers) {
        if (!inUse) {
            registers[reg] = true;
            return reg;
        }
    }
    std::cerr << "All 16 registers in use\n";
    std::exit(3);
}

void RegisterPool::freeRegister(const std::string &reg) {
    registers[reg] = false;
}

void RegisterPool::clearRegisters() {
    for (auto &it: registers) {
        it.second = false;
    }
}
