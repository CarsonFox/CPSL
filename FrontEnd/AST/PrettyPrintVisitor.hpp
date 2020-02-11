#pragma once

#include <iostream>

#include "AllNodes.hpp"
#include "Visitor.hpp"

struct PrettyPrintVisitor : Visitor {
    void visit(LiteralExpression *) override;

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
};
