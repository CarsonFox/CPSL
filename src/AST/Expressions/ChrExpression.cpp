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

std::string ChrExpression::emitToRegister(SymbolTable &table, RegisterPool &pool) {
    return expr->emitToRegister(table, pool);
}

Expression::type ChrExpression::getType(SymbolTable &) {
    return character;
}
