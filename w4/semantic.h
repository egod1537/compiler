#ifndef SEMANTIC_H
#define SEMANTIC_H

/* ============================================================
 * 1. Types & Constants
 * ============================================================ */

/* Shared semantic types and constants are declared in type.h. */
#include "type.h"

/* ============================================================
 * 2. Global State
 * ============================================================ */

/* Current symbol and lexical scope level */
extern A_ID *current_id;
extern int current_level;

/* Built-in canonical types */
extern A_TYPE *int_type;
extern A_TYPE *float_type;
extern A_TYPE *char_type;
extern A_TYPE *void_type;
extern A_TYPE *string_type;

/* ============================================================
 * 3. Initialization
 * ============================================================ */

void initialize(void);

/* Base type allocation used during initialization */
A_TYPE *makeType(T_KIND kind);

/* ============================================================
 * 4. Symbol Table & Scope Management
 * ============================================================ */

/* Identifier creation and lookup */
A_ID *makeIdentifier(char *name);

A_ID *searchIdentifier(const char *name);
A_ID *searchIdentifierAtCurrentLevel(const char *name, A_ID *start);

/* Lexical scope entry and exit */
void enterScope(void);
void leaveScope(void);

/* Semantic diagnostics and declaration-list linking */
void semanticError(const char *message);
A_ID *linkDeclaratorList(A_ID *head, A_ID *tail);

/* ============================================================
 * 5. Type Construction
 * ============================================================ */

A_TYPE *setTypeElementType(A_TYPE *t1, A_TYPE *t2);

A_ID *setDeclaratorElementType(A_ID *id, A_TYPE *type);

// T_ARRAY -> expr 연결함
A_TYPE *setTypeExpr(A_TYPE *type, A_NODE *expr);

// A_TYPE -> A_ID 타입 테이블에 식별자 목록 연결함
// e.g) struct 선언 및 멤버 선언
A_TYPE *setTypeField(A_TYPE *type, A_ID *field);

/* ============================================================
 * 6. Declaration & Semantic Actions
 * ============================================================ */

/* Declaration specifier construction and normalization */
// 저장 클래스랑 식별자를 하나로 묶음A
// e.g) static int a;
A_SPECIFIER *makeSpecifier(A_TYPE *type, S_KIND stor);

A_SPECIFIER *updateSpecifier(A_SPECIFIER *specifier, A_TYPE *type, S_KIND stor);

// 기본 타입(int)로 설정함
void setDefaultSpecifier(A_SPECIFIER *specifier);

/* Declarator, function, and parameter actions */
A_ID *setDeclaratorListSpecifier(A_ID *id, A_SPECIFIER *specifier);
A_ID *setStructDeclaratorListSpecifier(A_ID *id, A_TYPE *type);
A_ID *setFunctionDeclaratorSpecifier(A_ID *id, A_SPECIFIER *specifier);

A_ID *setFunctionDeclaratorBody(A_ID *id, A_NODE *body);
A_ID *setParameterDeclaratorSpecifier(A_ID *id, A_SPECIFIER *specifier);

/* Declaration-time symbol and type resolution */
A_ID *getIdentifierDeclared(const char *name);
A_ID *makeDummyIdentifier(void);

A_TYPE *setTypeNameSpecifier(A_TYPE *type, A_SPECIFIER *specifier);

A_TYPE *setTypeStructOrEnumIdentifier(T_KIND kind, char *name, ID_KIND id_kind);
A_TYPE *getTypeOfStructOrEnumIdentifier(T_KIND kind, char *name, ID_KIND id_kind);

A_ID *setDeclaratorKind(A_ID *id, ID_KIND kind);

/* ============================================================
 * 7. Error Handling & Utilities
 * ============================================================ */

/* Deferred semantic validation */
void checkForwardReference(void);
#endif // !SEMANTIC_H
