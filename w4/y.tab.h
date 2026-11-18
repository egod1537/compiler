/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INVALID_TOKEN = 258,           /* INVALID_TOKEN  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    TYPE_IDENTIFIER = 260,         /* TYPE_IDENTIFIER  */
    INTEGER_CONSTANT = 261,        /* INTEGER_CONSTANT  */
    FLOAT_CONSTANT = 262,          /* FLOAT_CONSTANT  */
    CHARACTER_CONSTANT = 263,      /* CHARACTER_CONSTANT  */
    STRING_LITERAL = 264,          /* STRING_LITERAL  */
    BREAK_SYM = 265,               /* BREAK_SYM  */
    CASE_SYM = 266,                /* CASE_SYM  */
    CONTINUE_SYM = 267,            /* CONTINUE_SYM  */
    DEFAULT_SYM = 268,             /* DEFAULT_SYM  */
    DO_SYM = 269,                  /* DO_SYM  */
    ELSE_SYM = 270,                /* ELSE_SYM  */
    ENUM_SYM = 271,                /* ENUM_SYM  */
    FOR_SYM = 272,                 /* FOR_SYM  */
    IF_SYM = 273,                  /* IF_SYM  */
    RETURN_SYM = 274,              /* RETURN_SYM  */
    SIZEOF_SYM = 275,              /* SIZEOF_SYM  */
    STRUCT_SYM = 276,              /* STRUCT_SYM  */
    SWITCH_SYM = 277,              /* SWITCH_SYM  */
    UNION_SYM = 278,               /* UNION_SYM  */
    WHILE_SYM = 279,               /* WHILE_SYM  */
    PLUSPLUS = 280,                /* PLUSPLUS  */
    MINUSMINUS = 281,              /* MINUSMINUS  */
    ARROW = 282,                   /* ARROW  */
    LSS = 283,                     /* LSS  */
    GTR = 284,                     /* GTR  */
    LEQ = 285,                     /* LEQ  */
    GEQ = 286,                     /* GEQ  */
    EQL = 287,                     /* EQL  */
    NEQ = 288,                     /* NEQ  */
    AMPAMP = 289,                  /* AMPAMP  */
    BARBAR = 290,                  /* BARBAR  */
    DOTDOTDOT = 291,               /* DOTDOTDOT  */
    LP = 292,                      /* LP  */
    RP = 293,                      /* RP  */
    LB = 294,                      /* LB  */
    RB = 295,                      /* RB  */
    LR = 296,                      /* LR  */
    RR = 297,                      /* RR  */
    COLON = 298,                   /* COLON  */
    PERIOD = 299,                  /* PERIOD  */
    COMMA = 300,                   /* COMMA  */
    EXCL = 301,                    /* EXCL  */
    STAR = 302,                    /* STAR  */
    SLASH = 303,                   /* SLASH  */
    PERCENT = 304,                 /* PERCENT  */
    AMP = 305,                     /* AMP  */
    BAR = 306,                     /* BAR  */
    SEMICOLON = 307,               /* SEMICOLON  */
    PLUS = 308,                    /* PLUS  */
    MINUS = 309,                   /* MINUS  */
    ASSIGN = 310,                  /* ASSIGN  */
    LOWER_THAN_ELSE = 311          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
