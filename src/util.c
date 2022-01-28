//
// Created by prxvvy on 28-01-22.
//

#include "include/util.h"
#include "include/list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Reverse a given string.
 * @param p_input The str to reverse.
 * @return A new str allocated with calloc (Must free!).
 */

char *ReverseStr(char *p_input) {
    List *p_charList = CreateList();
    char *p_newString;
    for (int i = 0; i < strlen(p_input); ++i) {
        InsertAtBeginning(p_charList, &(char[2]) {(char) p_input[i], '\0'} /* Turn it into a string. */,
                          sizeof(char *)); /* Little trick */
    }
    /* Walk the list. */
    Node *p_node1 = p_charList->p_head;
    p_newString = calloc(GetSize(p_charList) + 1, sizeof(char));
    while (1) {
        strcat(p_newString, p_node1->p_value); // Append byte by byte to the new string.
        p_node1 = p_node1->p_next; /* Continue... */

        if (p_node1 == p_charList->p_head) break;
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
                    if (++timesFound == toFindLen) return TRUE; /* If got same len */
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
 * Find a char in a str and replace it with another one.
 *
 * @param p_input The str we are gonna manipulate.
 * @param p_toReplace The str (for our purposes) to replace - thus it'll be treated as a char.
 * @param p_toReplaceWith - The str to replace the old str with. (Will be treated as char.)
 * @return Allocated str with calloc (Must free!).
 */

char *Replace(char *p_input, char *p_toReplace, char *p_toReplaceWith) {
    List *p_charList = CreateList();
    char *p_newString;
    for (int i = 0; i < strlen(p_input); ++i)
        InsertAtEnd(p_charList, &(char[2]) {(char) p_input[i], '\0'} /* Turn it into a string. */, sizeof(char *));

    /* Walk the list. */

    Node *p_node = p_charList->p_head;

    while (1) {

        if (strcmp(p_node->p_value, p_toReplace) == 0) {
            p_node->p_value = p_toReplaceWith;
        }
        p_node = p_node->p_next; /* Continue.. */

        if (p_node == p_charList->p_head) break;
    }

    /* Walk the list once again. */
    Node *p_node1 = p_charList->p_head;
    p_newString = calloc(GetSize(p_charList) + 1, sizeof(char));
    while (1) {
        strcat(p_newString, p_node1->p_value); // Append byte by byte to the new string.
        p_node1 = p_node1->p_next; /* Continue... */

        if (p_node1 == p_charList->p_head) break;
    }
    DestroyEach(p_charList);
    DestroyList(p_charList);
    return p_newString;
}

/**
 * A replacement for Replace function.
 * Does what Replace function does, but kind of better, also depending on what you want.
 * Will remove all the elements in a str.
 * @param p_input The str we are gonna manipulate.
 * @param p_garbage A str with all the elements we don't want in our str.
 * @return A new str allocated with calloc (Must free!).
 */

char *Strip(char *p_input, char *p_garbage) {
    List *p_charList = CreateList();
    List *p_garbageList = CreateList();
    char *p_newString;
    for (int i = 0; i < strlen(p_input); ++i)
        InsertAtEnd(p_charList, &(char[2]) {(char) p_input[i], '\0'} /* Turn it into a string. */, sizeof(char *));

    for (int j = 0; j < strlen(p_garbage); ++j)
        InsertAtEnd(p_garbageList, &(char[2]) {(char) p_garbage[j], '\0'} /* Turn it into a string. */, sizeof(char *));

    /* Walk both lists. */

    Node *p_nodeCharList = p_charList->p_head;
    Node *p_nodeGarbageList = p_garbageList->p_head;

    while (1) {
        while (1) {

            if (strcmp(p_nodeCharList->p_value, p_nodeGarbageList->p_value) == 0) p_nodeCharList->p_value = "";

            p_nodeGarbageList = p_nodeGarbageList->p_next;
            if (p_nodeGarbageList == p_garbageList->p_head) break;
        }
        p_nodeCharList = p_nodeCharList->p_next;
        if (p_nodeCharList == p_charList->p_head) break;
    }

    /* Walk the list once again. */
    Node *p_node1 = p_charList->p_head;
    p_newString = calloc(GetSize(p_charList) + 1, sizeof(char));
    while (1) {
        strcat(p_newString, p_node1->p_value); // Append byte by byte to the new string.
        p_node1 = p_node1->p_next; /* Continue... */

        if (p_node1 == p_charList->p_head) break;
    }
    /**
     * Destroy both lists.
     */
    DestroyEach(p_charList);
    DestroyEach(p_garbageList);

    DestroyList(p_charList);
    DestroyList(p_garbageList);

    return p_newString;
}

/**
 * Cut a str until a passed end.
 * @param p_input The str to cut.
 * @param end The end where we should stop cutting.
 * @param newSize The new size the str will got.
 * @return A new str allocated with calloc (Must free!).
 */

CutRes *CutStr(char *p_input, int end, size_t newSize) {

    if (end > strlen(p_input)) {
        printf("End is longer than str len.\n");
        exit(0);
    }

    char *p_firstPart = calloc(newSize, sizeof(char));
    char *p_secondPart = calloc(((strlen(p_input) + 1) - newSize) + 1, sizeof(char));


    int i;

    for (i = 0; i < end; ++i) {
        strcat(p_firstPart, (char[2]) {(char) p_input[i], '\0'} /* Turn it into a string. */);
    }

    for (int j = i; j < (strlen(p_input) + 1); ++j) {
        strcat(p_secondPart, (char[2]) {(char) p_input[j], '\0'} /* Turn it into a string. */);
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