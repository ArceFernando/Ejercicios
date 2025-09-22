#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include "validar_Numero_Int_10_digitos.h"

int main()
{
    char entrada[100];

    printf("Ingrese un numero entero: ");
    fgets(entrada, sizeof(entrada), stdin);

    if (esNumeroValido(entrada))
    {
        // Convertir a int luego de validar
        int numero = atoi(entrada);

        if (numero % 2 == 0)
        {
            printf("El numero %d es PAR.\n", numero);
        }
        else
        {
            printf("El numero %d no es PAR.\n", numero);
        }
    }
    else
    {
        printf("Numero invalido. Debe ser un entero de hasta 10 digitos en el rango de int.\n");
    }

    return 0;
}
