#include <stdio.h>

int encontrarMinimo(const int *arreglo, int medida);

int main()
{
    int datos[] = {12, 2, -3, 4, 11, 6, 547, 8, 9};
    int medida = sizeof(datos) / sizeof(datos[0]);

    int minimo = encontrarMinimo(datos, medida);

    printf("Minimo: %d\n", minimo);
    return 0;
}

int encontrarMinimo(const int *arreglo, int medida)
{
    if (medida <= 0)
    {
        // arreglo vacío
        fprintf(stderr, "Error: El arreglo esta vacio.\n");
        /*stderr: se utiliza para imprimir mensajes de error.
        Por defecto, este flujo envía la salida a la consola,
        pero no está almacenado en búfer.*/
        return 0;
    }

    int min = arreglo[0];

    for (int i = 1; i < medida; i++)
    {
        if (arreglo[i] < min)
        {
            min = arreglo[i];
        }
    }

    return min;
}