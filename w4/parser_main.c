#include "logger.h"
#include "semantic.h"
#include "syntax_tree.h"
#include "tests/ast_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yyparse(void);

typedef enum { AST_MODE_NONE, AST_MODE_PRECEDENCE, AST_MODE_PARENTHESES } AstTestMode;

static int parseAstTestMode(int argc, char **argv, AstTestMode *mode) {
  *mode = AST_MODE_NONE;

  if (argc == 1)
    return 1;

  if (argc != 3 || strcmp(argv[1], "--ast-test") != 0) {
    logMsg(LOG_ERROR, "Usage: %s [--ast-test precedence|parentheses]", argv[0]);
    return 0;
  }

  if (strcmp(argv[2], "precedence") == 0) {
    *mode = AST_MODE_PRECEDENCE;
    return 1;
  }

  if (strcmp(argv[2], "parentheses") == 0) {
    *mode = AST_MODE_PARENTHESES;
    return 1;
  }

  logMsg(LOG_ERROR, "Unknown AST test mode: %s", argv[2]);
  return 0;
}

int main(int argc, char **argv) {
  initialize();

  AstTestMode mode;
  if (!parseAstTestMode(argc, argv, &mode))
    return EXIT_FAILURE;

  int result = yyparse();

  if (result != 0)
    return result;

  printf("Parsing success\n");

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

  if (getenv("AST_TEST_POINTER") != NULL)
    AST_checkPointerDeclaration();

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

  if (getenv("AST_TEST_ARRAY_DECL") != NULL)
    AST_checkArrayDeclaration();

  if (getenv("AST_TEST_FUNCTION_DECL") != NULL)
    AST_checkFunctionDeclarator();

  if (getenv("AST_TEST_FUNCTION_PARAMS") != NULL)
    AST_checkFunctionParameters();

  if (getenv("AST_TEST_RETURN") != NULL)
    AST_checkReturn(statement_root);

  if (getenv("AST_TEST_COMPOUND") != NULL)
    AST_checkCompoundReturn(compound_root);

  if (getenv("AST_TEST_FUNCTION_SCOPE") != NULL)
    AST_checkFunctionScope();

  if (getenv("AST_TEST_FUNCTION_SCOPE") != NULL)
    AST_checkFunctionScope();

  if (getenv("AST_TEST_BLOCK_SHADOWING") != NULL)
    AST_checkBlockShadowing();

  if (getenv("AST_TEST_ASSIGNMENT") != NULL)
    AST_checkAssignment();

  {
    const char *comparison = getenv("AST_TEST_COMPARISON");

    if (comparison != NULL) {
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
  }

  {
    const char *logical = getenv("AST_TEST_LOGICAL");

    if (logical != NULL) {
      if (strcmp(logical, "and") == 0)
        AST_checkLogical(expression_root, 1);
      else if (strcmp(logical, "or") == 0)
        AST_checkLogical(expression_root, 2);
      else if (strcmp(logical, "precedence") == 0)
        AST_checkLogical(expression_root, 3);
      else
        semanticError("Unknown logical test");
    }
  }

  {
    const char *selection = getenv("AST_TEST_SELECTION");

    if (selection != NULL) {
      if (strcmp(selection, "if") == 0)
        AST_checkSelection(1);
      else if (strcmp(selection, "ifelse") == 0)
        AST_checkSelection(2);
      else if (strcmp(selection, "nested") == 0)
        AST_checkSelection(3);
      else
        semanticError("Unknown selection test");
    }
  }

  {
    const char *iteration = getenv("AST_TEST_ITERATION");

    if (iteration != NULL) {
      if (strcmp(iteration, "while") == 0)
        AST_checkIteration(1);
      else if (strcmp(iteration, "do") == 0)
        AST_checkIteration(2);
      else if (strcmp(iteration, "for") == 0)
        AST_checkIteration(3);
      else
        semanticError("Unknown iteration test");
    }
  }

  if (getenv("AST_TEST_BREAK_CONTINUE") != NULL)
    AST_checkBreakContinue();

  if (getenv("AST_TEST_VOID_RETURN") != NULL)
    AST_checkVoidReturn();

  if (getenv("AST_TEST_FUNCTION_CALL") != NULL)
    AST_checkFunctionCall();

  if (getenv("AST_TEST_SIZEOF_EXP") != NULL)
    AST_checkSizeofExpression();

  if (getenv("AST_TEST_SIZEOF_TYPE") != NULL)
    AST_checkSizeofType();

  if (getenv("AST_TEST_CAST") != NULL)
    AST_checkCastExpression();

  if (getenv("AST_TEST_SWITCH") != NULL)
    AST_checkSwitch();

  return 0;
}
