%{
#include <cstdlib>

#include "parser.hpp"
%}

%option nounput

%%

    /* Keywords */
"array"|"ARRAY" { return ARRAY; }
"else"|"ELSE" { return ELSE; }
"if"|"IF" { return IF; }
"record"|"RECORD" { return RECORD; }
"then"|"THEN" { return THEN; }
"write"|"WRITE" { return WRITE; }
"begin"|"BEGIN" { return BEGIN; }
"elseif"|"ELSEIF" { return ELSEIF; }
"of"|"OF" { return OF; }
"ref"|"REF" { return REF; }
"to"|"TO" { return TO; }
"chr"|"CHR" { return CHR; }
"end"|"END" { return END; }
"ord"|"ORD" { return ORD; }
"repeat"|"REPEAT" { return REPEAT; }
"type"|"TYPE" { return TYPE; }
"const"|"CONST" { return CONST; }
"for"|"FOR" { return FOR; }
"pred"|"PRED" { return PRED; }
"return"|"return" { return RETURN; }
"until"|"UNTIL" { return UNTIL; }
"do"|"DO" { return DO; }
"forward"|"FORWARD" { return FORWARD; }
"procedure"|"PROCEDURE" { return PROCEDURE; }
"stop"|"STOP" { return STOP; }
"var"|"VAR" { return VAR; }
"downto"|"DOWNTO" { return DOWNTO; }
"function"|"FUNCTION" { return FUNCTION; }
"read"|"READ" { return READ; }
"succ"|"SUCC" { return SUCC; }
"while"|"WHILE" { return WHILE; }

    /* Identifiers */
[a-zA-Z][a-zA-Z0-9_]* { yylval.id = strdup(yytext); return ID; }

    /* Operators and delimiters */
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

    /* Integer constants */
[0-9]+|"0x"[0-9]+ { char *end; yylval.val = strtol(yytext, &end, 0); return NUMBER; }

    /* Character constants */
'\\n' { yylval.val = '\n'; return CHARACTER; }
'\\r' { yylval.val = '\r'; return CHARACTER; }
'\\b' { yylval.val = '\b'; return CHARACTER; }
'\\t' { yylval.val = '\t'; return CHARACTER; }
'\\f' { yylval.val = '\f'; return CHARACTER; }
'\\.'  { yylval.val = yytext[2]; return CHARACTER; }
'.'    { yylval.val = yytext[1]; return CHARACTER; }

    /* String literals */
\"[\\\".]*\" { yylval.id = strdup(yytext); return STRING; }

    /* Comments */
"$".*"\n" {}

    /* Whitespace */
[ \b\t\n]* {}
%%