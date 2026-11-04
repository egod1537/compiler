
#include "ast_assert.h"
#include "../logger.h"
#include "../semantic.h"

#include <stdint.h>

void checkPrecedence(A_NODE *node) {
  if (node == NULL || node->name != N_EXP_ADD)
    semanticError("Expected N_EXP_ADD");

  A_NODE *left = node->llink;
  A_NODE *right = node->rlink;

  if (left == NULL || right == NULL)
    semanticError("Missing AST operand");

  if (left->name != N_EXP_INT_CONST || right->name != N_EXP_MUL)
    semanticError("Incorrect operator precedence");

  A_NODE *a = right->llink;
  A_NODE *b = right->rlink;

  if (a == NULL || b == NULL || a->name != N_EXP_INT_CONST ||
      b->name != N_EXP_INT_CONST)
    semanticError("Invalid multiplication operands");

  if ((intptr_t)left->clink != 1 || (intptr_t)a->clink != 2 ||
      (intptr_t)b->clink != 3)
    semanticError("Unexpected integer values");

  logMsg(LOG_INFO, "AST precedence test passed");
}

void checkParentheses(A_NODE *root) {
  if (root == NULL || root->name != N_EXP_MUL)
    semanticError("Expected N_EXP_MUL root");

  A_NODE *add = root->llink;
  A_NODE *three = root->rlink;

  if (add == NULL || add->name != N_EXP_ADD)
    semanticError("Expected N_EXP_ADD as left child");

  if (three == NULL || three->name != N_EXP_INT_CONST)
    semanticError("Expected integer as right child");

  A_NODE *one = add->llink;
  A_NODE *two = add->rlink;

  if (one == NULL || two == NULL || one->name != N_EXP_INT_CONST ||
      two->name != N_EXP_INT_CONST)
    semanticError("Invalid addition operands");

  if ((intptr_t)one->clink != 1 || (intptr_t)two->clink != 2 ||
      (intptr_t)three->clink != 3)
    semanticError("Incorrect integer values");

  logMsg(LOG_INFO, "AST parentheses test passed");
}
