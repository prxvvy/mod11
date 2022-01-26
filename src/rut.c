/*
* =================================================
*
*       Filename: rut
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
#include "include/util.h"
#include <string.h>
#include "include/rut.h"

int EsValido(char *p_rut) {
  char *p_rutLimpio = NULL;
  if (Includes(p_rut, "-") == TRUE || Includes(p_rut, ".") == TRUE || Includes(p_rut, "*") == TRUE) p_rutLimpio = LimpiarRut(p_rut);
  else {
    p_rutLimpio = calloc(strlen(p_rut) + 1, sizeof(char));
    strcpy(p_rutLimpio, p_rut);
  }
  char *p_numero = SliceString(p_rutLimpio, RUTSINDIGITOLONGITUD, 9);
  free(p_rutLimpio);
  if (p_numero[0] == '0') return 0;
  char digito = ObtenerDigidoVerificador(p_numero);
  if (digito == 'K' || digito == '0') return 1;
  else if (((int) digito - 48) > 1 && ((int) digito - 48) < 9) return 1;
  else return 0;
  free(p_numero);
}

char *LimpiarRut(char *p_rutCompleto) {
  char *p_rutLimpio = NULL;
  if (Includes(p_rutCompleto, "-") == TRUE) p_rutLimpio = Replace(p_rutCompleto, "-", "");  
  else if (Includes(p_rutCompleto, ".") == TRUE) p_rutLimpio = Replace(p_rutCompleto, ".", "");
  else if (Includes(p_rutCompleto, "*") == TRUE) p_rutLimpio = Replace(p_rutCompleto, "*", "");  
  else p_rutLimpio = p_rutCompleto;
  return p_rutLimpio;
}

char ObtenerDigidoVerificador(char *p_numero) {
  char *p_rutLimpio = NULL;
  if (Includes(p_numero, "-") == TRUE || Includes(p_numero, ".") == TRUE || Includes(p_numero, "*") == TRUE) p_rutLimpio = LimpiarRut(p_numero);
  else {
    p_rutLimpio = calloc(strlen(p_numero) + 1, sizeof(char));
    strcpy(p_rutLimpio, p_numero);
  }
  char *p_numeroo = SliceString(p_rutLimpio, RUTSINDIGITOLONGITUD, 9);
  free(p_rutLimpio);
  ReverseString(p_numeroo);
  int digito = 0;
  int multiplicador = 1;
  int suma = 0;
  for (int i = 0; i < strlen(p_numeroo); i++) {
    multiplicador++;
    if (multiplicador == 8) multiplicador = 2;
    int num = (int) p_numeroo[i] - 48;
    suma += num * multiplicador;
  } 
  free(p_numeroo); // Deberia ir a lo ultimo cuando ya no se usa la variable puntero
  digito = MOD11 - (suma % MOD11);
  if (digito == 11) return '0';
  else if (digito == 10) return 'K';
  else return (char) digito + '0';
}
