#include "semantic.h"
#include "sem_test_support.h"
#include "type.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SEM_07_SetDeclaratorElementType(void) {
  assert(current_id == NULL);
  assert(current_level == 0);

  A_ID *p = makeIdentifier("p");

  A_TYPE *pointer1 = makeType(T_POINTER);
  A_TYPE *pointer2 = makeType(T_POINTER);
  A_TYPE *int_type = makeType(T_ENUM);

  // 1. 처음 타입 연결
  A_ID *result = setDeclaratorElementType(p, pointer1);

  assert(result == p);
  assert(p->type == pointer1);
  assert(pointer1->element_type == NULL);

  // 2. 기존 타입 체인의 마지막에 연결
  setDeclaratorElementType(p, pointer2);
  setDeclaratorElementType(p, int_type);

  assert(p->type == pointer1);
  assert(pointer1->element_type == pointer2);
  assert(pointer2->element_type == int_type);
  assert(int_type->element_type == NULL);

  // 3. NULL 타입 처리
  result = setDeclaratorElementType(p, NULL);

  assert(result == p);
  assert(p->type == pointer1);
  assert(pointer2->element_type == int_type);

  // 메모리 해제
  free(pointer1);
  free(pointer2);
  free(int_type);
  free(p->name);
  free(p);

  current_id = NULL;

}

void SEM_10_MakeSpecifier(void) {
  A_TYPE *int_type = makeType(T_ENUM);

  // 1. 타입만 있는 선언: int a;
  A_SPECIFIER *s1 = makeSpecifier(int_type);

  assert(s1 != NULL);
  assert(s1->type == int_type);
  assert(s1->stor == S_NULL);
  assert(s1->line == line_no);

  // 2. 타입이 생략된 선언 지정자
  A_SPECIFIER *s2 = makeSpecifier(NULL);

  assert(s2 != NULL);
  assert(s2->type == NULL);
  assert(s2->stor == S_NULL);

  // 3. 서로 독립적인 객체인지 확인
  assert(s1 != s2);

  free(s1);
  free(s2);
  free(int_type);

}

void SEM_11_SpecifierIndependence(void) {
  A_TYPE *first_type = makeType(T_ENUM);
  A_TYPE *second_type = makeType(T_POINTER);
  A_SPECIFIER *first = makeSpecifier(first_type);
  A_SPECIFIER *second = makeSpecifier(second_type);

  assert(first != second);
  assert(first->type == first_type);
  assert(second->type == second_type);
  assert(first->stor == S_NULL);
  assert(second->stor == S_NULL);

  free(first);
  free(second);
  free(first_type);
  free(second_type);
}

void SEM_12_SetDefaultSpecifier(void) {
  // 아직 initialize()를 구현하지 않았으므로
  // 테스트에서 기본 int 타입을 임시 생성
  int_type = makeType(T_ENUM);

  // 1. 타입이 없는 경우 기본 int 적용
  A_SPECIFIER *s1 = makeSpecifier(NULL);

  setDefaultSpecifier(s1);

  assert(s1->type == int_type);
  assert(s1->stor == S_NULL);

  // 2. 타입이 이미 지정된 경우 유지
  A_TYPE *char_type = makeType(T_ENUM);
  A_SPECIFIER *s2 = makeSpecifier(char_type);

  setDefaultSpecifier(s2);

  assert(s2->type == char_type);
  assert(s2->type != int_type);

  // 3. 타입이 없는 다른 선언 지정자
  A_SPECIFIER *s3 = makeSpecifier(NULL);

  setDefaultSpecifier(s3);

  assert(s3->type == int_type);
  assert(s3->stor == S_NULL);

  // 메모리 해제
  free(s1);
  free(s2);
  free(s3);
  free(char_type);
  free(int_type);

  int_type = NULL;

}

void SEM_14_SetDeclaratorListSpecifier(void) {
  assert(current_id == NULL);
  assert(current_level == 0);
  assert(int_type == NULL);

  initialize();

  // 1. int a, *p;
  A_ID *a = makeIdentifier("a");
  A_ID *p = makeIdentifier("p");

  setDeclaratorElementType(p, makeType(T_POINTER));

  A_ID *list = linkDeclaratorList(a, p);
  A_SPECIFIER *specifier = makeSpecifier(int_type);

  A_ID *result = setDeclaratorListSpecifier(list, specifier);

  assert(result == a);

  assert(a->kind == ID_VAR);
  assert(a->type == int_type);
  assert(a->specifier == S_NULL);

  assert(p->kind == ID_VAR);
  assert(p->type->kind == T_POINTER);
  assert(p->type->element_type == int_type);
  assert(p->specifier == S_NULL);

  // 2. int value;
  A_ID *value = makeIdentifier("value");
  A_SPECIFIER *default_spec = makeSpecifier(int_type);

  setDeclaratorListSpecifier(value, default_spec);

  assert(value->kind == ID_VAR);
  assert(value->type == int_type);
  assert(value->specifier == S_NULL);

  // 3. 다른 스코프에서 동일 명칭 선언
  enterScope();

  A_ID *local_a = makeIdentifier("a");
  A_SPECIFIER *local_spec = makeSpecifier(int_type);

  setDeclaratorListSpecifier(local_a, local_spec);

  assert(local_a->kind == ID_VAR);
  assert(local_a->type == int_type);
  assert(local_a->level == 1);
  assert(searchIdentifier("a") == local_a);

  leaveScope();

  assert(searchIdentifier("a") == a);

  // 4. 테스트에서 생성한 객체 해제
  free(specifier);
  free(default_spec);
  free(local_spec);

  free(local_a->name);
  free(local_a);

  // 기본 타입은 공유되므로 여기서 해제하지 않음
  free(p->type);

  semTestResetInitializedState();

}

void SEM_15_SetFunctionDeclaratorSpecifier(void) {
  assert(current_id == NULL);
  assert(current_level == 0);
  assert(int_type == NULL);

  /* 테스트용 기본 타입 */
  int_type = makeType(T_ENUM);

  /* 1. int foo(); 프로토타입 등록 */
  A_ID *prototype = makeIdentifier("foo");
  setDeclaratorElementType(prototype, makeType(T_FUNC));

  A_SPECIFIER *proto_spec = makeSpecifier(int_type);
  setDeclaratorListSpecifier(prototype, proto_spec);

  assert(prototype->kind == ID_FUNC);
  assert(prototype->type->element_type == int_type);

  /* 2. int foo() { ... } 함수 정의 분석 */
  A_ID *definition = makeIdentifier("foo");
  setDeclaratorElementType(definition, makeType(T_FUNC));

  A_SPECIFIER *def_spec = makeSpecifier(int_type);

  A_ID *result = setFunctionDeclaratorSpecifier(definition, def_spec);

  assert(result == definition);
  assert(definition->kind == ID_FUNC);
  assert(definition->type->kind == T_FUNC);
  assert(definition->type->element_type == int_type);

  /* 3. int bar(int x) { ... } */
  A_ID *bar = makeIdentifier("bar");

  A_TYPE *bar_type = makeType(T_FUNC);
  setDeclaratorElementType(bar, bar_type);

  A_ID *param = makeIdentifier("x");
  param->kind = ID_PARM;
  param->type = int_type;

  setTypeField(bar_type, param);

  A_SPECIFIER *bar_spec = makeSpecifier(int_type);

  result = setFunctionDeclaratorSpecifier(bar, bar_spec);

  assert(result == bar);
  assert(bar->kind == ID_FUNC);
  assert(bar->type->field == param);
  assert(bar->type->element_type == int_type);
  assert(searchIdentifier("x") == param);

  /* 테스트에서 생성한 객체 해제 */
  free(proto_spec);
  free(def_spec);
  free(bar_spec);

  semTestFreeIdentifierChain();

  free(int_type);
  int_type = NULL;

}

void SEM_16_SetFunctionDeclaratorBody(void) {
  assert(current_id == NULL);
  assert(current_level == 0);

  A_ID *fun = makeIdentifier("fun");

  A_TYPE *func_type = makeType(T_FUNC);
  setDeclaratorElementType(fun, func_type);

  // 함수 정의라고 가정
  fun->kind = ID_FUNC;

  // { return ...; } 에 해당하는 AST 루트
  A_NODE *body = calloc(1, sizeof(A_NODE));
  assert(body != NULL);

  body->name = N_STMT_COMPOUND;

  // 1. 몸체 연결
  A_ID *result = setFunctionDeclaratorBody(fun, body);

  assert(result == fun);
  assert(fun->type == func_type);
  assert(func_type->expr == body);

  // 2. AST가 변경되지 않았는지 확인
  assert(func_type->expr->name == N_STMT_COMPOUND);

  // 3. 함수 타입 유지 확인
  assert(fun->kind == ID_FUNC);
  assert(fun->type->kind == T_FUNC);

  // 메모리 해제
  free(body);
  free(func_type);
  free(fun->name);
  free(fun);

  current_id = NULL;

}

void SEM_17_SetParameterDeclaratorSpecifier(void) {
  assert(current_id == NULL);
  assert(current_level == 0);
  assert(int_type == NULL);

  initialize();

  enterScope();

  // 1. int a
  A_ID *a = makeIdentifier("a");
  A_SPECIFIER *s1 = makeSpecifier(int_type);

  A_ID *result = setParameterDeclaratorSpecifier(a, s1);

  assert(result == a);
  assert(a->kind == ID_PARM);
  assert(a->type == int_type);
  assert(a->level == 1);

  // 2. int *b
  A_ID *b = makeIdentifier("b");
  setDeclaratorElementType(b, makeType(T_POINTER));

  A_SPECIFIER *s2 = makeSpecifier(int_type);

  result = setParameterDeclaratorSpecifier(b, s2);

  assert(result == b);
  assert(b->kind == ID_PARM);
  assert(b->type->kind == T_POINTER);
  assert(b->type->element_type == int_type);

  // 3. 이름 없는 void 파라미터
  A_ID *anonymous = makeIdentifier("");
  A_SPECIFIER *s3 = makeSpecifier(void_type);
  int previous_errors = syntax_err;

  result = setParameterDeclaratorSpecifier(anonymous, s3);

  assert(syntax_err == previous_errors + 1);
  assert(result == anonymous);
  assert(anonymous->kind == ID_PARM);
  assert(anonymous->type == void_type);

  // 4. 이름 검색
  assert(searchIdentifier("a") == a);
  assert(searchIdentifier("b") == b);

  // 5. 파라미터 목록 연결
  A_ID *params = linkDeclaratorList(a, b);

  assert(params == a);
  assert(a->link == b);

  // 스코프 종료
  leaveScope();

  assert(current_level == 0);
  assert(searchIdentifier("a") == NULL);
  assert(searchIdentifier("b") == NULL);

  // 테스트 객체 해제
  free(s1);
  free(s2);
  free(s3);

  free(b->type);

  free(anonymous->name);
  free(anonymous);

  free(b->name);
  free(b);

  free(a->name);
  free(a);

  semTestResetInitializedState();

}

