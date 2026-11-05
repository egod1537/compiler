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
  YYSYMBOL_struct_or_union = 85,           /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 86,   /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 87,        /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 88,  /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 89,    /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 90,         /* struct_declarator  */
  YYSYMBOL_enum_specifier = 91,            /* enum_specifier  */
  YYSYMBOL_enumerator_list = 92,           /* enumerator_list  */
  YYSYMBOL_enumerator = 93,                /* enumerator  */
  YYSYMBOL_declarator = 94,                /* declarator  */
  YYSYMBOL_pointer = 95,                   /* pointer  */
  YYSYMBOL_type_qualifier_list_opt = 96,   /* type_qualifier_list_opt  */
  YYSYMBOL_type_qualifier_list = 97,       /* type_qualifier_list  */
  YYSYMBOL_direct_declarator = 98,         /* direct_declarator  */
  YYSYMBOL_constant_expression_opt = 99,   /* constant_expression_opt  */
  YYSYMBOL_parameter_type_list_opt = 100,  /* parameter_type_list_opt  */
  YYSYMBOL_parameter_type_list = 101,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 102,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 103,    /* parameter_declaration  */
  YYSYMBOL_abstract_declarator_opt = 104,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 105,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 106, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 107,              /* initializer  */
  YYSYMBOL_initializer_list = 108,         /* initializer_list  */
  YYSYMBOL_statement = 109,                /* statement  */
  YYSYMBOL_scoped_compound_statement = 110, /* scoped_compound_statement  */
  YYSYMBOL_111_3 = 111,                    /* $@3  */
  YYSYMBOL_labeled_statement = 112,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 113,       /* compound_statement  */
  YYSYMBOL_declaration_list = 114,         /* declaration_list  */
  YYSYMBOL_statement_list_opt = 115,       /* statement_list_opt  */
  YYSYMBOL_statement_list = 116,           /* statement_list  */
  YYSYMBOL_expression_statement = 117,     /* expression_statement  */
  YYSYMBOL_selection_statement = 118,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 119,      /* iteration_statement  */
  YYSYMBOL_120_4 = 120,                    /* @4  */
  YYSYMBOL_expression_opt = 121,           /* expression_opt  */
  YYSYMBOL_for_expression = 122,           /* for_expression  */
  YYSYMBOL_jump_statement = 123,           /* jump_statement  */
  YYSYMBOL_primary_expression = 124,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 125,       /* postfix_expression  */
  YYSYMBOL_arg_expression_list_opt = 126,  /* arg_expression_list_opt  */
  YYSYMBOL_arg_expression_list = 127,      /* arg_expression_list  */
  YYSYMBOL_unary_expression = 128,         /* unary_expression  */
  YYSYMBOL_cast_expression = 129,          /* cast_expression  */
  YYSYMBOL_type_name = 130,                /* type_name  */
  YYSYMBOL_multiplicative_expression = 131, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 132,      /* additive_expression  */
  YYSYMBOL_shift_expression = 133,         /* shift_expression  */
  YYSYMBOL_relational_expression = 134,    /* relational_expression  */
  YYSYMBOL_equality_expression = 135,      /* equality_expression  */
  YYSYMBOL_AND_expression = 136,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 137,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 138,  /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 139,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 140,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 141,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 142,    /* assignment_expression  */
  YYSYMBOL_comma_expression = 143,         /* comma_expression  */
  YYSYMBOL_expression = 144,               /* expression  */
  YYSYMBOL_constant_expression = 145       /* constant_expression  */
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
#define YYLAST   769

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  196
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  330

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
       0,    44,    44,    48,    49,    53,    54,    61,    60,    86,
      85,   115,   118,   125,   132,   136,   140,   141,   145,   149,
     153,   154,   155,   156,   157,   161,   162,   166,   170,   177,
     181,   185,   186,   187,   194,   195,   196,   200,   201,   205,
     206,   210,   214,   215,   216,   217,   221,   222,   226,   227,
     228,   232,   233,   234,   238,   239,   243,   244,   248,   252,
     259,   263,   270,   271,   275,   276,   280,   289,   290,   295,
     304,   307,   315,   318,   325,   326,   330,   334,   341,   345,
     357,   360,   367,   368,   369,   373,   374,   375,   376,   377,
     381,   382,   383,   387,   388,   392,   393,   397,   401,   402,
     403,   411,   411,   422,   423,   424,   428,   437,   441,   449,
     452,   459,   464,   471,   475,   482,   486,   490,   494,   498,
     503,   502,   511,   514,   521,   525,   531,   532,   533,   537,
     545,   552,   553,   554,   555,   562,   566,   570,   571,   572,
     573,   577,   584,   585,   589,   590,   594,   598,   602,   606,
     610,   614,   618,   622,   623,   627,   628,   632,   636,   640,
     641,   645,   649,   653,   657,   664,   668,   672,   679,   680,
     681,   685,   689,   693,   697,   701,   708,   712,   716,   723,
     724,   728,   729,   733,   734,   738,   739,   746,   747,   754,
     755,   759,   763,   770,   771,   775,   783
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
  "init_declarator", "type_specifier", "struct_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "declarator", "pointer", "type_qualifier_list_opt",
  "type_qualifier_list", "direct_declarator", "constant_expression_opt",
  "parameter_type_list_opt", "parameter_type_list", "parameter_list",
  "parameter_declaration", "abstract_declarator_opt",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "scoped_compound_statement", "$@3",
  "labeled_statement", "compound_statement", "declaration_list",
  "statement_list_opt", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "@4", "expression_opt",
  "for_expression", "jump_statement", "primary_expression",
  "postfix_expression", "arg_expression_list_opt", "arg_expression_list",
  "unary_expression", "cast_expression", "type_name",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "AND_expression",
  "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "comma_expression",
  "expression", "constant_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-245)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-111)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     679,  -245,  -245,  -245,    24,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,    40,    89,    44,   679,  -245,  -245,  -245,
      40,   283,   283,   283,  -245,    26,  -245,  -245,    36,     6,
      48,    60,    64,  -245,    67,    89,  -245,  -245,    -6,  -245,
     -16,  -245,  -245,  -245,   111,   339,   113,     6,   283,   546,
      60,    65,    19,  -245,  -245,  -245,  -245,    40,  -245,   509,
     113,   339,   339,   339,   160,  -245,   105,   283,  -245,   146,
      99,  -245,    94,  -245,  -245,  -245,  -245,  -245,  -245,   583,
     620,   620,   435,   546,   546,   546,   546,   546,   546,   122,
    -245,   270,  -245,  -245,    79,   -28,    98,   130,   114,   124,
     123,   112,   156,    -2,  -245,  -245,    55,   546,  -245,    60,
    -245,   135,   509,  -245,   139,  -245,  -245,  -245,   480,  -245,
    -245,  -245,  -245,   546,    -3,  -245,   154,   264,  -245,    40,
     283,   633,   546,  -245,    32,  -245,  -245,    23,  -245,   723,
     435,  -245,   546,  -245,  -245,    -1,   166,  -245,   153,   167,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,   218,
     546,   546,   219,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,  -245,  -245,  -245,  -245,    56,   546,  -245,  -245,
     105,  -245,   546,   171,   161,   546,   162,   179,   390,   187,
     234,   194,   546,   195,   196,  -245,  -245,  -245,   113,  -245,
     193,   327,  -245,  -245,  -245,  -245,   182,  -245,   199,   201,
     200,    23,   283,   546,  -245,  -245,   203,   712,    81,  -245,
     546,   546,  -245,  -245,   210,   204,  -245,   211,  -245,  -245,
    -245,  -245,    79,    79,   -28,   -28,    98,    98,    98,    98,
     130,   130,   114,   124,   123,   112,   156,   207,  -245,   472,
    -245,  -245,  -245,   390,  -245,   209,  -245,   390,   235,   546,
     205,   546,   216,  -245,   546,   546,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,   226,   214,  -245,  -245,  -245,  -245,   546,
    -245,   546,  -245,  -245,  -245,   390,  -245,   240,   217,   242,
    -245,   243,  -245,   246,   247,  -245,  -245,  -245,  -245,  -245,
     546,   546,   390,   390,   390,   390,   248,   237,  -245,   286,
    -245,  -245,   244,   546,   390,   390,  -245,  -245,  -245,  -245
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    66,    33,    20,     0,    21,    37,    22,    38,    23,
      24,    25,    26,     0,    62,     0,     2,     3,     5,     6,
       0,    15,    16,    14,    31,     0,    32,     9,     0,    59,
      53,     0,     0,    64,    60,    63,     1,     4,     0,    27,
      29,    18,    19,    17,    36,     0,     0,    58,    72,    70,
       0,    56,     0,    54,    67,    61,    65,     0,    13,     0,
       0,     0,    43,    42,     0,    39,     0,    11,    10,    80,
       0,    73,    74,    76,   129,   130,   131,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   146,   157,   161,   165,   168,   171,   176,   179,   181,
     183,   185,   187,   189,   196,    71,     0,     0,    52,     0,
      28,    29,     0,    30,   157,   191,    90,     8,     0,    45,
      44,    35,    40,     0,     0,    46,    48,   101,   107,     0,
      12,    72,    70,    78,    82,    79,    81,    83,    69,     0,
       0,   155,     0,   147,   148,   159,     0,   193,   195,     0,
     151,   153,   150,   149,   154,   152,    68,   140,   141,     0,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,    57,    55,    93,     0,     0,    34,    49,
       0,    41,     0,   129,     0,     0,     0,     0,   101,     0,
       0,     0,   122,     0,     0,   113,   111,    96,     0,    95,
       0,   101,    97,    98,    99,   100,     0,   108,     0,     0,
       0,    84,    72,    70,    75,    77,     0,    72,    82,   160,
       0,     0,   134,   139,     0,   143,   144,     0,   138,   162,
     163,   164,   166,   167,   169,   170,   172,   173,   174,   175,
     177,   178,   180,   182,   184,   186,   188,     0,    91,     0,
     192,    47,    50,   101,   127,     0,   126,   101,     0,   122,
       0,     0,     0,   123,     0,     0,   102,   106,   112,   114,
      87,    85,    86,     0,     0,   156,   158,   194,   137,     0,
     136,     0,    92,    94,   105,   101,   104,     0,     0,     0,
     128,     0,   125,     0,     0,    89,    88,   145,   190,   103,
       0,   122,   101,   101,   101,   101,     0,     0,   120,   115,
     117,   118,     0,   122,   101,   101,   119,   124,   121,   116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -245,  -245,  -245,   282,  -245,  -245,  -245,  -245,   -43,    10,
    -245,    27,  -245,   260,    71,  -245,  -245,   261,   -22,    96,
    -245,   136,  -245,   275,   222,    -8,   -31,  -245,  -245,   -17,
    -124,   -44,  -245,  -245,   197,  -245,   -41,  -115,  -103,  -245,
     -86,  -245,  -245,  -245,   -53,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -244,  -245,  -245,  -245,  -245,  -245,  -245,   -59,
     -70,   202,     3,    11,    47,    13,   173,   175,   172,   174,
     176,  -245,   -48,   -57,  -245,   -76,   -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    15,    16,    17,    18,    60,    46,   127,    19,    69,
      21,    22,    38,    39,    23,    24,    25,    64,    65,    66,
     124,   125,    26,    52,    53,    27,    28,    34,    35,    29,
      89,   218,    71,    72,    73,   135,   219,   137,   113,   186,
     206,   207,   208,   209,    68,   130,   210,   211,   212,   213,
     214,   324,   272,   299,   215,    90,    91,   234,   235,    92,
      93,   146,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   115,   147,   148,   216,   105
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     114,   104,   116,    55,    70,    32,   149,   117,   220,   185,
      20,    47,    40,   150,   151,   152,   153,   154,   155,   221,
     141,   143,   144,   114,   128,   298,    20,    30,   136,    44,
     183,    41,    42,    43,    -7,     1,   166,   167,   134,     1,
     180,    33,   122,     1,    36,   227,   189,   132,    57,   111,
      59,   190,    48,   114,    49,   116,    14,    58,   126,   104,
     191,   133,    56,    51,   149,   181,   149,   317,   114,   222,
     108,   223,    62,   109,    31,   104,    45,   129,   131,   327,
     132,   114,    13,   114,   104,   237,    13,   217,    62,    62,
      62,    62,   145,   239,   240,   241,   122,    14,    50,   284,
     134,   114,   114,   236,   229,   257,   182,   258,     1,   109,
     259,    54,   268,   221,   228,   262,    63,    47,   265,    11,
      12,   111,   114,    32,    14,   278,   273,   227,   114,   132,
     260,   107,    63,    63,    63,    63,   163,   164,   165,   114,
     129,   168,   169,   114,   104,    62,   138,   104,   139,     1,
     145,    13,   114,   174,   175,   276,   293,   123,   119,   120,
     286,    61,    14,    67,     2,   170,   171,   172,   173,   242,
     243,   156,   114,   178,   287,   104,     4,   294,   283,   244,
     245,   296,   126,     6,   176,   177,     8,   250,   251,    63,
      11,    12,   131,   273,   132,   301,   228,   179,   303,   304,
     114,    59,   116,    14,   114,   187,   192,   231,   114,   309,
     114,   121,   114,   230,   232,   114,   114,   246,   247,   248,
     249,   233,   238,   263,   264,   266,   318,   319,   320,   321,
     114,   267,   307,   269,   316,   273,   114,   270,   328,   329,
     271,   274,   275,   308,   277,   279,   280,   273,   281,   282,
     285,   114,   114,   114,   114,   114,   114,   288,   289,   291,
     290,   295,   297,   306,   114,   114,   114,   193,   300,    75,
      76,    77,    78,   305,   194,   195,   196,   197,   198,   302,
     311,   199,   200,   201,   202,    79,   310,     2,   203,   312,
     313,   204,     3,   314,   315,   322,    80,    81,    37,     4,
     323,   325,   157,   158,   159,     5,     6,   326,     7,     8,
      82,     9,    10,    11,    12,  -109,   160,   110,   161,    83,
      84,    85,   118,   162,    86,   106,   261,   205,    87,    88,
     193,   184,    75,    76,    77,    78,   225,   194,   195,   196,
     197,   198,   226,     2,   199,   200,   201,   202,    79,   252,
     254,   203,   253,   255,   204,     4,   256,     0,     0,    80,
      81,     0,     6,     0,     0,     8,     0,     0,     0,    11,
      12,     0,     0,    82,     0,     0,     0,     0,  -110,     0,
       0,     0,    83,    84,    85,     0,     0,    86,     0,     0,
     205,    87,    88,   193,     0,    75,    76,    77,    78,     0,
     194,   195,   196,   197,   198,     0,     0,   199,   200,   201,
     202,    79,     0,     0,   203,     0,     0,   204,     0,     0,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,    74,     2,
      75,    76,    77,    78,     3,    83,    84,    85,     0,     0,
      86,     4,     0,   205,    87,    88,    79,     5,     6,     0,
       7,     8,     0,     9,    10,    11,    12,    80,    81,     0,
       0,     0,     0,     0,     0,    74,     0,    75,    76,    77,
      78,    82,     0,     0,     2,     0,     0,     0,     0,     0,
      83,    84,    85,    79,     0,    86,     4,     0,     0,    87,
      88,     0,     0,     6,    80,    81,     8,     0,     0,     0,
      11,    12,    74,     0,    75,    76,    77,    78,    82,     0,
       0,     0,   112,   292,     0,     0,     0,    83,    84,    85,
      79,   188,    86,     0,     0,     0,    87,    88,     0,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    74,
       0,    75,    76,    77,    78,    82,     0,     0,     0,   112,
       0,     0,     0,     0,    83,    84,    85,    79,     0,    86,
       0,     0,     0,    87,    88,     0,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    74,     0,    75,    76,
      77,    78,    82,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    79,     0,    86,     0,     0,     0,
      87,    88,     0,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    74,     0,    75,    76,    77,    78,   140,
       0,     0,     0,     0,     0,     0,     1,     2,    83,    84,
      85,    79,     3,    86,     0,     0,     0,    87,    88,     4,
       0,     0,    80,    81,     0,     5,     6,     0,     7,     8,
       0,     9,    10,    11,    12,     0,   142,     0,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    85,     0,   131,
      86,   132,     1,     2,    87,    88,     0,     0,     3,     0,
      14,     0,     0,     0,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     0,     7,     8,     0,     9,    10,    11,
      12,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     3,     0,     0,     0,    13,     0,     2,     4,     0,
       0,     0,     3,     0,     5,     6,    14,     7,     8,     4,
       9,    10,    11,    12,     0,     5,     6,     0,     7,     8,
       0,     9,    10,    11,    12,     0,     0,     0,   227,     0,
     132,     0,     0,     0,     0,     0,     0,     0,   224,    14
};

static const yytype_int16 yycheck[] =
{
      59,    49,    59,    34,    48,    13,    82,    60,   132,   112,
       0,    28,    20,    83,    84,    85,    86,    87,    88,   134,
      79,    80,    81,    82,    67,   269,    16,     3,    69,     3,
     107,    21,    22,    23,    50,     3,    64,    65,    69,     3,
      42,    14,    64,     3,     0,    46,   123,    48,    54,    57,
      66,    54,    46,   112,    48,   112,    57,    63,    66,   107,
      63,    69,    35,     3,   140,    67,   142,   311,   127,    46,
      51,    48,    45,    54,    50,   123,    50,    67,    46,   323,
      48,   140,    46,   142,   132,   161,    46,   130,    61,    62,
      63,    64,    82,   163,   164,   165,   118,    57,    50,   223,
     131,   160,   161,   160,   145,   181,    51,    51,     3,    54,
      54,    47,   198,   228,   145,   192,    45,   134,   195,    30,
      31,   129,   181,   131,    57,   211,   202,    46,   187,    48,
     187,    66,    61,    62,    63,    64,    57,    58,    59,   198,
     130,    43,    44,   202,   192,   118,    47,   195,    54,     3,
     140,    46,   211,    39,    40,   208,   259,    52,    62,    63,
     230,    50,    57,    50,     4,    35,    36,    37,    38,   166,
     167,    49,   231,    61,   231,   223,    16,   263,   222,   168,
     169,   267,   190,    23,    60,    62,    26,   174,   175,   118,
      30,    31,    46,   269,    48,   271,   227,    41,   274,   275,
     259,    66,   259,    57,   263,    66,    52,    54,   267,   295,
     269,    51,   271,    47,    47,   274,   275,   170,   171,   172,
     173,     3,     3,    52,    63,    63,   312,   313,   314,   315,
     289,    52,   289,    46,   310,   311,   295,     3,   324,   325,
      46,    46,    46,   291,    51,    63,    47,   323,    47,    49,
      47,   310,   311,   312,   313,   314,   315,    47,    54,    52,
      49,    52,    27,    49,   323,   324,   325,     3,    63,     5,
       6,     7,     8,    47,    10,    11,    12,    13,    14,    63,
      63,    17,    18,    19,    20,    21,    46,     4,    24,    47,
      47,    27,     9,    47,    47,    47,    32,    33,    16,    16,
      63,    15,    32,    33,    34,    22,    23,    63,    25,    26,
      46,    28,    29,    30,    31,    51,    46,    57,    48,    55,
      56,    57,    61,    53,    60,    50,   190,    63,    64,    65,
       3,   109,     5,     6,     7,     8,   139,    10,    11,    12,
      13,    14,   140,     4,    17,    18,    19,    20,    21,   176,
     178,    24,   177,   179,    27,    16,   180,    -1,    -1,    32,
      33,    -1,    23,    -1,    -1,    26,    -1,    -1,    -1,    30,
      31,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    55,    56,    57,    -1,    -1,    60,    -1,    -1,
      63,    64,    65,     3,    -1,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      20,    21,    -1,    -1,    24,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,     3,     4,
       5,     6,     7,     8,     9,    55,    56,    57,    -1,    -1,
      60,    16,    -1,    63,    64,    65,    21,    22,    23,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,    46,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    21,    -1,    60,    16,    -1,    -1,    64,
      65,    -1,    -1,    23,    32,    33,    26,    -1,    -1,    -1,
      30,    31,     3,    -1,     5,     6,     7,     8,    46,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    55,    56,    57,
      21,    51,    60,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,     6,     7,     8,    46,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    55,    56,    57,    21,    -1,    60,
      -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    21,    -1,    60,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,    46,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    55,    56,
      57,    21,     9,    60,    -1,    -1,    -1,    64,    65,    16,
      -1,    -1,    32,    33,    -1,    22,    23,    -1,    25,    26,
      -1,    28,    29,    30,    31,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    -1,    46,
      60,    48,     3,     4,    64,    65,    -1,    -1,     9,    -1,
      57,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    22,    23,    -1,    25,    26,    -1,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    46,    -1,     4,    16,    -1,
      -1,    -1,     9,    -1,    22,    23,    57,    25,    26,    16,
      28,    29,    30,    31,    -1,    22,    23,    -1,    25,    26,
      -1,    28,    29,    30,    31,    -1,    -1,    -1,    46,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     9,    16,    22,    23,    25,    26,    28,
      29,    30,    31,    46,    57,    70,    71,    72,    73,    77,
      78,    79,    80,    83,    84,    85,    91,    94,    95,    98,
       3,    50,    94,    80,    96,    97,     0,    72,    81,    82,
      94,    78,    78,    78,     3,    50,    75,    98,    46,    48,
      50,     3,    92,    93,    47,    95,    80,    54,    63,    66,
      74,    50,    80,    83,    86,    87,    88,    50,   113,    78,
     100,   101,   102,   103,     3,     5,     6,     7,     8,    21,
      32,    33,    46,    55,    56,    57,    60,    64,    65,    99,
     124,   125,   128,   129,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   145,    92,    66,    51,    54,
      82,    94,    50,   107,   128,   141,   142,   113,    86,    88,
      88,    51,    87,    52,    89,    90,    94,    76,    77,    78,
     114,    46,    48,    94,    95,   104,   105,   106,    47,    54,
      46,   128,    46,   128,   128,    78,   130,   142,   143,   144,
     129,   129,   129,   129,   129,   129,    49,    32,    33,    34,
      46,    48,    53,    57,    58,    59,    64,    65,    43,    44,
      35,    36,    37,    38,    39,    40,    60,    62,    61,    41,
      42,    67,    51,   145,    93,   107,   108,    66,    51,   145,
      54,    63,    52,     3,    10,    11,    12,    13,    14,    17,
      18,    19,    20,    24,    27,    63,   109,   110,   111,   112,
     115,   116,   117,   118,   119,   123,   144,    77,   100,   105,
      99,   106,    46,    48,    45,   103,   130,    46,    95,   105,
      47,    54,    47,     3,   126,   127,   142,   144,     3,   129,
     129,   129,   131,   131,   132,   132,   133,   133,   133,   133,
     134,   134,   135,   136,   137,   138,   139,   144,    51,    54,
     142,    90,   145,    52,    63,   145,    63,    52,   109,    46,
       3,    46,   121,   144,    46,    46,   113,    51,   109,    63,
      47,    47,    49,   100,    99,    47,   129,   142,    47,    54,
      49,    52,    51,   107,   109,    52,   109,    27,   121,   122,
      63,   144,    63,   144,   144,    47,    49,   142,   141,   109,
      46,    63,    47,    47,    47,    47,   144,   121,   109,   109,
     109,   109,    47,    63,   120,    15,    63,   121,   109,   109
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    74,    73,    75,
      73,    76,    76,    77,    78,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    83,    84,    84,    84,    85,    85,    86,
      86,    87,    88,    88,    88,    88,    89,    89,    90,    90,
      90,    91,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    97,    97,    98,    98,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   105,   106,   106,   106,   106,   106,
     107,   107,   107,   108,   108,   109,   109,   109,   109,   109,
     109,   111,   110,   112,   112,   112,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   118,   119,   119,
     120,   119,   121,   121,   122,   123,   123,   123,   123,   124,
     124,   124,   124,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   126,   126,   127,   127,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   129,   129,   130,
     130,   131,   131,   131,   131,   132,   132,   132,   133,   133,
     133,   134,   134,   134,   134,   134,   135,   135,   135,   136,
     136,   137,   137,   138,   138,   139,   139,   140,   140,   141,
     141,   142,   142,   143,   143,   144,   145
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     4,     0,
       3,     0,     1,     3,     1,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     1,     5,     4,     2,     1,     1,     1,
       2,     3,     1,     1,     2,     2,     1,     3,     1,     2,
       3,     5,     4,     2,     1,     3,     1,     3,     2,     1,
       2,     3,     0,     1,     1,     2,     1,     3,     4,     4,
       0,     1,     0,     1,     1,     3,     1,     3,     2,     2,
       0,     1,     1,     1,     2,     3,     3,     3,     4,     4,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     0,     2,     4,     3,     3,     4,     1,     2,     0,
       1,     1,     2,     1,     2,     5,     7,     5,     5,     7,
       0,     7,     0,     1,     5,     3,     2,     2,     3,     1,
       1,     1,     1,     1,     3,     1,     4,     4,     3,     3,
       2,     2,     0,     1,     1,     3,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     4,     1,     4,     1,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     3,     1,     1
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
  case 7: /* @1: %empty  */
#line 61 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
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
#line 1760 "y.tab.c"
    break;

  case 8: /* function_definition: declaration_specifiers declarator @1 compound_statement  */
#line 79 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = setFunctionDeclaratorBody(PTR(A_ID, yyvsp[-1]), PTR(A_NODE, yyvsp[0]));

      leaveScope();
      yyval = YY(id);
    }
#line 1771 "y.tab.c"
    break;

  case 9: /* @2: %empty  */
#line 86 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
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
        current_id = id;
      }

      yyval = YY(id);
    }
#line 1794 "y.tab.c"
    break;

  case 10: /* function_definition: declarator @2 compound_statement  */
#line 105 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = setFunctionDeclaratorBody(PTR(A_ID, yyvsp[-1]), PTR(A_NODE, yyvsp[0]));

      leaveScope();
      yyval = YY(id);
    }
#line 1805 "y.tab.c"
    break;

  case 11: /* declaration_list_opt: %empty  */
#line 115 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 1813 "y.tab.c"
    break;

  case 12: /* declaration_list_opt: declaration_list  */
#line 119 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1821 "y.tab.c"
    break;

  case 13: /* declaration: declaration_specifiers init_declarator_list SEMICOLON  */
#line 126 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorListSpecifier(PTR(A_ID, yyvsp[-1]), PTR(A_SPECIFIER, yyvsp[-2])));
    }
#line 1829 "y.tab.c"
    break;

  case 14: /* declaration_specifiers: type_specifier  */
#line 133 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeSpecifier(PTR(A_TYPE, yyvsp[0]), S_NULL));
    }
#line 1837 "y.tab.c"
    break;

  case 15: /* declaration_specifiers: storage_class_specifier  */
#line 137 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeSpecifier(NULL, (S_KIND)yyvsp[0]));
    }
#line 1845 "y.tab.c"
    break;

  case 17: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 142 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(updateSpecifier(PTR(A_SPECIFIER, yyvsp[0]), PTR(A_TYPE, yyvsp[-1]), S_NULL));
    }
#line 1853 "y.tab.c"
    break;

  case 18: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 146 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(updateSpecifier(PTR(A_SPECIFIER, yyvsp[0]), PTR(A_TYPE, yyvsp[-1]), S_NULL));
    }
#line 1861 "y.tab.c"
    break;

  case 27: /* init_declarator_list: init_declarator  */
#line 167 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1869 "y.tab.c"
    break;

  case 28: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 171 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 1877 "y.tab.c"
    break;

  case 29: /* init_declarator: declarator  */
#line 178 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1885 "y.tab.c"
    break;

  case 33: /* type_specifier: TYPE_IDENTIFIER  */
#line 188 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1893 "y.tab.c"
    break;

  case 58: /* declarator: pointer direct_declarator  */
#line 249 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[0]), PTR(A_TYPE, yyvsp[-1])));
    }
#line 1901 "y.tab.c"
    break;

  case 59: /* declarator: direct_declarator  */
#line 253 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1909 "y.tab.c"
    break;

  case 60: /* pointer: STAR type_qualifier_list_opt  */
#line 260 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeType(T_POINTER));
    }
#line 1917 "y.tab.c"
    break;

  case 61: /* pointer: STAR type_qualifier_list_opt pointer  */
#line 264 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[0]), makeType(T_POINTER)));
    }
#line 1925 "y.tab.c"
    break;

  case 66: /* direct_declarator: IDENTIFIER  */
#line 281 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);

      A_ID *id = makeIdentifier(name);
      free(name);

      yyval = YY(id);
    }
#line 1938 "y.tab.c"
    break;

  case 68: /* direct_declarator: direct_declarator LB constant_expression_opt RB  */
#line 291 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[-3]),
                                       setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1]))));
    }
#line 1947 "y.tab.c"
    break;

  case 69: /* direct_declarator: direct_declarator LP parameter_type_list_opt RP  */
#line 296 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[-3]),
                                       setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1]))));
    }
#line 1956 "y.tab.c"
    break;

  case 70: /* constant_expression_opt: %empty  */
#line 304 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 1964 "y.tab.c"
    break;

  case 71: /* constant_expression_opt: constant_expression  */
#line 308 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1972 "y.tab.c"
    break;

  case 72: /* parameter_type_list_opt: %empty  */
#line 315 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 1980 "y.tab.c"
    break;

  case 73: /* parameter_type_list_opt: parameter_type_list  */
#line 319 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1988 "y.tab.c"
    break;

  case 76: /* parameter_list: parameter_declaration  */
#line 331 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1996 "y.tab.c"
    break;

  case 77: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 335 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 2004 "y.tab.c"
    break;

  case 78: /* parameter_declaration: declaration_specifiers declarator  */
#line 342 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setParameterDeclaratorSpecifier(PTR(A_ID, yyvsp[0]), PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2012 "y.tab.c"
    break;

  case 79: /* parameter_declaration: declaration_specifiers abstract_declarator_opt  */
#line 346 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = makeDummyIdentifier();

      setDeclaratorElementType(id, PTR(A_TYPE, yyvsp[0]));

      yyval = YY(setParameterDeclaratorSpecifier(id, PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2024 "y.tab.c"
    break;

  case 80: /* abstract_declarator_opt: %empty  */
#line 357 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2032 "y.tab.c"
    break;

  case 81: /* abstract_declarator_opt: abstract_declarator  */
#line 361 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2040 "y.tab.c"
    break;

  case 96: /* statement: scoped_compound_statement  */
#line 394 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2048 "y.tab.c"
    break;

  case 97: /* statement: expression_statement  */
#line 398 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2056 "y.tab.c"
    break;

  case 98: /* statement: selection_statement  */
#line 401 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2062 "y.tab.c"
    break;

  case 99: /* statement: iteration_statement  */
#line 402 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2068 "y.tab.c"
    break;

  case 100: /* statement: jump_statement  */
#line 404 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2076 "y.tab.c"
    break;

  case 101: /* $@3: %empty  */
#line 411 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      enterScope();
    }
#line 2084 "y.tab.c"
    break;

  case 102: /* scoped_compound_statement: $@3 compound_statement  */
#line 415 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
      leaveScope();
    }
#line 2093 "y.tab.c"
    break;

  case 106: /* compound_statement: LR declaration_list_opt statement_list_opt RR  */
#line 429 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_COMPOUND, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[-1])));

      compound_root = PTR(A_NODE, yyval);
    }
#line 2103 "y.tab.c"
    break;

  case 107: /* declaration_list: declaration  */
#line 438 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2111 "y.tab.c"
    break;

  case 108: /* declaration_list: declaration_list declaration  */
#line 442 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-1]), PTR(A_ID, yyvsp[0])));
    }
#line 2119 "y.tab.c"
    break;

  case 109: /* statement_list_opt: %empty  */
#line 449 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL));
    }
#line 2127 "y.tab.c"
    break;

  case 110: /* statement_list_opt: statement_list  */
#line 453 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2135 "y.tab.c"
    break;

  case 111: /* statement_list: statement  */
#line 460 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LIST, PTR(A_NODE, yyvsp[0]), NULL,
                       makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL)));
    }
#line 2144 "y.tab.c"
    break;

  case 112: /* statement_list: statement_list statement  */
#line 465 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNodeList(N_STMT_LIST, PTR(A_NODE, yyvsp[-1]), PTR(A_NODE, yyvsp[0])));
    }
#line 2152 "y.tab.c"
    break;

  case 113: /* expression_statement: SEMICOLON  */
#line 472 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_EMPTY, NULL, NULL, NULL));
    }
#line 2160 "y.tab.c"
    break;

  case 114: /* expression_statement: expression SEMICOLON  */
#line 476 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_EXPRESSION, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2168 "y.tab.c"
    break;

  case 115: /* selection_statement: IF_SYM LP expression RP statement  */
#line 483 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_IF, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2176 "y.tab.c"
    break;

  case 116: /* selection_statement: IF_SYM LP expression RP statement ELSE_SYM statement  */
#line 487 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_IF_ELSE, PTR(A_NODE, yyvsp[-4]), PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2184 "y.tab.c"
    break;

  case 118: /* iteration_statement: WHILE_SYM LP expression RP statement  */
#line 495 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_WHILE, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2192 "y.tab.c"
    break;

  case 119: /* iteration_statement: DO_SYM statement WHILE_SYM LP expression RP SEMICOLON  */
#line 499 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_DO, PTR(A_NODE, yyvsp[-5]), NULL, PTR(A_NODE, yyvsp[-2])));
    }
#line 2200 "y.tab.c"
    break;

  case 120: /* @4: %empty  */
#line 503 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_FOR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2208 "y.tab.c"
    break;

  case 122: /* expression_opt: %empty  */
#line 511 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2216 "y.tab.c"
    break;

  case 123: /* expression_opt: expression  */
#line 515 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2224 "y.tab.c"
    break;

  case 124: /* for_expression: expression_opt SEMICOLON expression_opt SEMICOLON expression_opt  */
#line 522 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_FOR_EXP, PTR(A_NODE, yyvsp[-4]), PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2232 "y.tab.c"
    break;

  case 125: /* jump_statement: RETURN_SYM expression_opt SEMICOLON  */
#line 526 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_RETURN, NULL, PTR(A_NODE, yyvsp[-1]), NULL));

      statement_root = PTR(A_NODE, yyval);
    }
#line 2242 "y.tab.c"
    break;

  case 129: /* primary_expression: IDENTIFIER  */
#line 538 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      A_ID *id = getIdentifierDeclared(name);
      free(name);

      yyval = YY(makeNode(N_EXP_IDENT, NULL, PTR(A_NODE, id), NULL));
    }
#line 2254 "y.tab.c"
    break;

  case 130: /* primary_expression: INTEGER_CONSTANT  */
#line 546 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_INT_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));

      A_NODE *node = PTR(A_NODE, yyval);
      logMsg(LOG_DEBUG, "N_EXP_INT_CONST: %lld", (long long)(intptr_t)node->clink);
    }
#line 2265 "y.tab.c"
    break;

  case 134: /* primary_expression: LP expression RP  */
#line 556 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[-1];
    }
#line 2273 "y.tab.c"
    break;

  case 135: /* postfix_expression: primary_expression  */
#line 563 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2281 "y.tab.c"
    break;

  case 136: /* postfix_expression: postfix_expression LB expression RB  */
#line 567 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ARRAY, PTR(A_NODE, yyvsp[-3]), NULL, PTR(A_NODE, yyvsp[-1])));
    }
#line 2289 "y.tab.c"
    break;

  case 140: /* postfix_expression: postfix_expression PLUSPLUS  */
#line 574 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_POST_INC, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2297 "y.tab.c"
    break;

  case 141: /* postfix_expression: postfix_expression MINUSMINUS  */
#line 578 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_POST_DEC, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2305 "y.tab.c"
    break;

  case 146: /* unary_expression: postfix_expression  */
#line 595 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2313 "y.tab.c"
    break;

  case 147: /* unary_expression: PLUSPLUS unary_expression  */
#line 599 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_PRE_INC, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2321 "y.tab.c"
    break;

  case 148: /* unary_expression: MINUSMINUS unary_expression  */
#line 603 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_PRE_DEC, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2329 "y.tab.c"
    break;

  case 149: /* unary_expression: AMP cast_expression  */
#line 607 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_AMP, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2337 "y.tab.c"
    break;

  case 150: /* unary_expression: STAR cast_expression  */
#line 611 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_STAR, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2345 "y.tab.c"
    break;

  case 151: /* unary_expression: EXCL cast_expression  */
#line 615 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_NOT, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2353 "y.tab.c"
    break;

  case 152: /* unary_expression: MINUS cast_expression  */
#line 619 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MINUS, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2361 "y.tab.c"
    break;

  case 154: /* unary_expression: PLUS cast_expression  */
#line 624 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2369 "y.tab.c"
    break;

  case 157: /* cast_expression: unary_expression  */
#line 633 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2377 "y.tab.c"
    break;

  case 161: /* multiplicative_expression: cast_expression  */
#line 646 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2385 "y.tab.c"
    break;

  case 162: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 650 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MUL, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2393 "y.tab.c"
    break;

  case 163: /* multiplicative_expression: multiplicative_expression SLASH cast_expression  */
#line 654 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_DIV, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2401 "y.tab.c"
    break;

  case 164: /* multiplicative_expression: multiplicative_expression PERCENT cast_expression  */
#line 658 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MOD, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2409 "y.tab.c"
    break;

  case 165: /* additive_expression: multiplicative_expression  */
#line 665 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2417 "y.tab.c"
    break;

  case 166: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 669 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ADD, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2425 "y.tab.c"
    break;

  case 167: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 673 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_SUB, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2433 "y.tab.c"
    break;

  case 168: /* shift_expression: additive_expression  */
#line 679 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2439 "y.tab.c"
    break;

  case 171: /* relational_expression: shift_expression  */
#line 686 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2447 "y.tab.c"
    break;

  case 172: /* relational_expression: relational_expression LSS shift_expression  */
#line 690 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_LSS, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2455 "y.tab.c"
    break;

  case 173: /* relational_expression: relational_expression GTR shift_expression  */
#line 694 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_GTR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2463 "y.tab.c"
    break;

  case 174: /* relational_expression: relational_expression LEQ shift_expression  */
#line 698 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_LEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2471 "y.tab.c"
    break;

  case 175: /* relational_expression: relational_expression GEQ shift_expression  */
#line 702 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_GEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2479 "y.tab.c"
    break;

  case 176: /* equality_expression: relational_expression  */
#line 709 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2487 "y.tab.c"
    break;

  case 177: /* equality_expression: equality_expression EQL relational_expression  */
#line 713 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_EQL, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2495 "y.tab.c"
    break;

  case 178: /* equality_expression: equality_expression NEQ relational_expression  */
#line 717 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_NEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2503 "y.tab.c"
    break;

  case 179: /* AND_expression: equality_expression  */
#line 723 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2509 "y.tab.c"
    break;

  case 181: /* exclusive_OR_expression: AND_expression  */
#line 728 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                     { yyval = yyvsp[0]; }
#line 2515 "y.tab.c"
    break;

  case 183: /* inclusive_OR_expression: exclusive_OR_expression  */
#line 733 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                              { yyval = yyvsp[0]; }
#line 2521 "y.tab.c"
    break;

  case 185: /* logical_AND_expression: inclusive_OR_expression  */
#line 738 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                              { yyval = yyvsp[0]; }
#line 2527 "y.tab.c"
    break;

  case 186: /* logical_AND_expression: logical_AND_expression AMPAMP inclusive_OR_expression  */
#line 740 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_AND, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2535 "y.tab.c"
    break;

  case 187: /* logical_OR_expression: logical_AND_expression  */
#line 746 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                             { yyval = yyvsp[0]; }
#line 2541 "y.tab.c"
    break;

  case 188: /* logical_OR_expression: logical_OR_expression BARBAR logical_AND_expression  */
#line 748 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_OR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2549 "y.tab.c"
    break;

  case 191: /* assignment_expression: conditional_expression  */
#line 760 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2557 "y.tab.c"
    break;

  case 192: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 764 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ASSIGN, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2565 "y.tab.c"
    break;

  case 195: /* expression: comma_expression  */
#line 776 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
      expression_root = PTR(A_NODE, yyvsp[0]);
    }
#line 2574 "y.tab.c"
    break;


#line 2578 "y.tab.c"

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

#line 785 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"

int yyerror(const char *s) {
  logMsg(LOG_ERROR, "Syntax error at line %d: %s", line_no, s);
  return 0;
}
