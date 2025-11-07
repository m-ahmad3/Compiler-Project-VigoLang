%{
#include <stdio.h>
#include <string.h>

int line_num = 1;
FILE *token_file;
FILE *error_file;
int error_count = 0;
int token_count = 0;
%}

%option noyywrap

/* Regular Expression Definitions */
DIGIT           [0-9]
LETTER          [a-z]
UPPERCASE       [A-Z]
IDENTIFIER      \^[a-z]([a-z]|{DIGIT}|_)*
INTEGER         {DIGIT}+
FLOAT           {DIGIT}+\.{DIGIT}+
EXPONENTIAL     {DIGIT}+(\.{DIGIT}+)?[eE][+-]?{DIGIT}+
STRING          \"[^\"]*\"
CHAR            \'[^\']\'
WHITESPACE      [ \t]+
NEWLINE         \n

/* Keywords (20 total) */
KEYWORD_GHQ             "ghq"
KEYWORD_SAFEHOUSE       "safehouse"
KEYWORD_NRO             "nro"
KEYWORD_ORDER_HAI       "order_hai"
KEYWORD_DOOSRA_ORDER    "doosra_order"
KEYWORD_WARNA_VIGO      "warna_vigo"
KEYWORD_LONG_MARCH      "long_march"
KEYWORD_JAB_TAK_MISSING "jab_tak_missing"
KEYWORD_DEAL_HO_GAI     "deal_ho_gai"
KEYWORD_CHALTAY_RAHO    "chaltay_raho"
KEYWORD_FARMAAN         "farmaan"
KEYWORD_TAFTISH         "taftish"
KEYWORD_QAIDI_NO        "qaidi_no"
KEYWORD_BAYANIA         "bayania"
KEYWORD_FLOAT_SARKAR    "float_sarkar"
KEYWORD_ISHARA          "ishara"
KEYWORD_NAMALOOM        "namaloom"
KEYWORD_AIN             "ain"
KEYWORD_NEUTRAL         "neutral"
KEYWORD_JANWAR          "janwar"

/* Operators (7 total) */
OP_ADD          "+:"
OP_SUB          "-:"
OP_MUL          "*:"
OP_ASSIGN       ":="
OP_EQUAL        "=?"
OP_GREATER      ">?"
OP_LESS         "<?"
OP_OUTPUT       "<<"
OP_INPUT        ">>"
OP_INCREMENT    "^i++"
OP_DECREMENT    "^i--"

/* Punctuation (7 total) */
PUNCT_TERMINATOR "@"
PUNCT_BLOCK_START "{{"
PUNCT_BLOCK_END "}}"
PUNCT_EXPR_START "[["
PUNCT_EXPR_END "]]"
PUNCT_COMMA ","

/* Comments */
COMMENT         "#*"([^*]|\*+[^*#])*"*#"
SINGLE_LINE_COMMENT "##"[^\n]*

%%

{COMMENT}       { /* Ignore multi-line comments */ }
{SINGLE_LINE_COMMENT} { /* Ignore single-line comments */ }

{KEYWORD_GHQ}           { 
    fprintf(token_file, "Line %d: KEYWORD_MAIN → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_SAFEHOUSE}     { 
    fprintf(token_file, "Line %d: KEYWORD_CLASS → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_NRO}           { 
    fprintf(token_file, "Line %d: KEYWORD_RETURN → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_ORDER_HAI}     { 
    fprintf(token_file, "Line %d: KEYWORD_IF → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_DOOSRA_ORDER}  { 
    fprintf(token_file, "Line %d: KEYWORD_ELSE_IF → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_WARNA_VIGO}    { 
    fprintf(token_file, "Line %d: KEYWORD_ELSE → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_LONG_MARCH}    { 
    fprintf(token_file, "Line %d: KEYWORD_FOR → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_JAB_TAK_MISSING} { 
    fprintf(token_file, "Line %d: KEYWORD_WHILE → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_DEAL_HO_GAI}   { 
    fprintf(token_file, "Line %d: KEYWORD_BREAK → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_CHALTAY_RAHO}  { 
    fprintf(token_file, "Line %d: KEYWORD_CONTINUE → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_FARMAAN}       { 
    fprintf(token_file, "Line %d: KEYWORD_PRINT → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_TAFTISH}       { 
    fprintf(token_file, "Line %d: KEYWORD_INPUT → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_QAIDI_NO}      { 
    fprintf(token_file, "Line %d: KEYWORD_INT → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_BAYANIA}       { 
    fprintf(token_file, "Line %d: KEYWORD_STRING → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_FLOAT_SARKAR}  { 
    fprintf(token_file, "Line %d: KEYWORD_FLOAT → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_ISHARA}        { 
    fprintf(token_file, "Line %d: KEYWORD_CHAR → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_NAMALOOM}      { 
    fprintf(token_file, "Line %d: KEYWORD_VOID → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_AIN}           { 
    fprintf(token_file, "Line %d: KEYWORD_CONST → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_NEUTRAL}       { 
    fprintf(token_file, "Line %d: KEYWORD_TRUE → %s\n", line_num, yytext);
    token_count++;
}
{KEYWORD_JANWAR}        { 
    fprintf(token_file, "Line %d: KEYWORD_FALSE → %s\n", line_num, yytext);
    token_count++;
}

{OP_ASSIGN}     { 
    fprintf(token_file, "Line %d: OPERATOR_ASSIGN → %s\n", line_num, yytext);
    token_count++;
}
{OP_EQUAL}      { 
    fprintf(token_file, "Line %d: OPERATOR_EQUAL → %s\n", line_num, yytext);
    token_count++;
}
{OP_GREATER}    { 
    fprintf(token_file, "Line %d: OPERATOR_GREATER → %s\n", line_num, yytext);
    token_count++;
}
{OP_LESS}       { 
    fprintf(token_file, "Line %d: OPERATOR_LESS → %s\n", line_num, yytext);
    token_count++;
}
{OP_ADD}        { 
    fprintf(token_file, "Line %d: OPERATOR_ADD → %s\n", line_num, yytext);
    token_count++;
}
{OP_SUB}        { 
    fprintf(token_file, "Line %d: OPERATOR_SUB → %s\n", line_num, yytext);
    token_count++;
}
{OP_MUL}        { 
    fprintf(token_file, "Line %d: OPERATOR_MUL → %s\n", line_num, yytext);
    token_count++;
}
{OP_OUTPUT}     { 
    fprintf(token_file, "Line %d: OPERATOR_OUTPUT → %s\n", line_num, yytext);
    token_count++;
}
{OP_INPUT}      { 
    fprintf(token_file, "Line %d: OPERATOR_INPUT → %s\n", line_num, yytext);
    token_count++;
}
{OP_INCREMENT}  { 
    fprintf(token_file, "Line %d: OPERATOR_INCREMENT → %s\n", line_num, yytext);
    token_count++;
}
{OP_DECREMENT}  { 
    fprintf(token_file, "Line %d: OPERATOR_DECREMENT → %s\n", line_num, yytext);
    token_count++;
}

{PUNCT_BLOCK_START}     { 
    fprintf(token_file, "Line %d: PUNCTUATION_BLOCK_START → %s\n", line_num, yytext);
    token_count++;
}
{PUNCT_BLOCK_END}       { 
    fprintf(token_file, "Line %d: PUNCTUATION_BLOCK_END → %s\n", line_num, yytext);
    token_count++;
}
{PUNCT_EXPR_START}      { 
    fprintf(token_file, "Line %d: PUNCTUATION_EXPR_START → %s\n", line_num, yytext);
    token_count++;
}
{PUNCT_EXPR_END}        { 
    fprintf(token_file, "Line %d: PUNCTUATION_EXPR_END → %s\n", line_num, yytext);
    token_count++;
}
{PUNCT_TERMINATOR}      { 
    fprintf(token_file, "Line %d: PUNCTUATION_TERMINATOR → %s\n", line_num, yytext);
    token_count++;
}
{PUNCT_COMMA}           { 
    fprintf(token_file, "Line %d: PUNCTUATION_COMMA → %s\n", line_num, yytext);
    token_count++;
}

{EXPONENTIAL}   { 
    fprintf(token_file, "Line %d: NUMBER_EXPONENTIAL → %s\n", line_num, yytext);
    token_count++;
}
{FLOAT}         { 
    fprintf(token_file, "Line %d: NUMBER_FLOAT → %s\n", line_num, yytext);
    token_count++;
}
{INTEGER}       { 
    fprintf(token_file, "Line %d: NUMBER_INTEGER → %s\n", line_num, yytext);
    token_count++;
}
{IDENTIFIER}    { 
    fprintf(token_file, "Line %d: IDENTIFIER → %s\n", line_num, yytext);
    token_count++;
}
{STRING}        { 
    fprintf(token_file, "Line %d: STRING_LITERAL → %s\n", line_num, yytext);
    token_count++;
}
{CHAR}          { 
    fprintf(token_file, "Line %d: CHAR_LITERAL → %s\n", line_num, yytext);
    token_count++;
}

{WHITESPACE}    { /* Ignore whitespace */ }
{NEWLINE}       { line_num++; }

.               { 
    fprintf(error_file, "Line %d: ERROR → %s (invalid token)\n", line_num, yytext);
    error_count++;
}

%%

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        printf("Example: %s test_program.vigo\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("❌ Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    token_file = fopen("tokens.txt", "w");
    error_file = fopen("errors.txt", "w");

    if (!token_file || !error_file) {
        printf("❌ Error: Cannot create output files\n");
        return 1;
    }

    fprintf(token_file, "========================================\n");
    fprintf(token_file, "    VigoLang Lexical Analyzer Output    \n");
    fprintf(token_file, "========================================\n\n");

    yyin = input_file;
    yylex();

    fprintf(token_file, "\n========================================\n");
    fprintf(token_file, "Total Tokens: %d\n", token_count);
    fprintf(token_file, "Total Lines: %d\n", line_num - 1);
    fprintf(token_file, "========================================\n");

    fclose(input_file);
    fclose(token_file);
    fclose(error_file);

    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║   VigoLang Lexical Analyzer Results   ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    printf("✓ Tokenization complete!\n");
    printf("✓ Total tokens found: %d\n", token_count);
    printf("✓ Total lines processed: %d\n", line_num - 1);
    printf("✓ Tokens written to: tokens.txt\n");
    
    if (error_count > 0) {
        printf("✗ %d errors found. Check errors.txt\n", error_count);
    } else {
        printf("✓ No errors found!\n");
    }
    printf("\n");

    return 0;
}
