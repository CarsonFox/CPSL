%{
#include <iostream>
#include <vector>
#include <memory>

#include "FrontEnd/AST/Program.hpp"
#include "FrontEnd/AST/AllNodes.hpp"
#include "FrontEnd/AST/Expressions/ExpressionList.hpp"
#include "FrontEnd/AST/Expressions/LValueList.hpp"
#include "FrontEnd/AST/Statements/StatementList.hpp"
#include "FrontEnd/AST/IdentifierList.hpp"

extern int yylex();
void yyerror(const char*);

extern int lineNumber;
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
IfStatement *ifStatement;
IdentifierList *identifierList;
Type *type;
RecordType *recordType;
TypeDeclaration *typeDecl;
ConstDeclaration *constDecl;
VariableDeclaration *varDecl;
Block *block;
Body *body;
FormalParameters *formalParameters;
Function *function;
Procedure *procedure;
Program *program;
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
%type <ifStatement> IfStatement
%type <identifierList> IdentifierList
%type <type> Type;
%type <recordType> RecordType;
%type <typeDecl> TypeDecl;
%type <constDecl> ConstDecl;
%type <varDecl> VarDecl;
%type <typeDecl> OptTypeDecl;
%type <constDecl> OptConstDecl;
%type <varDecl> OptVarDecl;
%type <block> Block;
%type <body> Body;
%type <formalParameters> FormalParameters
%type <formalParameters> FormalParameter
%type <function> FunctionDecl
%type <procedure> ProcedureDecl
%type <program> ProgramHead
%type <program> ProgramBody

%%

Program: ProgramHead ProgramBody Block DOT { Program::main = std::make_unique<Program>($1, $2, $3); }
;

ProgramHead: OptConstDecl OptTypeDecl OptVarDecl  { $$ = new Program($1, $2, $3); }
;

ProgramBody: ProgramBody ProcedureDecl { $$ = new Program($1, $2); }
| ProgramBody FunctionDecl { $$ = new Program($1, $2); }
| { $$ = new Program(); }
;

ProcedureDecl: PROCEDURE ID OPEN_PAREN FormalParameters CLOSE_PAREN SEMICOLON FORWARD SEMICOLON { $$ = new Procedure($2, $4); }
| PROCEDURE ID OPEN_PAREN FormalParameters CLOSE_PAREN SEMICOLON Body SEMICOLON { $$ = new Procedure($2, $4, $7); }
;

FunctionDecl: FUNCTION ID OPEN_PAREN FormalParameters CLOSE_PAREN COLON Type SEMICOLON FORWARD SEMICOLON { $$ = new Function($2, $4, $7); }
| FUNCTION ID OPEN_PAREN FormalParameters CLOSE_PAREN COLON Type SEMICOLON Body SEMICOLON { $$ = new Function($2, $4, $7, $9); }
;

FormalParameters: { $$ = nullptr; }
| FormalParameter { $$ = $1; }
| FormalParameters SEMICOLON FormalParameter { $$ = new FormalParameters($1, $3); }
;

FormalParameter: VAR IdentifierList COLON Type { $$ = new FormalParameters(ParType::VAR_T, $2, $4); }
| REF IdentifierList COLON Type { $$ = new FormalParameters(ParType::REF_T, $2, $4); }
| IdentifierList COLON Type { $$ = new FormalParameters(ParType::NONE, $1, $3); }
;

Body: OptConstDecl OptTypeDecl OptVarDecl Block { $$ = new Body($1, $2, $3, $4); }

Block: BEGIN_BLOCK StatementList END { $$ = new Block($2); }
;

OptConstDecl: ConstDecl { $$ = $1; }
| { $$ = nullptr; }
;

OptVarDecl: VarDecl { $$ = $1; }
| { $$ = nullptr; }
;

OptTypeDecl: TypeDecl { $$ = $1; }
| { $$ = nullptr; }
;

VarDecl: VAR IdentifierList COLON Type SEMICOLON { $$ = new VariableDeclaration($2, $4); }
| VarDecl IdentifierList COLON Type SEMICOLON { $$ = new VariableDeclaration($1, $2, $4); }
;

ConstDecl: CONST ID EQUAL Expression SEMICOLON { $$ = new ConstDeclaration($2, $4); }
| ConstDecl ID EQUAL Expression SEMICOLON { $$ = new ConstDeclaration($1, $2, $4); }
;

TypeDecl: TYPE ID EQUAL Type SEMICOLON { $$ = new TypeDeclaration($2, $4); }
| TypeDecl ID EQUAL Type SEMICOLON { $$ = new TypeDeclaration($1, $2, $4); }
;

Type: ID { $$ = new SimpleType($1); }
| ARRAY OPEN_BRACKET Expression COLON Expression CLOSE_BRACKET OF Type { $$ = new ArrayType($3, $5, $8); }
| RecordType END { $$ = $1; }
;

RecordType: RECORD IdentifierList COLON Type SEMICOLON { $$ = new RecordType($2, $4); }
| RecordType IdentifierList COLON Type SEMICOLON { $$ = new RecordType($1, $2, $4); }
;

IdentifierList: ID { $$ = new IdentifierList($1); }
| IdentifierList COMMA ID { $$ = new IdentifierList($1, $3); }
;

StatementList: StatementList SEMICOLON Statement { $$ = new StatementList($1, $3); }
| Statement { $$ = new StatementList(nullptr, $1); }
;

Statement: LValue ASSIGN Expression { $$ = new AssignStatement($1, $3); }
| IfStatement END { $$ = $1; }
| WHILE Expression DO StatementList END { $$ = new WhileStatement($2, $4); }
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

IfStatement: IF Expression THEN StatementList { $$ = new IfStatement($2, $4); }
| IfStatement ELSEIF Expression THEN StatementList { $1->addElseIf($3, $5); $$ = $1; }
| IfStatement ELSE StatementList { $1->addElse($3); $$ = $1; }
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
  std::cerr << "Line " << lineNumber << ": " << msg << std::endl;
  std::exit(EXIT_FAILURE);
}