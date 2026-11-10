#include "sem_test_support.h"

#include "semantic.h"
#include "type.h"

#include <stdlib.h>

void semTestFreeIdentifierChain(void) {
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
}

void semTestResetInitializedState(void) {
  semTestFreeIdentifierChain();

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
  current_level = 0;
  syntax_err = 0;
}
