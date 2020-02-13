#pragma once

/*
 * These forward declarations avoid stupid
 * include cycle shenanigans.
 */
struct LiteralExpression;
struct SuccExpression;
struct PredExpression;
struct OrdExpression;
struct ChrExpression;
struct RecordAccessExpression;
struct IdentifierExpression;
struct ArrayAccessExpression;
struct FunctionCallExpression;
struct BinaryOpExpression;
struct UnaryOpExpression;
struct ParenthesisExpression;
struct ProcedureCallStatement;

struct Visitor {
    virtual void visit(LiteralExpression *) = 0;

    virtual void visit(SuccExpression *) = 0;

    virtual void visit(PredExpression *) = 0;

    virtual void visit(OrdExpression *) = 0;

    virtual void visit(ChrExpression *) = 0;

    virtual void visit(RecordAccessExpression *) = 0;

    virtual void visit(IdentifierExpression *) = 0;

    virtual void visit(ArrayAccessExpression *) = 0;

    virtual void visit(FunctionCallExpression *) = 0;

    virtual void visit(BinaryOpExpression *) = 0;

    virtual void visit(UnaryOpExpression *) = 0;

    virtual void visit(ParenthesisExpression *) = 0;

    virtual void visit(ProcedureCallStatement *) = 0;
};