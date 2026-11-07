#ifndef AST_RUNNER_H
#define AST_RUNNER_H

typedef enum {
  AST_MODE_NONE,
  AST_MODE_PRECEDENCE,
  AST_MODE_PARENTHESES,
  AST_MODE_PRINT
} AstTestMode;

int AST_parseTestMode(int argc, char **argv, AstTestMode *mode);
void AST_runDeclarationTests(void);
void AST_runExpressionTests(AstTestMode mode);
void AST_runStatementTests(void);
void AST_runExpectedTest(void);

#endif // !AST_RUNNER_H
