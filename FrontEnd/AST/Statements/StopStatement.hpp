#pragma once

#include "Statement.hpp"

struct StopStatement : Statement {
    StopStatement() = default;

    ~StopStatement() override = default;

    void accept(Visitor &visitor) override { visitor.visit(this); }
};