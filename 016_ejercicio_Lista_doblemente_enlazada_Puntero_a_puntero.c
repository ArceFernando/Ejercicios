#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
typedef struct Nodo
{
    int dato;
    struct Nodo *siguiente;
    struct Nodo *anterior;
} Nodo;

// Crear un nuevo nodo
Nodo *crearNodo(int dato)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

// Insertar al inicio
void insertarInicio(Nodo **cabeza, int dato)
{
    Nodo *nuevo = crearNodo(dato);
    if (*cabeza == NULL)
    {
        *cabeza = nuevo;
    }
    else
    {
        nuevo->siguiente = *cabeza;
        (*cabeza)->anterior = nuevo;
        *cabeza = nuevo;
    }
}

// Insertar al final
void insertarFinal(Nodo **cabeza, int dato) // un puntero al puntero del primer nodo de la lista (la cabeza)
{
    Nodo *nuevo = crearNodo(dato);
    if (*cabeza == NULL)
    {
        *cabeza = nuevo;
    }
    else
    {
        Nodo *temp = *cabeza;
        while (temp->siguiente != NULL)
            temp = temp->siguiente;
        temp->siguiente = nuevo;
        nuevo->anterior = temp;
    }
}

// Eliminar un nodo
void eliminarNodo(Nodo **cabeza, int dato)
{
    Nodo *temp = *cabeza;
    while (temp != NULL && temp->dato != dato)
        temp = temp->siguiente;

    if (temp == NULL)
    {
        printf("Nodo con dato %d no encontrado.\n", dato);
        return;
    }

    if (temp->anterior != NULL)
        temp->anterior->siguiente = temp->siguiente;
    else
        *cabeza = temp->siguiente; // era el primer nodo

    if (temp->siguiente != NULL)
        temp->siguiente->anterior = temp->anterior;

    free(temp);
    printf("Nodo con dato %d eliminado.\n", dato);
}

// Mostrar de inicio a fin
void mostrarAdelante(Nodo *cabeza)
{
    printf("Lista adelante: ");
    while (cabeza != NULL)
    {
        printf("%d ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("\n");
}

// Mostrar de fin a inicio
void mostrarAtras(Nodo *cabeza)
{
    if (cabeza == NULL)
    {
        printf("Lista vacia.\n");
        return;
    }

    // Ir al final de la lista
    while (cabeza->siguiente != NULL)
        cabeza = cabeza->siguiente;

    printf("Lista atras: ");
    while (cabeza != NULL)
    {
        printf("%d ", cabeza->dato);
        cabeza = cabeza->anterior;
    }
    printf("\n");
}

// Función principal
int main()
{
    Nodo *cabeza = NULL;

    insertarInicio(&cabeza, 10);
    insertarInicio(&cabeza, 20);
    insertarFinal(&cabeza, 5);
    insertarFinal(&cabeza, 1);

    mostrarAdelante(cabeza);
    mostrarAtras(cabeza);

    eliminarNodo(&cabeza, 10);

    mostrarAdelante(cabeza);
    mostrarAtras(cabeza);

    return 0;
}
