//
// Created by prxvvy on 27-01-22.
//

#ifndef ALGORITHM_UTIL_H
#define ALGORITHM_UTIL_H

#include <stddef.h>
#include "bool.h"

Bool Includes(char *p_input, char *p_toFind);

char *Replace(char *p_input, char *p_toReplace, char *p_toReplaceWith);

char *Strip(char *p_input, char *p_garbage);

char *CutStr(char *p_input, int end, size_t newSize);

char *ReverseStr(char *p_input);

#endif //ALGORITHM_UTIL_H