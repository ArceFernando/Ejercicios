#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
typedef struct Nodo
{
    int dato;
    struct Nodo *siguiente; // puntero al nodo siguiente →
    struct Nodo *anterior;  // puntero al nodo anterior ←
} Nodo;

// Puntero al inicio de la lista
Nodo *cabeza = NULL;

// Función para crear un nuevo nodo
Nodo *crearNodo(int dato)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

// Insertar al principio
void insertarInicio(int dato)
{
    Nodo *nuevo = crearNodo(dato);
    if (cabeza == NULL)
    {
        cabeza = nuevo;
    }
    else
    {
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
        cabeza = nuevo;
    }
}

// Insertar al final
void insertarFinal(int dato)
{
    Nodo *nuevo = crearNodo(dato);
    if (cabeza == NULL)
    {
        cabeza = nuevo;
    }
    else
    {
        Nodo *temp = cabeza;
        while (temp->siguiente != NULL)
            temp = temp->siguiente;
        temp->siguiente = nuevo;
        nuevo->anterior = temp;
    }
}

// Eliminar un nodo con valor específico
void eliminarNodo(int dato)
{
    Nodo *temp = cabeza;
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
        cabeza = temp->siguiente; // era el primer nodo

    if (temp->siguiente != NULL)
        temp->siguiente->anterior = temp->anterior;

    free(temp);
    printf("Nodo con dato %d eliminado.\n", dato);
}

// Mostrar la lista hacia adelante
void mostrarAdelante()
{
    Nodo *temp = cabeza;
    printf("Lista adelante: ");
    while (temp != NULL)
    {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

// Mostrar la lista hacia atrás
void mostrarAtras()
{
    if (cabeza == NULL)
    {
        printf("Lista vacia.\n");
        return;
    }

    Nodo *temp = cabeza;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;

    printf("Lista atras: ");
    while (temp != NULL)
    {
        printf("%d ", temp->dato);
        temp = temp->anterior;
    }
    printf("\n");
}

// Función principal
int main()
{
    insertarInicio(10);
    insertarInicio(20);
    insertarFinal(5);
    insertarFinal(1);

    mostrarAdelante();
    mostrarAtras();

    eliminarNodo(10);
    mostrarAdelante();
    mostrarAtras();

    return 0;
}
