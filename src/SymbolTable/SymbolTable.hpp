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
        std::unordered_map<std::string, std::shared_ptr<Type>> types;
        std::unordered_map<std::string, std::shared_ptr<Expression>> constants;

        int varSize = 0;
        std::string base;

        Scope();

        explicit Scope(std::string);

        void addVariable(const std::string &, std::shared_ptr<Type>, int);

        void addType(const std::string &, std::shared_ptr<Type>);

        void addConstant(const std::string &, std::shared_ptr<Expression>);
    };

    std::vector<Scope> scopes;
    std::unordered_map<std::string, std::shared_ptr<Type>> functions;//Functions cannot be nested.

public:
    SymbolTable();

    void addVariable(const std::string &, std::shared_ptr<Type>);

    void addType(const std::string &, std::shared_ptr<Type>);

    void addConstant(const std::string &, std::shared_ptr<Expression>);

    void addFunction(const std::string &, std::shared_ptr<Type>);

    const Variable &lookupVariable(const std::string &);

    std::shared_ptr<Type> lookupType(const std::string &);

    std::shared_ptr<Expression> lookupConstant(const std::string &);

    std::shared_ptr<Type> lookupFunction(const std::string &);

    bool isVariable(const std::string &) const;

    bool isLocalVariable(const std::string &) const;

    bool isConstant(const std::string &) const;

    void pushScope();

    void popScope();

    void pushForScope();

    void popForScope();

    int stackFrameSize() const;
};