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
    AST_36_Selection(1);
  else if (strcmp(selection, "ifelse") == 0)
    AST_36_Selection(2);
  else if (strcmp(selection, "nested") == 0)
    AST_36_Selection(3);
  else
    semanticError("Unknown selection test");
}

static void AST_runIterationTest(void) {
  const char *iteration = getenv("AST_TEST_ITERATION");

  if (iteration == NULL)
    return;

  if (strcmp(iteration, "while") == 0)
    AST_38_Iteration(1);
  else if (strcmp(iteration, "do") == 0)
    AST_38_Iteration(2);
  else if (strcmp(iteration, "for") == 0)
    AST_38_Iteration(3);
  else
    semanticError("Unknown iteration test");
}

void AST_runStatementTests(void) {
  if (getenv("AST_TEST_RETURN") != NULL)
    AST_01_Return(statement_root);

  if (getenv("AST_TEST_COMPOUND") != NULL)
    AST_43_CompoundReturn(compound_root);

  AST_runSelectionTest();
  AST_runIterationTest();

  if (getenv("AST_TEST_BREAK_CONTINUE") != NULL)
    AST_41_BreakContinue();

  if (getenv("AST_TEST_VOID_RETURN") != NULL)
    AST_42_VoidReturn();

  if (getenv("AST_TEST_SWITCH") != NULL)
    AST_63_Switch();
}
