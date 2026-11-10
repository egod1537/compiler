#include "../../logger.h"
#include "ast_runner.h"

#include <string.h>

int AST_parseTestMode(int argc, char **argv, AstTestMode *mode) {
  *mode = AST_MODE_NONE;

  if (argc == 1)
    return 1;

  if (argc == 2 && strcmp(argv[1], "--print-ast") == 0) {
    *mode = AST_MODE_PRINT;
    return 1;
  }

  if (argc != 3 || strcmp(argv[1], "--ast-test") != 0) {
    logMsg(LOG_ERROR,
           "Usage: %s [--print-ast | --ast-test precedence|parentheses]",
           argv[0]);
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
