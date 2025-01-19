#include <stdlib.h>
#include <stdio.h>
#include "Fatorial.h"

int main() {

    fat_t resultado;

    resultado = calculaFat(3);

    printf("\nResultado: %d\n", resultado);

    return EXIT_SUCCESS;
}