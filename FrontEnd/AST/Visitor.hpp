#pragma once

struct LiteralExpression;
struct SuccExpression;

struct Visitor {
    virtual void visit(LiteralExpression *) = 0;

    virtual void visit(SuccExpression *) = 0;
};