#include "funciones_Listas_Puntero_a_Puntero.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Nodo *crearLista()
{
    return NULL;
}

void *crearDatoInt(int valor)
{
    int *p = malloc(sizeof(int));
    if (!p)
        exit(EXIT_FAILURE);
    *p = valor;
    return p;
}

void *crearDatoFloat(float valor)
{
    float *p = malloc(sizeof(float));
    if (!p)
        exit(EXIT_FAILURE);
    *p = valor;
    return p;
}

void *crearDatoChar(char valor)
{
    char *p = malloc(sizeof(char));
    if (!p)
        exit(EXIT_FAILURE);
    *p = valor;
    return p;
}

void *crearDatoStruct(MiEstructura valor)
{
    MiEstructura *p = malloc(sizeof(MiEstructura));
    if (!p)
        exit(EXIT_FAILURE);
    *p = valor;

    return p;
}

void agregarElemento(Nodo **cabeza, TipoDato tipo, void *dato)
{
    Nodo *nuevo = malloc(sizeof(Nodo));
    if (!nuevo)
        exit(EXIT_FAILURE);

    nuevo->tipo = tipo;
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    if (!*cabeza)
    {
        *cabeza = nuevo;
        return;
    }

    Nodo *actual = *cabeza;
    while (actual->siguiente)
    {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
}

int detectarTipoLista(Nodo *cabeza)
{
    if (!cabeza)
        return -1;

    TipoDato tipo = cabeza->tipo;
    Nodo *actual = cabeza->siguiente;

    while (actual)
    {
        if (actual->tipo != tipo)
            return -1;
        actual = actual->siguiente;
    }
    return tipo;
}

int obtenerLargo(Nodo *cabeza)
{
    int cont = 0;
    while (cabeza)
    {
        cont++;
        cabeza = cabeza->siguiente;
    }
    return cont;
}

void imprimirNodo(Nodo *nodo)
{
    switch (nodo->tipo)
    {
    case TIPO_INT:
        printf("%d", *(int *)(nodo->dato));
        break;
    case TIPO_FLOAT:
        printf("%.2f", *(float *)(nodo->dato));
        break;
    case TIPO_CHAR:
        printf("'%c'", *(char *)(nodo->dato));
        break;
    case TIPO_STRUCT:
    {
        MiEstructura *s = (MiEstructura *)nodo->dato;
        printf("{id:%d, nombre:%s}", s->id, s->nombre);
        break;
    }
    default:
        printf("Tipo desconocido");
    }
}

void imprimirLista(Nodo *cabeza)
{
    printf("Lista: ");
    while (cabeza)
    {
        imprimirNodo(cabeza);
        printf(" -> ");
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

void obtenerElemento(Nodo *cabeza, int n)
{
    int i = 0;
    while (cabeza)
    {
        if (i == n)
        {
            printf("Elemento en posición %d: ", n);
            imprimirNodo(cabeza);
            printf("\n");
            return;
        }
        cabeza = cabeza->siguiente;
        i++;
    }
    printf("Índice fuera de rango.\n");
}

void eliminarElemento(Nodo **cabeza, int n)
{
    if (!*cabeza)
        return;

    Nodo *temp;
    if (n == 0)
    {
        temp = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(temp->dato);
        free(temp);
        return;
    }

    Nodo *actual = *cabeza;
    for (int i = 0; actual != NULL && i < n - 1; i++)
    {
        actual = actual->siguiente;
    }

    if (!actual || !actual->siguiente)
    {
        printf("Índice fuera de rango.\n");
        return;
    }

    temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    free(temp->dato);
    free(temp);
}

void ordenarEnteros(Nodo *cabeza, int ascendente)
{
    if (!cabeza || !cabeza->siguiente)
        return;

    Nodo *i, *j;
    for (i = cabeza; i; i = i->siguiente)
    {
        for (j = i->siguiente; j; j = j->siguiente)
        {
            int vi = *(int *)(i->dato);
            int vj = *(int *)(j->dato);
            int cambiar = (ascendente) ? (vi > vj) : (vi < vj);
            if (cambiar)
            {
                int temp = vi;
                *(int *)(i->dato) = vj;
                *(int *)(j->dato) = temp;
            }
        }
    }
}

void ordenarFloats(Nodo *cabeza, int ascendente)
{
    if (!cabeza || !cabeza->siguiente)
        return;

    Nodo *i, *j;
    for (i = cabeza; i; i = i->siguiente)
    {
        for (j = i->siguiente; j; j = j->siguiente)
        {
            float vi = *(float *)(i->dato);
            float vj = *(float *)(j->dato);
            int cambiar = (ascendente) ? (vi > vj) : (vi < vj);
            if (cambiar)
            {
                float temp = vi;
                *(float *)(i->dato) = vj;
                *(float *)(j->dato) = temp;
            }
        }
    }
}

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void liberarLista(Nodo **cabeza)
{
    Nodo *temp;
    while (*cabeza)
    {
        temp = *cabeza;
        *cabeza = (*cabeza)->siguiente;

        if (temp->tipo == TIPO_STRUCT)
        {
            free(((MiEstructura *)temp->dato)->nombre);
        }

        free(temp->dato);
        free(temp);
    }
}
