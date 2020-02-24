#include "ReturnStatement.hpp"

ReturnStatement::ReturnStatement(Expression *e) : expr(e) {
}

void ReturnStatement::print() const {
    std::cout << "RETURN ";
    expr->print();
    std::cout << ';';
}