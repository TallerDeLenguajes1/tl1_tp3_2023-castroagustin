#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int produccion[5][12];

    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        printf("\nProduccion año %d\n", i + 1);
        int totalGcia = 0;
        float promGcia;
        for (int j = 0; j < 12; j++) {
            produccion[i][j] = rand() % 40001 + 10000;
            printf("Mes %d: $%d\n", j + 1, produccion[i][j]);
            totalGcia += produccion[i][j];
        }
        promGcia = totalGcia / 12;
        printf("--------\nPromedio ganancia anual: $%.2f\n--------\n", promGcia);
    }

    int max = 0, min = 50000, aMax, mMax, aMin, mMin;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            if (produccion[i][j] > max) {
                max = produccion[i][j];
                aMax = i + 1;
                mMax = j + 1;
            } else if (produccion[i][j] < min) {
                min = produccion[i][j];
                aMin = i + 1;
                mMin = j + 1;
            }
        }
    }
    printf("Maxima ganancia: $%d, año: %d, mes: %d\n", max, aMax, mMax);
    printf("Minima ganancia: $%d, año: %d, mes: %d", min, aMin, mMin);
}