#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>

 //Estructura del nodo
 typedef struct Nodo {
    int dato;
    struct Nodo* siguiente; 
 }Nodo;

 //Estructura de lista
 typedef struct{
    Nodo* cabeza;
 } Lista;

 //Funciones basicas
 void crearLista(Lista* lista);
 void agregarElemento(Lista* lista ,int valor);
 int obtenerLargo(Lista* lista);
 int obtenerElemento(Lista* lista, int n);
 void eliminarElementoN(Lista* lista,int n);
 void imprimirLista(Lista* lista); 

 //Funcion extra para lista ordenada
 void agregarElementoOrdenado(Lista* lista, int valor);

#endif 