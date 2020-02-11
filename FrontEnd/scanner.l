%{
#include <cstdlib>

#include "FrontEnd/AST/AST.hpp"
#include "FrontEnd/AST/AllNodes.hpp"
#include "FrontEnd/AST/ExpressionList.hpp"

#include "parser.hpp"
%}

%option nounput

%%

array|ARRAY { return ARRAY; }
else|ELSE { return ELSE; }
if|IF { return IF; }
record|RECORD { return RECORD; }
then|THEN { return THEN; }
write|WRITE { return WRITE; }
begin|BEGIN { return BEGIN_BLOCK; }
elseif|ELSEIF { return ELSEIF; }
of|OF { return OF; }
ref|REF { return REF; }
to|TO { return TO; }
chr|CHR { return CHR; }
end|END { return END; }
ord|ORD { return ORD; }
repeat|REPEAT { return REPEAT; }
type|TYPE { return TYPE; }
const|CONST { return CONST; }
for|FOR { return FOR; }
pred|PRED { return PRED; }
return|return { return RETURN; }
until|UNTIL { return UNTIL; }
do|DO { return DO; }
forward|FORWARD { return FORWARD; }
procedure|PROCEDURE { return PROCEDURE; }
stop|STOP { return STOP; }
var|VAR { return VAR; }
downto|DOWNTO { return DOWNTO; }
function|FUNCTION { return FUNCTION; }
read|READ { return READ; }
succ|SUCC { return SUCC; }
while|WHILE { return WHILE; }

[a-zA-Z][a-zA-Z0-9_]* { yylval.str_val = strdup(yytext); return ID; }

"+" { return PLUS; }
"<>" { return NOT_EQUAL; }
";" { return SEMICOLON; }
"-" { return MINUS; }
"<" { return LESS; }
"(" { return OPEN_PAREN; }
"∗" { return MUL; }
"<=" { return LESS_EQUAL; }
")" { return CLOSE_PAREN; }
"/" { return DIV; }
">" { return GREATER; }
"[" { return OPEN_BRACKET; }
"&" { return AND; }
">=" { return GREATER_EQUAL; }
"]" { return CLOSE_BRACKET; }
"|" { return OR; }
"." { return DOT; }
":=" { return ASSIGN; }
"," { return COMMA; }
"%" { return MOD; }
"=" { return EQUAL; }
":" { return COLON; }
"~" { return NOT; }

[0-9]+|0x[0-9]+ { char *end; yylval.int_val = strtol(yytext, &end, 0); return NUMBER; }

'\\n' { yylval.char_val = '\n'; return CHARACTER; }
'\\r' { yylval.char_val = '\r'; return CHARACTER; }
'\\b' { yylval.char_val = '\b'; return CHARACTER; }
'\\t' { yylval.char_val = '\t'; return CHARACTER; }
'\\f' { yylval.char_val = '\f'; return CHARACTER; }
'\\.' { yylval.char_val = yytext[2]; return CHARACTER; }
'.'   { yylval.char_val = yytext[1]; return CHARACTER; }

\"[\\\".]*\" { yylval.str_val = strdup(yytext); return STRING; }

$.*\n {}

[ \b\t\n]* {}
%%