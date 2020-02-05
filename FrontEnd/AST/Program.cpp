#include <algorithm>

#include "Program.hpp"

Program::Program(std::vector<ASTNode *> *decls) {
    this->constantDecls = castNodeList<ConstantDecl>(decls);
}

void Program::prettyPrint() const {
    std::cout << "BEGIN\n";

    for (const auto &c : this->constantDecls) {
        c.prettyPrint();
    }

    std::cout << "END.\n";
}
