#include <iostream>

#include "FrontEnd/AST/AST.hpp"
#include "FrontEnd/AST/Program.hpp"

extern int yyparse();

int main() {
    auto x = yyparse();
    static_cast<Program *>(ASTNode::main)->hello();
    return x;
}