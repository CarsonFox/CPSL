cmake_minimum_required(VERSION 3.0)

project(cpsl)

find_package(Boost)

find_package(BISON)
find_package(FLEX)

bison_target(Parser FrontEnd/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(Scanner FrontEnd/scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
add_flex_bison_dependency(Scanner Parser)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O0 -std=c++17 -fsanitize=address")

set(src ${BISON_Parser_OUTPUTS} ${FLEX_Scanner_OUTPUTS} FrontEnd/AST/Program.cpp FrontEnd/AST/AST.cpp FrontEnd/AST/ConstantDecl.cpp FrontEnd/AST/RecordAccess.cpp)

add_executable(main main.cpp ${src})
target_link_libraries(main ${FLEX_LIBRARIES} ${BISON_LIBRARIES})
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})