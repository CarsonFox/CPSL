%{
#include <iostream>
#include <vector>
#include <memory>

#include "FrontEnd/AST/AST.hpp"
#include "FrontEnd/AST/AllNodes.hpp"

extern int yylex();
void yyerror(const char*);
%}

%union
{
int int_val;
char *str_val;
Expression *expression;
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

%type <str_val> ID
%type <int_val> NUMBER
%type <expression> Expression

%%

Program: Expression { AST::main = std::make_unique<AST>($1); }
;

Expression: NUMBER { $$ = new LiteralExpression($1); }
;

%%

void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}