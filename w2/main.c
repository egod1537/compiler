#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER 256
#define PLUS 257
#define STAR 258
#define LPAREN 259
#define RPAREN 260
#define END 261

#define EXPRESSION 0
#define TERM 1
#define FACTOR 2

#define ACC 999

int action[12][6] = {{5, 0, 0, 4, 0, 0},     {0, 6, 0, 0, 0, ACC},   {0, -2, 7, 0, -2, -2},
                     {0, -4, -4, 0, -4, -4}, {5, 0, 0, 4, 0, 0},     {0, -6, -6, 0, -6, -6},
                     {5, 0, 0, 4, 0, 0},     {5, 0, 0, 4, 0, 0},     {0, 6, 0, 0, 11, 0},
                     {0, -1, 7, 0, -1, -1},  {0, -3, -3, 0, -3, -3}, {0, -5, -5, 0, -5, -5}};
int go_to[12][3] = {{1, 2, 3}, {0, 0, 0},  {0, 0, 0}, {0, 0, 0}, {8, 2, 3}, {0, 0, 0},
                    {0, 9, 3}, {0, 0, 10}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int prod_left[7] = {0, EXPRESSION, EXPRESSION, TERM, TERM, FACTOR, FACTOR};
int prod_length[7] = {0, 3, 1, 3, 1, 3, 1};

#define STACK_CAPACITY 1000
typedef struct {
  int data[STACK_CAPACITY];
  int top;
} Stack;

void stack_init(Stack *stack) { stack->top = -1; }

int stack_empty(const Stack *stack) { return stack->top < 0; }

int stack_size(const Stack *stack) { return stack->top + 1; }

void stack_push(Stack *stack, int value) {
  if (stack->top + 1 >= STACK_CAPACITY) {
    fprintf(stderr, "stack overflow\n");
    exit(EXIT_FAILURE);
  }

  stack->data[++stack->top] = value;
}

int stack_pop(Stack *stack) {
  if (stack_empty(stack)) {
    fprintf(stderr, "stack underflow\n");
    exit(EXIT_FAILURE);
  }

  return stack->data[stack->top--];
}

int stack_peek(const Stack *stack) {
  if (stack_empty(stack)) {
    fprintf(stderr, "stack is empty\n");
    exit(EXIT_FAILURE);
  }

  return stack->data[stack->top];
}

void stack_pop_n(Stack *stack, int count) {
  if (count < 0 || stack_size(stack) < count) {
    fprintf(stderr, "invalid stack pop count\n");
    exit(EXIT_FAILURE);
  }

  stack->top -= count;
}

void lex_error(void) {
  printf("lexical error\n");
  exit(EXIT_FAILURE);
}

int yylval;

int yylex(void) {
  static int ch = ' ';

  while (ch == ' ' || ch == '\t') {
    ch = getchar();
  }

  if (ch == '\n' || ch == EOF) {
    return END;
  }

  if (isdigit(ch)) {
    int value = 0;

    do {
      value = value * 10 + (ch - '0');
      ch = getchar();
    } while (isdigit(ch));

    yylval = value;
    return NUMBER;
  }

  if (ch == '+') {
    ch = getchar();
    return PLUS;
  }

  if (ch == '*') {
    ch = getchar();
    return STAR;
  }

  if (ch == '(') {
    ch = getchar();
    return LPAREN;
  }

  if (ch == ')') {
    ch = getchar();
    return RPAREN;
  }

  if (ch == EOF) {
    return END;
  }

  lex_error();
  return -1;
}

void yyerror(void) {
  printf("syntax error\n");
  exit(1);
}

int sym;
Stack gram, value;

void push(int i) { stack_push(&gram, i); }

void shift(int i) {
  push(i);

  if (sym == NUMBER) {
    stack_push(&value, yylval);
  } else {
    stack_push(&value, 0);
  }
  sym = yylex();
}

void reduce(int i) {
  int result;

  switch (i) {
  case 1: // E -> E + T
    result = value.data[value.top - 2] + value.data[value.top];
    break;

  case 2: // E -> T
    result = value.data[value.top];
    break;

  case 3: // T -> T * F
    result = value.data[value.top - 2] * value.data[value.top];
    break;

  case 4: // T -> F
    result = value.data[value.top];
    break;

  case 5: // F -> ( E )
    result = value.data[value.top - 1];
    break;

  case 6: // F -> n
    result = value.data[value.top];
    break;

  default:
    yyerror();
    return;
  }

  stack_pop_n(&gram, prod_length[i]);
  stack_pop_n(&value, prod_length[i]);

  int state = stack_peek(&gram);
  int lhs = prod_left[i];

  stack_push(&gram, go_to[state][lhs]);
  stack_push(&value, result);
}

void yyparse(void) {
  int i;
  stack_push(&gram, 0);
  sym = yylex();
  do {
    i = action[stack_peek(&gram)][sym - 256];
    if (i == ACC) {
      printf("%d\n", stack_peek(&value));
    } else if (i > 0) {
      shift(i);
    } else if (i < 0) {
      reduce(-i);
    } else {
      yyerror();
    }

  } while (i != ACC);
}

int main(void) {
  stack_init(&gram);
  stack_init(&value);

  yyparse();
  return 0;
}
