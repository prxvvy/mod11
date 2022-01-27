//
// Created by prxvvy on 27-01-22.
//

#ifndef ALGORITHM_LIST_H
#define ALGORITHM_LIST_H

#include "node.h"

typedef struct List {
    unsigned int size;
    Node *p_head;
    Node *p_tail;
} List;

List *CreateList();

void DestroyEach(List *list);

Bool InsertAtBeginning(List *list, void *p_value, size_t size);

Bool InsertAtEnd(List *list, void *p_value, size_t size);

Bool FirstEntry(List *list, Node *p_firstNode);

Bool DestroyList(List *list);

unsigned int GetSize(List *list);

#endif //ALGORITHM_LIST_H
