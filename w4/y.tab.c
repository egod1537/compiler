/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"

#include "parse_value.h"
#include <stdio.h>
#include <stdlib.h>

#include "logger.h"
#include "semantic.h"
#include "syntax_tree.h"
#include "tests/ast_assert.h"
#include "type.h"

int yylex(void);
int yyerror(const char *s);
extern int line_no;

A_NODE *makeNode(NODE_NAME name, A_NODE *left, A_NODE *center, A_NODE *right);

#line 89 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    INTEGER_CONSTANT = 260,        /* INTEGER_CONSTANT  */
    FLOAT_CONSTANT = 261,          /* FLOAT_CONSTANT  */
    CHARACTER_CONSTANT = 262,      /* CHARACTER_CONSTANT  */
    STRING_LITERAL = 263,          /* STRING_LITERAL  */
    AUTO_SYM = 264,                /* AUTO_SYM  */
    BREAK_SYM = 265,               /* BREAK_SYM  */
    CASE_SYM = 266,                /* CASE_SYM  */
    CONTINUE_SYM = 267,            /* CONTINUE_SYM  */
    DEFAULT_SYM = 268,             /* DEFAULT_SYM  */
    DO_SYM = 269,                  /* DO_SYM  */
    ELSE_SYM = 270,                /* ELSE_SYM  */
    ENUM_SYM = 271,                /* ENUM_SYM  */
    FOR_SYM = 272,                 /* FOR_SYM  */
    GOTO_SYM = 273,                /* GOTO_SYM  */
    IF_SYM = 274,                  /* IF_SYM  */
    RETURN_SYM = 275,              /* RETURN_SYM  */
    SIZEOF_SYM = 276,              /* SIZEOF_SYM  */
    STATIC_SYM = 277,              /* STATIC_SYM  */
    STRUCT_SYM = 278,              /* STRUCT_SYM  */
    SWITCH_SYM = 279,              /* SWITCH_SYM  */
    TYPEDEF_SYM = 280,             /* TYPEDEF_SYM  */
    UNION_SYM = 281,               /* UNION_SYM  */
    WHILE_SYM = 282,               /* WHILE_SYM  */
    REGISTER_SYM = 283,            /* REGISTER_SYM  */
    EXTERN_SYM = 284,              /* EXTERN_SYM  */
    CONST_SYM = 285,               /* CONST_SYM  */
    VOLATILE_SYM = 286,            /* VOLATILE_SYM  */
    PLUSPLUS = 287,                /* PLUSPLUS  */
    MINUSMINUS = 288,              /* MINUSMINUS  */
    ARROW = 289,                   /* ARROW  */
    LSS = 290,                     /* LSS  */
    GTR = 291,                     /* GTR  */
    LEQ = 292,                     /* LEQ  */
    GEQ = 293,                     /* GEQ  */
    EQL = 294,                     /* EQL  */
    NEQ = 295,                     /* NEQ  */
    AMPAMP = 296,                  /* AMPAMP  */
    BARBAR = 297,                  /* BARBAR  */
    LSHIFT = 298,                  /* LSHIFT  */
    RSHIFT = 299,                  /* RSHIFT  */
    DOTDOTDOT = 300,               /* DOTDOTDOT  */
    LP = 301,                      /* LP  */
    RP = 302,                      /* RP  */
    LB = 303,                      /* LB  */
    RB = 304,                      /* RB  */
    LR = 305,                      /* LR  */
    RR = 306,                      /* RR  */
    COLON = 307,                   /* COLON  */
    PERIOD = 308,                  /* PERIOD  */
    COMMA = 309,                   /* COMMA  */
    EXCL = 310,                    /* EXCL  */
    TILDE = 311,                   /* TILDE  */
    STAR = 312,                    /* STAR  */
    SLASH = 313,                   /* SLASH  */
    PERCENT = 314,                 /* PERCENT  */
    AMP = 315,                     /* AMP  */
    BAR = 316,                     /* BAR  */
    CARET = 317,                   /* CARET  */
    SEMICOLON = 318,               /* SEMICOLON  */
    PLUS = 319,                    /* PLUS  */
    MINUS = 320,                   /* MINUS  */
    ASSIGN = 321,                  /* ASSIGN  */
    QUESTION = 322,                /* QUESTION  */
    LOWER_THAN_ELSE = 323          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define TYPE_IDENTIFIER 259
#define INTEGER_CONSTANT 260
#define FLOAT_CONSTANT 261
#define CHARACTER_CONSTANT 262
#define STRING_LITERAL 263
#define AUTO_SYM 264
#define BREAK_SYM 265
#define CASE_SYM 266
#define CONTINUE_SYM 267
#define DEFAULT_SYM 268
#define DO_SYM 269
#define ELSE_SYM 270
#define ENUM_SYM 271
#define FOR_SYM 272
#define GOTO_SYM 273
#define IF_SYM 274
#define RETURN_SYM 275
#define SIZEOF_SYM 276
#define STATIC_SYM 277
#define STRUCT_SYM 278
#define SWITCH_SYM 279
#define TYPEDEF_SYM 280
#define UNION_SYM 281
#define WHILE_SYM 282
#define REGISTER_SYM 283
#define EXTERN_SYM 284
#define CONST_SYM 285
#define VOLATILE_SYM 286
#define PLUSPLUS 287
#define MINUSMINUS 288
#define ARROW 289
#define LSS 290
#define GTR 291
#define LEQ 292
#define GEQ 293
#define EQL 294
#define NEQ 295
#define AMPAMP 296
#define BARBAR 297
#define LSHIFT 298
#define RSHIFT 299
#define DOTDOTDOT 300
#define LP 301
#define RP 302
#define LB 303
#define RB 304
#define LR 305
#define RR 306
#define COLON 307
#define PERIOD 308
#define COMMA 309
#define EXCL 310
#define TILDE 311
#define STAR 312
#define SLASH 313
#define PERCENT 314
#define AMP 315
#define BAR 316
#define CARET 317
#define SEMICOLON 318
#define PLUS 319
#define MINUS 320
#define ASSIGN 321
#define QUESTION 322
#define LOWER_THAN_ELSE 323

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_TYPE_IDENTIFIER = 4,            /* TYPE_IDENTIFIER  */
  YYSYMBOL_INTEGER_CONSTANT = 5,           /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 6,             /* FLOAT_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 7,         /* CHARACTER_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 8,             /* STRING_LITERAL  */
  YYSYMBOL_AUTO_SYM = 9,                   /* AUTO_SYM  */
  YYSYMBOL_BREAK_SYM = 10,                 /* BREAK_SYM  */
  YYSYMBOL_CASE_SYM = 11,                  /* CASE_SYM  */
  YYSYMBOL_CONTINUE_SYM = 12,              /* CONTINUE_SYM  */
  YYSYMBOL_DEFAULT_SYM = 13,               /* DEFAULT_SYM  */
  YYSYMBOL_DO_SYM = 14,                    /* DO_SYM  */
  YYSYMBOL_ELSE_SYM = 15,                  /* ELSE_SYM  */
  YYSYMBOL_ENUM_SYM = 16,                  /* ENUM_SYM  */
  YYSYMBOL_FOR_SYM = 17,                   /* FOR_SYM  */
  YYSYMBOL_GOTO_SYM = 18,                  /* GOTO_SYM  */
  YYSYMBOL_IF_SYM = 19,                    /* IF_SYM  */
  YYSYMBOL_RETURN_SYM = 20,                /* RETURN_SYM  */
  YYSYMBOL_SIZEOF_SYM = 21,                /* SIZEOF_SYM  */
  YYSYMBOL_STATIC_SYM = 22,                /* STATIC_SYM  */
  YYSYMBOL_STRUCT_SYM = 23,                /* STRUCT_SYM  */
  YYSYMBOL_SWITCH_SYM = 24,                /* SWITCH_SYM  */
  YYSYMBOL_TYPEDEF_SYM = 25,               /* TYPEDEF_SYM  */
  YYSYMBOL_UNION_SYM = 26,                 /* UNION_SYM  */
  YYSYMBOL_WHILE_SYM = 27,                 /* WHILE_SYM  */
  YYSYMBOL_REGISTER_SYM = 28,              /* REGISTER_SYM  */
  YYSYMBOL_EXTERN_SYM = 29,                /* EXTERN_SYM  */
  YYSYMBOL_CONST_SYM = 30,                 /* CONST_SYM  */
  YYSYMBOL_VOLATILE_SYM = 31,              /* VOLATILE_SYM  */
  YYSYMBOL_PLUSPLUS = 32,                  /* PLUSPLUS  */
  YYSYMBOL_MINUSMINUS = 33,                /* MINUSMINUS  */
  YYSYMBOL_ARROW = 34,                     /* ARROW  */
  YYSYMBOL_LSS = 35,                       /* LSS  */
  YYSYMBOL_GTR = 36,                       /* GTR  */
  YYSYMBOL_LEQ = 37,                       /* LEQ  */
  YYSYMBOL_GEQ = 38,                       /* GEQ  */
  YYSYMBOL_EQL = 39,                       /* EQL  */
  YYSYMBOL_NEQ = 40,                       /* NEQ  */
  YYSYMBOL_AMPAMP = 41,                    /* AMPAMP  */
  YYSYMBOL_BARBAR = 42,                    /* BARBAR  */
  YYSYMBOL_LSHIFT = 43,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 44,                    /* RSHIFT  */
  YYSYMBOL_DOTDOTDOT = 45,                 /* DOTDOTDOT  */
  YYSYMBOL_LP = 46,                        /* LP  */
  YYSYMBOL_RP = 47,                        /* RP  */
  YYSYMBOL_LB = 48,                        /* LB  */
  YYSYMBOL_RB = 49,                        /* RB  */
  YYSYMBOL_LR = 50,                        /* LR  */
  YYSYMBOL_RR = 51,                        /* RR  */
  YYSYMBOL_COLON = 52,                     /* COLON  */
  YYSYMBOL_PERIOD = 53,                    /* PERIOD  */
  YYSYMBOL_COMMA = 54,                     /* COMMA  */
  YYSYMBOL_EXCL = 55,                      /* EXCL  */
  YYSYMBOL_TILDE = 56,                     /* TILDE  */
  YYSYMBOL_STAR = 57,                      /* STAR  */
  YYSYMBOL_SLASH = 58,                     /* SLASH  */
  YYSYMBOL_PERCENT = 59,                   /* PERCENT  */
  YYSYMBOL_AMP = 60,                       /* AMP  */
  YYSYMBOL_BAR = 61,                       /* BAR  */
  YYSYMBOL_CARET = 62,                     /* CARET  */
  YYSYMBOL_SEMICOLON = 63,                 /* SEMICOLON  */
  YYSYMBOL_PLUS = 64,                      /* PLUS  */
  YYSYMBOL_MINUS = 65,                     /* MINUS  */
  YYSYMBOL_ASSIGN = 66,                    /* ASSIGN  */
  YYSYMBOL_QUESTION = 67,                  /* QUESTION  */
  YYSYMBOL_LOWER_THAN_ELSE = 68,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_program = 70,                   /* program  */
  YYSYMBOL_translation_unit = 71,          /* translation_unit  */
  YYSYMBOL_external_declaration = 72,      /* external_declaration  */
  YYSYMBOL_function_definition = 73,       /* function_definition  */
  YYSYMBOL_74_1 = 74,                      /* @1  */
  YYSYMBOL_75_2 = 75,                      /* @2  */
  YYSYMBOL_declaration_list_opt = 76,      /* declaration_list_opt  */
  YYSYMBOL_declaration = 77,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 78,    /* declaration_specifiers  */
  YYSYMBOL_storage_class_specifier = 79,   /* storage_class_specifier  */
  YYSYMBOL_type_qualifier = 80,            /* type_qualifier  */
  YYSYMBOL_init_declarator_list = 81,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 82,           /* init_declarator  */
  YYSYMBOL_type_specifier = 83,            /* type_specifier  */
  YYSYMBOL_struct_specifier = 84,          /* struct_specifier  */
  YYSYMBOL_85_3 = 85,                      /* @3  */
  YYSYMBOL_86_4 = 86,                      /* @4  */
  YYSYMBOL_struct_or_union = 87,           /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 88,   /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 89,        /* struct_declaration  */
  YYSYMBOL_struct_declarator_list = 90,    /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 91,         /* struct_declarator  */
  YYSYMBOL_enum_specifier = 92,            /* enum_specifier  */
  YYSYMBOL_93_5 = 93,                      /* @5  */
  YYSYMBOL_94_6 = 94,                      /* @6  */
  YYSYMBOL_enumerator_list = 95,           /* enumerator_list  */
  YYSYMBOL_enumerator = 96,                /* enumerator  */
  YYSYMBOL_declarator = 97,                /* declarator  */
  YYSYMBOL_pointer = 98,                   /* pointer  */
  YYSYMBOL_type_qualifier_list_opt = 99,   /* type_qualifier_list_opt  */
  YYSYMBOL_type_qualifier_list = 100,      /* type_qualifier_list  */
  YYSYMBOL_direct_declarator = 101,        /* direct_declarator  */
  YYSYMBOL_constant_expression_opt = 102,  /* constant_expression_opt  */
  YYSYMBOL_parameter_type_list_opt = 103,  /* parameter_type_list_opt  */
  YYSYMBOL_parameter_type_list = 104,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 105,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 106,    /* parameter_declaration  */
  YYSYMBOL_abstract_declarator_opt = 107,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 108,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 109, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 110,              /* initializer  */
  YYSYMBOL_initializer_list = 111,         /* initializer_list  */
  YYSYMBOL_statement = 112,                /* statement  */
  YYSYMBOL_scoped_compound_statement = 113, /* scoped_compound_statement  */
  YYSYMBOL_114_7 = 114,                    /* $@7  */
  YYSYMBOL_labeled_statement = 115,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 116,       /* compound_statement  */
  YYSYMBOL_declaration_list = 117,         /* declaration_list  */
  YYSYMBOL_statement_list_opt = 118,       /* statement_list_opt  */
  YYSYMBOL_statement_list = 119,           /* statement_list  */
  YYSYMBOL_expression_statement = 120,     /* expression_statement  */
  YYSYMBOL_selection_statement = 121,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 122,      /* iteration_statement  */
  YYSYMBOL_expression_opt = 123,           /* expression_opt  */
  YYSYMBOL_for_expression = 124,           /* for_expression  */
  YYSYMBOL_jump_statement = 125,           /* jump_statement  */
  YYSYMBOL_primary_expression = 126,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 127,       /* postfix_expression  */
  YYSYMBOL_arg_expression_list_opt = 128,  /* arg_expression_list_opt  */
  YYSYMBOL_arg_expression_list = 129,      /* arg_expression_list  */
  YYSYMBOL_unary_expression = 130,         /* unary_expression  */
  YYSYMBOL_cast_expression = 131,          /* cast_expression  */
  YYSYMBOL_type_name = 132,                /* type_name  */
  YYSYMBOL_multiplicative_expression = 133, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 134,      /* additive_expression  */
  YYSYMBOL_shift_expression = 135,         /* shift_expression  */
  YYSYMBOL_relational_expression = 136,    /* relational_expression  */
  YYSYMBOL_equality_expression = 137,      /* equality_expression  */
  YYSYMBOL_AND_expression = 138,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 139,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 140,  /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 141,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 142,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 143,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 144,    /* assignment_expression  */
  YYSYMBOL_comma_expression = 145,         /* comma_expression  */
  YYSYMBOL_expression = 146,               /* expression  */
  YYSYMBOL_constant_expression = 147       /* constant_expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   770

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  194
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  328

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    53,    54,    58,    59,    66,    65,    91,
      90,   120,   123,   130,   137,   141,   145,   150,   154,   158,
     166,   167,   168,   169,   174,   182,   183,   187,   191,   198,
     202,   206,   207,   208,   216,   215,   226,   225,   233,   242,
     243,   247,   248,   255,   262,   263,   270,   271,   276,   285,
     284,   293,   292,   300,   307,   308,   315,   323,   327,   331,
     338,   342,   349,   350,   354,   355,   359,   368,   369,   374,
     383,   386,   394,   397,   404,   405,   409,   413,   420,   424,
     436,   439,   446,   450,   454,   461,   465,   469,   473,   478,
     486,   487,   488,   492,   493,   497,   498,   502,   506,   507,
     508,   516,   516,   527,   531,   535,   539,   548,   552,   560,
     563,   570,   575,   582,   586,   593,   597,   601,   608,   612,
     616,   624,   627,   634,   641,   647,   651,   655,   659,   667,
     674,   678,   682,   686,   693,   697,   701,   705,   710,   715,
     719,   727,   730,   734,   739,   746,   750,   754,   758,   762,
     766,   770,   774,   775,   779,   783,   790,   794,   801,   808,
     812,   816,   820,   827,   831,   835,   842,   843,   844,   848,
     852,   856,   860,   864,   871,   875,   879,   886,   887,   891,
     892,   896,   897,   901,   902,   909,   910,   917,   918,   922,
     926,   933,   934,   938,   946
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "TYPE_IDENTIFIER", "INTEGER_CONSTANT", "FLOAT_CONSTANT",
  "CHARACTER_CONSTANT", "STRING_LITERAL", "AUTO_SYM", "BREAK_SYM",
  "CASE_SYM", "CONTINUE_SYM", "DEFAULT_SYM", "DO_SYM", "ELSE_SYM",
  "ENUM_SYM", "FOR_SYM", "GOTO_SYM", "IF_SYM", "RETURN_SYM", "SIZEOF_SYM",
  "STATIC_SYM", "STRUCT_SYM", "SWITCH_SYM", "TYPEDEF_SYM", "UNION_SYM",
  "WHILE_SYM", "REGISTER_SYM", "EXTERN_SYM", "CONST_SYM", "VOLATILE_SYM",
  "PLUSPLUS", "MINUSMINUS", "ARROW", "LSS", "GTR", "LEQ", "GEQ", "EQL",
  "NEQ", "AMPAMP", "BARBAR", "LSHIFT", "RSHIFT", "DOTDOTDOT", "LP", "RP",
  "LB", "RB", "LR", "RR", "COLON", "PERIOD", "COMMA", "EXCL", "TILDE",
  "STAR", "SLASH", "PERCENT", "AMP", "BAR", "CARET", "SEMICOLON", "PLUS",
  "MINUS", "ASSIGN", "QUESTION", "LOWER_THAN_ELSE", "$accept", "program",
  "translation_unit", "external_declaration", "function_definition", "@1",
  "@2", "declaration_list_opt", "declaration", "declaration_specifiers",
  "storage_class_specifier", "type_qualifier", "init_declarator_list",
  "init_declarator", "type_specifier", "struct_specifier", "@3", "@4",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "enum_specifier", "@5",
  "@6", "enumerator_list", "enumerator", "declarator", "pointer",
  "type_qualifier_list_opt", "type_qualifier_list", "direct_declarator",
  "constant_expression_opt", "parameter_type_list_opt",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "abstract_declarator_opt", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "statement", "scoped_compound_statement", "$@7", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list_opt",
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "expression_opt", "for_expression",
  "jump_statement", "primary_expression", "postfix_expression",
  "arg_expression_list_opt", "arg_expression_list", "unary_expression",
  "cast_expression", "type_name", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "AND_expression", "exclusive_OR_expression",
  "inclusive_OR_expression", "logical_AND_expression",
  "logical_OR_expression", "conditional_expression",
  "assignment_expression", "comma_expression", "expression",
  "constant_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-241)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-111)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     680,  -241,  -241,  -241,    31,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,    27,    39,    46,   680,  -241,  -241,  -241,
      27,   284,   284,   284,  -241,    54,  -241,  -241,    32,    -6,
       2,    26,    75,  -241,     7,    39,  -241,  -241,   -15,  -241,
      -5,  -241,  -241,  -241,    78,    98,   108,    -6,   284,   547,
     111,    93,  -241,  -241,  -241,    27,  -241,   510,   108,   115,
      40,   284,  -241,    34,   126,  -241,   120,  -241,  -241,  -241,
    -241,  -241,  -241,   584,   621,   621,   436,   547,   547,   547,
     547,   547,   547,   135,  -241,   173,  -241,  -241,    77,    45,
      87,   196,   124,   123,   128,   125,   150,   -14,  -241,  -241,
      93,   127,    14,  -241,  -241,   129,   510,  -241,   133,  -241,
    -241,  -241,    40,    97,   134,  -241,   265,  -241,    27,   284,
     634,   547,  -241,    59,  -241,  -241,    94,  -241,   724,   436,
    -241,   547,  -241,  -241,   -10,   147,  -241,   146,   162,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,   208,   547,
     547,   210,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,    43,   547,  -241,    93,  -241,    73,   547,   166,   547,
      49,  -241,   170,  -241,  -241,   171,   155,   547,   164,   176,
     391,   179,   226,   189,   547,   191,   199,  -241,  -241,  -241,
     108,  -241,   197,   328,  -241,  -241,  -241,  -241,   184,  -241,
     203,   204,   211,    94,   284,   547,  -241,  -241,   212,   713,
     105,  -241,   547,   547,  -241,  -241,   214,   209,  -241,   213,
    -241,  -241,  -241,  -241,    77,    77,    45,    45,    87,    87,
      87,    87,   196,   196,   124,   123,   128,   125,   150,   217,
    -241,  -241,  -241,  -241,   473,  -241,  -241,  -241,    97,  -241,
     547,   391,  -241,   222,  -241,   391,   237,   547,   202,   547,
     218,  -241,   547,   547,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,   233,   238,  -241,  -241,  -241,  -241,   547,  -241,   547,
    -241,  -241,  -241,  -241,  -241,   391,  -241,   244,   228,   247,
    -241,   248,  -241,   249,   252,  -241,  -241,  -241,  -241,  -241,
     547,   547,   391,   391,   391,   391,   254,   239,  -241,   288,
    -241,  -241,   241,   547,   391,  -241,  -241,  -241
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    66,    33,    20,    51,    21,    39,    22,    40,    23,
      24,    25,    26,     0,    62,     0,     2,     3,     5,     6,
       0,    15,    16,    14,    31,    36,    32,     9,     0,    59,
      53,     0,     0,    64,    60,    63,     1,     4,     0,    27,
      29,    18,    19,    17,    38,     0,     0,    58,    72,    70,
       0,     0,    67,    61,    65,     0,    13,     0,     0,     0,
       0,    11,    10,    80,     0,    73,    74,    76,   128,   129,
     130,   131,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   145,   156,   159,   163,   166,
     169,   174,   177,   179,   181,   183,   185,   187,   194,    71,
       0,    56,     0,    54,    28,    29,     0,    30,   156,   189,
      90,     8,     0,     0,     0,    41,   101,   107,     0,    12,
      72,    70,    78,    82,    79,    81,    83,    69,     0,     0,
     154,     0,   146,   147,    80,     0,   191,   193,     0,   150,
     152,   149,   148,   153,   151,    68,   139,   140,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,    93,     0,     0,     0,     0,
       0,    44,    46,    37,    42,   128,     0,     0,     0,     0,
     101,     0,     0,     0,   121,     0,     0,   113,   111,    96,
       0,    95,     0,   101,    97,    98,    99,   100,     0,   108,
       0,     0,     0,    84,    72,    70,    75,    77,     0,    72,
      82,   158,     0,     0,   133,   138,     0,   142,   143,     0,
     137,   160,   161,   162,   164,   165,   167,   168,   170,   171,
     172,   173,   175,   176,   178,   180,   182,   184,   186,     0,
      50,    57,    55,    91,     0,   190,    35,    47,     0,    43,
       0,   101,   126,     0,   125,   101,     0,   121,     0,     0,
       0,   122,     0,     0,   102,   106,   112,   114,    87,    85,
      86,     0,     0,   155,   157,   192,   136,     0,   135,     0,
      92,    94,    45,    48,   105,   101,   104,     0,     0,     0,
     127,     0,   124,     0,     0,    89,    88,   144,   188,   103,
       0,   121,   101,   101,   101,   101,     0,     0,   120,   115,
     117,   118,     0,   121,   101,   119,   123,   116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -241,  -241,  -241,   289,  -241,  -241,  -241,  -241,   -29,    95,
    -241,    15,  -241,   253,   -37,  -241,  -241,  -241,  -241,   205,
     -89,  -241,    60,  -241,  -241,  -241,   219,   149,   -12,   -32,
    -241,  -241,    -4,  -100,   -45,  -241,  -241,   198,   190,   -98,
    -116,  -102,  -241,  -136,  -241,  -241,  -241,   -38,  -241,  -241,
    -241,  -241,  -241,  -241,  -240,  -241,  -241,  -241,  -241,  -241,
    -241,   -57,   -67,   215,   -11,    10,    82,    17,   167,   161,
     183,   169,   174,  -241,   -40,   -51,  -241,   -71,  -146
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    15,    16,    17,    18,    58,    46,   116,    19,    63,
      21,    22,    38,    39,    23,    24,    59,    45,    25,   114,
     115,   180,   181,    26,    50,    31,   102,   103,    27,    28,
      34,    35,    29,    83,   210,    65,    66,    67,   124,   125,
     126,   107,   176,   198,   199,   200,   201,    62,   119,   202,
     203,   204,   205,   206,   270,   299,   207,    84,    85,   226,
     227,    86,    87,   135,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   109,   136,   137,   208,    99
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,    32,    53,    64,   175,   138,   110,   213,    40,    98,
     139,   140,   141,   142,   143,   144,   130,   132,   133,   108,
     111,   212,   211,   113,    47,   184,   251,   298,   169,    33,
       1,   123,   117,   257,    30,     1,   219,     1,   121,    55,
      48,   263,    49,   105,     2,    -7,    36,    14,    56,   108,
      54,   122,   -49,   170,   266,   110,     4,    44,   138,   108,
     138,    57,     1,     6,    14,   173,     8,   276,   174,    11,
      12,   317,   108,    13,   108,   113,    51,   113,    13,   229,
     120,    98,   121,   326,    14,   231,   232,   233,   123,   184,
     209,    14,   108,   108,   250,    20,   101,   174,   228,   249,
       1,   182,   220,   258,   213,   120,   105,   121,    32,   155,
     156,    20,   259,   108,   293,   282,    41,    42,    43,    47,
     108,   211,    52,   271,   253,   294,   255,   254,   -34,   296,
     157,   158,    98,   108,   152,   153,   154,   108,     2,    98,
     214,   113,   215,    13,   234,   235,   108,    98,    60,   179,
       4,   219,   291,   121,    14,   284,   118,     6,    61,   309,
       8,   100,   274,   163,   164,   112,   108,   236,   237,   281,
       2,   134,   285,   127,   128,    98,   318,   319,   320,   321,
     242,   243,     4,   165,   145,   183,   167,   220,   327,     6,
     166,   168,     8,   172,   222,    57,   271,   108,   301,   177,
     223,   303,   304,   110,   108,   146,   147,   148,   108,   224,
     108,   225,   108,   230,   118,   108,   108,   256,   262,   149,
      98,   150,   260,   261,   134,   267,   151,   264,   265,   268,
     108,   159,   160,   161,   162,   269,   307,   272,   108,   316,
     271,   238,   239,   240,   241,   273,   182,   277,   275,   308,
     278,   279,   271,   108,   108,   108,   108,   108,   108,   283,
     280,   286,   288,   287,   297,   300,   108,   108,   185,   289,
      69,    70,    71,    72,   295,   186,   187,   188,   189,   190,
     305,   302,   191,   192,   193,   194,    73,   306,     2,   195,
     310,   311,   196,     3,   312,   313,   314,    74,    75,   315,
       4,   322,   323,   324,   325,    37,     5,     6,   104,     7,
       8,    76,     9,    10,    11,    12,  -109,   178,   292,   171,
      77,    78,    79,   252,   221,    80,   217,   245,   197,    81,
      82,   185,   244,    69,    70,    71,    72,   247,   186,   187,
     188,   189,   190,   248,   218,   191,   192,   193,   194,    73,
     246,     0,   195,     0,     0,   196,     0,     0,     0,     0,
      74,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,     0,     0,  -110,
       0,     0,     0,    77,    78,    79,     0,     0,    80,     0,
       0,   197,    81,    82,   185,     0,    69,    70,    71,    72,
       0,   186,   187,   188,   189,   190,     0,     0,   191,   192,
     193,   194,    73,     0,     0,   195,     0,     0,   196,     0,
       0,     0,     0,    74,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,    68,
       2,    69,    70,    71,    72,     3,    77,    78,    79,     0,
       0,    80,     4,     0,   197,    81,    82,    73,     5,     6,
       0,     7,     8,     0,     9,    10,    11,    12,    74,    75,
       0,     0,     0,     0,     0,     0,    68,     0,    69,    70,
      71,    72,    76,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    73,     0,    80,     0,     0,     0,
      81,    82,     0,     0,     0,    74,    75,     0,     0,     0,
       0,     0,     0,    68,     0,    69,    70,    71,    72,    76,
       0,     0,     0,   106,   290,     0,     0,     0,    77,    78,
      79,    73,     0,    80,     0,     0,     0,    81,    82,     0,
       0,     0,    74,    75,     0,     0,     0,     0,     0,     0,
      68,     0,    69,    70,    71,    72,    76,     0,     0,     0,
     106,     0,     0,     0,     0,    77,    78,    79,    73,     0,
      80,     0,     0,     0,    81,    82,     0,     0,     0,    74,
      75,     0,     0,     0,     0,     0,     0,    68,     0,    69,
      70,    71,    72,    76,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    78,    79,    73,     0,    80,     0,     0,
       0,    81,    82,     0,     0,     0,    74,    75,     0,     0,
       0,     0,     0,     0,    68,     0,    69,    70,    71,    72,
     129,     0,     0,     0,     0,     0,     0,     1,     2,    77,
      78,    79,    73,     3,    80,     0,     0,     0,    81,    82,
       4,     0,     0,    74,    75,     0,     5,     6,     0,     7,
       8,     0,     9,    10,    11,    12,     0,   131,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,    79,     0,
     120,    80,   121,     1,     2,    81,    82,     0,     0,     3,
       0,    14,     0,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     5,     6,     0,     7,     8,     0,     9,    10,
      11,    12,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     3,     0,     0,     0,    13,     0,     2,     4,
       0,     0,     0,     3,     0,     5,     6,    14,     7,     8,
       4,     9,    10,    11,    12,     0,     5,     6,     0,     7,
       8,     0,     9,    10,    11,    12,     0,     0,     0,   219,
       0,   121,     0,     0,     0,     0,     0,     0,     0,   216,
      14
};

static const yytype_int16 yycheck[] =
{
      57,    13,    34,    48,   106,    76,    57,   123,    20,    49,
      77,    78,    79,    80,    81,    82,    73,    74,    75,    76,
      58,   121,   120,    60,    28,   114,   172,   267,    42,    14,
       3,    63,    61,   179,     3,     3,    46,     3,    48,    54,
      46,   187,    48,    55,     4,    50,     0,    57,    63,   106,
      35,    63,    50,    67,   190,   106,    16,     3,   129,   116,
     131,    66,     3,    23,    57,    51,    26,   203,    54,    30,
      31,   311,   129,    46,   131,   112,    50,   114,    46,   150,
      46,   121,    48,   323,    57,   152,   153,   154,   120,   178,
     119,    57,   149,   150,    51,     0,     3,    54,   149,   170,
       3,   113,   134,    54,   220,    46,   118,    48,   120,    64,
      65,    16,    63,   170,   260,   215,    21,    22,    23,   123,
     177,   219,    47,   194,    51,   261,   177,    54,    50,   265,
      43,    44,   172,   190,    57,    58,    59,   194,     4,   179,
      46,   178,    48,    46,   155,   156,   203,   187,    50,    52,
      16,    46,   254,    48,    57,   222,    61,    23,    50,   295,
      26,    50,   200,    39,    40,    50,   223,   157,   158,   214,
       4,    76,   223,    47,    54,   215,   312,   313,   314,   315,
     163,   164,    16,    60,    49,    51,    61,   219,   324,    23,
      62,    41,    26,    66,    47,    66,   267,   254,   269,    66,
      54,   272,   273,   254,   261,    32,    33,    34,   265,    47,
     267,     3,   269,     3,   119,   272,   273,    51,    63,    46,
     260,    48,    52,    52,   129,    46,    53,    63,    52,     3,
     287,    35,    36,    37,    38,    46,   287,    46,   295,   310,
     311,   159,   160,   161,   162,    46,   258,    63,    51,   289,
      47,    47,   323,   310,   311,   312,   313,   314,   315,    47,
      49,    47,    49,    54,    27,    63,   323,   324,     3,    52,
       5,     6,     7,     8,    52,    10,    11,    12,    13,    14,
      47,    63,    17,    18,    19,    20,    21,    49,     4,    24,
      46,    63,    27,     9,    47,    47,    47,    32,    33,    47,
      16,    47,    63,    15,    63,    16,    22,    23,    55,    25,
      26,    46,    28,    29,    30,    31,    51,   112,   258,   100,
      55,    56,    57,   174,   134,    60,   128,   166,    63,    64,
      65,     3,   165,     5,     6,     7,     8,   168,    10,    11,
      12,    13,    14,   169,   129,    17,    18,    19,    20,    21,
     167,    -1,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    55,    56,    57,    -1,    -1,    60,    -1,
      -1,    63,    64,    65,     3,    -1,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    -1,    -1,    17,    18,
      19,    20,    21,    -1,    -1,    24,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,     3,
       4,     5,     6,     7,     8,     9,    55,    56,    57,    -1,
      -1,    60,    16,    -1,    63,    64,    65,    21,    22,    23,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    21,    -1,    60,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    55,    56,
      57,    21,    -1,    60,    -1,    -1,    -1,    64,    65,    -1,
      -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,    46,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    55,    56,    57,    21,    -1,
      60,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
       6,     7,     8,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    21,    -1,    60,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
      46,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    55,
      56,    57,    21,     9,    60,    -1,    -1,    -1,    64,    65,
      16,    -1,    -1,    32,    33,    -1,    22,    23,    -1,    25,
      26,    -1,    28,    29,    30,    31,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    -1,
      46,    60,    48,     3,     4,    64,    65,    -1,    -1,     9,
      -1,    57,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    22,    23,    -1,    25,    26,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    46,    -1,     4,    16,
      -1,    -1,    -1,     9,    -1,    22,    23,    57,    25,    26,
      16,    28,    29,    30,    31,    -1,    22,    23,    -1,    25,
      26,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    46,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     9,    16,    22,    23,    25,    26,    28,
      29,    30,    31,    46,    57,    70,    71,    72,    73,    77,
      78,    79,    80,    83,    84,    87,    92,    97,    98,   101,
       3,    94,    97,    80,    99,   100,     0,    72,    81,    82,
      97,    78,    78,    78,     3,    86,    75,   101,    46,    48,
      93,    50,    47,    98,    80,    54,    63,    66,    74,    85,
      50,    50,   116,    78,   103,   104,   105,   106,     3,     5,
       6,     7,     8,    21,    32,    33,    46,    55,    56,    57,
      60,    64,    65,   102,   126,   127,   130,   131,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   147,
      50,     3,    95,    96,    82,    97,    50,   110,   130,   143,
     144,   116,    50,    83,    88,    89,    76,    77,    78,   117,
      46,    48,    97,    98,   107,   108,   109,    47,    54,    46,
     130,    46,   130,   130,    78,   132,   144,   145,   146,   131,
     131,   131,   131,   131,   131,    49,    32,    33,    34,    46,
      48,    53,    57,    58,    59,    64,    65,    43,    44,    35,
      36,    37,    38,    39,    40,    60,    62,    61,    41,    42,
      67,    95,    66,    51,    54,   110,   111,    66,    88,    52,
      90,    91,    97,    51,    89,     3,    10,    11,    12,    13,
      14,    17,    18,    19,    20,    24,    27,    63,   112,   113,
     114,   115,   118,   119,   120,   121,   122,   125,   146,    77,
     103,   108,   102,   109,    46,    48,    45,   106,   132,    46,
      98,   107,    47,    54,    47,     3,   128,   129,   144,   146,
       3,   131,   131,   131,   133,   133,   134,   134,   135,   135,
     135,   135,   136,   136,   137,   138,   139,   140,   141,   146,
      51,   147,    96,    51,    54,   144,    51,   147,    54,    63,
      52,    52,    63,   147,    63,    52,   112,    46,     3,    46,
     123,   146,    46,    46,   116,    51,   112,    63,    47,    47,
      49,   103,   102,    47,   131,   144,    47,    54,    49,    52,
      51,   110,    91,   147,   112,    52,   112,    27,   123,   124,
      63,   146,    63,   146,   146,    47,    49,   144,   143,   112,
      46,    63,    47,    47,    47,    47,   146,   123,   112,   112,
     112,   112,    47,    63,    15,    63,   123,   112
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    74,    73,    75,
      73,    76,    76,    77,    78,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    83,    85,    84,    86,    84,    84,    87,
      87,    88,    88,    89,    90,    90,    91,    91,    91,    93,
      92,    94,    92,    92,    95,    95,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   108,   109,   109,   109,   109,   109,
     110,   110,   110,   111,   111,   112,   112,   112,   112,   112,
     112,   114,   113,   115,   115,   115,   116,   117,   117,   118,
     118,   119,   119,   120,   120,   121,   121,   121,   122,   122,
     122,   123,   123,   124,   125,   125,   125,   125,   126,   126,
     126,   126,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   128,   128,   129,   129,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   131,   131,   132,   133,
     133,   133,   133,   134,   134,   134,   135,   135,   135,   136,
     136,   136,   136,   136,   137,   137,   137,   138,   138,   139,
     139,   140,   140,   141,   141,   142,   142,   143,   143,   144,
     144,   145,   145,   146,   147
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     4,     0,
       3,     0,     1,     3,     1,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     1,     0,     6,     0,     5,     2,     1,
       1,     1,     2,     3,     1,     3,     1,     2,     3,     0,
       6,     0,     5,     2,     1,     3,     1,     3,     2,     1,
       2,     3,     0,     1,     1,     2,     1,     3,     4,     4,
       0,     1,     0,     1,     1,     3,     1,     3,     2,     2,
       0,     1,     1,     1,     2,     3,     3,     3,     4,     4,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     0,     2,     4,     3,     3,     4,     1,     2,     0,
       1,     1,     2,     1,     2,     5,     7,     5,     5,     7,
       5,     0,     1,     5,     3,     2,     2,     3,     1,     1,
       1,     1,     1,     3,     1,     4,     4,     3,     3,     2,
       2,     0,     1,     1,     3,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     1,     4,     2,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: translation_unit  */
#line 45 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      program_root = makeNode(N_PROGRAM, NULL, PTR(A_NODE, current_id), NULL);

      yyval = YY(program_root);
    }
#line 1752 "y.tab.c"
    break;

  case 7: /* @1: %empty  */
#line 66 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = setFunctionDeclaratorSpecifier(PTR(A_ID, yyvsp[0]), PTR(A_SPECIFIER, yyvsp[-1]));

      current_id = id;
      enterScope();

      for (A_ID *p = id->type->field; p != NULL; p = p->link) {
        if (p->name == NULL || p->name[0] == '\0')
          continue;

        p->level = current_level;
        p->prev = current_id;
        current_id = p;
      }

      yyval = YY(id);
    }
#line 1774 "y.tab.c"
    break;

  case 8: /* function_definition: declaration_specifiers declarator @1 compound_statement  */
#line 84 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = setFunctionDeclaratorBody(PTR(A_ID, yyvsp[-1]), PTR(A_NODE, yyvsp[0]));

      leaveScope();
      yyval = YY(id);
    }
#line 1785 "y.tab.c"
    break;

  case 9: /* @2: %empty  */
#line 91 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id =
          setFunctionDeclaratorSpecifier(PTR(A_ID, yyvsp[0]), makeSpecifier(int_type, S_NULL));

      current_id = id;
      enterScope();

      for (A_ID *p = id->type->field; p != NULL; p = p->link) {
        if (p->name == NULL || p->name[0] == '\0')
          continue;

        p->level = current_level;
        p->prev = current_id;
        current_id = p;
      }

      yyval = YY(id);
    }
#line 1808 "y.tab.c"
    break;

  case 10: /* function_definition: declarator @2 compound_statement  */
#line 110 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = setFunctionDeclaratorBody(PTR(A_ID, yyvsp[-1]), PTR(A_NODE, yyvsp[0]));

      leaveScope();
      yyval = YY(id);
    }
#line 1819 "y.tab.c"
    break;

  case 11: /* declaration_list_opt: %empty  */
#line 120 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 1827 "y.tab.c"
    break;

  case 12: /* declaration_list_opt: declaration_list  */
#line 124 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1835 "y.tab.c"
    break;

  case 13: /* declaration: declaration_specifiers init_declarator_list SEMICOLON  */
#line 131 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorListSpecifier(PTR(A_ID, yyvsp[-1]), PTR(A_SPECIFIER, yyvsp[-2])));
    }
#line 1843 "y.tab.c"
    break;

  case 14: /* declaration_specifiers: type_specifier  */
#line 138 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeSpecifier(PTR(A_TYPE, yyvsp[0]), S_NULL));
    }
#line 1851 "y.tab.c"
    break;

  case 15: /* declaration_specifiers: storage_class_specifier  */
#line 142 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeSpecifier(NULL, (S_KIND)yyvsp[0]));
    }
#line 1859 "y.tab.c"
    break;

  case 16: /* declaration_specifiers: type_qualifier  */
#line 146 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Type type_qualifier are not suuported");
      yyval = YY(NULL);
    }
#line 1868 "y.tab.c"
    break;

  case 17: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 151 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(updateSpecifier(PTR(A_SPECIFIER, yyvsp[0]), PTR(A_TYPE, yyvsp[-1]), S_NULL));
    }
#line 1876 "y.tab.c"
    break;

  case 18: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 155 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(updateSpecifier(PTR(A_SPECIFIER, yyvsp[0]), NULL, (S_KIND)yyvsp[-1]));
    }
#line 1884 "y.tab.c"
    break;

  case 19: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 159 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Type type_qualifier are not suuported");
      yyval = yyvsp[0];
    }
#line 1893 "y.tab.c"
    break;

  case 20: /* storage_class_specifier: AUTO_SYM  */
#line 166 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
               { yyval = YY(S_AUTO); }
#line 1899 "y.tab.c"
    break;

  case 21: /* storage_class_specifier: STATIC_SYM  */
#line 167 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                 { yyval = YY(S_STATIC); }
#line 1905 "y.tab.c"
    break;

  case 22: /* storage_class_specifier: TYPEDEF_SYM  */
#line 168 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                  { yyval = YY(S_TYPEDEF); }
#line 1911 "y.tab.c"
    break;

  case 23: /* storage_class_specifier: REGISTER_SYM  */
#line 170 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("register is not supported");
      yyval = YY(S_NULL);
    }
#line 1920 "y.tab.c"
    break;

  case 24: /* storage_class_specifier: EXTERN_SYM  */
#line 175 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("extern is not supported");
      yyval = YY(S_NULL);
    }
#line 1929 "y.tab.c"
    break;

  case 27: /* init_declarator_list: init_declarator  */
#line 188 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1937 "y.tab.c"
    break;

  case 28: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 192 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 1945 "y.tab.c"
    break;

  case 29: /* init_declarator: declarator  */
#line 199 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1953 "y.tab.c"
    break;

  case 33: /* type_specifier: TYPE_IDENTIFIER  */
#line 209 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1961 "y.tab.c"
    break;

  case 34: /* @3: %empty  */
#line 216 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(setTypeStructOrEnumIdentifier((T_KIND)yyvsp[-1], name, ID_STRUCT));
      free(name);
    }
#line 1971 "y.tab.c"
    break;

  case 35: /* struct_specifier: struct_or_union IDENTIFIER @3 LR struct_declaration_list RR  */
#line 222 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 1979 "y.tab.c"
    break;

  case 36: /* @4: %empty  */
#line 226 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeType((T_KIND)yyvsp[0]));
    }
#line 1987 "y.tab.c"
    break;

  case 37: /* struct_specifier: struct_or_union @4 LR struct_declaration_list RR  */
#line 230 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 1995 "y.tab.c"
    break;

  case 38: /* struct_specifier: struct_or_union IDENTIFIER  */
#line 234 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(getTypeOfStructOrEnumIdentifier((T_KIND)yyvsp[-1], name, ID_STRUCT));
      free(name);
    }
#line 2005 "y.tab.c"
    break;

  case 39: /* struct_or_union: STRUCT_SYM  */
#line 242 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                 { yyval = YY(T_STRUCT); }
#line 2011 "y.tab.c"
    break;

  case 40: /* struct_or_union: UNION_SYM  */
#line 243 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                { yyval = YY(T_UNION); }
#line 2017 "y.tab.c"
    break;

  case 41: /* struct_declaration_list: struct_declaration  */
#line 247 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                         { yyval = yyvsp[0]; }
#line 2023 "y.tab.c"
    break;

  case 42: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 249 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-1]), PTR(A_ID, yyvsp[0])));
    }
#line 2031 "y.tab.c"
    break;

  case 43: /* struct_declaration: type_specifier struct_declarator_list SEMICOLON  */
#line 256 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setStructDeclaratorListSpecifier(PTR(A_ID, yyvsp[-1]), PTR(A_TYPE, yyvsp[-2])));
    }
#line 2039 "y.tab.c"
    break;

  case 44: /* struct_declarator_list: struct_declarator  */
#line 262 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                        { yyval = yyvsp[0]; }
#line 2045 "y.tab.c"
    break;

  case 45: /* struct_declarator_list: struct_declarator_list COMMA struct_declarator  */
#line 264 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 2053 "y.tab.c"
    break;

  case 46: /* struct_declarator: declarator  */
#line 270 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                 { yyval = yyvsp[0]; }
#line 2059 "y.tab.c"
    break;

  case 47: /* struct_declarator: COLON constant_expression  */
#line 272 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Bit-fields are not implemented");
      yyval = YY(NULL);
    }
#line 2068 "y.tab.c"
    break;

  case 48: /* struct_declarator: declarator COLON constant_expression  */
#line 277 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Bit-fields are not implemented");
      yyval = YY(NULL);
    }
#line 2077 "y.tab.c"
    break;

  case 49: /* @5: %empty  */
#line 285 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeStructOrEnumIdentifier(T_ENUM, PTR(char, yyvsp[0]), ID_ENUM));
    }
#line 2085 "y.tab.c"
    break;

  case 50: /* enum_specifier: ENUM_SYM IDENTIFIER @5 LR enumerator_list RR  */
#line 289 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 2093 "y.tab.c"
    break;

  case 51: /* @6: %empty  */
#line 293 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeType(T_ENUM));
    }
#line 2101 "y.tab.c"
    break;

  case 52: /* enum_specifier: ENUM_SYM @6 LR enumerator_list RR  */
#line 297 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 2109 "y.tab.c"
    break;

  case 53: /* enum_specifier: ENUM_SYM IDENTIFIER  */
#line 301 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(getTypeOfStructOrEnumIdentifier(T_ENUM, PTR(char, yyvsp[0]), ID_ENUM));
    }
#line 2117 "y.tab.c"
    break;

  case 54: /* enumerator_list: enumerator  */
#line 307 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                 { yyval = yyvsp[0]; }
#line 2123 "y.tab.c"
    break;

  case 55: /* enumerator_list: enumerator_list COMMA enumerator  */
#line 309 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 2131 "y.tab.c"
    break;

  case 56: /* enumerator: IDENTIFIER  */
#line 316 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      A_ID *id = makeIdentifier(name);
      free(name);

      yyval = YY(setDeclaratorKind(id, ID_ENUM_LITERAL));
    }
#line 2143 "y.tab.c"
    break;

  case 58: /* declarator: pointer direct_declarator  */
#line 328 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[0]), PTR(A_TYPE, yyvsp[-1])));
    }
#line 2151 "y.tab.c"
    break;

  case 59: /* declarator: direct_declarator  */
#line 332 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2159 "y.tab.c"
    break;

  case 60: /* pointer: STAR type_qualifier_list_opt  */
#line 339 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeType(T_POINTER));
    }
#line 2167 "y.tab.c"
    break;

  case 61: /* pointer: STAR type_qualifier_list_opt pointer  */
#line 343 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[0]), makeType(T_POINTER)));
    }
#line 2175 "y.tab.c"
    break;

  case 66: /* direct_declarator: IDENTIFIER  */
#line 360 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);

      A_ID *id = makeIdentifier(name);
      free(name);

      yyval = YY(id);
    }
#line 2188 "y.tab.c"
    break;

  case 68: /* direct_declarator: direct_declarator LB constant_expression_opt RB  */
#line 370 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[-3]),
                                       setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1]))));
    }
#line 2197 "y.tab.c"
    break;

  case 69: /* direct_declarator: direct_declarator LP parameter_type_list_opt RP  */
#line 375 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[-3]),
                                       setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1]))));
    }
#line 2206 "y.tab.c"
    break;

  case 70: /* constant_expression_opt: %empty  */
#line 383 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2214 "y.tab.c"
    break;

  case 71: /* constant_expression_opt: constant_expression  */
#line 387 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2222 "y.tab.c"
    break;

  case 72: /* parameter_type_list_opt: %empty  */
#line 394 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2230 "y.tab.c"
    break;

  case 73: /* parameter_type_list_opt: parameter_type_list  */
#line 398 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2238 "y.tab.c"
    break;

  case 76: /* parameter_list: parameter_declaration  */
#line 410 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2246 "y.tab.c"
    break;

  case 77: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 414 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 2254 "y.tab.c"
    break;

  case 78: /* parameter_declaration: declaration_specifiers declarator  */
#line 421 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setParameterDeclaratorSpecifier(PTR(A_ID, yyvsp[0]), PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2262 "y.tab.c"
    break;

  case 79: /* parameter_declaration: declaration_specifiers abstract_declarator_opt  */
#line 425 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = makeDummyIdentifier();

      setDeclaratorElementType(id, PTR(A_TYPE, yyvsp[0]));

      yyval = YY(setParameterDeclaratorSpecifier(id, PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2274 "y.tab.c"
    break;

  case 80: /* abstract_declarator_opt: %empty  */
#line 436 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2282 "y.tab.c"
    break;

  case 81: /* abstract_declarator_opt: abstract_declarator  */
#line 440 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2290 "y.tab.c"
    break;

  case 82: /* abstract_declarator: pointer  */
#line 447 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2298 "y.tab.c"
    break;

  case 83: /* abstract_declarator: direct_abstract_declarator  */
#line 451 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2306 "y.tab.c"
    break;

  case 84: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 455 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[0]), PTR(A_TYPE, yyvsp[-1])));
    }
#line 2314 "y.tab.c"
    break;

  case 85: /* direct_abstract_declarator: LP abstract_declarator RP  */
#line 462 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[-1];
    }
#line 2322 "y.tab.c"
    break;

  case 86: /* direct_abstract_declarator: LB constant_expression_opt RB  */
#line 466 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1])));
    }
#line 2330 "y.tab.c"
    break;

  case 87: /* direct_abstract_declarator: LP parameter_type_list_opt RP  */
#line 470 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1])));
    }
#line 2338 "y.tab.c"
    break;

  case 88: /* direct_abstract_declarator: direct_abstract_declarator LB constant_expression_opt RB  */
#line 474 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[-3]),
                                 setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1]))));
    }
#line 2347 "y.tab.c"
    break;

  case 89: /* direct_abstract_declarator: direct_abstract_declarator LP parameter_type_list_opt RP  */
#line 479 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[-3]),
                                 setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1]))));
    }
#line 2356 "y.tab.c"
    break;

  case 95: /* statement: labeled_statement  */
#line 497 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                        { yyval = yyvsp[0]; }
#line 2362 "y.tab.c"
    break;

  case 96: /* statement: scoped_compound_statement  */
#line 499 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2370 "y.tab.c"
    break;

  case 97: /* statement: expression_statement  */
#line 503 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2378 "y.tab.c"
    break;

  case 98: /* statement: selection_statement  */
#line 506 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2384 "y.tab.c"
    break;

  case 99: /* statement: iteration_statement  */
#line 507 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2390 "y.tab.c"
    break;

  case 100: /* statement: jump_statement  */
#line 509 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2398 "y.tab.c"
    break;

  case 101: /* $@7: %empty  */
#line 516 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      enterScope();
    }
#line 2406 "y.tab.c"
    break;

  case 102: /* scoped_compound_statement: $@7 compound_statement  */
#line 520 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
      leaveScope();
    }
#line 2415 "y.tab.c"
    break;

  case 103: /* labeled_statement: CASE_SYM constant_expression COLON statement  */
#line 528 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LABEL_CASE, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2423 "y.tab.c"
    break;

  case 104: /* labeled_statement: DEFAULT_SYM COLON statement  */
#line 532 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LABEL_DEFAULT, NULL, NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2431 "y.tab.c"
    break;

  case 106: /* compound_statement: LR declaration_list_opt statement_list_opt RR  */
#line 540 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_COMPOUND, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[-1])));

      compound_root = PTR(A_NODE, yyval);
    }
#line 2441 "y.tab.c"
    break;

  case 107: /* declaration_list: declaration  */
#line 549 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2449 "y.tab.c"
    break;

  case 108: /* declaration_list: declaration_list declaration  */
#line 553 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-1]), PTR(A_ID, yyvsp[0])));
    }
#line 2457 "y.tab.c"
    break;

  case 109: /* statement_list_opt: %empty  */
#line 560 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL));
    }
#line 2465 "y.tab.c"
    break;

  case 110: /* statement_list_opt: statement_list  */
#line 564 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2473 "y.tab.c"
    break;

  case 111: /* statement_list: statement  */
#line 571 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LIST, PTR(A_NODE, yyvsp[0]), NULL,
                       makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL)));
    }
#line 2482 "y.tab.c"
    break;

  case 112: /* statement_list: statement_list statement  */
#line 576 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNodeList(N_STMT_LIST, PTR(A_NODE, yyvsp[-1]), PTR(A_NODE, yyvsp[0])));
    }
#line 2490 "y.tab.c"
    break;

  case 113: /* expression_statement: SEMICOLON  */
#line 583 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_EMPTY, NULL, NULL, NULL));
    }
#line 2498 "y.tab.c"
    break;

  case 114: /* expression_statement: expression SEMICOLON  */
#line 587 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_EXPRESSION, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2506 "y.tab.c"
    break;

  case 115: /* selection_statement: IF_SYM LP expression RP statement  */
#line 594 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_IF, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2514 "y.tab.c"
    break;

  case 116: /* selection_statement: IF_SYM LP expression RP statement ELSE_SYM statement  */
#line 598 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_IF_ELSE, PTR(A_NODE, yyvsp[-4]), PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2522 "y.tab.c"
    break;

  case 117: /* selection_statement: SWITCH_SYM LP expression RP statement  */
#line 602 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_SWITCH, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2530 "y.tab.c"
    break;

  case 118: /* iteration_statement: WHILE_SYM LP expression RP statement  */
#line 609 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_WHILE, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2538 "y.tab.c"
    break;

  case 119: /* iteration_statement: DO_SYM statement WHILE_SYM LP expression RP SEMICOLON  */
#line 613 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_DO, PTR(A_NODE, yyvsp[-5]), NULL, PTR(A_NODE, yyvsp[-2])));
    }
#line 2546 "y.tab.c"
    break;

  case 120: /* iteration_statement: FOR_SYM LP for_expression RP statement  */
#line 617 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_FOR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2554 "y.tab.c"
    break;

  case 121: /* expression_opt: %empty  */
#line 624 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2562 "y.tab.c"
    break;

  case 122: /* expression_opt: expression  */
#line 628 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2570 "y.tab.c"
    break;

  case 123: /* for_expression: expression_opt SEMICOLON expression_opt SEMICOLON expression_opt  */
#line 635 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_FOR_EXP, PTR(A_NODE, yyvsp[-4]), PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2578 "y.tab.c"
    break;

  case 124: /* jump_statement: RETURN_SYM expression_opt SEMICOLON  */
#line 642 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_RETURN, NULL, PTR(A_NODE, yyvsp[-1]), NULL));

      statement_root = PTR(A_NODE, yyval);
    }
#line 2588 "y.tab.c"
    break;

  case 125: /* jump_statement: CONTINUE_SYM SEMICOLON  */
#line 648 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_CONTINUE, NULL, NULL, NULL));
    }
#line 2596 "y.tab.c"
    break;

  case 126: /* jump_statement: BREAK_SYM SEMICOLON  */
#line 652 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_BREAK, NULL, NULL, NULL));
    }
#line 2604 "y.tab.c"
    break;

  case 128: /* primary_expression: IDENTIFIER  */
#line 660 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      A_ID *id = getIdentifierDeclared(name);
      free(name);

      yyval = YY(makeNode(N_EXP_IDENT, NULL, PTR(A_NODE, id), NULL));
    }
#line 2616 "y.tab.c"
    break;

  case 129: /* primary_expression: INTEGER_CONSTANT  */
#line 668 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_INT_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));

      A_NODE *node = PTR(A_NODE, yyval);
      logMsg(LOG_DEBUG, "N_EXP_INT_CONST: %lld", (long long)(intptr_t)node->clink);
    }
#line 2627 "y.tab.c"
    break;

  case 130: /* primary_expression: FLOAT_CONSTANT  */
#line 675 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_FLOAT_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2635 "y.tab.c"
    break;

  case 131: /* primary_expression: CHARACTER_CONSTANT  */
#line 679 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_CHAR_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2643 "y.tab.c"
    break;

  case 132: /* primary_expression: STRING_LITERAL  */
#line 683 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_STRING_LITERAL, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2651 "y.tab.c"
    break;

  case 133: /* primary_expression: LP expression RP  */
#line 687 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[-1];
    }
#line 2659 "y.tab.c"
    break;

  case 134: /* postfix_expression: primary_expression  */
#line 694 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2667 "y.tab.c"
    break;

  case 135: /* postfix_expression: postfix_expression LB expression RB  */
#line 698 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ARRAY, PTR(A_NODE, yyvsp[-3]), NULL, PTR(A_NODE, yyvsp[-1])));
    }
#line 2675 "y.tab.c"
    break;

  case 136: /* postfix_expression: postfix_expression LP arg_expression_list_opt RP  */
#line 702 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_FUNCTION_CALL, PTR(A_NODE, yyvsp[-3]), NULL, PTR(A_NODE, yyvsp[-1])));
    }
#line 2683 "y.tab.c"
    break;

  case 137: /* postfix_expression: postfix_expression PERIOD IDENTIFIER  */
#line 706 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(makeNode(N_EXP_STRUCT, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, name)));
    }
#line 2692 "y.tab.c"
    break;

  case 138: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 711 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(makeNode(N_EXP_ARROW, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, name)));
    }
#line 2701 "y.tab.c"
    break;

  case 139: /* postfix_expression: postfix_expression PLUSPLUS  */
#line 716 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_POST_INC, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2709 "y.tab.c"
    break;

  case 140: /* postfix_expression: postfix_expression MINUSMINUS  */
#line 720 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_POST_DEC, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2717 "y.tab.c"
    break;

  case 141: /* arg_expression_list_opt: %empty  */
#line 727 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_ARG_LIST_NIL, NULL, NULL, NULL));
    }
#line 2725 "y.tab.c"
    break;

  case 142: /* arg_expression_list_opt: arg_expression_list  */
#line 730 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2731 "y.tab.c"
    break;

  case 143: /* arg_expression_list: assignment_expression  */
#line 735 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_ARG_LIST, PTR(A_NODE, yyvsp[0]), NULL,
                       makeNode(N_ARG_LIST_NIL, NULL, NULL, NULL)));
    }
#line 2740 "y.tab.c"
    break;

  case 144: /* arg_expression_list: arg_expression_list COMMA assignment_expression  */
#line 740 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNodeList(N_ARG_LIST, PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2748 "y.tab.c"
    break;

  case 145: /* unary_expression: postfix_expression  */
#line 747 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2756 "y.tab.c"
    break;

  case 146: /* unary_expression: PLUSPLUS unary_expression  */
#line 751 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_PRE_INC, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2764 "y.tab.c"
    break;

  case 147: /* unary_expression: MINUSMINUS unary_expression  */
#line 755 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_PRE_DEC, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2772 "y.tab.c"
    break;

  case 148: /* unary_expression: AMP cast_expression  */
#line 759 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_AMP, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2780 "y.tab.c"
    break;

  case 149: /* unary_expression: STAR cast_expression  */
#line 763 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_STAR, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2788 "y.tab.c"
    break;

  case 150: /* unary_expression: EXCL cast_expression  */
#line 767 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_NOT, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2796 "y.tab.c"
    break;

  case 151: /* unary_expression: MINUS cast_expression  */
#line 771 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MINUS, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2804 "y.tab.c"
    break;

  case 153: /* unary_expression: PLUS cast_expression  */
#line 776 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2812 "y.tab.c"
    break;

  case 154: /* unary_expression: SIZEOF_SYM unary_expression  */
#line 780 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_SIZE_EXP, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2820 "y.tab.c"
    break;

  case 155: /* unary_expression: SIZEOF_SYM LP type_name RP  */
#line 784 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_SIZE_TYPE, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2828 "y.tab.c"
    break;

  case 156: /* cast_expression: unary_expression  */
#line 791 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2836 "y.tab.c"
    break;

  case 157: /* cast_expression: LP type_name RP cast_expression  */
#line 795 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_CAST, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2844 "y.tab.c"
    break;

  case 158: /* type_name: declaration_specifiers abstract_declarator_opt  */
#line 802 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeNameSpecifier(PTR(A_TYPE, yyvsp[0]), PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2852 "y.tab.c"
    break;

  case 159: /* multiplicative_expression: cast_expression  */
#line 809 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2860 "y.tab.c"
    break;

  case 160: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 813 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MUL, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2868 "y.tab.c"
    break;

  case 161: /* multiplicative_expression: multiplicative_expression SLASH cast_expression  */
#line 817 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_DIV, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2876 "y.tab.c"
    break;

  case 162: /* multiplicative_expression: multiplicative_expression PERCENT cast_expression  */
#line 821 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MOD, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2884 "y.tab.c"
    break;

  case 163: /* additive_expression: multiplicative_expression  */
#line 828 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2892 "y.tab.c"
    break;

  case 164: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 832 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ADD, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2900 "y.tab.c"
    break;

  case 165: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 836 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_SUB, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2908 "y.tab.c"
    break;

  case 166: /* shift_expression: additive_expression  */
#line 842 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2914 "y.tab.c"
    break;

  case 169: /* relational_expression: shift_expression  */
#line 849 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2922 "y.tab.c"
    break;

  case 170: /* relational_expression: relational_expression LSS shift_expression  */
#line 853 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_LSS, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2930 "y.tab.c"
    break;

  case 171: /* relational_expression: relational_expression GTR shift_expression  */
#line 857 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_GTR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2938 "y.tab.c"
    break;

  case 172: /* relational_expression: relational_expression LEQ shift_expression  */
#line 861 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_LEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2946 "y.tab.c"
    break;

  case 173: /* relational_expression: relational_expression GEQ shift_expression  */
#line 865 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_GEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2954 "y.tab.c"
    break;

  case 174: /* equality_expression: relational_expression  */
#line 872 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2962 "y.tab.c"
    break;

  case 175: /* equality_expression: equality_expression EQL relational_expression  */
#line 876 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_EQL, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2970 "y.tab.c"
    break;

  case 176: /* equality_expression: equality_expression NEQ relational_expression  */
#line 880 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_NEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2978 "y.tab.c"
    break;

  case 177: /* AND_expression: equality_expression  */
#line 886 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2984 "y.tab.c"
    break;

  case 179: /* exclusive_OR_expression: AND_expression  */
#line 891 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                     { yyval = yyvsp[0]; }
#line 2990 "y.tab.c"
    break;

  case 181: /* inclusive_OR_expression: exclusive_OR_expression  */
#line 896 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                              { yyval = yyvsp[0]; }
#line 2996 "y.tab.c"
    break;

  case 183: /* logical_AND_expression: inclusive_OR_expression  */
#line 901 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                              { yyval = yyvsp[0]; }
#line 3002 "y.tab.c"
    break;

  case 184: /* logical_AND_expression: logical_AND_expression AMPAMP inclusive_OR_expression  */
#line 903 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_AND, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3010 "y.tab.c"
    break;

  case 185: /* logical_OR_expression: logical_AND_expression  */
#line 909 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                             { yyval = yyvsp[0]; }
#line 3016 "y.tab.c"
    break;

  case 186: /* logical_OR_expression: logical_OR_expression BARBAR logical_AND_expression  */
#line 911 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_OR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3024 "y.tab.c"
    break;

  case 189: /* assignment_expression: conditional_expression  */
#line 923 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 3032 "y.tab.c"
    break;

  case 190: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 927 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ASSIGN, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3040 "y.tab.c"
    break;

  case 193: /* expression: comma_expression  */
#line 939 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
      expression_root = PTR(A_NODE, yyvsp[0]);
    }
#line 3049 "y.tab.c"
    break;


#line 3053 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 948 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"

int yyerror(const char *s) {
  logMsg(LOG_ERROR, "Syntax error at line %d: %s", line_no, s);
  return 0;
}
