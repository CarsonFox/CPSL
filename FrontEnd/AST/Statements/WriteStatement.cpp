#include "WriteStatement.hpp"

#include "FrontEnd/AST/Util.hpp"

WriteStatement::WriteStatement(ExpressionList *list) {
    args = list->toVector();

    if (args.empty()) {
        std::cerr << "Syntax error: Write requires arguments\n";
        std::exit(EXIT_FAILURE);
    }

    delete list;
}

void WriteStatement::print() const {
    std::cout << "WRITE(";
    printExprList(args);
    std::cout << ");";
}
