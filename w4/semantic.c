#include "semantic.h"
#include "logger.h"
#include "type.h"
#include "syntax_tree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

A_ID *current_id = NULL;
int current_level = 0;

A_TYPE *int_type = NULL;
A_TYPE *float_type = NULL;
A_TYPE *char_type = NULL;
A_TYPE *void_type = NULL;
A_TYPE *string_type = NULL;

void initialize(void) {
  if (current_id != NULL || current_level != 0 || int_type != NULL ||
      float_type != NULL || char_type != NULL || void_type != NULL ||
      string_type != NULL)
    semanticError("Semantic state already initialized");

  int_type = makeType(T_ENUM);
  int_type->size = sizeof(int);

  float_type = makeType(T_ENUM);
  float_type->size = sizeof(float);

  char_type = makeType(T_ENUM);
  char_type->size = sizeof(char);

  void_type = makeType(T_VOID);
  void_type->size = 0;

  string_type = makeType(T_POINTER);
  setTypeElementType(string_type, char_type);
  string_type->size = sizeof(char *);

  A_ID *id;

  id = makeIdentifier("int");
  id->kind = ID_TYPE;
  id->type = int_type;

  id = makeIdentifier("float");
  id->kind = ID_TYPE;
  id->type = float_type;

  id = makeIdentifier("char");
  id->kind = ID_TYPE;
  id->type = char_type;

  id = makeIdentifier("void");
  id->kind = ID_TYPE;
  id->type = void_type;
  id = makeIdentifier("printf");
  id->kind = ID_FUNC;
  id->type = makeType(T_FUNC);
  setTypeElementType(id->type, int_type);

  id = makeIdentifier("scanf");
  id->kind = ID_FUNC;
  id->type = makeType(T_FUNC);
  setTypeElementType(id->type, int_type);
}

static int isSameType(const A_TYPE *a, const A_TYPE *b);
static int isSameFormalParameters(const A_ID *a, const A_ID *b);

static int isSameType(const A_TYPE *a, const A_TYPE *b) {
  if (a == b)
    return 1;

  if (a == NULL || b == NULL)
    return 0;

  if (a->kind != b->kind)
    return 0;

  switch (a->kind) {
  case T_POINTER:
    return isSameType(a->element_type, b->element_type);

  case T_ARRAY:
    return a->expr == b->expr && isSameType(a->element_type, b->element_type);

  case T_FUNC:
    return isSameType(a->element_type, b->element_type) &&
           isSameFormalParameters(a->field, b->field);

  case T_VOID:
    return 1;

  default:
    return 0;
  }
}

static int isSameFormalParameters(const A_ID *a, const A_ID *b) {
  while (a != NULL && b != NULL) {
    if (!isSameType(a->type, b->type))
      return 0;

    a = a->link;
    b = b->link;
  }

  return a == NULL && b == NULL;
}

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
    if (id->kind != ID_STRUCT && id->kind != ID_ENUM && id->kind != ID_FIELD &&
        strcmp(id->name, name) == 0)
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

    if (id->level == current_level && id->kind != ID_STRUCT && id->kind != ID_ENUM &&
        id->kind != ID_FIELD && strcmp(id->name, name) == 0)
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

  checkForwardReference();

  ScopreFrame *frame = scope_stack;

  current_id = frame->saved_id;
  current_level--;

  scope_stack = frame->prev;
  free(frame);
}

void semanticError(const char *message) {
  logMsg(LOG_ERROR, "Semantic error: %s", message);
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

// linkDeclaratorList type 버전, 뒤 연결한다
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

  if (type->kind == T_STRUCT || type->kind == T_UNION) {
    for (A_ID *member = field; member != NULL; member = member->link) {
      for (A_ID *previous = field; previous != member; previous = previous->link) {
        if (strcmp(previous->name, member->name) == 0)
          semanticError("Duplicate struct field");
      }
    }
  }

  type->field = field;

  if (type->kind == T_STRUCT || type->kind == T_UNION) {
    for (A_ID *member = field; member != NULL; member = member->link) {
      if (current_id == member) {
        current_id = member->prev;
        continue;
      }

      A_ID *id = current_id;

      while (id != NULL && id->prev != member)
        id = id->prev;

      if (id == NULL)
        semanticError("Struct field is missing from identifier table");

      id->prev = member->prev;
    }
  }

  return type;
}

A_SPECIFIER *makeSpecifier(A_TYPE *type, S_KIND stor) {
  A_SPECIFIER *specifier = calloc(1, sizeof(A_SPECIFIER));

  if (specifier == NULL)
    semanticError("Memory allocation failed in makeSpecifier");

  specifier->type = type;
  specifier->stor = stor;
  specifier->line = 0;

  return specifier;
}

A_SPECIFIER *updateSpecifier(A_SPECIFIER *specifier, A_TYPE *type, S_KIND stor) {
  if (specifier == NULL)
    semanticError("Null specifier in updateSpecifier");

  if (type != NULL) {
    if (specifier->type != NULL)
      semanticError("Duplicate type specifier");

    specifier->type = type;
  }

  if (stor != S_NULL) {
    if (specifier->stor != S_NULL)
      semanticError("Duplicate storage class specifier");

    specifier->stor = stor;
  }

  return specifier;
}

void setDefaultSpecifier(A_SPECIFIER *specifier) {
  if (specifier == NULL)
    semanticError("Null speicifer in setDefaultSpecifier");

  if (specifier->type == NULL) {
    if (int_type == NULL)
      semanticError("Default int type is not initalized");

    specifier->type = int_type;
  }
}

A_ID *setDeclaratorListSpecifier(A_ID *id, A_SPECIFIER *specifier) {
  if (specifier == NULL)
    semanticError("Null specifier in setDeclaratorListSpecifier");

  setDefaultSpecifier(specifier);

  A_ID *current = id;

  while (current != NULL) {
    // 현재 스코프 중복 검사
    if (current->name != NULL && current->name[0] != '\0' &&
        searchIdentifierAtCurrentLevel(current->name, current->prev) != NULL) {
      semanticError("Redeclaration of identifier");
    }

    // 선언자의 최종 타입 결정
    setDeclaratorElementType(current, specifier->type);

    if (current->type == NULL)
      semanticError("Unresolved declarator type");

    // 식별자 종류 결정
    if (specifier->stor == S_TYPEDEF) {
      current->kind = ID_TYPE;
    } else if (current->type->kind == T_FUNC) {
      current->kind = ID_FUNC;
    } else {
      current->kind = ID_VAR;
    }

    // 저장 클래스 적용
    current->specifier = specifier->stor;

    if (current->specifier == S_NULL)
      current->specifier = S_AUTO;

    current = current->link;
  }

  return id;
}

A_ID *setStructDeclaratorListSpecifier(A_ID *id, A_TYPE *type) {
  if (id == NULL || type == NULL)
    semanticError("Null struct field declaration");

  for (A_ID *field = id; field != NULL; field = field->link) {
    if (field->name == NULL || field->name[0] == '\0')
      semanticError("Missing struct field name");

    for (A_ID *previous = id; previous != field; previous = previous->link) {
      if (strcmp(previous->name, field->name) == 0)
        semanticError("Duplicate struct field");
    }

    setDeclaratorElementType(field, type);
    field->kind = ID_FIELD;
  }

  return id;
}

A_ID *setFunctionDeclaratorSpecifier(A_ID *id, A_SPECIFIER *specifier) {
  if (id == NULL || specifier == NULL)
    semanticError("Null argument in setFunctionDeclaratorSpecifier");

  if (specifier->stor != S_NULL)
    semanticError("Illegal function specifiers");

  setDefaultSpecifier(specifier);

  if (id->type == NULL || id->type->kind != T_FUNC)
    semanticError("Illegal function specifiers");

  setDeclaratorElementType(id, specifier->type);
  id->kind = ID_FUNC;

  A_ID *previous = searchIdentifierAtCurrentLevel(id->name, id->prev);

  if (previous != NULL) {
    if (previous->kind != ID_FUNC || previous->type == NULL ||
        previous->type->kind != T_FUNC || previous->type->expr != NULL)
      semanticError("Redeclaration of function");

    if (!isSameFormalParameters(previous->type->field, id->type->field))
      semanticError("Redeclaration of function");

    if (!isSameType(previous->type->element_type, id->type->element_type))
      semanticError("Redeclaration of function");
  }

  A_ID *param = id->type->field;

  while (param != NULL) {
    if ((param->name == NULL || param->name[0] == '\0') && param->type != NULL &&
        param->type->kind != T_VOID) {
      semanticError("Empty parameter name");
    }

    param = param->link;
  }

  return id;
}

A_ID *setFunctionDeclaratorBody(A_ID *id, A_NODE *body) {
  if (id == NULL)
    semanticError("Null identifier in setFunctionDeclaratorBody");

  if (id->kind != ID_FUNC || id->type == NULL || id->type->kind != T_FUNC)
    semanticError("Illegal function declarator");

  if (body == NULL)
    semanticError("Null function body");

  if (id->type->expr != NULL)
    semanticError("Function body already defined");

  id->type->expr = body;

  return id;
}

A_ID *setParameterDeclaratorSpecifier(A_ID *id, A_SPECIFIER *specifier) {
  if (id == NULL || specifier == NULL)
    semanticError("Null argument in setParameterDeclaratorSpecifier");

  // 파라미터에 허용되지 않는 저장 클래스 검사 (이번 과제는 하지 않음)
  if (specifier->stor != S_NULL)
    semanticError("Illegal storage class in formal parameter");

  // 파라미터는 명시적인 타입이 있어야됨
  if (specifier->type == NULL)
    semanticError("Missing paramater type");

  // 같이 스코프에서 이름 중복 검사
  if (id->name != NULL && id->name[0] != '\0') {
    if (searchIdentifierAtCurrentLevel(id->name, id->prev) != NULL)
      semanticError("Redeclaration of parameter");
  }

  // 타입 설정
  setDeclaratorElementType(id, specifier->type);

  // 이름이 있는 void 파라미터는 X
  if (id->type == void_type) {
    if (id->name != NULL && id->name[0] != '\0')
      semanticError("Named paramater of void type");
  }

  id->kind = ID_PARM;

  return id;
}

A_ID *getIdentifierDeclared(const char *name) {
  A_ID *id = searchIdentifier(name);

  if (id == NULL)
    semanticError("Undeclared identifier");

  return id;
}

A_ID *makeDummyIdentifier(void) {
  return makeIdentifier("");
}

A_TYPE *setTypeNameSpecifier(A_TYPE *type, A_SPECIFIER *specifier) {
  if (specifier == NULL)
    semanticError("Null type specifier");

  if (specifier->stor != S_NULL)
    semanticError("Illegal storage clss in type name");

  if (specifier->type == NULL)
    semanticError("Missing type in type name");

  if (type == NULL)
    return specifier->type;

  return setTypeElementType(type, specifier->type);
}

static int isTagIdentifier(const A_ID *id) {
  return id != NULL && (id->kind == ID_STRUCT || id->kind == ID_ENUM);
}

static void validateTagKind(T_KIND kind, ID_KIND id_kind) {
  if (id_kind == ID_STRUCT) {
    if (kind != T_STRUCT && kind != T_UNION)
      semanticError("Invalid struct or union tag kind");
  } else if (id_kind == ID_ENUM) {
    if (kind != T_ENUM)
      semanticError("Invalid enum tag kind");
  } else {
    semanticError("Invalid tag identifier kind");
  }
}

static A_ID *searchTagIdentifier(const char *name, int current_scope_only) {
  for (A_ID *id = current_id; id != NULL; id = id->prev) {
    if (current_scope_only && id->level < current_level)
      break;

    if (isTagIdentifier(id) && strcmp(id->name, name) == 0)
      return id;
  }

  return NULL;
}

A_TYPE *setTypeStructOrEnumIdentifier(T_KIND kind, char *name, ID_KIND id_kind) {
  if (name == NULL || name[0] == '\0')
    semanticError("Missing struct or enum tag");

  validateTagKind(kind, id_kind);

  A_ID *id = searchTagIdentifier(name, 1);

  if (id != NULL) {
    if (id->kind != id_kind || id->type == NULL || id->type->kind != kind)
      semanticError("Conflicting struct or enum tag declaration");

    if (id->type->field != NULL)
      semanticError("Redefinition of struct or enum tag");

    return id->type;
  }

  id = makeIdentifier(name);
  id->kind = id_kind;
  id->type = makeType(kind);

  return id->type;
}

A_TYPE *getTypeOfStructOrEnumIdentifier(T_KIND kind, char *name, ID_KIND id_kind) {
  if (name == NULL || name[0] == '\0')
    semanticError("Missing struct or enum tag");

  validateTagKind(kind, id_kind);

  A_ID *id = searchTagIdentifier(name, 0);

  if (id == NULL)
    return setTypeStructOrEnumIdentifier(kind, name, id_kind);

  if (id->kind != id_kind || id->type == NULL || id->type->kind != kind)
    semanticError("Struct or enum tag kind mismatch");

  return id->type;
}

A_ID *setDeclaratorKind(A_ID *id, ID_KIND kind) {
  if (id == NULL)
    semanticError("Null identifier");

  if (searchIdentifierAtCurrentLevel(id->name, id->prev) != NULL)
    semanticError("Redeclaration of identifier");

  id->kind = kind;
  return id;
}

void checkForwardReference(void) {
  A_ID *id = current_id;

  while (id != NULL) {
    if (id->level < current_level)
      break;

    if (id->kind == ID_NULL)
      semanticError("Undefined identifier");

    if (id->kind == ID_STRUCT && id->type != NULL && id->type->field == NULL)
      semanticError("Incomplete forward reference");

    id = id->prev;
  }
}
