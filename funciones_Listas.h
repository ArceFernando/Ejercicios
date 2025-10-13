// funciones.h
#ifndef FUNCIONES_H
#define FUNCIONES_H
/*es una macro (una constante definida). No tiene por qué coincidir con el nombre del archivo,
pero se suele usar un nombre similar para claridad.*/

#include <stdio.h>

// Enumeración para tipos de datos
typedef enum
{
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_CHAR,
    TIPO_STRUCT
} TipoDato;

// Estructura personalizada
typedef struct
{
    int id;
    char nombre[20];
} MiEstructura;

// Nodo de la lista
typedef struct Nodo
{
    TipoDato tipo;
    void *dato;
    struct Nodo *siguiente;
} Nodo;

// Funciones
Nodo *crearLista();
void *crearDatoInt(int valor);
void *crearDatoFloat(float valor);
void *crearDatoChar(char valor);
void *crearDatoStruct(MiEstructura valor);
Nodo *agregarElemento(Nodo *cabeza, TipoDato tipo, void *dato);
int detectarTipoLista(Nodo *cabeza);
int obtenerLargo(Nodo *cabeza);
void imprimirNodo(Nodo *nodo);
void imprimirLista(Nodo *cabeza);
void obtenerElemento(Nodo *cabeza, int n);
Nodo *eliminarElemento(Nodo *cabeza, int n);
Nodo *ordenarEnteros(Nodo *cabeza, int ascendente);
Nodo *ordenarFloats(Nodo *cabeza, int ascendente);
void limpiarBuffer();
void liberarLista(Nodo *cabeza);

#endif
