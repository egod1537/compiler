#ifndef AST_ASSERT_H
#define AST_ASSERT_H

#include "../type.h"

void AST_checkPrecedence(A_NODE *node);
void AST_checkParentheses(A_NODE *root);
void AST_checkIdentifierAST(A_NODE *root);
void AST_checkPointerDeclaration(void);
void AST_checkPointerDereference(A_NODE *root);
void AST_checkAddressOf(A_NODE *root);
void AST_checkUnaryMinus(A_NODE *root);
void AST_checkLogicalNot(A_NODE *root);
void AST_checkPreIncrement(A_NODE *root);

#endif // !AST_ASSERT_H
