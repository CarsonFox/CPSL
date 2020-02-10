#include "BinaryOpExpression.hpp"

BinaryOpExpression *BinaryOpExpression::Sub(Expression *left, Expression *right) {
    return new BinaryOpExpression(left, right, [](int x, int y) { return x - y; }, '-');
}

BinaryOpExpression::BinaryOpExpression(Expression *l, Expression *r,
                                       std::function<int(int, int)> f, char c) : left(l),
                                                                                 right(r),
                                                                                 op(std::move(f)),
                                                                                 opChar(c) {

}
