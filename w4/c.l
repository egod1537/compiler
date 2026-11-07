digit       [0-9]
letter      [a-zA-Z_]
delim       [ \t]
line        \r?\n
ws          {delim}+

%option noinput nounput

%{
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#ifdef _WIN64
typedef long long YYSTYPE;
#else
typedef long YYSTYPE;
#endif
#endif

#include "parse_value.h"
#include "semantic.h"
#include "error.h"
#include "y.tab.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkIdentifier(char *s);
%}

%%

{ws}                        {}
{line}                      { line_no++; }

"auto"|"static"|"typedef"|"register"|"extern" { return (INVALID_TOKEN); }

break                       { return (BREAK_SYM); }
case                        { return (CASE_SYM); }
continue                    { return (CONTINUE_SYM); }
default                     { return (DEFAULT_SYM); }
do                          { return (DO_SYM); }
else                        { return (ELSE_SYM); }
enum                        { return (ENUM_SYM); }
for                         { return (FOR_SYM); }
if                          { return (IF_SYM); }
return                      { return (RETURN_SYM); }
sizeof                      { return (SIZEOF_SYM); }
struct                      { return (STRUCT_SYM); }
switch                      { return (SWITCH_SYM); }
union                       { return (UNION_SYM); }
while                       { return (WHILE_SYM); }

"++"                        { return (PLUSPLUS); }
"--"                        { return (MINUSMINUS); }
"->"                        { return (ARROW); }

"<="                        { return (LEQ); }
">="                        { return (GEQ); }
"=="                        { return (EQL); }
"!="                        { return (NEQ); }

"&&"                        { return (AMPAMP); }
"||"                        { return (BARBAR); }

"..."                       { return (DOTDOTDOT); }

"<"                         { return (LSS); }
">"                         { return (GTR); }

"("                         { return (LP); }
")"                         { return (RP); }
"["                         { return (LB); }
"]"                         { return (RB); }
"{"                         { return (LR); }
"}"                         { return (RR); }

":"                         { return (COLON); }
"."                         { return (PERIOD); }
","                         { return (COMMA); }
"!"                         { return (EXCL); }

"*"                         { return (STAR); }
"/"                         { return (SLASH); }
"%"                         { return (PERCENT); }

"&"                         { return (AMP); }
"|"                         { return (BAR); }

";"                         { return (SEMICOLON); }

"+"                         { return (PLUS); }
"-"                         { return (MINUS); }

"="                         { return (ASSIGN); }

"//"[^\n]*                  {}

{digit}+\.{digit}+          {
  char *value = malloc(strlen(yytext) + 1);

  if (value == NULL) {
    report_compiler_error(INTERNAL_ERROR, 0, line_no, "memory allocation failed");
    exit(EXIT_FAILURE);
  }

  strcpy(value, yytext);
  yylval = YY(value);

  return (FLOAT_CONSTANT);
}
{digit}+                    {
  yylval = atoi(yytext);
  return (INTEGER_CONSTANT);
}

\"([^"\n]|\\["\n])*\"        {
  char *value = malloc(strlen(yytext) + 1);
  if (value == NULL) {
    report_compiler_error(INTERNAL_ERROR, 0, line_no, "memory allocation failed");
    exit(EXIT_FAILURE);
  }

  strcpy(value, yytext);
  yylval = YY(value);
  return (STRING_LITERAL);
}
\'([^'\n]|\\\')\'             {
  yylval = (unsigned char)yytext[1];
  return(CHARACTER_CONSTANT);
}

{letter}({letter}|{digit})* {
  int token = checkIdentifier(yytext);

  if (token == TYPE_IDENTIFIER) {
    A_ID *id = searchIdentifier(yytext);
    yylval = YY(id != NULL ? id->type : NULL);
  } else {
    char *name = malloc(strlen(yytext) + 1);

    if (name == NULL) {
      report_compiler_error(INTERNAL_ERROR, 0, line_no, "memory allocation failed");
      exit(EXIT_FAILURE);
    }

    strcpy(name, yytext);
    yylval = (YYSTYPE)(intptr_t)name;
  }

  return token;
}

. {
  if (compiler_error_tags_enabled()) {
    report_compiler_error(LEXICAL_ERROR, 0, line_no,
                          "invalid character '%s'", yytext);
    exit(EXIT_FAILURE);
  }

  return (unsigned char)yytext[0];
}


%%
int checkIdentifier(char *s) {
  A_ID *id = searchIdentifier(s);
  if (id != NULL && id->kind == ID_TYPE)
    return TYPE_IDENTIFIER;

  return IDENTIFIER;
}

int yywrap(void) {
  return 1;
}
