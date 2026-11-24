#ifndef SEMANTIC_H
#define SEMANTIC_H

/* ============================================================
 * 1. 타입 및 상수
 * ============================================================ */

#include "type.h"

/* ============================================================
 * 2. 전역 상태
 * ============================================================ */

// 현재 식별자 목록의 시작점, 현재 스코프 레벨
extern A_ID *current_id;
extern int current_level;
extern int line_no;
extern int syntax_err;

// 기본 타입 테이블
extern A_TYPE *int_type;
extern A_TYPE *float_type;
extern A_TYPE *char_type;
extern A_TYPE *void_type;
extern A_TYPE *string_type;

/* ============================================================
 * 3. 초기화
 * ============================================================ */

// 컴파일러 의미 분석 환경 초기화
// - 기본 타입 및 내장 식별자 등록
// - 심볼 테이블, 스코프 상태 초기화
void initialize(void);
// 타입 테이블 생성
// - 지정된 T_KIND에 대응하는 A_TYPE 생성
A_TYPE *makeType(T_KIND kind);

/* ============================================================
 * 4. 심볼 테이블 및 스코프 관리
 * ============================================================ */

// 식별자 생성
// - 심볼 테이블에 새로운 명칭 등록
// - 현재 스코프 레벨 부여
// - 기존 식별자와 prev 연결
A_ID *makeIdentifier(char *name);

// 식별자 검색
// - 현재 사용 가능한 스코프에서 명칭 검색
A_ID *searchIdentifier(const char *name);

// 현재 레벨의 식별자 검색
// - start부터 이전 선언들을 탐색
// - 동일 레벨의 중복 선언 확인
A_ID *searchIdentifierAtCurrentLevel(const char *name, A_ID *start);

// 스코프 진입
// - current_level 증가
void enterScope(void);

// 스코프 종료
// - 현재 레벨의 식별자를 검색 대상에서 제외
// - current_level 감소
void leaveScope(void);

// 컴파일러 내부 상태 오류 처리
void semanticError(const char *message);

// 강의자료의 선언 오류 번호를 유지한 오류 처리
void syntax_error(int code, const char *name);

// 선언자 목록 연결
// - 두 식별자 목록을 하나로 연결
A_ID *linkDeclaratorList(A_ID *head, A_ID *tail);

/* ============================================================
 * 5. 타입 구성
 * ============================================================ */

// 타입 합성
// - t1의 최하위 원소 타입에 t2 연결
// - 포인터, 배열, 함수 등의 복합 타입 구성
A_TYPE *setTypeElementType(A_TYPE *t1, A_TYPE *t2);

// 선언자의 타입 구성
// - 선언자가 가진 타입 구조에 원소 타입 연결
// - 포인터, 배열, 함수 선언자 처리
A_ID *setDeclaratorElementType(A_ID *id, A_TYPE *type);

// 타입의 수식 정보 설정
// - 배열의 크기 수식 등을 expr 필드에 연결
A_TYPE *setTypeExpr(A_TYPE *type, A_NODE *expr);

// 타입의 식별자 목록 설정
// - 구조체/공용체의 필드 목록 연결
// - 함수의 매개변수 목록 연결
A_TYPE *setTypeField(A_TYPE *type, A_ID *field);

/* ============================================================
 * 6. 선언 및 의미 동작
 * ============================================================ */

// 선언 지정자 생성
// - 타입 지정자를 선언 지정자 객체로 구성
// - A_SPECIFIER 테이블 생성
A_SPECIFIER *makeSpecifier(A_TYPE *type);

// 기본 선언 지정자 설정
// - 타입이 생략된 경우 기본 타입(int) 설정
void setDefaultSpecifier(A_SPECIFIER *specifier);

// 일반 선언문 분석
// - 선언자 목록의 중복 선언 검사
// - 각 명칭의 최종 타입 구성
// - 명칭 종류 결정 (ID_FUNC, ID_VAR)
A_ID *setDeclaratorListSpecifier(A_ID *id, A_SPECIFIER *specifier);

// 구조체 필드 선언 분석
// - 필드 명칭의 중복 선언 검사
// - 필드의 최종 타입 구성
// - 명칭 종류를 ID_FIELD로 설정
A_ID *setStructDeclaratorListSpecifier(A_ID *id, A_TYPE *type);

// 함수 정의 분석
// - 함수 명칭의 중복 선언 검사
// - 함수 반환 타입 결정
// - 함수 선언자 여부 검사
// - 기존 프로토타입의 반환 타입, 매개변수 검사
// - 매개변수 스코프 조정
A_ID *setFunctionDeclaratorSpecifier(A_ID *id, A_SPECIFIER *specifier);

// 함수 본문 연결
// - 함수 타입 테이블의 expr 필드에 AST 연결
A_ID *setFunctionDeclaratorBody(A_ID *id, A_NODE *body);

// 매개변수 선언 분석
// - 매개변수 명칭의 중복 선언 검사
// - void 타입 사용 검사
// - 매개변수의 최종 타입 구성
// - 명칭 종류를 ID_PARM으로 설정
A_ID *setParameterDeclaratorSpecifier(A_ID *id, A_SPECIFIER *specifier);

// 선언된 식별자 검색
// - 사용 가능한 스코프에서 명칭 검색
// - 미선언 식별자 검사
A_ID *getIdentifierDeclared(const char *name);

// 이름 없는 식별자 생성
// - 추상 선언자 및 이름 없는 매개변수 처리
A_ID *makeDummyIdentifier(void);

// 타입 명칭 구성
// - 선언 지정자와 추상 선언자 타입 결합
// - 캐스팅, sizeof 등의 타입 명칭 처리
A_TYPE *setTypeNameSpecifier(A_TYPE *type, A_SPECIFIER *specifier);

// 구조체/나열형 명칭 정의
// - 기존 선언 및 전방 참조 여부 검사
// - 새로운 명칭의 심볼 테이블 등록
// - 타입 테이블 생성 및 연결
A_TYPE *setTypeStructOrEnumIdentifier(T_KIND kind, char *name, ID_KIND id_kind);

// 구조체/나열형 명칭 참조
// - 기존 태그 명칭 및 타입 검사
// - 미선언 명칭의 전방 참조 처리
// - 타입 테이블 반환
A_TYPE *getTypeOfStructOrEnumIdentifier(T_KIND kind, char *name, ID_KIND id_kind);

// 식별자 종류 설정
// - 동일 스코프의 명칭 중복 검사
// - ID_KIND 값 결정
A_ID *setDeclaratorKind(A_ID *id, ID_KIND kind);

/* ============================================================
 * 7. 오류 처리 및 보조 기능
 * ============================================================ */

// 전방 참조 검사
// - 현재 스코프의 불완전 선언 검사
// - 미정의 명칭 및 불완전 구조체 검사
void checkForwardReference(void);

#endif // !SEMANTIC_H
