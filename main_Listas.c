// main.c
#include <stdio.h>
#include "funciones_Listas.h"

int main()
{
    Nodo *lista = crearLista();
    int opcion;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Crear e inicializar lista\n");
        printf("2. Agregar un elemento\n");
        printf("3. Ordenar enteros (asc o desc)\n");
        printf("4. Obtener largo de la lista\n");
        printf("5. Obtener un elemento N\n");
        printf("6. Eliminar un elemento N\n");
        printf("7. Imprimir la lista\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion)
        {
        case 1:
            liberarLista(lista);
            lista = crearLista();
            printf("Lista inicializada.\n");
            break;

        case 2:
        {
            printf("Tipo a agregar: i=int, f=float, c=char, s=estructura\n");
            char tipo;
            scanf(" %c", &tipo);
            limpiarBuffer();

            if (tipo == 'i')
            {
                int v;
                printf("Ingrese entero: ");
                scanf("%d", &v);
                limpiarBuffer();
                lista = agregarElemento(lista, TIPO_INT, crearDatoInt(v));
            }
            else if (tipo == 'f')
            {
                float v;
                printf("Ingrese float: ");
                scanf("%f", &v);
                limpiarBuffer();
                lista = agregarElemento(lista, TIPO_FLOAT, crearDatoFloat(v));
            }
            else if (tipo == 'c')
            {
                char v;
                printf("Ingrese char: ");
                scanf(" %c", &v);
                limpiarBuffer();
                lista = agregarElemento(lista, TIPO_CHAR, crearDatoChar(v));
            }
            else if (tipo == 's')
            {
                MiEstructura s;
                printf("Ingrese id (int): ");
                scanf("%d", &s.id);
                limpiarBuffer();
                printf("Ingrese nombre (sin espacios): ");
                scanf("%19s", s.nombre);
                limpiarBuffer();
                lista = agregarElemento(lista, TIPO_STRUCT, crearDatoStruct(s));
            }
            else
            {
                printf("Tipo invalido.\n");
                break;
            }

            int tipoLista = detectarTipoLista(lista);
            if (tipoLista == TIPO_INT)
            {
                lista = ordenarEnteros(lista, 1);
                printf("Lista ordenada automaticamente (enteros ascendentes).\n");
            }
            else if (tipoLista == TIPO_FLOAT)
            {
                lista = ordenarFloats(lista, 1);
                printf("Lista ordenada automaticamente (floats ascendentes).\n");
            }

            break;
        }

        case 3:
        {
            int tipo = detectarTipoLista(lista);
            if (tipo == TIPO_INT)
            {
                printf("1. Ascendente\n2. Descendente\nSeleccione orden: ");
                int ord;
                scanf("%d", &ord);
                limpiarBuffer();
                if (ord == 1 || ord == 2)
                {
                    lista = ordenarEnteros(lista, ord == 1);
                    printf("Lista ordenada.\n");
                }
                else
                {
                    printf("Opcion invalida.\n");
                }
            }
            else
            {
                printf("No se puede ordenar: lista vacía o con tipos no enteros.\n");
            }
            break;
        }

        case 4:
            printf("Largo de la lista: %d\n", obtenerLargo(lista));
            break;

        case 5:
        {
            int pos;
            printf("Ingrese posicion: ");
            scanf("%d", &pos);
            limpiarBuffer();
            obtenerElemento(lista, pos);
            break;
        }

        case 6:
        {
            int pos;
            printf("Ingrese posicion a eliminar: ");
            scanf("%d", &pos);
            limpiarBuffer();
            lista = eliminarElemento(lista, pos);
            break;
        }

        case 7:
            imprimirLista(lista);
            break;

        case 0:
            liberarLista(lista);
            printf("Saliendo...\n");
            break;

        default:
            printf("Opción invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}
