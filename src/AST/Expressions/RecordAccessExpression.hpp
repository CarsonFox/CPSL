#pragma once

#include <memory>

#include "LValue.hpp"

struct RecordAccessExpression : LValue {
    std::shared_ptr<LValue> left;
    std::string right;

    explicit RecordAccessExpression(LValue *, char *);

    ~RecordAccessExpression() override = default;

    void print() const override;

    bool isConst() const override;

    std::string emitLocationToRegister(SymbolTable &table, RegisterPool &pool) override;
};