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
  YYSYMBOL_declaration_list_opt = 74,      /* declaration_list_opt  */
  YYSYMBOL_declaration = 75,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 76,    /* declaration_specifiers  */
  YYSYMBOL_storage_class_specifier = 77,   /* storage_class_specifier  */
  YYSYMBOL_type_qualifier = 78,            /* type_qualifier  */
  YYSYMBOL_init_declarator_list = 79,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 80,           /* init_declarator  */
  YYSYMBOL_type_specifier = 81,            /* type_specifier  */
  YYSYMBOL_struct_specifier = 82,          /* struct_specifier  */
  YYSYMBOL_struct_or_union = 83,           /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 84,   /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 85,        /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 86,  /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 87,    /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 88,         /* struct_declarator  */
  YYSYMBOL_enum_specifier = 89,            /* enum_specifier  */
  YYSYMBOL_enumerator_list = 90,           /* enumerator_list  */
  YYSYMBOL_enumerator = 91,                /* enumerator  */
  YYSYMBOL_declarator = 92,                /* declarator  */
  YYSYMBOL_pointer = 93,                   /* pointer  */
  YYSYMBOL_type_qualifier_list_opt = 94,   /* type_qualifier_list_opt  */
  YYSYMBOL_type_qualifier_list = 95,       /* type_qualifier_list  */
  YYSYMBOL_direct_declarator = 96,         /* direct_declarator  */
  YYSYMBOL_constant_expression_opt = 97,   /* constant_expression_opt  */
  YYSYMBOL_parameter_type_list_opt = 98,   /* parameter_type_list_opt  */
  YYSYMBOL_parameter_type_list = 99,       /* parameter_type_list  */
  YYSYMBOL_parameter_list = 100,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 101,    /* parameter_declaration  */
  YYSYMBOL_abstract_declarator_opt = 102,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 103,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 104, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 105,              /* initializer  */
  YYSYMBOL_initializer_list = 106,         /* initializer_list  */
  YYSYMBOL_statement = 107,                /* statement  */
  YYSYMBOL_labeled_statement = 108,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 109,       /* compound_statement  */
  YYSYMBOL_declaration_list = 110,         /* declaration_list  */
  YYSYMBOL_statement_list_opt = 111,       /* statement_list_opt  */
  YYSYMBOL_statement_list = 112,           /* statement_list  */
  YYSYMBOL_expression_statement = 113,     /* expression_statement  */
  YYSYMBOL_selection_statement = 114,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 115,      /* iteration_statement  */
  YYSYMBOL_expression_opt = 116,           /* expression_opt  */
  YYSYMBOL_jump_statement = 117,           /* jump_statement  */
  YYSYMBOL_primary_expression = 118,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 119,       /* postfix_expression  */
  YYSYMBOL_arg_expression_list_opt = 120,  /* arg_expression_list_opt  */
  YYSYMBOL_arg_expression_list = 121,      /* arg_expression_list  */
  YYSYMBOL_unary_expression = 122,         /* unary_expression  */
  YYSYMBOL_cast_expression = 123,          /* cast_expression  */
  YYSYMBOL_type_name = 124,                /* type_name  */
  YYSYMBOL_multiplicative_expression = 125, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 126,      /* additive_expression  */
  YYSYMBOL_shift_expression = 127,         /* shift_expression  */
  YYSYMBOL_relational_expression = 128,    /* relational_expression  */
  YYSYMBOL_equality_expression = 129,      /* equality_expression  */
  YYSYMBOL_AND_expression = 130,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 131,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 132,  /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 133,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 134,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 135,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 136,    /* assignment_expression  */
  YYSYMBOL_comma_expression = 137,         /* comma_expression  */
  YYSYMBOL_expression = 138,               /* expression  */
  YYSYMBOL_constant_expression = 139       /* constant_expression  */
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
#define YYLAST   690

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  190
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  325

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
       0,    45,    45,    49,    50,    54,    55,    59,    65,    74,
      75,    79,    86,    90,    93,    94,    98,   102,   106,   107,
     108,   109,   110,   114,   115,   119,   120,   127,   128,   132,
     133,   134,   138,   139,   140,   144,   145,   149,   150,   154,
     158,   159,   160,   161,   165,   166,   170,   171,   172,   176,
     177,   178,   182,   183,   187,   188,   192,   196,   200,   203,
     210,   211,   215,   216,   220,   229,   230,   235,   243,   244,
     250,   251,   256,   257,   261,   262,   269,   273,   284,   285,
     291,   292,   293,   297,   298,   299,   300,   301,   305,   306,
     307,   311,   312,   316,   317,   318,   319,   320,   321,   325,
     326,   327,   331,   340,   341,   346,   349,   354,   359,   366,
     367,   371,   372,   373,   377,   378,   379,   383,   384,   388,
     394,   395,   396,   400,   408,   415,   416,   417,   418,   423,
     424,   428,   429,   430,   431,   435,   442,   443,   447,   448,
     452,   453,   457,   461,   465,   469,   473,   477,   478,   480,
     481,   485,   486,   490,   491,   495,   496,   500,   504,   511,
     512,   516,   523,   524,   525,   529,   530,   531,   532,   533,
     537,   538,   539,   543,   544,   548,   549,   553,   554,   558,
     559,   563,   564,   568,   569,   573,   574,   578,   579,   583,
     591
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
  "translation_unit", "external_declaration", "function_definition",
  "declaration_list_opt", "declaration", "declaration_specifiers",
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
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list_opt",
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "expression_opt", "jump_statement",
  "primary_expression", "postfix_expression", "arg_expression_list_opt",
  "arg_expression_list", "unary_expression", "cast_expression",
  "type_name", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "AND_expression", "exclusive_OR_expression", "inclusive_OR_expression",
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

#define YYPACT_NINF (-239)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-10)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     583,  -239,  -239,  -239,    46,  -239,  -239,  -239,  -239,  -239,
    -239,  -239,  -239,    87,   162,    33,   583,  -239,  -239,  -239,
      87,   659,   659,   659,  -239,   108,  -239,   659,    38,     0,
      37,   100,    77,  -239,    71,   162,  -239,  -239,    -1,  -239,
     518,  -239,  -239,  -239,    85,   198,   101,  -239,    87,   659,
       0,   659,   431,   100,   104,   -25,  -239,  -239,  -239,  -239,
      87,  -239,   394,   101,   198,   198,   198,   168,  -239,    60,
     659,  -239,   115,  -239,    86,   119,  -239,   132,  -239,  -239,
    -239,  -239,  -239,  -239,   468,   505,   505,   320,   431,   431,
     431,   431,   431,   431,   126,  -239,   121,  -239,  -239,   177,
      82,   166,   142,   187,   137,   141,   144,   172,   -32,  -239,
    -239,   109,   431,  -239,   100,  -239,   394,  -239,   154,  -239,
    -239,  -239,   228,  -239,  -239,  -239,  -239,   431,    67,  -239,
     155,   257,   550,   431,  -239,   116,  -239,  -239,    20,  -239,
     627,   320,  -239,   431,  -239,  -239,    79,   190,  -239,   189,
     203,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,
     252,   431,   431,   263,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,  -239,  -239,  -239,  -239,   136,   431,  -239,
    -239,    60,  -239,   431,   230,   217,   431,   220,   233,   257,
     240,   284,   242,   431,   245,   246,  -239,  -239,  -239,  -239,
     243,   257,  -239,  -239,  -239,  -239,   232,   249,   250,   244,
      20,   659,   431,  -239,  -239,   251,   616,   113,  -239,   431,
     431,  -239,  -239,   253,   247,  -239,   255,  -239,  -239,  -239,
    -239,   177,   177,    82,    82,   166,   166,   166,   166,   142,
     142,   187,   137,   141,   144,   172,   254,  -239,   357,  -239,
    -239,  -239,   257,  -239,   256,  -239,   257,   272,   431,   239,
     431,   248,  -239,   431,   431,  -239,  -239,  -239,  -239,  -239,
    -239,   258,   260,  -239,  -239,  -239,  -239,   431,  -239,   431,
    -239,  -239,  -239,   257,  -239,   264,   267,  -239,   268,  -239,
     269,   271,  -239,  -239,  -239,  -239,  -239,   431,   431,   257,
     257,   257,   285,   270,   304,  -239,  -239,   274,   431,   257,
    -239,   287,  -239,   257,  -239
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    64,    31,    18,     0,    19,    35,    20,    36,    21,
      22,    23,    24,     0,    60,     0,     2,     3,     5,     6,
       0,    13,    14,    12,    29,     0,    30,     9,     0,    57,
      51,     0,     0,    62,    58,    61,     1,     4,     0,    25,
      27,    16,    17,    15,    34,     0,     0,   103,     0,    10,
      56,    70,    68,     0,    54,     0,    52,    65,    59,    63,
       0,    11,     0,     0,     0,    41,    40,     0,    37,     0,
       9,     8,    27,   104,    78,     0,    71,    72,    74,   123,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,   140,   151,   155,   159,
     162,   165,   170,   173,   175,   177,   179,   181,   183,   190,
      69,     0,     0,    50,     0,    26,     0,    28,   151,   185,
      88,     7,     0,    43,    42,    33,    38,     0,     0,    44,
      46,   105,    70,    68,    76,    80,    77,    79,    81,    67,
       0,     0,   149,     0,   141,   142,   153,     0,   187,   189,
       0,   145,   147,   144,   143,   148,   146,    66,   134,   135,
       0,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,    55,    53,    91,     0,     0,    32,
      47,     0,    39,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,   117,     0,     0,   109,   107,    93,    94,
       0,   106,    95,    96,    97,    98,     0,     0,     0,     0,
      82,    70,    68,    73,    75,     0,    70,    80,   154,     0,
       0,   128,   133,     0,   137,   138,     0,   132,   156,   157,
     158,   160,   161,   163,   164,   166,   167,   168,   169,   171,
     172,   174,   176,   178,   180,   182,     0,    89,     0,   186,
      45,    48,     0,   121,     0,   120,     0,     0,   117,     0,
       0,     0,   118,     0,     0,   102,   108,   110,    85,    83,
      84,     0,     0,   150,   152,   188,   131,     0,   130,     0,
      90,    92,   101,     0,   100,     0,     0,   122,     0,   119,
       0,     0,    87,    86,   139,   184,    99,     0,   117,     0,
       0,     0,     0,     0,   111,   113,   114,     0,   117,     0,
     115,     0,   112,     0,   116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -239,  -239,  -239,   315,  -239,     5,    34,    15,  -239,    43,
    -239,   275,     7,  -239,  -239,   276,   -55,   174,  -239,   147,
    -239,   286,   241,    -9,   -31,  -239,  -239,   -21,  -124,   -45,
    -239,  -239,   204,  -239,   -60,  -122,  -108,  -239,  -171,  -239,
     -19,  -239,  -239,  -239,  -239,  -239,  -239,  -238,  -239,  -239,
    -239,  -239,  -239,   -62,   -72,   206,    74,    83,    44,    97,
     179,   176,   178,   181,   186,  -239,   -51,   -57,  -239,   -85,
     -80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    15,    16,    17,    18,    46,    47,    74,    21,    22,
      38,    39,    23,    24,    25,    67,    68,    69,   128,   129,
      26,    55,    56,    27,    28,    34,    35,    29,    94,   217,
      76,    77,    78,   136,   218,   138,   117,   187,   207,   208,
     209,    49,   210,   211,   212,   213,   214,   271,   215,    95,
      96,   233,   234,    97,    98,   147,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   119,   148,   149,   216,
     110
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     118,   109,   150,    58,    32,   120,    75,    50,   186,   219,
     181,    40,   126,   220,   137,    20,   151,   152,   153,   154,
     155,   156,   142,   144,   145,   118,   113,    71,   267,   114,
     296,    20,   184,    36,    19,   182,    41,    42,    43,    72,
     276,     1,    48,   135,   121,    63,    51,   190,    52,    30,
      19,    72,    66,    60,   118,    48,   150,    33,   150,   120,
     130,   109,    61,     1,    48,   134,   221,   126,   222,   118,
     313,    66,    66,    66,    66,   131,   109,   236,    59,   118,
     321,   118,   109,    73,    13,    48,   228,    53,    65,     1,
       1,   292,   238,   239,   240,   294,    31,   256,   282,   118,
     118,   135,   146,    54,   235,   220,    13,    65,    65,    65,
      65,    44,   127,   261,    50,   227,   264,    14,   272,     1,
     118,   191,   306,    32,    57,   226,   118,   133,    14,    66,
     192,   259,   132,    13,   133,    64,    14,   118,   314,   315,
     316,   118,   109,    14,    14,   109,   167,   168,   322,   118,
     291,    70,   324,   158,   159,   160,   146,   284,    45,   226,
     183,   133,   132,   114,   133,    65,   139,   161,   118,   162,
     112,   109,     2,   285,   163,   157,   281,   171,   172,   173,
     174,    62,   130,   272,     4,   298,   140,   257,   300,   301,
     258,     6,    11,    12,     8,   227,   118,   177,    11,    12,
     118,   120,     2,   178,   118,   179,   118,   193,   118,   169,
     170,   118,   118,   180,     4,   245,   246,   247,   248,   125,
     188,     6,   312,   272,     8,   118,   175,   176,    11,    12,
     304,   118,     2,   272,   164,   165,   166,   229,   305,   123,
     124,   241,   242,   230,     4,   118,   118,   118,   118,   118,
     231,     6,   243,   244,     8,   232,   118,   118,    11,    12,
     194,   118,    80,    81,    82,    83,   237,   195,   196,   197,
     198,   199,   249,   250,   200,   201,   202,   203,    84,   189,
     263,   204,   262,   265,   205,   266,   268,   269,   270,    85,
      86,   273,   274,   280,   275,   277,   278,   279,   283,   295,
     286,   287,   297,    87,   288,   302,   289,    70,   293,   303,
     307,   299,    88,    89,    90,   309,   310,    91,   311,   319,
     206,    92,    93,    79,     2,    80,    81,    82,    83,     3,
     308,    37,   317,   318,   323,   115,     4,   320,   260,   111,
     122,    84,     5,     6,   224,     7,     8,   225,     9,    10,
      11,    12,    85,    86,   252,   185,   251,   253,     0,     0,
      79,   254,    80,    81,    82,    83,    87,   255,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    84,     0,
      91,     0,     0,     0,    92,    93,     0,     0,     0,    85,
      86,     0,     0,     0,     0,     0,     0,    79,     0,    80,
      81,    82,    83,    87,     0,     0,     0,   116,   290,     0,
       0,     0,    88,    89,    90,    84,     0,    91,     0,     0,
       0,    92,    93,     0,     0,     0,    85,    86,     0,     0,
       0,     0,     0,     0,    79,     0,    80,    81,    82,    83,
      87,     0,     0,     0,   116,     0,     0,     0,     0,    88,
      89,    90,    84,     0,    91,     0,     0,     0,    92,    93,
       0,     0,     0,    85,    86,     0,     0,     0,     0,     0,
       0,    79,     0,    80,    81,    82,    83,    87,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    84,
       0,    91,     0,     0,     0,    92,    93,     0,     0,     0,
      85,    86,     0,     0,     0,     0,     0,     0,    79,     0,
      80,    81,    82,    83,   141,     0,     0,     0,     0,     0,
       0,     0,     2,    88,    89,    90,    84,     3,    91,     0,
       0,     0,    92,    93,     4,     0,     0,    85,    86,     0,
       5,     6,     0,     7,     8,     0,     9,    10,    11,    12,
       0,   143,     0,     1,     2,     0,     0,     0,     0,     3,
      88,    89,    90,     0,     0,    91,     4,     0,    -9,    92,
      93,     0,     5,     6,     0,     7,     8,     0,     9,    10,
      11,    12,     0,     0,    62,     0,     1,     2,     0,     0,
       0,     0,     3,     0,     0,     0,   132,     0,   133,     4,
       0,     0,     0,     0,     0,     5,     6,    14,     7,     8,
       0,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     3,     0,     0,     0,    13,
       0,     2,     4,     0,     0,     0,     3,     0,     5,     6,
      14,     7,     8,     4,     9,    10,    11,    12,     0,     5,
       6,     0,     7,     8,     0,     9,    10,    11,    12,     0,
       0,     0,   226,     2,   133,     0,     0,     0,     3,     0,
       0,     0,   223,    14,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     0,     7,     8,     0,     9,    10,    11,
      12
};

static const yytype_int16 yycheck[] =
{
      62,    52,    87,    34,    13,    62,    51,    28,   116,   133,
      42,    20,    67,   135,    74,     0,    88,    89,    90,    91,
      92,    93,    84,    85,    86,    87,    51,    46,   199,    54,
     268,    16,   112,     0,     0,    67,    21,    22,    23,    48,
     211,     3,    27,    74,    63,    40,    46,   127,    48,     3,
      16,    60,    45,    54,   116,    40,   141,    14,   143,   116,
      69,   112,    63,     3,    49,    74,    46,   122,    48,   131,
     308,    64,    65,    66,    67,    70,   127,   162,    35,   141,
     318,   143,   133,    49,    46,    70,   146,    50,    45,     3,
       3,   262,   164,   165,   166,   266,    50,   182,   222,   161,
     162,   132,    87,     3,   161,   227,    46,    64,    65,    66,
      67,     3,    52,   193,   135,   146,   196,    57,   203,     3,
     182,    54,   293,   132,    47,    46,   188,    48,    57,   122,
      63,   188,    46,    46,    48,    50,    57,   199,   309,   310,
     311,   203,   193,    57,    57,   196,    64,    65,   319,   211,
     258,    50,   323,    32,    33,    34,   141,   229,    50,    46,
      51,    48,    46,    54,    48,   122,    47,    46,   230,    48,
      66,   222,     4,   230,    53,    49,   221,    35,    36,    37,
      38,    66,   191,   268,    16,   270,    54,    51,   273,   274,
      54,    23,    30,    31,    26,   226,   258,    60,    30,    31,
     262,   258,     4,    62,   266,    61,   268,    52,   270,    43,
      44,   273,   274,    41,    16,   171,   172,   173,   174,    51,
      66,    23,   307,   308,    26,   287,    39,    40,    30,    31,
     287,   293,     4,   318,    57,    58,    59,    47,   289,    65,
      66,   167,   168,    54,    16,   307,   308,   309,   310,   311,
      47,    23,   169,   170,    26,     3,   318,   319,    30,    31,
       3,   323,     5,     6,     7,     8,     3,    10,    11,    12,
      13,    14,   175,   176,    17,    18,    19,    20,    21,    51,
      63,    24,    52,    63,    27,    52,    46,     3,    46,    32,
      33,    46,    46,    49,    51,    63,    47,    47,    47,    27,
      47,    54,    63,    46,    49,    47,    52,    50,    52,    49,
      46,    63,    55,    56,    57,    47,    47,    60,    47,    15,
      63,    64,    65,     3,     4,     5,     6,     7,     8,     9,
      63,    16,    47,    63,    47,    60,    16,    63,   191,    53,
      64,    21,    22,    23,   140,    25,    26,   141,    28,    29,
      30,    31,    32,    33,   178,   114,   177,   179,    -1,    -1,
       3,   180,     5,     6,     7,     8,    46,   181,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    21,    -1,
      60,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
       6,     7,     8,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    55,    56,    57,    21,    -1,    60,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,
      46,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    55,
      56,    57,    21,    -1,    60,    -1,    -1,    -1,    64,    65,
      -1,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,     7,     8,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    21,
      -1,    60,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    55,    56,    57,    21,     9,    60,    -1,
      -1,    -1,    64,    65,    16,    -1,    -1,    32,    33,    -1,
      22,    23,    -1,    25,    26,    -1,    28,    29,    30,    31,
      -1,    46,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,
      55,    56,    57,    -1,    -1,    60,    16,    -1,    50,    64,
      65,    -1,    22,    23,    -1,    25,    26,    -1,    28,    29,
      30,    31,    -1,    -1,    66,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    46,    -1,    48,    16,
      -1,    -1,    -1,    -1,    -1,    22,    23,    57,    25,    26,
      -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    46,
      -1,     4,    16,    -1,    -1,    -1,     9,    -1,    22,    23,
      57,    25,    26,    16,    28,    29,    30,    31,    -1,    22,
      23,    -1,    25,    26,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,    46,     4,    48,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    45,    57,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    22,    23,    -1,    25,    26,    -1,    28,    29,    30,
      31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     9,    16,    22,    23,    25,    26,    28,
      29,    30,    31,    46,    57,    70,    71,    72,    73,    75,
      76,    77,    78,    81,    82,    83,    89,    92,    93,    96,
       3,    50,    92,    78,    94,    95,     0,    72,    79,    80,
      92,    76,    76,    76,     3,    50,    74,    75,    76,   110,
      96,    46,    48,    50,     3,    90,    91,    47,    93,    78,
      54,    63,    66,    74,    50,    78,    81,    84,    85,    86,
      50,   109,    92,    75,    76,    98,    99,   100,   101,     3,
       5,     6,     7,     8,    21,    32,    33,    46,    55,    56,
      57,    60,    64,    65,    97,   118,   119,   122,   123,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     139,    90,    66,    51,    54,    80,    50,   105,   122,   135,
     136,   109,    84,    86,    86,    51,    85,    52,    87,    88,
      92,    74,    46,    48,    92,    93,   102,   103,   104,    47,
      54,    46,   122,    46,   122,   122,    76,   124,   136,   137,
     138,   123,   123,   123,   123,   123,   123,    49,    32,    33,
      34,    46,    48,    53,    57,    58,    59,    64,    65,    43,
      44,    35,    36,    37,    38,    39,    40,    60,    62,    61,
      41,    42,    67,    51,   139,    91,   105,   106,    66,    51,
     139,    54,    63,    52,     3,    10,    11,    12,    13,    14,
      17,    18,    19,    20,    24,    27,    63,   107,   108,   109,
     111,   112,   113,   114,   115,   117,   138,    98,   103,    97,
     104,    46,    48,    45,   101,   124,    46,    93,   103,    47,
      54,    47,     3,   120,   121,   136,   138,     3,   123,   123,
     123,   125,   125,   126,   126,   127,   127,   127,   127,   128,
     128,   129,   130,   131,   132,   133,   138,    51,    54,   136,
      88,   139,    52,    63,   139,    63,    52,   107,    46,     3,
      46,   116,   138,    46,    46,    51,   107,    63,    47,    47,
      49,    98,    97,    47,   123,   136,    47,    54,    49,    52,
      51,   105,   107,    52,   107,    27,   116,    63,   138,    63,
     138,   138,    47,    49,   136,   135,   107,    46,    63,    47,
      47,    47,   138,   116,   107,   107,   107,    47,    63,    15,
      63,   116,   107,    47,   107
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    76,    76,    76,    76,    76,    76,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    81,    82,    82,    82,    83,    83,    84,    84,    85,
      86,    86,    86,    86,    87,    87,    88,    88,    88,    89,
      89,    89,    90,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   103,   104,   104,   104,   104,   104,   105,   105,
     105,   106,   106,   107,   107,   107,   107,   107,   107,   108,
     108,   108,   109,   110,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   114,   115,   115,   115,   116,   116,   117,
     117,   117,   117,   118,   118,   118,   118,   118,   118,   119,
     119,   119,   119,   119,   119,   119,   120,   120,   121,   121,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   123,   123,   124,   124,   125,   125,   125,   125,   126,
     126,   126,   127,   127,   127,   128,   128,   128,   128,   128,
     129,   129,   129,   130,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     139
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     4,     3,     0,
       1,     3,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     1,     5,     4,     2,     1,     1,     1,     2,     3,
       1,     1,     2,     2,     1,     3,     1,     2,     3,     5,
       4,     2,     1,     3,     1,     3,     2,     1,     2,     3,
       0,     1,     1,     2,     1,     3,     4,     4,     0,     1,
       0,     1,     1,     3,     1,     3,     2,     2,     0,     1,
       1,     1,     2,     3,     3,     3,     4,     4,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       3,     3,     4,     1,     2,     0,     1,     1,     2,     1,
       2,     5,     7,     5,     5,     7,     9,     0,     1,     3,
       2,     2,     3,     1,     1,     1,     1,     1,     3,     1,
       4,     4,     3,     3,     2,     2,     0,     1,     1,     3,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     1,     4,     1,     2,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     3,     1,
       1
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
  case 7: /* function_definition: declaration_specifiers declarator declaration_list_opt compound_statement  */
#line 60 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = setFunctionDeclaratorSpecifier(
          PTR(A_ID, yyvsp[-2]), PTR(A_SPECIFIER, yyvsp[-3]));
      yyval = YY(setFunctionDeclaratorBody(id, PTR(A_NODE, yyvsp[0])));
    }
#line 1727 "y.tab.c"
    break;

  case 8: /* function_definition: declarator declaration_list_opt compound_statement  */
#line 66 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_SPECIFIER *specifier = makeSpecifier(NULL, S_NULL);
      A_ID *id = setFunctionDeclaratorSpecifier(PTR(A_ID, yyvsp[-2]), specifier);
      yyval = YY(setFunctionDeclaratorBody(id, PTR(A_NODE, yyvsp[0])));
    }
#line 1737 "y.tab.c"
    break;

  case 9: /* declaration_list_opt: %empty  */
#line 74 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
      { yyval = YY(NULL); }
#line 1743 "y.tab.c"
    break;

  case 10: /* declaration_list_opt: declaration_list  */
#line 75 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                      { yyval = yyvsp[0]; }
#line 1749 "y.tab.c"
    break;

  case 11: /* declaration: declaration_specifiers init_declarator_list SEMICOLON  */
#line 80 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorListSpecifier(PTR(A_ID, yyvsp[-1]), PTR(A_SPECIFIER, yyvsp[-2])));
    }
#line 1757 "y.tab.c"
    break;

  case 12: /* declaration_specifiers: type_specifier  */
#line 87 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeSpecifier(PTR(A_TYPE, yyvsp[0]), S_NULL));
    }
#line 1765 "y.tab.c"
    break;

  case 13: /* declaration_specifiers: storage_class_specifier  */
#line 91 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    { yyval = YY(makeSpecifier(NULL, (S_KIND)yyvsp[0])); }
#line 1771 "y.tab.c"
    break;

  case 15: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 95 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(updateSpecifier(PTR(A_SPECIFIER, yyvsp[0]), PTR(A_TYPE, yyvsp[-1]), S_NULL));
    }
#line 1779 "y.tab.c"
    break;

  case 16: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 99 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(updateSpecifier(PTR(A_SPECIFIER, yyvsp[0]), PTR(A_TYPE, yyvsp[-1]), S_NULL));
    }
#line 1787 "y.tab.c"
    break;

  case 25: /* init_declarator_list: init_declarator  */
#line 119 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                      { yyval = yyvsp[0]; }
#line 1793 "y.tab.c"
    break;

  case 26: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 121 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 1801 "y.tab.c"
    break;

  case 27: /* init_declarator: declarator  */
#line 127 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                 { yyval = yyvsp[0]; }
#line 1807 "y.tab.c"
    break;

  case 31: /* type_specifier: TYPE_IDENTIFIER  */
#line 134 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                      { yyval = yyvsp[0]; }
#line 1813 "y.tab.c"
    break;

  case 56: /* declarator: pointer direct_declarator  */
#line 193 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[0]), PTR(A_TYPE, yyvsp[-1])));
    }
#line 1821 "y.tab.c"
    break;

  case 57: /* declarator: direct_declarator  */
#line 196 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                        { yyval = yyvsp[0]; }
#line 1827 "y.tab.c"
    break;

  case 58: /* pointer: STAR type_qualifier_list_opt  */
#line 201 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    { yyval = YY(makeType(T_POINTER)); }
#line 1833 "y.tab.c"
    break;

  case 59: /* pointer: STAR type_qualifier_list_opt pointer  */
#line 204 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[0]), makeType(T_POINTER)));
    }
#line 1841 "y.tab.c"
    break;

  case 64: /* direct_declarator: IDENTIFIER  */
#line 221 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);

      A_ID *id = makeIdentifier(name);
      free(name);

      yyval = YY(id);
    }
#line 1854 "y.tab.c"
    break;

  case 66: /* direct_declarator: direct_declarator LB constant_expression_opt RB  */
#line 231 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(
          PTR(A_ID, yyvsp[-3]), setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1]))));
    }
#line 1863 "y.tab.c"
    break;

  case 67: /* direct_declarator: direct_declarator LP parameter_type_list_opt RP  */
#line 236 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setDeclaratorElementType(
          PTR(A_ID, yyvsp[-3]), setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1]))));
    }
#line 1872 "y.tab.c"
    break;

  case 68: /* constant_expression_opt: %empty  */
#line 243 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
      { yyval = YY(NULL); }
#line 1878 "y.tab.c"
    break;

  case 69: /* constant_expression_opt: constant_expression  */
#line 245 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    { yyval = yyvsp[0]; }
#line 1884 "y.tab.c"
    break;

  case 70: /* parameter_type_list_opt: %empty  */
#line 250 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
     { yyval = YY(NULL); }
#line 1890 "y.tab.c"
    break;

  case 71: /* parameter_type_list_opt: parameter_type_list  */
#line 252 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    { yyval = yyvsp[0]; }
#line 1896 "y.tab.c"
    break;

  case 74: /* parameter_list: parameter_declaration  */
#line 261 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                            { yyval = yyvsp[0]; }
#line 1902 "y.tab.c"
    break;

  case 75: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 263 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 1910 "y.tab.c"
    break;

  case 76: /* parameter_declaration: declaration_specifiers declarator  */
#line 270 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(setParameterDeclaratorSpecifier(PTR(A_ID, yyvsp[0]), PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 1918 "y.tab.c"
    break;

  case 77: /* parameter_declaration: declaration_specifiers abstract_declarator_opt  */
#line 274 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      A_ID *id = makeDummyIdentifier();

      setDeclaratorElementType(id, PTR(A_TYPE, yyvsp[0]));

      yyval = YY(setParameterDeclaratorSpecifier(id, PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 1930 "y.tab.c"
    break;

  case 78: /* abstract_declarator_opt: %empty  */
#line 284 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
      { yyval = YY(NULL); }
#line 1936 "y.tab.c"
    break;

  case 79: /* abstract_declarator_opt: abstract_declarator  */
#line 286 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    { yyval = yyvsp[0]; }
#line 1942 "y.tab.c"
    break;

  case 98: /* statement: jump_statement  */
#line 321 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                     { yyval = yyvsp[0]; }
#line 1948 "y.tab.c"
    break;

  case 102: /* compound_statement: LR declaration_list_opt statement_list_opt RR  */
#line 332 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_COMPOUND, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[-1])));

      compound_root = PTR(A_NODE, yyval);
    }
#line 1958 "y.tab.c"
    break;

  case 105: /* statement_list_opt: %empty  */
#line 346 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL));
    }
#line 1966 "y.tab.c"
    break;

  case 106: /* statement_list_opt: statement_list  */
#line 350 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    { yyval = yyvsp[0]; }
#line 1972 "y.tab.c"
    break;

  case 107: /* statement_list: statement  */
#line 355 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_LIST, PTR(A_NODE, yyvsp[0]), NULL,
                       makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL)));
    }
#line 1981 "y.tab.c"
    break;

  case 108: /* statement_list: statement_list statement  */
#line 360 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNodeList(N_STMT_LIST, PTR(A_NODE, yyvsp[-1]), PTR(A_NODE, yyvsp[0])));
    }
#line 1989 "y.tab.c"
    break;

  case 117: /* expression_opt: %empty  */
#line 383 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
      { yyval = YY(NULL); }
#line 1995 "y.tab.c"
    break;

  case 118: /* expression_opt: expression  */
#line 384 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                { yyval = yyvsp[0]; }
#line 2001 "y.tab.c"
    break;

  case 119: /* jump_statement: RETURN_SYM expression_opt SEMICOLON  */
#line 389 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_STMT_RETURN, NULL, PTR(A_NODE, yyvsp[-1]), NULL));

      statement_root = PTR(A_NODE, yyval);
    }
#line 2011 "y.tab.c"
    break;

  case 123: /* primary_expression: IDENTIFIER  */
#line 401 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      A_ID *id = getIdentifierDeclared(name);
      free(name);

      yyval = YY(makeNode(N_EXP_IDENT, NULL, PTR(A_NODE, id), NULL));
    }
#line 2023 "y.tab.c"
    break;

  case 124: /* primary_expression: INTEGER_CONSTANT  */
#line 409 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_INT_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));

      A_NODE *node = PTR(A_NODE, yyval);
      logMsg(LOG_DEBUG, "N_EXP_INT_CONST: %lld", (long long)(intptr_t)node->clink);
    }
#line 2034 "y.tab.c"
    break;

  case 128: /* primary_expression: LP expression RP  */
#line 419 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    { yyval = yyvsp[-1]; }
#line 2040 "y.tab.c"
    break;

  case 129: /* postfix_expression: primary_expression  */
#line 423 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                         { yyval = yyvsp[0]; }
#line 2046 "y.tab.c"
    break;

  case 130: /* postfix_expression: postfix_expression LB expression RB  */
#line 425 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ARRAY, PTR(A_NODE, yyvsp[-3]), NULL, PTR(A_NODE, yyvsp[-1])));
    }
#line 2054 "y.tab.c"
    break;

  case 134: /* postfix_expression: postfix_expression PLUSPLUS  */
#line 432 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_POST_INC, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2062 "y.tab.c"
    break;

  case 135: /* postfix_expression: postfix_expression MINUSMINUS  */
#line 436 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_POST_DEC, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2070 "y.tab.c"
    break;

  case 140: /* unary_expression: postfix_expression  */
#line 452 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                         { yyval = yyvsp[0]; }
#line 2076 "y.tab.c"
    break;

  case 141: /* unary_expression: PLUSPLUS unary_expression  */
#line 454 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_PRE_INC, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2084 "y.tab.c"
    break;

  case 142: /* unary_expression: MINUSMINUS unary_expression  */
#line 458 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_PRE_DEC, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2092 "y.tab.c"
    break;

  case 143: /* unary_expression: AMP cast_expression  */
#line 462 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_AMP, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2100 "y.tab.c"
    break;

  case 144: /* unary_expression: STAR cast_expression  */
#line 466 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_STAR, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2108 "y.tab.c"
    break;

  case 145: /* unary_expression: EXCL cast_expression  */
#line 470 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_NOT, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2116 "y.tab.c"
    break;

  case 146: /* unary_expression: MINUS cast_expression  */
#line 474 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MINUS, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2124 "y.tab.c"
    break;

  case 148: /* unary_expression: PLUS cast_expression  */
#line 479 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    { yyval = yyvsp[0]; }
#line 2130 "y.tab.c"
    break;

  case 151: /* cast_expression: unary_expression  */
#line 485 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                       { yyval = yyvsp[0]; }
#line 2136 "y.tab.c"
    break;

  case 155: /* multiplicative_expression: cast_expression  */
#line 495 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                      { yyval = yyvsp[0]; }
#line 2142 "y.tab.c"
    break;

  case 156: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 497 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MUL, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2150 "y.tab.c"
    break;

  case 157: /* multiplicative_expression: multiplicative_expression SLASH cast_expression  */
#line 501 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_DIV, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2158 "y.tab.c"
    break;

  case 158: /* multiplicative_expression: multiplicative_expression PERCENT cast_expression  */
#line 505 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_MOD, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2166 "y.tab.c"
    break;

  case 159: /* additive_expression: multiplicative_expression  */
#line 511 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
                                { yyval = yyvsp[0]; }
#line 2172 "y.tab.c"
    break;

  case 160: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 513 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_ADD, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2180 "y.tab.c"
    break;

  case 161: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 517 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = YY(makeNode(N_EXP_SUB, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2188 "y.tab.c"
    break;

  case 189: /* expression: comma_expression  */
#line 584 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"
    {
      yyval = yyvsp[0];
      expression_root = PTR(A_NODE, yyvsp[0]);
    }
#line 2197 "y.tab.c"
    break;


#line 2201 "y.tab.c"

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

#line 594 "C:\\Users\\egod1\\proj\\compiler\\w4\\c.y"

int yyerror(const char *s) {
  logMsg(LOG_ERROR, "Syntax error at line %d: %s", line_no, s);
  return 0;
}
