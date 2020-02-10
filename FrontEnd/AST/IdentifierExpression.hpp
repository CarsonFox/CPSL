#pragma once

#include <string>

#include "LValue.hpp"

struct IdentifierExpression : LValue {
    std::string id;

    explicit IdentifierExpression(char *);

    ~IdentifierExpression() override = default;

    void accept(Visitor &) override;
};
