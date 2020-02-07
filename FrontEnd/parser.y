%{
#include <iostream>
#include <vector>

#include "FrontEnd/AST/AST.hpp"
#include "FrontEnd/AST/Program.hpp"
#include "FrontEnd/AST/ConstantDecl.hpp"

extern int yylex();
void yyerror(const char*);
%}

%union
{
int int_val;
char *str_val;
ASTNode *node;
std::vector<ASTNode *> *nodelist;
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

%type <int_val> Program
%type <nodelist> ConstantDecls
%type <nodelist> ConstantDeclList
%type <node> ConstantDecl

%type <str_val> ID
%type <int_val> NUMBER

%%

Program: BEGIN_BLOCK ConstantDecls END { ASTNode::main = new Program($2); }
;

ConstantDecls: CONST ConstantDeclList { $$ = $2; }
| { $$ = new std::vector<ASTNode*>(); }
;

ConstantDeclList: ConstantDeclList ConstantDecl { $1->push_back($2); $$ = $1; }
| { $$ = new std::vector<ASTNode*>(); }
;

ConstantDecl: ID EQUAL NUMBER SEMICOLON { $$ = (ASTNode *) new ConstantDecl($1, $3); }
;
/*
LValue: ID
| ID AccessList
;

AccessList: ID DOT ID AccessList
| ID OPEN_BRACKET NUMBER CLOSE_BRACKET
*/
%%

void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}