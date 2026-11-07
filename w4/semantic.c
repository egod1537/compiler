#include "semantic.h"
#include "error.h"
#include "type.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *yytext;

A_ID *current_id = NULL;
int current_level = 0;
int line_no = 1;
int syntax_err = 0;

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
  float_type = makeType(T_ENUM);
  char_type = makeType(T_ENUM);
  void_type = makeType(T_VOID);
  string_type = setTypeElementType(makeType(T_POINTER), char_type);

  int_type->size = 4;
  float_type->size = 4;
  char_type->size = 1;
  void_type->size = 0;
  string_type->size = 4;

  int_type->check = TRUE;
  float_type->check = TRUE;
  char_type->check = TRUE;
  void_type->check = TRUE;
  string_type->check = TRUE;

  A_ID *id = makeIdentifier("int");
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

  A_ID *format = makeDummyIdentifier();
  format->kind = ID_PARM;
  format->type = string_type;
  A_ID *variadic = makeDummyIdentifier();
  variadic->kind = ID_PARM;

  id = makeIdentifier("printf");
  id->kind = ID_FUNC;
  id->type = setTypeField(setTypeElementType(makeType(T_FUNC), void_type),
                          linkDeclaratorList(format, variadic));

  format = makeDummyIdentifier();
  format->kind = ID_PARM;
  format->type = string_type;
  variadic = makeDummyIdentifier();
  variadic->kind = ID_PARM;

  id = makeIdentifier("scanf");
  id->kind = ID_FUNC;
  id->type = setTypeField(setTypeElementType(makeType(T_FUNC), void_type),
                          linkDeclaratorList(format, variadic));

  A_ID *size = makeDummyIdentifier();
  size->kind = ID_PARM;
  size->type = int_type;

  id = makeIdentifier("malloc");
  id->kind = ID_FUNC;
  id->type = setTypeField(setTypeElementType(makeType(T_FUNC), string_type), size);
}

static int isSameType(const A_TYPE *a, const A_TYPE *b);
static int isSameFormalParameters(const A_ID *a, const A_ID *b);
static int isPointerOrArrayType(const A_TYPE *type);

static int isSameType(const A_TYPE *a, const A_TYPE *b) {
  if (isPointerOrArrayType(a) || isPointerOrArrayType(b)) {
    return isSameType(a->element_type, b->element_type);
  }

  return a == b;
}

static int isSameFormalParameters(const A_ID *a, const A_ID *b) {
  if (a == NULL)
    return 1;

  while (a != NULL) {
    if (b == NULL)
      return 0;

    if (!isSameType(a->type, b->type))
      return 0;

    a = a->link;
    b = b->link;
  }

  return a == NULL && b == NULL;
}

static int isPointerOrArrayType(const A_TYPE *type) {
  return type != NULL && (type->kind == T_POINTER || type->kind == T_ARRAY);
}

A_TYPE *makeType(T_KIND kind) {
  A_TYPE *t = calloc(1, sizeof(A_TYPE));

  if (t == NULL) {
    semanticError("memory allocation failed");
  }

  t->kind = kind;
  t->line = line_no;

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
  id->line = line_no;
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

    if (strcmp(id->name, name) == 0)
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
  report_compiler_error(INTERNAL_ERROR, 0, line_no, "%s", message);
  exit(EXIT_FAILURE);
}

void syntax_error(int code, const char *name) {
  syntax_err++;
  const char *identifier = name != NULL ? name : "";

  if (!compiler_error_tags_enabled()) {
    printf("line %d: syntax error: ", line_no);
    switch (code) {
    case 11:
      printf("illegal referencing struct or union identifier %s", identifier);
      break;
    case 12:
      printf("redeclaration of identifier %s", identifier);
      break;
    case 13:
      printf("undefined identifier %s", identifier);
      break;
    case 14:
      printf("illegal type specifier in formal parameter");
      break;
    case 21:
      printf("illegal function declarator");
      break;
    case 22:
      printf("conflicting parm type in prototype function %s", identifier);
      break;
    case 23:
      printf("empty parameter name");
      break;
    case 26:
      printf("illegal or conflicting return type in function %s", identifier);
      break;
    case 31:
      printf("undefined type for identifier %s", identifier);
      break;
    case 32:
      printf("incomplete forward reference for identifier %s", identifier);
      break;
    default:
      printf("unknown");
      break;
    }

    if (yytext == NULL || yytext[0] == '\0')
      printf(" at end\n");
    else
      printf(" near %s\n", yytext);
    return;
  }

  switch (code) {
  case 11:
    report_compiler_error(DECLARATION_ERROR, code, line_no,
                          "illegal reference to struct or union identifier '%s'",
                          identifier);
    break;
  case 12:
    report_compiler_error(DECLARATION_ERROR, code, line_no,
                          "redeclaration of identifier '%s'", identifier);
    break;
  case 13:
    report_compiler_error(DECLARATION_ERROR, code, line_no,
                          "undefined identifier '%s'", identifier);
    break;
  case 14:
    report_compiler_error(DECLARATION_ERROR, code, line_no,
                          "illegal type specifier in formal parameter");
    break;
  case 21:
    report_compiler_error(DECLARATION_ERROR, code, line_no,
                          "illegal function declarator");
    break;
  case 22:
    report_compiler_error(DECLARATION_ERROR, code, line_no,
                          "conflicting parameter type in prototype function '%s'",
                          identifier);
    break;
  case 23:
    report_compiler_error(DECLARATION_ERROR, code, line_no,
                          "empty parameter name");
    break;
  case 26:
    report_compiler_error(DECLARATION_ERROR, code, line_no,
                          "illegal or conflicting return type in function '%s'",
                          identifier);
    break;
  case 31:
    report_compiler_error(DECLARATION_ERROR, code, line_no,
                          "undefined type for identifier '%s'", identifier);
    break;
  case 32:
    report_compiler_error(DECLARATION_ERROR, code, line_no,
                          "incomplete forward reference for identifier '%s'",
                          identifier);
    break;
  default:
    report_compiler_error(INTERNAL_ERROR, code, line_no,
                          "unknown declaration error");
    break;
  }

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
    return t2;

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

A_SPECIFIER *makeSpecifier(A_TYPE *type) {
  A_SPECIFIER *specifier = calloc(1, sizeof(A_SPECIFIER));

  if (specifier == NULL)
    semanticError("Memory allocation failed in makeSpecifier");

  specifier->type = type;
  specifier->stor = S_NULL;
  specifier->line = line_no;

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
      syntax_error(12, current->name);
    }

    // 선언자의 최종 타입 결정
    setDeclaratorElementType(current, specifier->type);

    if (current->type == NULL)
      semanticError("Unresolved declarator type");

    // 식별자 종류 결정
    if (current->type->kind == T_FUNC) {
      current->kind = ID_FUNC;
    } else {
      current->kind = ID_VAR;
    }

    current->specifier = S_NULL;

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

    if (searchIdentifierAtCurrentLevel(field->name, field->prev) != NULL)
      syntax_error(12, field->name);

    setDeclaratorElementType(field, type);
    field->kind = ID_FIELD;
  }

  return id;
}

A_ID *setFunctionDeclaratorSpecifier(A_ID *id, A_SPECIFIER *specifier) {
  if (id == NULL || specifier == NULL)
    semanticError("Null argument in setFunctionDeclaratorSpecifier");

  setDefaultSpecifier(specifier);

  if (id->type->kind != T_FUNC) {
    syntax_error(21, id->name);
    return id;
  }

  setDeclaratorElementType(id, specifier->type);
  id->kind = ID_FUNC;

  A_ID *previous = searchIdentifierAtCurrentLevel(id->name, id->prev);

  if (previous != NULL) {
    if (previous->kind != ID_FUNC || previous->type == NULL ||
        previous->type->kind != T_FUNC || previous->type->expr != NULL) {
      syntax_error(12, id->name);
    } else {
      if (!isSameFormalParameters(previous->type->field, id->type->field))
        syntax_error(22, id->name);

      if (!isSameType(previous->type->element_type, id->type->element_type))
        syntax_error(26, previous->name);
    }
  }

  A_ID *param = id->type->field;

  while (param != NULL) {
    if (param->name != NULL && param->name[0] != '\0')
      current_id = param;
    else if (param->type != NULL)
      syntax_error(23, NULL);

    param = param->link;
  }

  return id;
}

A_ID *setFunctionDeclaratorBody(A_ID *id, A_NODE *body) {
  if (id == NULL)
    semanticError("Null identifier in setFunctionDeclaratorBody");

  id->type->expr = body;
  current_id = id;

  return id;
}

A_ID *setParameterDeclaratorSpecifier(A_ID *id, A_SPECIFIER *specifier) {
  if (id == NULL || specifier == NULL)
    semanticError("Null argument in setParameterDeclaratorSpecifier");

  if (searchIdentifierAtCurrentLevel(id->name, id->prev) != NULL)
    syntax_error(12, id->name);

  if (specifier->type == void_type)
    syntax_error(14, NULL);

  setDefaultSpecifier(specifier);
  setDeclaratorElementType(id, specifier->type);

  id->kind = ID_PARM;

  return id;
}

A_ID *getIdentifierDeclared(const char *name) {
  A_ID *id = searchIdentifier(name);

  if (id == NULL)
    syntax_error(13, name);

  return id;
}

A_ID *makeDummyIdentifier(void) {
  A_ID *id = calloc(1, sizeof(A_ID));

  if (id == NULL)
    semanticError("memory allocation failed");

  id->name = malloc(1);
  if (id->name == NULL)
    semanticError("memory allocation failed");

  id->name[0] = '\0';
  id->level = current_level;
  id->line = line_no;
  return id;
}

A_TYPE *setTypeNameSpecifier(A_TYPE *type, A_SPECIFIER *specifier) {
  if (specifier == NULL)
    semanticError("Null type specifier");

  setDefaultSpecifier(specifier);
  return setTypeElementType(type, specifier->type);
}

A_TYPE *setTypeStructOrEnumIdentifier(T_KIND kind, char *name, ID_KIND id_kind) {
  if (name == NULL || name[0] == '\0')
    semanticError("Missing struct or enum tag");

  A_ID *previous = searchIdentifierAtCurrentLevel(name, current_id);

  if (previous != NULL) {
    if (previous->kind == id_kind && previous->type != NULL &&
        previous->type->kind == kind) {
      if (previous->type->field != NULL)
        syntax_error(12, name);
      else
        return previous->type;
    } else {
      syntax_error(12, name);
    }
  }

  A_ID *id = makeIdentifier(name);
  id->kind = id_kind;
  id->type = makeType(kind);

  return id->type;
}

A_TYPE *getTypeOfStructOrEnumIdentifier(T_KIND kind, char *name, ID_KIND id_kind) {
  if (name == NULL || name[0] == '\0')
    semanticError("Missing struct or enum tag");

  A_ID *id = searchIdentifier(name);

  if (id != NULL) {
    if (id->kind == id_kind && id->type != NULL && id->type->kind == kind)
      return id->type;
    syntax_error(11, name);
  }

  A_TYPE *type = makeType(kind);
  id = makeIdentifier(name);
  id->kind = id_kind;
  id->type = type;
  return type;
}

A_ID *setDeclaratorKind(A_ID *id, ID_KIND kind) {
  if (id == NULL)
    semanticError("Null identifier");

  if (searchIdentifierAtCurrentLevel(id->name, id->prev) != NULL)
    syntax_error(12, id->name);

  id->kind = kind;
  return id;
}

void checkForwardReference(void) {
  A_ID *id = current_id;

  while (id != NULL) {
    if (id->level < current_level)
      break;

    if (id->kind == ID_NULL)
      syntax_error(31, id->name);
    else if ((id->kind == ID_STRUCT || id->kind == ID_ENUM) && id->type != NULL &&
             id->type->field == NULL)
      syntax_error(32, id->name);

    id = id->prev;
  }
}
