#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validar_entrada()
{
    char linea[100];
    int numero;

    while (1)
    {
        fgets(linea, sizeof(linea), stdin);

        // Intentar leer un numero entero
        if (sscanf(linea, "%d", &numero) == 1)
        {
            return numero;
        }
        else
        {
            printf("Ingrese un numero entre 1 y 4: ");
        }
    }
}
