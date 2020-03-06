#pragma once

#include <memory>
#include <functional>

#include "FrontEnd/AST/Expressions/Expression.hpp"

struct UnaryOpExpression : Expression {
    std::shared_ptr<Expression> expr;

    bool isConst() const override;

protected:
    UnaryOpExpression(Expression *);
};