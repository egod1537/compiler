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
     204,   211,   215,   219,   220,   221,   229,   228,   239,   238,
     246,   255,   256,   260,   261,   268,   275,   276,   283,   284,
     289,   298,   297,   306,   305,   313,   320,   321,   328,   336,
     340,   344,   351,   355,   362,   363,   367,   368,   372,   381,
     385,   390,   399,   402,   410,   413,   420,   421,   425,   429,
     436,   440,   452,   455,   462,   466,   470,   477,   481,   485,
     489,   494,   502,   503,   504,   508,   509,   513,   514,   518,
     522,   523,   524,   532,   532,   543,   547,   551,   555,   564,
     568,   576,   579,   586,   591,   598,   602,   609,   613,   617,
     624,   628,   632,   640,   643,   650,   657,   663,   667,   671,
     675,   683,   690,   694,   698,   702,   709,   713,   717,   721,
     726,   731,   735,   743,   746,   750,   755,   762,   766,   770,
     774,   778,   782,   786,   790,   791,   795,   799,   806,   810,
     817,   824,   828,   832,   836,   843,   847,   851,   858,   859,
     860,   864,   868,   872,   876,   880,   887,   891,   895,   902,
     903,   907,   908,   912,   913,   917,   918,   925,   926,   933,
     934,   938,   942,   949,   950,   954,   962
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

  case 35: /* type_specifier: TYPE_IDENTIFIER  */
#line 222 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 1981 "y.tab.c"
    break;

  case 36: /* @3: %empty  */
#line 229 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(setTypeStructOrEnumIdentifier((T_KIND)yyvsp[-1], name, ID_STRUCT));
      free(name);
    }
#line 1991 "y.tab.c"
    break;

  case 37: /* struct_specifier: struct_or_union IDENTIFIER @3 LR struct_declaration_list RR  */
#line 235 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 1999 "y.tab.c"
    break;

  case 38: /* @4: %empty  */
#line 239 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeType((T_KIND)yyvsp[0]));
    }
#line 2007 "y.tab.c"
    break;

  case 39: /* struct_specifier: struct_or_union @4 LR struct_declaration_list RR  */
#line 243 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 2015 "y.tab.c"
    break;

  case 40: /* struct_specifier: struct_or_union IDENTIFIER  */
#line 247 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(getTypeOfStructOrEnumIdentifier((T_KIND)yyvsp[-1], name, ID_STRUCT));
      free(name);
    }
#line 2025 "y.tab.c"
    break;

  case 41: /* struct_or_union: STRUCT_SYM  */
#line 255 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                 { yyval = YY(T_STRUCT); }
#line 2031 "y.tab.c"
    break;

  case 42: /* struct_or_union: UNION_SYM  */
#line 256 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                { yyval = YY(T_UNION); }
#line 2037 "y.tab.c"
    break;

  case 43: /* struct_declaration_list: struct_declaration  */
#line 260 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                         { yyval = yyvsp[0]; }
#line 2043 "y.tab.c"
    break;

  case 44: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 262 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-1]), PTR(A_ID, yyvsp[0])));
    }
#line 2051 "y.tab.c"
    break;

  case 45: /* struct_declaration: type_specifier struct_declarator_list SEMICOLON  */
#line 269 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setStructDeclaratorListSpecifier(PTR(A_ID, yyvsp[-1]), PTR(A_TYPE, yyvsp[-2])));
    }
#line 2059 "y.tab.c"
    break;

  case 46: /* struct_declarator_list: struct_declarator  */
#line 275 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                        { yyval = yyvsp[0]; }
#line 2065 "y.tab.c"
    break;

  case 47: /* struct_declarator_list: struct_declarator_list COMMA struct_declarator  */
#line 277 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 2073 "y.tab.c"
    break;

  case 48: /* struct_declarator: declarator  */
#line 283 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                 { yyval = yyvsp[0]; }
#line 2079 "y.tab.c"
    break;

  case 49: /* struct_declarator: COLON constant_expression  */
#line 285 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Bit-fields are not implemented");
      yyval = YY(NULL);
    }
#line 2088 "y.tab.c"
    break;

  case 50: /* struct_declarator: declarator COLON constant_expression  */
#line 290 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      semanticError("Bit-fields are not implemented");
      yyval = YY(NULL);
    }
#line 2097 "y.tab.c"
    break;

  case 51: /* @5: %empty  */
#line 298 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeStructOrEnumIdentifier(T_ENUM, PTR(char, yyvsp[0]), ID_ENUM));
    }
#line 2105 "y.tab.c"
    break;

  case 52: /* enum_specifier: ENUM_SYM IDENTIFIER @5 LR enumerator_list RR  */
#line 302 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 2113 "y.tab.c"
    break;

  case 53: /* @6: %empty  */
#line 306 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeType(T_ENUM));
    }
#line 2121 "y.tab.c"
    break;

  case 54: /* enum_specifier: ENUM_SYM @6 LR enumerator_list RR  */
#line 310 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 2129 "y.tab.c"
    break;

  case 55: /* enum_specifier: ENUM_SYM IDENTIFIER  */
#line 314 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(getTypeOfStructOrEnumIdentifier(T_ENUM, PTR(char, yyvsp[0]), ID_ENUM));
    }
#line 2137 "y.tab.c"
    break;

  case 56: /* enumerator_list: enumerator  */
#line 320 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                 { yyval = yyvsp[0]; }
#line 2143 "y.tab.c"
    break;

  case 57: /* enumerator_list: enumerator_list COMMA enumerator  */
#line 322 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 2151 "y.tab.c"
    break;

  case 58: /* enumerator: IDENTIFIER  */
#line 329 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      A_ID *id = makeIdentifier(name);
      free(name);

      yyval = YY(setDeclaratorKind(id, ID_ENUM_LITERAL));
    }
#line 2163 "y.tab.c"
    break;

  case 60: /* declarator: pointer direct_declarator  */
#line 341 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[0]), PTR(A_TYPE, yyvsp[-1])));
    }
#line 2171 "y.tab.c"
    break;

  case 61: /* declarator: direct_declarator  */
#line 345 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2179 "y.tab.c"
    break;

  case 62: /* pointer: STAR type_qualifier_list_opt  */
#line 352 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeType(T_POINTER));
    }
#line 2187 "y.tab.c"
    break;

  case 63: /* pointer: STAR type_qualifier_list_opt pointer  */
#line 356 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[0]), makeType(T_POINTER)));
    }
#line 2195 "y.tab.c"
    break;

  case 68: /* direct_declarator: IDENTIFIER  */
#line 373 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);

      A_ID *id = makeIdentifier(name);
      free(name);

      yyval = YY(id);
    }
#line 2208 "y.tab.c"
    break;

  case 69: /* direct_declarator: LP declarator RP  */
#line 382 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[-1];
    }
#line 2216 "y.tab.c"
    break;

  case 70: /* direct_declarator: direct_declarator LB constant_expression_opt RB  */
#line 386 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[-3]),
                                       setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1]))));
    }
#line 2225 "y.tab.c"
    break;

  case 71: /* direct_declarator: direct_declarator LP parameter_type_list_opt RP  */
#line 391 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[-3]),
                                       setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1]))));
    }
#line 2234 "y.tab.c"
    break;

  case 72: /* constant_expression_opt: %empty  */
#line 399 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2242 "y.tab.c"
    break;

  case 73: /* constant_expression_opt: constant_expression  */
#line 403 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2250 "y.tab.c"
    break;

  case 74: /* parameter_type_list_opt: %empty  */
#line 410 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2258 "y.tab.c"
    break;

  case 75: /* parameter_type_list_opt: parameter_type_list  */
#line 414 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2266 "y.tab.c"
    break;

  case 78: /* parameter_list: parameter_declaration  */
#line 426 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2274 "y.tab.c"
    break;

  case 79: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 430 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 2282 "y.tab.c"
    break;

  case 80: /* parameter_declaration: declaration_specifiers declarator  */
#line 437 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setParameterDeclaratorSpecifier(PTR(A_ID, yyvsp[0]), PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2290 "y.tab.c"
    break;

  case 81: /* parameter_declaration: declaration_specifiers abstract_declarator_opt  */
#line 441 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = makeDummyIdentifier();

      setDeclaratorElementType(id, PTR(A_TYPE, yyvsp[0]));

      yyval = YY(setParameterDeclaratorSpecifier(id, PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2302 "y.tab.c"
    break;

  case 82: /* abstract_declarator_opt: %empty  */
#line 452 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2310 "y.tab.c"
    break;

  case 83: /* abstract_declarator_opt: abstract_declarator  */
#line 456 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2318 "y.tab.c"
    break;

  case 84: /* abstract_declarator: pointer  */
#line 463 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2326 "y.tab.c"
    break;

  case 85: /* abstract_declarator: direct_abstract_declarator  */
#line 467 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2334 "y.tab.c"
    break;

  case 86: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 471 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[0]), PTR(A_TYPE, yyvsp[-1])));
    }
#line 2342 "y.tab.c"
    break;

  case 87: /* direct_abstract_declarator: LP abstract_declarator RP  */
#line 478 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[-1];
    }
#line 2350 "y.tab.c"
    break;

  case 88: /* direct_abstract_declarator: LB constant_expression_opt RB  */
#line 482 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1])));
    }
#line 2358 "y.tab.c"
    break;

  case 89: /* direct_abstract_declarator: LP parameter_type_list_opt RP  */
#line 486 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1])));
    }
#line 2366 "y.tab.c"
    break;

  case 90: /* direct_abstract_declarator: direct_abstract_declarator LB constant_expression_opt RB  */
#line 490 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[-3]),
                                 setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1]))));
    }
#line 2375 "y.tab.c"
    break;

  case 91: /* direct_abstract_declarator: direct_abstract_declarator LP parameter_type_list_opt RP  */
#line 495 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[-3]),
                                 setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1]))));
    }
#line 2384 "y.tab.c"
    break;

  case 97: /* statement: labeled_statement  */
#line 513 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                        { yyval = yyvsp[0]; }
#line 2390 "y.tab.c"
    break;

  case 98: /* statement: scoped_compound_statement  */
#line 515 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2398 "y.tab.c"
    break;

  case 99: /* statement: expression_statement  */
#line 519 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2406 "y.tab.c"
    break;

  case 100: /* statement: selection_statement  */
#line 522 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2412 "y.tab.c"
    break;

  case 101: /* statement: iteration_statement  */
#line 523 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2418 "y.tab.c"
    break;

  case 102: /* statement: jump_statement  */
#line 525 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2426 "y.tab.c"
    break;

  case 103: /* $@7: %empty  */
#line 532 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      enterScope();
    }
#line 2434 "y.tab.c"
    break;

  case 104: /* scoped_compound_statement: $@7 compound_statement  */
#line 536 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
      leaveScope();
    }
#line 2443 "y.tab.c"
    break;

  case 105: /* labeled_statement: CASE_SYM constant_expression COLON statement  */
#line 544 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LABEL_CASE, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2451 "y.tab.c"
    break;

  case 106: /* labeled_statement: DEFAULT_SYM COLON statement  */
#line 548 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LABEL_DEFAULT, NULL, NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2459 "y.tab.c"
    break;

  case 108: /* compound_statement: LR declaration_list_opt statement_list_opt RR  */
#line 556 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_COMPOUND, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[-1])));

      compound_root = PTR(A_NODE, yyval);
    }
#line 2469 "y.tab.c"
    break;

  case 109: /* declaration_list: declaration  */
#line 565 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2477 "y.tab.c"
    break;

  case 110: /* declaration_list: declaration_list declaration  */
#line 569 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-1]), PTR(A_ID, yyvsp[0])));
    }
#line 2485 "y.tab.c"
    break;

  case 111: /* statement_list_opt: %empty  */
#line 576 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL));
    }
#line 2493 "y.tab.c"
    break;

  case 112: /* statement_list_opt: statement_list  */
#line 580 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2501 "y.tab.c"
    break;

  case 113: /* statement_list: statement  */
#line 587 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LIST, PTR(A_NODE, yyvsp[0]), NULL,
                       makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL)));
    }
#line 2510 "y.tab.c"
    break;

  case 114: /* statement_list: statement_list statement  */
#line 592 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNodeList(N_STMT_LIST, PTR(A_NODE, yyvsp[-1]), PTR(A_NODE, yyvsp[0])));
    }
#line 2518 "y.tab.c"
    break;

  case 115: /* expression_statement: SEMICOLON  */
#line 599 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_EMPTY, NULL, NULL, NULL));
    }
#line 2526 "y.tab.c"
    break;

  case 116: /* expression_statement: expression SEMICOLON  */
#line 603 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_EXPRESSION, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2534 "y.tab.c"
    break;

  case 117: /* selection_statement: IF_SYM LP expression RP statement  */
#line 610 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_IF, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2542 "y.tab.c"
    break;

  case 118: /* selection_statement: IF_SYM LP expression RP statement ELSE_SYM statement  */
#line 614 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_IF_ELSE, PTR(A_NODE, yyvsp[-4]), PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2550 "y.tab.c"
    break;

  case 119: /* selection_statement: SWITCH_SYM LP expression RP statement  */
#line 618 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_SWITCH, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2558 "y.tab.c"
    break;

  case 120: /* iteration_statement: WHILE_SYM LP expression RP statement  */
#line 625 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_WHILE, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2566 "y.tab.c"
    break;

  case 121: /* iteration_statement: DO_SYM statement WHILE_SYM LP expression RP SEMICOLON  */
#line 629 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_DO, PTR(A_NODE, yyvsp[-5]), NULL, PTR(A_NODE, yyvsp[-2])));
    }
#line 2574 "y.tab.c"
    break;

  case 122: /* iteration_statement: FOR_SYM LP for_expression RP statement  */
#line 633 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_FOR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2582 "y.tab.c"
    break;

  case 123: /* expression_opt: %empty  */
#line 640 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(NULL);
    }
#line 2590 "y.tab.c"
    break;

  case 124: /* expression_opt: expression  */
#line 644 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2598 "y.tab.c"
    break;

  case 125: /* for_expression: expression_opt SEMICOLON expression_opt SEMICOLON expression_opt  */
#line 651 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_FOR_EXP, PTR(A_NODE, yyvsp[-4]), PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2606 "y.tab.c"
    break;

  case 126: /* jump_statement: RETURN_SYM expression_opt SEMICOLON  */
#line 658 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_RETURN, NULL, PTR(A_NODE, yyvsp[-1]), NULL));

      statement_root = PTR(A_NODE, yyval);
    }
#line 2616 "y.tab.c"
    break;

  case 127: /* jump_statement: CONTINUE_SYM SEMICOLON  */
#line 664 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_CONTINUE, NULL, NULL, NULL));
    }
#line 2624 "y.tab.c"
    break;

  case 128: /* jump_statement: BREAK_SYM SEMICOLON  */
#line 668 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_BREAK, NULL, NULL, NULL));
    }
#line 2632 "y.tab.c"
    break;

  case 130: /* primary_expression: IDENTIFIER  */
#line 676 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      A_ID *id = getIdentifierDeclared(name);
      free(name);

      yyval = YY(makeNode(N_EXP_IDENT, NULL, PTR(A_NODE, id), NULL));
    }
#line 2644 "y.tab.c"
    break;

  case 131: /* primary_expression: INTEGER_CONSTANT  */
#line 684 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_INT_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));

      A_NODE *node = PTR(A_NODE, yyval);
      logMsg(LOG_DEBUG, "N_EXP_INT_CONST: %lld", (long long)(intptr_t)node->clink);
    }
#line 2655 "y.tab.c"
    break;

  case 132: /* primary_expression: FLOAT_CONSTANT  */
#line 691 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_FLOAT_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2663 "y.tab.c"
    break;

  case 133: /* primary_expression: CHARACTER_CONSTANT  */
#line 695 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_CHAR_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2671 "y.tab.c"
    break;

  case 134: /* primary_expression: STRING_LITERAL  */
#line 699 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_STRING_LITERAL, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2679 "y.tab.c"
    break;

  case 135: /* primary_expression: LP expression RP  */
#line 703 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[-1];
    }
#line 2687 "y.tab.c"
    break;

  case 136: /* postfix_expression: primary_expression  */
#line 710 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2695 "y.tab.c"
    break;

  case 137: /* postfix_expression: postfix_expression LB expression RB  */
#line 714 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ARRAY, PTR(A_NODE, yyvsp[-3]), NULL, PTR(A_NODE, yyvsp[-1])));
    }
#line 2703 "y.tab.c"
    break;

  case 138: /* postfix_expression: postfix_expression LP arg_expression_list_opt RP  */
#line 718 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_FUNCTION_CALL, PTR(A_NODE, yyvsp[-3]), NULL, PTR(A_NODE, yyvsp[-1])));
    }
#line 2711 "y.tab.c"
    break;

  case 139: /* postfix_expression: postfix_expression PERIOD IDENTIFIER  */
#line 722 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(makeNode(N_EXP_STRUCT, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, name)));
    }
#line 2720 "y.tab.c"
    break;

  case 140: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 727 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(makeNode(N_EXP_ARROW, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, name)));
    }
#line 2729 "y.tab.c"
    break;

  case 141: /* postfix_expression: postfix_expression PLUSPLUS  */
#line 732 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_POST_INC, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2737 "y.tab.c"
    break;

  case 142: /* postfix_expression: postfix_expression MINUSMINUS  */
#line 736 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_POST_DEC, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2745 "y.tab.c"
    break;

  case 143: /* arg_expression_list_opt: %empty  */
#line 743 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_ARG_LIST_NIL, NULL, NULL, NULL));
    }
#line 2753 "y.tab.c"
    break;

  case 144: /* arg_expression_list_opt: arg_expression_list  */
#line 746 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2759 "y.tab.c"
    break;

  case 145: /* arg_expression_list: assignment_expression  */
#line 751 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_ARG_LIST, PTR(A_NODE, yyvsp[0]), NULL,
                       makeNode(N_ARG_LIST_NIL, NULL, NULL, NULL)));
    }
#line 2768 "y.tab.c"
    break;

  case 146: /* arg_expression_list: arg_expression_list COMMA assignment_expression  */
#line 756 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNodeList(N_ARG_LIST, PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2776 "y.tab.c"
    break;

  case 147: /* unary_expression: postfix_expression  */
#line 763 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2784 "y.tab.c"
    break;

  case 148: /* unary_expression: PLUSPLUS unary_expression  */
#line 767 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_PRE_INC, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2792 "y.tab.c"
    break;

  case 149: /* unary_expression: MINUSMINUS unary_expression  */
#line 771 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_PRE_DEC, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2800 "y.tab.c"
    break;

  case 150: /* unary_expression: AMP cast_expression  */
#line 775 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_AMP, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2808 "y.tab.c"
    break;

  case 151: /* unary_expression: STAR cast_expression  */
#line 779 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_STAR, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2816 "y.tab.c"
    break;

  case 152: /* unary_expression: EXCL cast_expression  */
#line 783 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_NOT, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2824 "y.tab.c"
    break;

  case 153: /* unary_expression: MINUS cast_expression  */
#line 787 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MINUS, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2832 "y.tab.c"
    break;

  case 155: /* unary_expression: PLUS cast_expression  */
#line 792 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2840 "y.tab.c"
    break;

  case 156: /* unary_expression: SIZEOF_SYM unary_expression  */
#line 796 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_SIZE_EXP, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2848 "y.tab.c"
    break;

  case 157: /* unary_expression: SIZEOF_SYM LP type_name RP  */
#line 800 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_SIZE_TYPE, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2856 "y.tab.c"
    break;

  case 158: /* cast_expression: unary_expression  */
#line 807 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2864 "y.tab.c"
    break;

  case 159: /* cast_expression: LP type_name RP cast_expression  */
#line 811 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_CAST, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2872 "y.tab.c"
    break;

  case 160: /* type_name: declaration_specifiers abstract_declarator_opt  */
#line 818 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeNameSpecifier(PTR(A_TYPE, yyvsp[0]), PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2880 "y.tab.c"
    break;

  case 161: /* multiplicative_expression: cast_expression  */
#line 825 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2888 "y.tab.c"
    break;

  case 162: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 829 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MUL, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2896 "y.tab.c"
    break;

  case 163: /* multiplicative_expression: multiplicative_expression SLASH cast_expression  */
#line 833 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_DIV, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2904 "y.tab.c"
    break;

  case 164: /* multiplicative_expression: multiplicative_expression PERCENT cast_expression  */
#line 837 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MOD, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2912 "y.tab.c"
    break;

  case 165: /* additive_expression: multiplicative_expression  */
#line 844 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2920 "y.tab.c"
    break;

  case 166: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 848 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ADD, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2928 "y.tab.c"
    break;

  case 167: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 852 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_SUB, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2936 "y.tab.c"
    break;

  case 168: /* shift_expression: additive_expression  */
#line 858 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 2942 "y.tab.c"
    break;

  case 171: /* relational_expression: shift_expression  */
#line 865 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2950 "y.tab.c"
    break;

  case 172: /* relational_expression: relational_expression LSS shift_expression  */
#line 869 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_LSS, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2958 "y.tab.c"
    break;

  case 173: /* relational_expression: relational_expression GTR shift_expression  */
#line 873 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_GTR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2966 "y.tab.c"
    break;

  case 174: /* relational_expression: relational_expression LEQ shift_expression  */
#line 877 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_LEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2974 "y.tab.c"
    break;

  case 175: /* relational_expression: relational_expression GEQ shift_expression  */
#line 881 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_GEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2982 "y.tab.c"
    break;

  case 176: /* equality_expression: relational_expression  */
#line 888 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 2990 "y.tab.c"
    break;

  case 177: /* equality_expression: equality_expression EQL relational_expression  */
#line 892 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_EQL, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2998 "y.tab.c"
    break;

  case 178: /* equality_expression: equality_expression NEQ relational_expression  */
#line 896 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_NEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3006 "y.tab.c"
    break;

  case 179: /* AND_expression: equality_expression  */
#line 902 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                          { yyval = yyvsp[0]; }
#line 3012 "y.tab.c"
    break;

  case 181: /* exclusive_OR_expression: AND_expression  */
#line 907 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                     { yyval = yyvsp[0]; }
#line 3018 "y.tab.c"
    break;

  case 183: /* inclusive_OR_expression: exclusive_OR_expression  */
#line 912 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                              { yyval = yyvsp[0]; }
#line 3024 "y.tab.c"
    break;

  case 185: /* logical_AND_expression: inclusive_OR_expression  */
#line 917 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                              { yyval = yyvsp[0]; }
#line 3030 "y.tab.c"
    break;

  case 186: /* logical_AND_expression: logical_AND_expression AMPAMP inclusive_OR_expression  */
#line 919 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_AND, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3038 "y.tab.c"
    break;

  case 187: /* logical_OR_expression: logical_AND_expression  */
#line 925 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                             { yyval = yyvsp[0]; }
#line 3044 "y.tab.c"
    break;

  case 188: /* logical_OR_expression: logical_OR_expression BARBAR logical_AND_expression  */
#line 927 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_OR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3052 "y.tab.c"
    break;

  case 191: /* assignment_expression: conditional_expression  */
#line 939 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
    }
#line 3060 "y.tab.c"
    break;

  case 192: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 943 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ASSIGN, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 3068 "y.tab.c"
    break;

  case 195: /* expression: comma_expression  */
#line 955 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
      expression_root = PTR(A_NODE, yyvsp[0]);
    }
#line 3077 "y.tab.c"
    break;


#line 3081 "y.tab.c"

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

#line 964 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"

int yyerror(const char *s) {
  logMsg(LOG_ERROR, "Syntax error at line %d: %s", line_no, s);
  return 0;
}
