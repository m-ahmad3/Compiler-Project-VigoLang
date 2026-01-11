%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* External variables from lexer */
extern int yylex();
extern int line_num;
extern char *yytext;
extern FILE *yyin;

/* Token value storage from scanner */
extern char current_id[256];
extern char current_type[32];
extern char current_value[256];

/* Error handling function */
void yyerror(const char *s);

/* Success flag */
int parse_success = 1;

/* Helper variables for storing parsed names */
char saved_id[256] = "";
char saved_type[32] = "";
char saved_value[256] = "";
%}

/* Token declarations - matching Phase 1 scanner */

/* Keywords (20 total) */
%token KEYWORD_GHQ           /* ghq - main function */
%token KEYWORD_SAFEHOUSE     /* safehouse - class */
%token KEYWORD_NRO           /* nro - return */
%token KEYWORD_ORDER_HAI     /* order_hai - if */
%token KEYWORD_DOOSRA_ORDER  /* doosra_order - else if */
%token KEYWORD_WARNA_VIGO    /* warna_vigo - else */
%token KEYWORD_LONG_MARCH    /* long_march - for loop */
%token KEYWORD_JAB_TAK_MISSING /* jab_tak_missing - while loop */
%token KEYWORD_DEAL_HO_GAI   /* deal_ho_gai - break */
%token KEYWORD_CHALTAY_RAHO  /* chaltay_raho - continue */
%token KEYWORD_FARMAAN       /* farmaan - print */
%token KEYWORD_TAFTISH       /* taftish - input */
%token KEYWORD_QAIDI_NO      /* qaidi_no - int type */
%token KEYWORD_BAYANIA       /* bayania - string type */
%token KEYWORD_FLOAT_SARKAR  /* float_sarkar - float type */
%token KEYWORD_ISHARA        /* ishara - char type */
%token KEYWORD_NAMALOOM      /* namaloom - void type */
%token KEYWORD_AIN           /* ain - const modifier */
%token KEYWORD_NEUTRAL       /* neutral - true */
%token KEYWORD_JANWAR        /* janwar - false */

/* Operators */
%token OP_ASSIGN    /* := */
%token OP_ADD       /* +: */
%token OP_SUB       /* -: */
%token OP_MUL       /* *: */
%token OP_EQUAL     /* =? */
%token OP_GREATER   /* >? */
%token OP_LESS      /* <? */
%token OP_OUTPUT    /* << */
%token OP_INPUT     /* >> */

/* Punctuation */
%token PUNCT_TERMINATOR     /* @ */
%token PUNCT_BLOCK_START    /* {{ */
%token PUNCT_BLOCK_END      /* }} */
%token PUNCT_EXPR_START     /* [[ */
%token PUNCT_EXPR_END       /* ]] */
%token PUNCT_COMMA          /* , */

/* Literals and Identifiers */
%token IDENTIFIER
%token NUMBER_INTEGER
%token NUMBER_FLOAT
%token NUMBER_EXPONENTIAL
%token STRING_LITERAL
%token CHAR_LITERAL

/* Define operator precedence (lowest to highest) */
%left OP_ADD OP_SUB
%left OP_MUL

%%

/* ============================================
   GRAMMAR RULES FOR VIGOLANG
   ============================================ */

/* Program Structure - Allows declarations before and/or after main function */
program
    : global_list
        { printf("   ✓ Program structure validated\n"); }
    ;

global_list
    : global_item global_list
    | global_item
    ;

global_item
    : main_function
    | declaration
    | global_statement
    ;

main_function
    : KEYWORD_GHQ PUNCT_EXPR_START PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END
        { printf("   ✓ Line %d: Main function (ghq) parsed successfully\n", line_num); }
    ;

/* Unused - kept for reference
declaration_list
    : declaration declaration_list
    | declaration
    ;
*/

/* Global-level statements (like farmaan at top level) */
global_statement
    : output_statement
    | input_statement
    ;

declaration
    : variable_declaration
    | function_declaration
    | class_declaration
    | constant_declaration
    ;

/* Variable Declarations */
variable_declaration
    : type IDENTIFIER PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Variable declaration: %s %s\n", line_num, saved_type, current_id); }
    | type IDENTIFIER OP_ASSIGN expression PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Variable declaration: %s %s := %s\n", line_num, saved_type, saved_id, current_value); }
    ;

constant_declaration
    : KEYWORD_AIN type IDENTIFIER OP_ASSIGN expression PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Constant (ain): %s %s := %s\n", line_num, saved_type, saved_id, current_value); }
    ;

/* Type Definitions */
type
    : KEYWORD_QAIDI_NO      { strcpy(saved_type, "qaidi_no"); }
    | KEYWORD_FLOAT_SARKAR  { strcpy(saved_type, "float_sarkar"); }
    | KEYWORD_BAYANIA       { strcpy(saved_type, "bayania"); }
    | KEYWORD_ISHARA        { strcpy(saved_type, "ishara"); }
    | KEYWORD_NAMALOOM      { strcpy(saved_type, "namaloom"); }
    ;

/* Function Declaration */
function_declaration
    : type IDENTIFIER PUNCT_EXPR_START parameter_list PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END
        { printf("   ✓ Line %d: Function: %s %s[[...]]\n", line_num, saved_type, saved_id); }
    | type IDENTIFIER PUNCT_EXPR_START PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END
        { printf("   ✓ Line %d: Function: %s %s[[]]\n", line_num, saved_type, saved_id); }
    ;

parameter_list
    : parameter
    | parameter PUNCT_COMMA parameter_list
    ;

parameter
    : type IDENTIFIER
        { printf("      └─ Parameter: %s %s\n", saved_type, current_id); }
    ;

/* Class Declaration */
class_declaration
    : KEYWORD_SAFEHOUSE IDENTIFIER PUNCT_BLOCK_START member_list PUNCT_BLOCK_END PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Class (safehouse): %s\n", line_num, saved_id); }
    ;

member_list
    : member member_list
    | /* empty */
    ;

member
    : variable_declaration
    ;

/* Statement List */
statement_list
    : statement statement_list
    | /* empty */
    ;

/* Statement Types */
statement
    : variable_declaration
    | assignment_statement
    | if_statement
    | for_loop
    | while_loop
    | output_statement
    | input_statement
    | return_statement
    | break_statement
    | continue_statement
    | function_call_statement
    | error PUNCT_TERMINATOR
        { yyerrok; parse_success = 0; }
    ;

/* Assignment Statement */
assignment_statement
    : IDENTIFIER OP_ASSIGN expression PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Assignment: %s := %s\n", line_num, saved_id, current_value); }
    ;

/* If Statement (order_hai) */
if_statement
    : KEYWORD_ORDER_HAI PUNCT_EXPR_START condition PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END else_if_part else_part
        { printf("   ✓ Line %d: Conditional statement (order_hai) parsed\n", line_num); }
    ;

else_if_part
    : KEYWORD_DOOSRA_ORDER PUNCT_EXPR_START condition PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END else_if_part
    | /* empty */
    ;

else_part
    : KEYWORD_WARNA_VIGO PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END
    | /* empty */
    ;

/* For Loop (long_march) */
for_loop
    : KEYWORD_LONG_MARCH PUNCT_EXPR_START for_init condition PUNCT_TERMINATOR for_update PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END
        { printf("   ✓ Line %d: For loop (long_march) parsed\n", line_num); }
    ;

for_init
    : IDENTIFIER OP_ASSIGN expression PUNCT_TERMINATOR
    ;

for_update
    : IDENTIFIER OP_ASSIGN expression
    ;

/* While Loop (jab_tak_missing) */
while_loop
    : KEYWORD_JAB_TAK_MISSING PUNCT_EXPR_START condition PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END
        { printf("   ✓ Line %d: While loop (jab_tak_missing) parsed\n", line_num); }
    ;

/* Output Statement (farmaan) */
output_statement
    : KEYWORD_FARMAAN OP_OUTPUT expression PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Output (farmaan): << %s\n", line_num, current_value[0] ? current_value : current_id); }
    ;

/* Input Statement (taftish) */
input_statement
    : KEYWORD_TAFTISH OP_INPUT IDENTIFIER PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Input (taftish): >> %s\n", line_num, current_id); }
    ;

/* Return Statement (nro) */
return_statement
    : KEYWORD_NRO expression PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Return (nro): %s\n", line_num, current_value[0] ? current_value : current_id); }
    | KEYWORD_NRO PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Return (nro): void\n", line_num); }
    ;

/* Break Statement (deal_ho_gai) */
break_statement
    : KEYWORD_DEAL_HO_GAI PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Break statement (deal_ho_gai) parsed\n", line_num); }
    ;

/* Continue Statement (chaltay_raho) */
continue_statement
    : KEYWORD_CHALTAY_RAHO PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Continue statement (chaltay_raho) parsed\n", line_num); }
    ;

/* Function Call */
function_call_statement
    : IDENTIFIER PUNCT_EXPR_START argument_list PUNCT_EXPR_END PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Function call: %s[[...]]\n", line_num, saved_id); }
    | IDENTIFIER PUNCT_EXPR_START PUNCT_EXPR_END PUNCT_TERMINATOR
        { printf("   ✓ Line %d: Function call: %s[[]]\n", line_num, saved_id); }
    ;

argument_list
    : expression
    | expression PUNCT_COMMA argument_list
    ;

/* Condition (for if/while) */
condition
    : expression relational_operator expression
    ;

relational_operator
    : OP_EQUAL      { /* =? */ }
    | OP_GREATER    { /* >? */ }
    | OP_LESS       { /* <? */ }
    ;

/* Expression Grammar (handles operator precedence) */
expression
    : expression OP_ADD term
    | expression OP_SUB term
    | term
    ;

term
    : term OP_MUL factor
    | factor
    ;

factor
    : IDENTIFIER
    | NUMBER_INTEGER
    | NUMBER_FLOAT
    | NUMBER_EXPONENTIAL
    | STRING_LITERAL
    | CHAR_LITERAL
    | KEYWORD_NEUTRAL   /* true */
    | KEYWORD_JANWAR    /* false */
    ;

%%

/* ============================================
   C CODE SECTION
   ============================================ */

void yyerror(const char *s) {
    fprintf(stderr, "\n");
    fprintf(stderr, "╔════════════════════════════════════════════════════════╗\n");
    fprintf(stderr, "║              SYNTAX ERROR DETECTED                     ║\n");
    fprintf(stderr, "╚════════════════════════════════════════════════════════╝\n");
    fprintf(stderr, "  Line Number:    %d\n", line_num);
    fprintf(stderr, "  Error Type:     %s\n", s);
    fprintf(stderr, "  Found Token:    '%s'\n", yytext);
    fprintf(stderr, "════════════════════════════════════════════════════════\n\n");
    parse_success = 0;
}

int main(int argc, char **argv) {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║         VigoLang Syntax Analyzer v2.0                  ║\n");
    printf("║         Phase 2: Parsing                               ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");

    if (argc < 2) {
        printf("Usage: %s <input_file.vigo>\n", argv[0]);
        printf("Example: %s valid_program.vigo\n\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error: Cannot open file '%s'\n", argv[1]);
        return 1;
    }

    printf("Parsing file: %s\n", argv[1]);
    printf("════════════════════════════════════════════════════════\n\n");

    yyin = input_file;
    
    int result = yyparse();
    
    fclose(input_file);

    printf("\n════════════════════════════════════════════════════════\n");
    
    if (result == 0 && parse_success) {
        printf("╔════════════════════════════════════════════════════════╗\n");
        printf("║         SYNTAX ANALYSIS SUCCESSFUL!                    ║\n");
        printf("║         No syntax errors detected.                     ║\n");
        printf("╚════════════════════════════════════════════════════════╝\n");
    } else {
        printf("╔════════════════════════════════════════════════════════╗\n");
        printf("║         SYNTAX ANALYSIS FAILED!                        ║\n");
        printf("║         Please fix the errors above.                   ║\n");
        printf("╚════════════════════════════════════════════════════════╝\n");
    }
    printf("\n");

    return (result == 0 && parse_success) ? 0 : 1;
}
