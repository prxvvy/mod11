//
// Created by prxvvy on 27-01-22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/rut.h"
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
    char *p_tmpRut1 = CutStr(p_tmpRut, RUTWITHDIGIT, strlen(p_tmpRut) + 1); /* we store only 8 chars of the rut. */
    char *p_rutToWorkWith = ReverseStr(p_tmpRut1); /* Reverse it */
    free(p_tmpRut); /** We need it no more */
    free(p_tmpRut1); /** We need it no more */

    if (p_rutToWorkWith[0] == '0') return FALSE; /* If rut starts with 0 */

    char digit = GetDigit(p_rutToWorkWith);
    free(p_rutToWorkWith);
    if (digit == 'K' || digit == '0') return TRUE;
    else if (((int) digit - 48) > 1 && ((int) digit - 48) < 9) return TRUE;
    else return FALSE;
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
    char *p_tmpRut1 = CutStr(p_tmpRut, RUTWITHOUTDIGIT, strlen(p_tmpRut) + 1); /* we store only 8 chars of the rut. */
    char *p_rutToWorkWith = ReverseStr(p_tmpRut1); /* Reverse it */
    free(p_tmpRut); /** We need it no more */
    free(p_tmpRut1); /** We need it no more */

    for (int i = 0; i < strlen(p_rutToWorkWith); ++i) {
        multiplier++;
        if (multiplier == 8) multiplier = 2;
        int num = (int) p_rutToWorkWith[i] - 48;
        total += num * multiplier;
    }

    free(p_rutToWorkWith); /* We need it no more */

    digit = MOD11 - (total % MOD11);
    if (digit == 11) return '0';
    else if (digit == 10) return 'K';
    else return (char) digit + '0';

}