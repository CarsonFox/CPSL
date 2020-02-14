#include "ForStatement.hpp"

ForStatement::ForStatement(char *s, Expression *i, Expression *b, StatementList *stmts, ForType t)
        : id(s), init(i), bound(b), type(t) {
    free(s);
    statements = stmts->toVector();
    delete stmts;
}

void ForStatement::accept(Visitor &visitor) {
    visitor.visit(this);
}
