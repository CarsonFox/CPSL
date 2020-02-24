#pragma once

#include <memory>

#include "AST/Expressions/AllExpressions.hpp"

#include <yorel/yomm2/cute.hpp>

using yorel::yomm2::virtual_;

register_class (Expression);
register_class (LiteralExpression, Expression);
register_class (BinaryOpExpression, Expression);

//declare_method(std::unique_ptr<Expression>, fold, (virtual_<const Expression &>));