%{
#include <stdio.h>
#include <string.h>

/* Global variables for tracking */
int line_num = 1;
int error_count = 0;
int token_count = 0;

/* File pointers for output */
FILE *token_file;
FILE *error_file;

/* Flex needs this to read from a file */
extern FILE *yyin;
%}

/* Tell Flex not to look for the yywrap() function.
  This means we are only scanning one file.
*/
%option noyywrap

/* SECTION 1: REGULAR EXPRESSION DEFINITIONS
*/

DIGIT [0-9]
LETTER [a-zA-Z]
SIGN [+\-]

/* Token Definitions */
IDENTIFIER \^{LETTER}({LETTER}|{DIGIT}|_)*
EXPONENTIAL {SIGN}?{DIGIT}+(\.{DIGIT}+)?[eE]{SIGN}?{DIGIT}+
FLOAT {SIGN}?{DIGIT}+\.{DIGIT}+
INTEGER {SIGN}?{DIGIT}+
STRING \"[^\"]*\"
CHAR \'[^\']\'
WHITESPACE [ \t]+
NEWLINE \n

/* Keywords (20 total) */
KEYWORD_GHQ "ghq"
KEYWORD_SAFEHOUSE "safehouse"
KEYWORD_NRO "nro"
KEYWORD_ORDER_HAI "order_hai"
KEYWORD_DOOSRA_ORDER "doosra_order"
KEYWORD_WARNA_VIGO "warna_vigo"
KEYWORD_LONG_MARCH "long_march"
KEYWORD_JAB_TAK_MISSING "jab_tak_missing"
KEYWORD_DEAL_HO_GAI "deal_ho_gai"
KEYWORD_CHALTAY_RAHO "chaltay_raho"
KEYWORD_FARMAAN "farmaan"
KEYWORD_TAFTISH "taftish"
KEYWORD_QAIDI_NO "qaidi_no"
KEYWORD_BAYANIA "bayania"
KEYWORD_FLOAT_SARKAR "float_sarkar"
KEYWORD_ISHARA "ishara"
KEYWORD_NAMALOOM "namaloom"
KEYWORD_AIN "ain"
KEYWORD_NEUTRAL "neutral"
KEYWORD_JANWAR "janwar"

/* Operators */
OP_ADD "+:"
OP_SUB "-:"
OP_MUL "*:"
OP_ASSIGN ":="
OP_EQUAL "=?"
OP_GREATER ">?"
OP_LESS "<?"
OP_OUTPUT "<<"
OP_INPUT ">>"

/* Punctuation */
PUNCT_TERMINATOR "@"
PUNCT_BLOCK_START "{{"
PUNCT_BLOCK_END "}}"
PUNCT_EXPR_START "[["
PUNCT_EXPR_END "]]"
PUNCT_COMMA ","

COMMENT "#*"([^*]|\*+[^*#])*"*#"
SINGLE_COMMENT "###".*

%%

{COMMENT}         { /* Ignore multi-line comments */ }
{SINGLE_COMMENT}  { /* Ignore single-line comments */ }
{WHITESPACE}      { /* Ignore whitespace */ }
{NEWLINE}         { line_num++; /* Increment line count */ }

{KEYWORD_GHQ}           { fprintf(token_file, "Line %d: KEYWORD_MAIN -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_SAFEHOUSE}     { fprintf(token_file, "Line %d: KEYWORD_CLASS -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_NRO}           { fprintf(token_file, "Line %d: KEYWORD_RETURN -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_ORDER_HAI}     { fprintf(token_file, "Line %d: KEYWORD_IF -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_DOOSRA_ORDER}  { fprintf(token_file, "Line %d: KEYWORD_ELSE_IF -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_WARNA_VIGO}    { fprintf(token_file, "Line %d: KEYWORD_ELSE -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_LONG_MARCH}    { fprintf(token_file, "Line %d: KEYWORD_FOR -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_JAB_TAK_MISSING} { fprintf(token_file, "Line %d: KEYWORD_WHILE -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_DEAL_HO_GAI}   { fprintf(token_file, "Line %d: KEYWORD_BREAK -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_CHALTAY_RAHO}  { fprintf(token_file, "Line %d: KEYWORD_CONTINUE -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_FARMAAN}       { fprintf(token_file, "Line %d: KEYWORD_PRINT -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_TAFTISH}       { fprintf(token_file, "Line %d: KEYWORD_INPUT -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_QAIDI_NO}      { fprintf(token_file, "Line %d: KEYWORD_INT -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_BAYANIA}       { fprintf(token_file, "Line %d: KEYWORD_STRING -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_FLOAT_SARKAR}  { fprintf(token_file, "Line %d: KEYWORD_FLOAT -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_ISHARA}        { fprintf(token_file, "Line %d: KEYWORD_CHAR -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_NAMALOOM}      { fprintf(token_file, "Line %d: KEYWORD_VOID -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_AIN}           { fprintf(token_file, "Line %d: KEYWORD_CONST -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_NEUTRAL}       { fprintf(token_file, "Line %d: KEYWORD_TRUE -> %s\n", line_num, yytext); token_count++; }
{KEYWORD_JANWAR}        { fprintf(token_file, "Line %d: KEYWORD_FALSE -> %s\n", line_num, yytext); token_count++; }

{OP_ASSIGN}       { fprintf(token_file, "Line %d: OPERATOR_ASSIGN -> %s\n", line_num, yytext); token_count++; }
{OP_EQUAL}        { fprintf(token_file, "Line %d: OPERATOR_EQUAL -> %s\n", line_num, yytext); token_count++; }
{OP_GREATER}      { fprintf(token_file, "Line %d: OPERATOR_GREATER -> %s\n", line_num, yytext); token_count++; }
{OP_LESS}         { fprintf(token_file, "Line %d: OPERATOR_LESS -> %s\n", line_num, yytext); token_count++; }
{OP_ADD}          { fprintf(token_file, "Line %d: OPERATOR_ADD -> %s\n", line_num, yytext); token_count++; }
{OP_SUB}          { fprintf(token_file, "Line %d: OPERATOR_SUB -> %s\n", line_num, yytext); token_count++; }
{OP_MUL}          { fprintf(token_file, "Line %d: OPERATOR_MUL -> %s\n", line_num, yytext); token_count++; }
{OP_OUTPUT}       { fprintf(token_file, "Line %d: OPERATOR_OUTPUT -> %s\n", line_num, yytext); token_count++; }
{OP_INPUT}        { fprintf(token_file, "Line %d: OPERATOR_INPUT -> %s\n", line_num, yytext); token_count++; }

{PUNCT_BLOCK_START} { fprintf(token_file, "Line %d: PUNCTUATION_BLOCK_START -> %s\n", line_num, yytext); token_count++; }
{PUNCT_BLOCK_END}   { fprintf(token_file, "Line %d: PUNCTUATION_BLOCK_END -> %s\n", line_num, yytext); token_count++; }
{PUNCT_EXPR_START}  { fprintf(token_file, "Line %d: PUNCTUATION_EXPR_START -> %s\n", line_num, yytext); token_count++; }
{PUNCT_EXPR_END}    { fprintf(token_file, "Line %d: PUNCTUATION_EXPR_END -> %s\n", line_num, yytext); token_count++; }
{PUNCT_TERMINATOR}  { fprintf(token_file, "Line %d: PUNCTUATION_TERMINATOR -> %s\n", line_num, yytext); token_count++; }
{PUNCT_COMMA}       { fprintf(token_file, "Line %d: PUNCTUATION_COMMA -> %s\n", line_num, yytext); token_count++; }

{EXPONENTIAL}     { fprintf(token_file, "Line %d: NUMBER_EXPONENTIAL -> %s\n", line_num, yytext); token_count++; }
{FLOAT}           { fprintf(token_file, "Line %d: NUMBER_FLOAT -> %s\n", line_num, yytext); token_count++; }
{INTEGER}         { fprintf(token_file, "Line %d: NUMBER_INTEGER -> %s\n", line_num, yytext); token_count++; }
{IDENTIFIER}      { fprintf(token_file, "Line %d: IDENTIFIER -> %s\n", line_num, yytext); token_count++; }

{STRING}          { fprintf(token_file, "Line %d: STRING_LITERAL -> %s\n", line_num, yytext); token_count++; }
{CHAR}            { fprintf(token_file, "Line %d: CHAR_LITERAL -> %s\n", line_num, yytext); token_count++; }

.                 { fprintf(error_file, "Line %d: ERROR -> %s (invalid token)\n", line_num, yytext); error_count++; }

%%
/* SECTION 3: C CODE (main function)
*/

int main(int argc, char **argv) {
    // Check if a filename was provided
    if (argc < 2) {
        printf("\n");
        printf("╔════════════════════════════════════════╗\n");
        printf("║         VigoLang Scanner v1.0          ║\n");
        printf("╚════════════════════════════════════════╝\n\n");
        printf("Usage: %s <input_file>\n", argv[0]);
        printf("Example: %s test_program.vigo\n\n", argv[0]);
        return 1;
    }

    // Open the input file from the command line argument
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("\nError: Cannot open file '%s'\n", argv[1]);
        printf("Please check if the file exists and is readable.\n\n");
        return 1;
    }

    // Open output files
    token_file = fopen("tokens.txt", "w");
    error_file = fopen("errors.txt", "w");

    if (!token_file || !error_file) {
        printf("\nError: Cannot create output files\n");
        printf("Check write permissions for tokens.txt and errors.txt\n\n");
        fclose(input_file);
        return 1;
    }

    // Write header to token file
    fprintf(token_file, "════════════════════════════════════════════════════════\n");
    fprintf(token_file, "           VigoLang Lexical Analyzer Output             \n");
    fprintf(token_file, "           Author: Muhammad Ahmad                       \n");
    fprintf(token_file, "           Reg: L1F22BSCS0634                           \n");
    fprintf(token_file, "           Input File: %-30s\n", argv[1]);
    fprintf(token_file, "════════════════════════════════════════════════════════\n\n");

    // Write header to error file
    fprintf(error_file, "════════════════════════════════════════════════════════\n");
    fprintf(error_file, "           VigoLang Lexical Error Report                \n");
    fprintf(error_file, "           Input File: %-30s\n", argv[1]);
    fprintf(error_file, "════════════════════════════════════════════════════════\n\n");

    // Point Flex's input (yyin) to your file
    yyin = input_file;

    // Run the lexical analyzer
    printf("\nScanning '%s'...\n", argv[1]);
    yylex();

    // Write footer to token file
    fprintf(token_file, "\n════════════════════════════════════════════════════════\n");
    fprintf(token_file, "                   Scanning Statistics                   \n");
    fprintf(token_file, "════════════════════════════════════════════════════════\n");
    fprintf(token_file, "Total Lines Processed:    %d\n", line_num - 1);
    fprintf(token_file, "Total Tokens Recognized:  %d\n", token_count);
    fprintf(token_file, "Total Errors Found:       %d\n", error_count);
    fprintf(token_file, "════════════════════════════════════════════════════════\n");

    // Write footer to error file
    if (error_count > 0) {
        fprintf(error_file, "\n════════════════════════════════════════════════════════\n");
        fprintf(error_file, "Total Errors: %d\n", error_count);
        fprintf(error_file, "════════════════════════════════════════════════════════\n");
    } else {
        fprintf(error_file, "No lexical errors found!\n");
    }

    // Clean up and close all file pointers
    fclose(input_file);
    fclose(token_file);
    fclose(error_file);

    // Print comprehensive summary to console
    printf("\n");
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║         VigoLang Lexical Analyzer Results              ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");
    printf("Input File:         %s\n", argv[1]);
    printf("Lines Processed:    %d\n", line_num - 1);
    printf("Tokens Found:       %d\n", token_count);
    
    if (error_count > 0) {
        printf("Errors Found:       %d\n", error_count);
    } else {
        printf("Errors Found:       0\n");
    }
    
    printf("\nOutput Files:\n");
    printf("   ├─ tokens.txt      (Complete token list)\n");
    printf("   └─ errors.txt      (Error log)\n\n");
    
    if (error_count == 0) {
        printf("Scanning completed successfully!\n");
    } else {
        printf("Scanning completed with errors. Check errors.txt\n");
    }
    
    printf("════════════════════════════════════════════════════════\n\n");

    return 0; // Success
}
