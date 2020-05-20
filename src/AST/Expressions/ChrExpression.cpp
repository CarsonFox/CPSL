#include "ChrExpression.hpp"

ChrExpression::ChrExpression(Expression *e) : expr(e) {

}

void ChrExpression::print() const {
    std::cout << "CHR(";
    expr->print();
    std::cout << ')';
}

bool ChrExpression::isConst() const {
    return expr->isConst();
}