#include "AssignStatement.hpp"

AssignStatement::AssignStatement(LValue *l, Expression *e) : lvalue(l), expr(e) {}

void AssignStatement::accept(Visitor &visitor) {
    visitor.visit(this);
}
