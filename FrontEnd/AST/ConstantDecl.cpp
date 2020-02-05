#include "ConstantDecl.hpp"

ConstantDecl::ConstantDecl(char *id, int val) : id(id), val(val) {
    free(id);
}

ConstantDecl::ConstantDecl(ASTNode *other) {
    //Take some stuff.
    //Don't delete the pointer here, parent does that.
    auto c = (ConstantDecl *) other;
    this->id = std::move(c->id);
    this->val = c->val;
}

void ConstantDecl::prettyPrint() const {
    std::cout << "\t" << this->id << " = " << this->val << ";\n";
}
