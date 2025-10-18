#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>

typedef enum
{
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_CHAR,
    TIPO_STRUCT
} TipoDato;

typedef struct
{
    int id;
    char nombre[20];
} MiEstructura;

typedef struct Nodo
{
    TipoDato tipo;
    void *dato;
    struct Nodo *siguiente;
} Nodo;

Nodo *crearLista();
void *crearDatoInt(int valor);
void *crearDatoFloat(float valor);
void *crearDatoChar(char valor);
void *crearDatoStruct(MiEstructura valor);

//  Nodo* a void porque ya no retorna una nueva lista
void agregarElemento(Nodo **cabeza, TipoDato tipo, void *dato);
void eliminarElemento(Nodo **cabeza, int n);
void liberarLista(Nodo **cabeza);
int detectarTipoLista(Nodo *cabeza);
int obtenerLargo(Nodo *cabeza);

void imprimirNodo(Nodo *nodo);
void imprimirLista(Nodo *cabeza);
void obtenerElemento(Nodo *cabeza, int n);

// Estas  retornan la lista ordenada (porque no modificas punteros)
void ordenarEnteros(Nodo *cabeza, int ascendente);
void ordenarFloats(Nodo *cabeza, int ascendente);

void limpiarBuffer();

#endif
