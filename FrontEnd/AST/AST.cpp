#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(Body *x) {
    type = std::unique_ptr<Body>(x);
}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    type->accept(pp);
}
