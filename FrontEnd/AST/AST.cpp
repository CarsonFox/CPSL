#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(ConstDeclaration *t) {
    type = std::unique_ptr<ConstDeclaration>(t);
}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    type->accept(pp);
}
