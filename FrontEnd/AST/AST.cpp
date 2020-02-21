#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(FormalParameters *x) {
    type = std::unique_ptr<FormalParameters>(x);
}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    type->accept(pp);
}
