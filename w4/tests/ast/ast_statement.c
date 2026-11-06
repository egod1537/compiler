#include "../../semantic.h"
#include "../../syntax_tree.h"
#include "ast_assert.h"
#include "ast_runner.h"

#include <stdlib.h>
#include <string.h>

static void AST_runSelectionTest(void) {
  const char *selection = getenv("AST_TEST_SELECTION");

  if (selection == NULL)
    return;

  if (strcmp(selection, "if") == 0)
    AST_checkSelection(1);
  else if (strcmp(selection, "ifelse") == 0)
    AST_checkSelection(2);
  else if (strcmp(selection, "nested") == 0)
    AST_checkSelection(3);
  else
    semanticError("Unknown selection test");
}

static void AST_runIterationTest(void) {
  const char *iteration = getenv("AST_TEST_ITERATION");

  if (iteration == NULL)
    return;

  if (strcmp(iteration, "while") == 0)
    AST_checkIteration(1);
  else if (strcmp(iteration, "do") == 0)
    AST_checkIteration(2);
  else if (strcmp(iteration, "for") == 0)
    AST_checkIteration(3);
  else
    semanticError("Unknown iteration test");
}

void AST_runStatementTests(void) {
  if (getenv("AST_TEST_RETURN") != NULL)
    AST_checkReturn(statement_root);

  if (getenv("AST_TEST_COMPOUND") != NULL)
    AST_checkCompoundReturn(compound_root);

  AST_runSelectionTest();
  AST_runIterationTest();

  if (getenv("AST_TEST_BREAK_CONTINUE") != NULL)
    AST_checkBreakContinue();

  if (getenv("AST_TEST_VOID_RETURN") != NULL)
    AST_checkVoidReturn();

  if (getenv("AST_TEST_SWITCH") != NULL)
    AST_checkSwitch();
}
