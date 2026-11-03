#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "type.h"

extern A_ID *current_id;
extern int current_level;

A_TYPE *makeType(T_KIND kind);
A_ID *makeIdentifier(char *name);

A_ID *searchIdentifier(const char *name);
A_ID *searchIdentifierAtCurrentLevel(const char *name, A_ID *start);

void enterScope(void);
void leaveScope(void);

void semanticError(const char *message);

A_ID *linkDeclaratorList(A_ID *head, A_ID *tail);
A_TYPE *setTypeElementType(A_TYPE *t1, A_TYPE *t2);

A_ID *setDeclaratorElementType(A_ID *id, A_TYPE *type);

// T_ARRAY -> expr 연결함
A_TYPE *setTypeExpr(A_TYPE *type, A_NODE *expr);

// A_TYPE -> A_ID 타입 테이블에 식별자 목록 연결함
// e.g) struct 선언 및 멤버 선언
A_TYPE *setTypeField(A_TYPE *type, A_ID *field);

// 저장 클래스랑 식별자를 하나로 묶음A
// e.g) static int a;
A_SPECIFIER *makeSpecifier(A_TYPE *type, S_KIND stor);
#endif // !SEMANTIC_H
