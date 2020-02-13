#include "ProcedureCallStatement.hpp"

ProcedureCallStatement::ProcedureCallStatement(char *s, ExpressionList *list) : id(s) {
    args = list->toVector();

    free(s); //Alloc'd with strdup
    delete list; //Alloc'd with new
}

void ProcedureCallStatement::accept(Visitor &visitor) {
    visitor.visit(this);
}
