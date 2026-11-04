#include "logger.h"
#include "semantic.h"
#include "syntax_tree.h"
#include "tests/ast_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yyparse(void);

typedef enum {
  AST_MODE_NONE,
  AST_MODE_PRECEDENCE,
  AST_MODE_PARENTHESES
} AstTestMode;

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
    checkPrecedence(expression_root);
  else if (mode == AST_MODE_PARENTHESES)
    checkParentheses(expression_root);

  return 0;
}
