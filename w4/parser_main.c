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

  return 0;
}
