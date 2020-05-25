#pragma once

#include <memory>
#include <functional>

#include "src/AST/Expressions/Expression.hpp"

struct UnaryOpExpression : Expression {
    std::shared_ptr<Expression> expr;

    bool isConst() const override;

protected:
    UnaryOpExpression(Expression *);

public:
    type getType(SymbolTable &table) override;
};