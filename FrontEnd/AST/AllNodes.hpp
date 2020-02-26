#pragma once

#include "Expressions/AllExpressions.hpp"

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
#include "Statements/AssignStatement.hpp"

#include "Declarations/SimpleType.hpp"
#include "Declarations/ArrayType.hpp"
#include "Declarations/RecordType.hpp"
#include "Declarations/TypeDeclaration.hpp"
#include "Declarations/ConstDeclaration.hpp"
#include "Declarations/VariableDeclaration.hpp"

#include "FrontEnd/AST/Declarations/Block.hpp"
#include "Declarations/Body.hpp"
#include "Declarations/FormalParameters.hpp"
#include "Declarations/Function.hpp"
#include "Declarations/Procedure.hpp"