#pragma once

#include "Statement.hpp"

struct EmptyStatement : Statement {
    EmptyStatement() = default;

    ~EmptyStatement() override = default;

    void accept(Visitor &) override {}
};