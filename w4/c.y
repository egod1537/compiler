%code requires {
#include <stdint.h>
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#ifdef _WIN64
typedef long long YYSTYPE;
#else
typedef long YYSTYPE;
#endif
#endif
}

%{
#include <stdio.h>
#include "type.h"
#include "parse_value.h"
#include "support.h"
#include "error.h"

int yylex(void);
int yyerror(const char *s);

#define P(type, value) YY_TO_PTR(type, value)
#define V(value) YY_FROM_PTR(value)
%}

%start program
%expect 1
%token INVALID_TOKEN IDENTIFIER TYPE_IDENTIFIER FLOAT_CONSTANT INTEGER_CONSTANT
       CHARACTER_CONSTANT STRING_LITERAL PLUS MINUS PLUSPLUS
       MINUSMINUS BAR AMP BARBAR AMPAMP ARROW
       SEMICOLON LSS GTR LEQ GEQ EQL NEQ DOTDOTDOT
       LP RP LB RB LR RR PERIOD COMMA EXCL STAR SLASH PERCENT ASSIGN COLON
       STRUCT_SYM ENUM_SYM SIZEOF_SYM UNION_SYM
       IF_SYM ELSE_SYM WHILE_SYM DO_SYM FOR_SYM CONTINUE_SYM
       BREAK_SYM RETURN_SYM SWITCH_SYM CASE_SYM DEFAULT_SYM

%%
program
    : translation_unit
      { root=makeNode(N_PROGRAM,NIL,P(A_NODE,$1),NIL); checkForwardReference(); }
    ;

translation_unit
    : external_declaration                  { $$=$1; }
    | translation_unit external_declaration { $$=V(linkDeclaratorList(P(A_ID,$1),P(A_ID,$2))); }
    ;

external_declaration
    : function_definition { $$=$1; }
    | declaration         { $$=$1; }
    ;

function_definition
    : declaration_specifiers declarator
      { $$=V(setFunctionDeclaratorSpecifier(P(A_ID,$2),P(A_SPECIFIER,$1))); }
      compound_statement
      { $$=V(setFunctionDeclaratorBody(P(A_ID,$3),P(A_NODE,$4))); }
    | declarator
      { $$=V(setFunctionDeclaratorSpecifier(P(A_ID,$1),makeSpecifier(int_type))); }
      compound_statement
      { $$=V(setFunctionDeclaratorBody(P(A_ID,$2),P(A_NODE,$3))); }
    ;

declaration_list_opt
    :                  { $$=V(NIL); }
    | declaration_list { $$=$1; }
    ;

declaration_list
    : declaration                          { $$=$1; }
    | declaration_list declaration         { $$=V(linkDeclaratorList(P(A_ID,$1),P(A_ID,$2))); }
    ;

declaration
    : declaration_specifiers declarator_list_opt SEMICOLON
      { $$=V(setDeclaratorListSpecifier(P(A_ID,$2),P(A_SPECIFIER,$1))); }
    ;

declaration_specifiers
    : type_specifier
      { $$=V(makeSpecifier(P(A_TYPE,$1))); }
    ;

declarator_list_opt
    :                 { $$=V(makeDummyIdentifier()); }
    | declarator_list { $$=$1; }
    ;

declarator_list
    : declarator                       { $$=$1; }
    | declarator_list COMMA declarator { $$=V(linkDeclaratorList(P(A_ID,$1),P(A_ID,$3))); }
    ;

type_specifier
    : struct_type_specifier { $$=$1; }
    | enum_type_specifier   { $$=$1; }
    | TYPE_IDENTIFIER       { $$=$1; }
    ;

struct_type_specifier
    : struct_or_union IDENTIFIER
      { $$=V(setTypeStructOrEnumIdentifier((T_KIND)$1,P(char,$2),ID_STRUCT)); }
      LR { $$=V(current_id); current_level++; } struct_declaration_list RR
      { checkForwardReference(); $$=V(setTypeField(P(A_TYPE,$3),P(A_ID,$6)));
        current_level--; current_id=P(A_ID,$5); }
    | struct_or_union
      { $$=V(makeType((T_KIND)$1)); }
      LR { $$=V(current_id); current_level++; } struct_declaration_list RR
      { checkForwardReference(); $$=V(setTypeField(P(A_TYPE,$2),P(A_ID,$5)));
        current_level--; current_id=P(A_ID,$4); }
    | struct_or_union IDENTIFIER
      { $$=V(getTypeOfStructOrEnumRefIdentifier((T_KIND)$1,P(char,$2),ID_STRUCT)); }
    ;

struct_or_union
    : STRUCT_SYM { $$=T_STRUCT; }
    | UNION_SYM  { $$=T_UNION; }
    ;

struct_declaration_list
    : struct_declaration                         { $$=$1; }
    | struct_declaration_list struct_declaration { $$=V(linkDeclaratorList(P(A_ID,$1),P(A_ID,$2))); }
    ;

struct_declaration
    : type_specifier struct_declarator_list SEMICOLON
      { $$=V(setStructDeclaratorListSpecifier(P(A_ID,$2),P(A_TYPE,$1))); }
    ;

struct_declarator_list
    : struct_declarator                         { $$=$1; }
    | struct_declarator_list COMMA struct_declarator
      { $$=V(linkDeclaratorList(P(A_ID,$1),P(A_ID,$3))); }
    ;

struct_declarator
    : declarator { $$=$1; }
    ;

enum_type_specifier
    : ENUM_SYM IDENTIFIER
      { $$=V(setTypeStructOrEnumIdentifier(T_ENUM,P(char,$2),ID_ENUM)); }
      LR enumerator_list RR
      { $$=V(setTypeField(P(A_TYPE,$3),P(A_ID,$5))); }
    | ENUM_SYM
      { $$=V(makeType(T_ENUM)); }
      LR enumerator_list RR
      { $$=V(setTypeField(P(A_TYPE,$2),P(A_ID,$4))); }
    | ENUM_SYM IDENTIFIER
      { $$=V(getTypeOfStructOrEnumRefIdentifier(T_ENUM,P(char,$2),ID_ENUM)); }
    ;

enumerator_list
    : enumerator                       { $$=$1; }
    | enumerator_list COMMA enumerator { $$=V(linkDeclaratorList(P(A_ID,$1),P(A_ID,$3))); }
    ;

enumerator
    : IDENTIFIER
      { $$=V(setDeclaratorKind(makeIdentifier(P(char,$1)),ID_ENUM_LITERAL)); }
    ;

declarator
    : pointer direct_declarator { $$=V(setDeclaratorElementType(P(A_ID,$2),P(A_TYPE,$1))); }
    | direct_declarator         { $$=$1; }
    ;

pointer
    : STAR         { $$=V(makeType(T_POINTER)); }
    | STAR pointer { $$=V(setTypeElementType(P(A_TYPE,$2),makeType(T_POINTER))); }
    ;

direct_declarator
    : IDENTIFIER { $$=V(makeIdentifier(P(char,$1))); }
    | LP declarator RP { $$=$2; }
    | direct_declarator LB constant_expression_opt RB
      { $$=V(setDeclaratorElementType(P(A_ID,$1),setTypeExpr(makeType(T_ARRAY),P(A_NODE,$3)))); }
    | direct_declarator LP
      { $$=V(current_id); current_level++; }
      parameter_type_list_opt RP
      { checkForwardReference(); current_id=P(A_ID,$3); current_level--;
        $$=V(setDeclaratorElementType(P(A_ID,$1),setTypeField(makeType(T_FUNC),P(A_ID,$4)))); }
    ;

parameter_type_list_opt
    :                     { $$=V(NIL); }
    | parameter_type_list { $$=$1; }
    ;

parameter_type_list
    : parameter_list { $$=$1; }
    | parameter_list COMMA DOTDOTDOT
      { $$=V(linkDeclaratorList(P(A_ID,$1),setDeclaratorKind(makeDummyIdentifier(),ID_PARM))); }
    ;

parameter_list
    : parameter_declaration                      { $$=$1; }
    | parameter_list COMMA parameter_declaration { $$=V(linkDeclaratorList(P(A_ID,$1),P(A_ID,$3))); }
    ;

parameter_declaration
    : declaration_specifiers declarator
      { $$=V(setParameterDeclaratorSpecifier(P(A_ID,$2),P(A_SPECIFIER,$1))); }
    | declaration_specifiers abstract_declarator_opt
      { $$=V(setParameterDeclaratorSpecifier(setDeclaratorType(makeDummyIdentifier(),P(A_TYPE,$2)),P(A_SPECIFIER,$1))); }
    ;

abstract_declarator_opt
    :                     { $$=V(NIL); }
    | abstract_declarator { $$=$1; }
    ;

abstract_declarator
    : direct_abstract_declarator { $$=$1; }
    | pointer                    { $$=V(makeType(T_POINTER)); }
    | pointer direct_abstract_declarator
      { $$=V(setTypeElementType(P(A_TYPE,$2),makeType(T_POINTER))); }
    ;

direct_abstract_declarator
    : LP abstract_declarator RP { $$=$2; }
    | LB constant_expression_opt RB
      { $$=V(setTypeExpr(makeType(T_ARRAY),P(A_NODE,$2))); }
    | direct_abstract_declarator LB constant_expression_opt RB
      { $$=V(setTypeElementType(P(A_TYPE,$1),setTypeExpr(makeType(T_ARRAY),P(A_NODE,$3)))); }
    | LP parameter_type_list_opt RP
      { $$=V(setTypeExpr(makeType(T_FUNC),P(A_NODE,$2))); }
    | direct_abstract_declarator LP parameter_type_list_opt RP
      { $$=V(setTypeElementType(P(A_TYPE,$1),setTypeExpr(makeType(T_FUNC),P(A_NODE,$3)))); }
    ;

statement_list_opt
    :                { $$=V(makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL)); }
    | statement_list { $$=$1; }
    ;

statement_list
    : statement
      { $$=V(makeNode(N_STMT_LIST,P(A_NODE,$1),NIL,makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL))); }
    | statement_list statement
      { $$=V(makeNodeList(N_STMT_LIST,P(A_NODE,$1),P(A_NODE,$2))); }
    ;

statement
    : labeled_statement    { $$=$1; }
    | compound_statement   { $$=$1; }
    | expression_statement { $$=$1; }
    | selection_statement  { $$=$1; }
    | iteration_statement  { $$=$1; }
    | jump_statement       { $$=$1; }
    ;

labeled_statement
    : CASE_SYM constant_expression COLON statement
      { $$=V(makeNode(N_STMT_LABEL_CASE,P(A_NODE,$2),NIL,P(A_NODE,$4))); }
    | DEFAULT_SYM COLON statement
      { $$=V(makeNode(N_STMT_LABEL_DEFAULT,NIL,P(A_NODE,$3),NIL)); }
    ;

compound_statement
    : LR { $$=V(current_id); current_level++; } declaration_list_opt statement_list_opt RR
      { checkForwardReference(); $$=V(makeNode(N_STMT_COMPOUND,P(A_NODE,$3),NIL,P(A_NODE,$4)));
        current_id=P(A_ID,$2); current_level--; }
    ;

expression_statement
    : SEMICOLON            { $$=V(makeNode(N_STMT_EMPTY,NIL,NIL,NIL)); }
    | expression SEMICOLON { $$=V(makeNode(N_STMT_EXPRESSION,NIL,P(A_NODE,$1),NIL)); }
    ;

selection_statement
    : IF_SYM LP expression RP statement
      { $$=V(makeNode(N_STMT_IF,P(A_NODE,$3),NIL,P(A_NODE,$5))); }
    | IF_SYM LP expression RP statement ELSE_SYM statement
      { $$=V(makeNode(N_STMT_IF_ELSE,P(A_NODE,$3),P(A_NODE,$5),P(A_NODE,$7))); }
    | SWITCH_SYM LP expression RP statement
      { $$=V(makeNode(N_STMT_SWITCH,P(A_NODE,$3),NIL,P(A_NODE,$5))); }
    ;

iteration_statement
    : WHILE_SYM LP expression RP statement
      { $$=V(makeNode(N_STMT_WHILE,P(A_NODE,$3),NIL,P(A_NODE,$5))); }
    | DO_SYM statement WHILE_SYM LP expression RP SEMICOLON
      { $$=V(makeNode(N_STMT_DO,P(A_NODE,$2),NIL,P(A_NODE,$5))); }
    | FOR_SYM LP for_expression RP statement
      { $$=V(makeNode(N_STMT_FOR,P(A_NODE,$3),NIL,P(A_NODE,$5))); }
    ;

for_expression
    : expression_opt SEMICOLON expression_opt SEMICOLON expression_opt
      { $$=V(makeNode(N_FOR_EXP,P(A_NODE,$1),P(A_NODE,$3),P(A_NODE,$5))); }
    ;

expression_opt
    :            { $$=V(NIL); }
    | expression { $$=$1; }
    ;

jump_statement
    : RETURN_SYM expression_opt SEMICOLON
      { $$=V(makeNode(N_STMT_RETURN,NIL,P(A_NODE,$2),NIL)); }
    | CONTINUE_SYM SEMICOLON
      { $$=V(makeNode(N_STMT_CONTINUE,NIL,NIL,NIL)); }
    | BREAK_SYM SEMICOLON
      { $$=V(makeNode(N_STMT_BREAK,NIL,NIL,NIL)); }
    ;

arg_expression_list_opt
    :                     { $$=V(makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL)); }
    | arg_expression_list { $$=$1; }
    ;

arg_expression_list
    : assignment_expression
      { $$=V(makeNode(N_ARG_LIST,P(A_NODE,$1),NIL,makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL))); }
    | arg_expression_list COMMA assignment_expression
      { $$=V(makeNodeList(N_ARG_LIST,P(A_NODE,$1),P(A_NODE,$3))); }
    ;

constant_expression_opt
    :                     { $$=V(NIL); }
    | constant_expression { $$=$1; }
    ;

constant_expression
    : expression { $$=$1; }
    ;

expression
    : comma_expression { $$=$1; }
    ;

comma_expression
    : assignment_expression { $$=$1; }
    ;

assignment_expression
    : conditional_expression { $$=$1; }
    | unary_expression ASSIGN assignment_expression
      { $$=V(makeNode(N_EXP_ASSIGN,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    ;

conditional_expression
    : logical_or_expression { $$=$1; }
    ;

logical_or_expression
    : logical_and_expression { $$=$1; }
    | logical_or_expression BARBAR logical_and_expression
      { $$=V(makeNode(N_EXP_OR,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    ;

logical_and_expression
    : bitwise_or_expression { $$=$1; }
    | logical_and_expression AMPAMP bitwise_or_expression
      { $$=V(makeNode(N_EXP_AND,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    ;

bitwise_or_expression
    : bitwise_xor_expression { $$=$1; }
    ;

bitwise_xor_expression
    : bitwise_and_expression { $$=$1; }
    ;

bitwise_and_expression
    : equality_expression { $$=$1; }
    ;

equality_expression
    : relational_expression { $$=$1; }
    | equality_expression EQL relational_expression
      { $$=V(makeNode(N_EXP_EQL,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    | equality_expression NEQ relational_expression
      { $$=V(makeNode(N_EXP_NEQ,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    ;

relational_expression
    : shift_expression { $$=$1; }
    | relational_expression LSS shift_expression
      { $$=V(makeNode(N_EXP_LSS,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    | relational_expression GTR shift_expression
      { $$=V(makeNode(N_EXP_GTR,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    | relational_expression LEQ shift_expression
      { $$=V(makeNode(N_EXP_LEQ,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    | relational_expression GEQ shift_expression
      { $$=V(makeNode(N_EXP_GEQ,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    ;

shift_expression
    : additive_expression { $$=$1; }
    ;

additive_expression
    : multiplicative_expression { $$=$1; }
    | additive_expression PLUS multiplicative_expression
      { $$=V(makeNode(N_EXP_ADD,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    | additive_expression MINUS multiplicative_expression
      { $$=V(makeNode(N_EXP_SUB,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    ;

multiplicative_expression
    : cast_expression { $$=$1; }
    | multiplicative_expression STAR cast_expression
      { $$=V(makeNode(N_EXP_MUL,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    | multiplicative_expression SLASH cast_expression
      { $$=V(makeNode(N_EXP_DIV,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    | multiplicative_expression PERCENT cast_expression
      { $$=V(makeNode(N_EXP_MOD,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    ;

cast_expression
    : unary_expression { $$=$1; }
    | LP type_name RP cast_expression
      { $$=V(makeNode(N_EXP_CAST,P(A_NODE,$2),NIL,P(A_NODE,$4))); }
    ;

unary_expression
    : postfix_expression { $$=$1; }
    | PLUSPLUS unary_expression { $$=V(makeNode(N_EXP_PRE_INC,NIL,P(A_NODE,$2),NIL)); }
    | MINUSMINUS unary_expression { $$=V(makeNode(N_EXP_PRE_DEC,NIL,P(A_NODE,$2),NIL)); }
    | AMP cast_expression { $$=V(makeNode(N_EXP_AMP,NIL,P(A_NODE,$2),NIL)); }
    | STAR cast_expression { $$=V(makeNode(N_EXP_STAR,NIL,P(A_NODE,$2),NIL)); }
    | EXCL cast_expression { $$=V(makeNode(N_EXP_NOT,NIL,P(A_NODE,$2),NIL)); }
    | MINUS cast_expression { $$=V(makeNode(N_EXP_MINUS,NIL,P(A_NODE,$2),NIL)); }
    | PLUS cast_expression { $$=V(makeNode(N_EXP_PLUS,NIL,P(A_NODE,$2),NIL)); }
    | SIZEOF_SYM unary_expression { $$=V(makeNode(N_EXP_SIZE_EXP,NIL,P(A_NODE,$2),NIL)); }
    | SIZEOF_SYM LP type_name RP { $$=V(makeNode(N_EXP_SIZE_TYPE,NIL,P(A_NODE,$3),NIL)); }
    ;

postfix_expression
    : primary_expression { $$=$1; }
    | postfix_expression LB expression RB
      { $$=V(makeNode(N_EXP_ARRAY,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    | postfix_expression LP arg_expression_list_opt RP
      { $$=V(makeNode(N_EXP_FUNCTION_CALL,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    | postfix_expression PERIOD IDENTIFIER
      { $$=V(makeNode(N_EXP_STRUCT,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    | postfix_expression ARROW IDENTIFIER
      { $$=V(makeNode(N_EXP_ARROW,P(A_NODE,$1),NIL,P(A_NODE,$3))); }
    | postfix_expression PLUSPLUS
      { $$=V(makeNode(N_EXP_POST_INC,NIL,P(A_NODE,$1),NIL)); }
    | postfix_expression MINUSMINUS
      { $$=V(makeNode(N_EXP_POST_DEC,NIL,P(A_NODE,$1),NIL)); }
    ;

primary_expression
    : IDENTIFIER
      { $$=V(makeNode(N_EXP_IDENT,NIL,(A_NODE *)getIdentifierDeclared(P(char,$1)),NIL)); }
    | INTEGER_CONSTANT
      { $$=V(makeNode(N_EXP_INT_CONST,NIL,P(A_NODE,$1),NIL)); }
    | FLOAT_CONSTANT
      { $$=V(makeNode(N_EXP_FLOAT_CONST,NIL,P(A_NODE,$1),NIL)); }
    | CHARACTER_CONSTANT
      { $$=V(makeNode(N_EXP_CHAR_CONST,NIL,P(A_NODE,$1),NIL)); }
    | STRING_LITERAL
      { $$=V(makeNode(N_EXP_STRING_LITERAL,NIL,P(A_NODE,$1),NIL)); }
    | LP expression RP { $$=$2; }
    ;

type_name
    : declaration_specifiers abstract_declarator_opt
      { $$=V(setTypeNameSpecifier(P(A_TYPE,$2),P(A_SPECIFIER,$1))); }
    ;
%%

_Static_assert(sizeof(YYSTYPE)>=sizeof(void *),
               "YYSTYPE must be able to hold a pointer");

extern char *yytext;

int yyerror(const char *s)
{
    syntax_err++;
    if (yytext==NIL || yytext[0]=='\0')
        report_compiler_error(SYNTAX_ERROR,0,line_no,"%s at end",s);
    else
        report_compiler_error(SYNTAX_ERROR,0,line_no,
                              "%s near '%s'",s,yytext);
    return 0;
}
