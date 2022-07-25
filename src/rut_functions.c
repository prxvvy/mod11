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

#include "include/rut_functions.h"
#include "include/util.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int
mod11_rut_contains_letters (const char *p_rut)
{
  int final_char = strlen (p_rut) - 1;

  for (int idx = 0; p_rut[idx] != 00; ++idx)
    {
      if (idx == final_char)
        {
          if ((p_rut[idx] != 'k' && p_rut[idx] != 'K')
              && !isdigit (p_rut[idx]))
            return 1;
        }
      else if (!isdigit (p_rut[idx]))
        return 1;
    }

  return 0;
}

int
mod11_clean_rut (char *p_buffer, const char *p_rut)
{
  return !p_buffer || !p_rut ? 0 : strip (p_buffer, p_rut, "-/*.?![]{}=`, ");
}

char
mod11_get_checker_digit (const char *p_rut)
{
  if (!p_rut)
    return -1;

  char rut_clean[strlen (p_rut) + 1];
  char reverse_rut[strlen (p_rut) + 1];

  mod11_clean_rut (rut_clean, p_rut);

  if (strlen (rut_clean) < RUTWITHOUTDIGIT)
    return -1;

  if (strlen (rut_clean) > RUTWITHOUTDIGIT)
    {
      int writer = 0;
      for (int idx = 0; idx < RUTWITHOUTDIGIT;
           ++idx) /* Here we cut the string */
        rut_clean[writer++] = rut_clean[idx];
      rut_clean[writer] = 00;
    }

  for (int idx = 0; idx < RUTWITHOUTDIGIT; ++idx)
    if (!isdigit (rut_clean[idx]))
      return -1;

  reverse_str (reverse_rut, rut_clean);

  int digit;
  int multiplier = 1;
  int total = 0;

  for (int idx = 0; idx < RUTWITHOUTDIGIT; ++idx)
    {
      ++multiplier;
      if (multiplier == 8)
        multiplier = 2;
      int num = (int)reverse_rut[idx] - 48;
      total += num * multiplier;
    }

  digit = MOD11 - (total % MOD11);
  if (digit == MOD11)
    return '0';
  else if (digit == 10)
    return 'K';
  else
    return digit + '0';
}

int
mod11_is_rut_valid (const char *p_rut)
{
  if (!p_rut)
    return -1;

  char rut_clean[strlen (p_rut) + 1];

  mod11_clean_rut (rut_clean, p_rut);

  if (strlen (rut_clean) > RUTWITHDIGIT)
    {
      int writer = 0;

      for (int idx = 0; idx < RUTWITHDIGIT; ++idx)
        rut_clean[writer++] = rut_clean[idx];
      rut_clean[writer] = 00;
    }

  if (strlen (rut_clean) < RUTWITHDIGIT)
    return -1;
  else if (mod11_rut_contains_letters (rut_clean) == 1)
    return -1;

  char digit_from_buffer = rut_clean[RUTWITHDIGIT - 1];

  if (digit_from_buffer == 'k')
    digit_from_buffer = 'K';

  char digit_from_func = mod11_get_checker_digit (p_rut);
  return digit_from_buffer == digit_from_func ? 1 : 0;
}

int
mod11_format_rut (char *p_buffer, const char *p_rut, int dots)
{
  if (!p_buffer)
    return 0;

  char rut_clean[30];

  mod11_clean_rut (rut_clean, p_rut);

  if (strlen (rut_clean) < RUTWITHOUTDIGIT)
    return 0;
  else if (strlen (rut_clean) < RUTWITHDIGIT && strlen (rut_clean) > 7)
    {

      for (int idx = 0; idx < RUTWITHOUTDIGIT; ++idx)
        if (!isdigit (rut_clean[idx]))
          return 0;

      char digit_from_func = mod11_get_checker_digit (rut_clean);

      int end = strlen (rut_clean) - 1;
      rut_clean[end] = digit_from_func;
      rut_clean[end + 1] = digit_from_func;
    }

  if (strlen (rut_clean) > RUTWITHDIGIT)
    {
      int writer = 0;

      for (int idx = 0; idx < RUTWITHDIGIT; ++idx)
        rut_clean[writer++] = rut_clean[idx];
      rut_clean[writer] = 00;
    }

  int writer = 0;

  if (dots == 1)
    {

      for (int idx = 0; idx < RUTWITHDIGIT + 3; ++idx)
        {
          if (idx == 2)
            p_buffer[writer++] = '.';
          if (idx == 5)
            p_buffer[writer++] = '.';
          if (idx == 8)
            p_buffer[writer++] = '-';
          p_buffer[writer++] = rut_clean[idx];
          p_buffer[writer] = 00;
        }
    }
  else if (dots == 0)
    {
      for (int idx = 0; idx < RUTWITHDIGIT + 3; ++idx)
        {
          if (idx == 8)
            p_buffer[writer++] = '-';
          p_buffer[writer++] = rut_clean[idx];
          p_buffer[writer] = 00;
        }
    }
  else
    return 0;
  return 1;
}
