#pragma once

#include <string>

#include "SymbolTableType.hpp"

class Variable {
    std::string id;
    SymbolTableType type;
    std::string base; //Either $sp or $gp, depending on the scope of the variable
    int offset;

public:
    Variable() = default;

    std::string getLocation() const;
};