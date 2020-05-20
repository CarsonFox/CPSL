#pragma once

#include <string>

#include "SymbolTableType.hpp"

class Variable {
    std::string id;
    SymbolTableType type;
    std::string base;

public:
    Variable() = default;
};