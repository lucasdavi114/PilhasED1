#include <stdlib.h>
#include <stdio.h>
#include "Fatorial.h"

int main() {

    PilhaPtr p;
    fat_t resultado;

    resultado = calculaFat(5);

    printf("\nResultado: %d\n", resultado);

    return EXIT_SUCCESS;
}