#pragma once

#include <iostream>

#include "AllNodes.hpp"

struct PrettyPrintVisitor : Visitor {
    void visit(LiteralExpression *) override;
};
