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
  YYSYMBOL_init_declarator_list_opt = 81,  /* init_declarator_list_opt  */
  YYSYMBOL_init_declarator_list = 82,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 83,           /* init_declarator  */
  YYSYMBOL_type_specifier = 84,            /* type_specifier  */
  YYSYMBOL_struct_specifier = 85,          /* struct_specifier  */
  YYSYMBOL_86_3 = 86,                      /* @3  */
  YYSYMBOL_87_4 = 87,                      /* @4  */
  YYSYMBOL_struct_or_union = 88,           /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 89,   /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 90,        /* struct_declaration  */
  YYSYMBOL_struct_declarator_list = 91,    /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 92,         /* struct_declarator  */
  YYSYMBOL_enum_specifier = 93,            /* enum_specifier  */
  YYSYMBOL_94_5 = 94,                      /* @5  */
  YYSYMBOL_95_6 = 95,                      /* @6  */
  YYSYMBOL_enumerator_list = 96,           /* enumerator_list  */
  YYSYMBOL_enumerator = 97,                /* enumerator  */
  YYSYMBOL_declarator = 98,                /* declarator  */
  YYSYMBOL_pointer = 99,                   /* pointer  */
  YYSYMBOL_type_qualifier_list_opt = 100,  /* type_qualifier_list_opt  */
  YYSYMBOL_type_qualifier_list = 101,      /* type_qualifier_list  */
  YYSYMBOL_direct_declarator = 102,        /* direct_declarator  */
  YYSYMBOL_constant_expression_opt = 103,  /* constant_expression_opt  */
  YYSYMBOL_parameter_type_list_opt = 104,  /* parameter_type_list_opt  */
  YYSYMBOL_parameter_type_list = 105,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 106,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 107,    /* parameter_declaration  */
  YYSYMBOL_abstract_declarator_opt = 108,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 109,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 110, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 111,              /* initializer  */
  YYSYMBOL_initializer_list = 112,         /* initializer_list  */
  YYSYMBOL_statement = 113,                /* statement  */
  YYSYMBOL_scoped_compound_statement = 114, /* scoped_compound_statement  */
  YYSYMBOL_115_7 = 115,                    /* $@7  */
  YYSYMBOL_labeled_statement = 116,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 117,       /* compound_statement  */
  YYSYMBOL_declaration_list = 118,         /* declaration_list  */
  YYSYMBOL_statement_list_opt = 119,       /* statement_list_opt  */
  YYSYMBOL_statement_list = 120,           /* statement_list  */
  YYSYMBOL_expression_statement = 121,     /* expression_statement  */
  YYSYMBOL_selection_statement = 122,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 123,      /* iteration_statement  */
  YYSYMBOL_expression_opt = 124,           /* expression_opt  */
  YYSYMBOL_for_expression = 125,           /* for_expression  */
  YYSYMBOL_jump_statement = 126,           /* jump_statement  */
  YYSYMBOL_primary_expression = 127,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 128,       /* postfix_expression  */
  YYSYMBOL_arg_expression_list_opt = 129,  /* arg_expression_list_opt  */
  YYSYMBOL_arg_expression_list = 130,      /* arg_expression_list  */
  YYSYMBOL_unary_expression = 131,         /* unary_expression  */
  YYSYMBOL_cast_expression = 132,          /* cast_expression  */
  YYSYMBOL_type_name = 133,                /* type_name  */
  YYSYMBOL_multiplicative_expression = 134, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 135,      /* additive_expression  */
  YYSYMBOL_shift_expression = 136,         /* shift_expression  */
  YYSYMBOL_relational_expression = 137,    /* relational_expression  */
  YYSYMBOL_equality_expression = 138,      /* equality_expression  */
  YYSYMBOL_AND_expression = 139,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 140,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 141,  /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 142,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 143,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 144,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 145,    /* assignment_expression  */
  YYSYMBOL_comma_expression = 146,         /* comma_expression  */
  YYSYMBOL_expression = 147,               /* expression  */
  YYSYMBOL_constant_expression = 148       /* constant_expression  */
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
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  196
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  329

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
       0,    44,    44,    55,    56,    60,    61,    68,    67,    93,
      92,   122,   125,   132,   139,   143,   147,   152,   156,   160,
     168,   169,   170,   171,   176,   184,   185,   190,   193,   200,
     204,   211,   215,   223,   224,   225,   233,   232,   243,   242,
     250,   259,   260,   264,   265,   272,   279,   280,   287,   288,
     293,   302,   301,   310,   309,   317,   324,   325,   332,   340,
     348,   352,   359,   363,   370,   371,   375,   376,   380,   389,
     393,   398,   407,   410,   418,   421,   428,   429,   437,   441,
     448,   452,   464,   467,   474,   478,   482,   489,   493,   497,
     501,   506,   514,   519,   524,   532,   537,   545,   546,   550,
     554,   555,   556,   564,   564,   575,   579,   583,   591,   600,
     604,   612,   615,   622,   627,   634,   638,   645,   649,   653,
     660,   664,   668,   676,   679,   686,   693,   699,   703,   707,
     715,   723,   730,   734,   738,   742,   749,   753,   757,   761,
     766,   771,   775,   783,   786,   790,   795,   802,   806,   810,
     814,   818,   822,   826,   830,   835,   839,   843,   850,   854,
     861,   868,   872,   876,   880,   887,   891,   895,   902,   903,
     908,   916,   920,   924,   928,   932,   939,   943,   947,   954,
     955,   963,   964,   972,   973,   981,   982,   989,   990,   997,
    1001,  1009,  1013,  1020,  1024,  1032,  1040
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
  "storage_class_specifier", "type_qualifier", "init_declarator_list_opt",
  "init_declarator_list", "init_declarator", "type_specifier",
  "struct_specifier", "@3", "@4", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
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

#define YYPACT_NINF (-243)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-113)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     680,  -243,  -243,  -243,    37,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,    64,    17,    76,   680,  -243,  -243,  -243,
      64,   284,   284,   284,  -243,    92,  -243,  -243,    59,    86,
      56,    61,    54,  -243,    69,    17,  -243,  -243,    52,    77,
    -243,    -9,  -243,  -243,  -243,    85,   102,   119,    86,   284,
     547,   121,   176,  -243,  -243,  -243,  -243,    64,   510,   119,
     150,   157,   284,  -243,    70,   113,  -243,   137,  -243,  -243,
    -243,  -243,  -243,  -243,   584,   621,   621,   436,   547,   547,
     547,   547,   547,   547,   158,  -243,   142,  -243,  -243,    81,
      78,   134,   149,   154,   143,   147,   161,   170,    -6,  -243,
    -243,   176,   159,    12,  -243,  -243,   160,   510,  -243,   162,
    -243,  -243,  -243,   157,    51,    30,  -243,   265,  -243,    64,
     284,   634,   547,  -243,    29,  -243,  -243,   110,  -243,   724,
     436,  -243,   547,  -243,  -243,    23,   177,  -243,   169,   180,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,   226,
     547,   547,   228,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,    14,   547,  -243,   176,  -243,    74,   547,   141,
     547,     1,  -243,   181,  -243,  -243,   182,   172,   547,   173,
     185,   391,   195,   239,   197,   547,   198,   199,  -243,  -243,
    -243,   119,  -243,   200,   328,  -243,  -243,  -243,  -243,   186,
    -243,   201,   203,   210,   110,   284,   547,  -243,  -243,   213,
     713,   117,  -243,   547,   547,  -243,  -243,   214,   208,  -243,
     215,  -243,  -243,  -243,  -243,    81,    81,    78,    78,   134,
     134,   134,   134,   149,   149,   154,   143,   147,   161,   170,
     211,  -243,  -243,  -243,  -243,   473,  -243,  -243,  -243,    51,
    -243,   547,   391,  -243,   217,  -243,   391,   238,   547,   218,
     547,   224,  -243,   547,   547,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,   227,   231,  -243,  -243,  -243,  -243,   547,  -243,
     547,  -243,  -243,  -243,  -243,  -243,   391,  -243,   244,   232,
     247,  -243,   249,  -243,   252,   254,  -243,  -243,  -243,  -243,
    -243,   547,   547,   391,   391,   391,   391,   255,   240,  -243,
     276,  -243,  -243,   241,   547,   391,  -243,  -243,  -243
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    68,    35,    20,    53,    21,    41,    22,    42,    23,
      24,    25,    26,     0,    64,     0,     2,     3,     5,     6,
      27,    15,    16,    14,    33,    38,    34,     9,     0,    61,
      55,     0,     0,    66,    62,    65,     1,     4,     0,    28,
      29,    31,    18,    19,    17,    40,     0,     0,    60,    74,
      72,     0,     0,    69,    63,    67,    13,     0,     0,     0,
       0,     0,    11,    10,    82,     0,    75,    76,    78,   130,
     131,   132,   133,   134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,   147,   158,   161,   165,
     168,   171,   176,   179,   181,   183,   185,   187,   189,   196,
      73,     0,    58,     0,    56,    30,    31,     0,    32,   158,
     191,    92,     8,     0,     0,     0,    43,   103,   109,    27,
      12,    74,    72,    80,    84,    81,    83,    85,    71,     0,
       0,   156,     0,   148,   149,    82,     0,   193,   195,     0,
     152,   154,   151,   150,   155,   153,    70,   141,   142,     0,
     143,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,    95,     0,     0,     0,
       0,     0,    46,    48,    39,    44,   130,     0,     0,     0,
       0,   103,     0,     0,     0,   123,     0,     0,   115,   113,
      98,     0,    97,     0,   103,    99,   100,   101,   102,     0,
     110,     0,     0,     0,    86,    74,    72,    77,    79,     0,
      74,    84,   160,     0,     0,   135,   140,     0,   144,   145,
       0,   139,   162,   163,   164,   166,   167,   169,   170,   172,
     173,   174,   175,   177,   178,   180,   182,   184,   186,   188,
       0,    52,    59,    57,    93,     0,   192,    37,    49,     0,
      45,     0,   103,   128,     0,   127,   103,     0,   123,     0,
       0,     0,   124,     0,     0,   104,   108,   114,   116,    89,
      87,    88,     0,     0,   157,   159,   194,   138,     0,   137,
       0,    94,    96,    47,    50,   107,   103,   106,     0,     0,
       0,   129,     0,   126,     0,     0,    91,    90,   146,   190,
     105,     0,   123,   103,   103,   103,   103,     0,     0,   122,
     117,   119,   120,     0,   123,   103,   121,   125,   118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -243,  -243,  -243,   289,  -243,  -243,  -243,  -243,   -32,    21,
    -243,    15,  -243,  -243,   251,   -26,  -243,  -243,  -243,  -243,
     204,   -88,  -243,    60,  -243,  -243,  -243,   222,   151,   -12,
     -31,  -243,  -243,     0,   -99,   -45,  -243,  -243,   189,   192,
    -106,  -102,  -100,  -243,  -166,  -243,  -243,  -243,   -39,  -243,
    -243,  -243,  -243,  -243,  -243,  -242,  -243,  -243,  -243,  -243,
    -243,  -243,   -58,   -69,   194,    25,    47,    58,    49,   166,
     183,   175,   168,   174,  -243,   -44,   -56,  -243,   -72,  -149
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    15,    16,    17,    18,    59,    47,   117,    19,    64,
      21,    22,    38,    39,    40,    23,    24,    60,    46,    25,
     115,   116,   181,   182,    26,    51,    31,   103,   104,    27,
      28,    34,    35,    29,    84,   211,    66,    67,    68,   125,
     126,   127,   108,   177,   199,   200,   201,   202,    63,   120,
     203,   204,   205,   206,   207,   271,   300,   208,    85,    86,
     227,   228,    87,    88,   136,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   110,   137,   138,   209,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     109,    32,   111,    54,    65,   139,    99,   176,    41,   140,
     141,   142,   143,   144,   145,   212,   131,   133,   134,   109,
     112,    20,   214,   213,   252,   267,   299,   185,    48,    33,
     118,   258,     1,   124,     2,   114,   170,    20,   277,   264,
      30,    -7,    42,    43,    44,   106,     4,    11,    12,   109,
      55,   111,   123,     6,     1,   259,     8,    58,   139,   109,
     139,   171,     1,   174,   260,   251,   175,     1,   175,   220,
     318,   122,   109,     1,   109,   121,    36,   122,    99,   230,
      14,   184,   327,   119,   232,   233,   234,   114,   210,   114,
     124,   185,   109,   109,   229,    45,   295,    13,   135,   250,
     297,    53,   183,   180,   221,    13,   -51,   106,    14,    32,
      13,    52,   294,   109,   212,    56,   121,   283,   122,   214,
     109,    14,   256,   272,    48,   254,    14,    14,   255,    99,
     310,    57,    49,   109,    50,   -36,    99,   109,   153,   154,
     155,   119,   156,   157,    99,     2,   109,   319,   320,   321,
     322,   135,    61,   114,   285,   292,   215,     4,   216,   328,
     128,     2,   275,   220,     6,   122,   109,     8,   286,    62,
     282,   101,    99,     4,   147,   148,   149,   158,   159,   102,
       6,   235,   236,     8,   160,   161,   162,   163,   150,   221,
     151,   129,   257,   164,   165,   152,   272,   109,   302,   111,
     113,   304,   305,   166,   109,   237,   238,   146,   109,   167,
     109,   169,   109,   243,   244,   109,   109,    99,   239,   240,
     241,   242,   168,   224,   223,   173,    58,   225,   178,   226,
     109,   231,   308,   261,   262,   263,   265,   266,   109,   317,
     272,   268,   269,   270,   273,   274,   309,   183,   279,   278,
     280,   276,   272,   109,   109,   109,   109,   109,   109,   281,
     284,   287,   288,   290,   289,   298,   109,   109,   186,   296,
      70,    71,    72,    73,   306,   187,   188,   189,   190,   191,
     307,   301,   192,   193,   194,   195,    74,   303,     2,   196,
     311,   325,   197,     3,   313,   312,   314,    75,    76,   315,
       4,   316,   323,   324,   326,    37,     5,     6,   105,     7,
       8,    77,     9,    10,    11,    12,  -111,   179,   218,   293,
      78,    79,    80,   172,   219,    81,   253,   222,   198,    82,
      83,   186,   245,    70,    71,    72,    73,   248,   187,   188,
     189,   190,   191,   247,   249,   192,   193,   194,   195,    74,
     246,     0,   196,     0,     0,   197,     0,     0,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,  -112,
       0,     0,     0,    78,    79,    80,     0,     0,    81,     0,
       0,   198,    82,    83,   186,     0,    70,    71,    72,    73,
       0,   187,   188,   189,   190,   191,     0,     0,   192,   193,
     194,   195,    74,     0,     0,   196,     0,     0,   197,     0,
       0,     0,     0,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,    69,
       2,    70,    71,    72,    73,     3,    78,    79,    80,     0,
       0,    81,     4,     0,   198,    82,    83,    74,     5,     6,
       0,     7,     8,     0,     9,    10,    11,    12,    75,    76,
       0,     0,     0,     0,     0,     0,    69,     0,    70,    71,
      72,    73,    77,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    79,    80,    74,     0,    81,     0,     0,     0,
      82,    83,     0,     0,     0,    75,    76,     0,     0,     0,
       0,     0,     0,    69,     0,    70,    71,    72,    73,    77,
       0,     0,     0,   107,   291,     0,     0,     0,    78,    79,
      80,    74,     0,    81,     0,     0,     0,    82,    83,     0,
       0,     0,    75,    76,     0,     0,     0,     0,     0,     0,
      69,     0,    70,    71,    72,    73,    77,     0,     0,     0,
     107,     0,     0,     0,     0,    78,    79,    80,    74,     0,
      81,     0,     0,     0,    82,    83,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,    69,     0,    70,
      71,    72,    73,    77,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,    80,    74,     0,    81,     0,     0,
       0,    82,    83,     0,     0,     0,    75,    76,     0,     0,
       0,     0,     0,     0,    69,     0,    70,    71,    72,    73,
     130,     0,     0,     0,     0,     0,     0,     1,     2,    78,
      79,    80,    74,     3,    81,     0,     0,     0,    82,    83,
       4,     0,     0,    75,    76,     0,     5,     6,     0,     7,
       8,     0,     9,    10,    11,    12,     0,   132,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    79,    80,     0,
     121,    81,   122,     1,     2,    82,    83,     0,     0,     3,
       0,    14,     0,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     5,     6,     0,     7,     8,     0,     9,    10,
      11,    12,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,     3,     0,     0,     0,    13,     0,     2,     4,
       0,     0,     0,     3,     0,     5,     6,    14,     7,     8,
       4,     9,    10,    11,    12,     0,     5,     6,     0,     7,
       8,     0,     9,    10,    11,    12,     0,     0,     0,   220,
       0,   122,     0,     0,     0,     0,     0,     0,     0,   217,
      14
};

static const yytype_int16 yycheck[] =
{
      58,    13,    58,    34,    49,    77,    50,   107,    20,    78,
      79,    80,    81,    82,    83,   121,    74,    75,    76,    77,
      59,     0,   124,   122,   173,   191,   268,   115,    28,    14,
      62,   180,     3,    64,     4,    61,    42,    16,   204,   188,
       3,    50,    21,    22,    23,    57,    16,    30,    31,   107,
      35,   107,    64,    23,     3,    54,    26,    66,   130,   117,
     132,    67,     3,    51,    63,    51,    54,     3,    54,    46,
     312,    48,   130,     3,   132,    46,     0,    48,   122,   151,
      57,    51,   324,    62,   153,   154,   155,   113,   120,   115,
     121,   179,   150,   151,   150,     3,   262,    46,    77,   171,
     266,    47,   114,    52,   135,    46,    50,   119,    57,   121,
      46,    50,   261,   171,   220,    63,    46,   216,    48,   221,
     178,    57,   178,   195,   124,    51,    57,    57,    54,   173,
     296,    54,    46,   191,    48,    50,   180,   195,    57,    58,
      59,   120,    64,    65,   188,     4,   204,   313,   314,   315,
     316,   130,    50,   179,   223,   255,    46,    16,    48,   325,
      47,     4,   201,    46,    23,    48,   224,    26,   224,    50,
     215,    50,   216,    16,    32,    33,    34,    43,    44,     3,
      23,   156,   157,    26,    35,    36,    37,    38,    46,   220,
      48,    54,    51,    39,    40,    53,   268,   255,   270,   255,
      50,   273,   274,    60,   262,   158,   159,    49,   266,    62,
     268,    41,   270,   164,   165,   273,   274,   261,   160,   161,
     162,   163,    61,    54,    47,    66,    66,    47,    66,     3,
     288,     3,   288,    52,    52,    63,    63,    52,   296,   311,
     312,    46,     3,    46,    46,    46,   290,   259,    47,    63,
      47,    51,   324,   311,   312,   313,   314,   315,   316,    49,
      47,    47,    54,    52,    49,    27,   324,   325,     3,    52,
       5,     6,     7,     8,    47,    10,    11,    12,    13,    14,
      49,    63,    17,    18,    19,    20,    21,    63,     4,    24,
      46,    15,    27,     9,    47,    63,    47,    32,    33,    47,
      16,    47,    47,    63,    63,    16,    22,    23,    57,    25,
      26,    46,    28,    29,    30,    31,    51,   113,   129,   259,
      55,    56,    57,   101,   130,    60,   175,   135,    63,    64,
      65,     3,   166,     5,     6,     7,     8,   169,    10,    11,
      12,    13,    14,   168,   170,    17,    18,    19,    20,    21,
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
      78,    79,    80,    84,    85,    88,    93,    98,    99,   102,
       3,    95,    98,    80,   100,   101,     0,    72,    81,    82,
      83,    98,    78,    78,    78,     3,    87,    75,   102,    46,
      48,    94,    50,    47,    99,    80,    63,    54,    66,    74,
      86,    50,    50,   117,    78,   104,   105,   106,   107,     3,
       5,     6,     7,     8,    21,    32,    33,    46,    55,    56,
      57,    60,    64,    65,   103,   127,   128,   131,   132,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     148,    50,     3,    96,    97,    83,    98,    50,   111,   131,
     144,   145,   117,    50,    84,    89,    90,    76,    77,    78,
     118,    46,    48,    98,    99,   108,   109,   110,    47,    54,
      46,   131,    46,   131,   131,    78,   133,   145,   146,   147,
     132,   132,   132,   132,   132,   132,    49,    32,    33,    34,
      46,    48,    53,    57,    58,    59,    64,    65,    43,    44,
      35,    36,    37,    38,    39,    40,    60,    62,    61,    41,
      42,    67,    96,    66,    51,    54,   111,   112,    66,    89,
      52,    91,    92,    98,    51,    90,     3,    10,    11,    12,
      13,    14,    17,    18,    19,    20,    24,    27,    63,   113,
     114,   115,   116,   119,   120,   121,   122,   123,   126,   147,
      77,   104,   109,   103,   110,    46,    48,    45,   107,   133,
      46,    99,   108,    47,    54,    47,     3,   129,   130,   145,
     147,     3,   132,   132,   132,   134,   134,   135,   135,   136,
     136,   136,   136,   137,   137,   138,   139,   140,   141,   142,
     147,    51,   148,    97,    51,    54,   145,    51,   148,    54,
      63,    52,    52,    63,   148,    63,    52,   113,    46,     3,
      46,   124,   147,    46,    46,   117,    51,   113,    63,    47,
      47,    49,   104,   103,    47,   132,   145,    47,    54,    49,
      52,    51,   111,    92,   148,   113,    52,   113,    27,   124,
     125,    63,   147,    63,   147,   147,    47,    49,   145,   144,
     113,    46,    63,    47,    47,    47,    47,   147,   124,   113,
     113,   113,   113,    47,    63,    15,    63,   124,   113
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    74,    73,    75,
      73,    76,    76,    77,    78,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    84,    86,    85,    87,    85,
      85,    88,    88,    89,    89,    90,    91,    91,    92,    92,
      92,    94,    93,    95,    93,    93,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   111,   112,   112,   113,   113,   113,
     113,   113,   113,   115,   114,   116,   116,   116,   117,   118,
     118,   119,   119,   120,   120,   121,   121,   122,   122,   122,
     123,   123,   123,   124,   124,   125,   126,   126,   126,   126,
     127,   127,   127,   127,   127,   127,   128,   128,   128,   128,
     128,   128,   128,   129,   129,   130,   130,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   132,   132,
     133,   134,   134,   134,   134,   135,   135,   135,   136,   136,
     136,   137,   137,   137,   137,   137,   138,   138,   138,   139,
     139,   140,   140,   141,   141,   142,   142,   143,   143,   144,
     144,   145,   145,   146,   146,   147,   148
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     4,     0,
       3,     0,     1,     3,     1,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       3,     1,     3,     1,     1,     1,     0,     6,     0,     5,
       2,     1,     1,     1,     2,     3,     1,     3,     1,     2,
       3,     0,     6,     0,     5,     2,     1,     3,     1,     3,
       2,     1,     2,     3,     0,     1,     1,     2,     1,     3,
       4,     4,     0,     1,     0,     1,     1,     3,     1,     3,
       2,     2,     0,     1,     1,     1,     2,     3,     3,     3,
       4,     4,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     0,     2,     4,     3,     3,     4,     1,
       2,     0,     1,     1,     2,     1,     2,     5,     7,     5,
       5,     7,     5,     0,     1,     5,     3,     2,     2,     3,
       1,     1,     1,     1,     1,     3,     1,     4,     4,     3,
       3,     2,     2,     0,     1,     1,     3,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     4,     1,     4,
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
  case 2: /* program: translation_unit  */
#line 45 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      checkForwardReference();

      program_root = makeNode(N_PROGRAM, NULL, PTR(A_NODE, current_id), NULL);

      yyval = YY(program_root);
    }
#line 1756 "y.tab.c"
    break;

  case 7: /* @1: %empty  */
#line 68 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
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
#line 1778 "y.tab.c"
    break;

  case 8: /* function_definition: declaration_specifiers declarator @1 compound_statement  */
#line 86 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = setFunctionDeclaratorBody(PTR(A_ID, yyvsp[-1]), PTR(A_NODE, yyvsp[0]));

      leaveScope();
      yyval = YY(id);
    }
#line 1789 "y.tab.c"
    break;

  case 9: /* @2: %empty  */
#line 93 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
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
#line 1812 "y.tab.c"
    break;

  case 10: /* function_definition: declarator @2 compound_statement  */
#line 112 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = setFunctionDeclaratorBody(PTR(A_ID, yyvsp[-1]), PTR(A_NODE, yyvsp[0]));

      leaveScope();
      yyval = YY(id);
    }
#line 1823 "y.tab.c"
    break;

  case 11: /* declaration_list_opt: %empty  */
#line 122 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 1831 "y.tab.c"
    break;

  case 12: /* declaration_list_opt: declaration_list  */
#line 126 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1839 "y.tab.c"
    break;

  case 13: /* declaration: declaration_specifiers init_declarator_list_opt SEMICOLON  */
#line 133 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorListSpecifier(PTR(A_ID, yyvsp[-1]), PTR(A_SPECIFIER, yyvsp[-2])));
    }
#line 1847 "y.tab.c"
    break;

  case 14: /* declaration_specifiers: type_specifier  */
#line 140 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeSpecifier(PTR(A_TYPE, yyvsp[0]), S_NULL));
    }
#line 1855 "y.tab.c"
    break;

  case 15: /* declaration_specifiers: storage_class_specifier  */
#line 144 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeSpecifier(NULL, (S_KIND)yyvsp[0]));
    }
#line 1863 "y.tab.c"
    break;

  case 16: /* declaration_specifiers: type_qualifier  */
#line 148 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Type type_qualifier are not suuported");
      yyval = YY(NULL);
    }
#line 1872 "y.tab.c"
    break;

  case 17: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 153 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(updateSpecifier(PTR(A_SPECIFIER, yyvsp[0]), PTR(A_TYPE, yyvsp[-1]), S_NULL));
    }
#line 1880 "y.tab.c"
    break;

  case 18: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 157 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(updateSpecifier(PTR(A_SPECIFIER, yyvsp[0]), NULL, (S_KIND)yyvsp[-1]));
    }
#line 1888 "y.tab.c"
    break;

  case 19: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 161 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Type type_qualifier are not suuported");
      yyval = yyvsp[0];
    }
#line 1897 "y.tab.c"
    break;

  case 20: /* storage_class_specifier: AUTO_SYM  */
#line 168 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
               { yyval = YY(S_AUTO); }
#line 1903 "y.tab.c"
    break;

  case 21: /* storage_class_specifier: STATIC_SYM  */
#line 169 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                 { yyval = YY(S_STATIC); }
#line 1909 "y.tab.c"
    break;

  case 22: /* storage_class_specifier: TYPEDEF_SYM  */
#line 170 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                  { yyval = YY(S_TYPEDEF); }
#line 1915 "y.tab.c"
    break;

  case 23: /* storage_class_specifier: REGISTER_SYM  */
#line 172 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("register is not supported");
      yyval = YY(S_NULL);
    }
#line 1924 "y.tab.c"
    break;

  case 24: /* storage_class_specifier: EXTERN_SYM  */
#line 177 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("extern is not supported");
      yyval = YY(S_NULL);
    }
#line 1933 "y.tab.c"
    break;

  case 27: /* init_declarator_list_opt: %empty  */
#line 190 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 1941 "y.tab.c"
    break;

  case 28: /* init_declarator_list_opt: init_declarator_list  */
#line 194 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1949 "y.tab.c"
    break;

  case 29: /* init_declarator_list: init_declarator  */
#line 201 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1957 "y.tab.c"
    break;

  case 30: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 205 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 1965 "y.tab.c"
    break;

  case 31: /* init_declarator: declarator  */
#line 212 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1973 "y.tab.c"
    break;

  case 32: /* init_declarator: declarator ASSIGN initializer  */
#line 216 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Initializers are not supported");
      yyval = YY(NULL);
    }
#line 1982 "y.tab.c"
    break;

  case 35: /* type_specifier: TYPE_IDENTIFIER  */
#line 226 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1990 "y.tab.c"
    break;

  case 36: /* @3: %empty  */
#line 233 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(setTypeStructOrEnumIdentifier((T_KIND)yyvsp[-1], name, ID_STRUCT));
      free(name);
    }
#line 2000 "y.tab.c"
    break;

  case 37: /* struct_specifier: struct_or_union IDENTIFIER @3 LR struct_declaration_list RR  */
#line 239 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 2008 "y.tab.c"
    break;

  case 38: /* @4: %empty  */
#line 243 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeType((T_KIND)yyvsp[0]));
    }
#line 2016 "y.tab.c"
    break;

  case 39: /* struct_specifier: struct_or_union @4 LR struct_declaration_list RR  */
#line 247 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 2024 "y.tab.c"
    break;

  case 40: /* struct_specifier: struct_or_union IDENTIFIER  */
#line 251 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(getTypeOfStructOrEnumIdentifier((T_KIND)yyvsp[-1], name, ID_STRUCT));
      free(name);
    }
#line 2034 "y.tab.c"
    break;

  case 41: /* struct_or_union: STRUCT_SYM  */
#line 259 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                 { yyval = YY(T_STRUCT); }
#line 2040 "y.tab.c"
    break;

  case 42: /* struct_or_union: UNION_SYM  */
#line 260 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                { yyval = YY(T_UNION); }
#line 2046 "y.tab.c"
    break;

  case 43: /* struct_declaration_list: struct_declaration  */
#line 264 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                         { yyval = yyvsp[0]; }
#line 2052 "y.tab.c"
    break;

  case 44: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 266 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-1]), PTR(A_ID, yyvsp[0])));
    }
#line 2060 "y.tab.c"
    break;

  case 45: /* struct_declaration: type_specifier struct_declarator_list SEMICOLON  */
#line 273 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setStructDeclaratorListSpecifier(PTR(A_ID, yyvsp[-1]), PTR(A_TYPE, yyvsp[-2])));
    }
#line 2068 "y.tab.c"
    break;

  case 46: /* struct_declarator_list: struct_declarator  */
#line 279 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                        { yyval = yyvsp[0]; }
#line 2074 "y.tab.c"
    break;

  case 47: /* struct_declarator_list: struct_declarator_list COMMA struct_declarator  */
#line 281 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 2082 "y.tab.c"
    break;

  case 48: /* struct_declarator: declarator  */
#line 287 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                 { yyval = yyvsp[0]; }
#line 2088 "y.tab.c"
    break;

  case 49: /* struct_declarator: COLON constant_expression  */
#line 289 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Bit-fields are not implemented");
      yyval = YY(NULL);
    }
#line 2097 "y.tab.c"
    break;

  case 50: /* struct_declarator: declarator COLON constant_expression  */
#line 294 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Bit-fields are not implemented");
      yyval = YY(NULL);
    }
#line 2106 "y.tab.c"
    break;

  case 51: /* @5: %empty  */
#line 302 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeStructOrEnumIdentifier(T_ENUM, PTR(char, yyvsp[0]), ID_ENUM));
    }
#line 2114 "y.tab.c"
    break;

  case 52: /* enum_specifier: ENUM_SYM IDENTIFIER @5 LR enumerator_list RR  */
#line 306 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 2122 "y.tab.c"
    break;

  case 53: /* @6: %empty  */
#line 310 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeType(T_ENUM));
    }
#line 2130 "y.tab.c"
    break;

  case 54: /* enum_specifier: ENUM_SYM @6 LR enumerator_list RR  */
#line 314 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 2138 "y.tab.c"
    break;

  case 55: /* enum_specifier: ENUM_SYM IDENTIFIER  */
#line 318 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(getTypeOfStructOrEnumIdentifier(T_ENUM, PTR(char, yyvsp[0]), ID_ENUM));
    }
#line 2146 "y.tab.c"
    break;

  case 56: /* enumerator_list: enumerator  */
#line 324 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                 { yyval = yyvsp[0]; }
#line 2152 "y.tab.c"
    break;

  case 57: /* enumerator_list: enumerator_list COMMA enumerator  */
#line 326 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 2160 "y.tab.c"
    break;

  case 58: /* enumerator: IDENTIFIER  */
#line 333 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      A_ID *id = makeIdentifier(name);
      free(name);

      yyval = YY(setDeclaratorKind(id, ID_ENUM_LITERAL));
    }
#line 2172 "y.tab.c"
    break;

  case 59: /* enumerator: IDENTIFIER ASSIGN constant_expression  */
#line 341 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Enumerator initializers are not supported");
      yyval = YY(NULL);
    }
#line 2181 "y.tab.c"
    break;

  case 60: /* declarator: pointer direct_declarator  */
#line 349 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[0]), PTR(A_TYPE, yyvsp[-1])));
    }
#line 2189 "y.tab.c"
    break;

  case 61: /* declarator: direct_declarator  */
#line 353 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2197 "y.tab.c"
    break;

  case 62: /* pointer: STAR type_qualifier_list_opt  */
#line 360 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeType(T_POINTER));
    }
#line 2205 "y.tab.c"
    break;

  case 63: /* pointer: STAR type_qualifier_list_opt pointer  */
#line 364 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[0]), makeType(T_POINTER)));
    }
#line 2213 "y.tab.c"
    break;

  case 68: /* direct_declarator: IDENTIFIER  */
#line 381 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);

      A_ID *id = makeIdentifier(name);
      free(name);

      yyval = YY(id);
    }
#line 2226 "y.tab.c"
    break;

  case 69: /* direct_declarator: LP declarator RP  */
#line 390 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[-1];
    }
#line 2234 "y.tab.c"
    break;

  case 70: /* direct_declarator: direct_declarator LB constant_expression_opt RB  */
#line 394 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[-3]),
                                       setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1]))));
    }
#line 2243 "y.tab.c"
    break;

  case 71: /* direct_declarator: direct_declarator LP parameter_type_list_opt RP  */
#line 399 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[-3]),
                                       setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1]))));
    }
#line 2252 "y.tab.c"
    break;

  case 72: /* constant_expression_opt: %empty  */
#line 407 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2260 "y.tab.c"
    break;

  case 73: /* constant_expression_opt: constant_expression  */
#line 411 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2268 "y.tab.c"
    break;

  case 74: /* parameter_type_list_opt: %empty  */
#line 418 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2276 "y.tab.c"
    break;

  case 75: /* parameter_type_list_opt: parameter_type_list  */
#line 422 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2284 "y.tab.c"
    break;

  case 77: /* parameter_type_list: parameter_list COMMA DOTDOTDOT  */
#line 430 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Variadic parameters are not supported");
      yyval = YY(NULL);
    }
#line 2293 "y.tab.c"
    break;

  case 78: /* parameter_list: parameter_declaration  */
#line 438 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2301 "y.tab.c"
    break;

  case 79: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 442 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 2309 "y.tab.c"
    break;

  case 80: /* parameter_declaration: declaration_specifiers declarator  */
#line 449 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setParameterDeclaratorSpecifier(PTR(A_ID, yyvsp[0]), PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2317 "y.tab.c"
    break;

  case 81: /* parameter_declaration: declaration_specifiers abstract_declarator_opt  */
#line 453 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = makeDummyIdentifier();

      setDeclaratorElementType(id, PTR(A_TYPE, yyvsp[0]));

      yyval = YY(setParameterDeclaratorSpecifier(id, PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2329 "y.tab.c"
    break;

  case 82: /* abstract_declarator_opt: %empty  */
#line 464 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2337 "y.tab.c"
    break;

  case 83: /* abstract_declarator_opt: abstract_declarator  */
#line 468 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2345 "y.tab.c"
    break;

  case 84: /* abstract_declarator: pointer  */
#line 475 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2353 "y.tab.c"
    break;

  case 85: /* abstract_declarator: direct_abstract_declarator  */
#line 479 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2361 "y.tab.c"
    break;

  case 86: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 483 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[0]), PTR(A_TYPE, yyvsp[-1])));
    }
#line 2369 "y.tab.c"
    break;

  case 87: /* direct_abstract_declarator: LP abstract_declarator RP  */
#line 490 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[-1];
    }
#line 2377 "y.tab.c"
    break;

  case 88: /* direct_abstract_declarator: LB constant_expression_opt RB  */
#line 494 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1])));
    }
#line 2385 "y.tab.c"
    break;

  case 89: /* direct_abstract_declarator: LP parameter_type_list_opt RP  */
#line 498 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1])));
    }
#line 2393 "y.tab.c"
    break;

  case 90: /* direct_abstract_declarator: direct_abstract_declarator LB constant_expression_opt RB  */
#line 502 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[-3]),
                                 setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1]))));
    }
#line 2402 "y.tab.c"
    break;

  case 91: /* direct_abstract_declarator: direct_abstract_declarator LP parameter_type_list_opt RP  */
#line 507 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[-3]),
                                 setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1]))));
    }
#line 2411 "y.tab.c"
    break;

  case 92: /* initializer: assignment_expression  */
#line 515 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Initializers are not supported");
      yyval = YY(NULL);
    }
#line 2420 "y.tab.c"
    break;

  case 93: /* initializer: LR initializer_list RR  */
#line 520 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Initializers are not supported");
      yyval = YY(NULL);
    }
#line 2429 "y.tab.c"
    break;

  case 94: /* initializer: LR initializer_list COMMA RR  */
#line 525 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Initializers are not supported");
      yyval = YY(NULL);
    }
#line 2438 "y.tab.c"
    break;

  case 95: /* initializer_list: initializer  */
#line 533 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Initializers are not supported");
      yyval = YY(NULL);
    }
#line 2447 "y.tab.c"
    break;

  case 96: /* initializer_list: initializer_list COMMA initializer  */
#line 538 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Initializers are not supported");
      yyval = YY(NULL);
    }
#line 2456 "y.tab.c"
    break;

  case 97: /* statement: labeled_statement  */
#line 545 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                        { yyval = yyvsp[0]; }
#line 2462 "y.tab.c"
    break;

  case 98: /* statement: scoped_compound_statement  */
#line 547 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2470 "y.tab.c"
    break;

  case 99: /* statement: expression_statement  */
#line 551 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2478 "y.tab.c"
    break;

  case 100: /* statement: selection_statement  */
#line 554 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2484 "y.tab.c"
    break;

  case 101: /* statement: iteration_statement  */
#line 555 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2490 "y.tab.c"
    break;

  case 102: /* statement: jump_statement  */
#line 557 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2498 "y.tab.c"
    break;

  case 103: /* $@7: %empty  */
#line 564 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      enterScope();
    }
#line 2506 "y.tab.c"
    break;

  case 104: /* scoped_compound_statement: $@7 compound_statement  */
#line 568 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
      leaveScope();
    }
#line 2515 "y.tab.c"
    break;

  case 105: /* labeled_statement: CASE_SYM constant_expression COLON statement  */
#line 576 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LABEL_CASE, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2523 "y.tab.c"
    break;

  case 106: /* labeled_statement: DEFAULT_SYM COLON statement  */
#line 580 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LABEL_DEFAULT, NULL, NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2531 "y.tab.c"
    break;

  case 107: /* labeled_statement: IDENTIFIER COLON statement  */
#line 584 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("User labels are not supported");
      yyval = YY(NULL);
    }
#line 2540 "y.tab.c"
    break;

  case 108: /* compound_statement: LR declaration_list_opt statement_list_opt RR  */
#line 592 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_COMPOUND, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[-1])));

      compound_root = PTR(A_NODE, yyval);
    }
#line 2550 "y.tab.c"
    break;

  case 109: /* declaration_list: declaration  */
#line 601 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2558 "y.tab.c"
    break;

  case 110: /* declaration_list: declaration_list declaration  */
#line 605 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-1]), PTR(A_ID, yyvsp[0])));
    }
#line 2566 "y.tab.c"
    break;

  case 111: /* statement_list_opt: %empty  */
#line 612 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL));
    }
#line 2574 "y.tab.c"
    break;

  case 112: /* statement_list_opt: statement_list  */
#line 616 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2582 "y.tab.c"
    break;

  case 113: /* statement_list: statement  */
#line 623 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LIST, PTR(A_NODE, yyvsp[0]), NULL,
                       makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL)));
    }
#line 2591 "y.tab.c"
    break;

  case 114: /* statement_list: statement_list statement  */
#line 628 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNodeList(N_STMT_LIST, PTR(A_NODE, yyvsp[-1]), PTR(A_NODE, yyvsp[0])));
    }
#line 2599 "y.tab.c"
    break;

  case 115: /* expression_statement: SEMICOLON  */
#line 635 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_EMPTY, NULL, NULL, NULL));
    }
#line 2607 "y.tab.c"
    break;

  case 116: /* expression_statement: expression SEMICOLON  */
#line 639 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_EXPRESSION, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2615 "y.tab.c"
    break;

  case 117: /* selection_statement: IF_SYM LP expression RP statement  */
#line 646 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_IF, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2623 "y.tab.c"
    break;

  case 118: /* selection_statement: IF_SYM LP expression RP statement ELSE_SYM statement  */
#line 650 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_IF_ELSE, PTR(A_NODE, yyvsp[-4]), PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2631 "y.tab.c"
    break;

  case 119: /* selection_statement: SWITCH_SYM LP expression RP statement  */
#line 654 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_SWITCH, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2639 "y.tab.c"
    break;

  case 120: /* iteration_statement: WHILE_SYM LP expression RP statement  */
#line 661 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_WHILE, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2647 "y.tab.c"
    break;

  case 121: /* iteration_statement: DO_SYM statement WHILE_SYM LP expression RP SEMICOLON  */
#line 665 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_DO, PTR(A_NODE, yyvsp[-5]), NULL, PTR(A_NODE, yyvsp[-2])));
    }
#line 2655 "y.tab.c"
    break;

  case 122: /* iteration_statement: FOR_SYM LP for_expression RP statement  */
#line 669 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_FOR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2663 "y.tab.c"
    break;

  case 123: /* expression_opt: %empty  */
#line 676 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2671 "y.tab.c"
    break;

  case 124: /* expression_opt: expression  */
#line 680 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2679 "y.tab.c"
    break;

  case 125: /* for_expression: expression_opt SEMICOLON expression_opt SEMICOLON expression_opt  */
#line 687 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_FOR_EXP, PTR(A_NODE, yyvsp[-4]), PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2687 "y.tab.c"
    break;

  case 126: /* jump_statement: RETURN_SYM expression_opt SEMICOLON  */
#line 694 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_RETURN, NULL, PTR(A_NODE, yyvsp[-1]), NULL));

      statement_root = PTR(A_NODE, yyval);
    }
#line 2697 "y.tab.c"
    break;

  case 127: /* jump_statement: CONTINUE_SYM SEMICOLON  */
#line 700 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_CONTINUE, NULL, NULL, NULL));
    }
#line 2705 "y.tab.c"
    break;

  case 128: /* jump_statement: BREAK_SYM SEMICOLON  */
#line 704 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_BREAK, NULL, NULL, NULL));
    }
#line 2713 "y.tab.c"
    break;

  case 129: /* jump_statement: GOTO_SYM IDENTIFIER SEMICOLON  */
#line 708 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("goto is not supported");
      yyval = YY(NULL);
    }
#line 2722 "y.tab.c"
    break;

  case 130: /* primary_expression: IDENTIFIER  */
#line 716 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      A_ID *id = getIdentifierDeclared(name);
      free(name);

      yyval = YY(makeNode(N_EXP_IDENT, NULL, PTR(A_NODE, id), NULL));
    }
#line 2734 "y.tab.c"
    break;

  case 131: /* primary_expression: INTEGER_CONSTANT  */
#line 724 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_INT_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));

      A_NODE *node = PTR(A_NODE, yyval);
      logMsg(LOG_DEBUG, "N_EXP_INT_CONST: %lld", (long long)(intptr_t)node->clink);
    }
#line 2745 "y.tab.c"
    break;

  case 132: /* primary_expression: FLOAT_CONSTANT  */
#line 731 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_FLOAT_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2753 "y.tab.c"
    break;

  case 133: /* primary_expression: CHARACTER_CONSTANT  */
#line 735 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_CHAR_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2761 "y.tab.c"
    break;

  case 134: /* primary_expression: STRING_LITERAL  */
#line 739 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_STRING_LITERAL, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2769 "y.tab.c"
    break;

  case 135: /* primary_expression: LP expression RP  */
#line 743 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[-1];
    }
#line 2777 "y.tab.c"
    break;

  case 136: /* postfix_expression: primary_expression  */
#line 750 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2785 "y.tab.c"
    break;

  case 137: /* postfix_expression: postfix_expression LB expression RB  */
#line 754 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ARRAY, PTR(A_NODE, yyvsp[-3]), NULL, PTR(A_NODE, yyvsp[-1])));
    }
#line 2793 "y.tab.c"
    break;

  case 138: /* postfix_expression: postfix_expression LP arg_expression_list_opt RP  */
#line 758 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_FUNCTION_CALL, PTR(A_NODE, yyvsp[-3]), NULL, PTR(A_NODE, yyvsp[-1])));
    }
#line 2801 "y.tab.c"
    break;

  case 139: /* postfix_expression: postfix_expression PERIOD IDENTIFIER  */
#line 762 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(makeNode(N_EXP_STRUCT, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, name)));
    }
#line 2810 "y.tab.c"
    break;

  case 140: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 767 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(makeNode(N_EXP_ARROW, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, name)));
    }
#line 2819 "y.tab.c"
    break;

  case 141: /* postfix_expression: postfix_expression PLUSPLUS  */
#line 772 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_POST_INC, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2827 "y.tab.c"
    break;

  case 142: /* postfix_expression: postfix_expression MINUSMINUS  */
#line 776 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_POST_DEC, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2835 "y.tab.c"
    break;

  case 143: /* arg_expression_list_opt: %empty  */
#line 783 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_ARG_LIST_NIL, NULL, NULL, NULL));
    }
#line 2843 "y.tab.c"
    break;

  case 144: /* arg_expression_list_opt: arg_expression_list  */
#line 786 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2849 "y.tab.c"
    break;

  case 145: /* arg_expression_list: assignment_expression  */
#line 791 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_ARG_LIST, PTR(A_NODE, yyvsp[0]), NULL,
                       makeNode(N_ARG_LIST_NIL, NULL, NULL, NULL)));
    }
#line 2858 "y.tab.c"
    break;

  case 146: /* arg_expression_list: arg_expression_list COMMA assignment_expression  */
#line 796 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNodeList(N_ARG_LIST, PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2866 "y.tab.c"
    break;

  case 147: /* unary_expression: postfix_expression  */
#line 803 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2874 "y.tab.c"
    break;

  case 148: /* unary_expression: PLUSPLUS unary_expression  */
#line 807 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_PRE_INC, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2882 "y.tab.c"
    break;

  case 149: /* unary_expression: MINUSMINUS unary_expression  */
#line 811 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_PRE_DEC, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2890 "y.tab.c"
    break;

  case 150: /* unary_expression: AMP cast_expression  */
#line 815 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_AMP, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2898 "y.tab.c"
    break;

  case 151: /* unary_expression: STAR cast_expression  */
#line 819 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_STAR, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2906 "y.tab.c"
    break;

  case 152: /* unary_expression: EXCL cast_expression  */
#line 823 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_NOT, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2914 "y.tab.c"
    break;

  case 153: /* unary_expression: MINUS cast_expression  */
#line 827 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MINUS, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2922 "y.tab.c"
    break;

  case 154: /* unary_expression: TILDE cast_expression  */
#line 831 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Bitwise complement is not supported");
      yyval = YY(NULL);
    }
#line 2931 "y.tab.c"
    break;

  case 155: /* unary_expression: PLUS cast_expression  */
#line 836 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2939 "y.tab.c"
    break;

  case 156: /* unary_expression: SIZEOF_SYM unary_expression  */
#line 840 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_SIZE_EXP, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2947 "y.tab.c"
    break;

  case 157: /* unary_expression: SIZEOF_SYM LP type_name RP  */
#line 844 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_SIZE_TYPE, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2955 "y.tab.c"
    break;

  case 158: /* cast_expression: unary_expression  */
#line 851 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2963 "y.tab.c"
    break;

  case 159: /* cast_expression: LP type_name RP cast_expression  */
#line 855 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_CAST, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2971 "y.tab.c"
    break;

  case 160: /* type_name: declaration_specifiers abstract_declarator_opt  */
#line 862 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeNameSpecifier(PTR(A_TYPE, yyvsp[0]), PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2979 "y.tab.c"
    break;

  case 161: /* multiplicative_expression: cast_expression  */
#line 869 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2987 "y.tab.c"
    break;

  case 162: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 873 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MUL, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2995 "y.tab.c"
    break;

  case 163: /* multiplicative_expression: multiplicative_expression SLASH cast_expression  */
#line 877 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_DIV, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3003 "y.tab.c"
    break;

  case 164: /* multiplicative_expression: multiplicative_expression PERCENT cast_expression  */
#line 881 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MOD, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3011 "y.tab.c"
    break;

  case 165: /* additive_expression: multiplicative_expression  */
#line 888 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 3019 "y.tab.c"
    break;

  case 166: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 892 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ADD, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3027 "y.tab.c"
    break;

  case 167: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 896 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_SUB, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3035 "y.tab.c"
    break;

  case 168: /* shift_expression: additive_expression  */
#line 902 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 3041 "y.tab.c"
    break;

  case 169: /* shift_expression: shift_expression LSHIFT additive_expression  */
#line 904 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Left shift is not supported");
      yyval = YY(NULL);
    }
#line 3050 "y.tab.c"
    break;

  case 170: /* shift_expression: shift_expression RSHIFT additive_expression  */
#line 909 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Right shift is not supported");
      yyval = YY(NULL);
    }
#line 3059 "y.tab.c"
    break;

  case 171: /* relational_expression: shift_expression  */
#line 917 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 3067 "y.tab.c"
    break;

  case 172: /* relational_expression: relational_expression LSS shift_expression  */
#line 921 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_LSS, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3075 "y.tab.c"
    break;

  case 173: /* relational_expression: relational_expression GTR shift_expression  */
#line 925 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_GTR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3083 "y.tab.c"
    break;

  case 174: /* relational_expression: relational_expression LEQ shift_expression  */
#line 929 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_LEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3091 "y.tab.c"
    break;

  case 175: /* relational_expression: relational_expression GEQ shift_expression  */
#line 933 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_GEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3099 "y.tab.c"
    break;

  case 176: /* equality_expression: relational_expression  */
#line 940 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 3107 "y.tab.c"
    break;

  case 177: /* equality_expression: equality_expression EQL relational_expression  */
#line 944 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_EQL, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3115 "y.tab.c"
    break;

  case 178: /* equality_expression: equality_expression NEQ relational_expression  */
#line 948 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_NEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3123 "y.tab.c"
    break;

  case 179: /* AND_expression: equality_expression  */
#line 954 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 3129 "y.tab.c"
    break;

  case 180: /* AND_expression: AND_expression AMP equality_expression  */
#line 956 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Bitwise AND is not supported");
      yyval = YY(NULL);
    }
#line 3138 "y.tab.c"
    break;

  case 181: /* exclusive_OR_expression: AND_expression  */
#line 963 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                     { yyval = yyvsp[0]; }
#line 3144 "y.tab.c"
    break;

  case 182: /* exclusive_OR_expression: exclusive_OR_expression CARET AND_expression  */
#line 965 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Bitwise XOR is not supported");
      yyval = YY(NULL);
    }
#line 3153 "y.tab.c"
    break;

  case 183: /* inclusive_OR_expression: exclusive_OR_expression  */
#line 972 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                              { yyval = yyvsp[0]; }
#line 3159 "y.tab.c"
    break;

  case 184: /* inclusive_OR_expression: inclusive_OR_expression BAR exclusive_OR_expression  */
#line 974 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Bitwise OR is not supported");
      yyval = YY(NULL);
    }
#line 3168 "y.tab.c"
    break;

  case 185: /* logical_AND_expression: inclusive_OR_expression  */
#line 981 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                              { yyval = yyvsp[0]; }
#line 3174 "y.tab.c"
    break;

  case 186: /* logical_AND_expression: logical_AND_expression AMPAMP inclusive_OR_expression  */
#line 983 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_AND, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3182 "y.tab.c"
    break;

  case 187: /* logical_OR_expression: logical_AND_expression  */
#line 989 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                             { yyval = yyvsp[0]; }
#line 3188 "y.tab.c"
    break;

  case 188: /* logical_OR_expression: logical_OR_expression BARBAR logical_AND_expression  */
#line 991 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_OR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3196 "y.tab.c"
    break;

  case 189: /* conditional_expression: logical_OR_expression  */
#line 998 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 3204 "y.tab.c"
    break;

  case 190: /* conditional_expression: logical_OR_expression QUESTION expression COLON conditional_expression  */
#line 1002 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Conditional operator is not supported");
      yyval = YY(NULL);
    }
#line 3213 "y.tab.c"
    break;

  case 191: /* assignment_expression: conditional_expression  */
#line 1010 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 3221 "y.tab.c"
    break;

  case 192: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 1014 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ASSIGN, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3229 "y.tab.c"
    break;

  case 193: /* comma_expression: assignment_expression  */
#line 1021 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 3237 "y.tab.c"
    break;

  case 194: /* comma_expression: comma_expression COMMA assignment_expression  */
#line 1025 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Comma expressions are not supported");
      yyval = YY(NULL);
    }
#line 3246 "y.tab.c"
    break;

  case 195: /* expression: comma_expression  */
#line 1033 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
      expression_root = PTR(A_NODE, yyvsp[0]);
    }
#line 3255 "y.tab.c"
    break;


#line 3259 "y.tab.c"

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

#line 1042 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"

int yyerror(const char *s) {
  logMsg(LOG_ERROR, "Syntax error at line %d: %s", line_no, s);
  return 0;
}
