#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(Statement *s) {
    stmt = std::unique_ptr<Statement>(s);
}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    stmt->accept(pp);
}
