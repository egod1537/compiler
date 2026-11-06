#include "semantic.h"
#include "syntax_tree.h"

#include <stdlib.h>

int yyparse(void);

int main(void) {
  initialize();

  if (yyparse() != 0)
    return EXIT_FAILURE;

  print_ast(program_root);
  return EXIT_SUCCESS;
}
