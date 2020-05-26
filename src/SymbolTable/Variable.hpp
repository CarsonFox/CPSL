#pragma once

#include <string>

#include "SymbolTableType.hpp"

class Variable {
    std::string id;
    std::shared_ptr<Type> type;
    std::string base; //Either $sp or $gp, depending on the scope of the variable
    int offset = 0;

public:
    Variable() = default;

    Variable(std::string, std::shared_ptr<Type>, std::string, int);

    std::string getLocation() const;

    std::string getBase() const;

    int getOffset() const;
};