#include "type.h"

extern int semantic_err;
void semantic_analysis(A_NODE *);
void print_sem_ast(A_NODE *);

extern int syntax_err;
extern A_NODE *root;

void initialize();
int yyparse();
void print_ast(A_NODE *);

/*
bison -d -o y.tab.c c.y
flex -o lex.yy.c c.l
gcc -o parser y.tab.c lex.yy.c support.c print.c main.c
*/

int main() {
  initialize();

  if (yyparse() || syntax_err)
    return (1);

  semantic_analysis(root);

  if (semantic_err)
    return (1);

  print_sem_ast(root);
  return (0);
}
