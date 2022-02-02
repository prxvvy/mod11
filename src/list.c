/* mod11 - A program to validate a Chilean RUT (id).
 * Copyright (C) 2021 prxvvy <qsk55464@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

//
// Created by prxvvy on 29-01-22.
//

#include "include/list.h"

#include <stdio.h>
#include <stdlib.h>

List *CreateList() {
    List *self = calloc(1, sizeof(struct List));
    self->size = 0;
    self->p_tail = NULL;
    self->p_head = NULL;
    return self;
}

unsigned int GetSize(List *p_list) { return p_list->size; }

Bool InsertAtBeginning(List *p_list, void *p_value, size_t valueSize) {
    Node *p_newNode = CreateNode(p_value, valueSize); /* Create a new node. */

    if (GetSize(p_list) == 0) return FirstEntry(p_list, p_newNode);

    p_newNode->p_next = p_list->p_head; /* Next pointer of new node points to
                                           the current head of the list. */
    p_list->p_head->p_previous = p_newNode;
    p_list->p_head = p_newNode; /* Update the head of the list. */
    p_list->p_tail->p_next =
        p_list->p_head; /* The tail of the list is still pointing to the old
                           head so update the next pointer of the tail to new
                           the head. */
    p_list->p_head->p_previous = p_list->p_tail;

    p_list->size++; /* Increment size */

    return TRUE;
}

Bool InsertAtEnd(List *p_list, void *p_value, size_t valueSize) {
    Node *p_newNode = CreateNode(p_value, valueSize); /* Create a new node. */

    if (GetSize(p_list) == 0) return FirstEntry(p_list, p_newNode);

    p_list->p_tail->p_next = p_newNode;
    p_newNode->p_previous = p_list->p_tail;
    p_list->p_tail = p_newNode;
    p_list->p_head->p_previous = p_list->p_tail;
    p_list->p_tail->p_next = p_list->p_head;

    p_list->size++;

    return TRUE;
}

Bool DestroyList(List *p_list) {
    free(p_list);
    return TRUE;
}

Bool DestroyEach(List *p_list) {
    if (GetSize(p_list) == 0) return FALSE;
    Node *p_node = p_list->p_head;

    for (unsigned int i = 0; i < GetSize(p_list); ++i) {
        Node *tmp = p_node;
        p_node = p_node->p_next;
        DestroyNode(tmp);
    }

    return TRUE;
}

Bool RemoveAtBeginning(List *p_list) {
    if (GetSize(p_list) == 0) return FALSE;

    Node *p_toDestroy = p_list->p_head;

    p_list->p_tail->p_next = p_list->p_head->p_next;
    p_list->p_head = p_list->p_head->p_next;
    p_list->p_head->p_previous = p_list->p_tail;

    p_list->size--;

    DestroyNode(p_toDestroy);

    return TRUE;
}

Bool RemoveAtEnd(List *p_list) {
    if (GetSize(p_list) == 0) return FALSE;

    Node *p_toDestroy = p_list->p_tail;

    p_list->p_head->p_previous = p_list->p_tail->p_previous;
    p_list->p_tail = p_list->p_tail->p_previous;
    p_list->p_tail->p_next = p_list->p_head;

    p_list->size--;

    DestroyNode(p_toDestroy);

    return TRUE;
}

Bool FirstEntry(List *p_list, Node *p_node) {
    /* Have the new node be the new head and tail of the list because it's
     * empty. */
    p_list->p_head = p_node;
    p_list->p_tail = p_node;

    /* We know as for now, it's the only node in the list, so we do this. */
    p_list->p_head->p_previous =
        p_list
            ->p_tail; /* Have it point itself as, currently, it's the only node
                         therefore, head and tail should point each other */
    p_list->p_tail->p_next = p_list->p_head;

    p_list->size++; /* Increment size of the list. */
    return TRUE;
}

Node *GetNodeAt(List *p_list, unsigned int index) {
    if (GetSize(p_list) == 0) return NULL;

    if (index > GetSize(p_list)) return 0;

    Node *p_node = p_list->p_head;

    for (unsigned int i = 0; i < GetSize(p_list); ++i) {
        if (i == index) return p_node;
        p_node = p_node->p_next;
    }

    exit(0);
}

Bool UnlinkNode(List *p_list, Node *p_node) {
    if (GetSize(p_list) == 0) return FALSE;

    if (p_node == p_list->p_head) {
        Node *p_toDestroy = p_list->p_head;

        p_list->p_tail->p_next = p_list->p_head->p_next;
        p_list->p_head = p_list->p_head->p_next;
        p_list->p_head->p_previous = p_list->p_tail;

        p_list->size--;
        DestroyNode(p_toDestroy);
        return TRUE;

    } else if (p_node == p_list->p_tail) {
        Node *p_toDestroy = p_list->p_tail;

        p_list->p_head->p_previous = p_list->p_tail->p_previous;
        p_list->p_tail = p_list->p_tail->p_previous;
        p_list->p_tail->p_next = p_list->p_head;

        p_list->size--;

        DestroyNode(p_toDestroy);
        return TRUE;
    } else {
        p_node->p_previous->p_next = p_node->p_next;
        p_node->p_next->p_previous = p_node->p_previous;

        p_list->size--;

        DestroyNode(p_node);

        return TRUE;
    }
}

int Insert(List *p_list, void *p_value, size_t valueSize, unsigned int index) {
    Node *p_newNode = CreateNode(p_value, valueSize); /* Create a new node */

    if (index == 0 && GetSize(p_list) == 0)
        return FirstEntry(
            p_list, p_newNode); /* If we wanna append to the 0 index && no nodes
                                   in the list, we do the first entry */
    else if (index == 0 &&
             GetSize(p_list) !=
                 0) /* If we still wanna append to the 0 index && lists's
                       already got some nodes, we update the head */
        return InsertAtBeginning(p_list, p_value, valueSize);

    /* After these first cases... */

    Node *p_node = p_list->p_head;

    index -= 1; /* Descrement index param -1 so that we stop looping at the
                   previous node of the desired index */

    for (unsigned int i = 0; i < GetSize(p_list); ++i) {
        if (i == index) break;
        p_node = p_node->p_next;
    }

    if (p_node == p_list->p_tail) /* If we've stopped at the tail of the list,
                                     well, we update the tail to append the new
                                     node right after it. */
        return InsertAtEnd(p_list, p_value, valueSize);
    else {
        p_node->p_next->p_previous = p_newNode;
        p_newNode->p_next = p_node->p_next;
        p_node->p_next = p_newNode;
        p_newNode->p_previous = p_node;
        p_list->size++;
        return 1;
    }
}
