#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

#include "Variable.hpp"

//I'm looking forward to modules so much
struct Type;
struct Expression;

class SymbolTable {
    struct Scope {
        std::unordered_map<std::string, Variable> variables;
        std::unordered_map<std::string, SymbolTableType> types;
        std::unordered_map<std::string, std::shared_ptr<Expression>> constants;

        int varSize = 0;

        Scope() = default;

        void addVariable(const std::string &, std::shared_ptr<Type>, std::string);

        void addConstant(const std::string &, std::shared_ptr<Expression>);
    };

    std::vector<Scope> scopes;

public:
    SymbolTable();

    void addVariable(const std::string &, std::shared_ptr<Type>);

    void addConstant(const std::string &, std::shared_ptr<Expression>);

    void addType(const std::string &, std::shared_ptr<Type>);

    const Variable &lookupVariable(const std::string &);

    std::shared_ptr<Expression> lookupConstant(const std::string &);

    bool isVariable(const std::string &) const;

    bool isConstant(const std::string &) const;
};