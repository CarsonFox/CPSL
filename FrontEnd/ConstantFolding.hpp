#pragma once

#include <memory>
#include <yorel/yomm2/cute.hpp>

#include "AST/Expressions/AllExpressions.hpp"

using yorel::yomm2::virtual_;

register_class (Expression);
register_class (LiteralExpression, Expression);
register_class (BinaryOpExpression, Expression);

declare_method(std::shared_ptr<LiteralExpression>, fold, (virtual_<std::shared_ptr<Expression>>));