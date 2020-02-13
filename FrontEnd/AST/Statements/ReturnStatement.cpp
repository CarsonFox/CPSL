#include "ReturnStatement.hpp"

ReturnStatement::ReturnStatement(Expression *e) : expr(e) {
}

void ReturnStatement::accept(Visitor &visitor) {
    visitor.visit(this);
}
