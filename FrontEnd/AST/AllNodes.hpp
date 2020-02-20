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
#include "Expressions/StringExpression.hpp"
#include "Expressions/ParenthesisExpression.hpp"

#include "Statements/Statement.hpp"
#include "Statements/EmptyStatement.hpp"
#include "Statements/ProcedureCallStatement.hpp"
#include "Statements/WriteStatement.hpp"
#include "Statements/ReadStatement.hpp"
#include "Statements/ReturnStatement.hpp"
#include "Statements/StopStatement.hpp"
#include "Statements/ForStatement.hpp"
#include "Statements/RepeatStatement.hpp"
#include "Statements/WhileStatement.hpp"
#include "Statements/IfStatement.hpp"
#include "FrontEnd/AST/Statements/AssignStatement.hpp"

#include "Declarations/SimpleType.hpp"
#include "Declarations/ArrayType.hpp"
#include "Declarations/RecordType.hpp"
#include "Declarations/TypeDeclaration.hpp"
#include "Declarations/ConstDeclaration.hpp"
#include "FrontEnd/AST/Declarations/VariableDeclaration.hpp"