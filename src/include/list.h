/* mod11 - A program to validate a Chilean RUT (id).
 * Copyright (C) 2022 prxvvy <qsk55464@gmail.com>
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

#ifndef CLINKEDLIST_LIST_H
#define CLINKEDLIST_LIST_H

#include "node.h"

typedef struct List {
    unsigned int size;
    Node *p_head;
    Node *p_tail;
} List;

List *CreateList();

unsigned int GetSize(List *p_list);

Bool InsertAtBeginning(List *p_list, void *p_value, size_t valueSize);

Bool InsertAtEnd(List *p_list, void *p_value, size_t valueSize);

Bool RemoveAtBeginning(List *p_list);

Bool RemoveAtEnd(List *p_list);

Bool FirstEntry(List *p_list, Node *p_node);

Bool DestroyList(List *p_list);

Bool DestroyEach(List *p_list);

Node *GetNodeAt(List *p_list, unsigned int index);

Bool UnlinkNode(List *p_list, Node *p_node);

int Insert(List *p_list, void *p_value, size_t valueSize, unsigned int index);

#endif  // CLINKEDLIST_LIST_H
