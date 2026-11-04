%{
#include "parse_value.h"
#include <stdio.h>
#include <stdlib.h>

#include "type.h"
#include "logger.h"
#include "semantic.h"

int yylex(void);
int yyerror(const char *s);
extern int line_no;

A_NODE* makeNode(
  NODE_NAME name,
  A_NODE* left,
  A_NODE* center,
  A_NODE* right
);

static void checkBinaryNode(A_NODE* node){
  if(node == NULL || node->llink == NULL || node->rlink == NULL)
  semanticError("Invalid binary AST Node");

if(node->name != N_EXP_ADD && node->name != N_EXP_SUB)
  semanticError("Unexpected binary operator");

if(node->llink->name != N_EXP_INT_CONST || node->rlink->name != N_EXP_INT_CONST)
  semanticError("Expected interger operands");

    logMsg(
        LOG_DEBUG,
        "%s: %lld, %lld",
        node->name == N_EXP_ADD ? "ADD" : "SUB",
        (long long)(intptr_t)node->llink->clink,
        (long long)(intptr_t)node->rlink->clink
    );
}

static void checkPrecedence(A_NODE *node)
{
    if (node == NULL || node->name != N_EXP_ADD)
        semanticError("Expected N_EXP_ADD");

    A_NODE *left = node->llink;
    A_NODE *right = node->rlink;

    if (left == NULL || right == NULL)
        semanticError("Missing AST operand");

    if (left->name != N_EXP_INT_CONST ||
        right->name != N_EXP_MUL)
        semanticError("Incorrect operator precedence");

    A_NODE *mul_left = right->llink;
    A_NODE *mul_right = right->rlink;

    if (mul_left == NULL || mul_right == NULL ||
        mul_left->name != N_EXP_INT_CONST ||
        mul_right->name != N_EXP_INT_CONST)
        semanticError("Invalid multiplication operands");

    if ((intptr_t)left->clink != 1 ||
        (intptr_t)mul_left->clink != 2 ||
        (intptr_t)mul_right->clink != 3)
        semanticError("Unexpected integer values");

    logMsg(LOG_INFO, "AST precedence test passed");
}
%}

%token IDENTIFIER TYPE_IDENTIFIER
%token INTEGER_CONSTANT FLOAT_CONSTANT CHARACTER_CONSTANT STRING_LITERAL

%token AUTO_SYM BREAK_SYM CASE_SYM CONTINUE_SYM DEFAULT_SYM DO_SYM
%token ELSE_SYM ENUM_SYM FOR_SYM GOTO_SYM IF_SYM RETURN_SYM SIZEOF_SYM
%token STATIC_SYM STRUCT_SYM SWITCH_SYM TYPEDEF_SYM UNION_SYM WHILE_SYM
%token REGISTER_SYM EXTERN_SYM CONST_SYM VOLATILE_SYM

%token PLUSPLUS MINUSMINUS ARROW
%token LSS GTR LEQ GEQ EQL NEQ
%token AMPAMP BARBAR
%token LSHIFT RSHIFT
%token DOTDOTDOT
%token LP RP LB RB LR RR
%token COLON PERIOD COMMA EXCL TILDE
%token STAR SLASH PERCENT AMP BAR CARET
%token SEMICOLON PLUS MINUS ASSIGN QUESTION

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE_SYM

%start program

%%

program
    : translation_unit
    ;

translation_unit
    : external_declaration
    | translation_unit external_declaration
    ;

external_declaration
    : function_definition
    | declaration
    ;

function_definition
    : declaration_specifiers declarator declaration_list_opt compound_statement
    | declarator declaration_list_opt compound_statement
    ;

declaration_list_opt
    :
    | declaration_list
    ;

declaration
    : declaration_specifiers init_declarator_list SEMICOLON
    ;

declaration_specifiers
    : type_specifier
    | storage_class_specifier
    | type_qualifier
    | type_specifier declaration_specifiers
    | storage_class_specifier declaration_specifiers
    | type_qualifier declaration_specifiers
    ;

storage_class_specifier
    : AUTO_SYM
    | STATIC_SYM
    | TYPEDEF_SYM
    | REGISTER_SYM
    | EXTERN_SYM
    ;

type_qualifier
    : CONST_SYM
    | VOLATILE_SYM
    ;

init_declarator_list
    : init_declarator
    | init_declarator_list COMMA init_declarator
    ;

init_declarator
    : declarator
    | declarator ASSIGN initializer
    ;

type_specifier
    : struct_specifier
    | enum_specifier
    | TYPE_IDENTIFIER
    ;

struct_specifier
    : struct_or_union IDENTIFIER LR struct_declaration_list RR
    | struct_or_union LR struct_declaration_list RR
    | struct_or_union IDENTIFIER
    ;

struct_or_union
    : STRUCT_SYM
    | UNION_SYM
    ;

struct_declaration_list
    : struct_declaration
    | struct_declaration_list struct_declaration
    ;

struct_declaration
    : specifier_qualifier_list struct_declarator_list SEMICOLON
    ;

specifier_qualifier_list
    : type_specifier
    | type_qualifier
    | type_specifier specifier_qualifier_list
    | type_qualifier specifier_qualifier_list
    ;

struct_declarator_list
    : struct_declarator
    | struct_declarator_list COMMA struct_declarator
    ;

struct_declarator
    : declarator
    | COLON constant_expression
    | declarator COLON constant_expression
    ;

enum_specifier
    : ENUM_SYM IDENTIFIER LR enumerator_list RR
    | ENUM_SYM LR enumerator_list RR
    | ENUM_SYM IDENTIFIER
    ;

enumerator_list
    : enumerator
    | enumerator_list COMMA enumerator
    ;

enumerator
    : IDENTIFIER
    | IDENTIFIER ASSIGN constant_expression
    ;

declarator
    : pointer direct_declarator
    | direct_declarator
    ;

pointer
    : STAR type_qualifier_list_opt
    | STAR type_qualifier_list_opt pointer
    ;

type_qualifier_list_opt
    :
    | type_qualifier_list
    ;

type_qualifier_list
    : type_qualifier
    | type_qualifier_list type_qualifier
    ;

direct_declarator
    : IDENTIFIER
    | LP declarator RP
    | direct_declarator LB constant_expression_opt RB
    | direct_declarator LP parameter_type_list_opt RP
    ;

constant_expression_opt
    :
    | constant_expression
    ;

parameter_type_list_opt
    :
    | parameter_type_list
    ;

parameter_type_list
    : parameter_list
    | parameter_list COMMA DOTDOTDOT
    ;

parameter_list
    : parameter_declaration
    | parameter_list COMMA parameter_declaration
    ;

parameter_declaration
    : declaration_specifiers declarator
    | declaration_specifiers abstract_declarator_opt
    ;

abstract_declarator_opt
    :
    | abstract_declarator
    ;

abstract_declarator
    : pointer
    | direct_abstract_declarator
    | pointer direct_abstract_declarator
    ;

direct_abstract_declarator
    : LP abstract_declarator RP
    | LB constant_expression_opt RB
    | LP parameter_type_list_opt RP
    | direct_abstract_declarator LB constant_expression_opt RB
    | direct_abstract_declarator LP parameter_type_list_opt RP
    ;

initializer
    : assignment_expression
    | LR initializer_list RR
    | LR initializer_list COMMA RR
    ;

initializer_list
    : initializer
    | initializer_list COMMA initializer
    ;

statement
    : labeled_statement
    | compound_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    ;

labeled_statement
    : CASE_SYM constant_expression COLON statement
    | DEFAULT_SYM COLON statement
    | IDENTIFIER COLON statement
    ;

compound_statement
    : LR declaration_list_opt statement_list RR
    ;

declaration_list
    : declaration
    | declaration_list declaration
    ;

statement_list
    :
    | statement_list statement
    ;

expression_statement
    : SEMICOLON
    | expression SEMICOLON
    ;

selection_statement
    : IF_SYM LP expression RP statement %prec LOWER_THAN_ELSE
    | IF_SYM LP expression RP statement ELSE_SYM statement
    | SWITCH_SYM LP expression RP statement
    ;

iteration_statement
    : WHILE_SYM LP expression RP statement
    | DO_SYM statement WHILE_SYM LP expression RP SEMICOLON
    | FOR_SYM LP expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RP statement
    ;

expression_opt
    :
    | expression
    ;

jump_statement
    : RETURN_SYM expression_opt SEMICOLON
    | CONTINUE_SYM SEMICOLON
    | BREAK_SYM SEMICOLON
    | GOTO_SYM IDENTIFIER SEMICOLON
    ;

primary_expression
    : IDENTIFIER
    | INTEGER_CONSTANT {
      $$ =(YYSTYPE)makeNode(N_EXP_INT_CONST, NULL, (A_NODE*)$1, NULL);
      
      A_NODE *node = (A_NODE*)$$;
      logMsg(LOG_DEBUG, "N_EXP_INT_CONST: %lld",
             (long long)(intptr_t)node->clink);
    }
    | FLOAT_CONSTANT
    | CHARACTER_CONSTANT
    | STRING_LITERAL
    | LP expression RP
    ;

postfix_expression
    : primary_expression { $$ = $1;}
    | postfix_expression LB expression RB
    | postfix_expression LP arg_expression_list_opt RP
    | postfix_expression PERIOD IDENTIFIER
    | postfix_expression ARROW IDENTIFIER
    | postfix_expression PLUSPLUS
    | postfix_expression MINUSMINUS
    ;

arg_expression_list_opt
    :
    | arg_expression_list
    ;

arg_expression_list
    : assignment_expression
    | arg_expression_list COMMA assignment_expression
    ;

unary_expression
    : postfix_expression {$$ = $1;}
    | PLUSPLUS unary_expression
    | MINUSMINUS unary_expression
    | AMP cast_expression
    | STAR cast_expression
    | EXCL cast_expression
    | MINUS cast_expression
    | TILDE cast_expression
    | PLUS cast_expression
    | SIZEOF_SYM unary_expression
    | SIZEOF_SYM LP type_name RP
    ;

cast_expression
    : unary_expression { $$=$1;}
    | LP type_name RP cast_expression
    ;

type_name
    : declaration_specifiers
    | declaration_specifiers abstract_declarator
    ;

multiplicative_expression
    : cast_expression {$$=$1;}
    | multiplicative_expression STAR cast_expression
    {
      $$ = (YYSTYPE) makeNode(
        N_EXP_MUL,
        (A_NODE*) $1,
        NULL,
        (A_NODE*) $3
      );
    }
    | multiplicative_expression SLASH cast_expression
    {
$$ = (YYSTYPE) makeNode(
        N_EXP_DIV,
        (A_NODE*) $1,
        NULL,
        (A_NODE*) $3
      );

    }
    | multiplicative_expression PERCENT cast_expression
    {
$$ = (YYSTYPE) makeNode(
        N_EXP_MOD,
        (A_NODE*) $1,
        NULL,
        (A_NODE*) $3
      );

    }
    ;

additive_expression
    : multiplicative_expression {$$ =$1;}
    | additive_expression PLUS multiplicative_expression
    {
      $$ = (YYSTYPE) makeNode(
        N_EXP_ADD, (A_NODE*) $1, NULL, (A_NODE*)$3);

      if(getenv("AST_TEST_PRECEDENCE") != NULL)
        checkPrecedence((A_NODE*) $$);
    }
    | additive_expression MINUS multiplicative_expression
    {
      $$ = (YYSTYPE) makeNode(
        N_EXP_SUB, (A_NODE*) $1, NULL, (A_NODE*)$3);
    }
    ;

shift_expression
    : additive_expression
    | shift_expression LSHIFT additive_expression
    | shift_expression RSHIFT additive_expression
    ;

relational_expression
    : shift_expression
    | relational_expression LSS shift_expression
    | relational_expression GTR shift_expression
    | relational_expression LEQ shift_expression
    | relational_expression GEQ shift_expression
    ;

equality_expression
    : relational_expression
    | equality_expression EQL relational_expression
    | equality_expression NEQ relational_expression
    ;

AND_expression
    : equality_expression
    | AND_expression AMP equality_expression
    ;

exclusive_OR_expression
    : AND_expression
    | exclusive_OR_expression CARET AND_expression
    ;

inclusive_OR_expression
    : exclusive_OR_expression
    | inclusive_OR_expression BAR exclusive_OR_expression
    ;

logical_AND_expression
    : inclusive_OR_expression
    | logical_AND_expression AMPAMP inclusive_OR_expression
    ;

logical_OR_expression
    : logical_AND_expression
    | logical_OR_expression BARBAR logical_AND_expression
    ;

conditional_expression
    : logical_OR_expression
    | logical_OR_expression QUESTION expression COLON conditional_expression
    ;

assignment_expression
    : conditional_expression
    | unary_expression ASSIGN assignment_expression
    ;

comma_expression
    : assignment_expression
    | comma_expression COMMA assignment_expression
    ;

expression
    : comma_expression
    ;

constant_expression
    : conditional_expression
    ;

%%

int main(void)
{
    int result = yyparse();

    if (result == 0)
        printf("Parsing success\n");

    return result;
}

int yyerror(const char *s)
{
    logMsg(LOG_ERROR,
               "Syntax error at line %d: %s",
               line_no, s);
    return 0;
}
