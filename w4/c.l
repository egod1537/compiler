digit       [0-9]
letter      [a-zA-Z_]
delim       [ \t]
line        [\n]
ws          {delim}+

%{
#include "y.tab.h"
#include <string.h>

int line_no = 1;

int checkIdentifier(char *s);
%}

%%

{ws}                        { }
{line}                      { line_no++; }

auto                        { return(AUTO_SYM); }
static                      { return(STATIC_SYM); }
typedef                     { return(TYPEDEF_SYM); }
register                    { return(REGISTER_SYM); }
extern                      { return(EXTERN_SYM); }

break                       { return(BREAK_SYM); }
case                        { return(CASE_SYM); }
continue                    { return(CONTINUE_SYM); }
default                     { return(DEFAULT_SYM); }
do                          { return(DO_SYM); }
else                        { return(ELSE_SYM); }
enum                        { return(ENUM_SYM); }
for                         { return(FOR_SYM); }
goto                        { return(GOTO_SYM); }
if                          { return(IF_SYM); }
return                      { return(RETURN_SYM); }
sizeof                      { return(SIZEOF_SYM); }
struct                      { return(STRUCT_SYM); }
switch                      { return(SWITCH_SYM); }
union                       { return(UNION_SYM); }
while                       { return(WHILE_SYM); }

const                       { return(CONST_SYM); }
volatile                    { return(VOLATILE_SYM); }

"++"                        { return(PLUSPLUS); }
"--"                        { return(MINUSMINUS); }
"->"                        { return(ARROW); }

"<="                        { return(LEQ); }
">="                        { return(GEQ); }
"=="                        { return(EQL); }
"!="                        { return(NEQ); }

"&&"                        { return(AMPAMP); }
"||"                        { return(BARBAR); }

"<<"                        { return(LSHIFT); }
">>"                        { return(RSHIFT); }

"..."                       { return(DOTDOTDOT); }

"<"                         { return(LSS); }
">"                         { return(GTR); }

"("                         { return(LP); }
")"                         { return(RP); }
"["                         { return(LB); }
"]"                         { return(RB); }
"{"                         { return(LR); }
"}"                         { return(RR); }

":"                         { return(COLON); }
"."                         { return(PERIOD); }
","                         { return(COMMA); }
"!"                         { return(EXCL); }
"~"                         { return(TILDE); }

"*"                         { return(STAR); }
"/"                         { return(SLASH); }
"%"                         { return(PERCENT); }

"&"                         { return(AMP); }
"|"                         { return(BAR); }
"^"                         { return(CARET); }

";"                         { return(SEMICOLON); }

"+"                         { return(PLUS); }
"-"                         { return(MINUS); }

"="                         { return(ASSIGN); }

"?"                         { return(QUESTION); }

"//"[^\n]*                  { }
"/*"([^*]|\*+[^*/])*\*+"/"  { }

{digit}+\.{digit}+          { return(FLOAT_CONSTANT); }
{digit}+                    { return(INTEGER_CONSTANT); }

\"([^"\n]|\\["\n])*\"        { return(STRING_LITERAL); }
\'([^'\n]|\\.)\'             { return(CHARACTER_CONSTANT); }

{letter}({letter}|{digit})* { return(checkIdentifier(yytext)); }

%%

int checkIdentifier(char *s)
{
    const char *types[] = {
        "int",
        "float",
        "double",
        "char",
        "void",
        "short",
        "long",
        "signed",
        "unsigned" };

    int count = sizeof(types) / sizeof(types[0]);

    for (int i = 0; i < count; i++) {
        if (strcmp(s, types[i]) == 0)
            return TYPE_IDENTIFIER;
    }

    return IDENTIFIER;
}

int yywrap(void)
{
    return 1;
}
