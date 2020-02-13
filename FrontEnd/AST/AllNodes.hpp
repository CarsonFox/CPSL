#pragma once

#include "ASTNode.hpp"
#include "FrontEnd/AST/Expressions/Expression.hpp"
#include "FrontEnd/AST/Expressions/LiteralExpression.hpp"
#include "FrontEnd/AST/Expressions/SuccExpression.hpp"
#include "FrontEnd/AST/Expressions/PredExpression.hpp"
#include "FrontEnd/AST/Expressions/OrdExpression.hpp"
#include "FrontEnd/AST/Expressions/ChrExpression.hpp"
#include "FrontEnd/AST/Expressions/LValue.hpp"
#include "FrontEnd/AST/Expressions/RecordAccessExpression.hpp"
#include "FrontEnd/AST/Expressions/IdentifierExpression.hpp"
#include "FrontEnd/AST/Expressions/ArrayAccessExpression.hpp"
#include "FrontEnd/AST/Expressions/FunctionCallExpression.hpp"
#include "FrontEnd/AST/Expressions/BinaryOpExpression.hpp"
#include "FrontEnd/AST/Expressions/UnaryOpExpression.hpp"
#include "Expressions/ParenthesisExpression.hpp"

#include "Statements/Statement.hpp"
#include "Statements/EmptyStatement.hpp"
#include "Statements/ProcedureCallStatement.hpp"
#include "Statements/WriteStatement.hpp"
#include "Statements/ReadStatement.hpp"