#pragma once

#include <string>
#include <memory>

//I'm looking forward to modules so much
struct Type;

class SymbolTable {
public:
    SymbolTable() = default;

    void addVariable(std::string, std::shared_ptr<Type>);
};