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
LValue *lvalue;
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
%type <lvalue> LValue

%%

Program: Expression { AST::main = std::make_unique<AST>($1); }
;

Expression: CHR OPEN_PAREN Expression CLOSE_PAREN { $$ = new ChrExpression($3); }
| ORD OPEN_PAREN Expression CLOSE_PAREN { $$ = new OrdExpression($3); }
| PRED OPEN_PAREN Expression CLOSE_PAREN { $$ = new PredExpression($3); }
| SUCC OPEN_PAREN Expression CLOSE_PAREN { $$ = new SuccExpression($3); }
| LValue { $$ = $1; }
| NUMBER { $$ = new LiteralExpression($1); }
;

LValue: LValue DOT ID { $$ = new RecordAccessExpression($1, $3); }
| LValue OPEN_BRACKET Expression CLOSE_BRACKET { $$ = new ArrayAccessExpression($1, $3); }
| ID { $$ = new IdentifierExpression($1); }
;

%%

void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}