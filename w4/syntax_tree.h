#ifndef SYNTAX_TREE_H
#define SYNTAX_TREE_H

#include "type.h"

extern A_NODE *expression_root;
extern A_NODE *statement_root;
extern A_NODE *compound_root;
extern A_NODE *program_root;

A_NODE *makeNode(NODE_NAME name, A_NODE *left, A_NODE *center, A_NODE *right);
A_NODE *makeNodeList(NODE_NAME name, A_NODE *list, A_NODE *item);

#endif
