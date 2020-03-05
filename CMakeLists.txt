cmake_minimum_required(VERSION 3.0)

enable_testing()

project(cpsl)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

find_package(BISON)
find_package(FLEX)

bison_target(Parser FrontEnd/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(Scanner FrontEnd/scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
add_flex_bison_dependency(Scanner Parser)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O0 -g3 -std=c++17 -fsanitize=address")

set(src ${BISON_Parser_OUTPUTS} ${FLEX_Scanner_OUTPUTS})
set(src ${src} FrontEnd/AST/Expressions/LiteralExpression.cpp FrontEnd/AST/Program.cpp
        FrontEnd/AST/Expressions/SuccExpression.cpp FrontEnd/AST/Expressions/PredExpression.cpp
        FrontEnd/AST/Expressions/OrdExpression.cpp FrontEnd/AST/Expressions/OrdExpression.hpp
        FrontEnd/AST/Expressions/ChrExpression.cpp FrontEnd/AST/Expressions/RecordAccessExpression.cpp
        FrontEnd/AST/Expressions/IdentifierExpression.cpp FrontEnd/AST/Expressions/IdentifierExpression.hpp
        FrontEnd/AST/Expressions/ArrayAccessExpression.cpp FrontEnd/AST/Expressions/ArrayAccessExpression.hpp
        FrontEnd/AST/Expressions/FunctionCallExpression.cpp FrontEnd/AST/Expressions/ExpressionList.cpp
        FrontEnd/AST/Expressions/BinaryOperators/BinaryOpExpression.cpp FrontEnd/AST/Expressions/UnaryOpExpression.cpp
        FrontEnd/AST/Expressions/ParenthesisExpression.cpp FrontEnd/AST/Statements/ProcedureCallStatement.cpp
        FrontEnd/AST/Statements/WriteStatement.cpp FrontEnd/AST/Expressions/LValueList.cpp FrontEnd/AST/Statements/ReadStatement.cpp
        FrontEnd/AST/Statements/ReturnStatement.cpp FrontEnd/AST/Expressions/StringExpression.cpp
        FrontEnd/AST/Statements/StatementList.cpp FrontEnd/AST/Statements/ForStatement.cpp FrontEnd/AST/Statements/RepeatStatement.cpp
        FrontEnd/AST/Statements/WhileStatement.cpp FrontEnd/AST/Statements/IfStatement.cpp FrontEnd/AST/Statements/AssignStatement.cpp
        FrontEnd/AST/IdentifierList.cpp FrontEnd/AST/Declarations/SimpleType.cpp FrontEnd/AST/Declarations/ArrayType.cpp
        FrontEnd/AST/Declarations/RecordType.cpp FrontEnd/AST/Declarations/TypeDeclaration.cpp
        FrontEnd/AST/Declarations/TypeDeclaration.hpp
        FrontEnd/AST/Declarations/ConstDeclaration.cpp FrontEnd/AST/Declarations/VariableDeclaration.cpp
        FrontEnd/AST/Declarations/Block.cpp FrontEnd/AST/Declarations/Body.cpp FrontEnd/AST/Declarations/FormalParameters.cpp
        FrontEnd/AST/Declarations/Function.cpp FrontEnd/AST/Declarations/Procedure.cpp FrontEnd/AST/Util.cpp
        FrontEnd/AST/Expressions/BinaryOperators/OrExpression.cpp FrontEnd/AST/Expressions/BinaryOperators/AndExpression.cpp
        FrontEnd/AST/Expressions/BinaryOperators/EqualExpression.cpp FrontEnd/AST/Expressions/BinaryOperators/NotEqualExpression.cpp
        FrontEnd/AST/Expressions/BinaryOperators/LessExpression.cpp FrontEnd/AST/Expressions/BinaryOperators/LessEqualExpression.cpp
        FrontEnd/AST/Expressions/BinaryOperators/GreaterExpression.cpp
        FrontEnd/AST/Expressions/BinaryOperators/GreaterEqualExpression.cpp FrontEnd/AST/Expressions/BinaryOperators/AddExpression.cpp
        FrontEnd/AST/Expressions/BinaryOperators/SubExpression.cpp FrontEnd/AST/Expressions/BinaryOperators/MulExpression.cpp
        FrontEnd/AST/Expressions/BinaryOperators/DivExpression.cpp FrontEnd/AST/Expressions/BinaryOperators/ModExpression.cpp
        FrontEnd/AST/Expressions/BinaryOperators/ModExpression.hpp)

add_executable(cpsl cpsl.cpp ${src})
target_include_directories(cpsl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cpsl ${FLEX_LIBRARIES} ${BISON_LIBRARIES})

add_executable(test_exe test/test.cpp ${src})
target_include_directories(test_exe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIRS})
target_compile_definitions(test_exe PRIVATE "BOOST_TEST_DYN_LINK=1")
target_link_libraries(test_exe ${FLEX_LIBRARIES} ${BISON_LIBRARIES} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
