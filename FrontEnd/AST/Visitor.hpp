#pragma once

struct LiteralExpression;
//struct IdentifierExpression;

struct Visitor {
    virtual void visit(LiteralExpression *) = 0;

//    virtual void visit(IdentifierExpression *) = 0;
};