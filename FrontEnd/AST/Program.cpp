#include <algorithm>

#include "Program.hpp"

Program::Program(std::vector<ASTNode *> *decls) {
    if (decls) {
        //ASTNode* ==> ConstantDecl conversion.
        //This will reverse the order, which was already reversed in the parser.
        std::transform(decls->begin(), decls->end(), std::back_inserter(this->constantDecls),
                       [](ASTNode *node) { return ConstantDecl(node); });

        //Clean up
        for (ASTNode *p : *decls) {
            delete ((ConstantDecl *) p);
        }
        delete decls;
    } else {
        std::cerr << "Program constructed with null list of const decls."
                  << "Should be a pointer to an empty vector if there aren't any.\n";
        exit(EXIT_FAILURE);
    }
}

void Program::echo() {
    std::cout << "Program\n";

    for (auto &c : this->constantDecls) {
        c.echo();
    }
}
