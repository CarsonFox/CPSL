#pragma once

#include <memory>
#include <vector>

#include "Statement.hpp"
#include "FrontEnd/AST/Expressions/LValueList.hpp"

struct ReadStatement : Statement {
    std::vector<std::shared_ptr<LValue>> lvals;

    explicit ReadStatement(LValueList *);

    ~ReadStatement() override = default;

    void print() const override;
};