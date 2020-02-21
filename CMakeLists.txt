cmake_minimum_required(VERSION 3.0)

project(cpsl)

find_package(Boost)

find_package(BISON)
find_package(FLEX)

bison_target(Parser FrontEnd/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(Scanner FrontEnd/scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
add_flex_bison_dependency(Scanner Parser)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O0 -g3 -std=c++17 -fsanitize=address")

set(src ${BISON_Parser_OUTPUTS} ${FLEX_Scanner_OUTPUTS})
set(src ${src} FrontEnd/AST/Expressions/LiteralExpression.cpp FrontEnd/AST/AST.cpp FrontEnd/AST/PrettyPrintVisitor.cpp
        FrontEnd/AST/Expressions/SuccExpression.cpp FrontEnd/AST/Expressions/SuccExpression.hpp FrontEnd/AST/Expressions/PredExpression.cpp
        FrontEnd/AST/Expressions/PredExpression.hpp FrontEnd/AST/Expressions/OrdExpression.cpp FrontEnd/AST/Expressions/OrdExpression.hpp
        FrontEnd/AST/Expressions/ChrExpression.cpp FrontEnd/AST/Expressions/ChrExpression.hpp FrontEnd/AST/Expressions/RecordAccessExpression.cpp
        FrontEnd/AST/Expressions/IdentifierExpression.cpp FrontEnd/AST/Expressions/IdentifierExpression.hpp
        FrontEnd/AST/Expressions/ArrayAccessExpression.cpp FrontEnd/AST/Expressions/ArrayAccessExpression.hpp
        FrontEnd/AST/Expressions/FunctionCallExpression.cpp FrontEnd/AST/Expressions/FunctionCallExpression.hpp FrontEnd/AST/Expressions/ExpressionList.cpp
        FrontEnd/AST/Expressions/ExpressionList.hpp FrontEnd/AST/Expressions/BinaryOpExpression.cpp FrontEnd/AST/Expressions/UnaryOpExpression.cpp FrontEnd/AST/Expressions/UnaryOpExpression.hpp FrontEnd/AST/Expressions/ParenthesisExpression.cpp FrontEnd/AST/Expressions/ParenthesisExpression.hpp FrontEnd/AST/Statements/ProcedureCallStatement.cpp FrontEnd/AST/Statements/ProcedureCallStatement.hpp FrontEnd/AST/Statements/WriteStatement.cpp FrontEnd/AST/Statements/WriteStatement.hpp FrontEnd/AST/Expressions/LValueList.cpp FrontEnd/AST/Expressions/LValueList.hpp FrontEnd/AST/Statements/ReadStatement.cpp FrontEnd/AST/Statements/ReadStatement.hpp FrontEnd/AST/Statements/ReturnStatement.cpp FrontEnd/AST/Statements/ReturnStatement.hpp FrontEnd/AST/Expressions/StringExpression.cpp FrontEnd/AST/Expressions/StringExpression.hpp FrontEnd/AST/Statements/StatementList.cpp FrontEnd/AST/Statements/StatementList.hpp FrontEnd/AST/Statements/ForStatement.cpp FrontEnd/AST/Statements/ForStatement.hpp FrontEnd/AST/Statements/RepeatStatement.cpp FrontEnd/AST/Statements/RepeatStatement.hpp FrontEnd/AST/Statements/WhileStatement.cpp FrontEnd/AST/Statements/WhileStatement.hpp FrontEnd/AST/Statements/IfStatement.cpp FrontEnd/AST/Statements/IfStatement.hpp FrontEnd/AST/Statements/AssignStatement.cpp FrontEnd/AST/Statements/AssignStatement.hpp FrontEnd/AST/IdentifierList.cpp FrontEnd/AST/IdentifierList.hpp FrontEnd/AST/Declarations/Type.hpp FrontEnd/AST/Declarations/SimpleType.cpp FrontEnd/AST/Declarations/SimpleType.hpp FrontEnd/AST/Declarations/ArrayType.cpp FrontEnd/AST/Declarations/ArrayType.hpp FrontEnd/AST/Declarations/RecordType.cpp FrontEnd/AST/Declarations/RecordType.hpp FrontEnd/AST/Declarations/TypeDeclaration.cpp FrontEnd/AST/Declarations/TypeDeclaration.hpp
        FrontEnd/AST/Declarations/ConstDeclaration.cpp FrontEnd/AST/Declarations/VariableDeclaration.cpp FrontEnd/AST/Block.cpp FrontEnd/AST/Block.hpp)

add_executable(cpsl cpsl.cpp ${src})
target_link_libraries(cpsl ${FLEX_LIBRARIES} ${BISON_LIBRARIES})
target_include_directories(cpsl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})