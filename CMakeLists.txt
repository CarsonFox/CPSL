cmake_minimum_required(VERSION 3.0)

project(cpsl)

find_package(Boost)

find_package(BISON)
find_package(FLEX)

bison_target(Parser FrontEnd/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(Scanner FrontEnd/scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
add_flex_bison_dependency(Scanner Parser)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O0 -std=c++17 -fsanitize=address")

set(src ${BISON_Parser_OUTPUTS} ${FLEX_Scanner_OUTPUTS})
set(src ${src} FrontEnd/AST/LiteralExpression.cpp FrontEnd/AST/AST.cpp FrontEnd/AST/PrettyPrintVisitor.cpp
        FrontEnd/AST/SuccExpression.cpp FrontEnd/AST/SuccExpression.hpp FrontEnd/AST/PredExpression.cpp
        FrontEnd/AST/PredExpression.hpp FrontEnd/AST/OrdExpression.cpp FrontEnd/AST/OrdExpression.hpp
        FrontEnd/AST/ChrExpression.cpp FrontEnd/AST/ChrExpression.hpp FrontEnd/AST/RecordAccessExpression.cpp FrontEnd/AST/IdentifierExpression.cpp FrontEnd/AST/IdentifierExpression.hpp FrontEnd/AST/ArrayAccessExpression.cpp FrontEnd/AST/ArrayAccessExpression.hpp FrontEnd/AST/FunctionCallExpression.cpp FrontEnd/AST/FunctionCallExpression.hpp FrontEnd/AST/ExpressionList.cpp FrontEnd/AST/ExpressionList.hpp)

add_executable(cpsl cpsl.cpp ${src})
target_link_libraries(cpsl ${FLEX_LIBRARIES} ${BISON_LIBRARIES})
target_include_directories(cpsl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})