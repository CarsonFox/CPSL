#pragma once

#include <iostream>

#include "Visitor.hpp"
#include "AllNodes.hpp"

struct PrettyPrintVisitor : Visitor {
    void visit(LiteralExpression *) override;

    void visit(SuccExpression *) override;
};
