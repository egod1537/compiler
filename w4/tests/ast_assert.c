
#include "ast_assert.h"
#include "../logger.h"
#include "../parse_value.h"
#include "../semantic.h"

#include <stdint.h>
#include <string.h>

void AST_checkPrecedence(A_NODE *node) {
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

void AST_checkParentheses(A_NODE *root) {
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

void AST_checkIdentifierAST(A_NODE *root) {
  if (root == NULL || root->name != N_EXP_IDENT)
    semanticError("Expected N_EXP_IDENT");

  A_ID *id = PTR(A_ID, root->clink);

  if (id == NULL)
    semanticError("Missing identifier");

  if (strcmp(id->name, "x") != 0)
    semanticError("Incorrect identifier name");

  if (id->kind != ID_VAR)
    semanticError("Expected ID_VAR");

  if (id->type != int_type)
    semanticError("Expected int_type");

  logMsg(LOG_INFO, "AST identifier test passed");
}

void AST_checkPointerDeclaration(void) {
  A_ID *p = searchIdentifier("p");
  A_ID *pp = searchIdentifier("pp");

  if (p == NULL || pp == NULL)
    semanticError("Missing pointer declarations");

  if (p->kind != ID_VAR || pp->kind != ID_VAR)
    semanticError("Expected ID_VAR");

  if (p->type == NULL || p->type->kind != T_POINTER ||
      p->type->element_type != int_type)
    semanticError("Incorrect type for p");

  A_TYPE *t = pp->type;

  if (t == NULL || t->kind != T_POINTER)
    semanticError("Expected pointer type for pp");

  t = t->element_type;

  if (t == NULL || t->kind != T_POINTER || t->element_type != int_type)
    semanticError("Incorrect type for pp");

  logMsg(LOG_INFO, "AST pointer declaration test passed");
}

void AST_checkPointerDereference(A_NODE *root) {
  if (root == NULL || root->name != N_EXP_STAR)
    semanticError("Expected N_EXP_STAR");

  if (root->llink != NULL || root->rlink != NULL)
    semanticError("Invalid dereference AST structure");

  A_NODE *operand = root->clink;

  if (operand == NULL || operand->name != N_EXP_IDENT)
    semanticError("Expected N_EXP_IDENT operand");

  A_ID *id = PTR(A_ID, operand->clink);

  if (id == NULL || strcmp(id->name, "p") != 0)
    semanticError("Expected identifier p");

  if (id->kind != ID_VAR)
    semanticError("Expected ID_VAR");

  if (id->type == NULL || id->type->kind != T_POINTER ||
      id->type->element_type != int_type)
    semanticError("Expected pointer to int");

  logMsg(LOG_INFO, "AST pointer dereference test passed");
}

void AST_checkAddressOf(A_NODE *root) {
  if (root == NULL || root->name != N_EXP_AMP)
    semanticError("Expected N_EXP_AMP");

  if (root->llink != NULL || root->rlink != NULL)
    semanticError("Invalid address-of AST structure");

  A_NODE *operand = root->clink;

  if (operand == NULL || operand->name != N_EXP_IDENT)
    semanticError("Expected N_EXP_IDENT operand");

  A_ID *id = PTR(A_ID, operand->clink);

  if (id == NULL || strcmp(id->name, "x") != 0)
    semanticError("Expected identifier x");

  if (id->kind != ID_VAR || id->type != int_type)
    semanticError("Expected int variable");

  if (searchIdentifier("x") != id)
    semanticError("Identifier mismatch");

  logMsg(LOG_INFO, "AST address-of test passed");
}

void AST_checkUnaryMinus(A_NODE *root) {
  if (root == NULL || root->name != N_EXP_MINUS)
    semanticError("Expected N_EXP_MINUS");

  if (root->llink != NULL || root->rlink != NULL)
    semanticError("Invalid unary minus AST structure");

  A_NODE *operand = root->clink;

  if (operand == NULL || operand->name != N_EXP_INT_CONST)
    semanticError("Expected N_EXP_INT_CONST");

  if ((intptr_t)operand->clink != 5)
    semanticError("Expected integer value 5");

  logMsg(LOG_INFO, "AST unary minus test passed");
}

void AST_checkLogicalNot(A_NODE *root) {
  if (root == NULL || root->name != N_EXP_NOT)
    semanticError("Expected N_EXP_NOT");

  if (root->llink != NULL || root->rlink != NULL)
    semanticError("Invalid NOT AST structure");

  A_NODE *operand = root->clink;

  if (operand == NULL || operand->name != N_EXP_INT_CONST)
    semanticError("Expected N_EXP_INT_CONST");

  if ((intptr_t)operand->clink != 0)
    semanticError("Expected integer value 0");

  logMsg(LOG_INFO, "AST logical NOT test passed");
}

void AST_checkPreIncrement(A_NODE *root) {
  if (root == NULL || root->name != N_EXP_PRE_INC)
    semanticError("Expected N_EXP_PRE_INC");

  if (root->llink != NULL || root->rlink != NULL)
    semanticError("Invalid pre-increment AST structure");

  A_NODE *operand = root->clink;

  if (operand == NULL || operand->name != N_EXP_IDENT)
    semanticError("Expected N_EXP_IDENT");

  A_ID *id = (A_ID *)operand->clink;

  if (id == NULL || strcmp(id->name, "x") != 0)
    semanticError("Expected identifier x");

  if (id->kind != ID_VAR || id->type != int_type)
    semanticError("Expected int variable");

  if (searchIdentifier("x") != id)
    semanticError("Identifier mismatch");

  logMsg(LOG_INFO, "AST pre-increment test passed");
}
