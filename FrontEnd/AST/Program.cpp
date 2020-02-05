#include <algorithm>

#include "Program.hpp"

Program::Program(std::vector<ASTNode *> *decls) {
    //ASTNode* ==> ConstantDecl conversion.
    //This will reverse the order, which was already reversed in the parser.
    std::transform(decls->begin(), decls->end(), std::back_inserter(this->constantDecls),
                   [](ASTNode *node) { return ConstantDecl(node); });

    //Clean up
    for (auto p : *decls) {
        delete p;
    }
    delete decls;
}

void Program::echo() {
    std::cout << "Program\n";

    for (auto &c : this->constantDecls) {
        c.echo();
    }
}
