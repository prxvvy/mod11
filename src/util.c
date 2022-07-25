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
// Created by prxvvy on 20/07/2022
//

#include "include/util.h"
#include <string.h>

int
strip (char *p_buffer, const char *p_str, const char *p_garbage)
{
  if (!p_buffer || !p_str || !p_garbage || !strlen (p_str))
    return 0;

  size_t p_str_end = strlen (p_str) - 1;
  int p_str_start = 0;
  int writer = 0;

  for (int idx = (int)p_str_end; idx >= 0 && p_str[idx] == ' '; --idx)
    p_str_end--;

  for (int idx = (int)p_str_start; p_str[idx] != 00 && p_str[idx] == ' ';
       ++idx)
    p_str_start++;

  for (int idx = p_str_start; idx < (int)p_str_end + 1; ++idx)
    {

      for (int sbindx = 0; p_garbage[sbindx] != 00; ++sbindx)
        while (p_str[idx] == p_garbage[sbindx])
          p_buffer[writer] = p_str[idx++];

      p_buffer[writer++] = p_str[idx];
      p_buffer[writer] = 00;
    }

  return 1;
}

int
reverse_str (char *p_buffer, const char *p_str)
{
  if (!p_buffer || !p_str)
    return 0;
  int writer = 0;
  for (int idx = strlen (p_str) - 1; idx >= 0; --idx)
    {
      p_buffer[writer++] = p_str[idx];
      p_buffer[writer] = 00;
    }

  return 1;
}
