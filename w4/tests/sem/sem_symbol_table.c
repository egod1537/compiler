#include "semantic.h"
#include "type.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SEM_testMakeIdentifier(void) {
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

void SEM_testSearchIdentifier(void) {
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

void SEM_testLinkDeclaratorList(void) {
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

void SEM_testInitialize(void) {
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

