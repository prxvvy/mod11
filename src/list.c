//
// Created by prxvvy on 28-01-22.
//

#include "include/list.h"
#include <stdlib.h>

void DestroyEach(List *list) {
    Node *p_node = list->p_head;
    for (int i = 0; i < GetSize(list); ++i) {
        Node *tmp = p_node;
        p_node = p_node->p_next;
        DestroyNode(tmp);
    }
}

List *CreateList() {
    List *self = calloc(1, sizeof(struct List));
    self->size = 0;
    self->p_head = NULL;
    self->p_tail = NULL;
    return self;
}

Bool InsertAtBeginning(List *list, void *p_value, size_t size) {
    Node *newNode = CreateNode(p_value, size);
    if (!GetSize(list)) {
        list->p_head = newNode;
        list->p_tail = newNode;
        list->p_head->p_previous = list->p_tail;
        list->p_tail->p_next = list->p_head;
        list->size++;
        return TRUE;
    }
    newNode->p_next = list->p_head;
    list->p_head = newNode;
    list->p_head->p_previous = list->p_tail;
    list->p_tail->p_next = list->p_head;
    list->size++;
    return TRUE;
}

Bool InsertAtEnd(List *list, void *p_value, size_t size) {
    Node *newNode = CreateNode(p_value, size);
    if (!GetSize(list)) {
        return FirstEntry(list, newNode);
    }

    Node *p_node = list->p_head;
    while (1) {
        p_node = p_node->p_next;
        if (p_node == list->p_head) break;
    }
    list->p_tail->p_next = newNode;
    newNode->p_previous = p_node;
    list->p_tail = newNode;
    list->p_tail->p_next = list->p_head;
    list->p_head->p_previous = list->p_tail;
    list->size++;
    return TRUE;
}

unsigned int GetSize(List *list) {
    return list->size;
}

Bool DestroyList(List *list) {
    free(list);
    return TRUE;
}

Bool FirstEntry(List *list, Node *p_firstNode) {
    list->p_head = p_firstNode;
    list->p_tail = p_firstNode;
    list->p_head->p_previous = list->p_tail;
    list->p_tail->p_next = list->p_head;
    list->size++;
    return TRUE;
}