#include "ConstantFolding.hpp"

define_method (std::shared_ptr<LiteralExpression>, fold, (std::shared_ptr<LiteralExpression>
        expr)) {
    return expr;
}

define_method (std::shared_ptr<LiteralExpression>, fold, (std::shared_ptr<BinaryOpExpression>
        expr)) {
    switch (expr->type) {
        case BinaryOp::Or:
            return std::make_shared<LiteralExpression>(
                    fold(expr->left)->value ||
                    fold(expr->right)->value
            );
    }
}