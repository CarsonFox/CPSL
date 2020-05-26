#pragma once

#include <memory>

#include "LValue.hpp"

struct ArrayAccessExpression : LValue {
    std::shared_ptr<LValue> left;
    std::shared_ptr<Expression> right;

    ArrayAccessExpression(LValue *, Expression *);

    ~ArrayAccessExpression() override = default;

    void print() const override;

    bool isConst() const override;

    std::optional<int> try_fold() override;

    std::string emitLocationToRegister(SymbolTable &table, RegisterPool &pool) override;

    std::string emitToRegister(SymbolTable &table, RegisterPool &pool) override;

    std::shared_ptr<Type> getConcreteType(SymbolTable &table) override;
};