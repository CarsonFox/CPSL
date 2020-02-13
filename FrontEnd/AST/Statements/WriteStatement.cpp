#include "WriteStatement.hpp"

#include <iostream>

WriteStatement::WriteStatement(ExpressionList *list) {
    args = list->toVector();

    if (args.empty()) {
        std::cerr << "Syntax error: Write requires arguments\n";
        std::exit(EXIT_FAILURE);
    }

    delete list;
}

void WriteStatement::accept(Visitor &visitor) {
    visitor.visit(this);
}
