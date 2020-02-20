#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(TypeDeclaration *t) {
    type = std::unique_ptr<TypeDeclaration>(t);
}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    type->accept(pp);
}
