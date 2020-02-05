#include <algorithm>

#include "Program.hpp"

Program::Program(std::vector<ASTNode *> *decls) {
    this->constantDecls = castNodeList<ConstantDecl>(decls);
}

void Program::prettyPrint() const {
    if (!this->constantDecls.empty()) {
        std::cout << "CONST\n";
        for (const auto &c : this->constantDecls) {
            c.prettyPrint();
        }
        std::cout << std::endl;
    }

    std::cout << "BEGIN\n";
    //Body
    std::cout << "END.\n";
}
