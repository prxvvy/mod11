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

#endif //ALGORITHM_RUT_H
