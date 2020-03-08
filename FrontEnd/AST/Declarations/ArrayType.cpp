#include "ArrayType.hpp"
#include "FrontEnd/AST/Expressions/LiteralExpression.hpp"

ArrayType::ArrayType(Expression *l, Expression *r, Type *t) : left(l), right(r), type(t) {

}

void ArrayType::print() const {
    std::cout << "ARRAY [";
    left->print();
    std::cout << " : ";
    right->print();
    std::cout << "] OF ";
    type->print();
}

void ArrayType::fold_constants() {
    const auto l = left->try_fold(), r = right->try_fold();

    if (l)
        left = std::shared_ptr<Expression>(new LiteralExpression(*l));
    if (r)
        right = std::shared_ptr<Expression>(new LiteralExpression(*r));
}
