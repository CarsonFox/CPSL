#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(Block *x) {
    type = std::unique_ptr<Block>(x);
}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    type->accept(pp);
}
