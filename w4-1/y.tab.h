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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    TYPE_IDENTIFIER = 259,         /* TYPE_IDENTIFIER  */
    FLOAT_CONSTANT = 260,          /* FLOAT_CONSTANT  */
    INTEGER_CONSTANT = 261,        /* INTEGER_CONSTANT  */
    CHARACTER_CONSTANT = 262,      /* CHARACTER_CONSTANT  */
    STRING_LITERAL = 263,          /* STRING_LITERAL  */
    PLUS = 264,                    /* PLUS  */
    MINUS = 265,                   /* MINUS  */
    PLUSPLUS = 266,                /* PLUSPLUS  */
    MINUSMINUS = 267,              /* MINUSMINUS  */
    AMP = 268,                     /* AMP  */
    BARBAR = 269,                  /* BARBAR  */
    AMPAMP = 270,                  /* AMPAMP  */
    ARROW = 271,                   /* ARROW  */
    SEMICOLON = 272,               /* SEMICOLON  */
    LSS = 273,                     /* LSS  */
    GTR = 274,                     /* GTR  */
    LEQ = 275,                     /* LEQ  */
    GEQ = 276,                     /* GEQ  */
    EQL = 277,                     /* EQL  */
    NEQ = 278,                     /* NEQ  */
    DOTDOTDOT = 279,               /* DOTDOTDOT  */
    LP = 280,                      /* LP  */
    RP = 281,                      /* RP  */
    LB = 282,                      /* LB  */
    RB = 283,                      /* RB  */
    LR = 284,                      /* LR  */
    RR = 285,                      /* RR  */
    PERIOD = 286,                  /* PERIOD  */
    COMMA = 287,                   /* COMMA  */
    EXCL = 288,                    /* EXCL  */
    STAR = 289,                    /* STAR  */
    SLASH = 290,                   /* SLASH  */
    PERCENT = 291,                 /* PERCENT  */
    ASSIGN = 292,                  /* ASSIGN  */
    COLON = 293,                   /* COLON  */
    AUTO_SYM = 294,                /* AUTO_SYM  */
    STATIC_SYM = 295,              /* STATIC_SYM  */
    TYPEDEF_SYM = 296,             /* TYPEDEF_SYM  */
    STRUCT_SYM = 297,              /* STRUCT_SYM  */
    ENUM_SYM = 298,                /* ENUM_SYM  */
    SIZEOF_SYM = 299,              /* SIZEOF_SYM  */
    UNION_SYM = 300,               /* UNION_SYM  */
    IF_SYM = 301,                  /* IF_SYM  */
    ELSE_SYM = 302,                /* ELSE_SYM  */
    WHILE_SYM = 303,               /* WHILE_SYM  */
    DO_SYM = 304,                  /* DO_SYM  */
    FOR_SYM = 305,                 /* FOR_SYM  */
    CONTINUE_SYM = 306,            /* CONTINUE_SYM  */
    BREAK_SYM = 307,               /* BREAK_SYM  */
    RETURN_SYM = 308,              /* RETURN_SYM  */
    SWITCH_SYM = 309,              /* SWITCH_SYM  */
    CASE_SYM = 310,                /* CASE_SYM  */
    DEFAULT_SYM = 311              /* DEFAULT_SYM  */
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
