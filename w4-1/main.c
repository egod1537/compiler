#include "type.h"
#include <stdio.h>
#include <stdlib.h>

extern int syntax_err;
extern int semantic_err;
extern A_NODE *root;

FILE *fout;

void initialize();
void print_ast();
void print_sem_ast();
void code_generation();
void semantic_analysis();

void main(int argc, char *argv[]) {
  if ((fout = fopen("a.asm", "w")) == NULL) {
    printf("can not open output file: a.asm\n");
    exit(1);
  }
  initialize();
  yyparse();
  if (syntax_err)
    exit(1);
  // print_ast(root);
  semantic_analysis(root);
  if (semantic_err)
    exit(1);
  code_generation(root);
  exit(0);
}
