#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "menu.h"
#include "frases.h"
#include "validar_entrada_menu.h"

int main()
{
    int opcion;

    do
    {
        mostrarMenu();
        opcion = validar_entrada();

        switch (opcion)
        {
        case 1:
            frase1();
            break;
        case 2:
            frase2();
            break;
        case 3:
            frase3();
            break;
        case 4:
            printf("\nSaliendo\n");
            break;
        default:
            printf("\nPor favor, elija entre 1 y 4.\n");
        }

    } while (opcion != 4);

    return 0;
}
