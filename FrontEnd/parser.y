%{
#include <iostream>

#include "FrontEnd/AST/AST.hpp"
#include "FrontEnd/AST/Program.hpp"

extern int yylex();
void yyerror(const char*);
%}

%union
{
long val;
char *str;
}

%token ARRAY ELSE IF RECORD THEN WRITE BEGIN_BLOCK ELSEIF OF REF TO
%token CHR END ORD REPEAT TYPE CONST FOR PRED RETURN UNTIL DO
%token FORWARD PROCEDURE STOP VAR DOWNTO FUNCTION READ SUCC WHILE

%token ID

%token PLUS NOT_EQUAL SEMICOLON MINUS LESS OPEN_PAREN MUL LESS_EQUAL
%token CLOSE_PAREN DIV GREATER OPEN_BRACKET AND GREATER_EQUAL CLOSE_BRACKET
%token OR DOT ASSIGN COMMA MOD EQUAL COLON

%token NUMBER
%token CHARACTER
%token STRING

%type <val> Program

%%

Program: BEGIN_BLOCK END { ASTNode::main = new Program(); }
;

%%

void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}