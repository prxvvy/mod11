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

char *LimpiarRut(char *p_rutCompleto) {
  char *p_rutLimpio = NULL;
  if (Includes(p_rutCompleto, "-") == TRUE) {
    char *temp = Replace(p_rutCompleto, "-", "");
    p_rutLimpio = &*temp;
    free(temp);
  } 
  if (Includes(p_rutCompleto, ".") == TRUE) p_rutLimpio = Replace(p_rutCompleto, ".", "");
  if (Includes(p_rutCompleto, "*") == TRUE) p_rutLimpio = Replace(p_rutCompleto, "*", "");
  return p_rutLimpio;
}

char *ObtenerDigidoVerificador(char *p_numero) {
  if (strlen(p_numero) == 0 || strlen(p_numero) > 8) return NULL;
  return NULL;
}
