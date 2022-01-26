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
  char digito = ObtenerDigidoVerificador("25938058");
  printf("%c\n", digito);
  return 0;
}
