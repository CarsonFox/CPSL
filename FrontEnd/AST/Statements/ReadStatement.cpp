#include "ReadStatement.hpp"

#include "FrontEnd/AST/Util.hpp"

ReadStatement::ReadStatement(LValueList *list) {
    lvals = list->toVector();
    delete list;

    if (lvals.empty()) {
        std::cerr << "Syntax error: Read requires arguments\n";
        std::exit(EXIT_FAILURE);
    }
}

void ReadStatement::print() const {
    std::cout << "READ(";
    printExprList(lvals);
    std::cout << ");";
}