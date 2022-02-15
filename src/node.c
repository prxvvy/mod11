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

#include "include/node.h"

#include <stdlib.h>
#include <string.h>

Node *CreateNode(void *p_value, size_t valueSize) {
    Node *self = calloc(1, sizeof(struct Node));

    self->p_value = calloc(1, valueSize);

    memcpy(self->p_value, p_value, valueSize);

    self->p_next = NULL;
    self->p_previous = NULL;

    return self;
}

Bool DestroyNode(Node *p_node) {
    free(p_node->p_value);
    free(p_node);
    return TRUE;
}
