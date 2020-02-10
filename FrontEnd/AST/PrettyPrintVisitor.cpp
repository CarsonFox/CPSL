#include "PrettyPrintVisitor.hpp"

void PrettyPrintVisitor::visit(LiteralExpression *literal) {
    std::cout << literal->value;
}

void PrettyPrintVisitor::visit(SuccExpression *succExpression) {
    std::cout << "succ(";
    succExpression->expr->accept(*this);
    std::cout << ")";
}

void PrettyPrintVisitor::visit(PredExpression *predExpression) {
    std::cout << "pred(";
    predExpression->expr->accept(*this);
    std::cout << ")";
}

void PrettyPrintVisitor::visit(OrdExpression *ordExpression) {
    std::cout << "ord(";
    ordExpression->expr->accept(*this);
    std::cout << ")";
}

void PrettyPrintVisitor::visit(ChrExpression *chrExpression) {
    std::cout << "chr(";
    chrExpression->expr->accept(*this);
    std::cout << ")";
}

void PrettyPrintVisitor::visit(RecordAccessExpression *recordAccess) {
    recordAccess->left->accept(*this);
    std::cout << '.' << recordAccess->right;
}

void PrettyPrintVisitor::visit(IdentifierExpression *identifierExpression) {
    std::cout << identifierExpression->id;
}

void PrettyPrintVisitor::visit(ArrayAccessExpression *arrayAccess) {
    arrayAccess->left->accept(*this);
    std::cout << '[';
    arrayAccess->right->accept(*this);
    std::cout << ']';
}
