#pragma once

#include <string>

#include "LValue.hpp"

struct IdentifierExpression : LValue {
    std::string id;

    explicit IdentifierExpression(char *);

    explicit IdentifierExpression(std::string);

    ~IdentifierExpression() override = default;

    void print() const override;

    bool isConst() const override;

    std::string getLocation(SymbolTable &table) override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;

    std::string emitLocationToRegister(SymbolTable &table, RegisterPool &pool) override;

    std::shared_ptr<Type> getConcreteType(SymbolTable &table) override;

    type getType(SymbolTable &table) override;
};
