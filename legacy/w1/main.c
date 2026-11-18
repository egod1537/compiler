#include <stdio.h>
#include <stdlib.h>

#define DEBUG_ 0

enum { NULL_, PLUS, STAR, NUMBER, LPAREN, RPAREN, END } token;

void get_token(void) {
  int ch = getchar();
  while (ch == ' ' || ch == '\t') {
    ch = getchar();
  }

  if (ch == '+') {
    token = PLUS;
  } else if (ch == '*') {
    token = STAR;
  } else if (ch == '(') {
    token = LPAREN;
  } else if (ch == ')') {
    token = RPAREN;
  } else if (ch >= '0' && ch <= '9') {

    while (1) {
      ch = getchar();

      if (!(ch >= '0' && ch <= '9')) {
        break;
      }
    }

    if (ch != EOF) {
      ungetc(ch, stdin);
    }

    token = NUMBER;
  } else if (ch == '\n' || ch == EOF) {
    token = END;
  } else {
    token = NULL_;
  }
}

void error(const char *msg) {
  if (DEBUG_) {
    printf("Error: %s\n", msg);
  }

  printf("No\n");
  exit(0);
}

void term(void);
void factor(void);

void expression(void) {
  term();

  while (token == PLUS) {
    get_token();
    term();
  }
}

void term(void) {
  factor();

  while (token == STAR) {
    get_token();
    factor();
  }
}

void factor(void) {
  if (token == NUMBER) {
    get_token();

  } else if (token == LPAREN) {
    get_token();
    expression();

    if (token == RPAREN) {
      get_token();
    } else {
      error("expected ')'");
    }

  } else {
    error("expected number or '('");
  }
}

int main(void) {
  get_token();
  expression();

  if (token != END) {
    error("unexpected token after expression");
  }

  printf("Yes\n");

  return 0;
}
