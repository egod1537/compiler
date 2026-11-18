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
#line 4 "c.y"

#include "parse_value.h"
#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "semantic.h"
#include "syntax_tree.h"
#include "type.h"

int yylex(void);
int yyerror(const char *s);
extern int line_no;
extern char *yytext;

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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INVALID_TOKEN = 3,              /* INVALID_TOKEN  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_TYPE_IDENTIFIER = 5,            /* TYPE_IDENTIFIER  */
  YYSYMBOL_INTEGER_CONSTANT = 6,           /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 7,             /* FLOAT_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 8,         /* CHARACTER_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 9,             /* STRING_LITERAL  */
  YYSYMBOL_BREAK_SYM = 10,                 /* BREAK_SYM  */
  YYSYMBOL_CASE_SYM = 11,                  /* CASE_SYM  */
  YYSYMBOL_CONTINUE_SYM = 12,              /* CONTINUE_SYM  */
  YYSYMBOL_DEFAULT_SYM = 13,               /* DEFAULT_SYM  */
  YYSYMBOL_DO_SYM = 14,                    /* DO_SYM  */
  YYSYMBOL_ELSE_SYM = 15,                  /* ELSE_SYM  */
  YYSYMBOL_ENUM_SYM = 16,                  /* ENUM_SYM  */
  YYSYMBOL_FOR_SYM = 17,                   /* FOR_SYM  */
  YYSYMBOL_IF_SYM = 18,                    /* IF_SYM  */
  YYSYMBOL_RETURN_SYM = 19,                /* RETURN_SYM  */
  YYSYMBOL_SIZEOF_SYM = 20,                /* SIZEOF_SYM  */
  YYSYMBOL_STRUCT_SYM = 21,                /* STRUCT_SYM  */
  YYSYMBOL_SWITCH_SYM = 22,                /* SWITCH_SYM  */
  YYSYMBOL_UNION_SYM = 23,                 /* UNION_SYM  */
  YYSYMBOL_WHILE_SYM = 24,                 /* WHILE_SYM  */
  YYSYMBOL_PLUSPLUS = 25,                  /* PLUSPLUS  */
  YYSYMBOL_MINUSMINUS = 26,                /* MINUSMINUS  */
  YYSYMBOL_ARROW = 27,                     /* ARROW  */
  YYSYMBOL_LSS = 28,                       /* LSS  */
  YYSYMBOL_GTR = 29,                       /* GTR  */
  YYSYMBOL_LEQ = 30,                       /* LEQ  */
  YYSYMBOL_GEQ = 31,                       /* GEQ  */
  YYSYMBOL_EQL = 32,                       /* EQL  */
  YYSYMBOL_NEQ = 33,                       /* NEQ  */
  YYSYMBOL_AMPAMP = 34,                    /* AMPAMP  */
  YYSYMBOL_BARBAR = 35,                    /* BARBAR  */
  YYSYMBOL_DOTDOTDOT = 36,                 /* DOTDOTDOT  */
  YYSYMBOL_LP = 37,                        /* LP  */
  YYSYMBOL_RP = 38,                        /* RP  */
  YYSYMBOL_LB = 39,                        /* LB  */
  YYSYMBOL_RB = 40,                        /* RB  */
  YYSYMBOL_LR = 41,                        /* LR  */
  YYSYMBOL_RR = 42,                        /* RR  */
  YYSYMBOL_COLON = 43,                     /* COLON  */
  YYSYMBOL_PERIOD = 44,                    /* PERIOD  */
  YYSYMBOL_COMMA = 45,                     /* COMMA  */
  YYSYMBOL_EXCL = 46,                      /* EXCL  */
  YYSYMBOL_STAR = 47,                      /* STAR  */
  YYSYMBOL_SLASH = 48,                     /* SLASH  */
  YYSYMBOL_PERCENT = 49,                   /* PERCENT  */
  YYSYMBOL_AMP = 50,                       /* AMP  */
  YYSYMBOL_BAR = 51,                       /* BAR  */
  YYSYMBOL_SEMICOLON = 52,                 /* SEMICOLON  */
  YYSYMBOL_PLUS = 53,                      /* PLUS  */
  YYSYMBOL_MINUS = 54,                     /* MINUS  */
  YYSYMBOL_ASSIGN = 55,                    /* ASSIGN  */
  YYSYMBOL_LOWER_THAN_ELSE = 56,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_program = 58,                   /* program  */
  YYSYMBOL_translation_unit = 59,          /* translation_unit  */
  YYSYMBOL_external_declaration = 60,      /* external_declaration  */
  YYSYMBOL_function_definition = 61,       /* function_definition  */
  YYSYMBOL_62_1 = 62,                      /* @1  */
  YYSYMBOL_63_2 = 63,                      /* @2  */
  YYSYMBOL_declaration_list_opt = 64,      /* declaration_list_opt  */
  YYSYMBOL_declaration = 65,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 66,    /* declaration_specifiers  */
  YYSYMBOL_declarator_list_opt = 67,       /* declarator_list_opt  */
  YYSYMBOL_declarator_list = 68,           /* declarator_list  */
  YYSYMBOL_type_specifier = 69,            /* type_specifier  */
  YYSYMBOL_struct_specifier = 70,          /* struct_specifier  */
  YYSYMBOL_71_3 = 71,                      /* @3  */
  YYSYMBOL_72_4 = 72,                      /* @4  */
  YYSYMBOL_struct_or_union = 73,           /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 74,   /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 75,        /* struct_declaration  */
  YYSYMBOL_struct_declarator_list = 76,    /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 77,         /* struct_declarator  */
  YYSYMBOL_enum_specifier = 78,            /* enum_specifier  */
  YYSYMBOL_79_5 = 79,                      /* @5  */
  YYSYMBOL_80_6 = 80,                      /* @6  */
  YYSYMBOL_enumerator_list = 81,           /* enumerator_list  */
  YYSYMBOL_enumerator = 82,                /* enumerator  */
  YYSYMBOL_declarator = 83,                /* declarator  */
  YYSYMBOL_pointer = 84,                   /* pointer  */
  YYSYMBOL_direct_declarator = 85,         /* direct_declarator  */
  YYSYMBOL_86_7 = 86,                      /* $@7  */
  YYSYMBOL_constant_expression_opt = 87,   /* constant_expression_opt  */
  YYSYMBOL_parameter_type_list_opt = 88,   /* parameter_type_list_opt  */
  YYSYMBOL_parameter_type_list = 89,       /* parameter_type_list  */
  YYSYMBOL_parameter_list = 90,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 91,     /* parameter_declaration  */
  YYSYMBOL_abstract_declarator_opt = 92,   /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 93,       /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 94, /* direct_abstract_declarator  */
  YYSYMBOL_statement = 95,                 /* statement  */
  YYSYMBOL_labeled_statement = 96,         /* labeled_statement  */
  YYSYMBOL_compound_statement = 97,        /* compound_statement  */
  YYSYMBOL_98_8 = 98,                      /* $@8  */
  YYSYMBOL_declaration_list = 99,          /* declaration_list  */
  YYSYMBOL_statement_list_opt = 100,       /* statement_list_opt  */
  YYSYMBOL_statement_list = 101,           /* statement_list  */
  YYSYMBOL_expression_statement = 102,     /* expression_statement  */
  YYSYMBOL_selection_statement = 103,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 104,      /* iteration_statement  */
  YYSYMBOL_expression_opt = 105,           /* expression_opt  */
  YYSYMBOL_for_expression = 106,           /* for_expression  */
  YYSYMBOL_jump_statement = 107,           /* jump_statement  */
  YYSYMBOL_primary_expression = 108,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 109,       /* postfix_expression  */
  YYSYMBOL_arg_expression_list_opt = 110,  /* arg_expression_list_opt  */
  YYSYMBOL_arg_expression_list = 111,      /* arg_expression_list  */
  YYSYMBOL_unary_expression = 112,         /* unary_expression  */
  YYSYMBOL_cast_expression = 113,          /* cast_expression  */
  YYSYMBOL_type_name = 114,                /* type_name  */
  YYSYMBOL_multiplicative_expression = 115, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 116,      /* additive_expression  */
  YYSYMBOL_shift_expression = 117,         /* shift_expression  */
  YYSYMBOL_relational_expression = 118,    /* relational_expression  */
  YYSYMBOL_equality_expression = 119,      /* equality_expression  */
  YYSYMBOL_AND_expression = 120,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 121,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 122,  /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 123,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 124,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 125,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 126,    /* assignment_expression  */
  YYSYMBOL_comma_expression = 127,         /* comma_expression  */
  YYSYMBOL_expression = 128,               /* expression  */
  YYSYMBOL_constant_expression = 129       /* constant_expression  */
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
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   392

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  272

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
       0,    52,    52,    61,    62,    69,    70,    77,    76,    85,
      84,   102,   105,   112,   119,   127,   130,   137,   141,   148,
     149,   150,   160,   159,   174,   173,   185,   194,   195,   199,
     200,   207,   214,   215,   222,   229,   228,   237,   236,   244,
     251,   252,   259,   276,   280,   287,   291,   300,   309,   313,
     319,   318,   336,   339,   349,   352,   359,   360,   368,   372,
     379,   383,   395,   398,   405,   409,   413,   420,   424,   428,
     432,   437,   451,   452,   456,   460,   461,   462,   469,   473,
     483,   482,   496,   500,   508,   511,   518,   523,   532,   536,
     545,   549,   553,   562,   566,   570,   578,   581,   588,   597,
     602,   606,   619,   627,   631,   635,   639,   643,   650,   654,
     658,   662,   667,   672,   676,   684,   687,   691,   696,   705,
     709,   713,   717,   721,   725,   729,   733,   737,   741,   748,
     752,   759,   768,   772,   776,   780,   787,   791,   795,   802,
     808,   812,   816,   820,   824,   831,   835,   839,   848,   852,
     856,   860,   861,   868,   869,   878,   885,   889,   896,   905,
     912
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
  "\"end of file\"", "error", "\"invalid token\"", "INVALID_TOKEN",
  "IDENTIFIER", "TYPE_IDENTIFIER", "INTEGER_CONSTANT", "FLOAT_CONSTANT",
  "CHARACTER_CONSTANT", "STRING_LITERAL", "BREAK_SYM", "CASE_SYM",
  "CONTINUE_SYM", "DEFAULT_SYM", "DO_SYM", "ELSE_SYM", "ENUM_SYM",
  "FOR_SYM", "IF_SYM", "RETURN_SYM", "SIZEOF_SYM", "STRUCT_SYM",
  "SWITCH_SYM", "UNION_SYM", "WHILE_SYM", "PLUSPLUS", "MINUSMINUS",
  "ARROW", "LSS", "GTR", "LEQ", "GEQ", "EQL", "NEQ", "AMPAMP", "BARBAR",
  "DOTDOTDOT", "LP", "RP", "LB", "RB", "LR", "RR", "COLON", "PERIOD",
  "COMMA", "EXCL", "STAR", "SLASH", "PERCENT", "AMP", "BAR", "SEMICOLON",
  "PLUS", "MINUS", "ASSIGN", "LOWER_THAN_ELSE", "$accept", "program",
  "translation_unit", "external_declaration", "function_definition", "@1",
  "@2", "declaration_list_opt", "declaration", "declaration_specifiers",
  "declarator_list_opt", "declarator_list", "type_specifier",
  "struct_specifier", "@3", "@4", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "enum_specifier", "@5",
  "@6", "enumerator_list", "enumerator", "declarator", "pointer",
  "direct_declarator", "$@7", "constant_expression_opt",
  "parameter_type_list_opt", "parameter_type_list", "parameter_list",
  "parameter_declaration", "abstract_declarator_opt",
  "abstract_declarator", "direct_abstract_declarator", "statement",
  "labeled_statement", "compound_statement", "$@8", "declaration_list",
  "statement_list_opt", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "expression_opt",
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

#define YYPACT_NINF (-214)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-36)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     144,  -214,  -214,    39,  -214,  -214,    76,   -16,    13,   144,
    -214,  -214,  -214,    76,  -214,  -214,    53,  -214,  -214,    26,
      92,    19,    38,    36,  -214,  -214,  -214,    62,    73,    64,
      97,   109,   114,    92,  -214,   283,   125,   179,  -214,  -214,
      76,   114,   128,   169,  -214,  -214,   169,  -214,  -214,  -214,
    -214,  -214,   315,   338,   338,   260,   283,   283,   283,   283,
     283,   149,  -214,   100,  -214,  -214,    54,    93,  -214,   165,
     129,  -214,  -214,  -214,   153,   163,  -214,  -214,   179,  -214,
      33,  -214,  -214,  -214,   169,    76,   112,  -214,   169,    60,
     172,  -214,   166,  -214,   260,  -214,   283,  -214,  -214,    83,
     170,   186,  -214,  -214,  -214,   192,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,   228,   283,   283,   232,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,    74,  -214,   179,   159,    -8,  -214,  -214,  -214,  -214,
     209,  -214,    76,   169,    29,   283,  -214,    44,  -214,  -214,
     119,  -214,   237,   199,    30,   147,  -214,   283,   283,  -214,
    -214,   200,   194,  -214,   201,  -214,  -214,  -214,  -214,    54,
      54,  -214,  -214,  -214,  -214,   165,   165,  -214,   153,  -214,
    -214,  -214,    76,  -214,   188,   283,   191,   202,   209,   207,
     210,   283,   211,   212,  -214,  -214,  -214,  -214,   215,   209,
    -214,  -214,  -214,  -214,   218,  -214,  -214,   213,   214,   231,
     119,   169,   283,  -214,  -214,  -214,  -214,  -214,  -214,   283,
    -214,  -214,  -214,   229,  -214,   209,   230,   283,   283,   222,
    -214,   283,   283,  -214,  -214,  -214,  -214,  -214,  -214,   239,
     235,  -214,   209,  -214,   241,   227,   244,   246,  -214,   250,
     255,  -214,  -214,  -214,   283,   283,   209,   209,   209,   209,
     256,   243,  -214,   281,  -214,  -214,   247,   283,   209,  -214,
    -214,  -214
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    47,    21,    37,    27,    28,     0,    45,     0,     2,
       3,     5,     6,    15,    14,    19,    24,    20,     9,     0,
      44,    39,     0,     0,    46,     1,     4,     0,    16,    17,
      26,     0,     0,    43,    50,    52,     0,     0,    48,    13,
       0,     0,     0,     0,    80,    10,    54,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,   119,   129,   132,   136,   139,   140,   145,
     148,   149,   150,   151,   153,   155,   160,    53,     0,    42,
       0,    40,    18,     8,     0,     0,     0,    29,    11,    62,
       0,    55,    56,    58,     0,   127,     0,   120,   121,    62,
     129,     0,   156,   158,   159,     0,   124,   123,   122,   126,
     125,    49,   113,   114,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,    32,    34,    25,    30,
      84,    82,    15,    12,    54,    52,    60,    64,    61,    63,
      65,    51,     0,     0,    54,    64,   131,     0,     0,   107,
     112,     0,   116,   117,     0,   111,   133,   134,   135,   137,
     138,   141,   142,   143,   144,   146,   147,   152,   154,    36,
      41,    23,     0,    31,     0,     0,     0,     0,     0,     0,
       0,    96,     0,     0,    88,    86,    72,    73,     0,    85,
      74,    75,    76,    77,     0,    17,    83,     0,     0,     0,
      66,    54,    52,    57,    59,   128,   157,   130,   110,     0,
     109,    33,   101,     0,   100,     0,     0,    96,     0,     0,
      97,     0,     0,    81,    87,    89,    69,    67,    68,     0,
       0,   118,     0,    79,     0,     0,     0,     0,    99,     0,
       0,    71,    70,    78,     0,    96,     0,     0,     0,     0,
       0,     0,    95,    90,    92,    93,     0,    96,     0,    94,
      98,    91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,  -214,   289,  -214,  -214,  -214,  -214,   -81,    27,
    -214,  -214,   -28,  -214,  -214,  -214,  -214,   216,   -69,  -214,
     120,  -214,  -214,  -214,   223,   171,    15,     9,   -15,  -214,
    -139,   -43,  -214,  -214,   160,   206,   -95,  -115,   -54,  -214,
      -3,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -213,  -214,
    -214,  -214,  -214,  -214,  -214,   -34,   -48,   217,    85,  -214,
      17,    81,  -214,  -214,  -214,   187,   185,  -214,   -33,  -110,
    -214,   -55,   132
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    41,    32,   140,    12,    89,
      27,    28,    14,    15,    42,    31,    16,    86,    87,   135,
     136,    17,    36,    22,    80,    81,    18,    19,    20,    46,
      61,   207,    91,    92,    93,   148,   149,   150,   195,   196,
     197,    88,   143,   198,   199,   200,   201,   202,   229,   246,
     203,    62,    63,   161,   162,   100,    65,   101,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,   102,   103,
     104,   204,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     105,    64,    76,    90,    33,   163,   209,   141,   106,   107,
     108,   109,   110,    25,   245,    85,    24,   139,    95,    97,
      98,    23,    64,    64,    64,    64,    64,    13,    29,    45,
       1,     7,   210,     1,     2,     2,    13,   182,    83,   105,
     210,   105,   261,    21,   183,     3,     3,   216,     1,   208,
       4,     4,     5,     5,   270,    82,    85,    30,    85,   208,
     -35,   164,   206,     6,     1,   139,   144,   154,   145,   145,
     166,   167,   168,   240,    38,   132,     7,     7,   133,    37,
       1,   144,    99,   145,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,   144,   147,   145,
     137,   118,   119,   120,   146,    -7,    85,     7,   155,   241,
     217,    64,    76,     6,    39,   142,   179,     2,    40,   133,
     154,    99,   145,     7,    64,   112,   113,   114,     3,    34,
       7,    35,    33,     4,   226,     5,   230,   115,   -22,   116,
     171,   172,   173,   174,   117,   234,   121,   122,     1,     2,
      43,    64,    76,   147,   138,    44,   211,   205,   212,    23,
       3,   127,   128,   155,     2,     4,    78,     5,   239,    84,
     142,   243,   230,   247,     2,     3,   249,   250,    64,    76,
       4,     6,     5,    79,   154,     3,   145,   129,   253,   111,
       4,     7,     5,   123,   124,   125,   126,   137,   130,   260,
     230,   181,   262,   263,   264,   265,   169,   170,   175,   176,
     151,   152,   230,    47,   271,    48,    49,    50,    51,   184,
     185,   186,   187,   188,   158,   157,   189,   190,   191,    52,
     159,   192,   160,   193,    53,    54,   165,   215,   218,   219,
     222,   220,     2,   224,   227,   225,    55,   228,   231,   232,
      44,   236,   237,     3,   244,    56,    57,   233,     4,    58,
       5,   194,    59,    60,    47,     2,    48,    49,    50,    51,
     235,   238,   242,   213,   248,   252,     3,   251,   254,   255,
      52,     4,   256,     5,   257,    53,    54,    47,   258,    48,
      49,    50,    51,   259,   266,   267,   268,    55,    26,   269,
     134,   131,   221,    52,   180,   156,    56,    57,    53,    54,
      58,   153,   214,    59,    60,   178,   177,   223,     0,    47,
      55,    48,    49,    50,    51,     0,     0,     0,     0,    56,
      57,     0,     0,    58,     0,    52,    59,    60,     0,     0,
      53,    54,    47,     0,    48,    49,    50,    51,     0,     0,
       0,     0,    94,     0,     0,     0,     0,     0,    52,     0,
       0,    56,    57,    53,    54,    58,     0,     0,    59,    60,
       0,     0,     0,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,     0,     0,    58,     0,
       0,    59,    60
};

static const yytype_int16 yycheck[] =
{
      55,    35,    35,    46,    19,   115,   145,    88,    56,    57,
      58,    59,    60,     0,   227,    43,     7,    86,    52,    53,
      54,     6,    56,    57,    58,    59,    60,     0,    13,    32,
       4,    47,   147,     4,     5,     5,     9,    45,    41,    94,
     155,    96,   255,     4,    52,    16,    16,   157,     4,   144,
      21,    21,    23,    23,   267,    40,    84,     4,    86,   154,
      41,   116,   143,    37,     4,   134,    37,    37,    39,    39,
     118,   119,   120,   212,    38,    42,    47,    47,    45,    41,
       4,    37,    55,    39,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    37,    89,    39,
      85,    47,    48,    49,    89,    41,   134,    47,    99,   219,
     158,   145,   145,    37,    52,    88,    42,     5,    45,    45,
      37,    94,    39,    47,   158,    25,    26,    27,    16,    37,
      47,    39,   147,    21,   188,    23,   191,    37,    41,    39,
     123,   124,   125,   126,    44,   199,    53,    54,     4,     5,
      41,   185,   185,   144,    42,    41,    37,   142,    39,   144,
      16,    32,    33,   154,     5,    21,    41,    23,   211,    41,
     143,   225,   227,   228,     5,    16,   231,   232,   212,   212,
      21,    37,    23,     4,    37,    16,    39,    34,   242,    40,
      21,    47,    23,    28,    29,    30,    31,   182,    35,   254,
     255,    42,   256,   257,   258,   259,   121,   122,   127,   128,
      38,    45,   267,     4,   268,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    38,    55,    17,    18,    19,    20,
      38,    22,     4,    24,    25,    26,     4,    38,    38,    45,
      52,    40,     5,    52,    37,    43,    37,    37,    37,    37,
      41,    38,    38,    16,    24,    46,    47,    42,    21,    50,
      23,    52,    53,    54,     4,     5,     6,     7,     8,     9,
      52,    40,    43,    36,    52,    40,    16,    38,    37,    52,
      20,    21,    38,    23,    38,    25,    26,     4,    38,     6,
       7,     8,     9,    38,    38,    52,    15,    37,     9,    52,
      84,    78,   182,    20,   133,    99,    46,    47,    25,    26,
      50,    94,   152,    53,    54,   130,   129,   185,    -1,     4,
      37,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    46,
      47,    -1,    -1,    50,    -1,    20,    53,    54,    -1,    -1,
      25,    26,     4,    -1,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    46,    47,    25,    26,    50,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    50,    -1,
      -1,    53,    54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    16,    21,    23,    37,    47,    58,    59,
      60,    61,    65,    66,    69,    70,    73,    78,    83,    84,
      85,     4,    80,    83,    84,     0,    60,    67,    68,    83,
       4,    72,    63,    85,    37,    39,    79,    41,    38,    52,
      45,    62,    71,    41,    41,    97,    86,     4,     6,     7,
       8,     9,    20,    25,    26,    37,    46,    47,    50,    53,
      54,    87,   108,   109,   112,   113,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   129,    41,     4,
      81,    82,    83,    97,    41,    69,    74,    75,    98,    66,
      88,    89,    90,    91,    37,   112,    37,   112,   112,    66,
     112,   114,   125,   126,   127,   128,   113,   113,   113,   113,
     113,    40,    25,    26,    27,    37,    39,    44,    47,    48,
      49,    53,    54,    28,    29,    30,    31,    32,    33,    34,
      35,    81,    42,    45,    74,    76,    77,    83,    42,    75,
      64,    65,    66,    99,    37,    39,    83,    84,    92,    93,
      94,    38,    45,   114,    37,    84,    92,    55,    38,    38,
       4,   110,   111,   126,   128,     4,   113,   113,   113,   115,
     115,   117,   117,   117,   117,   118,   118,   122,   123,    42,
      82,    42,    45,    52,    10,    11,    12,    13,    14,    17,
      18,    19,    22,    24,    52,    95,    96,    97,   100,   101,
     102,   103,   104,   107,   128,    83,    65,    88,    93,    87,
      94,    37,    39,    36,    91,    38,   126,   113,    38,    45,
      40,    77,    52,   129,    52,    43,    95,    37,    37,   105,
     128,    37,    37,    42,    95,    52,    38,    38,    40,    88,
      87,   126,    43,    95,    24,   105,   106,   128,    52,   128,
     128,    38,    40,    95,    37,    52,    38,    38,    38,    38,
     128,   105,    95,    95,    95,    95,    38,    52,    15,    52,
     105,    95
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    62,    61,    63,
      61,    64,    64,    65,    66,    67,    67,    68,    68,    69,
      69,    69,    71,    70,    72,    70,    70,    73,    73,    74,
      74,    75,    76,    76,    77,    79,    78,    80,    78,    78,
      81,    81,    82,    83,    83,    84,    84,    85,    85,    85,
      86,    85,    87,    87,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    93,    93,    93,    94,    94,    94,
      94,    94,    95,    95,    95,    95,    95,    95,    96,    96,
      98,    97,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   103,   104,   104,   104,   105,   105,   106,   107,
     107,   107,   108,   108,   108,   108,   108,   108,   109,   109,
     109,   109,   109,   109,   109,   110,   110,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   113,
     113,   114,   115,   115,   115,   115,   116,   116,   116,   117,
     118,   118,   118,   118,   118,   119,   119,   119,   120,   121,
     122,   123,   123,   124,   124,   125,   126,   126,   127,   128,
     129
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     4,     0,
       3,     0,     1,     3,     1,     0,     1,     1,     3,     1,
       1,     1,     0,     6,     0,     5,     2,     1,     1,     1,
       2,     3,     1,     3,     1,     0,     6,     0,     5,     2,
       1,     3,     1,     2,     1,     1,     2,     1,     3,     4,
       0,     5,     0,     1,     0,     1,     1,     3,     1,     3,
       2,     2,     0,     1,     1,     1,     2,     3,     3,     3,
       4,     4,     1,     1,     1,     1,     1,     1,     4,     3,
       0,     5,     1,     2,     0,     1,     1,     2,     1,     2,
       5,     7,     5,     5,     7,     5,     0,     1,     5,     3,
       2,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       4,     3,     3,     2,     2,     0,     1,     1,     3,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     1,
       4,     2,     1,     3,     3,     3,     1,     3,     3,     1,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     3,     1,     1,
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
  case 2: /* program: translation_unit  */
#line 53 "c.y"
    {
      program_root = makeNode(N_PROGRAM, NULL, PTR(A_NODE, yyvsp[0]), NULL);
      checkForwardReference();
      yyval = YY(program_root);
    }
#line 1546 "y.tab.c"
    break;

  case 3: /* translation_unit: external_declaration  */
#line 61 "c.y"
                           { yyval = yyvsp[0]; }
#line 1552 "y.tab.c"
    break;

  case 4: /* translation_unit: translation_unit external_declaration  */
#line 63 "c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-1]), PTR(A_ID, yyvsp[0])));
    }
#line 1560 "y.tab.c"
    break;

  case 5: /* external_declaration: function_definition  */
#line 69 "c.y"
                          { yyval = yyvsp[0]; }
#line 1566 "y.tab.c"
    break;

  case 6: /* external_declaration: declaration  */
#line 70 "c.y"
                  { yyval = yyvsp[0]; }
#line 1572 "y.tab.c"
    break;

  case 7: /* @1: %empty  */
#line 77 "c.y"
    {
      yyval = YY(setFunctionDeclaratorSpecifier(PTR(A_ID, yyvsp[0]), PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 1580 "y.tab.c"
    break;

  case 8: /* function_definition: declaration_specifiers declarator @1 compound_statement  */
#line 81 "c.y"
    {
      yyval = YY(setFunctionDeclaratorBody(PTR(A_ID, yyvsp[-1]), PTR(A_NODE, yyvsp[0])));
    }
#line 1588 "y.tab.c"
    break;

  case 9: /* @2: %empty  */
#line 85 "c.y"
    {
      yyval = YY(setFunctionDeclaratorSpecifier(PTR(A_ID, yyvsp[0]), makeSpecifier(int_type)));
    }
#line 1596 "y.tab.c"
    break;

  case 10: /* function_definition: declarator @2 compound_statement  */
#line 89 "c.y"
    {
      yyval = YY(setFunctionDeclaratorBody(PTR(A_ID, yyvsp[-1]), PTR(A_NODE, yyvsp[0])));
    }
#line 1604 "y.tab.c"
    break;

  case 11: /* declaration_list_opt: %empty  */
#line 102 "c.y"
    {
      yyval = YY(NULL);
    }
#line 1612 "y.tab.c"
    break;

  case 12: /* declaration_list_opt: declaration_list  */
#line 106 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 1620 "y.tab.c"
    break;

  case 13: /* declaration: declaration_specifiers declarator_list_opt SEMICOLON  */
#line 113 "c.y"
    {
      yyval = YY(setDeclaratorListSpecifier(PTR(A_ID, yyvsp[-1]), PTR(A_SPECIFIER, yyvsp[-2])));
    }
#line 1628 "y.tab.c"
    break;

  case 14: /* declaration_specifiers: type_specifier  */
#line 120 "c.y"
    {
      yyval = YY(makeSpecifier(PTR(A_TYPE, yyvsp[0])));
    }
#line 1636 "y.tab.c"
    break;

  case 15: /* declarator_list_opt: %empty  */
#line 127 "c.y"
    {
      yyval = YY(makeDummyIdentifier());
    }
#line 1644 "y.tab.c"
    break;

  case 16: /* declarator_list_opt: declarator_list  */
#line 131 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 1652 "y.tab.c"
    break;

  case 17: /* declarator_list: declarator  */
#line 138 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 1660 "y.tab.c"
    break;

  case 18: /* declarator_list: declarator_list COMMA declarator  */
#line 142 "c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 1668 "y.tab.c"
    break;

  case 21: /* type_specifier: TYPE_IDENTIFIER  */
#line 151 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 1676 "y.tab.c"
    break;

  case 22: /* @3: %empty  */
#line 160 "c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(setTypeStructOrEnumIdentifier((T_KIND)yyvsp[-1], name, ID_STRUCT));
      free(name);
    
      enterScope();
    }
#line 1688 "y.tab.c"
    break;

  case 23: /* struct_specifier: struct_or_union IDENTIFIER @3 LR struct_declaration_list RR  */
#line 168 "c.y"
    {
      checkForwardReference();
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
      leaveScope();
    }
#line 1698 "y.tab.c"
    break;

  case 24: /* @4: %empty  */
#line 174 "c.y"
    {
      yyval = YY(makeType((T_KIND)yyvsp[0]));
    
      enterScope();
    }
#line 1708 "y.tab.c"
    break;

  case 25: /* struct_specifier: struct_or_union @4 LR struct_declaration_list RR  */
#line 180 "c.y"
    {
      checkForwardReference();
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
      leaveScope();
    }
#line 1718 "y.tab.c"
    break;

  case 26: /* struct_specifier: struct_or_union IDENTIFIER  */
#line 186 "c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(getTypeOfStructOrEnumIdentifier((T_KIND)yyvsp[-1], name, ID_STRUCT));
      free(name);
    }
#line 1728 "y.tab.c"
    break;

  case 27: /* struct_or_union: STRUCT_SYM  */
#line 194 "c.y"
                 { yyval = YY(T_STRUCT); }
#line 1734 "y.tab.c"
    break;

  case 28: /* struct_or_union: UNION_SYM  */
#line 195 "c.y"
                { yyval = YY(T_UNION); }
#line 1740 "y.tab.c"
    break;

  case 29: /* struct_declaration_list: struct_declaration  */
#line 199 "c.y"
                         { yyval = yyvsp[0]; }
#line 1746 "y.tab.c"
    break;

  case 30: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 201 "c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-1]), PTR(A_ID, yyvsp[0])));
    }
#line 1754 "y.tab.c"
    break;

  case 31: /* struct_declaration: type_specifier struct_declarator_list SEMICOLON  */
#line 208 "c.y"
    {
      yyval = YY(setStructDeclaratorListSpecifier(PTR(A_ID, yyvsp[-1]), PTR(A_TYPE, yyvsp[-2])));
    }
#line 1762 "y.tab.c"
    break;

  case 32: /* struct_declarator_list: struct_declarator  */
#line 214 "c.y"
                        { yyval = yyvsp[0]; }
#line 1768 "y.tab.c"
    break;

  case 33: /* struct_declarator_list: struct_declarator_list COMMA struct_declarator  */
#line 216 "c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 1776 "y.tab.c"
    break;

  case 34: /* struct_declarator: declarator  */
#line 222 "c.y"
                 { yyval = yyvsp[0]; }
#line 1782 "y.tab.c"
    break;

  case 35: /* @5: %empty  */
#line 229 "c.y"
    {
      yyval = YY(setTypeStructOrEnumIdentifier(T_ENUM, PTR(char, yyvsp[0]), ID_ENUM));
    }
#line 1790 "y.tab.c"
    break;

  case 36: /* enum_specifier: ENUM_SYM IDENTIFIER @5 LR enumerator_list RR  */
#line 233 "c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 1798 "y.tab.c"
    break;

  case 37: /* @6: %empty  */
#line 237 "c.y"
    {
      yyval = YY(makeType(T_ENUM));
    }
#line 1806 "y.tab.c"
    break;

  case 38: /* enum_specifier: ENUM_SYM @6 LR enumerator_list RR  */
#line 241 "c.y"
    {
      yyval = YY(setTypeField(PTR(A_TYPE, yyvsp[-3]), PTR(A_ID, yyvsp[-1])));
    }
#line 1814 "y.tab.c"
    break;

  case 39: /* enum_specifier: ENUM_SYM IDENTIFIER  */
#line 245 "c.y"
    {
      yyval = YY(getTypeOfStructOrEnumIdentifier(T_ENUM, PTR(char, yyvsp[0]), ID_ENUM));
    }
#line 1822 "y.tab.c"
    break;

  case 40: /* enumerator_list: enumerator  */
#line 251 "c.y"
                 { yyval = yyvsp[0]; }
#line 1828 "y.tab.c"
    break;

  case 41: /* enumerator_list: enumerator_list COMMA enumerator  */
#line 253 "c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 1836 "y.tab.c"
    break;

  case 42: /* enumerator: IDENTIFIER  */
#line 260 "c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      A_ID *id = makeIdentifier(name);
      free(name);
    
      yyval = YY(setDeclaratorKind(id, ID_ENUM_LITERAL));
    }
#line 1848 "y.tab.c"
    break;

  case 43: /* declarator: pointer direct_declarator  */
#line 277 "c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[0]), PTR(A_TYPE, yyvsp[-1])));
    }
#line 1856 "y.tab.c"
    break;

  case 44: /* declarator: direct_declarator  */
#line 281 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 1864 "y.tab.c"
    break;

  case 45: /* pointer: STAR  */
#line 288 "c.y"
    {
      yyval = YY(makeType(T_POINTER));
    }
#line 1872 "y.tab.c"
    break;

  case 46: /* pointer: STAR pointer  */
#line 292 "c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[0]), makeType(T_POINTER)));
    }
#line 1880 "y.tab.c"
    break;

  case 47: /* direct_declarator: IDENTIFIER  */
#line 301 "c.y"
    {
      char *name = PTR(char, yyvsp[0]);
    
      A_ID *id = makeIdentifier(name);
      free(name);
    
      yyval = YY(id);
    }
#line 1893 "y.tab.c"
    break;

  case 48: /* direct_declarator: LP declarator RP  */
#line 310 "c.y"
    {
      yyval = yyvsp[-1];
    }
#line 1901 "y.tab.c"
    break;

  case 49: /* direct_declarator: direct_declarator LB constant_expression_opt RB  */
#line 314 "c.y"
    {
      yyval = YY(setDeclaratorElementType(PTR(A_ID, yyvsp[-3]),
                                       setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1]))));
    }
#line 1910 "y.tab.c"
    break;

  case 50: /* $@7: %empty  */
#line 319 "c.y"
    {
      enterScope();
    }
#line 1918 "y.tab.c"
    break;

  case 51: /* direct_declarator: direct_declarator LP $@7 parameter_type_list_opt RP  */
#line 323 "c.y"
    {
      A_ID *params = PTR(A_ID, yyvsp[-1]);
    
      yyval = YY(
          setDeclaratorElementType(PTR(A_ID, yyvsp[-4]), setTypeField(makeType(T_FUNC), params)));
    
      checkForwardReference();
      leaveScope();
    }
#line 1932 "y.tab.c"
    break;

  case 52: /* constant_expression_opt: %empty  */
#line 336 "c.y"
    {
      yyval = YY(NULL);
    }
#line 1940 "y.tab.c"
    break;

  case 53: /* constant_expression_opt: constant_expression  */
#line 340 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 1948 "y.tab.c"
    break;

  case 54: /* parameter_type_list_opt: %empty  */
#line 349 "c.y"
    {
      yyval = YY(NULL);
    }
#line 1956 "y.tab.c"
    break;

  case 55: /* parameter_type_list_opt: parameter_type_list  */
#line 353 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 1964 "y.tab.c"
    break;

  case 57: /* parameter_type_list: parameter_list COMMA DOTDOTDOT  */
#line 361 "c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]),
                                 setDeclaratorKind(makeDummyIdentifier(), ID_PARM)));
    }
#line 1973 "y.tab.c"
    break;

  case 58: /* parameter_list: parameter_declaration  */
#line 369 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 1981 "y.tab.c"
    break;

  case 59: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 373 "c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-2]), PTR(A_ID, yyvsp[0])));
    }
#line 1989 "y.tab.c"
    break;

  case 60: /* parameter_declaration: declaration_specifiers declarator  */
#line 380 "c.y"
    {
      yyval = YY(setParameterDeclaratorSpecifier(PTR(A_ID, yyvsp[0]), PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 1997 "y.tab.c"
    break;

  case 61: /* parameter_declaration: declaration_specifiers abstract_declarator_opt  */
#line 384 "c.y"
    {
      A_ID *id = makeDummyIdentifier();
    
      setDeclaratorElementType(id, PTR(A_TYPE, yyvsp[0]));
    
      yyval = YY(setParameterDeclaratorSpecifier(id, PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2009 "y.tab.c"
    break;

  case 62: /* abstract_declarator_opt: %empty  */
#line 395 "c.y"
    {
      yyval = YY(NULL);
    }
#line 2017 "y.tab.c"
    break;

  case 63: /* abstract_declarator_opt: abstract_declarator  */
#line 399 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2025 "y.tab.c"
    break;

  case 64: /* abstract_declarator: pointer  */
#line 406 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2033 "y.tab.c"
    break;

  case 65: /* abstract_declarator: direct_abstract_declarator  */
#line 410 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2041 "y.tab.c"
    break;

  case 66: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 414 "c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[0]), PTR(A_TYPE, yyvsp[-1])));
    }
#line 2049 "y.tab.c"
    break;

  case 67: /* direct_abstract_declarator: LP abstract_declarator RP  */
#line 421 "c.y"
    {
      yyval = yyvsp[-1];
    }
#line 2057 "y.tab.c"
    break;

  case 68: /* direct_abstract_declarator: LB constant_expression_opt RB  */
#line 425 "c.y"
    {
      yyval = YY(setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1])));
    }
#line 2065 "y.tab.c"
    break;

  case 69: /* direct_abstract_declarator: LP parameter_type_list_opt RP  */
#line 429 "c.y"
    {
      yyval = YY(setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1])));
    }
#line 2073 "y.tab.c"
    break;

  case 70: /* direct_abstract_declarator: direct_abstract_declarator LB constant_expression_opt RB  */
#line 433 "c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[-3]),
                                 setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, yyvsp[-1]))));
    }
#line 2082 "y.tab.c"
    break;

  case 71: /* direct_abstract_declarator: direct_abstract_declarator LP parameter_type_list_opt RP  */
#line 438 "c.y"
    {
      yyval = YY(setTypeElementType(PTR(A_TYPE, yyvsp[-3]),
                                 setTypeField(makeType(T_FUNC), PTR(A_ID, yyvsp[-1]))));
    }
#line 2091 "y.tab.c"
    break;

  case 72: /* statement: labeled_statement  */
#line 451 "c.y"
                        { yyval = yyvsp[0]; }
#line 2097 "y.tab.c"
    break;

  case 73: /* statement: compound_statement  */
#line 453 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2105 "y.tab.c"
    break;

  case 74: /* statement: expression_statement  */
#line 457 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2113 "y.tab.c"
    break;

  case 75: /* statement: selection_statement  */
#line 460 "c.y"
                          { yyval = yyvsp[0]; }
#line 2119 "y.tab.c"
    break;

  case 76: /* statement: iteration_statement  */
#line 461 "c.y"
                          { yyval = yyvsp[0]; }
#line 2125 "y.tab.c"
    break;

  case 77: /* statement: jump_statement  */
#line 463 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2133 "y.tab.c"
    break;

  case 78: /* labeled_statement: CASE_SYM constant_expression COLON statement  */
#line 470 "c.y"
    {
      yyval = YY(makeNode(N_STMT_LABEL_CASE, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2141 "y.tab.c"
    break;

  case 79: /* labeled_statement: DEFAULT_SYM COLON statement  */
#line 474 "c.y"
    {
      yyval = YY(makeNode(N_STMT_LABEL_DEFAULT, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2149 "y.tab.c"
    break;

  case 80: /* $@8: %empty  */
#line 483 "c.y"
    {
      enterScope();
    }
#line 2157 "y.tab.c"
    break;

  case 81: /* compound_statement: LR $@8 declaration_list_opt statement_list_opt RR  */
#line 487 "c.y"
    {
      yyval = YY(makeNode(N_STMT_COMPOUND, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[-1])));
    
      checkForwardReference();
      leaveScope();
    }
#line 2168 "y.tab.c"
    break;

  case 82: /* declaration_list: declaration  */
#line 497 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2176 "y.tab.c"
    break;

  case 83: /* declaration_list: declaration_list declaration  */
#line 501 "c.y"
    {
      yyval = YY(linkDeclaratorList(PTR(A_ID, yyvsp[-1]), PTR(A_ID, yyvsp[0])));
    }
#line 2184 "y.tab.c"
    break;

  case 84: /* statement_list_opt: %empty  */
#line 508 "c.y"
    {
      yyval = YY(makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL));
    }
#line 2192 "y.tab.c"
    break;

  case 85: /* statement_list_opt: statement_list  */
#line 512 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2200 "y.tab.c"
    break;

  case 86: /* statement_list: statement  */
#line 519 "c.y"
    {
      yyval = YY(makeNode(N_STMT_LIST, PTR(A_NODE, yyvsp[0]), NULL,
                       makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL)));
    }
#line 2209 "y.tab.c"
    break;

  case 87: /* statement_list: statement_list statement  */
#line 524 "c.y"
    {
      yyval = YY(makeNodeList(N_STMT_LIST, PTR(A_NODE, yyvsp[-1]), PTR(A_NODE, yyvsp[0])));
    }
#line 2217 "y.tab.c"
    break;

  case 88: /* expression_statement: SEMICOLON  */
#line 533 "c.y"
    {
      yyval = YY(makeNode(N_STMT_EMPTY, NULL, NULL, NULL));
    }
#line 2225 "y.tab.c"
    break;

  case 89: /* expression_statement: expression SEMICOLON  */
#line 537 "c.y"
    {
      yyval = YY(makeNode(N_STMT_EXPRESSION, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2233 "y.tab.c"
    break;

  case 90: /* selection_statement: IF_SYM LP expression RP statement  */
#line 546 "c.y"
    {
      yyval = YY(makeNode(N_STMT_IF, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2241 "y.tab.c"
    break;

  case 91: /* selection_statement: IF_SYM LP expression RP statement ELSE_SYM statement  */
#line 550 "c.y"
    {
      yyval = YY(makeNode(N_STMT_IF_ELSE, PTR(A_NODE, yyvsp[-4]), PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2249 "y.tab.c"
    break;

  case 92: /* selection_statement: SWITCH_SYM LP expression RP statement  */
#line 554 "c.y"
    {
      yyval = YY(makeNode(N_STMT_SWITCH, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2257 "y.tab.c"
    break;

  case 93: /* iteration_statement: WHILE_SYM LP expression RP statement  */
#line 563 "c.y"
    {
      yyval = YY(makeNode(N_STMT_WHILE, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2265 "y.tab.c"
    break;

  case 94: /* iteration_statement: DO_SYM statement WHILE_SYM LP expression RP SEMICOLON  */
#line 567 "c.y"
    {
      yyval = YY(makeNode(N_STMT_DO, PTR(A_NODE, yyvsp[-5]), NULL, PTR(A_NODE, yyvsp[-2])));
    }
#line 2273 "y.tab.c"
    break;

  case 95: /* iteration_statement: FOR_SYM LP for_expression RP statement  */
#line 571 "c.y"
    {
      yyval = YY(makeNode(N_STMT_FOR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2281 "y.tab.c"
    break;

  case 96: /* expression_opt: %empty  */
#line 578 "c.y"
    {
      yyval = YY(NULL);
    }
#line 2289 "y.tab.c"
    break;

  case 97: /* expression_opt: expression  */
#line 582 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2297 "y.tab.c"
    break;

  case 98: /* for_expression: expression_opt SEMICOLON expression_opt SEMICOLON expression_opt  */
#line 589 "c.y"
    {
      yyval = YY(makeNode(N_FOR_EXP, PTR(A_NODE, yyvsp[-4]), PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2305 "y.tab.c"
    break;

  case 99: /* jump_statement: RETURN_SYM expression_opt SEMICOLON  */
#line 598 "c.y"
    {
      yyval = YY(makeNode(N_STMT_RETURN, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    
    }
#line 2314 "y.tab.c"
    break;

  case 100: /* jump_statement: CONTINUE_SYM SEMICOLON  */
#line 603 "c.y"
    {
      yyval = YY(makeNode(N_STMT_CONTINUE, NULL, NULL, NULL));
    }
#line 2322 "y.tab.c"
    break;

  case 101: /* jump_statement: BREAK_SYM SEMICOLON  */
#line 607 "c.y"
    {
      yyval = YY(makeNode(N_STMT_BREAK, NULL, NULL, NULL));
    }
#line 2330 "y.tab.c"
    break;

  case 102: /* primary_expression: IDENTIFIER  */
#line 620 "c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      A_ID *id = getIdentifierDeclared(name);
      free(name);
    
      yyval = YY(makeNode(N_EXP_IDENT, NULL, PTR(A_NODE, id), NULL));
    }
#line 2342 "y.tab.c"
    break;

  case 103: /* primary_expression: INTEGER_CONSTANT  */
#line 628 "c.y"
    {
      yyval = YY(makeNode(N_EXP_INT_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2350 "y.tab.c"
    break;

  case 104: /* primary_expression: FLOAT_CONSTANT  */
#line 632 "c.y"
    {
      yyval = YY(makeNode(N_EXP_FLOAT_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2358 "y.tab.c"
    break;

  case 105: /* primary_expression: CHARACTER_CONSTANT  */
#line 636 "c.y"
    {
      yyval = YY(makeNode(N_EXP_CHAR_CONST, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2366 "y.tab.c"
    break;

  case 106: /* primary_expression: STRING_LITERAL  */
#line 640 "c.y"
    {
      yyval = YY(makeNode(N_EXP_STRING_LITERAL, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2374 "y.tab.c"
    break;

  case 107: /* primary_expression: LP expression RP  */
#line 644 "c.y"
    {
      yyval = yyvsp[-1];
    }
#line 2382 "y.tab.c"
    break;

  case 108: /* postfix_expression: primary_expression  */
#line 651 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2390 "y.tab.c"
    break;

  case 109: /* postfix_expression: postfix_expression LB expression RB  */
#line 655 "c.y"
    {
      yyval = YY(makeNode(N_EXP_ARRAY, PTR(A_NODE, yyvsp[-3]), NULL, PTR(A_NODE, yyvsp[-1])));
    }
#line 2398 "y.tab.c"
    break;

  case 110: /* postfix_expression: postfix_expression LP arg_expression_list_opt RP  */
#line 659 "c.y"
    {
      yyval = YY(makeNode(N_EXP_FUNCTION_CALL, PTR(A_NODE, yyvsp[-3]), NULL, PTR(A_NODE, yyvsp[-1])));
    }
#line 2406 "y.tab.c"
    break;

  case 111: /* postfix_expression: postfix_expression PERIOD IDENTIFIER  */
#line 663 "c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(makeNode(N_EXP_STRUCT, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, name)));
    }
#line 2415 "y.tab.c"
    break;

  case 112: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 668 "c.y"
    {
      char *name = PTR(char, yyvsp[0]);
      yyval = YY(makeNode(N_EXP_ARROW, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, name)));
    }
#line 2424 "y.tab.c"
    break;

  case 113: /* postfix_expression: postfix_expression PLUSPLUS  */
#line 673 "c.y"
    {
      yyval = YY(makeNode(N_EXP_POST_INC, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2432 "y.tab.c"
    break;

  case 114: /* postfix_expression: postfix_expression MINUSMINUS  */
#line 677 "c.y"
    {
      yyval = YY(makeNode(N_EXP_POST_DEC, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2440 "y.tab.c"
    break;

  case 115: /* arg_expression_list_opt: %empty  */
#line 684 "c.y"
    {
      yyval = YY(makeNode(N_ARG_LIST_NIL, NULL, NULL, NULL));
    }
#line 2448 "y.tab.c"
    break;

  case 116: /* arg_expression_list_opt: arg_expression_list  */
#line 687 "c.y"
                          { yyval = yyvsp[0]; }
#line 2454 "y.tab.c"
    break;

  case 117: /* arg_expression_list: assignment_expression  */
#line 692 "c.y"
    {
      yyval = YY(makeNode(N_ARG_LIST, PTR(A_NODE, yyvsp[0]), NULL,
                       makeNode(N_ARG_LIST_NIL, NULL, NULL, NULL)));
    }
#line 2463 "y.tab.c"
    break;

  case 118: /* arg_expression_list: arg_expression_list COMMA assignment_expression  */
#line 697 "c.y"
    {
      yyval = YY(makeNodeList(N_ARG_LIST, PTR(A_NODE, yyvsp[-2]), PTR(A_NODE, yyvsp[0])));
    }
#line 2471 "y.tab.c"
    break;

  case 119: /* unary_expression: postfix_expression  */
#line 706 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2479 "y.tab.c"
    break;

  case 120: /* unary_expression: PLUSPLUS unary_expression  */
#line 710 "c.y"
    {
      yyval = YY(makeNode(N_EXP_PRE_INC, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2487 "y.tab.c"
    break;

  case 121: /* unary_expression: MINUSMINUS unary_expression  */
#line 714 "c.y"
    {
      yyval = YY(makeNode(N_EXP_PRE_DEC, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2495 "y.tab.c"
    break;

  case 122: /* unary_expression: AMP cast_expression  */
#line 718 "c.y"
    {
      yyval = YY(makeNode(N_EXP_AMP, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2503 "y.tab.c"
    break;

  case 123: /* unary_expression: STAR cast_expression  */
#line 722 "c.y"
    {
      yyval = YY(makeNode(N_EXP_STAR, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2511 "y.tab.c"
    break;

  case 124: /* unary_expression: EXCL cast_expression  */
#line 726 "c.y"
    {
      yyval = YY(makeNode(N_EXP_NOT, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2519 "y.tab.c"
    break;

  case 125: /* unary_expression: MINUS cast_expression  */
#line 730 "c.y"
    {
      yyval = YY(makeNode(N_EXP_MINUS, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2527 "y.tab.c"
    break;

  case 126: /* unary_expression: PLUS cast_expression  */
#line 734 "c.y"
    {
      yyval = YY(makeNode(N_EXP_PLUS, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2535 "y.tab.c"
    break;

  case 127: /* unary_expression: SIZEOF_SYM unary_expression  */
#line 738 "c.y"
    {
      yyval = YY(makeNode(N_EXP_SIZE_EXP, NULL, PTR(A_NODE, yyvsp[0]), NULL));
    }
#line 2543 "y.tab.c"
    break;

  case 128: /* unary_expression: SIZEOF_SYM LP type_name RP  */
#line 742 "c.y"
    {
      yyval = YY(makeNode(N_EXP_SIZE_TYPE, NULL, PTR(A_NODE, yyvsp[-1]), NULL));
    }
#line 2551 "y.tab.c"
    break;

  case 129: /* cast_expression: unary_expression  */
#line 749 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2559 "y.tab.c"
    break;

  case 130: /* cast_expression: LP type_name RP cast_expression  */
#line 753 "c.y"
    {
      yyval = YY(makeNode(N_EXP_CAST, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2567 "y.tab.c"
    break;

  case 131: /* type_name: declaration_specifiers abstract_declarator_opt  */
#line 760 "c.y"
    {
      yyval = YY(setTypeNameSpecifier(PTR(A_TYPE, yyvsp[0]), PTR(A_SPECIFIER, yyvsp[-1])));
    }
#line 2575 "y.tab.c"
    break;

  case 132: /* multiplicative_expression: cast_expression  */
#line 769 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2583 "y.tab.c"
    break;

  case 133: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 773 "c.y"
    {
      yyval = YY(makeNode(N_EXP_MUL, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2591 "y.tab.c"
    break;

  case 134: /* multiplicative_expression: multiplicative_expression SLASH cast_expression  */
#line 777 "c.y"
    {
      yyval = YY(makeNode(N_EXP_DIV, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2599 "y.tab.c"
    break;

  case 135: /* multiplicative_expression: multiplicative_expression PERCENT cast_expression  */
#line 781 "c.y"
    {
      yyval = YY(makeNode(N_EXP_MOD, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2607 "y.tab.c"
    break;

  case 136: /* additive_expression: multiplicative_expression  */
#line 788 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2615 "y.tab.c"
    break;

  case 137: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 792 "c.y"
    {
      yyval = YY(makeNode(N_EXP_ADD, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2623 "y.tab.c"
    break;

  case 138: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 796 "c.y"
    {
      yyval = YY(makeNode(N_EXP_SUB, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2631 "y.tab.c"
    break;

  case 139: /* shift_expression: additive_expression  */
#line 802 "c.y"
                          { yyval = yyvsp[0]; }
#line 2637 "y.tab.c"
    break;

  case 140: /* relational_expression: shift_expression  */
#line 809 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2645 "y.tab.c"
    break;

  case 141: /* relational_expression: relational_expression LSS shift_expression  */
#line 813 "c.y"
    {
      yyval = YY(makeNode(N_EXP_LSS, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2653 "y.tab.c"
    break;

  case 142: /* relational_expression: relational_expression GTR shift_expression  */
#line 817 "c.y"
    {
      yyval = YY(makeNode(N_EXP_GTR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2661 "y.tab.c"
    break;

  case 143: /* relational_expression: relational_expression LEQ shift_expression  */
#line 821 "c.y"
    {
      yyval = YY(makeNode(N_EXP_LEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2669 "y.tab.c"
    break;

  case 144: /* relational_expression: relational_expression GEQ shift_expression  */
#line 825 "c.y"
    {
      yyval = YY(makeNode(N_EXP_GEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2677 "y.tab.c"
    break;

  case 145: /* equality_expression: relational_expression  */
#line 832 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2685 "y.tab.c"
    break;

  case 146: /* equality_expression: equality_expression EQL relational_expression  */
#line 836 "c.y"
    {
      yyval = YY(makeNode(N_EXP_EQL, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2693 "y.tab.c"
    break;

  case 147: /* equality_expression: equality_expression NEQ relational_expression  */
#line 840 "c.y"
    {
      yyval = YY(makeNode(N_EXP_NEQ, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2701 "y.tab.c"
    break;

  case 148: /* AND_expression: equality_expression  */
#line 848 "c.y"
                          { yyval = yyvsp[0]; }
#line 2707 "y.tab.c"
    break;

  case 149: /* exclusive_OR_expression: AND_expression  */
#line 852 "c.y"
                     { yyval = yyvsp[0]; }
#line 2713 "y.tab.c"
    break;

  case 150: /* inclusive_OR_expression: exclusive_OR_expression  */
#line 856 "c.y"
                              { yyval = yyvsp[0]; }
#line 2719 "y.tab.c"
    break;

  case 151: /* logical_AND_expression: inclusive_OR_expression  */
#line 860 "c.y"
                              { yyval = yyvsp[0]; }
#line 2725 "y.tab.c"
    break;

  case 152: /* logical_AND_expression: logical_AND_expression AMPAMP inclusive_OR_expression  */
#line 862 "c.y"
    {
      yyval = YY(makeNode(N_EXP_AND, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2733 "y.tab.c"
    break;

  case 153: /* logical_OR_expression: logical_AND_expression  */
#line 868 "c.y"
                             { yyval = yyvsp[0]; }
#line 2739 "y.tab.c"
    break;

  case 154: /* logical_OR_expression: logical_OR_expression BARBAR logical_AND_expression  */
#line 870 "c.y"
    {
      yyval = YY(makeNode(N_EXP_OR, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2747 "y.tab.c"
    break;

  case 155: /* conditional_expression: logical_OR_expression  */
#line 879 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2755 "y.tab.c"
    break;

  case 156: /* assignment_expression: conditional_expression  */
#line 886 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2763 "y.tab.c"
    break;

  case 157: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 890 "c.y"
    {
      yyval = YY(makeNode(N_EXP_ASSIGN, PTR(A_NODE, yyvsp[-2]), NULL, PTR(A_NODE, yyvsp[0])));
    }
#line 2771 "y.tab.c"
    break;

  case 158: /* comma_expression: assignment_expression  */
#line 897 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2779 "y.tab.c"
    break;

  case 159: /* expression: comma_expression  */
#line 906 "c.y"
    {
      yyval = yyvsp[0];
    }
#line 2787 "y.tab.c"
    break;


#line 2791 "y.tab.c"

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

#line 914 "c.y"

/* ============================================================
 * 7. 보조 C 함수
 * ============================================================ */

int yyerror(const char *s) {
  syntax_err++;
  if (!compiler_error_tags_enabled()) {
    printf("line %d: %s near %s \n", line_no, s, yytext);
  } else if (yytext == NULL || yytext[0] == '\0') {
    report_compiler_error(SYNTAX_ERROR, 0, line_no, "%s at end", s);
  } else {
    report_compiler_error(SYNTAX_ERROR, 0, line_no, "%s near '%s'", s, yytext);
  }
  return 0;
}
