%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int line_num = 1;
extern FILE *yyin;

/* Store the current token text for parser messages */
char current_id[256] = "";
char current_type[32] = "";
char current_value[256] = "";

/* From parser - used to save identifier before expression */
extern char saved_id[256];
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
"safehouse"         { strcpy(current_type, "class"); return KEYWORD_SAFEHOUSE; }
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
"qaidi_no"          { strcpy(current_type, "qaidi_no (int)"); return KEYWORD_QAIDI_NO; }
"bayania"           { strcpy(current_type, "bayania (string)"); return KEYWORD_BAYANIA; }
"float_sarkar"      { strcpy(current_type, "float_sarkar (float)"); return KEYWORD_FLOAT_SARKAR; }
"ishara"            { strcpy(current_type, "ishara (char)"); return KEYWORD_ISHARA; }
"namaloom"          { strcpy(current_type, "namaloom (void)"); return KEYWORD_NAMALOOM; }
"ain"               { return KEYWORD_AIN; }
"neutral"           { strcpy(current_value, "neutral (true)"); return KEYWORD_NEUTRAL; }
"janwar"            { strcpy(current_value, "janwar (false)"); return KEYWORD_JANWAR; }

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

{EXPONENTIAL}       { strcpy(current_value, yytext); return NUMBER_EXPONENTIAL; }
{FLOAT}             { strcpy(current_value, yytext); return NUMBER_FLOAT; }
{INTEGER}           { strcpy(current_value, yytext); return NUMBER_INTEGER; }
{IDENTIFIER}        { strcpy(current_id, yytext); strcpy(saved_id, yytext); return IDENTIFIER; }
{STRING}            { strcpy(current_value, yytext); return STRING_LITERAL; }
{CHAR}              { strcpy(current_value, yytext); return CHAR_LITERAL; }

.                   { fprintf(stderr, "Lexical Error at line %d: Invalid token '%s'\n", line_num, yytext); }

%%
