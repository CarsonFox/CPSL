#include "ProcedureCallStatement.hpp"

#include "FrontEnd/AST/Util.hpp"

ProcedureCallStatement::ProcedureCallStatement(char *s, ExpressionList *list) : id(s) {
    args = list->toVector();

    free(s); //Alloc'd with strdup
    delete list; //Alloc'd with new
}

void ProcedureCallStatement::print() const {
    std::cout << id << '(';
    printExprList(args);
    std::cout << ");";
}