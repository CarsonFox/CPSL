#include <algorithm>

#include "Program.hpp"

Program::Program(std::vector<ASTNode *> *decls) {
    this->constantDecls = castNodeList<ConstantDecl>(decls);
}

void Program::echo() {
    std::cout << "Program\n";

    for (auto &c : this->constantDecls) {
        c.echo();
    }
}
