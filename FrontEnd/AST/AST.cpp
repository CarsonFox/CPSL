#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(Procedure *x) {
    type = std::unique_ptr<Procedure>(x);
}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    type->accept(pp);
}
