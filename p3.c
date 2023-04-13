#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargar(char **vectorP);
void imprimir(char **vectorP);

int main() {
    char **vectorPunteros;
    vectorPunteros = (char **)malloc(5 * sizeof(char));

    cargar(vectorPunteros);
    imprimir(vectorPunteros);

    free(vectorPunteros);

    return 0;
}

void cargar(char **vectorP) {
    char *aux;
    aux = (char *)malloc(30 * sizeof(char)); 
    for (int i = 0; i < 5; i++) {
        printf("Ingrese el nombre %d: ", i + 1);
        gets(aux);
        vectorP[i] = malloc(strlen(aux) * sizeof(char));
        printf("strlen aux: %d\n", strlen(aux));
        strcpy(vectorP[i], aux);
    }
    free(aux);
}

void imprimir(char **vectorP) {
    for (int i = 0; i < 5; i++) {
        printf("Nombre %d: %s\n", i + 1, vectorP[i]);
    }
}