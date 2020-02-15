%{
#include <iostream>
#include <vector>
#include <memory>

#include "FrontEnd/AST/AST.hpp"
#include "FrontEnd/AST/AllNodes.hpp"
#include "FrontEnd/AST/Expressions/ExpressionList.hpp"
#include "FrontEnd/AST/Expressions/LValueList.hpp"
#include "FrontEnd/AST/Statements/StatementList.hpp"

extern int yylex();
void yyerror(const char*);
%}

%union
{
int int_val;
char char_val;
char *str_val;
Expression *expression;
ExpressionList *expressionList;
LValue *lvalue;
LValueList *lvalueList;
Statement *statement;
StatementList *statementList;
}

%token ARRAY ELSE IF RECORD THEN WRITE BEGIN_BLOCK ELSEIF OF REF TO
%token CHR END ORD REPEAT TYPE CONST FOR PRED RETURN UNTIL DO
%token FORWARD PROCEDURE STOP VAR DOWNTO FUNCTION READ SUCC WHILE

%token ID

%token PLUS NOT_EQUAL SEMICOLON MINUS LESS OPEN_PAREN MUL LESS_EQUAL
%token CLOSE_PAREN DIV GREATER OPEN_BRACKET AND GREATER_EQUAL CLOSE_BRACKET
%token OR DOT ASSIGN COMMA MOD EQUAL COLON NOT

%token NUMBER
%token CHARACTER
%token STRING

%left PLUS MINUS
%left DIV MUL MOD

%left AND OR

%nonassoc NOT_EQUAL LESS GREATER LESS_EQUAL GREATER_EQUAL EQUAL

%right UNARYMINUS NOT

%type <str_val> ID
%type <str_val> STRING
%type <int_val> NUMBER
%type <char_val> CHARACTER
%type <expression> Expression
%type <expressionList> ExpressionList
%type <lvalue> LValue
%type <lvalueList> LValueList
%type <statement> Statement
%type <statementList> StatementList

%%

Program: Statement { AST::main = std::make_unique<AST>($1); }
;

StatementList: StatementList SEMICOLON Statement { $$ = new StatementList($1, $3); }
| Statement { $$ = new StatementList(nullptr, $1); }
| { $$ = new StatementList(nullptr, nullptr); }
;

Statement: WHILE Expression DO StatementList END { $$ = new WhileStatement($2, $4); }
| REPEAT StatementList UNTIL Expression { $$ = new RepeatStatement($2, $4); }
| FOR ID ASSIGN Expression TO Expression DO StatementList END { $$ = new ForStatement($2, $4, $6, $8, ForType::UP_TO); }
| FOR ID ASSIGN Expression DOWNTO Expression DO StatementList END { $$ = new ForStatement($2, $4, $6, $8, ForType::DOWN_TO); }
| STOP { $$ = new StopStatement(); }
| RETURN Expression { $$ = new ReturnStatement($2); }
| RETURN { $$ = new ReturnStatement(nullptr); }
| READ OPEN_PAREN LValueList CLOSE_PAREN { $$ = new ReadStatement($3); }
| WRITE OPEN_PAREN ExpressionList CLOSE_PAREN { $$ = new WriteStatement($3); }
| ID OPEN_PAREN ExpressionList CLOSE_PAREN { $$ = new ProcedureCallStatement($1, $3); }
| { $$ = new EmptyStatement(); }
;

LValueList: LValueList COMMA LValue { $$ = new LValueList($1, $3); }
| LValue { $$ = new LValueList(nullptr, $1); }
| { $$ = new LValueList(nullptr, nullptr); }
;

ExpressionList: ExpressionList COMMA Expression { $$ = new ExpressionList($1, $3); }
| Expression { $$ = new ExpressionList(nullptr, $1); }
| { $$ = new ExpressionList(nullptr, nullptr); }
;

Expression: Expression OR Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::Or); }
| Expression AND Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::And); }
| Expression EQUAL Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::Equal); }
| Expression NOT_EQUAL Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::NotEqual); }
| Expression LESS Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::Less); }
| Expression LESS_EQUAL Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::LessEqual); }
| Expression GREATER Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::Greater); }
| Expression GREATER_EQUAL Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::GreaterEqual); }
| Expression PLUS Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::Add); }
| Expression MINUS Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::Sub); }
| Expression MUL Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::Mul); }
| Expression DIV Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::Div); }
| Expression MOD Expression { $$ = new BinaryOpExpression($1, $3, BinaryOp::Mod); }
| NOT Expression { $$ = new UnaryOpExpression($2, UnaryOp::Not); }
| MINUS Expression %prec UNARYMINUS { $$ = new UnaryOpExpression($2, UnaryOp::Neg); }
| ID OPEN_PAREN ExpressionList CLOSE_PAREN { $$ = new FunctionCallExpression($1, $3); }
| CHR OPEN_PAREN Expression CLOSE_PAREN { $$ = new ChrExpression($3); }
| ORD OPEN_PAREN Expression CLOSE_PAREN { $$ = new OrdExpression($3); }
| PRED OPEN_PAREN Expression CLOSE_PAREN { $$ = new PredExpression($3); }
| SUCC OPEN_PAREN Expression CLOSE_PAREN { $$ = new SuccExpression($3); }
| OPEN_PAREN Expression CLOSE_PAREN { $$ = new ParenthesisExpression($2); }
| LValue { $$ = $1; }
| NUMBER { $$ = new LiteralExpression($1); }
| CHARACTER { $$ = new LiteralExpression($1); }
| STRING { $$ = new StringExpression($1); }
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