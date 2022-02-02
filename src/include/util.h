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
// Created by prxvvy on 28-01-22.
//

#ifndef ALGORITHM_UTIL_H
#define ALGORITHM_UTIL_H

#include <stddef.h>

#include "bool.h"

/* Private struct for CutStr function. WIll be treated as return value. */

typedef struct CutRes {
    char *p_str1;
    char *p_str2;
} CutRes;

Bool DestroyCutRes(CutRes *res);

Bool Includes(char *p_input, char *p_toFind);

char *Strip(char *p_input, char *p_garbage);

CutRes *CutStr(char *p_input, unsigned int end, size_t newSize);

char *ReverseStr(char *p_input);

#endif  // ALGORITHM_UTIL_H
