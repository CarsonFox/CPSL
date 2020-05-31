#include "RegisterPool.hpp"

#include <iostream>
#include <sstream>

#include "src/AST/Types/BuiltinType.hpp"

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
            registers.at(reg) = true;
            return reg;
        }
    }
    std::cerr << "All temporary registers in use\n";
    std::exit(3);
}

std::string RegisterPool::getArgRegister() {
    for (const auto &[reg, inUse]: argumentRegisters) {
        if (!inUse) {
            argumentRegisters.at(reg) = true;
            return reg;
        }
    }
    std::cerr << "All argument registers in use\n";
    std::exit(15);
}

void RegisterPool::freeRegister(const std::string &reg) {
    registers.at(reg) = false;
}

void RegisterPool::clearArgRegisters() {
    for (auto &it: argumentRegisters) {
        it.second = false;
    }
}

void RegisterPool::saveRegisters(SymbolTable &table) const {
    const std::shared_ptr<Type> word(new BuiltinType(Expression::integral));

    for (const auto &[reg, inUse]: registers) {
        if (inUse) {
            std::stringstream ss;
            ss << " " << reg; //Identifiers can't have whitespace, so this is safe

            if (!table.isLocalVariable(ss.str())) {
                table.addVariable(ss.str(), word);
            }

            std::cout << "sw " << reg << ", " << table.lookupVariable(ss.str()).getLocation()
                      << " #Save state of register\n";
        }
    }
}

void RegisterPool::loadRegisters(SymbolTable &table) const {
    for (const auto &[reg, inUse]: registers) {
        if (inUse) {
            std::stringstream ss;
            ss << " " << reg;

            if (!table.isVariable(ss.str())) {
                std::cout << "Expected to find saved register " << reg << std::endl;
                std::exit(16);
            }

            std::cout << "lw " << reg << ", " << table.lookupVariable(ss.str()).getLocation()
                      << " #Load state of register\n";
        }
    }
}

/*
 * Problem: return statements don't know how big the stack frame is.
 * solution: since we're writing to a string anyways, add a placeholder to fill in with the stack size
 */