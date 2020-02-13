#include <iostream>

#include "ReadStatement.hpp"

ReadStatement::ReadStatement(LValueList *list) {
    lvals = list->toVector();
    delete list;

    if (lvals.empty()) {
        std::cerr << "Syntax error: Read requires arguments\n";
        std::exit(EXIT_FAILURE);
    }
}

void ReadStatement::accept(Visitor &visitor) {
    visitor.visit(this);
}
