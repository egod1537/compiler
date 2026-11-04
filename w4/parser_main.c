#include "syntax_tree.h"
#include "tests/ast_assert.h"
#include <stdio.h>
#include <stdlib.h>

int yyparse(void);

int main(void) {
  int result = yyparse();

  if (result != 0)
    return result;

  printf("Parsing success\n");

  if (getenv("AST_TEST_PRECEDENCE") != NULL)
    checkPrecedence(expression_root);

  if (getenv("AST_TEST_PARENTHESES") != NULL)
    checkParentheses(expression_root);

  return 0;
}
