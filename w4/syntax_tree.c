#include "semantic.h"
#include "type.h"
#include <stdlib.h>

A_NODE *expression_root = NULL;
A_NODE *statement_root = NULL;
A_NODE *compound_root = NULL;

A_NODE *makeNode(NODE_NAME name, A_NODE *left, A_NODE *center, A_NODE *right) {
  A_NODE *node = calloc(1, sizeof(A_NODE));

  if (node == NULL) {
    semanticError("memory allocation failed");
  }

  node->name = name;
  node->llink = left;
  node->clink = center;
  node->rlink = right;

  return node;
}

A_NODE *makeNodeList(NODE_NAME name, A_NODE *list, A_NODE *item) {
  if (list == NULL || item == NULL)
    semanticError("Invalid node list");

  NODE_NAME nil;

  switch (name) {
  case N_STMT_LIST:
    nil = N_STMT_LIST_NIL;
    break;
  case N_ARG_LIST:
    nil = N_ARG_LIST_NIL;
    break;

  default:
    semanticError("Unsupported list type");
    return NULL;
  }

  A_NODE *current = list;

  while (current->name == name) {
    if (current->rlink == NULL)
      semanticError("invalid list structure");

    current = current->rlink;
  }

  if (current->name != nil)
    semanticError("Invalid list terminator");

  current->name = name;
  current->llink = item;
  current->clink = NULL;
  current->rlink = makeNode(nil, NULL, NULL, NULL);

  return list;
}
