#include <memory>

#include "Statement.hpp"
#include "FrontEnd/AST/Expressions/Expression.hpp"

struct ReturnStatement : Statement {
    std::unique_ptr<Expression> expr;

    explicit ReturnStatement(Expression *);

    ~ReturnStatement() override = default;

    void print() const override;
};