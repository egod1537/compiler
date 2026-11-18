#include "semantic.h"
#include "type.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SEM_04_Scope(void) {
  assert(current_level == 0);
  assert(current_id == NULL);

  A_ID *a = setDeclaratorKind(makeIdentifier("a"), ID_VAR);

  enterScope();
  assert(current_level == 1);

  A_ID *b = setDeclaratorKind(makeIdentifier("b"), ID_VAR);

  assert(current_id == b);
  assert(searchIdentifier("a") == a);
  assert(searchIdentifier("b") == b);

  enterScope();
  assert(current_level == 2);

  A_ID *c = setDeclaratorKind(makeIdentifier("c"), ID_VAR);

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

}

