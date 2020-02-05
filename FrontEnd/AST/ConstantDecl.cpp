#include "ConstantDecl.hpp"

ConstantDecl::ConstantDecl(char *id, long val) : id(id), val(val) {
    free(id);
}

ConstantDecl::ConstantDecl(ASTNode *other) {
    //Take some stuff.
    //Don't delete the pointer here, parent does that.
    auto c = (ConstantDecl *) other;
    this->id = std::move(c->id);
    this->val = c->val;
}

void ConstantDecl::echo() {
    std::cout << "const " << this->id << " = " << this->val << std::endl;
}