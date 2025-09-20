#include <stdio.h>

// Función que encuentra el número máximo en un arreglo
int hallarMaximo(int arr[], int longitud)
{
    int max = arr[0];
    for (int i = 1; i < longitud; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int numeros[] = {-5, 45, -67, 34, 7, 79};
    int dimension = sizeof(numeros) / sizeof(numeros[0]);
    /*Calcula cuántos elementos tiene el arreglo:
      sizeof(numeros) = tamaño total del arreglo en bytes.
      sizeof(numeros[0]) = tamaño de un solo entero.
      Dividiendo ambos, se obtiene el número de elementos*/

    int maximo = hallarMaximo(numeros, dimension);

    printf("Maximo: %d\n", maximo);
    return 0;
}