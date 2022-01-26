/**
 * @author      : prxvvy (qsk55464@gmail.com)
 * @created     : 25/01/2022
 * @filename    : rut
 */
#ifndef RUT_H
#define RUT_H

#include "bool.h"

#define MOD11 11
#define RUTCONDIGITOLONGITUD 9
#define RUTSINDIGITOLONGITUD 8

char *LimpiarRut(char *p_rutCompleto);

char ObtenerDigidoVerificador(char *p_numer);

int EsValido(char *p_rut);

#endif /* RUT_H */
