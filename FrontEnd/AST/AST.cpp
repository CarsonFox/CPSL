#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(Expression *e) : expr(e) {}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    expr->accept(pp);
}
