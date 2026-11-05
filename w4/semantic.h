#ifndef SEMANTIC_H
#define SEMANTIC_H

/* ============================================================
 * 1. 타입 및 상수
 * ============================================================ */

/* 공통 의미 분석 타입과 상수는 type.h에 선언되어 있음 */
#include "type.h"

/* ============================================================
 * 2. 전역 상태
 * ============================================================ */

/* 현재 식별자와 어휘적 스코프 레벨 */
extern A_ID *current_id;
extern int current_level;

/* 기본 표준 타입 */
extern A_TYPE *int_type;
extern A_TYPE *float_type;
extern A_TYPE *char_type;
extern A_TYPE *void_type;
extern A_TYPE *string_type;

/* ============================================================
 * 3. 초기화
 * ============================================================ */

void initialize(void);

/* 초기화 과정에서 사용하는 기본 타입 생성 */
A_TYPE *makeType(T_KIND kind);

/* ============================================================
 * 4. 심볼 테이블 및 스코프 관리
 * ============================================================ */

/* 식별자 생성 및 검색 */
A_ID *makeIdentifier(char *name);

A_ID *searchIdentifier(const char *name);
A_ID *searchIdentifierAtCurrentLevel(const char *name, A_ID *start);

/* 어휘적 스코프 진입 및 종료 */
void enterScope(void);
void leaveScope(void);

/* 의미 오류 처리 및 선언 목록 연결 */
void semanticError(const char *message);
A_ID *linkDeclaratorList(A_ID *head, A_ID *tail);

/* ============================================================
 * 5. 타입 구성
 * ============================================================ */

A_TYPE *setTypeElementType(A_TYPE *t1, A_TYPE *t2);

A_ID *setDeclaratorElementType(A_ID *id, A_TYPE *type);

// T_ARRAY -> expr 연결함
A_TYPE *setTypeExpr(A_TYPE *type, A_NODE *expr);

// A_TYPE -> A_ID 타입 테이블에 식별자 목록 연결함
// e.g) struct 선언 및 멤버 선언
A_TYPE *setTypeField(A_TYPE *type, A_ID *field);

/* ============================================================
 * 6. 선언 및 의미 동작
 * ============================================================ */

/* 선언 지정자 생성 및 정규화 */
// 저장 클래스랑 식별자를 하나로 묶음A
// e.g) static int a;
A_SPECIFIER *makeSpecifier(A_TYPE *type, S_KIND stor);

A_SPECIFIER *updateSpecifier(A_SPECIFIER *specifier, A_TYPE *type, S_KIND stor);

// 기본 타입(int)로 설정함
void setDefaultSpecifier(A_SPECIFIER *specifier);

/* 선언자, 함수 및 매개변수 처리 */
A_ID *setDeclaratorListSpecifier(A_ID *id, A_SPECIFIER *specifier);
A_ID *setStructDeclaratorListSpecifier(A_ID *id, A_TYPE *type);
A_ID *setFunctionDeclaratorSpecifier(A_ID *id, A_SPECIFIER *specifier);

A_ID *setFunctionDeclaratorBody(A_ID *id, A_NODE *body);
A_ID *setParameterDeclaratorSpecifier(A_ID *id, A_SPECIFIER *specifier);

/* 선언 시점의 식별자 및 타입 결정 */
A_ID *getIdentifierDeclared(const char *name);
A_ID *makeDummyIdentifier(void);

A_TYPE *setTypeNameSpecifier(A_TYPE *type, A_SPECIFIER *specifier);

A_TYPE *setTypeStructOrEnumIdentifier(T_KIND kind, char *name, ID_KIND id_kind);
A_TYPE *getTypeOfStructOrEnumIdentifier(T_KIND kind, char *name, ID_KIND id_kind);

A_ID *setDeclaratorKind(A_ID *id, ID_KIND kind);

/* ============================================================
 * 7. 오류 처리 및 보조 기능
 * ============================================================ */

/* 지연된 의미 검증 */
void checkForwardReference(void);
#endif // !SEMANTIC_H
