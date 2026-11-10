#include "semantic.h"
#include "syntax_tree.h"

#include <stdio.h>
#include <stdlib.h>

int yyparse(void);
void print_ast(A_NODE *node);

/*
 * 테스트 명령 (w4 디렉터리에서 실행):
 *   make test                    전체 테스트
 *   make test-ast                AST 테스트
 *   make test-astexp             AST 기댓값 테스트
 *   make test-sem                의미 분석 테스트
 *   make test-semerr             의미 오류 테스트
 *   make test-baseline           w4-1 결과와 비교
 *
 * 개별 테스트: make <테스트 타깃> TEST=list 또는 TEST=번호
 */
/* 실제 구문분석기 실행 파일에는 테스트 코드를 연결하지 않는다. */
int main(void) {
  initialize();

  if (yyparse() != 0 || syntax_err != 0)
    return EXIT_FAILURE;

  print_ast(program_root);
  return EXIT_SUCCESS;
}
