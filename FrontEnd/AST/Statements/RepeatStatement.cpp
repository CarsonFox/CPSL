#include "RepeatStatement.hpp"

RepeatStatement::RepeatStatement(StatementList *l, Expression *e) : pred(e) {
    stmts = l->toVector();
    delete l;
}

void RepeatStatement::accept(Visitor &visitor) {
    visitor.visit(this);
}
