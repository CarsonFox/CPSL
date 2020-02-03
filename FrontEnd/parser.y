%{
#include <iostream>
#include <map>

#include "FrontEnd/AST.hpp"

extern int yylex();
void yyerror(const char*);

std::map<std::string, double> variables;
%}

%union
{
long val;
char *id;
}

%token NUMBER
%token ADD SUB MUL DIV OPEN CLOSE
%token DONE
%token LET ID EQUAL

%type <val> NUMBER
%type <val> Expression
%type <val> Factor
%type <val> Term
%type <id> ID

%%



%%

void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}