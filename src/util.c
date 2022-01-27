//
// Created by prxvvy on 27-01-22.
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
    /* Walk the list once. */
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
    char *res = strstr(p_input, p_toFind);
    return res ? TRUE : FALSE;
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

    /* Walk the list once. */
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

    /* Walk the list once. */
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

char *CutStr(char *p_input, int end, size_t newSize) {
    char *p_newString = calloc(newSize, sizeof(char));
    for (int i = 0; i < end; ++i) {
        strcat(p_newString, (char[2]) {(char) p_input[i], '\0'} /* Turn it into a string. */);
    }
    return p_newString;
}
