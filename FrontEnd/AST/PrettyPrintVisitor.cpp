#include "PrettyPrintVisitor.hpp"

void PrettyPrintVisitor::visit(LiteralExpression *literal) {
    if (std::holds_alternative<int>(literal->value)) {
        std::cout << std::get<int>(literal->value);
    } else {
        std::cout << '\'';
        char c = std::get<char>(literal->value);
        switch (c) {
            case '\n':
                std::cout << "\\n";
                break;
            case '\r':
                std::cout << "\\r";
                break;
            case '\b':
                std::cout << "\\b";
                break;
            case '\t':
                std::cout << "\\t";
                break;
            case '\f':
                std::cout << "\\f";
                break;
            default:
                std::cout << c;
                break;
        }
        std::cout << '\'';
    }
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

void PrettyPrintVisitor::visit(FunctionCallExpression *functionCall) {
    std::cout << functionCall->id << '(';
    for (auto &e : functionCall->args) {
        e->accept(*this);
    }
    std::cout << ')';
}

void PrettyPrintVisitor::visit(BinaryOpExpression *binaryOpExpression) {
    binaryOpExpression->left->accept(*this);
    switch (binaryOpExpression->type) {
        case BinaryOp::Sub:
            std::cout << " - ";
    }
    binaryOpExpression->right->accept(*this);
}

void PrettyPrintVisitor::visit(UnaryOpExpression *unaryOpExpression) {
    if (unaryOpExpression->type == UnaryOp::Neg) {
        std::cout << '-';
    } else {
        std::cout << '~';
    }
    unaryOpExpression->expr->accept(*this);
}
