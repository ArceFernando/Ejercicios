#include "lista.h"

int main() {
    Lista lista;
    crearLista(&lista);

    printf("=== Lista simple ===\n");
    agregarElemento(&lista, 10);
    agregarElemento(&lista, 20);
    agregarElemento(&lista, 5);
    imprimirLista(&lista);

    printf("Largo: %d\n", obtenerLargo(&lista));
    printf("Elemento en posición 1: %d\n", obtenerElemento(&lista, 1));

    eliminarElementoN(&lista, 0);
    imprimirLista(&lista);

    printf("\n=== Lista ordenada ===\n");
    Lista listaOrdenada;
    crearLista(&listaOrdenada);

    agregarElementoOrdenado(&listaOrdenada, 10);
    agregarElementoOrdenado(&listaOrdenada, 5);
    agregarElementoOrdenado(&listaOrdenada, 15);
    agregarElementoOrdenado(&listaOrdenada, 7);

    imprimirLista(&listaOrdenada); // salida: [ 5 7 10 15 ]

    return 0;
}
