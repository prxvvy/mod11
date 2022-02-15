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

#include "include/util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/list.h"

/**
 * Reverse a given string.
 * @param p_input The str to reverse.
 * @return A new str allocated with calloc (Must free!).
 */

char *ReverseStr(char *p_input) {
    List *p_charList = CreateList();
    char *p_newString;
    for (unsigned int i = 0; i < strlen(p_input); ++i) {
        InsertAtBeginning(
            p_charList,
            &(char[2]){(char)p_input[i], '\0'} /* Turn it into a string. */,
            sizeof(char *)); /* Little trick */
    }
    /* Walk the list. */
    Node *p_node1 = p_charList->p_head;
    p_newString = calloc(GetSize(p_charList) + 1, sizeof(char));
    for (unsigned int i = 0; i < GetSize(p_charList); ++i) {
        strcat(p_newString,
               p_node1->p_value);  // Append byte by byte to the new string.
        p_node1 = p_node1->p_next; /* Continue... */
    }
    DestroyEach(p_charList);
    DestroyList(p_charList);

    return p_newString;
}

Bool Includes(char *p_input, char *p_toFind) {
    size_t sLen = strlen(p_input);
    size_t toFindLen = strlen(p_toFind);

    unsigned int timesFound = 0;

    if (sLen > toFindLen) {
        for (unsigned int i = 0, j = 0; i < sLen; ++i) {
            do {
                if (p_input[i] == p_toFind[j]) { /* If stars with same char */
                    if (++timesFound == toFindLen)
                        return TRUE; /* If got same len */
                    i++;
                    j++;
                } else {
                    i -= timesFound;
                    timesFound = 0;
                    j = 0;
                }
            } while (timesFound);
        }
        return FALSE;
    } else {
        printf("\"%s\" is longer than \"%s\"\n", p_toFind, p_input);
        return FALSE;
    }
}

/**
 * A replacement for Replace function.
 * Does what Replace function does, but kind of better, also depending on what
 * you want. Will remove all the elements in a str.
 * @param p_input The str we are gonna manipulate.
 * @param p_garbage A str with all the elements we don't want in our str.
 * @return A new str allocated with calloc (Must free!).
 */

char *Strip(char *p_input, char *p_garbage) {
    List *p_charList = CreateList();
    List *p_garbageList = CreateList();
    char *p_newString;
    for (unsigned int i = 0; i < strlen(p_input); ++i)
        InsertAtEnd(
            p_charList,
            &(char[2]){(char)p_input[i], '\0'} /* Turn it into a string. */,
            sizeof(char *));

    for (unsigned int j = 0; j < strlen(p_garbage); ++j)
        InsertAtEnd(
            p_garbageList,
            &(char[2]){(char)p_garbage[j], '\0'} /* Turn it into a string. */,
            sizeof(char *));

    /* Walk both lists. */

    Node *p_nodeCharList = p_charList->p_head;
    Node *p_nodeGarbageList = p_garbageList->p_head;

    for (unsigned int i = 0; i < GetSize(p_charList); ++i) {
        for (unsigned int j = 0; j < GetSize(p_garbageList); ++j) {
            if (strcmp(p_nodeCharList->p_value, p_nodeGarbageList->p_value) ==
                0) {
                Node *p_currentToDestroy =
                    p_nodeCharList; /* Store the current node to unlink */
                p_nodeCharList = p_nodeCharList->p_next; /* Move forward  */
                UnlinkNode(p_charList,
                           p_currentToDestroy); /* Unlink the stored node */
            }
            p_nodeGarbageList = p_nodeGarbageList->p_next;
        }
        p_nodeCharList = p_nodeCharList->p_next;
    }

    Node *p_node1 = p_charList->p_head;

    p_newString = calloc(GetSize(p_charList) + 1, sizeof(char));

    /* Walk the list containing the chars */

    for (unsigned int i = 0; i < GetSize(p_charList); ++i) {
        strcat(p_newString, p_node1->p_value); /* Append byte by byte */
        p_node1 = p_node1->p_next;
    }

    /* Free both lists as we need them no more. */

    DestroyEach(p_charList);
    DestroyList(p_charList);

    DestroyEach(p_garbageList);
    DestroyList(p_garbageList);

    return p_newString; /* NOTE: Must free! */
}

/**
 * Cut a str until a passed end.
 * @param p_input The str to cut.
 * @param end The end where we should stop cutting.
 * @param newSize The new size the str will got.
 * @return A new str allocated with calloc (Must free!).
 */

CutRes *CutStr(char *p_input, unsigned int end, size_t newSize) {
    if (end > strlen(p_input)) {
        printf("End is longer than str len.\n");
        exit(0);
    }

    char *p_firstPart = calloc(newSize, sizeof(char));
    char *p_secondPart =
        calloc(((strlen(p_input) + 1) - newSize) + 1, sizeof(char));

    unsigned int i;

    for (i = 0; i < end; ++i) {
        strcat(p_firstPart,
               (char[2]){(char)p_input[i], '\0'} /* Turn it into a string. */);
    }

    for (unsigned int j = i; j < (strlen(p_input) + 1); ++j) {
        strcat(p_secondPart,
               (char[2]){(char)p_input[j], '\0'} /* Turn it into a string. */);
    }

    CutRes *res = calloc(1, sizeof(struct CutRes));

    res->p_str1 = calloc(strlen(p_firstPart) + 1, sizeof(char));
    strcpy(res->p_str1, p_firstPart);

    res->p_str2 = calloc(strlen(p_secondPart) + 1, sizeof(char));
    strcpy(res->p_str2, p_secondPart);

    free(p_firstPart);
    free(p_secondPart);

    return res;
}

Bool DestroyCutRes(CutRes *res) {
    free(res->p_str1);
    free(res->p_str2);
    free(res);
    return TRUE;
}
