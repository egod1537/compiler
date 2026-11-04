#ifndef AST_ASSERT_H
#define AST_ASSERT_H

#include "../type.h"

void checkPrecedence(A_NODE *node);
void checkParentheses(A_NODE *root);

#endif // !AST_ASSERT_H
