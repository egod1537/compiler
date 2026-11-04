#include "semantic.h"
#include "type.h"
#include <stdlib.h>

A_NODE *expression_root = NULL;

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
