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

#ifndef _RUT_FUNCTIONS_H_
#define _RUT_FUNCTIONS_H_

#define MOD11 11
#define RUTWITHOUTDIGIT 8
#define RUTWITHDIGIT 9

int mod11_clean_rut (char *, const char *);

char mod11_get_checker_digit (const char *);

int mod11_is_rut_valid (const char *);

int mod11_format_rut (char *, const char *, int);

int mod11_rut_contains_letters (const char *);

#endif // _RUT_FUNCTIONS_H_
