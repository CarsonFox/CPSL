#pragma once

#include "Expression.hpp"

struct LValue : Expression {
    virtual std::string getLocation(SymbolTable &) {
        std::cerr << "getLocation unimplemented for " << typeid(*this).name() << std::endl;
        std::exit(1);
    }
};