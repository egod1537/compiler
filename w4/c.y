/* ============================================================
 * 1. 선언 및 파서 설정
 * ============================================================ */
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

/* ============================================================
 * 2. 프로그램 및 함수 정의
 * ============================================================ */

/* 2.1 프로그램 루트 및 번역 단위 */

program
    : translation_unit
    {
      checkForwardReference();

      program_root = makeNode(N_PROGRAM, NULL, PTR(A_NODE, $1), NULL);

      $$ = YY(program_root);
    }
    ;

translation_unit
    : external_declaration { $$ = $1; }
    | translation_unit external_declaration
    {
      $$ = YY(linkDeclaratorList(PTR(A_ID, $1), PTR(A_ID, $2)));
    }
    ;

external_declaration
    : function_definition { $$ = $1; }
    | declaration { $$ = $1; }
    ;

/* 2.2 함수 정의 및 함수 스코프 설정 */

function_definition
    : declaration_specifiers declarator
    {
      A_ID *id = setFunctionDeclaratorSpecifier(PTR(A_ID, $2), PTR(A_SPECIFIER, $1));

      current_id = id;
      enterScope();

      for (A_ID *p = id->type->field; p != NULL; p = p->link) {
        if (p->name == NULL || p->name[0] == '\0')
          continue;

        p->level = current_level;
        p->prev = current_id;
        current_id = p;
      }

      $$ = YY(id);
    }
      compound_statement
    {
      A_ID *id = setFunctionDeclaratorBody(PTR(A_ID, $3), PTR(A_NODE, $4));

      leaveScope();
      $$ = YY(id);
    }
    | declarator
    {
      A_ID *id =
          setFunctionDeclaratorSpecifier(PTR(A_ID, $1), makeSpecifier(int_type, S_NULL));

      current_id = id;
      enterScope();

      for (A_ID *p = id->type->field; p != NULL; p = p->link) {
        if (p->name == NULL || p->name[0] == '\0')
          continue;

        p->level = current_level;
        p->prev = current_id;
        current_id = p;
      }

      $$ = YY(id);
    }
      compound_statement
    {
      A_ID *id = setFunctionDeclaratorBody(PTR(A_ID, $2), PTR(A_NODE, $3));

      leaveScope();
      $$ = YY(id);
    }
    ;

/* ============================================================
 * 3. 선언 및 타입 지정자
 * ============================================================ */

/* 3.1 일반 선언, 지정자 및 선언자 목록 */

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
    : declaration_specifiers init_declarator_list_opt SEMICOLON
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
    {
      semanticError("Type type_qualifier are not suuported");
      $$ = YY(NULL);
    }
    | type_specifier declaration_specifiers
    {
      $$ = YY(updateSpecifier(PTR(A_SPECIFIER, $2), PTR(A_TYPE, $1), S_NULL));
    }
    | storage_class_specifier declaration_specifiers
    {
      $$ = YY(updateSpecifier(PTR(A_SPECIFIER, $2), NULL, (S_KIND)$1));
    }
    | type_qualifier declaration_specifiers
    {
      semanticError("Type type_qualifier are not suuported");
      $$ = $2;
    }
    ;

storage_class_specifier
    : AUTO_SYM { $$ = YY(S_AUTO); }
    | STATIC_SYM { $$ = YY(S_STATIC); }
    | TYPEDEF_SYM { $$ = YY(S_TYPEDEF); }
    | REGISTER_SYM
    {
      semanticError("register is not supported");
      $$ = YY(S_NULL);
    }
    | EXTERN_SYM
    {
      semanticError("extern is not supported");
      $$ = YY(S_NULL);
    }
    ;

type_qualifier
    : CONST_SYM
    | VOLATILE_SYM
    ;

init_declarator_list_opt
    :
    {
      $$ = YY(NULL);
    }
    | init_declarator_list
    {
      $$ = $1;
    }
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
    {
      semanticError("Initializers are not supported");
      $$ = YY(NULL);
    }
    ;

type_specifier
    : struct_specifier
    | enum_specifier
    | TYPE_IDENTIFIER
    {
      $$ = $1;
    }
    ;

/* 3.2 구조체 및 공용체 지정자 */

struct_specifier
    : struct_or_union IDENTIFIER
    {
      char *name = PTR(char, $2);
      $$ = YY(setTypeStructOrEnumIdentifier((T_KIND)$1, name, ID_STRUCT));
      free(name);
    }
      LR struct_declaration_list RR
    {
      $$ = YY(setTypeField(PTR(A_TYPE, $3), PTR(A_ID, $5)));
    }
    | struct_or_union
    {
      $$ = YY(makeType((T_KIND)$1));
    }
      LR struct_declaration_list RR
    {
      $$ = YY(setTypeField(PTR(A_TYPE, $2), PTR(A_ID, $4)));
    }
    | struct_or_union IDENTIFIER
    {
      char *name = PTR(char, $2);
      $$ = YY(getTypeOfStructOrEnumIdentifier((T_KIND)$1, name, ID_STRUCT));
      free(name);
    }
    ;

struct_or_union
    : STRUCT_SYM { $$ = YY(T_STRUCT); }
    | UNION_SYM { $$ = YY(T_UNION); }
    ;

struct_declaration_list
    : struct_declaration { $$ = $1; }
    | struct_declaration_list struct_declaration
    {
      $$ = YY(linkDeclaratorList(PTR(A_ID, $1), PTR(A_ID, $2)));
    }
    ;

struct_declaration
    : type_specifier struct_declarator_list SEMICOLON
    {
      $$ = YY(setStructDeclaratorListSpecifier(PTR(A_ID, $2), PTR(A_TYPE, $1)));
    }
    ;

struct_declarator_list
    : struct_declarator { $$ = $1; }
    | struct_declarator_list COMMA struct_declarator
    {
      $$ = YY(linkDeclaratorList(PTR(A_ID, $1), PTR(A_ID, $3)));
    }
    ;

struct_declarator
    : declarator { $$ = $1; }
    | COLON constant_expression
    {
      semanticError("Bit-fields are not implemented");
      $$ = YY(NULL);
    }
    | declarator COLON constant_expression
    {
      semanticError("Bit-fields are not implemented");
      $$ = YY(NULL);
    }
    ;

/* 3.3 열거형 지정자 및 열거자 */

enum_specifier
    : ENUM_SYM IDENTIFIER
    {
      $$ = YY(setTypeStructOrEnumIdentifier(T_ENUM, PTR(char, $2), ID_ENUM));
    }
      LR enumerator_list RR
    {
      $$ = YY(setTypeField(PTR(A_TYPE, $3), PTR(A_ID, $5)));
    }
    | ENUM_SYM
    {
      $$ = YY(makeType(T_ENUM));
    }
      LR enumerator_list RR
    {
      $$ = YY(setTypeField(PTR(A_TYPE, $2), PTR(A_ID, $4)));
    }
    | ENUM_SYM IDENTIFIER
    {
      $$ = YY(getTypeOfStructOrEnumIdentifier(T_ENUM, PTR(char, $2), ID_ENUM));
    }
    ;

enumerator_list
    : enumerator { $$ = $1; }
    | enumerator_list COMMA enumerator
    {
      $$ = YY(linkDeclaratorList(PTR(A_ID, $1), PTR(A_ID, $3)));
    }
    ;

enumerator
    : IDENTIFIER
    {
      char *name = PTR(char, $1);
      A_ID *id = makeIdentifier(name);
      free(name);

      $$ = YY(setDeclaratorKind(id, ID_ENUM_LITERAL));
    }
    | IDENTIFIER ASSIGN constant_expression
    {
      semanticError("Enumerator initializers are not supported");
      $$ = YY(NULL);
    }
    ;

/* ============================================================
 * 4. 선언자 및 매개변수
 * ============================================================ */

/* 4.1 선언자, 포인터 및 한정자 */

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

/* 4.2 직접 선언자 및 배열 크기 */

direct_declarator
    : IDENTIFIER
    {
      char *name = PTR(char, $1);

      A_ID *id = makeIdentifier(name);
      free(name);

      $$ = YY(id);
    }
    | LP declarator RP
    {
      $$ = $2;
    }
    | direct_declarator LB constant_expression_opt RB
    {
      $$ = YY(setDeclaratorElementType(PTR(A_ID, $1),
                                       setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, $3))));
    }
    | direct_declarator LP
    {
      enterScope();
    }
      parameter_type_list_opt RP
    {
      A_ID *params = PTR(A_ID, $4);

      $$ = YY(
          setDeclaratorElementType(PTR(A_ID, $1), setTypeField(makeType(T_FUNC), params)));

      leaveScope();
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

/* 4.3 형식 매개변수 및 추상 선언자 */

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
    {
      semanticError("Variadic parameters are not supported");
      $$ = YY(NULL);
    }
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
    {
      $$ = $1;
    }
    | direct_abstract_declarator
    {
      $$ = $1;
    }
    | pointer direct_abstract_declarator
    {
      $$ = YY(setTypeElementType(PTR(A_TYPE, $2), PTR(A_TYPE, $1)));
    }
    ;

direct_abstract_declarator
    : LP abstract_declarator RP
    {
      $$ = $2;
    }
    | LB constant_expression_opt RB
    {
      $$ = YY(setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, $2)));
    }
    | LP parameter_type_list_opt RP
    {
      $$ = YY(setTypeField(makeType(T_FUNC), PTR(A_ID, $2)));
    }
    | direct_abstract_declarator LB constant_expression_opt RB
    {
      $$ = YY(setTypeElementType(PTR(A_TYPE, $1),
                                 setTypeExpr(makeType(T_ARRAY), PTR(A_NODE, $3))));
    }
    | direct_abstract_declarator LP parameter_type_list_opt RP
    {
      $$ = YY(setTypeElementType(PTR(A_TYPE, $1),
                                 setTypeField(makeType(T_FUNC), PTR(A_ID, $3))));
    }
    ;

/* 4.4 초기화 */

initializer
    : assignment_expression
    {
      semanticError("Initializers are not supported");
      $$ = YY(NULL);
    }
    | LR initializer_list RR
    {
      semanticError("Initializers are not supported");
      $$ = YY(NULL);
    }
    | LR initializer_list COMMA RR
    {
      semanticError("Initializers are not supported");
      $$ = YY(NULL);
    }
    ;

initializer_list
    : initializer
    {
      semanticError("Initializers are not supported");
      $$ = YY(NULL);
    }
    | initializer_list COMMA initializer
    {
      semanticError("Initializers are not supported");
      $$ = YY(NULL);
    }
    ;

/* ============================================================
 * 5. 문장
 * ============================================================ */

/* 5.1 문장 분기, 스코프 블록 및 레이블 */

statement
    : labeled_statement { $$ = $1; }
    | scoped_compound_statement
    {
      $$ = $1;
    }
    | expression_statement
    {
      $$ = $1;
    }
    | selection_statement { $$ = $1; }
    | iteration_statement { $$ = $1; }
    | jump_statement
    {
      $$ = $1;
    }
    ;

scoped_compound_statement
    :
    {
      enterScope();
    }
      compound_statement
    {
      $$ = $2;
      leaveScope();
    }
    ;

labeled_statement
    : CASE_SYM constant_expression COLON statement
    {
      $$ = YY(makeNode(N_STMT_LABEL_CASE, PTR(A_NODE, $2), NULL, PTR(A_NODE, $4)));
    }
    | DEFAULT_SYM COLON statement
    {
      $$ = YY(makeNode(N_STMT_LABEL_DEFAULT, NULL, PTR(A_NODE, $3), NULL));
    }
    | IDENTIFIER COLON statement
    {
      semanticError("User labels are not supported");
      $$ = YY(NULL);
    }
    ;

/* 5.2 복합문 및 문장 목록 */

compound_statement
    : LR declaration_list_opt statement_list_opt RR
    {
      $$ = YY(makeNode(N_STMT_COMPOUND, PTR(A_NODE, $2), NULL, PTR(A_NODE, $3)));

      compound_root = PTR(A_NODE, $$);
    }
    ;

declaration_list
    : declaration
    {
      $$ = $1;
    }
    | declaration_list declaration
    {
      $$ = YY(linkDeclaratorList(PTR(A_ID, $1), PTR(A_ID, $2)));
    }
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

/* 5.3 수식문 */

expression_statement
    : SEMICOLON
    {
      $$ = YY(makeNode(N_STMT_EMPTY, NULL, NULL, NULL));
    }
    | expression SEMICOLON
    {
      $$ = YY(makeNode(N_STMT_EXPRESSION, NULL, PTR(A_NODE, $1), NULL));
    }
    ;

/* 5.4 선택문: if, if-else, switch */

selection_statement
    : IF_SYM LP expression RP statement %prec LOWER_THAN_ELSE
    {
      $$ = YY(makeNode(N_STMT_IF, PTR(A_NODE, $3), NULL, PTR(A_NODE, $5)));
    }
    | IF_SYM LP expression RP statement ELSE_SYM statement
    {
      $$ = YY(makeNode(N_STMT_IF_ELSE, PTR(A_NODE, $3), PTR(A_NODE, $5), PTR(A_NODE, $7)));
    }
    | SWITCH_SYM LP expression RP statement
    {
      $$ = YY(makeNode(N_STMT_SWITCH, PTR(A_NODE, $3), NULL, PTR(A_NODE, $5)));
    }
    ;

/* 5.5 반복문: while, do-while, for */

iteration_statement
    : WHILE_SYM LP expression RP statement
    {
      $$ = YY(makeNode(N_STMT_WHILE, PTR(A_NODE, $3), NULL, PTR(A_NODE, $5)));
    }
    | DO_SYM statement WHILE_SYM LP expression RP SEMICOLON
    {
      $$ = YY(makeNode(N_STMT_DO, PTR(A_NODE, $2), NULL, PTR(A_NODE, $5)));
    }
    | FOR_SYM LP for_expression RP statement
    {
      $$ = YY(makeNode(N_STMT_FOR, PTR(A_NODE, $3), NULL, PTR(A_NODE, $5)));
    }
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

for_expression
    : expression_opt SEMICOLON expression_opt SEMICOLON expression_opt
    {
      $$ = YY(makeNode(N_FOR_EXP, PTR(A_NODE, $1), PTR(A_NODE, $3), PTR(A_NODE, $5)));
    }
    ;

/* 5.6 점프문: return, continue, break, goto */

jump_statement
    : RETURN_SYM expression_opt SEMICOLON
    {
      $$ = YY(makeNode(N_STMT_RETURN, NULL, PTR(A_NODE, $2), NULL));

      statement_root = PTR(A_NODE, $$);
    }
    | CONTINUE_SYM SEMICOLON
    {
      $$ = YY(makeNode(N_STMT_CONTINUE, NULL, NULL, NULL));
    }
    | BREAK_SYM SEMICOLON
    {
      $$ = YY(makeNode(N_STMT_BREAK, NULL, NULL, NULL));
    }
    | GOTO_SYM IDENTIFIER SEMICOLON
    {
      semanticError("goto is not supported");
      $$ = YY(NULL);
    }
    ;

/* ============================================================
 * 6. 수식
 * ============================================================ */

/* 6.1 기본, 후위 및 인수 목록 수식 */

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
    {
      $$ = YY(makeNode(N_EXP_FLOAT_CONST, NULL, PTR(A_NODE, $1), NULL));
    }
    | CHARACTER_CONSTANT
    {
      $$ = YY(makeNode(N_EXP_CHAR_CONST, NULL, PTR(A_NODE, $1), NULL));
    }
    | STRING_LITERAL
    {
      $$ = YY(makeNode(N_EXP_STRING_LITERAL, NULL, PTR(A_NODE, $1), NULL));
    }
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
    {
      $$ = YY(makeNode(N_EXP_FUNCTION_CALL, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    | postfix_expression PERIOD IDENTIFIER
    {
      char *name = PTR(char, $3);
      $$ = YY(makeNode(N_EXP_STRUCT, PTR(A_NODE, $1), NULL, PTR(A_NODE, name)));
    }
    | postfix_expression ARROW IDENTIFIER
    {
      char *name = PTR(char, $3);
      $$ = YY(makeNode(N_EXP_ARROW, PTR(A_NODE, $1), NULL, PTR(A_NODE, name)));
    }
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
    {
      $$ = YY(makeNode(N_ARG_LIST_NIL, NULL, NULL, NULL));
    }
    | arg_expression_list { $$ = $1; }
    ;

arg_expression_list
    : assignment_expression
    {
      $$ = YY(makeNode(N_ARG_LIST, PTR(A_NODE, $1), NULL,
                       makeNode(N_ARG_LIST_NIL, NULL, NULL, NULL)));
    }
    | arg_expression_list COMMA assignment_expression
    {
      $$ = YY(makeNodeList(N_ARG_LIST, PTR(A_NODE, $1), PTR(A_NODE, $3)));
    }
    ;

/* 6.2 단항, 캐스트 및 타입 이름 수식 */

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
    {
      semanticError("Bitwise complement is not supported");
      $$ = YY(NULL);
    }
    | PLUS cast_expression
    {
      $$ = $2;
    }
    | SIZEOF_SYM unary_expression
    {
      $$ = YY(makeNode(N_EXP_SIZE_EXP, NULL, PTR(A_NODE, $2), NULL));
    }
    | SIZEOF_SYM LP type_name RP
    {
      $$ = YY(makeNode(N_EXP_SIZE_TYPE, NULL, PTR(A_NODE, $3), NULL));
    }
    ;

cast_expression
    : unary_expression
    {
      $$ = $1;
    }
    | LP type_name RP cast_expression
    {
      $$ = YY(makeNode(N_EXP_CAST, PTR(A_NODE, $2), NULL, PTR(A_NODE, $4)));
    }
    ;

type_name
    : declaration_specifiers abstract_declarator_opt
    {
      $$ = YY(setTypeNameSpecifier(PTR(A_TYPE, $2), PTR(A_SPECIFIER, $1)));
    }
    ;

/* 6.3 곱셈, 덧셈 및 시프트 수식 */

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
    : additive_expression { $$ = $1; }
    | shift_expression LSHIFT additive_expression
    {
      semanticError("Left shift is not supported");
      $$ = YY(NULL);
    }
    | shift_expression RSHIFT additive_expression
    {
      semanticError("Right shift is not supported");
      $$ = YY(NULL);
    }
    ;

/* 6.4 관계 및 동등 수식 */

relational_expression
    : shift_expression
    {
      $$ = $1;
    }
    | relational_expression LSS shift_expression
    {
      $$ = YY(makeNode(N_EXP_LSS, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    | relational_expression GTR shift_expression
    {
      $$ = YY(makeNode(N_EXP_GTR, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    | relational_expression LEQ shift_expression
    {
      $$ = YY(makeNode(N_EXP_LEQ, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    | relational_expression GEQ shift_expression
    {
      $$ = YY(makeNode(N_EXP_GEQ, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    ;

equality_expression
    : relational_expression
    {
      $$ = $1;
    }
    | equality_expression EQL relational_expression
    {
      $$ = YY(makeNode(N_EXP_EQL, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    | equality_expression NEQ relational_expression
    {
      $$ = YY(makeNode(N_EXP_NEQ, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    ;

/* 6.5 비트 및 논리 수식 */

AND_expression
    : equality_expression { $$ = $1; }
    | AND_expression AMP equality_expression
    {
      semanticError("Bitwise AND is not supported");
      $$ = YY(NULL);
    }
    ;

exclusive_OR_expression
    : AND_expression { $$ = $1; }
    | exclusive_OR_expression CARET AND_expression
    {
      semanticError("Bitwise XOR is not supported");
      $$ = YY(NULL);
    }
    ;

inclusive_OR_expression
    : exclusive_OR_expression { $$ = $1; }
    | inclusive_OR_expression BAR exclusive_OR_expression
    {
      semanticError("Bitwise OR is not supported");
      $$ = YY(NULL);
    }
    ;

logical_AND_expression
    : inclusive_OR_expression { $$ = $1; }
    | logical_AND_expression AMPAMP inclusive_OR_expression
    {
      $$ = YY(makeNode(N_EXP_AND, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    ;

logical_OR_expression
    : logical_AND_expression { $$ = $1; }
    | logical_OR_expression BARBAR logical_AND_expression
    {
      $$ = YY(makeNode(N_EXP_OR, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    ;

/* 6.6 조건, 대입 및 콤마 수식 */

conditional_expression
    : logical_OR_expression
    {
      $$ = $1;
    }
    | logical_OR_expression QUESTION expression COLON conditional_expression
    {
      semanticError("Conditional operator is not supported");
      $$ = YY(NULL);
    }
    ;

assignment_expression
    : conditional_expression
    {
      $$ = $1;
    }
    | unary_expression ASSIGN assignment_expression
    {
      $$ = YY(makeNode(N_EXP_ASSIGN, PTR(A_NODE, $1), NULL, PTR(A_NODE, $3)));
    }
    ;

comma_expression
    : assignment_expression
    {
      $$ = $1;
    }
    | comma_expression COMMA assignment_expression
    {
      semanticError("Comma expressions are not supported");
      $$ = YY(NULL);
    }
    ;

/* 6.7 수식 루트 및 상수 수식 */

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

/* ============================================================
 * 7. 보조 C 함수
 * ============================================================ */

int yyerror(const char *s) {
  logMsg(LOG_ERROR, "Syntax error at line %d: %s", line_no, s);
  return 0;
}
