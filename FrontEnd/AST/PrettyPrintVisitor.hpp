#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "FrontEnd/AST/Visitor.hpp"

struct PrettyPrintVisitor : Visitor {
    template<typename T>
    void printNodeList(std::vector<std::unique_ptr<T>> &list) {
        if (!list.empty()) {
            for (auto e = list.begin(); e != list.end() - 1; e++) {
                (*e)->accept(*this);
                std::cout << ", ";
            }
            list.back()->accept(*this);
        }
    }

    void visit(LiteralExpression *) override;

    void visit(StringExpression *) override;

    void visit(SuccExpression *) override;

    void visit(PredExpression *) override;

    void visit(OrdExpression *) override;

    void visit(ChrExpression *) override;

    void visit(RecordAccessExpression *) override;

    void visit(IdentifierExpression *) override;

    void visit(ArrayAccessExpression *) override;

    void visit(FunctionCallExpression *) override;

    void visit(BinaryOpExpression *) override;

    void visit(UnaryOpExpression *) override;

    void visit(ParenthesisExpression *) override;

    void visit(ProcedureCallStatement *) override;

    void visit(WriteStatement *) override;

    void visit(ReadStatement *) override;

    void visit(ReturnStatement *) override;

    void visit(StopStatement *) override;
};
