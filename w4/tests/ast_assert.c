
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

  if ((intptr_t)left->clink != 1 || (intptr_t)a->clink != 2 || (intptr_t)b->clink != 3)
    semanticError("Unexpected integer values");

  logMsg(LOG_SUCCESS, "AST precedence test passed");
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

  logMsg(LOG_SUCCESS, "AST parentheses test passed");
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

void AST_checkPreDecrement(A_NODE *root) {
  if (root == NULL || root->name != N_EXP_PRE_DEC)
    semanticError("Expected N_EXP_PRE_DEC");

  if (root->llink != NULL || root->rlink != NULL)
    semanticError("Invalid pre-decrement AST");

  A_NODE *operand = root->clink;

  if (operand == NULL || operand->name != N_EXP_IDENT)
    semanticError("Expected N_EXP_IDENT");

  A_ID *id = PTR(A_ID, operand->clink);

  if (id == NULL || strcmp(id->name, "x") != 0)
    semanticError("Expected identifier x");

  if (id->kind != ID_VAR || id->type != int_type)
    semanticError("Expected int variable");

  if (searchIdentifier("x") != id)
    semanticError("Identifier mismatch");

  logMsg(LOG_INFO, "AST pre-decrement test passed");
}

void AST_checkPostIncrement(A_NODE *root) {
  if (root == NULL || root->name != N_EXP_POST_INC)
    semanticError("Expected N_EXP_POST_INC");

  if (root->llink != NULL || root->rlink != NULL)
    semanticError("Invalid post-increment AST");

  A_NODE *operand = root->clink;

  if (operand == NULL || operand->name != N_EXP_IDENT)
    semanticError("Expected N_EXP_IDENT");

  A_ID *id = PTR(A_ID, operand->clink);

  if (id == NULL || strcmp(id->name, "x") != 0)
    semanticError("Expected identifier x");

  if (id->kind != ID_VAR || id->type != int_type)
    semanticError("Expected int variable");

  if (searchIdentifier("x") != id)
    semanticError("Identifier mismatch");

  logMsg(LOG_INFO, "AST post-increment test passed");
}

void AST_checkPostDecrement(A_NODE *root) {
  if (root == NULL || root->name != N_EXP_POST_DEC)
    semanticError("Expected N_EXP_POST_DEC");

  if (root->llink != NULL || root->rlink != NULL)
    semanticError("Invalid post-decrement AST");

  A_NODE *operand = root->clink;

  if (operand == NULL || operand->name != N_EXP_IDENT)
    semanticError("Expected N_EXP_IDENT");

  A_ID *id = PTR(A_ID, operand->clink);

  if (id == NULL || strcmp(id->name, "x") != 0)
    semanticError("Expected identifier x");

  if (id->kind != ID_VAR || id->type != int_type)
    semanticError("Expected int variable");

  if (searchIdentifier("x") != id)
    semanticError("Identifier mismatch");

  logMsg(LOG_INFO, "AST post-decrement test passed");
}

void AST_checkArrayAccess(A_NODE *root) {
  if (root == NULL || root->name != N_EXP_ARRAY)
    semanticError("Expected N_EXP_ARRAY");

  if (root->clink != NULL)
    semanticError("Invalid array AST structure");

  A_NODE *array = root->llink;
  A_NODE *index = root->rlink;

  if (array == NULL || array->name != N_EXP_IDENT)
    semanticError("Expected array identifier");

  A_ID *id = PTR(A_ID, array->clink);

  if (id == NULL || strcmp(id->name, "a") != 0)
    semanticError("Expected identifier a");

  if (id->kind != ID_VAR || id->type == NULL || id->type->kind != T_POINTER ||
      id->type->element_type != int_type)
    semanticError("Expected int pointer");

  if (searchIdentifier("a") != id)
    semanticError("Identifier mismatch");

  if (index == NULL || index->name != N_EXP_INT_CONST)
    semanticError("Expected integer index");

  if ((intptr_t)index->clink != 0)
    semanticError("Expected index 0");

  logMsg(LOG_INFO, "AST array access test passed");
}
void AST_checkArrayDeclaration(void) {
  A_ID *id = searchIdentifier("a");

  if (id == NULL)
    semanticError("Missing identifier a");

  if (id->kind != ID_VAR)
    semanticError("Expected ID_VAR");

  A_TYPE *type = id->type;

  if (type == NULL || type->kind != T_ARRAY)
    semanticError("Expected T_ARRAY");

  if (type->element_type != int_type)
    semanticError("Expected int element type");

  A_NODE *size = type->expr;

  if (size == NULL || size->name != N_EXP_INT_CONST)
    semanticError("Expected integer array size");

  if ((intptr_t)size->clink != 10)
    semanticError("Expected array size 10");

  logMsg(LOG_INFO, "AST array declaration test passed");
}
void AST_checkFunctionDeclarator(void) {
  A_ID *id = searchIdentifier("f");

  if (id == NULL)
    semanticError("Missing function f");

  if (id->kind != ID_FUNC)
    semanticError("Expected ID_FUNC");

  A_TYPE *type = id->type;

  if (type == NULL || type->kind != T_FUNC)
    semanticError("Expected T_FUNC");

  if (type->element_type != int_type)
    semanticError("Expected int return type");

  if (type->field != NULL)
    semanticError("Expected empty parameter list");

  logMsg(LOG_INFO, "AST function declarator test passed");
}

void AST_checkFunctionParameters(void) {
  A_ID *func = searchIdentifier("add");

  if (func == NULL || func->kind != ID_FUNC)
    semanticError("Expected function add");

  A_TYPE *type = func->type;

  if (type == NULL || type->kind != T_FUNC)
    semanticError("Expected T_FUNC");

  if (type->element_type != int_type)
    semanticError("Expected int return type");

  A_ID *a = type->field;
  A_ID *b = a != NULL ? a->link : NULL;

  if (a == NULL || b == NULL || b->link != NULL)
    semanticError("Expected two parameters");

  if (strcmp(a->name, "a") != 0 || strcmp(b->name, "b") != 0)
    semanticError("Incorrect parameter names");

  if (a->kind != ID_PARM || b->kind != ID_PARM)
    semanticError("Expected ID_PARM");

  if (a->type != int_type || b->type != int_type)
    semanticError("Incorrect parameter types");

  logMsg(LOG_INFO, "AST function parameters test passed");
}

void AST_checkReturn(A_NODE *root) {
  if (root == NULL || root->name != N_STMT_RETURN)
    semanticError("Expected N_STMT_RETURN");

  if (root->llink != NULL || root->rlink != NULL)
    semanticError("Invalid return AST structure");

  A_NODE *expr = root->clink;

  if (expr == NULL || expr->name != N_EXP_INT_CONST)
    semanticError("Expected N_EXP_INT_CONST");

  if ((intptr_t)expr->clink != 123)
    semanticError("Expected return value 123");

  logMsg(LOG_INFO, "AST return test passed");
}
void AST_checkCompoundReturn(A_NODE *root) {
  if (root == NULL || root->name != N_STMT_COMPOUND)
    semanticError("Expected N_STMT_COMPOUND");

  if (root->llink != NULL || root->clink != NULL)
    semanticError("Invalid compound structure");

  A_NODE *list = root->rlink;

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Expected N_STMT_LIST");

  A_NODE *ret = list->llink;

  if (ret == NULL || ret->name != N_STMT_RETURN)
    semanticError("Expected N_STMT_RETURN");

  A_NODE *expr = ret->clink;

  if (expr == NULL || expr->name != N_EXP_INT_CONST)
    semanticError("Expected integer expression");

  if ((intptr_t)expr->clink != 123)
    semanticError("Expected value 123");

  if (list->rlink == NULL || list->rlink->name != N_STMT_LIST_NIL)
    semanticError("Expected list terminator");

  logMsg(LOG_INFO, "AST compound return test passed");
}

void AST_checkFunctionScope(void) {
  A_ID *func = searchIdentifier("add");

  if (func == NULL || func->kind != ID_FUNC)
    semanticError("Missing function add");

  if (current_level != 0)
    semanticError("Function scope not closed");

  if (searchIdentifier("a") != NULL || searchIdentifier("b") != NULL)
    semanticError("Parameter scope leaked");

  A_TYPE *type = func->type;
  if (type == NULL || type->kind != T_FUNC)
    semanticError("Expected T_FUNC");

  A_ID *a = type->field;
  A_ID *b = a ? a->link : NULL;

  if (a == NULL || b == NULL || a->kind != ID_PARM || b->kind != ID_PARM)
    semanticError("Invalid parameters");

  A_NODE *body = type->expr;
  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Missing function body");

  A_NODE *list = body->rlink;
  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing statement list");

  A_NODE *ret = list->llink;
  if (ret == NULL || ret->name != N_STMT_RETURN)
    semanticError("Missing return statement");

  A_NODE *add = ret->clink;
  if (add == NULL || add->name != N_EXP_ADD)
    semanticError("Expected N_EXP_ADD");

  A_NODE *left = add->llink;
  A_NODE *right = add->rlink;

  if (left == NULL || right == NULL || left->name != N_EXP_IDENT ||
      right->name != N_EXP_IDENT)
    semanticError("Invalid parameter expressions");

  if (PTR(A_ID, left->clink) != a || PTR(A_ID, right->clink) != b)
    semanticError("Parameter references mismatch");

  logMsg(LOG_INFO, "AST function scope test passed");
}
