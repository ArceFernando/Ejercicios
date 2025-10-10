#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipos que acepta la lista
typedef enum
{
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_CHAR,
    TIPO_STRUCT
} TipoDato;

// Ejemplo de estructura personalizada
typedef struct
{
    int id;
    char nombre[20];
} MiEstructura;

typedef struct Nodo
{
    TipoDato tipo;
    void *dato; // puntero  al dato
    struct Nodo *siguiente;
} Nodo;

// Crear lista vacia
Nodo *crearLista()
{
    return NULL;
}

// Funciones para crear datos en heap para almacenar en nodo
void *crearDatoInt(int valor)
{
    int *p = malloc(sizeof(int));
    *p = valor;
    return p;
}

void *crearDatoFloat(float valor)
{
    float *p = malloc(sizeof(float));
    *p = valor;
    return p;
}

void *crearDatoChar(char valor)
{
    char *p = malloc(sizeof(char));
    *p = valor;
    return p;
}

void *crearDatoStruct(MiEstructura valor)
{
    MiEstructura *p = malloc(sizeof(MiEstructura));
    *p = valor;
    return p;
}

// Agregar elemento al final
Nodo *agregarElemento(Nodo *cabeza, TipoDato tipo, void *dato)
{
    Nodo *nuevo = malloc(sizeof(Nodo));
    nuevo->tipo = tipo;
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    if (cabeza == NULL)
    {
        return nuevo;
    }

    Nodo *actual = cabeza;
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;

    return cabeza;
}

// Detectar tipo dominante (si todos iguales, devuelve tipo, sino -1)
int detectarTipoLista(Nodo *cabeza)
{
    if (!cabeza)
        return -1;
    TipoDato tipo = cabeza->tipo;
    Nodo *actual = cabeza->siguiente;
    while (actual)
    {
        if (actual->tipo != tipo)
        {
            return -1; // Mixta
        }
        actual = actual->siguiente;
    }
    return tipo;
}

// Obtener largo
int obtenerLargo(Nodo *cabeza)
{
    int cont = 0;
    while (cabeza)
    {
        cont++;
        cabeza = cabeza->siguiente;
    }
    return cont;
}

// Imprimir un nodo segun tipo
void imprimirNodo(Nodo *nodo)
{
    switch (nodo->tipo)
    {
    case TIPO_INT:
        printf("%d", *(int *)(nodo->dato));
        break;
    case TIPO_FLOAT:
        printf("%.2f", *(float *)(nodo->dato));
        break;
    case TIPO_CHAR:
        printf("'%c'", *(char *)(nodo->dato));
        break;
    case TIPO_STRUCT:
    {
        MiEstructura *s = (MiEstructura *)nodo->dato;
        printf("{id:%d, nombre:%s}", s->id, s->nombre);
        break;
    }
    default:
        printf("Tipo desconocido");
    }
}

// Imprimir lista completa
void imprimirLista(Nodo *cabeza)
{
    printf("Lista: ");
    while (cabeza)
    {
        imprimirNodo(cabeza);
        printf(" -> ");
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

// Obtener elemento N
void obtenerElemento(Nodo *cabeza, int n)
{
    int i = 0;
    while (cabeza)
    {
        if (i == n)
        {
            printf("Elemento en posición %d: ", n);
            imprimirNodo(cabeza);
            printf("\n");
            return;
        }
        cabeza = cabeza->siguiente;
        i++;
    }
    printf("Índice fuera de rango.\n");
}

// Eliminar elemento N
Nodo *eliminarElemento(Nodo *cabeza, int n)
{
    if (!cabeza)
        return NULL;

    Nodo *temp;
    if (n == 0)
    {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp->dato);
        free(temp);
        return cabeza;
    }

    Nodo *actual = cabeza;
    for (int i = 0; actual != NULL && i < n - 1; i++)
    {
        actual = actual->siguiente;
    }

    if (!actual || !actual->siguiente)
    {
        printf("Índice fuera de rango.\n");
        return cabeza;
    }

    temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    free(temp->dato);
    free(temp);
    return cabeza;
}

// Ordenar lista si es de enteros
Nodo *ordenarEnteros(Nodo *cabeza, int ascendente)
{
    if (!cabeza || !cabeza->siguiente)
        return cabeza;

    Nodo *i, *j;
    for (i = cabeza; i != NULL; i = i->siguiente)
    {
        for (j = i->siguiente; j != NULL; j = j->siguiente)
        {
            int vi = *(int *)(i->dato);
            int vj = *(int *)(j->dato);
            int cambiar = (ascendente) ? (vi > vj) : (vi < vj);
            if (cambiar)
            {
                int temp = vi;
                *(int *)(i->dato) = vj;
                *(int *)(j->dato) = temp;
            }
        }
    }
    return cabeza;
}

// Limpiar buffer stdin
void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Menú
int main()
{
    Nodo *lista = crearLista();
    int opcion;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Crear e inicializar lista\n");
        printf("2. Agregar un elemento\n");
        printf("3. Ordene de forma ascendente o descendente solo para enteros\n");
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
            // Liberar lista previa
            while (lista != NULL)
            {
                Nodo *temp = lista;
                lista = lista->siguiente;
                free(temp->dato);
                free(temp);
            }
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

            // Orden automático si la lista es de enteros o floats
            int tipoLista = detectarTipoLista(lista);
            if (tipoLista == TIPO_INT)
            {
                lista = ordenarEnteros(lista, 1); // Ascendente
                printf("Lista ordenada automaticamente (enteros ascendentes).\n");
            }
            else if (tipoLista == TIPO_FLOAT)
            {
                // Implementar ordenamiento de floats
                Nodo *i, *j;
                for (i = lista; i != NULL; i = i->siguiente)
                {
                    for (j = i->siguiente; j != NULL; j = j->siguiente)
                    {
                        float vi = *(float *)(i->dato);
                        float vj = *(float *)(j->dato);
                        if (vi > vj)
                        {
                            float temp = vi;
                            *(float *)(i->dato) = vj;
                            *(float *)(j->dato) = temp;
                        }
                    }
                }
                printf("Lista ordenada automaticamente (floats ascendentes).\n");
            }

            break;
        }

        case 3:
        {
            int tipo = detectarTipoLista(lista);
            if (tipo == TIPO_INT)
            {
                printf("La lista contiene solo enteros.\n");
                printf("1. Orden ascendente\n2. Orden descendente\n");
                int ord;
                printf("Seleccione orden: ");
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
            else if (tipo == -1)
            {
                printf("La lista tiene tipos mixtos o esta vacia. No se puede ordenar.\n");
            }
            else
            {
                printf("La lista contiene elementos no enteros, no se puede ordenar.\n");
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
            // Liberar memoria antes de salir
            while (lista != NULL)
            {
                Nodo *temp = lista;
                lista = lista->siguiente;
                free(temp->dato);
                free(temp);
            }
            printf("Saliendo...\n");
            break;

        default:
            printf("Opción invalida.\n");
        }
    } while (opcion != 0);

    return 0;
}
