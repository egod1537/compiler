#include "../../semantic.h"
#include "../../syntax_tree.h"
#include "ast_assert.h"
#include "ast_runner.h"

#include <stdlib.h>
#include <string.h>

static void AST_runComparisonTest(void) {
  const char *comparison = getenv("AST_TEST_COMPARISON");

  if (comparison == NULL)
    return;

  if (strcmp(comparison, "lt") == 0)
    AST_checkComparison(expression_root, N_EXP_LSS, 1, 2);
  else if (strcmp(comparison, "gt") == 0)
    AST_checkComparison(expression_root, N_EXP_GTR, 3, 2);
  else if (strcmp(comparison, "le") == 0)
    AST_checkComparison(expression_root, N_EXP_LEQ, 1, 2);
  else if (strcmp(comparison, "ge") == 0)
    AST_checkComparison(expression_root, N_EXP_GEQ, 3, 2);
  else if (strcmp(comparison, "eq") == 0)
    AST_checkComparison(expression_root, N_EXP_EQL, 1, 1);
  else if (strcmp(comparison, "ne") == 0)
    AST_checkComparison(expression_root, N_EXP_NEQ, 1, 2);
  else
    semanticError("Unknown comparison test");
}

static void AST_runLogicalTest(void) {
  const char *logical = getenv("AST_TEST_LOGICAL");

  if (logical == NULL)
    return;

  if (strcmp(logical, "and") == 0)
    AST_checkLogical(expression_root, 1);
  else if (strcmp(logical, "or") == 0)
    AST_checkLogical(expression_root, 2);
  else if (strcmp(logical, "precedence") == 0)
    AST_checkLogical(expression_root, 3);
  else
    semanticError("Unknown logical test");
}

void AST_runExpressionTests(AstTestMode mode) {
  if (mode == AST_MODE_PRECEDENCE)
    AST_checkPrecedence(expression_root);
  else if (mode == AST_MODE_PARENTHESES)
    AST_checkParentheses(expression_root);

  if (getenv("AST_TEST_PRECEDENCE") != NULL)
    AST_checkPrecedence(expression_root);

  if (getenv("AST_TEST_PARENTHESES") != NULL)
    AST_checkParentheses(expression_root);

  if (getenv("AST_TEST_IDENTIFIER") != NULL)
    AST_checkIdentifierAST(expression_root);

  if (getenv("AST_TEST_DEREFERENCE") != NULL)
    AST_checkPointerDereference(expression_root);

  if (getenv("AST_TEST_ADDRESS_OF") != NULL)
    AST_checkAddressOf(expression_root);

  if (getenv("AST_TEST_UNARY_MINUS") != NULL)
    AST_checkUnaryMinus(expression_root);

  if (getenv("AST_TEST_LOGICAL_NOT") != NULL)
    AST_checkLogicalNot(expression_root);

  if (getenv("AST_TEST_PRE_INC") != NULL)
    AST_checkPreIncrement(expression_root);

  if (getenv("AST_TEST_PRE_DEC") != NULL)
    AST_checkPreDecrement(expression_root);

  if (getenv("AST_TEST_POST_INC") != NULL)
    AST_checkPostIncrement(expression_root);

  if (getenv("AST_TEST_POST_DEC") != NULL)
    AST_checkPostDecrement(expression_root);

  if (getenv("AST_TEST_ARRAY_ACCESS") != NULL)
    AST_checkArrayAccess(expression_root);

  if (getenv("AST_TEST_ASSIGNMENT") != NULL)
    AST_checkAssignment();

  AST_runComparisonTest();
  AST_runLogicalTest();

  if (getenv("AST_TEST_FUNCTION_CALL") != NULL)
    AST_checkFunctionCall();

  if (getenv("AST_TEST_SIZEOF_EXP") != NULL)
    AST_checkSizeofExpression();

  if (getenv("AST_TEST_CAST") != NULL)
    AST_checkCastExpression();

  if (getenv("AST_TEST_CHAR_STRING") != NULL)
    AST_checkCharString();
}
