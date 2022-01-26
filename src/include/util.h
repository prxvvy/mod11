/**
 * @author      : prxvvy (qsk55464@gmail.com)
 * @created     : 25/01/2022
 * @filename    : util
 */
#ifndef UTIL_H
#define UTIL_H

#include "bool.h"
#include <stddef.h>

char *Replace(char *p_input, char *p_toReplace, char *p_replaceWith);

Bool Includes(char *p_input, char *p_charToFind);

void ReverseString(char *p_string);

char *SliceString(char *p_str, int end, size_t newSizeString);

#endif /* UTIL_H */
