#include "AssignStatement.hpp"

AssignStatement::AssignStatement(LValue *l, Expression *e) : lvalue(l), expr(e) {}

void AssignStatement::print() const {
    lvalue->print();
    std::cout << " := ";
    expr->print();
    std::cout << ';';
}