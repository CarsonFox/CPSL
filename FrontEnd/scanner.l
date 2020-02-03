%{
#include <cstdlib>

#include "parser.hpp"
%}

%option nounput

%%

"//".*"\n" { return DONE; }
"/*".*"*/" {}
[ \t]+ {}

"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"(" { return OPEN; }
")" { return CLOSE; }
"\n" { return DONE; }
";" { return DONE; }
"=" { return EQUAL; }

"let"|"LET" { return LET; }
[a-zA-z]+ { yylval.id = strdup(yytext); return ID; }

-?[0-9]+(\.[0-9]+)? { yylval.val = atof(yytext); return NUMBER; }

%%