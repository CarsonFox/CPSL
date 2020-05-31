cmake_minimum_required(VERSION 3.0)

project(cpsl)

find_package(BISON)
find_package(FLEX)

bison_target(Parser src/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(Scanner src/scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
add_flex_bison_dependency(Scanner Parser)

set(CMAKE_CXX_FLAGS "-std=c++17")

set(src ${BISON_Parser_OUTPUTS} ${FLEX_Scanner_OUTPUTS})
set(src ${src} src/AST/Expressions/LiteralExpression.cpp src/AST/Program.cpp
        src/AST/Expressions/SuccExpression.cpp src/AST/Expressions/PredExpression.cpp src/AST/Expressions/OrdExpression.cpp
        src/AST/Expressions/ChrExpression.cpp src/AST/Expressions/RecordAccessExpression.cpp
        src/AST/Expressions/IdentifierExpression.cpp src/AST/Expressions/ArrayAccessExpression.cpp
        src/AST/Expressions/FunctionCallExpression.cpp src/AST/Expressions/ExpressionList.cpp
        src/AST/Expressions/BinaryOperators/BinaryOpExpression.cpp src/AST/Expressions/UnaryOperators/UnaryOpExpression.cpp
        src/AST/Expressions/ParenthesisExpression.cpp src/AST/Statements/ProcedureCallStatement.cpp
        src/AST/Statements/WriteStatement.cpp src/AST/Expressions/LValueList.cpp src/AST/Statements/ReadStatement.cpp
        src/AST/Statements/ReturnStatement.cpp src/AST/Expressions/StringExpression.cpp
        src/AST/Statements/StatementList.cpp src/AST/Statements/ForStatement.cpp src/AST/Statements/RepeatStatement.cpp
        src/AST/Statements/WhileStatement.cpp src/AST/Statements/IfStatement.cpp src/AST/Statements/AssignStatement.cpp
        src/AST/IdentifierList.cpp src/AST/Types/SimpleType.cpp src/AST/Types/ArrayType.cpp
        src/AST/Types/RecordType.cpp src/AST/Declarations/TypeDeclaration.cpp
        src/AST/Declarations/ConstDeclaration.cpp src/AST/Declarations/VariableDeclaration.cpp
        src/AST/Declarations/Block.cpp src/AST/Declarations/Body.cpp src/AST/Declarations/FormalParameters.cpp
        src/AST/Declarations/Function.cpp src/AST/Declarations/Procedure.cpp src/AST/Util.cpp
        src/AST/Expressions/BinaryOperators/OrExpression.cpp src/AST/Expressions/BinaryOperators/AndExpression.cpp
        src/AST/Expressions/BinaryOperators/EqualExpression.cpp src/AST/Expressions/BinaryOperators/NotEqualExpression.cpp
        src/AST/Expressions/BinaryOperators/LessExpression.cpp src/AST/Expressions/BinaryOperators/LessEqualExpression.cpp
        src/AST/Expressions/BinaryOperators/GreaterExpression.cpp
        src/AST/Expressions/BinaryOperators/GreaterEqualExpression.cpp src/AST/Expressions/BinaryOperators/AddExpression.cpp
        src/AST/Expressions/BinaryOperators/SubExpression.cpp src/AST/Expressions/BinaryOperators/MulExpression.cpp
        src/AST/Expressions/BinaryOperators/DivExpression.cpp src/AST/Expressions/BinaryOperators/ModExpression.cpp
        src/AST/Expressions/UnaryOperators/NegExpression.cpp src/AST/Expressions/UnaryOperators/NotExpression.cpp
        src/SymbolTable/SymbolTable.cpp src/SymbolTable/Variable.cpp
        src/RegisterPool.cpp src/Labels.cpp src/AST/Types/BuiltinType.cpp
        src/AST/Statements/StopStatement.cpp src/AST/Declarations/Subroutine.cpp)

add_executable(cpsl src/cpsl.cpp ${src})
target_include_directories(cpsl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
