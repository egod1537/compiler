%{
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

// 이전이랑 달라진 듯?

function_definition
    : declaration_specifiers declarator
    {
      A_ID *id = YY(setFunctionDeclaratorSpecifier(PTR(A_ID, $2), PTR(A_SPECIFIER, $1)));
    
      current_id = id;
      enterScope();
    
      for (A_ID *p = id->type->field; p; p = p->link) {
        if (p->name == NULL || p->name[0] == '\0')
          continue;
    
        p->level = current_level;
        p->prev = current_id;
        current_id = p;
      }
    
      $$ = YY(id);
    }
    | compound_statement
    {
      A_ID *id = YY(setFunctionDeclaratorBody(PTR(A_ID, $2), PTR(A_NODE, $3)));
    
      leaveScope();
      $$ = YY(id);
    }
    | declarator
    {
      A_ID *id =
          setFunctionDeclaratorSpecifier(PTR(A_ID, $1), makeSpecifier(int_type, s_NULL));
    
      current_id = id;
      enterScope();
    
      for (A_ID *p = id->type->field; p; p = p->link) {
        if (p->name == NULL || p->name[0] == '\0')
          continue;
    
        p->level = current_level;
        p->prev = current_id;
        current_id = id;
      }
    
      $$ = YY(id);
    }
    | compound_statement
    {
      A_ID *id = setFunctionDeclaratorBody(PTR(A_ID, $2), PTR(A_NODE, $3));
    
      leaveScope();
      $$ = YY(id);
    }
    ;

declaration_list_opt
    :
    {
      $$ = YY(NULL);
    }
    | declaration_list
    {
      $$ = $1;
    }
    ;

declaration
    : declaration_specifiers init_declarator_list SEMICOLON
    {
      $$ = YY(setDeclaratorListSpecifier(PTR(A_ID, $2), PTR(A_SPECIFIER, $1)));
    }
    ;

declaration_specifiers
    : type_specifier
    {
      $$ = YY(makeSpecifier(PTR(A_TYPE, $1), S_NULL));
    }
    | storage_class_specifier
    {
      $$ = YY(makeSpecifier(NULL, (S_KIND)$1));
    }
    | type_qualifier
    | type_specifier declaration_specifiers
    {
      $$ = YY(updateSpecifier(PTR(A_SPECIFIER, $2), PTR(A_TYPE, $1), S_NULL));
    }
    | storage_class_specifier declaration_specifiers
    {
      $$ = YY(updateSpecifier(PTR(A_SPECIFIER, $2), PTR(A_TYPE, $1), S_NULL));
    }
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
    {
      $$ = $1;
    }
    | init_declarator_list COMMA init_declarator
    {
      $$ = YY(linkDeclaratorList(PTR(A_ID, $1), PTR(A_ID, $3)));
    }
    ;

init_declarator
    : declarator
    {
      $$ = $1;
    }
    | declarator ASSIGN initializer
    ;

type_specifier
    : struct_specifier
    | enum_specifier
    | TYPE_IDENTIFIER
    {
      $$ = $1;
    }
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
    {
      $$ = YY(setDeclaratorElementType(PTR(A_ID, $2), PTR(A_TYPE, $1)));
    }
    | direct_declarator
    {
      $$ = $1;
    }
    ;

pointer
    : STAR type_qualifier_list_opt
    {
      $$ = YY(makeType(T_POINTER));
    }
    | STAR type_qualifier_list_opt pointer
    {
      $$ = YY(setTypeElementType(PTR(A_TYPE, $3), makeType(T_POINTER)));
    }
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
    {
      char *name = PTR(char, $1);
    
      A_ID *id = makeIdentifier(name);
      free(name);
    
      $$ = YY(id);
    }
    | LP declarator RP
    | direct_declarator LB constant_expression_opt RB
    {
      $$ = YY(setDeclaratorElementType(PTR(A_ID, $1),
                                       setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, $3))));
    }
    | direct_declarator LP parameter_type_list_opt RP
    {
      $$ = YY(setDeclaratorElementType(PTR(A_ID, $1),
                                       setTypeField(makeType(T_FUNC), PTR(A_ID, $3))));
    }
    ;

constant_expression_opt
    :
    {
      $$ = YY(NULL);
    }
    | constant_expression
    {
      $$ = $1;
    }
    ;

parameter_type_list_opt
    :
    {
      $$ = YY(NULL);
    }
    | parameter_type_list
    {
      $$ = $1;
    }
    ;

parameter_type_list
    : parameter_list
    | parameter_list COMMA DOTDOTDOT
    ;

parameter_list
    : parameter_declaration
    {
      $$ = $1;
    }
    | parameter_list COMMA parameter_declaration
    {
      $$ = YY(linkDeclaratorList(PTR(A_ID, $1), PTR(A_ID, $3)));
    }
    ;

parameter_declaration
    : declaration_specifiers declarator
    {
      $$ = YY(setParameterDeclaratorSpecifier(PTR(A_ID, $2), PTR(A_SPECIFIER, $1)));
    }
    | declaration_specifiers abstract_declarator_opt
    {
      A_ID *id = makeDummyIdentifier();
    
      setDeclaratorElementType(id, PTR(A_TYPE, $2));
    
      $$ = YY(setParameterDeclaratorSpecifier(id, PTR(A_SPECIFIER, $1)));
    }
    ;

abstract_declarator_opt
    :
    {
      $$ = YY(NULL);
    }
    | abstract_declarator
    {
      $$ = $1;
    }
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
    {
      $$ = $1;
    }
    ;

labeled_statement
    : CASE_SYM constant_expression COLON statement
    | DEFAULT_SYM COLON statement
    | IDENTIFIER COLON statement
    ;

compound_statement
    : LR declaration_list_opt statement_list_opt RR
    {
      $$ = YY(makeNode(N_STMT_COMPOUND, PTR(A_NODE, $2), NULL, PTR(A_NODE, $3)));
    }
    ;

declaration_list
    : declaration
    | declaration_list declaration
    ;

statement_list_opt
    :
    {
      $$ = YY(makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL));
    }
    | statement_list
    {
      $$ = $1;
    }
    ;

statement_list
    : statement
    {
      $$ = YY(makeNode(N_STMT_LIST, PTR(A_NODE, $1), NULL,
                       makeNode(N_STMT_LIST_NIL, NULL, NULL, NULL)));
    }
    | statement_list statement
    {
      $$ = YY(makeNodeList(N_STMT_LIST, PTR(A_NODE, $1), PTR(A_NODE, $2)));
    }
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
    | FOR_SYM LP expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RP
      statement
    ;

expression_opt
    :
    {
      $$ = YY(NULL);
    }
    | expression
    {
      $$ = $1;
    }
    ;

jump_statement
    : RETURN_SYM expression_opt SEMICOLON
    {
      $$ = YY(makeNode(N_STMT_RETURN, NULL, PTR(A_NODE, $2), NULL));
    
      statement_root = PTR(A_NODE, $$);
    }
    | CONTINUE_SYM SEMICOLON
    | BREAK_SYM SEMICOLON
    | GOTO_SYM IDENTIFIER SEMICOLON
    ;

primary_expression
    : IDENTIFIER
    {
      char *name = PTR(char, $1);
      A_ID *id = getIdentifierDeclared(name);
      free(name);
    
      $$ = YY(makeNode(N_EXP_IDENT, NULL, PTR(A_NODE, id), NULL));
    }
    | INTEGER_CONSTANT
    {
      $$ = YY(makeNode(N_EXP_INT_CONST, NULL, PTR(A_NODE, $1), NULL));
    
      A_NODE *node = PTR(A_NODE, $$);
      logMsg(LOG_DEBUG, "N_EXP_INT_CONST: %lld", (long long)(intptr_t)node->clink);
    }
    | FLOAT_CONSTANT
    | CHARACTER_CONSTANT
    | STRING_LITERAL
    | LP expression RP
    {
      $$ = $2;
    }
    ;

postfix_expression
    : primary_expression
    {
      $$ = $1;
    }
    | postfix_expression LB expression RB
    {
      $$ = YY(makeNode(N_EXP_ARRAY, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    | postfix_expression LP arg_expression_list_opt RP
    | postfix_expression PERIOD IDENTIFIER
    | postfix_expression ARROW IDENTIFIER
    | postfix_expression PLUSPLUS
    {
      $$ = YY(makeNode(N_EXP_POST_INC, NULL, PTR(A_NODE, $1), NULL));
    }
    | postfix_expression MINUSMINUS
    {
      $$ = YY(makeNode(N_EXP_POST_DEC, NULL, PTR(A_NODE, $1), NULL));
    }
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
    : postfix_expression
    {
      $$ = $1;
    }
    | PLUSPLUS unary_expression
    {
      $$ = YY(makeNode(N_EXP_PRE_INC, NULL, PTR(A_NODE, $2), NULL));
    }
    | MINUSMINUS unary_expression
    {
      $$ = YY(makeNode(N_EXP_PRE_DEC, NULL, PTR(A_NODE, $2), NULL));
    }
    | AMP cast_expression
    {
      $$ = YY(makeNode(N_EXP_AMP, NULL, PTR(A_NODE, $2), NULL));
    }
    | STAR cast_expression
    {
      $$ = YY(makeNode(N_EXP_STAR, NULL, PTR(A_NODE, $2), NULL));
    }
    | EXCL cast_expression
    {
      $$ = YY(makeNode(N_EXP_NOT, NULL, PTR(A_NODE, $2), NULL));
    }
    | MINUS cast_expression
    {
      $$ = YY(makeNode(N_EXP_MINUS, NULL, PTR(A_NODE, $2), NULL));
    }
    | TILDE cast_expression
    | PLUS cast_expression
    {
      $$ = $2;
    }
    | SIZEOF_SYM unary_expression
    | SIZEOF_SYM LP type_name RP
    ;

cast_expression
    : unary_expression
    {
      $$ = $1;
    }
    | LP type_name RP cast_expression
    ;

type_name
    : declaration_specifiers
    | declaration_specifiers abstract_declarator
    ;

multiplicative_expression
    : cast_expression
    {
      $$ = $1;
    }
    | multiplicative_expression STAR cast_expression
    {
      $$ = YY(makeNode(N_EXP_MUL, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    | multiplicative_expression SLASH cast_expression
    {
      $$ = YY(makeNode(N_EXP_DIV, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    | multiplicative_expression PERCENT cast_expression
    {
      $$ = YY(makeNode(N_EXP_MOD, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    ;

additive_expression
    : multiplicative_expression
    {
      $$ = $1;
    }
    | additive_expression PLUS multiplicative_expression
    {
      $$ = YY(makeNode(N_EXP_ADD, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    | additive_expression MINUS multiplicative_expression
    {
      $$ = YY(makeNode(N_EXP_SUB, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
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
    {
      $$ = $1;
      expression_root = PTR(A_NODE, $1);
    }
    ;

constant_expression
    : conditional_expression
    ;
%%
int yyerror(const char *s) {
  logMsg(LOG_ERROR, "Syntax error at line %d: %s", line_no, s);
  return 0;
}
