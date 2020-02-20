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
struct WriteStatement;
struct ReadStatement;
struct ReturnStatement;
struct StringExpression;
struct StopStatement;
struct ForStatement;
struct RepeatStatement;
struct WhileStatement;
struct IfStatement;
struct AssignStatement;
struct SimpleType;
struct ArrayType;
struct RecordType;
struct TypeDeclaration;
struct ConstDeclaration;
struct VarDeclaration;

struct Visitor {
    virtual void visit(LiteralExpression *) = 0;

    virtual void visit(StringExpression *) = 0;

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

    virtual void visit(WriteStatement *) = 0;

    virtual void visit(ReadStatement *) = 0;

    virtual void visit(ReturnStatement *) = 0;

    virtual void visit(StopStatement *) = 0;

    virtual void visit(ForStatement *) = 0;

    virtual void visit(RepeatStatement *) = 0;

    virtual void visit(WhileStatement *) = 0;

    virtual void visit(IfStatement *) = 0;

    virtual void visit(AssignStatement *) = 0;

    virtual void visit(SimpleType *) = 0;

    virtual void visit(ArrayType *) = 0;

    virtual void visit(RecordType *) = 0;

    virtual void visit(TypeDeclaration *) = 0;

    virtual void visit(ConstDeclaration *) = 0;

    virtual void visit(VarDeclaration *) = 0;
};