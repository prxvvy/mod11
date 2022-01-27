//
// Created by prxvvy on 27-01-22.
//

#include <stdlib.h>
#include <string.h>
#include "include/node.h"

Node *CreateNode(void *p_value, size_t size) {
    Node *self = calloc(1, sizeof(struct Node));
    self->p_value = calloc(1, size);
    memcpy(self->p_value, p_value, size);
    self->p_next = NULL;
    self->p_previous = NULL;
    return self;
}

Bool DestroyNode(Node *p_node) {
    free(p_node->p_value);
    free(p_node);
    return TRUE;
}