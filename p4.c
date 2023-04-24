#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct {
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    int PrecioUnitario;
} typedef Producto;

struct {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
} typedef Cliente;

void cargarClientes(Cliente *Clientes, int cant);
void cargarProductos(Producto *Productos, int cant);
void mostrarDatos(Cliente *Clientes, int cant);
int costoTotalProd(Producto Prod);

int main() {
    int cantClientes;
    Cliente *Clientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);

    srand(time(NULL));

    Clientes = (Cliente *)malloc(cantClientes * sizeof(Cliente));

    cargarClientes(Clientes, cantClientes);
    mostrarDatos(Clientes, cantClientes);

    return 0;
}

void cargarClientes(Cliente *Clientes, int cant) {
    for (int i = 0; i < cant; i++) {
        Clientes[i].ClienteID = i;
        char *Buff;
        Buff = (char *)malloc(50 * sizeof(char));
        printf("Nombre del cliente %d: ", i + 1);
        fflush(stdin);
        gets(Buff);
        Clientes[i].NombreCliente = (char *)malloc(strlen(Buff) * sizeof(char));
        strcpy(Clientes[i].NombreCliente, Buff);
        Clientes[i].CantidadProductosAPedir = rand() % 4 + 1;
        Clientes[i].Productos = (Producto *)malloc(Clientes[i].CantidadProductosAPedir * sizeof(Producto));
        cargarProductos(Clientes[i].Productos, Clientes[i].CantidadProductosAPedir);
    }
}

void cargarProductos(Producto *Productos, int cant) {
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramalos", "Bebidas"};
    for (int i = 0; i < cant; i++) {
        Productos[i].ProductoID = i;
        Productos[i].Cantidad = rand() % 9 + 1;
        char *tipo;
        tipo = (char *)malloc(11 * sizeof(char));
        strcpy(tipo, TiposProductos[rand() % 5]);
        Productos[i].TipoProducto = (char *)malloc(strlen(tipo) * sizeof(char));
        strcpy(Productos[i].TipoProducto, tipo);
        Productos[i].PrecioUnitario = rand() % (100 - 10 + 1) + 10;
    }
}

void mostrarDatos(Cliente *Clientes, int cant) {
    for (int i = 0; i < cant; i++) {
        printf("---------- Cliente %d ----------\n", i + 1);
        printf("ID: %d\n", Clientes[i].ClienteID);
        printf("Nombre: %s\n", Clientes[i].NombreCliente);
        printf("Cantidad de Productos: %d\n", Clientes[i].CantidadProductosAPedir);
        printf("Productos pedidos:\n");

        int costoTotal = 0;

        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++) {
            printf("%d.\n", j + 1);
            printf("id producto: %d\n", Clientes[i].Productos[j].ProductoID);
            printf("cantidad: %d\n", Clientes[i].Productos[j].Cantidad);
            printf("tipo: %s\n", Clientes[i].Productos[j].TipoProducto);
            printf("precio unitario: %d\n", Clientes[i].Productos[j].PrecioUnitario);
            costoTotal += costoTotalProd(Clientes[i].Productos[j]);
        }
        printf("~~~ Total a pagar: $%d ~~~\n", costoTotal);
    }
}

int costoTotalProd(Producto Prod) {
    return Prod.Cantidad * Prod.PrecioUnitario;
}