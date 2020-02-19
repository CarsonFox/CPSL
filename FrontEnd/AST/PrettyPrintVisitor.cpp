#include "PrettyPrintVisitor.hpp"

#include "FrontEnd/AST/AllNodes.hpp"

int indentLevel = 0;

void PrettyPrintVisitor::printStatementList(std::vector<std::unique_ptr<Statement>> &stmts) {
    indentLevel++;
    for (auto &s : stmts) {
        if (!dynamic_cast<EmptyStatement *>(s.get())) {
            for (int i = 0; i < indentLevel; i++) std::cout << '\t';
            s->accept(*this);
        }
    }
    indentLevel--;
}

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

void PrettyPrintVisitor::visit(StringExpression *stringExpression) {
    std::cout << '"' << stringExpression->value << '"';
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
    printNodeList(functionCall->args);
    std::cout << ')';
}

void PrettyPrintVisitor::visit(BinaryOpExpression *binaryOpExpression) {
    binaryOpExpression->left->accept(*this);
    switch (binaryOpExpression->type) {
        case BinaryOp::Or:
            std::cout << " | ";
            break;
        case BinaryOp::And:
            std::cout << " & ";
            break;
        case BinaryOp::Equal:
            std::cout << " = ";
            break;
        case BinaryOp::NotEqual:
            std::cout << " <> ";
            break;
        case BinaryOp::Less:
            std::cout << " < ";
            break;
        case BinaryOp::LessEqual:
            std::cout << " <= ";
            break;
        case BinaryOp::Greater:
            std::cout << " > ";
            break;
        case BinaryOp::GreaterEqual:
            std::cout << " >= ";
            break;
        case BinaryOp::Add:
            std::cout << " + ";
            break;
        case BinaryOp::Sub:
            std::cout << " - ";
            break;
        case BinaryOp::Mul:
            std::cout << " * ";
            break;
        case BinaryOp::Div:
            std::cout << " / ";
            break;
        case BinaryOp::Mod:
            std::cout << " % ";
            break;
        default:
            std::cout << " ? ";
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

void PrettyPrintVisitor::visit(ParenthesisExpression *parenthesisExpression) {
    std::cout << '(';
    parenthesisExpression->expr->accept(*this);
    std::cout << ')';
}

void PrettyPrintVisitor::visit(ProcedureCallStatement *procedureCall) {
    std::cout << procedureCall->id << '(';
    printNodeList(procedureCall->args);
    std::cout << ");\n";
}

void PrettyPrintVisitor::visit(WriteStatement *writeStatement) {
    std::cout << "write(";
    printNodeList(writeStatement->args);
    std::cout << ");\n";
}

void PrettyPrintVisitor::visit(ReadStatement *readStatement) {
    std::cout << "read(";
    printNodeList(readStatement->lvals);
    std::cout << ");\n";
}

void PrettyPrintVisitor::visit(ReturnStatement *returnStatement) {
    std::cout << "return ";
    if (returnStatement->expr) {
        returnStatement->expr->accept(*this);
    }
    std::cout << ";\n";
}

void PrettyPrintVisitor::visit(StopStatement *) {
    std::cout << "stop;\n";
}

void PrettyPrintVisitor::visit(ForStatement *forStatement) {
    std::cout << "for " << forStatement->id << " := ";
    forStatement->init->accept(*this);
    std::cout << (forStatement->type == ForType::UP_TO ? " to " : " downto ");
    forStatement->bound->accept(*this);
    std::cout << " do\n";

    printStatementList(forStatement->statements);

    for (int i = 0; i < indentLevel; i++) std::cout << '\t';
    std::cout << "end\n";
}

void PrettyPrintVisitor::visit(RepeatStatement *repeatStatement) {
    std::cout << "repeat\n";
    printStatementList(repeatStatement->stmts);
    for (int i = 0; i < indentLevel; i++) std::cout << '\t';
    std::cout << "until ";
    repeatStatement->pred->accept(*this);
    std::cout << std::endl;
}

void PrettyPrintVisitor::visit(WhileStatement *whileStatement) {
    std::cout << "while ";
    whileStatement->pred->accept(*this);
    std::cout << " do\n";
    printStatementList(whileStatement->stmts);
    for (int i = 0; i < indentLevel; i++) std::cout << '\t';
    std::cout << "end\n";
}

void PrettyPrintVisitor::visit(IfStatement *ifStatement) {
    std::cout << "if ";
    ifStatement->pred->accept(*this);
    std::cout << " then\n";
    printStatementList(ifStatement->stmts);

    for (auto &e: ifStatement->elseIfs) {
        for (int i = 0; i < indentLevel; i++) std::cout << '\t';
        std::cout << "elseif ";
        std::get<0>(e)->accept(*this);
        std::cout << " then\n";
        printStatementList(std::get<1>(e));
    }

    if (!ifStatement->elseStmts.empty()) {
        for (int i = 0; i < indentLevel; i++) std::cout << '\t';
        std::cout << "else\n";
        printStatementList(ifStatement->elseStmts);
    }

    for (int i = 0; i < indentLevel; i++) std::cout << '\t';
    std::cout << "end\n";
}

void PrettyPrintVisitor::visit(AssignStatement *assignStatement) {
    assignStatement->lvalue->accept(*this);
    std::cout << " := ";
    assignStatement->expr->accept(*this);
    std::cout << ";\n";
}


