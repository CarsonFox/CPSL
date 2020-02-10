#pragma once

struct LiteralExpression;
struct SuccExpression;
struct PredExpression;
struct OrdExpression;

struct Visitor {
    virtual void visit(LiteralExpression *) = 0;

    virtual void visit(SuccExpression *) = 0;

    virtual void visit(PredExpression *) = 0;

    virtual void visit(OrdExpression *) = 0;
};