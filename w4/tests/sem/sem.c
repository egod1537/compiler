#include <stdio.h>

/* 타입 테이블 생성, T_KIND 설정 및 초기 필드 값 검증 */
void SEM_MakeType(void);
/* 식별자 생성, 이름 저장 및 심볼 테이블 prev 연결 검증 */
void SEM_MakeIdentifier(void);
/* 식별자 검색, 스코프 내 이름 가림 및 중복 검색 검증 */
void SEM_SearchIdentifier(void);
/* 스코프 진입/종료에 따른 레벨과 검색 가능 식별자 변경 검증 */
void SEM_Scope(void);
/* 선언자 link 목록 연결 및 prev 심볼 테이블 체인 보존 검증 */
void SEM_LinkDeclaratorList(void);
/* 포인터/배열 타입 체인 끝에 원소 타입 연결 검증 */
void SEM_SetTypeElementType(void);
/* 선언자의 타입 설정, 중첩 타입 연결 및 NULL 처리 검증 */
void SEM_SetDeclaratorElementType(void);
/* 배열 크기 수식 연결 및 크기 생략 배열 처리 검증 */
void SEM_SetTypeExpr(void);
/* 구조체 필드와 함수 매개변수 목록의 타입 테이블 연결 검증 */
void SEM_SetTypeField(void);
/* 타입과 저장 클래스를 결합한 선언 지정자 생성 검증 */
void SEM_MakeSpecifier(void);
/* 기존 선언 지정자에 타입 또는 저장 클래스 정보 추가 검증 */
void SEM_UpdateSpecifier(void);
/* 타입 생략 시 기본 int 타입 설정 및 기존 타입 유지 검증 */
void SEM_SetDefaultSpecifier(void);
/* 기본 타입, 내장 함수 및 전역 식별자 초기화 검증 */
void SEM_Initialize(void);
/* 일반 선언의 최종 타입, 종류, 저장 클래스 및 스코프 처리 검증 */
void SEM_SetDeclaratorListSpecifier(void);
/* 함수 프로토타입, 함수 정의 및 매개변수 타입 연결 검증 */
void SEM_SetFunctionDeclaratorSpecifier(void);
/* 함수 본문 AST 연결, 함수 종류 및 타입 유지 검증 */
void SEM_SetFunctionDeclaratorBody(void);
/* 매개변수 타입, 포인터, 익명 void, 스코프 및 목록 연결 검증 */
void SEM_SetParameterDeclaratorSpecifier(void);

int main(void) {
  SEM_MakeType();
  SEM_MakeIdentifier();
  SEM_SearchIdentifier();
  SEM_Scope();
  SEM_LinkDeclaratorList();
  SEM_SetTypeElementType();
  SEM_SetDeclaratorElementType();
  SEM_SetTypeExpr();
  SEM_SetTypeField();
  SEM_MakeSpecifier();
  SEM_UpdateSpecifier();
  SEM_SetDefaultSpecifier();
  SEM_Initialize();
  SEM_SetDeclaratorListSpecifier();
  SEM_SetFunctionDeclaratorSpecifier();
  SEM_SetFunctionDeclaratorBody();
  SEM_SetParameterDeclaratorSpecifier();

  printf("testScope passed\n");
  return 0;
}

