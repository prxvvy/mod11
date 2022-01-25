/*
* =================================================
*
*       Filename: util
*
*    Description:
*
*        Created: 25/01/2022
*
*        Author:  prxvvy (qsk55464@gmail.com)
*
*
* =================================================
*/

#include <stdlib.h>
#include "include/bool.h"
#include <string.h>

char *Replace(char *p_input, char *p_toReplace, char *p_replaceWith) {
	char *p_newString;
	int i, cnt = 0;
	size_t toReplaceLength = strlen(p_toReplace);
	size_t replaceWithLength = strlen(p_replaceWith);

	for (i = 0; p_input[i] != '\0'; i++)  {
		if (strstr(&p_input[i], p_toReplace) == &p_input[i]) {
			cnt++;
			i += toReplaceLength - 1;
		}
	}

	p_newString = malloc(i + cnt * (replaceWithLength - toReplaceLength) + 1);

	i = 0;

	while (*p_input) {
		if (strstr(p_input, p_toReplace) == p_input) {
			strcpy(&p_newString[i], p_replaceWith);
			i += replaceWithLength;
			p_input += toReplaceLength;
		} else {
			p_newString[i++] = *p_input++;
		}
	}
	p_newString[i] = '\0';
	return p_newString;
}

Bool Includes(char *p_input, char *p_charToFind) {
	char *ret = strstr(p_input, p_charToFind);
	if (ret) return TRUE;
	else return FALSE;
}
