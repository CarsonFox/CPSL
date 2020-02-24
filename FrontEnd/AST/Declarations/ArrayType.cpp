#include "ArrayType.hpp"

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