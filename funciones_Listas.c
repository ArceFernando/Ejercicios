// funciones.c
#include "funciones_Listas.h"
#include <stdlib.h>
#include <string.h>

Nodo *crearLista()
{
    return NULL;
}

void *crearDatoInt(int valor)
{
    int *p = malloc(sizeof(int));
    *p = valor;
    return p;
}

void *crearDatoFloat(float valor)
{
    float *p = malloc(sizeof(float));
    *p = valor;
    return p;
}

void *crearDatoChar(char valor)
{
    char *p = malloc(sizeof(char));
    *p = valor;
    return p;
}

void *crearDatoStruct(MiEstructura valor)
{
    MiEstructura *p = malloc(sizeof(MiEstructura));
    *p = valor;
    return p;
}

Nodo *agregarElemento(Nodo *cabeza, TipoDato tipo, void *dato)
{
    Nodo *nuevo = malloc(sizeof(Nodo));
    nuevo->tipo = tipo;
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    if (!cabeza)
        return nuevo;

    Nodo *actual = cabeza;
    while (actual->siguiente)
    {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
    return cabeza;
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
            printf("Elemento en posicion %d: ", n);
            imprimirNodo(cabeza);
            printf("\n");
            return;
        }
        cabeza = cabeza->siguiente;
        i++;
    }
    printf("Índice fuera de rango.\n");
}

Nodo *eliminarElemento(Nodo *cabeza, int n)
{
    if (!cabeza)
        return NULL;

    Nodo *temp;
    if (n == 0)
    {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp->dato);
        free(temp);
        return cabeza;
    }

    Nodo *actual = cabeza;
    for (int i = 0; actual != NULL && i < n - 1; i++)
    {
        actual = actual->siguiente;
    }

    if (!actual || !actual->siguiente)
    {
        printf("Índice fuera de rango.\n");
        return cabeza;
    }

    temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    free(temp->dato);
    free(temp);
    return cabeza;
}

Nodo *ordenarEnteros(Nodo *cabeza, int ascendente)
{
    if (!cabeza || !cabeza->siguiente)
        return cabeza;

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
    return cabeza;
}

Nodo *ordenarFloats(Nodo *cabeza, int ascendente)
{
    if (!cabeza || !cabeza->siguiente)
        return cabeza;

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
    return cabeza;
}

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void liberarLista(Nodo *cabeza)
{
    while (cabeza)
    {
        Nodo *temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp->dato);
        free(temp);
    }
}
