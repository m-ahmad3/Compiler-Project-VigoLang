%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

int line_num = 1;
extern FILE *yyin;
%}

%option noyywrap

DIGIT [0-9]
LETTER [a-zA-Z]
SIGN [+\-]

IDENTIFIER \^{LETTER}({LETTER}|{DIGIT}|_)*
EXPONENTIAL {SIGN}?{DIGIT}+(\.{DIGIT}+)?[eE]{SIGN}?{DIGIT}+
FLOAT {SIGN}?{DIGIT}+\.{DIGIT}+
INTEGER {SIGN}?{DIGIT}+
STRING \"[^\"]*\"
CHAR \'[^\']\'
WHITESPACE [ \t]+
NEWLINE \n

COMMENT "#*"([^*]|\*+[^*#])*"*#"
SINGLE_COMMENT "###".*

%%

{COMMENT}         { }
{SINGLE_COMMENT}  { }
{WHITESPACE}      { }
{NEWLINE}         { line_num++; }

"ghq"               { return KEYWORD_GHQ; }
"safehouse"         { return KEYWORD_SAFEHOUSE; }
"nro"               { return KEYWORD_NRO; }
"order_hai"         { return KEYWORD_ORDER_HAI; }
"doosra_order"      { return KEYWORD_DOOSRA_ORDER; }
"warna_vigo"        { return KEYWORD_WARNA_VIGO; }
"long_march"        { return KEYWORD_LONG_MARCH; }
"jab_tak_missing"   { return KEYWORD_JAB_TAK_MISSING; }
"deal_ho_gai"       { return KEYWORD_DEAL_HO_GAI; }
"chaltay_raho"      { return KEYWORD_CHALTAY_RAHO; }
"farmaan"           { return KEYWORD_FARMAAN; }
"taftish"           { return KEYWORD_TAFTISH; }
"qaidi_no"          { return KEYWORD_QAIDI_NO; }
"bayania"           { return KEYWORD_BAYANIA; }
"float_sarkar"      { return KEYWORD_FLOAT_SARKAR; }
"ishara"            { return KEYWORD_ISHARA; }
"namaloom"          { return KEYWORD_NAMALOOM; }
"ain"               { return KEYWORD_AIN; }
"neutral"           { return KEYWORD_NEUTRAL; }
"janwar"            { return KEYWORD_JANWAR; }

":="                { return OP_ASSIGN; }
"=?"                { return OP_EQUAL; }
">?"                { return OP_GREATER; }
"<?"                { return OP_LESS; }
"+:"                { return OP_ADD; }
"-:"                { return OP_SUB; }
"*:"                { return OP_MUL; }
"<<"                { return OP_OUTPUT; }
">>"                { return OP_INPUT; }

"{{"                { return PUNCT_BLOCK_START; }
"}}"                { return PUNCT_BLOCK_END; }
"[["                { return PUNCT_EXPR_START; }
"]]"                { return PUNCT_EXPR_END; }
"@"                 { return PUNCT_TERMINATOR; }
","                 { return PUNCT_COMMA; }

{EXPONENTIAL}       { return NUMBER_EXPONENTIAL; }
{FLOAT}             { return NUMBER_FLOAT; }
{INTEGER}           { return NUMBER_INTEGER; }
{IDENTIFIER}        { return IDENTIFIER; }
{STRING}            { return STRING_LITERAL; }
{CHAR}              { return CHAR_LITERAL; }

.                   { fprintf(stderr, "Lexical Error at line %d: Invalid token '%s'\n", line_num, yytext); }

%%
