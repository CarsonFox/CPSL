%{
#include <iostream>
#include <map>

extern int yylex();
void yyerror(const char*);

std::map<std::string, double> variables;
%}

%union
{
double val;
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

StatementList: StatementList Statement {}
| {}
;

Statement: Expression DONE { std::cout << $1 << std::endl; }
| LET ID EQUAL Expression DONE { variables.insert_or_assign($2, $4); free($2); }
| DONE {}
;

Expression: Expression ADD Term { $$ = $1 + $3; }
| Expression SUB Term { $$ = $1 - $3; }
| Term { $$ = $1; }
;

Term: Term MUL Factor { $$ = $1 * $3; }
| Term Factor { $$ = $1 * $2; }
| Term DIV Factor { $$ = $1 / $3; }
| Factor { $$ = $1; }
;

Factor: OPEN Expression CLOSE { $$ = $2; }
| NUMBER { $$ = $1; }
| ID { $$ = variables[$1]; free($1); }
;

%%

void yyerror(const char* msg)
{
  std::cerr << msg << std::endl;
}