#ifndef SYNTAX_TREE_H
#define SYNTAX_TREE_H

#include "type.h"

extern A_NODE *expression_root;

A_NODE *makeNode(NODE_NAME name, A_NODE *left, A_NODE *center, A_NODE *right);

#endif
