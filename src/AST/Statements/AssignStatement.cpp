#include <src/AST/Expressions/LiteralExpression.hpp>
#include "AssignStatement.hpp"

AssignStatement::AssignStatement(LValue *l, Expression *e) : lvalue(l), expr(e) {}

void AssignStatement::print() const {
    lvalue->print();
    std::cout << " := ";
    expr->print();
    std::cout << ';';
}

void AssignStatement::fold_constants() {
    const auto folded = expr->try_fold();
    if (folded)
        expr = std::shared_ptr<Expression>(new LiteralExpression(*folded));
}
