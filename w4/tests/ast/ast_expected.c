#include "ast_expected.h"

#include "../../semantic.h"
#include "../../syntax_tree.h"
#include "ast_assert.h"
#include "ast_runner.h"

#include <stdlib.h>

void ASTEXP_01_Precedence(void) {
  AST_03_Precedence(expression_root);
}

void ASTEXP_02_IfElse(void) {
  AST_36_Selection(2);
}

void ASTEXP_03_For(void) {
  AST_38_Iteration(3);
}

void ASTEXP_04_FunctionPrototype(void) {
  AST_24_FunctionPrototype();
}

void ASTEXP_05_FunctionParameters(void) {
  AST_25_FunctionParameters();
  AST_25_FunctionScope();
}

void ASTEXP_06_ScopeShadowing(void) {
  AST_44_BlockShadowing();
}

void ASTEXP_07_FunctionDeclarator(void) {
  AST_59_FunctionDeclarator();
}

void AST_runExpectedTest(void) {
  const char *value = getenv("AST_TEST_EXPECTED_NUMBER");

  if (value == NULL)
    return;

  char *end = NULL;
  long number = strtol(value, &end, 10);

  if (value[0] == '\0' || end == NULL || *end != '\0')
    semanticError("Invalid expected AST test number");

  switch (number) {
  case 1:
    ASTEXP_01_Precedence();
    break;
  case 2:
    ASTEXP_02_IfElse();
    break;
  case 3:
    ASTEXP_03_For();
    break;
  case 4:
    ASTEXP_04_FunctionPrototype();
    break;
  case 5:
    ASTEXP_05_FunctionParameters();
    break;
  case 6:
    ASTEXP_06_ScopeShadowing();
    break;
  case 7:
    ASTEXP_07_FunctionDeclarator();
    break;
  default:
    semanticError("Expected AST test number must be between 1 and 7");
  }
}
