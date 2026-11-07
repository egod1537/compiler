digit       [0-9]
letter      [a-zA-Z_]
delim       [ \t]
line        \r?\n
ws          {delim}+

%option noinput nounput

%{
#include <stdlib.h>
#include <string.h>
#include "type.h"
#include "parse_value.h"
#include "y.tab.h"

_Static_assert(sizeof(YYSTYPE)>=sizeof(void *),
               "YYSTYPE must be able to hold a pointer");

extern int line_no;
extern A_ID *current_id;

static char *makeString(const char *s);
static int checkIdentifier(const char *s);
%}

%%
{ws}                    { }
{line}                  { line_no++; }
"auto"|"static"|"typedef"|"extern"|"register" { return INVALID_TOKEN; }
struct                  { return STRUCT_SYM; }
union                   { return UNION_SYM; }
enum                    { return ENUM_SYM; }
sizeof                  { return SIZEOF_SYM; }
if                      { return IF_SYM; }
else                    { return ELSE_SYM; }
while                   { return WHILE_SYM; }
do                      { return DO_SYM; }
for                     { return FOR_SYM; }
continue                { return CONTINUE_SYM; }
break                   { return BREAK_SYM; }
return                  { return RETURN_SYM; }
switch                  { return SWITCH_SYM; }
case                    { return CASE_SYM; }
default                 { return DEFAULT_SYM; }
"++"                    { return PLUSPLUS; }
"--"                    { return MINUSMINUS; }
"->"                    { return ARROW; }
"||"                    { return BARBAR; }
"&&"                    { return AMPAMP; }
"<="                    { return LEQ; }
">="                    { return GEQ; }
"=="                    { return EQL; }
"!="                    { return NEQ; }
"..."                   { return DOTDOTDOT; }
"+"                     { return PLUS; }
"-"                     { return MINUS; }
"|"                     { return BAR; }
"&"                     { return AMP; }
";"                     { return SEMICOLON; }
"<"                     { return LSS; }
">"                     { return GTR; }
"("                     { return LP; }
")"                     { return RP; }
"["                     { return LB; }
"]"                     { return RB; }
"{"                     { return LR; }
"}"                     { return RR; }
"."                     { return PERIOD; }
","                     { return COMMA; }
"!"                     { return EXCL; }
"*"                     { return STAR; }
"/"                     { return SLASH; }
"%"                     { return PERCENT; }
"="                     { return ASSIGN; }
":"                     { return COLON; }
{digit}+                 { yylval = atoi(yytext); return INTEGER_CONSTANT; }
{digit}+\.{digit}+       { yylval = YY_FROM_PTR(makeString(yytext)); return FLOAT_CONSTANT; }
{letter}({letter}|{digit})* { return checkIdentifier(yytext); }
\"([^"\n]|\\["\n])*\" { yylval = YY_FROM_PTR(makeString(yytext)); return STRING_LITERAL; }
\'([^'\n]|\\')\'       { yylval = (unsigned char)*(yytext+1); return CHARACTER_CONSTANT; }
"//"[^\n]*              { }
.                       { return (unsigned char)yytext[0]; }
%%

static char *makeString(const char *s)
{
    char *t = (char *)malloc(strlen(s) + 1);
    strcpy(t, s);
    return t;
}

static int checkIdentifier(const char *s)
{
    A_ID *id = current_id;
    char *t;

    while (id) {
        if (strcmp(id->name, s) == 0)
            break;
        id = id->prev;
    }
    if (id == 0) {
        t = makeString(s);
        yylval = YY_FROM_PTR(t);
        return IDENTIFIER;
    } else if (id->kind == ID_TYPE) {
        yylval = YY_FROM_PTR(id->type);
        return TYPE_IDENTIFIER;
    } else {
        yylval = YY_FROM_PTR(id->name);
        return IDENTIFIER;
    }
}

int yywrap(void)
{
    return 1;
}
