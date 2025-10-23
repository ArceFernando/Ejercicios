#include "lista.h"
//todo el codigo logico de las funciones(definiciones de las funciones declaradas en .h)
void crearLista(Lista* lista){
    lista->cabeza = NULL;
} 
void agregarElemento(Lista* lista,int valor){
    Nodo* nuevo =(Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    if(lista->cabeza ==NULL){
        lista->cabeza = nuevo;
    }else{
        Nodo* actual = lista->cabeza;
        while(actual->siguiente != NULL){
            actual =actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}
int obtenerLargo(Lista* lista){
    int contador =0;
    Nodo* actual = lista->cabeza; 
    while (actual != NULL){
        contador++;
        actual = actual->siguiente; 
    }
    return contador;
}
int obtenerElemento(Lista* lista, int n) {
    Nodo* actual = lista->cabeza;
    int i = 0;

    while (actual != NULL) {
        if (i == n) return actual->dato;
        actual = actual->siguiente;
        i++;
    }

    printf("Índice fuera de rango\n");
    return -1;
}

void eliminarElementoN(Lista* lista, int n) {
    if (lista->cabeza == NULL) return;

    Nodo* actual = lista->cabeza;

    if (n == 0) {
        lista->cabeza = actual->siguiente;
        free(actual);
        return;
    }

    Nodo* anterior = NULL;
    int i = 0;
    while (actual != NULL && i < n) {
        anterior = actual;
        actual = actual->siguiente;
        i++;
    }

    if (actual == NULL) return;

    anterior->siguiente = actual->siguiente;
    free(actual);
}

void imprimirLista(Lista* lista) {
    Nodo* actual = lista->cabeza;
    printf("[ ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("]\n");
}

void agregarElementoOrdenado(Lista* lista, int valor) {
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (lista->cabeza == NULL || valor < lista->cabeza->dato) {
        nuevo->siguiente = lista->cabeza;
        lista->cabeza = nuevo;
        return;
    }

    Nodo* actual = lista->cabeza;
    while (actual->siguiente != NULL && actual->siguiente->dato < valor) {
        actual = actual->siguiente;
    }

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
}