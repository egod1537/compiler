
#ifndef AST_ASSERT_H
#define AST_ASSERT_H

#include "../../type.h"

/* 연산자 우선순위에 맞게 AST가 구성되는지 검증. e.g) 1 + 2 * 3 */
void AST_checkPrecedence(A_NODE *node);

/* 괄호에 의해 연산자 결합 순서가 변경되는지 검증. e.g) (1 + 2) * 3 */
void AST_checkParentheses(A_NODE *root);

/* 식별자 AST가 올바른 심볼 테이블 항목과 타입을 참조하는지 검증 */
void AST_checkIdentifierAST(A_NODE *root);

/* 단일 및 다중 포인터 선언의 타입 체인 검증. e.g) int *p, **pp; */
void AST_checkPointerDeclaration(void);

/* 포인터 역참조 연산자의 AST 구조 검증. e.g) *p */
void AST_checkPointerDereference(A_NODE *root);

/* 주소 연산자의 AST 구조 검증. e.g) &x */
void AST_checkAddressOf(A_NODE *root);

/* 단항 음수 연산자의 AST 구조 검증. e.g) -x */
void AST_checkUnaryMinus(A_NODE *root);

/* 논리 부정 연산자의 AST 구조 검증. e.g) !x */
void AST_checkLogicalNot(A_NODE *root);

/* 전위 증가 연산자의 AST 구조 검증. e.g) ++x */
void AST_checkPreIncrement(A_NODE *root);

/* 전위 감소 연산자의 AST 구조 검증. e.g) --x */
void AST_checkPreDecrement(A_NODE *root);

/* 후위 증가 연산자의 AST 구조 검증. e.g) x++ */
void AST_checkPostIncrement(A_NODE *root);

/* 후위 감소 연산자의 AST 구조 검증. e.g) x-- */
void AST_checkPostDecrement(A_NODE *root);

/* 배열 인덱스 접근의 AST 구조 검증. e.g) a[i] */
void AST_checkArrayAccess(A_NODE *root);

/* 배열 선언의 타입과 크기 수식 연결 검증. e.g) int a[10]; */
void AST_checkArrayDeclaration(void);

/* 함수 선언자의 타입, 반환 타입 및 함수 구조 검증 */
void AST_checkFunctionDeclarator(void);

/* 함수 매개변수 목록의 개수, 타입 및 연결 구조 검증 */
void AST_checkFunctionParameters(void);

/* return 명령문의 AST 구조와 반환 수식 연결 검증 */
void AST_checkReturn(A_NODE *root);

/* 복합문 내부의 return 명령문 AST 구조 검증 */
void AST_checkCompoundReturn(A_NODE *root);

/* 함수 매개변수와 지역 식별자의 스코프 처리 검증 */
void AST_checkFunctionScope(void);

/* 중첩 블록에서 동일한 이름의 식별자 가림 처리 검증 */
void AST_checkBlockShadowing(void);

/* 대입 연산자의 AST 구조 검증. e.g) a = b */
void AST_checkAssignment(void);

/* 비교 연산자의 종류와 좌우 피연산자 검증 */
void AST_checkComparison(A_NODE *root, NODE_NAME expected, int lhs, int rhs);

/* 논리 연산자의 AST 구조 검증. mode에 따라 검사 대상 구분 */
void AST_checkLogical(A_NODE *root, int mode);

/* if, if-else 등 선택문의 AST 구조 검증 */
void AST_checkSelection(int mode);

/* while, do-while, for 등 반복문의 AST 구조 검증 */
void AST_checkIteration(int mode);

/* break, continue 명령문의 AST 노드 구성 검증 */
void AST_checkBreakContinue(void);

/* 반환값이 없는 return 명령문의 AST 구조 검증. e.g) return; */
void AST_checkVoidReturn(void);

/* 함수 호출 수식과 인자 목록의 AST 구조 검증 */
void AST_checkFunctionCall(void);

/* 수식에 대한 sizeof 연산자의 AST 구조 검증. e.g) sizeof(x) */
void AST_checkSizeofExpression(void);

/* 타입에 대한 sizeof 연산자의 AST 구조 검증. e.g) sizeof(int) */
void AST_checkSizeofType(void);

/* 명시적 형변환 수식의 AST 구조 검증. e.g) (int)x */
void AST_checkCastExpression(void);

/* switch, case, default 명령문의 AST 구조 검증 */
void AST_checkSwitch(void);

/* 문자 상수와 문자열 리터럴의 AST 구성 검증 */
void AST_checkCharString(void);

/* 프로그램 루트 노드와 전역 선언 목록 연결 검증 */
void AST_checkProgram(A_NODE *root);

/* 구조체 선언 및 필드 참조의 AST 구성 검증. mode별로 검사 구분 */
void AST_checkStruct(int mode);

#endif // !AST_ASSERT_H
