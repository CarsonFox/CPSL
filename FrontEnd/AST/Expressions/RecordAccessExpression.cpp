#include "RecordAccessExpression.hpp"

RecordAccessExpression::RecordAccessExpression(LValue *l, char *r) : left(l), right(r) {
    free(r);
}

void RecordAccessExpression::print() const {
    left->print();
    std::cout << '.' << right;
}

bool RecordAccessExpression::isConst() const {
    return false;
}
