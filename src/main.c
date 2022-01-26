/*
* =================================================
*
*       Filename: main
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

#include <stdio.h>
#include "include/rut.h"
#include "include/util.h"
#include <stdlib.h>
#include <string.h>

int main() {
  int esValido = EsValido("5328478");
  if (esValido == 1) {
    printf("El rut es valido.\n");
  } else {
    printf("El rut es invalido.\n");
  }
  return 0;
}
