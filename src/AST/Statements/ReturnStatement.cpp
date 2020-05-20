#include <src/AST/Expressions/LiteralExpression.hpp>
#include "ReturnStatement.hpp"

ReturnStatement::ReturnStatement(Expression *e) : expr(e) {
}

void ReturnStatement::print() const {
    std::cout << "RETURN ";
    expr->print();
    std::cout << ';';
}

void ReturnStatement::fold_constants() {
    const auto folded = expr->try_fold();
    if (folded)
        expr = std::shared_ptr<Expression>(new LiteralExpression(*folded));
}
