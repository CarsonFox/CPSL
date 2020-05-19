#include <iostream>
#include <cstdio>

#include "FrontEnd/AST/Program.hpp"

extern int yyparse();

extern FILE *yyin;

int main(int argc, char **argv) {
    if (argc > 1) {
        auto infile = std::fopen(argv[1], "r");
        if (!infile) {
            std::perror("Error opening file");
            return EXIT_FAILURE;
        }
        yyin = infile;
    }

    yyparse();

    Program::main->emit();

    return EXIT_SUCCESS;
}