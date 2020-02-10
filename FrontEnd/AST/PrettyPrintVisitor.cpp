#include "PrettyPrintVisitor.hpp"

void PrettyPrintVisitor::visit(LiteralExpression *literal) {
    std::cout << literal->value;
}

void PrettyPrintVisitor::visit(SuccExpression *succExpression) {
    std::cout << "succ(";
    succExpression->expr->accept(*this);
    std::cout << ")";
}