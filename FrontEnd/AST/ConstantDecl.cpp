#include "ConstantDecl.hpp"

void ConstantDecl::echo() {
    std::cout << "Constant Declaration\n";
}

ConstantDecl::ConstantDecl(ASTNode *) {
    //Take some stuff.
    //Don't delete the pointer here, parent does that.
}
