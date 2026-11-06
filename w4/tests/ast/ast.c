#include "../../semantic.h"
#include "../../syntax_tree.h"
#include "ast_runner.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yyparse(void);
void print_ast(A_NODE *node);

int main(int argc, char **argv) {
  initialize();

  AstTestMode mode;
  if (!AST_parseTestMode(argc, argv, &mode))
    return EXIT_FAILURE;

  int result = yyparse();

  if (result != 0)
    return result;

  printf("Parsing success\n");

  AST_runExpressionTests(mode);
  AST_runDeclarationTests();
  AST_runStatementTests();

  const char *ast_print = getenv("AST_PRINT");

  if (ast_print != NULL && strcmp(ast_print, "1") == 0)
    print_ast(program_root);

  return EXIT_SUCCESS;
}
