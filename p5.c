#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargar(char **vectorP, int cant);
void imprimir(char **vectorP, int cant);
void liberar(char **vectorP, int cant);

int main() {
    char **vectorPunteros;
    int cantNombres;

    vectorPunteros = (char **)malloc(cantNombres * sizeof(char *));

    printf("Ingrese la cantidad de nombres: ");
    scanf("%d", &cantNombres);

    fflush(stdin);

    cargar(vectorPunteros, cantNombres);
    imprimir(vectorPunteros, cantNombres);
    liberar(vectorPunteros, cantNombres);

    return 0;
}

void cargar(char **vectorP, int cant) {
    char *aux;
    aux = (char *)malloc(30 * sizeof(char)); 
    for (int i = 0; i < cant; i++) {
        printf("Ingrese el nombre %d: ", i + 1);
        gets(aux);
        vectorP[i] = malloc(strlen(aux) * sizeof(char));
        strcpy(vectorP[i], aux);
    }
    free(aux);
}

void imprimir(char **vectorP, int cant) {
    for (int i = 0; i < cant; i++) {
        printf("Nombre %d: %s\n", i + 1, vectorP[i]);
    }
}

void liberar(char **vectorP, int cant) {
    for (int i = 0; i < cant; i++) {
        free(vectorP[i]);
    }
    free(vectorP);
}