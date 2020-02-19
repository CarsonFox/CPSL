#include "ArrayType.hpp"

ArrayType::ArrayType(Expression *l, Expression *r, Type *t) : left(l), right(r), type(t) {

}

void ArrayType::accept(Visitor &visitor) {
    visitor.visit(this);
}
