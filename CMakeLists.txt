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
set(src ${src} FrontEnd/AST/Expression/LiteralExpression.cpp FrontEnd/AST/AST.cpp FrontEnd/AST/PrettyPrintVisitor.cpp
        FrontEnd/AST/Expression/SuccExpression.cpp FrontEnd/AST/Expression/SuccExpression.hpp FrontEnd/AST/Expression/PredExpression.cpp
        FrontEnd/AST/Expression/PredExpression.hpp FrontEnd/AST/Expression/OrdExpression.cpp FrontEnd/AST/Expression/OrdExpression.hpp
        FrontEnd/AST/Expression/ChrExpression.cpp FrontEnd/AST/Expression/ChrExpression.hpp FrontEnd/AST/Expression/RecordAccessExpression.cpp
        FrontEnd/AST/Expression/IdentifierExpression.cpp FrontEnd/AST/Expression/IdentifierExpression.hpp
        FrontEnd/AST/Expression/ArrayAccessExpression.cpp FrontEnd/AST/Expression/ArrayAccessExpression.hpp
        FrontEnd/AST/Expression/FunctionCallExpression.cpp FrontEnd/AST/Expression/FunctionCallExpression.hpp FrontEnd/AST/Expression/ExpressionList.cpp
        FrontEnd/AST/Expression/ExpressionList.hpp FrontEnd/AST/Expression/BinaryOpExpression.cpp FrontEnd/AST/Expression/UnaryOpExpression.cpp FrontEnd/AST/Expression/UnaryOpExpression.hpp FrontEnd/AST/Expression/ParenthesisExpression.cpp FrontEnd/AST/Expression/ParenthesisExpression.hpp)

add_executable(cpsl cpsl.cpp ${src})
target_link_libraries(cpsl ${FLEX_LIBRARIES} ${BISON_LIBRARIES})
target_include_directories(cpsl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})