#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

#include "Variable.hpp"

//I'm looking forward to modules so much
struct Type;

class SymbolTable {
    struct Scope {
        std::unordered_map<std::string, Variable> variables;

        Scope() = default;

        void addVariable(std::string, std::shared_ptr<Type>, std::string);
    };

    std::vector<Scope> scopes;

public:
    SymbolTable();

    void addVariable(std::string, std::shared_ptr<Type>);
};