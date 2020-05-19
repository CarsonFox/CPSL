#pragma once

#include <memory>

#include "AST/Declarations/Type.hpp"

struct Variable {
    //Like c/c++, size in words (32-bit chunks)
    virtual int size() = 0;

    //String representation of the base location of the variable
    virtual std::string location() = 0;
};