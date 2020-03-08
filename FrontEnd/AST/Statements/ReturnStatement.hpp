#include <memory>

#include "Statement.hpp"
#include "FrontEnd/AST/Expressions/Expression.hpp"

struct ReturnStatement : Statement {
    std::shared_ptr<Expression> expr;

    explicit ReturnStatement(Expression *);

    ~ReturnStatement() override = default;

    void print() const override;

    void fold_constants() override;
};