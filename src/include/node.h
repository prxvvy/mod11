//
// Created by prxvvy on 27-01-22.
//

#ifndef ALGORITHM_NODE_H
#define ALGORITHM_NODE_H

#include <stddef.h>
#include "bool.h"

typedef struct Node {
    void *p_value;
    struct Node *p_next;
    struct Node *p_previous;
} Node;

Node *CreateNode(void *p_value, size_t size);

Bool DestroyNode(Node *p_node);

#endif //ALGORITHM_NODE_H
