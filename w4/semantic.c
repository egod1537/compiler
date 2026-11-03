#include "semantic.h"
#include "type.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

A_ID *current_id = NULL;
int current_level = 0;

A_TYPE *makeType(T_KIND kind) {
  A_TYPE *t = calloc(1, sizeof(A_TYPE));

  if (t == NULL) {
    semanticError("memory allocation failed");
  }

  t->kind = kind;

  return t;
}

A_ID *makeIdentifier(char *name) {
  A_ID *id = calloc(1, sizeof(A_ID));

  if (id == NULL) {
    semanticError("memory allocation failed");
  }

  id->name = malloc(strlen(name) + 1);

  if (id->name == NULL) {
    semanticError("memory allocation failed");
  }

  strcpy(id->name, name);

  id->level = current_level;
  id->prev = current_id;
  current_id = id;

  return id;
}

A_ID *searchIdentifier(const char *name) {
  A_ID *id = current_id;

  while (id != NULL) {
    if (strcmp(id->name, name) == 0)
      return id;

    id = id->prev;
  }

  return NULL;
}

A_ID *searchIdentifierAtCurrentLevel(const char *name, A_ID *start) {
  A_ID *id = start;

  while (id != NULL) {
    if (id->level < current_level)
      break;

    if (id->level == current_level && strcmp(id->name, name) == 0)
      return id;

    id = id->prev;
  }

  return NULL;
}

// Scope 관리 로직
typedef struct s_scope_frame {
  A_ID *saved_id;
  struct s_scope_frame *prev;
} ScopreFrame;

static ScopreFrame *scope_stack = NULL;

void enterScope(void) {
  ScopreFrame *frame = malloc(sizeof(ScopreFrame));

  if (frame == NULL) {
    semanticError("memory allocation failed");
  }

  frame->saved_id = current_id;
  frame->prev = scope_stack;

  scope_stack = frame;
  current_level++;
}

void leaveScope(void) {
  if (scope_stack == NULL) {
    semanticError("scope stack underflow");
  }

  ScopreFrame *frame = scope_stack;

  current_id = frame->saved_id;
  current_level--;

  scope_stack = frame->prev;
  free(frame);
}

void semanticError(const char *message) {
  fprintf(stderr, "Semantic error: %s\n", message);
  exit(EXIT_FAILURE);
}

// head 뒤에 tail 연결함. insert(head.end(), v.begin(), v.end()) 느낌?
// A_ID -> A_ID
A_ID *linkDeclaratorList(A_ID *head, A_ID *tail) {
  if (head == NULL)
    return tail;

  if (tail == NULL)
    return head;

  A_ID *current = head;

  while (current->link != NULL)
    current = current->link;

  current->link = tail;

  return head;
}

// linkDeclaratorList type 버전, 뒤에 다가 연결한다
// A_TYPE -> A_TYPE
A_TYPE *setTypeElementType(A_TYPE *t1, A_TYPE *t2) {
  if (t1 == NULL)
    semanticError("Null type in setTypeElementType");

  A_TYPE *current = t1;

  while (current->element_type != NULL)
    current = current->element_type;

  current->element_type = t2;

  return t1;
}

A_ID *setDeclaratorElementType(A_ID *id, A_TYPE *type) {
  if (id == NULL)
    semanticError("Null identifier in setDeclaratorElementType");

  if (type == NULL)
    return id;

  if (id->type == NULL)
    id->type = type;
  else
    setTypeElementType(id->type, type);

  return id;
}

A_TYPE *setTypeExpr(A_TYPE *type, A_NODE *expr) {
  if (type == NULL)
    semanticError("NULL type in setTypeExpr");

  type->expr = expr;

  return type;
}

A_TYPE *setTypeField(A_TYPE *type, A_ID *field) {
  if (type == NULL)
    semanticError("NULL type in setTypeField");

  type->field = field;
  return type;
}

A_SPECIFIER *makeSpecifier(A_TYPE *type, S_KIND stor) {
  A_SPECIFIER *specifier = calloc(1, sizeof(A_SPECIFIER));

  if (type == NULL)
    semanticError("NULL type in setTypeField");

  specifier->type = type;
  specifier->stor = stor;
  specifier->line = 0;

  return specifier;
}
