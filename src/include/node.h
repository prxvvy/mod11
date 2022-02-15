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

#ifndef CLINKEDLIST_NODE_H
#define CLINKEDLIST_NODE_H

#include <stddef.h>

#include "bool.h"

typedef struct Node {
    void *p_value;
    struct Node *p_next;
    struct Node *p_previous;
} Node;

Node *CreateNode(void *p_value, size_t valueSize);

Bool DestroyNode(Node *p_node);

#endif  // CLINKEDLIST_NODE_H
