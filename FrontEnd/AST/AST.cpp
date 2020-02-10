#include "AST.hpp"

std::unique_ptr<AST> AST::main;

AST::AST(ExpressionList *e) {
    exprs = e->toVector();
    delete e;
}

void AST::prettyPrint() {
    PrettyPrintVisitor pp;
    for (auto &e : exprs) {
        e->accept(pp);
        std::cout << std::endl;
    }
}
