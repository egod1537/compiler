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

  return 0;
}
