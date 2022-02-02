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

#include "include/rut.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/list.h"
#include "include/util.h"

char *Clean(char *p_rut) {
    if (!p_rut) {
        printf("1 argument expected.");
        exit(0);
    }
    return Strip(p_rut, "-/*.?![]{}=`,");
}

Bool ValidateRut(char *p_rut) {
    if (!p_rut) {
        printf("1 argument expected.");
        exit(0);
    }

    char *p_tmpRut = Clean(p_rut); /* We clean the rut */
    CutRes *p_tmpRut1 =
        CutStr(p_tmpRut, RUTWITHOUTDIGIT,
               RUTWITHOUTDIGIT + 1); /* we store only 8 chars of the rut. */
    char *p_rutToWorkWith = ReverseStr(p_tmpRut1->p_str1); /* Reverse it */
    free(p_tmpRut);           /** We need it no more */
    DestroyCutRes(p_tmpRut1); /** We need it no more */

    if (p_rutToWorkWith[0] == '0') return FALSE; /* If rut starts with 0 */

    char digit = GetDigit(p_rutToWorkWith);
    free(p_rutToWorkWith);
    if (digit == 'K' || digit == '0')
        return TRUE;
    else if (((int)digit - 48) > 1 && ((int)digit - 48) < 9)
        return TRUE;
    else
        return FALSE;
}

char GetDigit(char *p_rut) {
    int digit;
    int multiplier = 1;
    int total = 0;

    if (!p_rut) {
        printf("1 argument expected.");
        exit(0);
    }

    char *p_tmpRut = Clean(p_rut); /* We clean the rut */
    CutRes *p_tmpRut1 =
        CutStr(p_tmpRut, RUTWITHOUTDIGIT,
               RUTWITHOUTDIGIT + 1); /* we store only 8 chars of the rut. */
    char *p_rutToWorkWith = ReverseStr(p_tmpRut1->p_str1); /* Reverse it */
    free(p_tmpRut);           /** We need it no more */
    DestroyCutRes(p_tmpRut1); /** We need it no more */

    for (unsigned int i = 0; i < strlen(p_rutToWorkWith); ++i) {
        multiplier++;
        if (multiplier == 8) multiplier = 2;
        int num = (int)p_rutToWorkWith[i] - 48;
        total += num * multiplier;
    }

    free(p_rutToWorkWith); /* We need it no more */

    digit = MOD11 - (total % MOD11);
    if (digit == 11)
        return '0';
    else if (digit == 10)
        return 'K';
    else
        return (char)digit + '0';
}

char *Format(char *p_rut, Bool dots) {
    char *p_tmpRut = Clean(p_rut); /* We clean the rut */
    char *p_formattedRut = NULL;
    CutRes *p_rutToWorkWith =
        CutStr(p_tmpRut, RUTWITHOUTDIGIT,
               RUTWITHOUTDIGIT + 1); /* we store only 9 chars of the rut. */
    free(p_tmpRut);                  /** We need it no more */
    List *p_rutChars = CreateList();
    for (unsigned int i = 0; i < strlen(p_rutToWorkWith->p_str1); ++i) {
        InsertAtEnd(p_rutChars, (char[2]){p_rutToWorkWith->p_str1[i], '\0'},
                    sizeof(char *));
    }

    InsertAtEnd(p_rutChars, (char[2]){GetDigit(p_rutToWorkWith->p_str1), '\0'},
                sizeof(char *));

    DestroyCutRes(p_rutToWorkWith);
    if (dots == FALSE) {
        p_formattedRut = calloc(
            GetSize(p_rutChars) + 2 /* Slash and null char */, sizeof(char));
        Insert(p_rutChars, "-", sizeof(char *), 8);
        for (unsigned int i = 0; i < GetSize(p_rutChars); ++i) {
            strcat(p_formattedRut, GetNodeAt(p_rutChars, i)->p_value);
        }
        DestroyEach(p_rutChars);
        DestroyList(p_rutChars);
        return p_formattedRut;
    } else {
        p_formattedRut = calloc(GetSize(p_rutChars) + 4, sizeof(char));
        int indexes[3] = {2, 6, 10};
        for (unsigned int i = 0; i < 3; ++i) {
            if (indexes[i] != 10)
                Insert(p_rutChars, ".", sizeof(char *), indexes[i]);
            else
                Insert(p_rutChars, "-", sizeof(char *), indexes[i]);
        }
        for (unsigned int i = 0; i < GetSize(p_rutChars); ++i) {
            strcat(p_formattedRut, GetNodeAt(p_rutChars, i)->p_value);
        }
        DestroyEach(p_rutChars);
        DestroyList(p_rutChars);
        return p_formattedRut;
    }
}
