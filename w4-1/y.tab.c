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
#line 1 "c.y"

#define YYSTYPE_IS_DECLARED 1
typedef long YYSTYPE;

#include "type.h"
#include "support.h"
#include <stdio.h>

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wint-conversion"
#endif

int yylex(void);
void yyerror(char *);
extern int line_no, syntax_err;
extern A_NODE *root;
extern A_ID *current_id;
extern int current_level;
extern A_TYPE *int_type;

#line 92 "y.tab.c"

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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_TYPE_IDENTIFIER = 4,            /* TYPE_IDENTIFIER  */
  YYSYMBOL_FLOAT_CONSTANT = 5,             /* FLOAT_CONSTANT  */
  YYSYMBOL_INTEGER_CONSTANT = 6,           /* INTEGER_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 7,         /* CHARACTER_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 8,             /* STRING_LITERAL  */
  YYSYMBOL_PLUS = 9,                       /* PLUS  */
  YYSYMBOL_MINUS = 10,                     /* MINUS  */
  YYSYMBOL_PLUSPLUS = 11,                  /* PLUSPLUS  */
  YYSYMBOL_MINUSMINUS = 12,                /* MINUSMINUS  */
  YYSYMBOL_AMP = 13,                       /* AMP  */
  YYSYMBOL_BARBAR = 14,                    /* BARBAR  */
  YYSYMBOL_AMPAMP = 15,                    /* AMPAMP  */
  YYSYMBOL_ARROW = 16,                     /* ARROW  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_LSS = 18,                       /* LSS  */
  YYSYMBOL_GTR = 19,                       /* GTR  */
  YYSYMBOL_LEQ = 20,                       /* LEQ  */
  YYSYMBOL_GEQ = 21,                       /* GEQ  */
  YYSYMBOL_EQL = 22,                       /* EQL  */
  YYSYMBOL_NEQ = 23,                       /* NEQ  */
  YYSYMBOL_DOTDOTDOT = 24,                 /* DOTDOTDOT  */
  YYSYMBOL_LP = 25,                        /* LP  */
  YYSYMBOL_RP = 26,                        /* RP  */
  YYSYMBOL_LB = 27,                        /* LB  */
  YYSYMBOL_RB = 28,                        /* RB  */
  YYSYMBOL_LR = 29,                        /* LR  */
  YYSYMBOL_RR = 30,                        /* RR  */
  YYSYMBOL_PERIOD = 31,                    /* PERIOD  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_EXCL = 33,                      /* EXCL  */
  YYSYMBOL_STAR = 34,                      /* STAR  */
  YYSYMBOL_SLASH = 35,                     /* SLASH  */
  YYSYMBOL_PERCENT = 36,                   /* PERCENT  */
  YYSYMBOL_ASSIGN = 37,                    /* ASSIGN  */
  YYSYMBOL_COLON = 38,                     /* COLON  */
  YYSYMBOL_AUTO_SYM = 39,                  /* AUTO_SYM  */
  YYSYMBOL_STATIC_SYM = 40,                /* STATIC_SYM  */
  YYSYMBOL_TYPEDEF_SYM = 41,               /* TYPEDEF_SYM  */
  YYSYMBOL_STRUCT_SYM = 42,                /* STRUCT_SYM  */
  YYSYMBOL_ENUM_SYM = 43,                  /* ENUM_SYM  */
  YYSYMBOL_SIZEOF_SYM = 44,                /* SIZEOF_SYM  */
  YYSYMBOL_UNION_SYM = 45,                 /* UNION_SYM  */
  YYSYMBOL_IF_SYM = 46,                    /* IF_SYM  */
  YYSYMBOL_ELSE_SYM = 47,                  /* ELSE_SYM  */
  YYSYMBOL_WHILE_SYM = 48,                 /* WHILE_SYM  */
  YYSYMBOL_DO_SYM = 49,                    /* DO_SYM  */
  YYSYMBOL_FOR_SYM = 50,                   /* FOR_SYM  */
  YYSYMBOL_CONTINUE_SYM = 51,              /* CONTINUE_SYM  */
  YYSYMBOL_BREAK_SYM = 52,                 /* BREAK_SYM  */
  YYSYMBOL_RETURN_SYM = 53,                /* RETURN_SYM  */
  YYSYMBOL_SWITCH_SYM = 54,                /* SWITCH_SYM  */
  YYSYMBOL_CASE_SYM = 55,                  /* CASE_SYM  */
  YYSYMBOL_DEFAULT_SYM = 56,               /* DEFAULT_SYM  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_program = 58,                   /* program  */
  YYSYMBOL_translation_unit = 59,          /* translation_unit  */
  YYSYMBOL_external_declaration = 60,      /* external_declaration  */
  YYSYMBOL_function_definition = 61,       /* function_definition  */
  YYSYMBOL_62_1 = 62,                      /* @1  */
  YYSYMBOL_63_2 = 63,                      /* @2  */
  YYSYMBOL_declaration_list_opt = 64,      /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 65,          /* declaration_list  */
  YYSYMBOL_declaration = 66,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 67,    /* declaration_specifiers  */
  YYSYMBOL_storage_class_specifier = 68,   /* storage_class_specifier  */
  YYSYMBOL_init_declarator_list_opt = 69,  /* init_declarator_list_opt  */
  YYSYMBOL_init_declarator_list = 70,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 71,           /* init_declarator  */
  YYSYMBOL_initializer = 72,               /* initializer  */
  YYSYMBOL_initializer_list = 73,          /* initializer_list  */
  YYSYMBOL_type_specifier = 74,            /* type_specifier  */
  YYSYMBOL_struct_type_specifier = 75,     /* struct_type_specifier  */
  YYSYMBOL_76_3 = 76,                      /* @3  */
  YYSYMBOL_77_4 = 77,                      /* @4  */
  YYSYMBOL_78_5 = 78,                      /* @5  */
  YYSYMBOL_79_6 = 79,                      /* @6  */
  YYSYMBOL_struct_or_union = 80,           /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 81,   /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 82,        /* struct_declaration  */
  YYSYMBOL_struct_declarator_list = 83,    /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 84,         /* struct_declarator  */
  YYSYMBOL_enum_type_specifier = 85,       /* enum_type_specifier  */
  YYSYMBOL_86_7 = 86,                      /* @7  */
  YYSYMBOL_87_8 = 87,                      /* @8  */
  YYSYMBOL_enumerator_list = 88,           /* enumerator_list  */
  YYSYMBOL_enumerator = 89,                /* enumerator  */
  YYSYMBOL_90_9 = 90,                      /* @9  */
  YYSYMBOL_declarator = 91,                /* declarator  */
  YYSYMBOL_pointer = 92,                   /* pointer  */
  YYSYMBOL_direct_declarator = 93,         /* direct_declarator  */
  YYSYMBOL_94_10 = 94,                     /* @10  */
  YYSYMBOL_parameter_type_list_opt = 95,   /* parameter_type_list_opt  */
  YYSYMBOL_parameter_type_list = 96,       /* parameter_type_list  */
  YYSYMBOL_parameter_list = 97,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 98,     /* parameter_declaration  */
  YYSYMBOL_abstract_declarator_opt = 99,   /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 100,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 101, /* direct_abstract_declarator  */
  YYSYMBOL_statement_list_opt = 102,       /* statement_list_opt  */
  YYSYMBOL_statement_list = 103,           /* statement_list  */
  YYSYMBOL_statement = 104,                /* statement  */
  YYSYMBOL_labeled_statement = 105,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 106,       /* compound_statement  */
  YYSYMBOL_107_11 = 107,                   /* @11  */
  YYSYMBOL_expression_statement = 108,     /* expression_statement  */
  YYSYMBOL_selection_statement = 109,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 110,      /* iteration_statement  */
  YYSYMBOL_for_expression = 111,           /* for_expression  */
  YYSYMBOL_expression_opt = 112,           /* expression_opt  */
  YYSYMBOL_jump_statement = 113,           /* jump_statement  */
  YYSYMBOL_arg_expression_list_opt = 114,  /* arg_expression_list_opt  */
  YYSYMBOL_arg_expression_list = 115,      /* arg_expression_list  */
  YYSYMBOL_constant_expression_opt = 116,  /* constant_expression_opt  */
  YYSYMBOL_constant_expression = 117,      /* constant_expression  */
  YYSYMBOL_expression = 118,               /* expression  */
  YYSYMBOL_comma_expression = 119,         /* comma_expression  */
  YYSYMBOL_assignment_expression = 120,    /* assignment_expression  */
  YYSYMBOL_conditional_expression = 121,   /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 122,    /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 123,   /* logical_and_expression  */
  YYSYMBOL_bitwise_or_expression = 124,    /* bitwise_or_expression  */
  YYSYMBOL_bitwise_xor_expression = 125,   /* bitwise_xor_expression  */
  YYSYMBOL_bitwise_and_expression = 126,   /* bitwise_and_expression  */
  YYSYMBOL_equality_expression = 127,      /* equality_expression  */
  YYSYMBOL_relational_expression = 128,    /* relational_expression  */
  YYSYMBOL_shift_expression = 129,         /* shift_expression  */
  YYSYMBOL_additive_expression = 130,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 131, /* multiplicative_expression  */
  YYSYMBOL_cast_expression = 132,          /* cast_expression  */
  YYSYMBOL_unary_expression = 133,         /* unary_expression  */
  YYSYMBOL_postfix_expression = 134,       /* postfix_expression  */
  YYSYMBOL_primary_expression = 135,       /* primary_expression  */
  YYSYMBOL_type_name = 136                 /* type_name  */
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
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   438

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  293

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


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
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    40,    41,    46,    47,    52,    51,    56,
      55,    62,    63,    67,    68,    73,    78,    80,    82,    84,
      89,    90,    91,    95,    96,   100,   101,   106,   107,   112,
     114,   118,   120,   125,   126,   127,   132,   133,   131,   137,
     138,   136,   141,   146,   147,   151,   152,   157,   162,   163,
     168,   173,   172,   177,   176,   180,   185,   186,   191,   194,
     193,   200,   202,   206,   207,   212,   213,   214,   217,   216,
     224,   225,   229,   230,   235,   236,   241,   243,   248,   249,
     253,   254,   255,   260,   261,   263,   265,   267,   272,   273,
     277,   279,   284,   285,   286,   287,   288,   289,   293,   295,
     300,   300,   307,   308,   313,   315,   317,   322,   324,   326,
     331,   336,   337,   341,   343,   345,   350,   351,   355,   357,
     362,   363,   367,   371,   375,   379,   380,   385,   389,   390,
     395,   396,   401,   405,   409,   413,   414,   416,   421,   422,
     424,   426,   428,   433,   437,   438,   440,   445,   446,   448,
     450,   455,   456,   461,   462,   464,   466,   468,   470,   472,
     474,   476,   478,   483,   484,   486,   488,   490,   492,   494,
     499,   501,   503,   505,   507,   509,   513
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
  "TYPE_IDENTIFIER", "FLOAT_CONSTANT", "INTEGER_CONSTANT",
  "CHARACTER_CONSTANT", "STRING_LITERAL", "PLUS", "MINUS", "PLUSPLUS",
  "MINUSMINUS", "AMP", "BARBAR", "AMPAMP", "ARROW", "SEMICOLON", "LSS",
  "GTR", "LEQ", "GEQ", "EQL", "NEQ", "DOTDOTDOT", "LP", "RP", "LB", "RB",
  "LR", "RR", "PERIOD", "COMMA", "EXCL", "STAR", "SLASH", "PERCENT",
  "ASSIGN", "COLON", "AUTO_SYM", "STATIC_SYM", "TYPEDEF_SYM", "STRUCT_SYM",
  "ENUM_SYM", "SIZEOF_SYM", "UNION_SYM", "IF_SYM", "ELSE_SYM", "WHILE_SYM",
  "DO_SYM", "FOR_SYM", "CONTINUE_SYM", "BREAK_SYM", "RETURN_SYM",
  "SWITCH_SYM", "CASE_SYM", "DEFAULT_SYM", "$accept", "program",
  "translation_unit", "external_declaration", "function_definition", "@1",
  "@2", "declaration_list_opt", "declaration_list", "declaration",
  "declaration_specifiers", "storage_class_specifier",
  "init_declarator_list_opt", "init_declarator_list", "init_declarator",
  "initializer", "initializer_list", "type_specifier",
  "struct_type_specifier", "@3", "@4", "@5", "@6", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "enum_type_specifier",
  "@7", "@8", "enumerator_list", "enumerator", "@9", "declarator",
  "pointer", "direct_declarator", "@10", "parameter_type_list_opt",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "abstract_declarator_opt", "abstract_declarator",
  "direct_abstract_declarator", "statement_list_opt", "statement_list",
  "statement", "labeled_statement", "compound_statement", "@11",
  "expression_statement", "selection_statement", "iteration_statement",
  "for_expression", "expression_opt", "jump_statement",
  "arg_expression_list_opt", "arg_expression_list",
  "constant_expression_opt", "constant_expression", "expression",
  "comma_expression", "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "bitwise_or_expression", "bitwise_xor_expression",
  "bitwise_and_expression", "equality_expression", "relational_expression",
  "shift_expression", "additive_expression", "multiplicative_expression",
  "cast_expression", "unary_expression", "postfix_expression",
  "primary_expression", "type_name", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-220)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      46,  -220,  -220,    26,    -3,  -220,  -220,  -220,  -220,    58,
    -220,    65,    46,  -220,  -220,  -220,    26,   239,   239,  -220,
      75,  -220,  -220,    19,     3,    74,  -220,    78,   117,  -220,
    -220,   104,    96,  -220,    25,  -220,  -220,   122,   129,   134,
       3,  -220,    30,  -220,   145,   219,  -220,    26,   314,   134,
     200,  -220,  -220,  -220,   239,  -220,  -220,  -220,  -220,  -220,
      30,    30,   354,   354,    30,   173,    30,    30,   394,   204,
    -220,  -220,  -220,  -220,  -220,   223,   226,  -220,  -220,  -220,
      88,   152,  -220,   115,   175,  -220,   201,   208,  -220,   219,
     205,    49,  -220,  -220,   207,   314,  -220,  -220,  -220,  -220,
     287,   239,    42,   220,  -220,   213,  -220,  -220,  -220,  -220,
      30,  -220,  -220,  -220,   132,   222,   238,  -220,  -220,   173,
    -220,  -220,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,  -220,  -220,   271,    30,
      30,   273,    62,   246,  -220,   219,  -220,   108,   287,    26,
     119,  -220,   260,   239,  -220,    26,   102,    30,  -220,    72,
    -220,  -220,   172,  -220,    92,   350,   196,  -220,  -220,    30,
     266,   226,  -220,   152,   152,  -220,  -220,  -220,  -220,   175,
     175,  -220,  -220,  -220,  -220,  -220,   269,   254,  -220,   268,
    -220,  -220,    30,  -220,  -220,   314,   245,    15,  -220,  -220,
    -220,  -220,  -220,   274,   275,   260,   276,   281,   285,    30,
     278,    30,   267,   277,   260,  -220,  -220,  -220,  -220,  -220,
    -220,  -220,   301,  -220,   302,   305,   306,   172,   239,    30,
    -220,  -220,  -220,  -220,  -220,    30,  -220,  -220,  -220,  -220,
    -220,    26,    30,    30,   288,    30,  -220,  -220,   316,  -220,
      30,   297,   260,  -220,  -220,  -220,  -220,  -220,  -220,   311,
     310,  -220,  -220,   315,   318,   317,   319,   323,  -220,   320,
     260,  -220,  -220,  -220,   260,   260,    30,   260,    30,   260,
    -220,   303,  -220,   325,  -220,   332,  -220,   260,   335,    30,
    -220,  -220,  -220
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    65,    35,     0,    63,    20,    21,    22,    43,    53,
      44,     0,     2,     3,     5,     6,    23,    17,    16,    33,
      39,    34,     9,     0,    62,     0,    64,    55,     0,     1,
       4,     0,    24,    25,    27,    19,    18,    42,     0,     0,
      61,    68,   120,    66,     0,     0,    15,     0,     0,     0,
       0,    40,   100,    10,    70,   170,   172,   171,   173,   174,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,   122,   123,   124,   125,   127,   128,   130,   132,   133,
     134,   135,   138,   143,   144,   147,   151,   153,   163,     0,
      58,     0,    56,    26,    27,     0,    28,    29,     8,    37,
       0,    11,    78,     0,    71,    72,    74,   160,   151,   159,
       0,   154,   155,   156,    78,     0,     0,   158,   157,     0,
     161,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,   169,     0,   116,
       0,     0,     0,     0,    54,     0,    31,     0,     0,     0,
       0,    45,    88,    12,    13,    23,    70,   120,    76,    81,
      77,    79,    80,    69,     0,    70,    81,   176,   175,     0,
       0,   129,   131,   136,   137,   139,   140,   141,   142,   145,
     146,   148,   149,   150,   126,   167,     0,   117,   118,     0,
     166,    52,     0,    57,    30,     0,     0,     0,    48,    50,
      41,    46,   102,     0,     0,     0,     0,     0,     0,   111,
       0,     0,     0,     0,    89,    90,    92,    93,    94,    95,
      96,    97,     0,    14,     0,     0,     0,    82,    70,   120,
      73,    75,   152,   162,   165,     0,   164,    60,    32,    38,
      47,     0,     0,     0,     0,   111,   114,   115,     0,   112,
       0,     0,     0,   101,    91,   103,    86,    83,    84,     0,
       0,   119,    49,     0,     0,     0,     0,     0,   113,     0,
       0,    99,    87,    85,     0,     0,     0,     0,   111,     0,
      98,   104,   107,     0,   109,     0,   106,     0,     0,   111,
     105,   108,   110
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -220,  -220,  -220,   341,  -220,  -220,  -220,  -220,  -220,   -80,
       7,  -220,  -220,  -220,   308,   -83,  -220,   -92,  -220,  -220,
    -220,  -220,  -220,  -220,   221,  -130,  -220,   127,  -220,  -220,
    -220,   282,   211,  -220,    -1,     0,   -20,  -220,   -53,  -220,
    -220,   206,   258,    37,  -132,  -220,  -220,  -157,  -220,    54,
    -220,  -220,  -220,  -220,  -220,  -219,  -220,  -220,  -220,  -139,
     -43,   -42,  -220,  -126,  -220,  -220,   251,   253,  -220,  -220,
    -220,    80,    99,  -220,   100,   -50,   128,  -220,  -220,   255
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    11,    12,    13,    14,    49,    39,   152,   153,    15,
     102,    17,    31,    32,    33,    96,   147,    18,    19,    50,
     148,    38,   100,    20,   150,   151,   197,   198,    21,    44,
      28,    91,    92,   143,    22,    23,    24,    54,   224,   104,
     105,   106,   160,   161,   162,   213,   214,   215,   216,   217,
     101,   218,   219,   220,   266,   248,   221,   186,   187,    69,
      70,   222,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   116
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,   103,    25,    40,    26,    97,    71,    16,   149,   184,
     107,   109,   146,   188,   113,    34,   117,   118,   226,    16,
     201,   154,     1,   115,    35,    36,   267,   227,    41,     1,
      42,     4,   240,    55,   227,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     3,     1,    94,   241,   244,     1,
       2,     3,    97,    71,    -7,    65,   149,   254,   149,   285,
       4,    27,    48,    66,    67,    29,   201,   156,   115,   157,
     292,     3,   114,   223,    68,     1,     4,   115,    37,   144,
       4,   145,   181,   182,   183,     5,     6,     7,     8,     9,
     260,    10,   191,    53,   145,   271,     2,   156,   189,   157,
      43,   158,   159,    98,   149,     1,     2,   -51,   155,   261,
     124,   125,   238,   280,   166,    71,   230,   281,   282,   232,
     284,    46,   286,     2,   130,   131,   114,   156,    47,   157,
     290,     5,     6,     7,     8,     9,     4,    10,   194,    40,
     195,     5,     6,     7,     8,     9,    45,    10,   199,   200,
     237,   -36,    97,    71,    94,    25,   159,   165,    51,   157,
     155,     8,     9,    52,    10,   166,     4,   249,   251,    71,
     126,   127,   128,   129,    89,   259,    55,     2,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    71,   108,   108,
     111,   112,   108,   225,   108,   108,   120,   228,    65,   229,
     263,   264,   225,   249,   173,   174,    66,    67,   269,   132,
     133,   134,     5,     6,     7,     8,     9,    68,    10,   136,
     137,   165,    90,   157,   138,   175,   176,   177,   178,    99,
     179,   180,   121,   139,   283,   140,   249,   122,   135,   141,
     199,   123,   -59,     2,    48,   164,   163,   249,   168,     2,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,    55,   169,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   185,   239,   190,   202,     5,     6,
       7,     8,     9,   192,    10,    65,   235,     8,     9,    52,
      10,     2,   233,    66,    67,   234,   236,   108,   246,   242,
     243,   245,   247,   250,    68,   252,   203,   253,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    55,   255,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   256,     8,
       9,   257,    10,   268,   258,   270,   265,   272,   273,    65,
     278,   274,   276,    95,   275,   277,   279,    66,    67,   289,
     287,   288,   291,    30,     2,    93,   193,    55,    68,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   262,   196,
     231,   142,   167,   171,   170,   165,   172,   157,     0,   110,
       0,     0,     0,     0,     4,     0,     0,    66,    67,     5,
       6,     7,     8,     9,     0,    10,     0,    55,    68,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,    66,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    68
};

static const yytype_int16 yycheck[] =
{
      42,    54,     3,    23,     4,    48,    48,     0,   100,   135,
      60,    61,    95,   139,    64,    16,    66,    67,   157,    12,
     150,   101,     3,    65,    17,    18,   245,   159,    25,     3,
      27,    34,    17,     3,   166,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    25,     3,    47,    32,   205,     3,
       4,    25,    95,    95,    29,    25,   148,   214,   150,   278,
      34,     3,    37,    33,    34,     0,   196,    25,   110,    27,
     289,    25,    65,   153,    44,     3,    34,   119,     3,    30,
      34,    32,   132,   133,   134,    39,    40,    41,    42,    43,
     229,    45,    30,    39,    32,   252,     4,    25,   140,    27,
      26,   102,   102,    49,   196,     3,     4,    29,   101,   235,
      22,    23,   195,   270,   114,   157,    24,   274,   275,   169,
     277,    17,   279,     4,     9,    10,   119,    25,    32,    27,
     287,    39,    40,    41,    42,    43,    34,    45,    30,   159,
      32,    39,    40,    41,    42,    43,    29,    45,   149,    30,
     192,    29,   195,   195,   155,   156,   156,    25,    29,    27,
     153,    42,    43,    29,    45,   165,    34,   209,   211,   211,
      18,    19,    20,    21,    29,   228,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,   229,    60,    61,
      62,    63,    64,   156,    66,    67,    68,    25,    25,    27,
     242,   243,   165,   245,   124,   125,    33,    34,   250,    34,
      35,    36,    39,    40,    41,    42,    43,    44,    45,    11,
      12,    25,     3,    27,    16,   126,   127,   128,   129,    29,
     130,   131,    28,    25,   276,    27,   278,    14,    37,    31,
     241,    15,    37,     4,    37,    32,    26,   289,    26,     4,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,     3,    26,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     3,    30,     3,    17,    39,    40,
      41,    42,    43,    37,    45,    25,    32,    42,    43,    29,
      45,     4,    26,    33,    34,    26,    28,   169,    17,    25,
      25,    25,    17,    25,    44,    38,    46,    30,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     3,    17,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    26,    42,
      43,    26,    45,    17,    28,    38,    48,    26,    28,    25,
      17,    26,    25,    29,    26,    26,    26,    33,    34,    17,
      47,    26,    17,    12,     4,    47,   145,     3,    44,     5,
       6,     7,     8,     9,    10,    11,    12,    13,   241,   148,
     164,    89,   114,   122,   119,    25,   123,    27,    -1,    25,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    33,    34,    39,
      40,    41,    42,    43,    -1,    45,    -1,     3,    44,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    25,    34,    39,    40,    41,    42,    43,
      45,    58,    59,    60,    61,    66,    67,    68,    74,    75,
      80,    85,    91,    92,    93,    91,    92,     3,    87,     0,
      60,    69,    70,    71,    91,    67,    67,     3,    78,    63,
      93,    25,    27,    26,    86,    29,    17,    32,    37,    62,
      76,    29,    29,   106,    94,     3,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    25,    33,    34,    44,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    29,
       3,    88,    89,    71,    91,    29,    72,   117,   106,    29,
      79,   107,    67,    95,    96,    97,    98,   132,   133,   132,
      25,   133,   133,   132,    67,   118,   136,   132,   132,    25,
     133,    28,    14,    15,    22,    23,    18,    19,    20,    21,
       9,    10,    34,    35,    36,    37,    11,    12,    16,    25,
      27,    31,    88,    90,    30,    32,    72,    73,    77,    74,
      81,    82,    64,    65,    66,    67,    25,    27,    91,    92,
      99,   100,   101,    26,    32,    25,    92,    99,    26,    26,
     136,   123,   124,   128,   128,   129,   129,   129,   129,   131,
     131,   132,   132,   132,   120,     3,   114,   115,   120,   118,
       3,    30,    37,    89,    30,    32,    81,    83,    84,    91,
      30,    82,    17,    46,    48,    49,    50,    51,    52,    53,
      54,    55,    56,   102,   103,   104,   105,   106,   108,   109,
     110,   113,   118,    66,    95,   100,   116,   101,    25,    27,
      24,    98,   132,    26,    26,    32,    28,   118,    72,    30,
      17,    32,    25,    25,   104,    25,    17,    17,   112,   118,
      25,   117,    38,    30,   104,    17,    26,    26,    28,    95,
     116,   120,    84,   118,   118,    48,   111,   112,    17,   118,
      38,   104,    26,    28,    26,    26,    25,    26,    17,    26,
     104,   104,   104,   118,   104,   112,   104,    47,    26,    17,
     104,    17,   112
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    62,    61,    63,
      61,    64,    64,    65,    65,    66,    67,    67,    67,    67,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    74,    76,    77,    75,    78,
      79,    75,    75,    80,    80,    81,    81,    82,    83,    83,
      84,    86,    85,    87,    85,    85,    88,    88,    89,    90,
      89,    91,    91,    92,    92,    93,    93,    93,    94,    93,
      95,    95,    96,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   100,   101,   101,   101,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   105,   105,
     107,   106,   108,   108,   109,   109,   109,   110,   110,   110,
     111,   112,   112,   113,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   118,   119,   120,   120,   121,   122,   122,
     123,   123,   124,   125,   126,   127,   127,   127,   128,   128,
     128,   128,   128,   129,   130,   130,   130,   131,   131,   131,
     131,   132,   132,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   134,   134,   134,   134,   134,   134,   134,
     135,   135,   135,   135,   135,   135,   136
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     4,     0,
       3,     0,     1,     1,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     0,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     0,     0,     7,     0,
       0,     6,     2,     1,     1,     1,     2,     3,     1,     3,
       1,     0,     6,     0,     5,     2,     1,     3,     1,     0,
       4,     2,     1,     1,     2,     1,     3,     4,     0,     5,
       0,     1,     1,     3,     1,     3,     2,     2,     0,     1,
       1,     1,     2,     3,     3,     4,     3,     4,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     4,     3,
       0,     5,     1,     2,     5,     7,     5,     5,     7,     5,
       5,     0,     1,     3,     2,     2,     0,     1,     1,     3,
       0,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     1,     3,     3,     1,     3,     3,
       3,     1,     4,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     1,     4,     4,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     3,     2
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
#line 36 "c.y"
    { root=makeNode(N_PROGRAM,NIL,yyvsp[0],NIL); checkForwardReference(); }
#line 1571 "y.tab.c"
    break;

  case 3: /* translation_unit: external_declaration  */
#line 40 "c.y"
                         { yyval=yyvsp[0]; }
#line 1577 "y.tab.c"
    break;

  case 4: /* translation_unit: translation_unit external_declaration  */
#line 42 "c.y"
    { yyval=linkDeclaratorList(yyvsp[-1],yyvsp[0]); }
#line 1583 "y.tab.c"
    break;

  case 5: /* external_declaration: function_definition  */
#line 46 "c.y"
                        { yyval=yyvsp[0]; }
#line 1589 "y.tab.c"
    break;

  case 6: /* external_declaration: declaration  */
#line 47 "c.y"
                { yyval=yyvsp[0]; }
#line 1595 "y.tab.c"
    break;

  case 7: /* @1: %empty  */
#line 52 "c.y"
    { yyval=setFunctionDeclaratorSpecifier(yyvsp[0],yyvsp[-1]); }
#line 1601 "y.tab.c"
    break;

  case 8: /* function_definition: declaration_specifiers declarator @1 compound_statement  */
#line 54 "c.y"
    { yyval=setFunctionDeclaratorBody(yyvsp[-1],yyvsp[0]); }
#line 1607 "y.tab.c"
    break;

  case 9: /* @2: %empty  */
#line 56 "c.y"
    { yyval=setFunctionDeclaratorSpecifier(yyvsp[0],makeSpecifier(int_type,0)); }
#line 1613 "y.tab.c"
    break;

  case 10: /* function_definition: declarator @2 compound_statement  */
#line 58 "c.y"
    { yyval=setFunctionDeclaratorBody(yyvsp[-1],yyvsp[0]); }
#line 1619 "y.tab.c"
    break;

  case 11: /* declaration_list_opt: %empty  */
#line 62 "c.y"
    { yyval=NIL; }
#line 1625 "y.tab.c"
    break;

  case 12: /* declaration_list_opt: declaration_list  */
#line 63 "c.y"
                     { yyval=yyvsp[0]; }
#line 1631 "y.tab.c"
    break;

  case 13: /* declaration_list: declaration  */
#line 67 "c.y"
                { yyval=yyvsp[0]; }
#line 1637 "y.tab.c"
    break;

  case 14: /* declaration_list: declaration_list declaration  */
#line 69 "c.y"
    { yyval=linkDeclaratorList(yyvsp[-1],yyvsp[0]); }
#line 1643 "y.tab.c"
    break;

  case 15: /* declaration: declaration_specifiers init_declarator_list_opt SEMICOLON  */
#line 74 "c.y"
    { yyval=setDeclaratorListSpecifier(yyvsp[-1],yyvsp[-2]); }
#line 1649 "y.tab.c"
    break;

  case 16: /* declaration_specifiers: type_specifier  */
#line 79 "c.y"
    { yyval=makeSpecifier(yyvsp[0],0); }
#line 1655 "y.tab.c"
    break;

  case 17: /* declaration_specifiers: storage_class_specifier  */
#line 81 "c.y"
    { yyval=makeSpecifier(0,yyvsp[0]); }
#line 1661 "y.tab.c"
    break;

  case 18: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 83 "c.y"
    { yyval=updateSpecifier(yyvsp[0],yyvsp[-1],0); }
#line 1667 "y.tab.c"
    break;

  case 19: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 85 "c.y"
    { yyval=updateSpecifier(yyvsp[0],0,yyvsp[-1]); }
#line 1673 "y.tab.c"
    break;

  case 20: /* storage_class_specifier: AUTO_SYM  */
#line 89 "c.y"
             { yyval=S_AUTO; }
#line 1679 "y.tab.c"
    break;

  case 21: /* storage_class_specifier: STATIC_SYM  */
#line 90 "c.y"
               { yyval=S_STATIC; }
#line 1685 "y.tab.c"
    break;

  case 22: /* storage_class_specifier: TYPEDEF_SYM  */
#line 91 "c.y"
                { yyval=S_TYPEDEF; }
#line 1691 "y.tab.c"
    break;

  case 23: /* init_declarator_list_opt: %empty  */
#line 95 "c.y"
    { yyval=makeDummyIdentifier(); }
#line 1697 "y.tab.c"
    break;

  case 24: /* init_declarator_list_opt: init_declarator_list  */
#line 96 "c.y"
                         { yyval=yyvsp[0]; }
#line 1703 "y.tab.c"
    break;

  case 25: /* init_declarator_list: init_declarator  */
#line 100 "c.y"
                    { yyval=yyvsp[0]; }
#line 1709 "y.tab.c"
    break;

  case 26: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 102 "c.y"
    { yyval=linkDeclaratorList(yyvsp[-2],yyvsp[0]); }
#line 1715 "y.tab.c"
    break;

  case 27: /* init_declarator: declarator  */
#line 106 "c.y"
               { yyval=yyvsp[0]; }
#line 1721 "y.tab.c"
    break;

  case 28: /* init_declarator: declarator ASSIGN initializer  */
#line 108 "c.y"
    { yyval=setDeclaratorInit(yyvsp[-2],yyvsp[0]); }
#line 1727 "y.tab.c"
    break;

  case 29: /* initializer: constant_expression  */
#line 113 "c.y"
    { yyval=makeNode(N_INIT_LIST_ONE,NIL,yyvsp[0],NIL); }
#line 1733 "y.tab.c"
    break;

  case 30: /* initializer: LR initializer_list RR  */
#line 114 "c.y"
                           { yyval=yyvsp[-1]; }
#line 1739 "y.tab.c"
    break;

  case 31: /* initializer_list: initializer  */
#line 119 "c.y"
    { yyval=makeNode(N_INIT_LIST,yyvsp[0],NIL,makeNode(N_INIT_LIST_NIL,NIL,NIL,NIL)); }
#line 1745 "y.tab.c"
    break;

  case 32: /* initializer_list: initializer_list COMMA initializer  */
#line 121 "c.y"
    { yyval=makeNodeList(N_INIT_LIST,yyvsp[-2],yyvsp[0]); }
#line 1751 "y.tab.c"
    break;

  case 33: /* type_specifier: struct_type_specifier  */
#line 125 "c.y"
                          { yyval=yyvsp[0]; }
#line 1757 "y.tab.c"
    break;

  case 34: /* type_specifier: enum_type_specifier  */
#line 126 "c.y"
                        { yyval=yyvsp[0]; }
#line 1763 "y.tab.c"
    break;

  case 35: /* type_specifier: TYPE_IDENTIFIER  */
#line 127 "c.y"
                    { yyval=yyvsp[0]; }
#line 1769 "y.tab.c"
    break;

  case 36: /* @3: %empty  */
#line 132 "c.y"
    { yyval=setTypeStructOrEnumIdentifier(yyvsp[-1],yyvsp[0],ID_STRUCT); }
#line 1775 "y.tab.c"
    break;

  case 37: /* @4: %empty  */
#line 133 "c.y"
     { yyval=current_id; current_level++; }
#line 1781 "y.tab.c"
    break;

  case 38: /* struct_type_specifier: struct_or_union IDENTIFIER @3 LR @4 struct_declaration_list RR  */
#line 134 "c.y"
    { checkForwardReference(); yyval=setTypeField(yyvsp[-4],yyvsp[-1]); current_level--;
  current_id=yyvsp[-2]; }
#line 1788 "y.tab.c"
    break;

  case 39: /* @5: %empty  */
#line 137 "c.y"
    { yyval=makeType(yyvsp[0]); }
#line 1794 "y.tab.c"
    break;

  case 40: /* @6: %empty  */
#line 138 "c.y"
     { yyval=current_id; current_level++; }
#line 1800 "y.tab.c"
    break;

  case 41: /* struct_type_specifier: struct_or_union @5 LR @6 struct_declaration_list RR  */
#line 139 "c.y"
    { checkForwardReference(); yyval=setTypeField(yyvsp[-4],yyvsp[-1]); current_level--;
  current_id=yyvsp[-2]; }
#line 1807 "y.tab.c"
    break;

  case 42: /* struct_type_specifier: struct_or_union IDENTIFIER  */
#line 142 "c.y"
    { yyval=getTypeOfStructOrEnumRefIdentifier(yyvsp[-1],yyvsp[0],ID_STRUCT); }
#line 1813 "y.tab.c"
    break;

  case 43: /* struct_or_union: STRUCT_SYM  */
#line 146 "c.y"
               { yyval=T_STRUCT; }
#line 1819 "y.tab.c"
    break;

  case 44: /* struct_or_union: UNION_SYM  */
#line 147 "c.y"
              { yyval=T_UNION; }
#line 1825 "y.tab.c"
    break;

  case 45: /* struct_declaration_list: struct_declaration  */
#line 151 "c.y"
                       { yyval=yyvsp[0]; }
#line 1831 "y.tab.c"
    break;

  case 46: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 153 "c.y"
    { yyval=linkDeclaratorList(yyvsp[-1],yyvsp[0]); }
#line 1837 "y.tab.c"
    break;

  case 47: /* struct_declaration: type_specifier struct_declarator_list SEMICOLON  */
#line 158 "c.y"
    { yyval=setStructDeclaratorListSpecifier(yyvsp[-1],yyvsp[-2]); }
#line 1843 "y.tab.c"
    break;

  case 48: /* struct_declarator_list: struct_declarator  */
#line 162 "c.y"
                      { yyval=yyvsp[0]; }
#line 1849 "y.tab.c"
    break;

  case 49: /* struct_declarator_list: struct_declarator_list COMMA struct_declarator  */
#line 164 "c.y"
    { yyval=linkDeclaratorList(yyvsp[-2],yyvsp[0]); }
#line 1855 "y.tab.c"
    break;

  case 50: /* struct_declarator: declarator  */
#line 168 "c.y"
               { yyval=yyvsp[0]; }
#line 1861 "y.tab.c"
    break;

  case 51: /* @7: %empty  */
#line 173 "c.y"
    { yyval=setTypeStructOrEnumIdentifier(T_ENUM,yyvsp[0],ID_ENUM); }
#line 1867 "y.tab.c"
    break;

  case 52: /* enum_type_specifier: ENUM_SYM IDENTIFIER @7 LR enumerator_list RR  */
#line 175 "c.y"
    { yyval=setTypeField(yyvsp[-3],yyvsp[-1]); }
#line 1873 "y.tab.c"
    break;

  case 53: /* @8: %empty  */
#line 177 "c.y"
    { yyval=makeType(T_ENUM); }
#line 1879 "y.tab.c"
    break;

  case 54: /* enum_type_specifier: ENUM_SYM @8 LR enumerator_list RR  */
#line 179 "c.y"
    { yyval=setTypeField(yyvsp[-3],yyvsp[-1]); }
#line 1885 "y.tab.c"
    break;

  case 55: /* enum_type_specifier: ENUM_SYM IDENTIFIER  */
#line 181 "c.y"
    { yyval=getTypeOfStructOrEnumRefIdentifier(T_ENUM,yyvsp[0],ID_ENUM); }
#line 1891 "y.tab.c"
    break;

  case 56: /* enumerator_list: enumerator  */
#line 185 "c.y"
               { yyval=yyvsp[0]; }
#line 1897 "y.tab.c"
    break;

  case 57: /* enumerator_list: enumerator_list COMMA enumerator  */
#line 187 "c.y"
    { yyval=linkDeclaratorList(yyvsp[-2],yyvsp[0]); }
#line 1903 "y.tab.c"
    break;

  case 58: /* enumerator: IDENTIFIER  */
#line 192 "c.y"
    { yyval=setDeclaratorKind(makeIdentifier(yyvsp[0]),ID_ENUM_LITERAL); }
#line 1909 "y.tab.c"
    break;

  case 59: /* @9: %empty  */
#line 194 "c.y"
    { yyval=setDeclaratorKind(makeIdentifier(yyvsp[0]),ID_ENUM_LITERAL); }
#line 1915 "y.tab.c"
    break;

  case 60: /* enumerator: IDENTIFIER @9 ASSIGN expression  */
#line 196 "c.y"
    { yyval=setDeclaratorInit(yyvsp[-2],yyvsp[0]); }
#line 1921 "y.tab.c"
    break;

  case 61: /* declarator: pointer direct_declarator  */
#line 201 "c.y"
    { yyval=setDeclaratorElementType(yyvsp[0],yyvsp[-1]); }
#line 1927 "y.tab.c"
    break;

  case 62: /* declarator: direct_declarator  */
#line 202 "c.y"
                      { yyval=yyvsp[0]; }
#line 1933 "y.tab.c"
    break;

  case 63: /* pointer: STAR  */
#line 206 "c.y"
         { yyval=makeType(T_POINTER); }
#line 1939 "y.tab.c"
    break;

  case 64: /* pointer: STAR pointer  */
#line 208 "c.y"
    { yyval=setTypeElementType(yyvsp[0],makeType(T_POINTER)); }
#line 1945 "y.tab.c"
    break;

  case 65: /* direct_declarator: IDENTIFIER  */
#line 212 "c.y"
               { yyval=makeIdentifier(yyvsp[0]); }
#line 1951 "y.tab.c"
    break;

  case 66: /* direct_declarator: LP declarator RP  */
#line 213 "c.y"
                     { yyval=yyvsp[-1]; }
#line 1957 "y.tab.c"
    break;

  case 67: /* direct_declarator: direct_declarator LB constant_expression_opt RB  */
#line 215 "c.y"
    { yyval=setDeclaratorElementType(yyvsp[-3],setTypeExpr(makeType(T_ARRAY),yyvsp[-1])); }
#line 1963 "y.tab.c"
    break;

  case 68: /* @10: %empty  */
#line 217 "c.y"
    { yyval=current_id; current_level++; }
#line 1969 "y.tab.c"
    break;

  case 69: /* direct_declarator: direct_declarator LP @10 parameter_type_list_opt RP  */
#line 219 "c.y"
    { checkForwardReference(); current_id=yyvsp[-2]; current_level--;
  yyval=setDeclaratorElementType(yyvsp[-4],setTypeField(makeType(T_FUNC),yyvsp[-1])); }
#line 1976 "y.tab.c"
    break;

  case 70: /* parameter_type_list_opt: %empty  */
#line 224 "c.y"
    { yyval=NIL; }
#line 1982 "y.tab.c"
    break;

  case 71: /* parameter_type_list_opt: parameter_type_list  */
#line 225 "c.y"
                        { yyval=yyvsp[0]; }
#line 1988 "y.tab.c"
    break;

  case 72: /* parameter_type_list: parameter_list  */
#line 229 "c.y"
                   { yyval=yyvsp[0]; }
#line 1994 "y.tab.c"
    break;

  case 73: /* parameter_type_list: parameter_list COMMA DOTDOTDOT  */
#line 231 "c.y"
    { yyval=linkDeclaratorList(yyvsp[-2],setDeclaratorKind(makeDummyIdentifier(),ID_PARM)); }
#line 2000 "y.tab.c"
    break;

  case 74: /* parameter_list: parameter_declaration  */
#line 235 "c.y"
                          { yyval=yyvsp[0]; }
#line 2006 "y.tab.c"
    break;

  case 75: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 237 "c.y"
    { yyval=linkDeclaratorList(yyvsp[-2],yyvsp[0]); }
#line 2012 "y.tab.c"
    break;

  case 76: /* parameter_declaration: declaration_specifiers declarator  */
#line 242 "c.y"
    { yyval=setParameterDeclaratorSpecifier(yyvsp[0],yyvsp[-1]); }
#line 2018 "y.tab.c"
    break;

  case 77: /* parameter_declaration: declaration_specifiers abstract_declarator_opt  */
#line 244 "c.y"
    { yyval=setParameterDeclaratorSpecifier(setDeclaratorType(makeDummyIdentifier(),yyvsp[0]),yyvsp[-1]); }
#line 2024 "y.tab.c"
    break;

  case 78: /* abstract_declarator_opt: %empty  */
#line 248 "c.y"
    { yyval=NIL; }
#line 2030 "y.tab.c"
    break;

  case 79: /* abstract_declarator_opt: abstract_declarator  */
#line 249 "c.y"
                        { yyval=yyvsp[0]; }
#line 2036 "y.tab.c"
    break;

  case 80: /* abstract_declarator: direct_abstract_declarator  */
#line 253 "c.y"
                               { yyval=yyvsp[0]; }
#line 2042 "y.tab.c"
    break;

  case 81: /* abstract_declarator: pointer  */
#line 254 "c.y"
            { yyval=makeType(T_POINTER); }
#line 2048 "y.tab.c"
    break;

  case 82: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 256 "c.y"
    { yyval=setTypeElementType(yyvsp[0],makeType(T_POINTER)); }
#line 2054 "y.tab.c"
    break;

  case 83: /* direct_abstract_declarator: LP abstract_declarator RP  */
#line 260 "c.y"
                              { yyval=yyvsp[-1]; }
#line 2060 "y.tab.c"
    break;

  case 84: /* direct_abstract_declarator: LB constant_expression_opt RB  */
#line 262 "c.y"
    { yyval=setTypeExpr(makeType(T_ARRAY),yyvsp[-1]); }
#line 2066 "y.tab.c"
    break;

  case 85: /* direct_abstract_declarator: direct_abstract_declarator LB constant_expression_opt RB  */
#line 264 "c.y"
    { yyval=setTypeElementType(yyvsp[-3],setTypeExpr(makeType(T_ARRAY),yyvsp[-1])); }
#line 2072 "y.tab.c"
    break;

  case 86: /* direct_abstract_declarator: LP parameter_type_list_opt RP  */
#line 266 "c.y"
    { yyval=setTypeExpr(makeType(T_FUNC),yyvsp[-1]); }
#line 2078 "y.tab.c"
    break;

  case 87: /* direct_abstract_declarator: direct_abstract_declarator LP parameter_type_list_opt RP  */
#line 268 "c.y"
    { yyval=setTypeElementType(yyvsp[-3],setTypeExpr(makeType(T_FUNC),yyvsp[-1])); }
#line 2084 "y.tab.c"
    break;

  case 88: /* statement_list_opt: %empty  */
#line 272 "c.y"
    { yyval=makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL); }
#line 2090 "y.tab.c"
    break;

  case 89: /* statement_list_opt: statement_list  */
#line 273 "c.y"
                   { yyval=yyvsp[0]; }
#line 2096 "y.tab.c"
    break;

  case 90: /* statement_list: statement  */
#line 278 "c.y"
    { yyval=makeNode(N_STMT_LIST,yyvsp[0],NIL,makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL)); }
#line 2102 "y.tab.c"
    break;

  case 91: /* statement_list: statement_list statement  */
#line 280 "c.y"
    { yyval=makeNodeList(N_STMT_LIST,yyvsp[-1],yyvsp[0]); }
#line 2108 "y.tab.c"
    break;

  case 92: /* statement: labeled_statement  */
#line 284 "c.y"
                      { yyval=yyvsp[0]; }
#line 2114 "y.tab.c"
    break;

  case 93: /* statement: compound_statement  */
#line 285 "c.y"
                       { yyval=yyvsp[0]; }
#line 2120 "y.tab.c"
    break;

  case 94: /* statement: expression_statement  */
#line 286 "c.y"
                         { yyval=yyvsp[0]; }
#line 2126 "y.tab.c"
    break;

  case 95: /* statement: selection_statement  */
#line 287 "c.y"
                        { yyval=yyvsp[0]; }
#line 2132 "y.tab.c"
    break;

  case 96: /* statement: iteration_statement  */
#line 288 "c.y"
                        { yyval=yyvsp[0]; }
#line 2138 "y.tab.c"
    break;

  case 97: /* statement: jump_statement  */
#line 289 "c.y"
                   { yyval=yyvsp[0]; }
#line 2144 "y.tab.c"
    break;

  case 98: /* labeled_statement: CASE_SYM constant_expression COLON statement  */
#line 294 "c.y"
    { yyval=makeNode(N_STMT_LABEL_CASE,yyvsp[-2],NIL,yyvsp[0]); }
#line 2150 "y.tab.c"
    break;

  case 99: /* labeled_statement: DEFAULT_SYM COLON statement  */
#line 296 "c.y"
    { yyval=makeNode(N_STMT_LABEL_DEFAULT,NIL,yyvsp[0],NIL); }
#line 2156 "y.tab.c"
    break;

  case 100: /* @11: %empty  */
#line 300 "c.y"
       { yyval=current_id; current_level++; }
#line 2162 "y.tab.c"
    break;

  case 101: /* compound_statement: LR @11 declaration_list_opt statement_list_opt RR  */
#line 302 "c.y"
    { checkForwardReference(); yyval=makeNode(N_STMT_COMPOUND,yyvsp[-2],NIL,yyvsp[-1]);
  current_id=yyvsp[-3]; current_level--; }
#line 2169 "y.tab.c"
    break;

  case 102: /* expression_statement: SEMICOLON  */
#line 307 "c.y"
              { yyval=makeNode(N_STMT_EMPTY,NIL,NIL,NIL); }
#line 2175 "y.tab.c"
    break;

  case 103: /* expression_statement: expression SEMICOLON  */
#line 309 "c.y"
    { yyval=makeNode(N_STMT_EXPRESSION,NIL,yyvsp[-1],NIL); }
#line 2181 "y.tab.c"
    break;

  case 104: /* selection_statement: IF_SYM LP expression RP statement  */
#line 314 "c.y"
    { yyval=makeNode(N_STMT_IF,yyvsp[-2],NIL,yyvsp[0]); }
#line 2187 "y.tab.c"
    break;

  case 105: /* selection_statement: IF_SYM LP expression RP statement ELSE_SYM statement  */
#line 316 "c.y"
    { yyval=makeNode(N_STMT_IF_ELSE,yyvsp[-4],yyvsp[-2],yyvsp[0]); }
#line 2193 "y.tab.c"
    break;

  case 106: /* selection_statement: SWITCH_SYM LP expression RP statement  */
#line 318 "c.y"
    { yyval=makeNode(N_STMT_SWITCH,yyvsp[-2],NIL,yyvsp[0]); }
#line 2199 "y.tab.c"
    break;

  case 107: /* iteration_statement: WHILE_SYM LP expression RP statement  */
#line 323 "c.y"
    { yyval=makeNode(N_STMT_WHILE,yyvsp[-2],NIL,yyvsp[0]); }
#line 2205 "y.tab.c"
    break;

  case 108: /* iteration_statement: DO_SYM statement WHILE_SYM LP expression RP SEMICOLON  */
#line 325 "c.y"
    { yyval=makeNode(N_STMT_DO,yyvsp[-5],NIL,yyvsp[-2]); }
#line 2211 "y.tab.c"
    break;

  case 109: /* iteration_statement: FOR_SYM LP for_expression RP statement  */
#line 327 "c.y"
    { yyval=makeNode(N_STMT_FOR,yyvsp[-2],NIL,yyvsp[0]); }
#line 2217 "y.tab.c"
    break;

  case 110: /* for_expression: expression_opt SEMICOLON expression_opt SEMICOLON expression_opt  */
#line 332 "c.y"
    { yyval=makeNode(N_FOR_EXP,yyvsp[-4],yyvsp[-2],yyvsp[0]); }
#line 2223 "y.tab.c"
    break;

  case 111: /* expression_opt: %empty  */
#line 336 "c.y"
                { yyval=NIL; }
#line 2229 "y.tab.c"
    break;

  case 112: /* expression_opt: expression  */
#line 337 "c.y"
               { yyval=yyvsp[0]; }
#line 2235 "y.tab.c"
    break;

  case 113: /* jump_statement: RETURN_SYM expression_opt SEMICOLON  */
#line 342 "c.y"
    { yyval=makeNode(N_STMT_RETURN,NIL,yyvsp[-1],NIL); }
#line 2241 "y.tab.c"
    break;

  case 114: /* jump_statement: CONTINUE_SYM SEMICOLON  */
#line 344 "c.y"
    { yyval=makeNode(N_STMT_CONTINUE,NIL,NIL,NIL); }
#line 2247 "y.tab.c"
    break;

  case 115: /* jump_statement: BREAK_SYM SEMICOLON  */
#line 346 "c.y"
    { yyval=makeNode(N_STMT_BREAK,NIL,NIL,NIL); }
#line 2253 "y.tab.c"
    break;

  case 116: /* arg_expression_list_opt: %empty  */
#line 350 "c.y"
    { yyval=makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL); }
#line 2259 "y.tab.c"
    break;

  case 117: /* arg_expression_list_opt: arg_expression_list  */
#line 351 "c.y"
                        { yyval=yyvsp[0]; }
#line 2265 "y.tab.c"
    break;

  case 118: /* arg_expression_list: assignment_expression  */
#line 356 "c.y"
    { yyval=makeNode(N_ARG_LIST,yyvsp[0],NIL,makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL)); }
#line 2271 "y.tab.c"
    break;

  case 119: /* arg_expression_list: arg_expression_list COMMA assignment_expression  */
#line 358 "c.y"
    { yyval=makeNodeList(N_ARG_LIST,yyvsp[-2],yyvsp[0]); }
#line 2277 "y.tab.c"
    break;

  case 120: /* constant_expression_opt: %empty  */
#line 362 "c.y"
    { yyval=NIL; }
#line 2283 "y.tab.c"
    break;

  case 121: /* constant_expression_opt: constant_expression  */
#line 363 "c.y"
                        { yyval=yyvsp[0]; }
#line 2289 "y.tab.c"
    break;

  case 122: /* constant_expression: expression  */
#line 367 "c.y"
               { yyval=yyvsp[0]; }
#line 2295 "y.tab.c"
    break;

  case 123: /* expression: comma_expression  */
#line 371 "c.y"
                     { yyval=yyvsp[0]; }
#line 2301 "y.tab.c"
    break;

  case 124: /* comma_expression: assignment_expression  */
#line 375 "c.y"
                          { yyval=yyvsp[0]; }
#line 2307 "y.tab.c"
    break;

  case 125: /* assignment_expression: conditional_expression  */
#line 379 "c.y"
                           { yyval=yyvsp[0]; }
#line 2313 "y.tab.c"
    break;

  case 126: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 381 "c.y"
    { yyval=makeNode(N_EXP_ASSIGN,yyvsp[-2],NIL,yyvsp[0]); }
#line 2319 "y.tab.c"
    break;

  case 127: /* conditional_expression: logical_or_expression  */
#line 385 "c.y"
                          { yyval=yyvsp[0]; }
#line 2325 "y.tab.c"
    break;

  case 128: /* logical_or_expression: logical_and_expression  */
#line 389 "c.y"
                           { yyval=yyvsp[0]; }
#line 2331 "y.tab.c"
    break;

  case 129: /* logical_or_expression: logical_or_expression BARBAR logical_and_expression  */
#line 391 "c.y"
    { yyval=makeNode(N_EXP_OR,yyvsp[-2],NIL,yyvsp[0]); }
#line 2337 "y.tab.c"
    break;

  case 130: /* logical_and_expression: bitwise_or_expression  */
#line 395 "c.y"
                          { yyval=yyvsp[0]; }
#line 2343 "y.tab.c"
    break;

  case 131: /* logical_and_expression: logical_and_expression AMPAMP bitwise_or_expression  */
#line 397 "c.y"
    { yyval=makeNode(N_EXP_AND,yyvsp[-2],NIL,yyvsp[0]); }
#line 2349 "y.tab.c"
    break;

  case 132: /* bitwise_or_expression: bitwise_xor_expression  */
#line 401 "c.y"
                           { yyval=yyvsp[0]; }
#line 2355 "y.tab.c"
    break;

  case 133: /* bitwise_xor_expression: bitwise_and_expression  */
#line 405 "c.y"
                           { yyval=yyvsp[0]; }
#line 2361 "y.tab.c"
    break;

  case 134: /* bitwise_and_expression: equality_expression  */
#line 409 "c.y"
                        { yyval=yyvsp[0]; }
#line 2367 "y.tab.c"
    break;

  case 135: /* equality_expression: relational_expression  */
#line 413 "c.y"
                          { yyval=yyvsp[0]; }
#line 2373 "y.tab.c"
    break;

  case 136: /* equality_expression: equality_expression EQL relational_expression  */
#line 415 "c.y"
    { yyval=makeNode(N_EXP_EQL,yyvsp[-2],NIL,yyvsp[0]); }
#line 2379 "y.tab.c"
    break;

  case 137: /* equality_expression: equality_expression NEQ relational_expression  */
#line 417 "c.y"
    { yyval=makeNode(N_EXP_NEQ,yyvsp[-2],NIL,yyvsp[0]); }
#line 2385 "y.tab.c"
    break;

  case 138: /* relational_expression: shift_expression  */
#line 421 "c.y"
                     { yyval=yyvsp[0]; }
#line 2391 "y.tab.c"
    break;

  case 139: /* relational_expression: relational_expression LSS shift_expression  */
#line 423 "c.y"
    { yyval=makeNode(N_EXP_LSS,yyvsp[-2],NIL,yyvsp[0]); }
#line 2397 "y.tab.c"
    break;

  case 140: /* relational_expression: relational_expression GTR shift_expression  */
#line 425 "c.y"
    { yyval=makeNode(N_EXP_GTR,yyvsp[-2],NIL,yyvsp[0]); }
#line 2403 "y.tab.c"
    break;

  case 141: /* relational_expression: relational_expression LEQ shift_expression  */
#line 427 "c.y"
    { yyval=makeNode(N_EXP_LEQ,yyvsp[-2],NIL,yyvsp[0]); }
#line 2409 "y.tab.c"
    break;

  case 142: /* relational_expression: relational_expression GEQ shift_expression  */
#line 429 "c.y"
    { yyval=makeNode(N_EXP_GEQ,yyvsp[-2],NIL,yyvsp[0]); }
#line 2415 "y.tab.c"
    break;

  case 143: /* shift_expression: additive_expression  */
#line 433 "c.y"
                        { yyval=yyvsp[0]; }
#line 2421 "y.tab.c"
    break;

  case 144: /* additive_expression: multiplicative_expression  */
#line 437 "c.y"
                              { yyval=yyvsp[0]; }
#line 2427 "y.tab.c"
    break;

  case 145: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 439 "c.y"
    { yyval=makeNode(N_EXP_ADD,yyvsp[-2],NIL,yyvsp[0]); }
#line 2433 "y.tab.c"
    break;

  case 146: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 441 "c.y"
    { yyval=makeNode(N_EXP_SUB,yyvsp[-2],NIL,yyvsp[0]); }
#line 2439 "y.tab.c"
    break;

  case 147: /* multiplicative_expression: cast_expression  */
#line 445 "c.y"
                    { yyval=yyvsp[0]; }
#line 2445 "y.tab.c"
    break;

  case 148: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 447 "c.y"
    { yyval=makeNode(N_EXP_MUL,yyvsp[-2],NIL,yyvsp[0]); }
#line 2451 "y.tab.c"
    break;

  case 149: /* multiplicative_expression: multiplicative_expression SLASH cast_expression  */
#line 449 "c.y"
    { yyval=makeNode(N_EXP_DIV,yyvsp[-2],NIL,yyvsp[0]); }
#line 2457 "y.tab.c"
    break;

  case 150: /* multiplicative_expression: multiplicative_expression PERCENT cast_expression  */
#line 451 "c.y"
    { yyval=makeNode(N_EXP_MOD,yyvsp[-2],NIL,yyvsp[0]); }
#line 2463 "y.tab.c"
    break;

  case 151: /* cast_expression: unary_expression  */
#line 455 "c.y"
                     { yyval=yyvsp[0]; }
#line 2469 "y.tab.c"
    break;

  case 152: /* cast_expression: LP type_name RP cast_expression  */
#line 457 "c.y"
    { yyval=makeNode(N_EXP_CAST,yyvsp[-2],NIL,yyvsp[0]); }
#line 2475 "y.tab.c"
    break;

  case 153: /* unary_expression: postfix_expression  */
#line 461 "c.y"
                       { yyval=yyvsp[0]; }
#line 2481 "y.tab.c"
    break;

  case 154: /* unary_expression: PLUSPLUS unary_expression  */
#line 463 "c.y"
    { yyval=makeNode(N_EXP_PRE_INC,NIL,yyvsp[0],NIL); }
#line 2487 "y.tab.c"
    break;

  case 155: /* unary_expression: MINUSMINUS unary_expression  */
#line 465 "c.y"
    { yyval=makeNode(N_EXP_PRE_DEC,NIL,yyvsp[0],NIL); }
#line 2493 "y.tab.c"
    break;

  case 156: /* unary_expression: AMP cast_expression  */
#line 467 "c.y"
    { yyval=makeNode(N_EXP_AMP,NIL,yyvsp[0],NIL); }
#line 2499 "y.tab.c"
    break;

  case 157: /* unary_expression: STAR cast_expression  */
#line 469 "c.y"
    { yyval=makeNode(N_EXP_STAR,NIL,yyvsp[0],NIL); }
#line 2505 "y.tab.c"
    break;

  case 158: /* unary_expression: EXCL cast_expression  */
#line 471 "c.y"
    { yyval=makeNode(N_EXP_NOT,NIL,yyvsp[0],NIL); }
#line 2511 "y.tab.c"
    break;

  case 159: /* unary_expression: MINUS cast_expression  */
#line 473 "c.y"
    { yyval=makeNode(N_EXP_MINUS,NIL,yyvsp[0],NIL); }
#line 2517 "y.tab.c"
    break;

  case 160: /* unary_expression: PLUS cast_expression  */
#line 475 "c.y"
    { yyval=makeNode(N_EXP_PLUS,NIL,yyvsp[0],NIL); }
#line 2523 "y.tab.c"
    break;

  case 161: /* unary_expression: SIZEOF_SYM unary_expression  */
#line 477 "c.y"
    { yyval=makeNode(N_EXP_SIZE_EXP,NIL,yyvsp[0],NIL); }
#line 2529 "y.tab.c"
    break;

  case 162: /* unary_expression: SIZEOF_SYM LP type_name RP  */
#line 479 "c.y"
    { yyval=makeNode(N_EXP_SIZE_TYPE,NIL,yyvsp[-1],NIL); }
#line 2535 "y.tab.c"
    break;

  case 163: /* postfix_expression: primary_expression  */
#line 483 "c.y"
                       { yyval=yyvsp[0]; }
#line 2541 "y.tab.c"
    break;

  case 164: /* postfix_expression: postfix_expression LB expression RB  */
#line 485 "c.y"
    { yyval=makeNode(N_EXP_ARRAY,yyvsp[-3],NIL,yyvsp[-1]); }
#line 2547 "y.tab.c"
    break;

  case 165: /* postfix_expression: postfix_expression LP arg_expression_list_opt RP  */
#line 487 "c.y"
    { yyval=makeNode(N_EXP_FUNCTION_CALL,yyvsp[-3],NIL,yyvsp[-1]); }
#line 2553 "y.tab.c"
    break;

  case 166: /* postfix_expression: postfix_expression PERIOD IDENTIFIER  */
#line 489 "c.y"
    { yyval=makeNode(N_EXP_STRUCT,yyvsp[-2],NIL,yyvsp[0]); }
#line 2559 "y.tab.c"
    break;

  case 167: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 491 "c.y"
    { yyval=makeNode(N_EXP_ARROW,yyvsp[-2],NIL,yyvsp[0]); }
#line 2565 "y.tab.c"
    break;

  case 168: /* postfix_expression: postfix_expression PLUSPLUS  */
#line 493 "c.y"
    { yyval=makeNode(N_EXP_POST_INC,NIL,yyvsp[-1],NIL); }
#line 2571 "y.tab.c"
    break;

  case 169: /* postfix_expression: postfix_expression MINUSMINUS  */
#line 495 "c.y"
    { yyval=makeNode(N_EXP_POST_DEC,NIL,yyvsp[-1],NIL); }
#line 2577 "y.tab.c"
    break;

  case 170: /* primary_expression: IDENTIFIER  */
#line 500 "c.y"
    { yyval=makeNode(N_EXP_IDENT,NIL,getIdentifierDeclared(yyvsp[0]),NIL); }
#line 2583 "y.tab.c"
    break;

  case 171: /* primary_expression: INTEGER_CONSTANT  */
#line 502 "c.y"
    { yyval=makeNode(N_EXP_INT_CONST,NIL,yyvsp[0],NIL); }
#line 2589 "y.tab.c"
    break;

  case 172: /* primary_expression: FLOAT_CONSTANT  */
#line 504 "c.y"
    { yyval=makeNode(N_EXP_FLOAT_CONST,NIL,yyvsp[0],NIL); }
#line 2595 "y.tab.c"
    break;

  case 173: /* primary_expression: CHARACTER_CONSTANT  */
#line 506 "c.y"
    { yyval=makeNode(N_EXP_CHAR_CONST,NIL,yyvsp[0],NIL); }
#line 2601 "y.tab.c"
    break;

  case 174: /* primary_expression: STRING_LITERAL  */
#line 508 "c.y"
    { yyval=makeNode(N_EXP_STRING_LITERAL,NIL,yyvsp[0],NIL); }
#line 2607 "y.tab.c"
    break;

  case 175: /* primary_expression: LP expression RP  */
#line 509 "c.y"
                     { yyval=yyvsp[-1]; }
#line 2613 "y.tab.c"
    break;

  case 176: /* type_name: declaration_specifiers abstract_declarator_opt  */
#line 514 "c.y"
    { yyval=setTypeNameSpecifier(yyvsp[0],yyvsp[-1]); }
#line 2619 "y.tab.c"
    break;


#line 2623 "y.tab.c"

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

#line 517 "c.y"

extern char *yytext;
void yyerror(char *s)
{
    syntax_err++;
    printf("line %d: %s near %s \n",line_no,s,yytext);
}
