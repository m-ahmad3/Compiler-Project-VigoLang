/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20240109

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* External variables from lexer */
extern int yylex();
extern int line_num;
extern char *yytext;
extern FILE *yyin;

/* Error handling function */
void yyerror(const char *s);

/* Success flag */
int parse_success = 1;
#line 40 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define KEYWORD_GHQ 257
#define KEYWORD_SAFEHOUSE 258
#define KEYWORD_NRO 259
#define KEYWORD_ORDER_HAI 260
#define KEYWORD_DOOSRA_ORDER 261
#define KEYWORD_WARNA_VIGO 262
#define KEYWORD_LONG_MARCH 263
#define KEYWORD_JAB_TAK_MISSING 264
#define KEYWORD_DEAL_HO_GAI 265
#define KEYWORD_CHALTAY_RAHO 266
#define KEYWORD_FARMAAN 267
#define KEYWORD_TAFTISH 268
#define KEYWORD_QAIDI_NO 269
#define KEYWORD_BAYANIA 270
#define KEYWORD_FLOAT_SARKAR 271
#define KEYWORD_ISHARA 272
#define KEYWORD_NAMALOOM 273
#define KEYWORD_AIN 274
#define KEYWORD_NEUTRAL 275
#define KEYWORD_JANWAR 276
#define OP_ASSIGN 277
#define OP_ADD 278
#define OP_SUB 279
#define OP_MUL 280
#define OP_EQUAL 281
#define OP_GREATER 282
#define OP_LESS 283
#define OP_OUTPUT 284
#define OP_INPUT 285
#define PUNCT_TERMINATOR 286
#define PUNCT_BLOCK_START 287
#define PUNCT_BLOCK_END 288
#define PUNCT_EXPR_START 289
#define PUNCT_EXPR_END 290
#define PUNCT_COMMA 291
#define IDENTIFIER 292
#define NUMBER_INTEGER 293
#define NUMBER_FLOAT 294
#define NUMBER_EXPONENTIAL 295
#define STRING_LITERAL 296
#define CHAR_LITERAL 297
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    2,    1,    1,    4,    4,    4,    4,    5,
    5,    8,    9,    9,    9,    9,    9,    6,    6,   11,
   11,   12,    7,   13,   13,   14,    3,    3,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   15,
   16,   17,   27,   27,   28,   28,   18,   29,   30,   19,
   20,   21,   22,   22,   23,   24,   25,   25,   31,   31,
   26,   32,   32,   32,   10,   10,   10,   33,   33,   34,
   34,   34,   34,   34,   34,   34,   34,
};
static const YYINT yylen[] = {                            2,
    2,    1,    6,    2,    1,    1,    1,    1,    1,    3,
    5,    6,    1,    1,    1,    1,    1,    8,    7,    1,
    3,    2,    6,    2,    0,    1,    2,    0,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    2,
    4,    9,    8,    0,    4,    0,   10,    4,    3,    7,
    4,    4,    3,    2,    2,    2,    5,    4,    1,    3,
    3,    1,    1,    1,    3,    3,    1,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,   13,   15,   14,   16,   17,    0,    0,    0,
    2,    0,    6,    7,    8,    9,    0,    0,    0,    0,
    1,    4,    0,    0,    0,    0,    0,   10,    0,    0,
   26,    0,    0,    0,    0,   76,   77,   70,   71,   72,
   73,   74,   75,    0,    0,   69,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   29,    0,   30,   31,   32,   33,   34,   35,   36,
   37,   38,   39,    0,    0,   24,    0,    0,    0,   11,
    0,    0,   22,    0,    0,   40,   54,    0,    0,    0,
    0,   55,   56,    0,    0,    0,    0,    3,   27,   23,
   12,    0,    0,   68,    0,    0,   21,   53,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   19,
    0,   62,   63,   64,    0,    0,    0,    0,    0,   51,
   52,   41,   58,    0,    0,   18,    0,    0,    0,    0,
    0,   60,   57,    0,   48,    0,    0,    0,    0,    0,
    0,   50,    0,    0,    0,    0,    0,    0,   42,    0,
    0,    0,   47,    0,    0,    0,   45,    0,    0,   43,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  257,  258,  269,  270,  271,  272,  273,  274,  299,  300,
  301,  303,  304,  305,  306,  307,  308,  289,  292,  308,
  301,  300,  292,  290,  287,  292,  277,  286,  289,  287,
  304,  308,  312,  313,  277,  275,  276,  292,  293,  294,
  295,  296,  297,  309,  332,  333,  290,  308,  310,  311,
  256,  259,  260,  263,  264,  265,  266,  267,  268,  292,
  302,  304,  314,  315,  316,  317,  318,  319,  320,  321,
  322,  323,  324,  292,  288,  312,  309,  278,  279,  286,
  280,  287,  292,  290,  291,  286,  286,  309,  289,  289,
  289,  286,  286,  284,  285,  277,  289,  288,  302,  286,
  286,  332,  332,  333,  302,  287,  310,  286,  309,  325,
  292,  328,  325,  309,  292,  309,  290,  309,  330,  288,
  302,  281,  282,  283,  331,  290,  277,  325,  290,  286,
  286,  286,  286,  291,  290,  288,  309,  287,  309,  286,
  287,  330,  286,  302,  286,  292,  329,  302,  288,  277,
  290,  288,  261,  326,  309,  287,  289,  262,  327,  302,
  325,  287,  288,  290,  302,  287,  288,  302,  288,  326,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          9,
   10,   11,   61,   12,   62,   14,   15,   16,   32,  109,
   49,   50,   33,   34,   63,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   73,  110,  154,  159,  112,  147,
  119,  125,   45,   46,
};
static const YYINT yysindex[] = {                      -238,
 -277, -275,    0,    0,    0,    0,    0,  -44,    0, -235,
    0,  -93,    0,    0,    0,    0, -263, -266, -208, -227,
    0,    0, -211, -200,  -44, -183, -234,    0, -100, -109,
    0, -199, -191,  -44, -234,    0,    0,    0,    0,    0,
    0,    0,    0, -272, -181,    0, -171, -189, -186, -185,
 -168, -184, -170, -150, -145, -140, -138, -132, -119, -273,
 -114,    0, -109,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -259, -111,    0, -205, -234, -234,    0,
 -234, -109,    0, -142,  -44,    0,    0, -196, -234,  -99,
 -234,    0,    0, -234,  -85, -234, -108,    0,    0,    0,
    0, -181, -181,    0,  -82, -109,    0,    0, -141,  -77,
  -69, -234,  -73, -190,  -68, -164,  -66, -268,  -60,    0,
  -57,    0,    0,    0, -234,  -65, -234,  -54,  -53,    0,
    0,    0,    0, -234,  -51,    0, -240, -109, -143,  -71,
 -109,    0,    0,  -55,    0,  -41,  -52,  -49,  -24, -234,
  -47,    0,  -48,  -20, -240, -109, -234,  -43,    0,  -45,
  -42, -109,    0,  -40,  -39, -109,    0,  -38,  -24,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -12,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -37,    0,    0,    0,    0,  -36,
    0,    0,    0,  -37,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -87,    0,    0,    0,    0,  -35,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -36,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -81,  -67,    0,    0,  -36,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -34,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -222,  -36,    0,    0,
  -36,    0,    0,    0,    0,    0,    0,    0, -216,    0,
    0,    0,    0, -139,  -33,  -36,    0,    0,    0,    0,
    0,  -36,    0,    0,    0,  -36,    0,    0, -216,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
  234,  243,  -61,    0,    3,    0,    0,    0,    1,  -27,
  169,    0,  224,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -86,   90,    0,    0,    0,
  126,    0,    6,  180,
};
#define YYTABLESIZE 261
static const YYINT yytable[] = {                         44,
   17,   99,   13,   96,  113,   78,   79,   77,   20,   78,
   79,   18,   17,   80,   13,   97,   19,   27,    1,    2,
  105,    1,  134,   24,   88,  128,   28,   31,   23,   48,
    3,    4,    5,    6,    7,    8,   31,   78,   79,   44,
   36,   37,   44,   44,  121,   44,   44,   44,   44,   44,
   44,   44,   44,   44,   44,   44,   44,   38,   39,   40,
   41,   42,   43,   61,   26,   27,  114,   61,  116,  118,
  161,   44,   78,   79,   28,   44,  144,   29,   25,  148,
  101,   78,   79,  102,  103,   48,   30,   78,   79,  108,
   36,   37,   74,   35,  160,  130,   75,  137,   81,  139,
  165,   87,   83,   84,  168,   85,  118,   38,   39,   40,
   41,   42,   43,   78,   79,   82,   46,   86,   89,   46,
   46,  132,  155,   46,   46,   46,   46,   46,   46,   46,
   46,   46,   46,   46,   78,   79,   78,   79,   90,  122,
  123,  124,  145,   91,  106,   92,   51,   93,   46,   52,
   53,   94,   46,   54,   55,   56,   57,   58,   59,    3,
    4,    5,    6,    7,    2,   95,   36,   37,    3,    4,
    5,    6,    7,   98,  100,    3,    4,    5,    6,    7,
    8,  117,   60,   38,   39,   40,   41,   42,   43,   47,
   67,   67,  111,   67,   67,   67,   65,   65,   67,   65,
   65,   65,   67,   67,   65,  120,  115,  127,   65,   65,
   66,   66,  126,   66,   66,   66,  129,  131,   66,  133,
  146,  138,   66,   66,    3,    4,    5,    6,    7,  135,
  136,  140,  149,  141,  143,  150,  153,  151,  152,  156,
  157,  158,  163,  162,    5,   22,  166,  164,  167,  169,
   25,   28,   21,  107,   20,   59,   49,   76,  170,  142,
  104,
};
static const YYINT yycheck[] = {                         27,
    0,   63,    0,  277,   91,  278,  279,   35,    8,  278,
  279,  289,   12,  286,   12,  289,  292,  277,  257,  258,
   82,  257,  291,  290,   52,  112,  286,   25,  292,   29,
  269,  270,  271,  272,  273,  274,   34,  278,  279,  256,
  275,  276,  259,  260,  106,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  273,  292,  293,  294,
  295,  296,  297,  286,  292,  277,   94,  290,   96,   97,
  157,  288,  278,  279,  286,  292,  138,  289,  287,  141,
  286,  278,  279,   78,   79,   85,  287,  278,  279,  286,
  275,  276,  292,  277,  156,  286,  288,  125,  280,  127,
  162,  286,  292,  290,  166,  291,  134,  292,  293,  294,
  295,  296,  297,  278,  279,  287,  256,  286,  289,  259,
  260,  286,  150,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  278,  279,  278,  279,  289,  281,
  282,  283,  286,  289,  287,  286,  256,  286,  288,  259,
  260,  284,  292,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  258,  285,  275,  276,  269,  270,
  271,  272,  273,  288,  286,  269,  270,  271,  272,  273,
  274,  290,  292,  292,  293,  294,  295,  296,  297,  290,
  278,  279,  292,  281,  282,  283,  278,  279,  286,  281,
  282,  283,  290,  291,  286,  288,  292,  277,  290,  291,
  278,  279,  290,  281,  282,  283,  290,  286,  286,  286,
  292,  287,  290,  291,  269,  270,  271,  272,  273,  290,
  288,  286,  288,  287,  286,  277,  261,  290,  288,  287,
  289,  262,  288,  287,  257,   12,  287,  290,  288,  288,
  288,  288,   10,   85,  290,  290,  290,   34,  169,  134,
   81,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 297
#define YYUNDFTOKEN 334
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","KEYWORD_GHQ","KEYWORD_SAFEHOUSE",
"KEYWORD_NRO","KEYWORD_ORDER_HAI","KEYWORD_DOOSRA_ORDER","KEYWORD_WARNA_VIGO",
"KEYWORD_LONG_MARCH","KEYWORD_JAB_TAK_MISSING","KEYWORD_DEAL_HO_GAI",
"KEYWORD_CHALTAY_RAHO","KEYWORD_FARMAAN","KEYWORD_TAFTISH","KEYWORD_QAIDI_NO",
"KEYWORD_BAYANIA","KEYWORD_FLOAT_SARKAR","KEYWORD_ISHARA","KEYWORD_NAMALOOM",
"KEYWORD_AIN","KEYWORD_NEUTRAL","KEYWORD_JANWAR","OP_ASSIGN","OP_ADD","OP_SUB",
"OP_MUL","OP_EQUAL","OP_GREATER","OP_LESS","OP_OUTPUT","OP_INPUT",
"PUNCT_TERMINATOR","PUNCT_BLOCK_START","PUNCT_BLOCK_END","PUNCT_EXPR_START",
"PUNCT_EXPR_END","PUNCT_COMMA","IDENTIFIER","NUMBER_INTEGER","NUMBER_FLOAT",
"NUMBER_EXPONENTIAL","STRING_LITERAL","CHAR_LITERAL","$accept","program",
"declaration_list","main_function","statement_list","declaration",
"variable_declaration","function_declaration","class_declaration",
"constant_declaration","type","expression","parameter_list","parameter",
"member_list","member","statement","assignment_statement","if_statement",
"for_loop","while_loop","output_statement","input_statement","return_statement",
"break_statement","continue_statement","function_call_statement","condition",
"else_if_part","else_part","for_init","for_update","argument_list",
"relational_operator","term","factor","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : declaration_list main_function",
"program : main_function",
"main_function : KEYWORD_GHQ PUNCT_EXPR_START PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END",
"declaration_list : declaration declaration_list",
"declaration_list : declaration",
"declaration : variable_declaration",
"declaration : function_declaration",
"declaration : class_declaration",
"declaration : constant_declaration",
"variable_declaration : type IDENTIFIER PUNCT_TERMINATOR",
"variable_declaration : type IDENTIFIER OP_ASSIGN expression PUNCT_TERMINATOR",
"constant_declaration : KEYWORD_AIN type IDENTIFIER OP_ASSIGN expression PUNCT_TERMINATOR",
"type : KEYWORD_QAIDI_NO",
"type : KEYWORD_FLOAT_SARKAR",
"type : KEYWORD_BAYANIA",
"type : KEYWORD_ISHARA",
"type : KEYWORD_NAMALOOM",
"function_declaration : type IDENTIFIER PUNCT_EXPR_START parameter_list PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END",
"function_declaration : type IDENTIFIER PUNCT_EXPR_START PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END",
"parameter_list : parameter",
"parameter_list : parameter PUNCT_COMMA parameter_list",
"parameter : type IDENTIFIER",
"class_declaration : KEYWORD_SAFEHOUSE IDENTIFIER PUNCT_BLOCK_START member_list PUNCT_BLOCK_END PUNCT_TERMINATOR",
"member_list : member member_list",
"member_list :",
"member : variable_declaration",
"statement_list : statement statement_list",
"statement_list :",
"statement : variable_declaration",
"statement : assignment_statement",
"statement : if_statement",
"statement : for_loop",
"statement : while_loop",
"statement : output_statement",
"statement : input_statement",
"statement : return_statement",
"statement : break_statement",
"statement : continue_statement",
"statement : function_call_statement",
"statement : error PUNCT_TERMINATOR",
"assignment_statement : IDENTIFIER OP_ASSIGN expression PUNCT_TERMINATOR",
"if_statement : KEYWORD_ORDER_HAI PUNCT_EXPR_START condition PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END else_if_part else_part",
"else_if_part : KEYWORD_DOOSRA_ORDER PUNCT_EXPR_START condition PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END else_if_part",
"else_if_part :",
"else_part : KEYWORD_WARNA_VIGO PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END",
"else_part :",
"for_loop : KEYWORD_LONG_MARCH PUNCT_EXPR_START for_init condition PUNCT_TERMINATOR for_update PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END",
"for_init : IDENTIFIER OP_ASSIGN expression PUNCT_TERMINATOR",
"for_update : IDENTIFIER OP_ASSIGN expression",
"while_loop : KEYWORD_JAB_TAK_MISSING PUNCT_EXPR_START condition PUNCT_EXPR_END PUNCT_BLOCK_START statement_list PUNCT_BLOCK_END",
"output_statement : KEYWORD_FARMAAN OP_OUTPUT expression PUNCT_TERMINATOR",
"input_statement : KEYWORD_TAFTISH OP_INPUT IDENTIFIER PUNCT_TERMINATOR",
"return_statement : KEYWORD_NRO expression PUNCT_TERMINATOR",
"return_statement : KEYWORD_NRO PUNCT_TERMINATOR",
"break_statement : KEYWORD_DEAL_HO_GAI PUNCT_TERMINATOR",
"continue_statement : KEYWORD_CHALTAY_RAHO PUNCT_TERMINATOR",
"function_call_statement : IDENTIFIER PUNCT_EXPR_START argument_list PUNCT_EXPR_END PUNCT_TERMINATOR",
"function_call_statement : IDENTIFIER PUNCT_EXPR_START PUNCT_EXPR_END PUNCT_TERMINATOR",
"argument_list : expression",
"argument_list : expression PUNCT_COMMA argument_list",
"condition : expression relational_operator expression",
"relational_operator : OP_EQUAL",
"relational_operator : OP_GREATER",
"relational_operator : OP_LESS",
"expression : expression OP_ADD term",
"expression : expression OP_SUB term",
"expression : term",
"term : term OP_MUL factor",
"term : factor",
"factor : IDENTIFIER",
"factor : NUMBER_INTEGER",
"factor : NUMBER_FLOAT",
"factor : NUMBER_EXPONENTIAL",
"factor : STRING_LITERAL",
"factor : CHAR_LITERAL",
"factor : KEYWORD_NEUTRAL",
"factor : KEYWORD_JANWAR",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 304 "parser.y"

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
#line 654 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 83 "parser.y"
	{ printf("   ✓ Program structure validated\n"); }
#line 1327 "y.tab.c"
break;
case 2:
#line 85 "parser.y"
	{ printf("   ✓ Program structure validated\n"); }
#line 1332 "y.tab.c"
break;
case 3:
#line 90 "parser.y"
	{ printf("   ✓ Main function (ghq) parsed successfully\n"); }
#line 1337 "y.tab.c"
break;
case 10:
#line 108 "parser.y"
	{ printf("   ✓ Variable declaration parsed\n"); }
#line 1342 "y.tab.c"
break;
case 11:
#line 110 "parser.y"
	{ printf("   ✓ Variable declaration with initialization parsed\n"); }
#line 1347 "y.tab.c"
break;
case 12:
#line 115 "parser.y"
	{ printf("   ✓ Constant declaration parsed\n"); }
#line 1352 "y.tab.c"
break;
case 13:
#line 120 "parser.y"
	{ /* int */ }
#line 1357 "y.tab.c"
break;
case 14:
#line 121 "parser.y"
	{ /* float */ }
#line 1362 "y.tab.c"
break;
case 15:
#line 122 "parser.y"
	{ /* string */ }
#line 1367 "y.tab.c"
break;
case 16:
#line 123 "parser.y"
	{ /* char */ }
#line 1372 "y.tab.c"
break;
case 17:
#line 124 "parser.y"
	{ /* void */ }
#line 1377 "y.tab.c"
break;
case 18:
#line 130 "parser.y"
	{ printf("   ✓ Function declaration parsed\n"); }
#line 1382 "y.tab.c"
break;
case 19:
#line 132 "parser.y"
	{ printf("   ✓ Function declaration (no params) parsed\n"); }
#line 1387 "y.tab.c"
break;
case 23:
#line 147 "parser.y"
	{ printf("   ✓ Class (safehouse) declaration parsed\n"); }
#line 1392 "y.tab.c"
break;
case 40:
#line 179 "parser.y"
	{ yyerrok; parse_success = 0; }
#line 1397 "y.tab.c"
break;
case 41:
#line 185 "parser.y"
	{ printf("   ✓ Assignment statement parsed\n"); }
#line 1402 "y.tab.c"
break;
case 42:
#line 191 "parser.y"
	{ printf("   ✓ Conditional statement (order_hai) parsed\n"); }
#line 1407 "y.tab.c"
break;
case 47:
#line 207 "parser.y"
	{ printf("   ✓ For loop (long_march) parsed\n"); }
#line 1412 "y.tab.c"
break;
case 50:
#line 221 "parser.y"
	{ printf("   ✓ While loop (jab_tak_missing) parsed\n"); }
#line 1417 "y.tab.c"
break;
case 51:
#line 227 "parser.y"
	{ printf("   ✓ Output statement (farmaan) parsed\n"); }
#line 1422 "y.tab.c"
break;
case 52:
#line 233 "parser.y"
	{ printf("   ✓ Input statement (taftish) parsed\n"); }
#line 1427 "y.tab.c"
break;
case 53:
#line 239 "parser.y"
	{ printf("   ✓ Return statement (nro) parsed\n"); }
#line 1432 "y.tab.c"
break;
case 54:
#line 241 "parser.y"
	{ printf("   ✓ Return statement (nro) parsed\n"); }
#line 1437 "y.tab.c"
break;
case 55:
#line 247 "parser.y"
	{ printf("   ✓ Break statement (deal_ho_gai) parsed\n"); }
#line 1442 "y.tab.c"
break;
case 56:
#line 253 "parser.y"
	{ printf("   ✓ Continue statement (chaltay_raho) parsed\n"); }
#line 1447 "y.tab.c"
break;
case 57:
#line 259 "parser.y"
	{ printf("   ✓ Function call parsed\n"); }
#line 1452 "y.tab.c"
break;
case 58:
#line 261 "parser.y"
	{ printf("   ✓ Function call (no args) parsed\n"); }
#line 1457 "y.tab.c"
break;
case 62:
#line 275 "parser.y"
	{ /* =? */ }
#line 1462 "y.tab.c"
break;
case 63:
#line 276 "parser.y"
	{ /* >? */ }
#line 1467 "y.tab.c"
break;
case 64:
#line 277 "parser.y"
	{ /* <? */ }
#line 1472 "y.tab.c"
break;
#line 1474 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
