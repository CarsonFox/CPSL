#include "ConstantFolding.hpp"

define_method (std::shared_ptr<LiteralExpression>, fold, (std::shared_ptr<LiteralExpression>
        expr)) {
    return expr;
}