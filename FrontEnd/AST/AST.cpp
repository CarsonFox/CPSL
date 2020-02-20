#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(VariableDeclaration *x) {
    type = std::unique_ptr<VariableDeclaration>(x);
}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    type->accept(pp);
}
