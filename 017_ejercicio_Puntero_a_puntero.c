#include <stdio.h>
#include <stdlib.h>

// Función que modifica el puntero usando un puntero a puntero
void asignarMemoria(int **ptr)
{
    *ptr = (int *)malloc(sizeof(int)); // Reservamos memoria para un entero
    if (*ptr != NULL)
    {
        **ptr = 42; // Asignamos valor a la memoria reservada
    }
}

int main()
{
    int *p = NULL; // Este es el puntero original

    printf("Antes de asignar: p = %p\n", (void *)p);

    asignarMemoria(&p); // Pasamos la dirección del puntero: int**

    if (p != NULL)
    {
        printf("Despues de asignar: p = %p, *p = %d\n", (void *)p, *p);
    }

    // Liberamos la memoria
    free(p);

    return 0;
}
