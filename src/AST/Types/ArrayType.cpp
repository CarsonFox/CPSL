#include "ArrayType.hpp"

#include "src/AST/Expressions/Expression.hpp"

ArrayType::ArrayType(Expression *l, Expression *r, Type *t) : type(t) {
    const auto leftFold = l->try_fold(), rightFold = r->try_fold();

    if (leftFold && rightFold) {
        left = *leftFold;
        right = *rightFold;
    } else {
        std::cerr << "Arrays bounds must be constant expressions\n";
        std::exit(7);
    }
}

void ArrayType::print() const {
    std::cout << "ARRAY [" << left << " : " << right << "] OF ";
    type->print();
}

void ArrayType::fold_constants() {
//    const auto leftFold = left->try_fold(), rightFold = right->try_fold();
//
//    if (leftFold && rightFold) {
//        left = std::shared_ptr<Expression>(new LiteralExpression(*leftFold));
//        right = std::shared_ptr<Expression>(new LiteralExpression(*rightFold));
//    } else {
//        std::cerr << "Arrays bounds must be constant expressions\n";
//        std::exit(7);
//    }
}

int ArrayType::getSize(SymbolTable &table) {
    return (right - left + 1) * type->getSize(table);
}
