#include "semantic.h"
#include "type.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SEM_01_MakeType(void) {
  A_TYPE *t = makeType(T_POINTER);

  assert(t != NULL);
  assert(t->kind == T_POINTER);
  assert(t->element_type == NULL);


  free(t);
}

void SEM_06_SetTypeElementType(void) {
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

}

void SEM_08_SetTypeExpr(void) {
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

}

void SEM_09_SetTypeField(void) {
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

}

