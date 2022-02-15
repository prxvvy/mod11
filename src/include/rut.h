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
// Created by prxvvy on 28-01-22.
//

#ifndef ALGORITHM_RUT_H
#define ALGORITHM_RUT_H

#include "bool.h"

#define MOD11 11
#define RUTWITHOUTDIGIT 8
#define RUTWITHDIGIT 9

char GetDigit(char *p_rut);

char *Clean(char *p_rut);

Bool ValidateRut(char *p_rut);

char *Format(char *p_rut, Bool dots);

#endif  // ALGORITHM_RUT_H
