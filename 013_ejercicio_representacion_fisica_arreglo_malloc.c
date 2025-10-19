#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variables normales
    int a = 10;
    float b = 3.14;
    char c = 'X';

    // Arreglo estático
    int arr[5] = {1, 2, 3, 4, 5};
    // arr[] se almacena de forma contigua en la memoria del stack.

    // Asignación dinámica
    int *dynArr = (int *)malloc(5 * sizeof(int));
    if (dynArr == NULL)
    {
        printf("Error al asignar memoria\n");
        return 1;
    }
    /*Se usa malloc para pedir memoria manualmente.
    Esto representa la administración explícita de memoria,*/

    // Inicializamos dynArr
    for (int i = 0; i < 5; i++)
    {
        dynArr[i] = (i + 1) * 10;
    }

    /* dynArr[] se almacena en el heap, también de forma contigua,
    pero su dirección suele estar más alta en memoria */

    // Mostrar variables básicas
    printf("=== Variables basicas ===\n");
    printf("a = %d\t Direccion: %p\n", a, (void *)&a);
    printf("b = %.2f\t Direccion: %p\n", b, (void *)&b);
    printf("c = %c\t Direccion: %p\n\n", c, (void *)&c);

    // Mostrar arreglo estático
    printf("=== Arreglo estatico ===\n");
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\t Direccion: %p\n", i, arr[i], (void *)&arr[i]);
    }
    printf("\n");

    // Mostrar arreglo dinámico
    printf("=== Arreglo dinamico (malloc) ===\n");
    for (int i = 0; i < 5; i++)
    {
        printf("dynArr[%d] = %d\t Direccion: %p\n", i, dynArr[i], (void *)&dynArr[i]);
    }
    printf("\n");

    // Liberar memoria
    free(dynArr);

    return 0;
}
