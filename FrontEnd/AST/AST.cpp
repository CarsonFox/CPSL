#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(VarDeclaration *x) {
    type = std::unique_ptr<VarDeclaration>(x);
}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    type->accept(pp);
}
