#include "semantic.h"
#include "type.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testMakeType(void) {
  A_TYPE *t = makeType(T_POINTER);

  assert(t != NULL);
  assert(t->kind == T_POINTER);
  assert(t->element_type == NULL);

  printf("makeType test passed\n");

  free(t);
}

void testMakeIdentifier(void) {
  A_ID *a = makeIdentifier("a");
  A_ID *b = makeIdentifier("b");

  assert(strcmp(a->name, "a") == 0);
  assert(strcmp(b->name, "b") == 0);
  assert(b->prev == a);
  assert(current_id == b);
  assert(a->prev == NULL);
  assert(a->link == NULL);

  printf("makeIdentifier test passed\n");

  free(a);
  free(b);
}

void testSearchIdentifier(void) {
  current_id = NULL;
  current_level = 0;

  A_ID *global_x = makeIdentifier("x");
  A_ID *global_y = makeIdentifier("y");
  assert(searchIdentifier("x") == global_x);
  assert(searchIdentifier("y") == global_y);
  assert(searchIdentifier("z") == NULL);

  current_level = 1;

  A_ID *local_x = makeIdentifier("x");
  assert(searchIdentifier("x") == local_x);
  assert(searchIdentifierAtCurrentLevel("x", local_x->prev) == NULL);

  A_ID *duplicate_x = makeIdentifier("x");
  assert(searchIdentifierAtCurrentLevel("x", duplicate_x->prev) == local_x);

  printf("searchIdentifier test passed\n");

  A_ID *id = current_id;
  while (id != NULL) {
    A_ID *prev = id->prev;
    free(id->name);
    free(id);
    id = prev;
  }

  current_id = NULL;
  current_level = 0;
}

void testScope(void) {
  assert(current_level == 0);
  assert(current_id == NULL);

  A_ID *a = makeIdentifier("a");

  enterScope();
  assert(current_level == 1);

  A_ID *b = makeIdentifier("b");

  assert(current_id == b);
  assert(searchIdentifier("a") == a);
  assert(searchIdentifier("b") == b);

  enterScope();
  assert(current_level == 2);

  A_ID *c = makeIdentifier("c");

  assert(searchIdentifier("c") == c);

  leaveScope();

  assert(current_level == 1);
  assert(current_id == b);
  assert(searchIdentifier("c") == NULL);
  assert(searchIdentifier("b") == b);

  leaveScope();

  assert(current_level == 0);
  assert(current_id == a);
  assert(searchIdentifier("b") == NULL);
  assert(searchIdentifier("a") == a);

  free(c->name);
  free(c);
  free(b->name);
  free(b);
  free(a->name);
  free(a);

  current_id = NULL;

  printf("testScope passed\n");
}

void testLinkDeclaratorList(void) {
  assert(current_id == NULL);
  assert(current_level == 0);

  A_ID *a = makeIdentifier("a");
  A_ID *b = makeIdentifier("b");
  A_ID *c = makeIdentifier("c");

  A_ID *list = linkDeclaratorList(a, b);
  list = linkDeclaratorList(list, c);

  // 선언자 목록 연결 검증
  assert(list == a);
  assert(a->link == b);
  assert(b->link == c);
  assert(c->link == NULL);

  // 심볼 테이블 연결은 변경되지 않아야 함
  assert(current_id == c);
  assert(c->prev == b);
  assert(b->prev == a);
  assert(a->prev == NULL);

  // 빈 리스트 처리 검증
  assert(linkDeclaratorList(NULL, NULL) == NULL);
  assert(linkDeclaratorList(NULL, a) == a);
  assert(linkDeclaratorList(a, NULL) == a);

  // 메모리 해제
  free(c->name);
  free(c);
  free(b->name);
  free(b);
  free(a->name);
  free(a);

  current_id = NULL;

  printf("testLinkDeclaratorList passed\n");
}

void testSetTypeElementType(void) {
  A_TYPE *int_type = makeType(T_ENUM);
  A_TYPE *pointer1 = makeType(T_POINTER);
  A_TYPE *pointer2 = makeType(T_POINTER);

  // T_POINTER -> int_type
  A_TYPE *result = setTypeElementType(pointer1, int_type);

  assert(result == pointer1);
  assert(pointer1->element_type == int_type);

  // T_POINTER -> T_POINTER -> int_type
  result = setTypeElementType(pointer2, pointer1);

  assert(result == pointer2);
  assert(pointer2->element_type == pointer1);
  assert(pointer1->element_type == int_type);

  // 기존 체인의 마지막에 다른 타입 연결
  A_TYPE *array = makeType(T_ARRAY);
  A_TYPE *outer = makeType(T_POINTER);

  setTypeElementType(outer, array);
  setTypeElementType(outer, pointer2);

  assert(outer->element_type == array);
  assert(array->element_type == pointer2);
  assert(pointer2->element_type == pointer1);

  // 만들어진 타입 체인의 메모리 해제
  free(outer);
  free(array);
  free(pointer2);
  free(pointer1);
  free(int_type);

  printf("testSetTypeElementType passed\n");
}

void testSetDeclaratorElementType(void) {
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

  printf("testSetDeclaratorElementType passed\n");
}

void testSetTypeExpr(void) {
  A_TYPE *array = makeType(T_ARRAY);

  A_NODE size_expr = {0};
  size_expr.name = N_EXP_INT_CONST;
  size_expr.clink = (A_NODE *)(long)10;

  // 1. 배열 크기 수식 연결
  A_TYPE *result = setTypeExpr(array, &size_expr);

  assert(result == array);
  assert(array->kind == T_ARRAY);
  assert(array->expr == &size_expr);

  // 2. 원소 타입 연결
  A_TYPE *int_type = makeType(T_ENUM);

  setTypeElementType(array, int_type);

  assert(array->element_type == int_type);
  assert(array->expr == &size_expr);

  // 3. 크기가 생략된 배열
  A_TYPE *unsized_array = makeType(T_ARRAY);

  result = setTypeExpr(unsized_array, NULL);

  assert(result == unsized_array);
  assert(unsized_array->expr == NULL);

  // 메모리 해제
  free(unsized_array);
  free(int_type);
  free(array);

  printf("testSetTypeExpr passed\n");
}

void testSetTypeField(void) {
  assert(current_id == NULL);
  assert(current_level == 0);

  // 1. 구조체 타입 생성
  A_TYPE *struct_type = makeType(T_STRUCT);

  A_ID *x = makeIdentifier("x");
  A_ID *y = makeIdentifier("y");

  A_ID *fields = linkDeclaratorList(x, y);

  A_TYPE *result = setTypeField(struct_type, fields);

  assert(result == struct_type);
  assert(struct_type->kind == T_STRUCT);
  assert(struct_type->field == x);
  assert(struct_type->field->link == y);
  assert(y->link == NULL);

  // 2. 함수 타입의 파라미터 목록
  A_TYPE *func_type = makeType(T_FUNC);

  A_ID *param = makeIdentifier("param");

  result = setTypeField(func_type, param);

  assert(result == func_type);
  assert(func_type->field == param);

  // 3. 빈 파라미터 목록
  A_TYPE *empty_func = makeType(T_FUNC);

  result = setTypeField(empty_func, NULL);

  assert(result == empty_func);
  assert(empty_func->field == NULL);

  // 4. 기존 타입 체인에는 영향이 없는지 확인
  assert(struct_type->element_type == NULL);
  assert(func_type->element_type == NULL);

  // 메모리 해제
  free(empty_func);
  free(func_type);
  free(struct_type);

  free(param->name);
  free(param);
  free(y->name);
  free(y);
  free(x->name);
  free(x);

  current_id = NULL;
  current_level = 0;

  printf("testSetTypeField passed\n");
}

void testMakeSpecifier(void) {
  A_TYPE *int_type = makeType(T_ENUM);

  // 1. 타입만 있는 선언: int a;
  A_SPECIFIER *s1 = makeSpecifier(int_type, S_NULL);

  assert(s1 != NULL);
  assert(s1->type == int_type);
  assert(s1->stor == S_NULL);
  assert(s1->line == 0);

  // 2. 타입과 저장 클래스: static int b;
  A_SPECIFIER *s2 = makeSpecifier(int_type, S_STATIC);

  assert(s2 != NULL);
  assert(s2->type == int_type);
  assert(s2->stor == S_STATIC);

  // 3. 저장 클래스만 있는 상태
  A_SPECIFIER *s3 = makeSpecifier(NULL, S_TYPEDEF);

  assert(s3 != NULL);
  assert(s3->type == NULL);
  assert(s3->stor == S_TYPEDEF);

  // 4. 둘 다 지정되지 않은 상태
  A_SPECIFIER *s4 = makeSpecifier(NULL, S_NULL);

  assert(s4 != NULL);
  assert(s4->type == NULL);
  assert(s4->stor == S_NULL);

  // 5. 서로 독립적인 객체인지 확인
  assert(s1 != s2);
  assert(s2 != s3);
  assert(s3 != s4);

  // 6. 타입 객체는 공유되는지 확인
  assert(s1->type == s2->type);

  free(s1);
  free(s2);
  free(s3);
  free(s4);
  free(int_type);

  printf("testMakeSpecifier passed\n");
}

void testUpdateSpecifier(void) {
  A_TYPE *int_type = makeType(T_ENUM);

  // 1. 타입만 있는 명시자에 static 추가
  A_SPECIFIER *s1 = makeSpecifier(int_type, S_NULL);

  A_SPECIFIER *result = updateSpecifier(s1, NULL, S_STATIC);

  assert(result == s1);
  assert(s1->type == int_type);
  assert(s1->stor == S_STATIC);

  // 2. 저장 클래스만 있는 명시자에 타입 추가
  A_SPECIFIER *s2 = makeSpecifier(NULL, S_TYPEDEF);

  result = updateSpecifier(s2, int_type, S_NULL);

  assert(result == s2);
  assert(s2->type == int_type);
  assert(s2->stor == S_TYPEDEF);

  // 3. 아무 정보가 없는 명시자에 타입 추가
  A_SPECIFIER *s3 = makeSpecifier(NULL, S_NULL);

  updateSpecifier(s3, int_type, S_NULL);

  assert(s3->type == int_type);
  assert(s3->stor == S_NULL);

  // 4. 아무 정보가 없는 명시자에 static 추가
  A_SPECIFIER *s4 = makeSpecifier(NULL, S_NULL);

  updateSpecifier(s4, NULL, S_STATIC);

  assert(s4->type == NULL);
  assert(s4->stor == S_STATIC);

  // 5. 기존 명시자 객체를 재사용하는지 검증
  assert(s1 != s2);
  assert(s2 != s3);
  assert(s3 != s4);

  free(s1);
  free(s2);
  free(s3);
  free(s4);
  free(int_type);

  printf("testUpdateSpecifier passed\n");
}

void testSetDefaultSpecifier(void) {
  // 아직 initialize()를 구현하지 않았으므로
  // 테스트에서 기본 int 타입을 임시 생성
  int_type = makeType(T_ENUM);

  // 1. 타입이 없는 경우 기본 int 적용
  A_SPECIFIER *s1 = makeSpecifier(NULL, S_STATIC);

  setDefaultSpecifier(s1);

  assert(s1->type == int_type);
  assert(s1->stor == S_STATIC);

  // 2. 타입이 이미 지정된 경우 유지
  A_TYPE *char_type = makeType(T_ENUM);
  A_SPECIFIER *s2 = makeSpecifier(char_type, S_NULL);

  setDefaultSpecifier(s2);

  assert(s2->type == char_type);
  assert(s2->type != int_type);

  // 3. 타입과 저장 클래스 모두 없는 경우
  A_SPECIFIER *s3 = makeSpecifier(NULL, S_NULL);

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

  printf("testSetDefaultSpecifier passed\n");
}

void testInitialize(void) {
  assert(current_id == NULL);
  assert(current_level == 0);
  assert(int_type == NULL);

  initialize();

  // 기본 타입 생성 확인
  assert(int_type != NULL);
  assert(float_type != NULL);
  assert(char_type != NULL);
  assert(void_type != NULL);
  assert(string_type != NULL);

  assert(int_type->kind == T_ENUM);
  assert(float_type->kind == T_ENUM);
  assert(char_type->kind == T_ENUM);
  assert(void_type->kind == T_VOID);

  assert(string_type->kind == T_POINTER);
  assert(string_type->element_type == char_type);

  // 기본 타입 명칭 검색
  A_ID *id = searchIdentifier("int");
  assert(id != NULL);
  assert(id->kind == ID_TYPE);
  assert(id->type == int_type);

  id = searchIdentifier("float");
  assert(id != NULL);
  assert(id->type == float_type);

  id = searchIdentifier("char");
  assert(id != NULL);
  assert(id->type == char_type);

  id = searchIdentifier("void");
  assert(id != NULL);
  assert(id->type == void_type);

  // 기본 함수 검색
  id = searchIdentifier("printf");
  assert(id != NULL);
  assert(id->kind == ID_FUNC);
  assert(id->type->kind == T_FUNC);
  assert(id->type->element_type == int_type);

  id = searchIdentifier("scanf");
  assert(id != NULL);
  assert(id->kind == ID_FUNC);

  // 모든 기본 명칭은 전역 레벨에 등록됨
  assert(id->level == 0);

  // 테스트 전역 상태 정리
  A_ID *current = current_id;

  while (current != NULL) {
    A_ID *prev = current->prev;

    if (current->kind == ID_FUNC)
      free(current->type);

    free(current->name);
    free(current);
    current = prev;
  }

  current_id = NULL;

  free(string_type);
  free(void_type);
  free(char_type);
  free(float_type);
  free(int_type);

  string_type = NULL;
  void_type = NULL;
  char_type = NULL;
  float_type = NULL;
  int_type = NULL;

  printf("testInitialize passed\n");
}

void testSetDeclaratorListSpecifier(void) {
  assert(current_id == NULL);
  assert(current_level == 0);
  assert(int_type == NULL);

  initialize();

  // 1. static int a, *p;
  A_ID *a = makeIdentifier("a");
  A_ID *p = makeIdentifier("p");

  setDeclaratorElementType(p, makeType(T_POINTER));

  A_ID *list = linkDeclaratorList(a, p);
  A_SPECIFIER *specifier = makeSpecifier(int_type, S_STATIC);

  A_ID *result = setDeclaratorListSpecifier(list, specifier);

  assert(result == a);

  assert(a->kind == ID_VAR);
  assert(a->type == int_type);
  assert(a->specifier == S_STATIC);

  assert(p->kind == ID_VAR);
  assert(p->type->kind == T_POINTER);
  assert(p->type->element_type == int_type);
  assert(p->specifier == S_STATIC);

  // 2. typedef int NUMBER;
  A_ID *number = makeIdentifier("NUMBER");
  A_SPECIFIER *typedef_spec = makeSpecifier(int_type, S_TYPEDEF);

  setDeclaratorListSpecifier(number, typedef_spec);

  assert(number->kind == ID_TYPE);
  assert(number->type == int_type);
  assert(number->specifier == S_TYPEDEF);

  // 3. int value; (저장 클래스 기본값)
  A_ID *value = makeIdentifier("value");
  A_SPECIFIER *default_spec = makeSpecifier(int_type, S_NULL);

  setDeclaratorListSpecifier(value, default_spec);

  assert(value->kind == ID_VAR);
  assert(value->type == int_type);
  assert(value->specifier == S_AUTO);

  // 4. 다른 스코프에서 동일 명칭 선언
  enterScope();

  A_ID *local_a = makeIdentifier("a");
  A_SPECIFIER *local_spec = makeSpecifier(int_type, S_NULL);

  setDeclaratorListSpecifier(local_a, local_spec);

  assert(local_a->kind == ID_VAR);
  assert(local_a->type == int_type);
  assert(local_a->level == 1);
  assert(searchIdentifier("a") == local_a);

  leaveScope();

  assert(searchIdentifier("a") == a);

  // 5. 테스트에서 생성한 객체 해제
  free(specifier);
  free(typedef_spec);
  free(default_spec);
  free(local_spec);

  free(local_a->name);
  free(local_a);

  // 기본 타입은 공유되므로 여기서 해제하지 않음
  free(p->type);

  // 전역 심볼 체인 해제
  A_ID *current = current_id;

  while (current != NULL) {
    A_ID *prev = current->prev;

    if (current->kind == ID_FUNC)
      free(current->type);

    free(current->name);
    free(current);
    current = prev;
  }

  current_id = NULL;

  free(string_type);
  free(void_type);
  free(char_type);
  free(float_type);
  free(int_type);

  string_type = NULL;
  void_type = NULL;
  char_type = NULL;
  float_type = NULL;
  int_type = NULL;

  printf("testSetDeclaratorListSpecifier passed\n");
}

void testSetFunctionDeclaratorSpecifier(void) {
  assert(current_id == NULL);
  assert(current_level == 0);
  assert(int_type == NULL);

  /* 테스트용 기본 타입 */
  int_type = makeType(T_ENUM);

  /* 1. int foo(); 프로토타입 등록 */
  A_ID *prototype = makeIdentifier("foo");
  setDeclaratorElementType(prototype, makeType(T_FUNC));

  A_SPECIFIER *proto_spec = makeSpecifier(int_type, S_NULL);
  setDeclaratorListSpecifier(prototype, proto_spec);

  assert(prototype->kind == ID_FUNC);
  assert(prototype->type->element_type == int_type);

  /* 2. int foo() { ... } 함수 정의 분석 */
  A_ID *definition = makeIdentifier("foo");
  setDeclaratorElementType(definition, makeType(T_FUNC));

  A_SPECIFIER *def_spec = makeSpecifier(int_type, S_NULL);

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

  A_SPECIFIER *bar_spec = makeSpecifier(int_type, S_NULL);

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

  A_ID *id = current_id;

  while (id != NULL) {
    A_ID *prev = id->prev;

    if (id->kind == ID_FUNC)
      free(id->type);

    free(id->name);
    free(id);
    id = prev;
  }

  current_id = NULL;

  free(int_type);
  int_type = NULL;

  printf("testSetFunctionDeclaratorSpecifier passed\n");
}

void testSetFunctionDeclaratorBody(void) {
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

  printf("testSetFunctionDeclaratorBody passed\n");
}

void testSetParameterDeclaratorSpecifier(void) {
  assert(current_id == NULL);
  assert(current_level == 0);
  assert(int_type == NULL);

  initialize();

  enterScope();

  // 1. int a
  A_ID *a = makeIdentifier("a");
  A_SPECIFIER *s1 = makeSpecifier(int_type, S_NULL);

  A_ID *result = setParameterDeclaratorSpecifier(a, s1);

  assert(result == a);
  assert(a->kind == ID_PARM);
  assert(a->type == int_type);
  assert(a->level == 1);

  // 2. int *b
  A_ID *b = makeIdentifier("b");
  setDeclaratorElementType(b, makeType(T_POINTER));

  A_SPECIFIER *s2 = makeSpecifier(int_type, S_NULL);

  result = setParameterDeclaratorSpecifier(b, s2);

  assert(result == b);
  assert(b->kind == ID_PARM);
  assert(b->type->kind == T_POINTER);
  assert(b->type->element_type == int_type);

  // 3. 이름 없는 void 파라미터
  A_ID *anonymous = makeIdentifier("");
  A_SPECIFIER *s3 = makeSpecifier(void_type, S_NULL);

  result = setParameterDeclaratorSpecifier(anonymous, s3);

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

  // initialize()에서 생성한 전역 심볼 해제
  A_ID *current = current_id;

  while (current != NULL) {
    A_ID *prev = current->prev;

    if (current->kind == ID_FUNC)
      free(current->type);

    free(current->name);
    free(current);
    current = prev;
  }

  current_id = NULL;

  free(string_type);
  free(void_type);
  free(char_type);
  free(float_type);
  free(int_type);

  string_type = NULL;
  void_type = NULL;
  char_type = NULL;
  float_type = NULL;
  int_type = NULL;

  printf("testSetParameterDeclaratorSpecifier passed\n");
}

int main(void) {
  testMakeType();
  testMakeIdentifier();
  testSearchIdentifier();
  testScope();
  testLinkDeclaratorList();
  testSetTypeElementType();
  testSetDeclaratorElementType();
  testSetTypeExpr();
  testSetTypeField();
  testMakeSpecifier();
  testUpdateSpecifier();
  testSetDefaultSpecifier();
  testInitialize();
  testSetDeclaratorListSpecifier();
  testSetFunctionDeclaratorSpecifier();
  testSetFunctionDeclaratorBody();
  testSetParameterDeclaratorSpecifier();

  printf("testScope passed\n");
  return 0;
}
