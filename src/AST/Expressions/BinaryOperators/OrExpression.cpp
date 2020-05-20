#include <src/AST/Expressions/LiteralExpression.hpp>
#include "OrExpression.hpp"

OrExpression::OrExpression(Expression *l, Expression *r) : BinaryOpExpression(l, r) {

}

void OrExpression::print() const {
    left->print();
    std::cout << " | ";
    right->print();
}

std::optional<int> OrExpression::try_fold() {
    const auto l = left->try_fold(), r = right->try_fold();

    if (l && r)
        return *l || *r;

    if (l)
        left = std::shared_ptr<Expression>(new LiteralExpression(*l));
    if (r)
        right = std::shared_ptr<Expression>(new LiteralExpression(*r));

    return {};
}
