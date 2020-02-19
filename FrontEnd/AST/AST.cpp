#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(Type *t) {
    type = std::unique_ptr<Type>(t);
}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    type->accept(pp);
}
