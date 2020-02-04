#pragma once

#include <iostream>

#include "AST.hpp"

class Program : public ASTNode {
public:
    Program();
    void hello();
};
