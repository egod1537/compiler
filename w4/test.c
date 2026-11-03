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

  printf("testScope passed\n");
  return 0;
}
