#pragma once

#include <memory>

#include "LValue.hpp"

struct RecordAccessExpression : LValue {
    std::unique_ptr<LValue> left;
    std::string right;

    explicit RecordAccessExpression(LValue *, char *);

    ~RecordAccessExpression() override = default;

    void print() const override;

    bool isConst() const override;
};