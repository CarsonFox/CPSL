#pragma once

#include "PrettyPrintVisitor.hpp"

void PrettyPrintVisitor::visit(LiteralExpression *literal) {
    std::cout << literal->value << std::endl;
}
