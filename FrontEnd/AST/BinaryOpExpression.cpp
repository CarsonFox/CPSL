#include "BinaryOpExpression.hpp"

BinaryOpExpression::BinaryOpExpression(Expression *l, Expression *r, BinaryOp t) : left(l), right(r), type(t) {}
