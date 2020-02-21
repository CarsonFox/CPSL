#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(Function *x) {
    type = std::unique_ptr<Function>(x);
}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    type->accept(pp);
}
