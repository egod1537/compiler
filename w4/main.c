#include "semantic.h"
#include "syntax_tree.h"

#include <stdio.h>
#include <stdlib.h>

int yyparse(void);
void print_ast(A_NODE *node);

/* 실제 구문분석기 실행 파일에는 테스트 코드를 연결하지 않는다. */
int main(void) {
  initialize();

  if (yyparse() != 0 || syntax_err != 0)
    return EXIT_FAILURE;

  print_ast(program_root);
  return EXIT_SUCCESS;
}
