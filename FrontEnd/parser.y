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
long val;
char *str;
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

%type <val> Program
%type <nodelist> ConstantDeclList
%type <node> ConstantDecl

%%

Program: ConstantDeclList BEGIN_BLOCK END { ASTNode::main = new Program($1); }
;

ConstantDeclList: ConstantDeclList ConstantDecl { $1->push_back($2); $$ = $1; }
| { $$ = new std::vector<ASTNode*>(); }
;

ConstantDecl: STOP { $$ = (ASTNode *) new ConstantDecl(); std::cout << $$ << std::endl; }
;

%%

void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}