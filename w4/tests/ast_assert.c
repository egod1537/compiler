
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
void AST_checkBlockShadowing(void) {
  A_ID *global = searchIdentifier("x");
  A_ID *func = searchIdentifier("main");

  if (global == NULL || func == NULL)
    semanticError("Missing global identifiers");

  if (current_level != 0)
    semanticError("Scope was not restored");

  if (global->level != 0 || global->type != int_type)
    semanticError("Invalid global x");

  A_NODE *body = func->type->expr;

  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Missing function body");

  A_ID *outer = PTR(A_ID, body->llink);

  if (outer == NULL || strcmp(outer->name, "x") != 0 || outer->level != 1)
    semanticError("Invalid outer x");

  A_NODE *inner = NULL;

  for (A_NODE *list = body->rlink; list != NULL && list->name == N_STMT_LIST;
       list = list->rlink) {

    if (list->llink != NULL && list->llink->name == N_STMT_COMPOUND) {
      inner = list->llink;
      break;
    }
  }

  if (inner == NULL)
    semanticError("Missing inner compound");

  A_ID *local = PTR(A_ID, inner->llink);

  if (local == NULL || strcmp(local->name, "x") != 0 || local->level != 2)
    semanticError("Invalid inner x");

  if (global == outer || outer == local || global == local)
    semanticError("Identifiers must be distinct");

  A_NODE *ret = NULL;

  for (A_NODE *list = body->rlink; list != NULL && list->name == N_STMT_LIST;
       list = list->rlink) {

    if (list->llink != NULL && list->llink->name == N_STMT_RETURN)
      ret = list->llink;
  }

  if (ret == NULL || ret->clink == NULL || ret->clink->name != N_EXP_IDENT)
    semanticError("Missing return identifier");

  if (PTR(A_ID, ret->clink->clink) != outer)
    semanticError("Incorrect identifier after shadowing");

  logMsg(LOG_INFO, "AST block shadowing test passed");
}

void AST_checkAssignment(void) {
  A_ID *func = searchIdentifier("main");

  if (func == NULL || func->type == NULL)
    semanticError("Missing main function");

  A_NODE *body = func->type->expr;

  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Expected compound statement");

  A_ID *x = PTR(A_ID, body->llink);

  if (x == NULL || strcmp(x->name, "x") != 0 || x->kind != ID_VAR ||
      x->type != int_type)
    semanticError("Invalid variable x");

  A_NODE *list = body->rlink;

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Expected statement list");

  A_NODE *stmt = list->llink;

  if (stmt == NULL || stmt->name != N_STMT_EXPRESSION)
    semanticError("Expected expression statement");

  A_NODE *assign = stmt->clink;

  if (assign == NULL || assign->name != N_EXP_ASSIGN)
    semanticError("Expected N_EXP_ASSIGN");

  A_NODE *left = assign->llink;
  A_NODE *right = assign->rlink;

  if (left == NULL || left->name != N_EXP_IDENT || PTR(A_ID, left->clink) != x)
    semanticError("Invalid assignment target");

  if (right == NULL || right->name != N_EXP_INT_CONST || (intptr_t)right->clink != 10)
    semanticError("Invalid assignment value");

  list = list->rlink;

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing return statement list");

  A_NODE *ret = list->llink;

  if (ret == NULL || ret->name != N_STMT_RETURN || ret->clink == NULL ||
      ret->clink->name != N_EXP_IDENT || PTR(A_ID, ret->clink->clink) != x)
    semanticError("Invalid return identifier");

  logMsg(LOG_INFO, "AST assignment test passed");
}
void AST_checkComparison(A_NODE *root, NODE_NAME expected, int lhs, int rhs) {
  if (root == NULL || root->name != expected)
    semanticError("Incorrect comparison node");

  if (root->clink != NULL)
    semanticError("Invalid comparison structure");

  A_NODE *left = root->llink;
  A_NODE *right = root->rlink;

  if (left == NULL || right == NULL)
    semanticError("Missing operands");

  if (left->name != N_EXP_INT_CONST || right->name != N_EXP_INT_CONST)
    semanticError("Expected integer operands");

  if ((intptr_t)left->clink != lhs || (intptr_t)right->clink != rhs)
    semanticError("Incorrect operand values");

  logMsg(LOG_INFO, "AST comparison test passed");
}
static void AST_checkIntValue(A_NODE *node, int value) {
  if (node == NULL || node->name != N_EXP_INT_CONST)
    semanticError("Expected N_EXP_INT_CONST");

  if ((intptr_t)node->clink != value)
    semanticError("Incorrect integer value");
}

void AST_checkLogical(A_NODE *root, int mode) {
  NODE_NAME expected = mode == 1 ? N_EXP_AND : N_EXP_OR;

  if (root == NULL || root->name != expected)
    semanticError("Incorrect logical AST root");

  if (root->clink != NULL)
    semanticError("Invalid logical AST structure");

  if (mode == 1) {
    AST_checkIntValue(root->llink, 1);
    AST_checkIntValue(root->rlink, 0);
  } else if (mode == 2) {
    AST_checkIntValue(root->llink, 0);
    AST_checkIntValue(root->rlink, 1);
  } else if (mode == 3) {
    AST_checkIntValue(root->llink, 1);

    A_NODE *and = root->rlink;

    if (and== NULL || and->name != N_EXP_AND || and->clink != NULL)
      semanticError("Incorrect logical precedence");

    AST_checkIntValue(and->llink, 0);
    AST_checkIntValue(and->rlink, 1);
  } else {
    semanticError("Unknown logical test mode");
  }

  logMsg(LOG_INFO, "AST logical test passed");
}

static A_NODE *AST_nthStatement(A_NODE *body, int n) {
  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Expected compound statement");

  A_NODE *list = body->rlink;

  while (n-- > 0) {
    if (list == NULL || list->name != N_STMT_LIST)
      semanticError("Statement index out of range");

    list = list->rlink;
  }

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing statement");

  return list->llink;
}

void AST_checkSelection(int mode) {
  A_ID *func = searchIdentifier("main");

  if (func == NULL || func->type == NULL)
    semanticError("Missing main function");

  A_NODE *body = func->type->expr;
  A_NODE *node;

  if (mode == 1) {
    // 36_if_statement.c
    node = AST_nthStatement(body, 1);

    if (node == NULL || node->name != N_STMT_IF || node->clink != NULL)
      semanticError("Expected N_STMT_IF");

    if (node->llink == NULL || node->llink->name != N_EXP_IDENT ||
        node->rlink == NULL || node->rlink->name != N_STMT_RETURN)
      semanticError("Invalid if structure");
  } else if (mode == 2) {
    // 07_if_else.c
    node = AST_nthStatement(body, 1);

    if (node == NULL || node->name != N_STMT_IF_ELSE)
      semanticError("Expected N_STMT_IF_ELSE");

    if (node->llink == NULL || node->llink->name != N_EXP_GTR || node->clink == NULL ||
        node->clink->name != N_STMT_RETURN || node->rlink == NULL ||
        node->rlink->name != N_STMT_RETURN)
      semanticError("Invalid if-else structure");
  } else if (mode == 3) {
    // 37_if_else_nested.c
    node = AST_nthStatement(body, 2);

    if (node == NULL || node->name != N_STMT_IF || node->clink != NULL)
      semanticError("Expected outer if");

    A_NODE *inner = node->rlink;

    if (inner == NULL || inner->name != N_STMT_IF_ELSE)
      semanticError("Dangling else bound incorrectly");

    if (inner->llink == NULL || inner->llink->name != N_EXP_IDENT ||
        inner->clink == NULL || inner->clink->name != N_STMT_RETURN ||
        inner->rlink == NULL || inner->rlink->name != N_STMT_RETURN)
      semanticError("Invalid nested if-else");
  } else {
    semanticError("Unknown selection test mode");
  }

  logMsg(LOG_INFO, "AST selection test passed");
}

static A_NODE *AST_iterationStatement(A_NODE *body, int index) {
  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Expected compound body");

  A_NODE *list = body->rlink;

  while (index-- > 0) {
    if (list == NULL || list->name != N_STMT_LIST)
      semanticError("Missing statement");
    list = list->rlink;
  }

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing iteration statement");

  return list->llink;
}

void AST_checkIteration(int mode) {
  A_ID *func = searchIdentifier("main");

  if (func == NULL || func->type == NULL)
    semanticError("Missing main function");

  A_NODE *body = func->type->expr;
  A_NODE *node = AST_iterationStatement(body, mode == 3 ? 0 : 1);

  if (node == NULL)
    semanticError("Null iteration statement");

  if (mode == 1) {
    // while
    if (node->name != N_STMT_WHILE || node->llink == NULL ||
        node->llink->name != N_EXP_LSS || node->clink != NULL || node->rlink == NULL ||
        node->rlink->name != N_STMT_EXPRESSION)
      semanticError("Invalid while AST");
  } else if (mode == 2) {
    // do-while
    if (node->name != N_STMT_DO || node->llink == NULL ||
        node->llink->name != N_STMT_EXPRESSION || node->clink != NULL ||
        node->rlink == NULL || node->rlink->name != N_EXP_LSS)
      semanticError("Invalid do-while AST");
  } else if (mode == 3) {
    // for
    if (node->name != N_STMT_FOR || node->clink != NULL || node->rlink == NULL ||
        node->rlink->name != N_STMT_EMPTY)
      semanticError("Invalid for AST");

    A_NODE *exp = node->llink;

    if (exp == NULL || exp->name != N_FOR_EXP)
      semanticError("Missing N_FOR_EXP");

    if (exp->llink == NULL || exp->llink->name != N_EXP_ASSIGN || exp->clink == NULL ||
        exp->clink->name != N_EXP_LSS || exp->rlink == NULL ||
        exp->rlink->name != N_EXP_POST_INC)
      semanticError("Invalid for expressions");
  } else {
    semanticError("Unknown iteration test");
  }

  logMsg(LOG_INFO, "AST iteration test passed");
}

void AST_checkBreakContinue(void) {
  A_ID *func = searchIdentifier("main");

  if (func == NULL || func->type == NULL)
    semanticError("Missing main function");

  A_NODE *body = func->type->expr;
  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Missing function body");

  // main: i = 0; while (...) { ... } return i;
  A_NODE *list = body->rlink;

  if (list == NULL || list->name != N_STMT_LIST || list->rlink == NULL ||
      list->rlink->name != N_STMT_LIST)
    semanticError("Invalid main statement list");

  A_NODE *loop = list->rlink->llink;

  if (loop == NULL || loop->name != N_STMT_WHILE)
    semanticError("Expected while statement");

  A_NODE *block = loop->rlink;

  if (block == NULL || block->name != N_STMT_COMPOUND)
    semanticError("Expected while compound body");

  // while body: i++; if (...) continue; if (...) break;
  list = block->rlink;

  if (list == NULL || list->name != N_STMT_LIST || list->rlink == NULL ||
      list->rlink->name != N_STMT_LIST || list->rlink->rlink == NULL ||
      list->rlink->rlink->name != N_STMT_LIST)
    semanticError("Invalid while statement list");

  A_NODE *if_continue = list->rlink->llink;
  A_NODE *if_break = list->rlink->rlink->llink;

  if (if_continue == NULL || if_continue->name != N_STMT_IF ||
      if_continue->rlink == NULL || if_continue->rlink->name != N_STMT_CONTINUE)
    semanticError("Invalid continue AST");

  if (if_break == NULL || if_break->name != N_STMT_IF || if_break->rlink == NULL ||
      if_break->rlink->name != N_STMT_BREAK)
    semanticError("Invalid break AST");

  A_NODE *cont = if_continue->rlink;
  A_NODE *brk = if_break->rlink;

  if (cont->llink != NULL || cont->clink != NULL || cont->rlink != NULL ||
      brk->llink != NULL || brk->clink != NULL || brk->rlink != NULL)
    semanticError("Jump nodes must be leaf nodes");

  logMsg(LOG_INFO, "AST break/continue test passed");
}
void AST_checkVoidReturn(void) {
  A_ID *func = searchIdentifier("done");

  if (func == NULL || func->kind != ID_FUNC)
    semanticError("Missing done function");

  if (func->type == NULL || func->type->kind != T_FUNC ||
      func->type->element_type != void_type)
    semanticError("Invalid void function type");

  A_NODE *body = func->type->expr;

  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Missing function body");

  A_NODE *list = body->rlink;

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing statement list");

  A_NODE *ret = list->llink;

  if (ret == NULL || ret->name != N_STMT_RETURN)
    semanticError("Expected N_STMT_RETURN");

  if (ret->llink != NULL || ret->clink != NULL || ret->rlink != NULL)
    semanticError("Void return must have no expression");

  if (list->rlink == NULL || list->rlink->name != N_STMT_LIST_NIL)
    semanticError("Invalid statement list terminator");

  logMsg(LOG_INFO, "AST void return test passed");
}

void AST_checkFunctionCall(void) {
  A_ID *func = searchIdentifier("main");
  A_ID *add = searchIdentifier("add");

  if (func == NULL || add == NULL)
    semanticError("Missing functions");

  A_NODE *body = func->type->expr;

  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Missing main body");

  A_NODE *list = body->rlink;

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing statement list");

  A_NODE *ret = list->llink;

  if (ret == NULL || ret->name != N_STMT_RETURN)
    semanticError("Expected return statement");

  A_NODE *call = ret->clink;

  if (call == NULL || call->name != N_EXP_FUNCTION_CALL || call->clink != NULL)
    semanticError("Expected function call");

  A_NODE *callee = call->llink;

  if (callee == NULL || callee->name != N_EXP_IDENT || PTR(A_ID, callee->clink) != add)
    semanticError("Incorrect called function");

  A_NODE *args = call->rlink;

  for (int expected = 1; expected <= 2; expected++) {
    if (args == NULL || args->name != N_ARG_LIST)
      semanticError("Invalid argument list");

    A_NODE *value = args->llink;

    if (value == NULL || value->name != N_EXP_INT_CONST ||
        (intptr_t)value->clink != expected)
      semanticError("Incorrect argument");

    args = args->rlink;
  }

  if (args == NULL || args->name != N_ARG_LIST_NIL)
    semanticError("Invalid argument list terminator");

  logMsg(LOG_INFO, "AST function call test passed");
}

void AST_checkSizeofExpression(void) {
  A_ID *func = searchIdentifier("main");

  if (func == NULL || func->type == NULL)
    semanticError("Missing main function");

  A_NODE *body = func->type->expr;

  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Missing function body");

  A_ID *x = PTR(A_ID, body->llink);

  if (x == NULL || strcmp(x->name, "x") != 0 || x->type != int_type)
    semanticError("Missing variable x");

  A_NODE *list = body->rlink;

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing statement list");

  A_NODE *ret = list->llink;

  if (ret == NULL || ret->name != N_STMT_RETURN)
    semanticError("Expected return statement");

  A_NODE *size = ret->clink;

  if (size == NULL || size->name != N_EXP_SIZE_EXP || size->llink != NULL ||
      size->rlink != NULL)
    semanticError("Invalid sizeof expression");

  A_NODE *operand = size->clink;

  if (operand == NULL || operand->name != N_EXP_IDENT || PTR(A_ID, operand->clink) != x)
    semanticError("Incorrect sizeof operand");

  logMsg(LOG_INFO, "AST sizeof expression test passed");
}

void AST_checkSizeofType(void) {
  A_ID *func = searchIdentifier("main");

  if (func == NULL || func->type == NULL)
    semanticError("Missing main function");

  A_NODE *body = func->type->expr;

  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Missing function body");

  A_NODE *list = body->rlink;

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing statement list");

  A_NODE *ret = list->llink;

  if (ret == NULL || ret->name != N_STMT_RETURN)
    semanticError("Expected return statement");

  A_NODE *size = ret->clink;

  if (size == NULL || size->name != N_EXP_SIZE_TYPE || size->llink != NULL ||
      size->rlink != NULL)
    semanticError("Invalid sizeof type AST");

  A_TYPE *type = PTR(A_TYPE, size->clink);

  if (type != int_type)
    semanticError("Expected int_type");

  if (list->rlink == NULL || list->rlink->name != N_STMT_LIST_NIL)
    semanticError("Invalid statement list terminator");

  logMsg(LOG_INFO, "AST sizeof type test passed");
}
void AST_checkCastExpression(void) {
  A_ID *func = searchIdentifier("main");

  if (func == NULL || func->type == NULL)
    semanticError("Missing main function");

  A_NODE *body = func->type->expr;

  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Missing function body");

  A_NODE *list = body->rlink;

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing statement list");

  A_NODE *ret = list->llink;

  if (ret == NULL || ret->name != N_STMT_RETURN)
    semanticError("Expected return statement");

  A_NODE *cast = ret->clink;

  if (cast == NULL || cast->name != N_EXP_CAST || cast->clink != NULL)
    semanticError("Invalid cast AST");

  A_TYPE *type = PTR(A_TYPE, cast->llink);

  if (type != int_type)
    semanticError("Expected cast to int");

  A_NODE *operand = cast->rlink;

  if (operand == NULL || operand->name != N_EXP_FLOAT_CONST)
    semanticError("Expected float operand");

  const char *value = PTR(char, operand->clink);

  if (value == NULL || strcmp(value, "3.5") != 0)
    semanticError("Incorrect float literal");

  if (list->rlink == NULL || list->rlink->name != N_STMT_LIST_NIL)
    semanticError("Invalid statement list terminator");

  logMsg(LOG_INFO, "AST cast expression test passed");
}

void AST_checkSwitch(void) {
  A_ID *func = searchIdentifier("main");

  if (func == NULL || func->type == NULL)
    semanticError("Missing main function");

  A_NODE *body = func->type->expr;

  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Missing function body");

  A_NODE *sw = NULL;

  // main 함수의 최상위 문장 목록에서 switch 검색
  for (A_NODE *p = body->rlink; p != NULL && p->name == N_STMT_LIST; p = p->rlink) {

    if (p->llink != NULL && p->llink->name == N_STMT_SWITCH) {
      sw = p->llink;
      break;
    }
  }

  if (sw == NULL)
    semanticError("Missing N_STMT_SWITCH");

  if (sw->llink == NULL || sw->llink->name != N_EXP_IDENT || sw->clink != NULL)
    semanticError("Invalid switch condition");

  A_NODE *block = sw->rlink;

  if (block == NULL || block->name != N_STMT_COMPOUND)
    semanticError("Invalid switch body");

  A_NODE *list = block->rlink;

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing case statement");

  A_NODE *case_stmt = list->llink;

  if (case_stmt == NULL || case_stmt->name != N_STMT_LABEL_CASE ||
      case_stmt->llink == NULL || case_stmt->llink->name != N_EXP_INT_CONST ||
      (intptr_t)case_stmt->llink->clink != 0 || case_stmt->clink != NULL ||
      case_stmt->rlink == NULL || case_stmt->rlink->name != N_STMT_EXPRESSION)
    semanticError("Invalid case AST");

  list = list->rlink;

  if (list == NULL || list->name != N_STMT_LIST || list->llink == NULL ||
      list->llink->name != N_STMT_BREAK)
    semanticError("Missing case break");

  list = list->rlink;

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing default statement");

  A_NODE *def = list->llink;

  if (def == NULL || def->name != N_STMT_LABEL_DEFAULT || def->llink != NULL ||
      def->clink != NULL || def->rlink == NULL || def->rlink->name != N_STMT_BREAK)
    semanticError("Invalid default AST");

  if (list->rlink == NULL || list->rlink->name != N_STMT_LIST_NIL)
    semanticError("Invalid switch statement list");

  logMsg(LOG_INFO, "AST switch test passed");
}

void AST_checkCharString(void) {
  A_ID *func = searchIdentifier("main");

  if (func == NULL || func->type == NULL)
    semanticError("Missing main function");

  A_NODE *body = func->type->expr;

  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Missing function body");

  A_NODE *list = body->rlink;

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing expression statement");

  A_NODE *stmt = list->llink;

  if (stmt == NULL || stmt->name != N_STMT_EXPRESSION)
    semanticError("Invalid expression statement");

  A_NODE *call = stmt->clink;

  if (call == NULL || call->name != N_EXP_FUNCTION_CALL)
    semanticError("Missing function call");

  A_NODE *args = call->rlink;

  if (args == NULL || args->name != N_ARG_LIST)
    semanticError("Missing argument list");

  A_NODE *str = args->llink;

  if (str == NULL || str->name != N_EXP_STRING_LITERAL)
    semanticError("Expected string literal");

  if (strcmp(PTR(char, str->clink), "\"hello\"") != 0)
    semanticError("Incorrect string literal");

  list = list->rlink;

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing return statement");

  A_NODE *ret = list->llink;

  if (ret == NULL || ret->name != N_STMT_RETURN)
    semanticError("Expected return statement");

  A_NODE *ch = ret->clink;

  if (ch == NULL || ch->name != N_EXP_CHAR_CONST)
    semanticError("Expected character literal");

  if (strcmp(PTR(char, ch->clink), "'A'") != 0)
    semanticError("Incorrect character literal");

  logMsg(LOG_INFO, "AST character/string test passed");
}
void AST_checkProgram(A_NODE *root) {
  if (root == NULL || root->name != N_PROGRAM)
    semanticError("Expected N_PROGRAM");

  if (root->llink != NULL || root->rlink != NULL)
    semanticError("Invalid program root");

  A_ID *head = PTR(A_ID, root->clink);

  if (head != current_id)
    semanticError("Incorrect symbol table head");

  const char *names[] = {"c", "b", "a"};

  A_ID *id = head;

  for (int i = 0; i < 3; i++) {
    if (id == NULL || strcmp(id->name, names[i]) != 0)
      semanticError("Incorrect global declaration order");

    if (id->kind != ID_VAR || id->type != int_type || id->level != 0)
      semanticError("Invalid global declaration");

    id = id->prev;
  }

  logMsg(LOG_INFO, "AST program root test passed");
}
void AST_checkStruct(int mode) {
  A_ID *origin = searchIdentifier("origin");

  if (origin == NULL || origin->type == NULL || origin->type->kind != T_STRUCT)
    semanticError("Missing struct variable origin");

  A_TYPE *point = origin->type;
  A_ID *point_tag = NULL;

  for (A_ID *id = current_id; id != NULL; id = id->prev) {
    if (id->kind == ID_STRUCT && strcmp(id->name, "Point") == 0) {
      point_tag = id;
      break;
    }
  }

  if (point_tag == NULL || point_tag->type != point ||
      point_tag->type->kind != T_STRUCT)
    semanticError("Invalid struct tag type");

  A_ID *x = point->field;
  A_ID *y = x != NULL ? x->link : NULL;

  if (x == NULL || y == NULL || y->link != NULL || strcmp(x->name, "x") != 0 ||
      strcmp(y->name, "y") != 0 || x->kind != ID_FIELD || y->kind != ID_FIELD ||
      x->type != int_type || y->type != int_type)
    semanticError("Invalid struct fields");

  if (searchIdentifier("x") != NULL || searchIdentifier("y") != NULL)
    semanticError("Struct field leaked into ordinary identifier namespace");

  for (A_ID *id = current_id; id != NULL; id = id->prev) {
    if (id == x || id == y)
      semanticError("Struct field leaked into identifier table");
  }

  if (mode == 1) {
    logMsg(LOG_INFO, "AST struct fields test passed");
    return;
  }

  A_ID *main_func = searchIdentifier("main");

  if (main_func == NULL || main_func->type == NULL)
    semanticError("Missing main");

  A_NODE *body = main_func->type->expr;

  if (body == NULL || body->name != N_STMT_COMPOUND)
    semanticError("Missing main body");

  A_NODE *list = body->rlink;

  // mode 3: p = &origin; 다음의 return 문
  if (mode == 3) {
    if (list == NULL || list->rlink == NULL)
      semanticError("Missing assignment");

    list = list->rlink;
  }

  if (list == NULL || list->name != N_STMT_LIST)
    semanticError("Missing return statement list");

  A_NODE *ret = list->llink;

  if (ret == NULL || ret->name != N_STMT_RETURN)
    semanticError("Expected return");

  A_NODE *access = ret->clink;
  NODE_NAME expected = mode == 2 ? N_EXP_STRUCT : N_EXP_ARROW;

  if (access == NULL || access->name != expected || access->llink == NULL ||
      access->clink != NULL || access->rlink == NULL ||
      strcmp(PTR(char, access->rlink), "x") != 0)
    semanticError("Invalid member access AST");

  A_NODE *base = access->llink;

  if (base->name != N_EXP_IDENT)
    semanticError("Invalid member base");

  A_ID *id = (A_ID *)base->clink;

  if (mode == 2) {
    if (id != origin)
      semanticError("Expected origin.x");
  } else if (mode == 3) {
    if (id == NULL || strcmp(id->name, "p") != 0 || id->type == NULL ||
        id->type->kind != T_POINTER || id->type->element_type != point)
      semanticError("Expected p->x");
  } else {
    semanticError("Unknown struct test mode");
  }

  logMsg(LOG_INFO, "AST struct member test passed");
}
