#include <stdio.h>
#include "include/rut.h"

int main() {
    int validate = ValidateRut("0259380588");
    printf("%d\n", validate);
    return 0;
}
