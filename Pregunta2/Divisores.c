#include <stdio.h>

int main() {
    int arreglo[15] = {0};
    int i, j, divisores;

    // Ingreso de los 15 valores
    for (i = 0; i < 15; i++) {
        printf("Ingrese el valor %d: ", i + 1);
        scanf("%d", &arreglo[i]);
    }

    // Impresion del arreglo
    printf("\nEl arreglo es:\n");
    for (i = 0; i < 15; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n\n");

    // Conteo de divisores y clasificacion
    for (i = 0; i < 15; i++) {
        divisores = 0;
        for (j = 1; j <= arreglo[i]; j++) {
            if (arreglo[i] % j == 0) {
                divisores++;
            }
        }

        printf("%d -> %d divisores -> ", arreglo[i], divisores);

        if (arreglo[i] == 1) {
            printf("No es primo ni compuesto\n");
        } else if (divisores == 2) {
            printf("Primo\n");
        } else if (divisores == 4) {
            printf("Semiprimo\n");
        } else if (divisores > 2) {
            printf("Compuesto\n");
        } else {
            printf("Sin clasificacion\n");
        }
    }

    return 0;
}
