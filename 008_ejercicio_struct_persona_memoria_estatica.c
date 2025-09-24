#include <stdio.h>
#include <string.h>

#define MAX_PERSONAS 5

typedef struct
{
    char nombre[50];
    int edad;
    int activa; // 1 si hay datos, 0 si está vacía
} Persona;

// Función para crear una persona
void crearPersona(Persona *p, const char *nombre, int edad)
{
    if (p == NULL)
        return;
    strncpy(p->nombre, nombre, sizeof(p->nombre) - 1);
    p->nombre[sizeof(p->nombre) - 1] = '\0';
    p->edad = edad;
    p->activa = 1;
}

// Modificar nombre
void modificarNombre(Persona *p, const char *nuevoNombre)
{
    if (p == NULL || !p->activa)
        return;
    strncpy(p->nombre, nuevoNombre, sizeof(p->nombre) - 1);
    p->nombre[sizeof(p->nombre) - 1] = '\0';
}

// Modificar edad
void modificarEdad(Persona *p, int nuevaEdad)
{
    if (p == NULL || !p->activa)
        return;
    p->edad = nuevaEdad;
}

// Mostrar persona
void mostrarPersona(const Persona *p, int indice)
{
    if (p == NULL || !p->activa)
    {
        printf("Persona %d: [Vacía]\n", indice + 1);
        return;
    }
    printf("Persona %d:\n", indice + 1);
    printf("  Nombre: %s\n", p->nombre);
    printf("  Edad: %d\n", p->edad);
}

// Mostrar todas las personas
void mostrarTodasLasPersonas(const Persona personas[], int total)
{
    for (int i = 0; i < total; i++)
    {
        mostrarPersona(&personas[i], i);
    }
}

int main()
{
    Persona personas[MAX_PERSONAS] = {0}; // Inicializa todo a cero
    int opcion;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Crear persona\n");
        printf("2. Modificar nombre\n");
        printf("3. Modificar edad\n");
        printf("4. Mostrar una persona\n");
        printf("5. Mostrar todas las personas\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpia el salto de línea del buffer

        switch (opcion)
        {
        case 1:
        {
            int i;
            for (i = 0; i < MAX_PERSONAS; i++)
            {
                if (!personas[i].activa)
                    break;
            }
            if (i == MAX_PERSONAS)
            {
                printf("No hay espacio para mas personas.\n");
            }
            else
            {
                char nombre[50];
                int edad;
                printf("Ingrese nombre: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; // Eliminar salto de línea
                printf("Ingrese edad: ");
                scanf("%d", &edad);
                getchar(); // Limpia buffer
                crearPersona(&personas[i], nombre, edad);
                printf("Persona creada en posicion %d.\n", i + 1);
            }
            break;
        }
        case 2:
        {
            int pos;
            char nuevoNombre[50];
            printf("Ingrese el numero de persona a modificar (1-%d): ", MAX_PERSONAS);
            scanf("%d", &pos);
            getchar();
            if (pos < 1 || pos > MAX_PERSONAS || !personas[pos - 1].activa)
            {
                printf("Posición invalida o vacia.\n");
                break;
            }
            printf("Ingrese nuevo nombre: ");
            fgets(nuevoNombre, sizeof(nuevoNombre), stdin);
            nuevoNombre[strcspn(nuevoNombre, "\n")] = '\0';
            modificarNombre(&personas[pos - 1], nuevoNombre);
            printf("Nombre modificado.\n");
            break;
        }
        case 3:
        {
            int pos, nuevaEdad;
            printf("Ingrese el numero de persona a modificar (1-%d): ", MAX_PERSONAS);
            scanf("%d", &pos);
            if (pos < 1 || pos > MAX_PERSONAS || !personas[pos - 1].activa)
            {
                printf("Posición invalida o vacia.\n");
                break;
            }
            printf("Ingrese nueva edad: ");
            scanf("%d", &nuevaEdad);
            modificarEdad(&personas[pos - 1], nuevaEdad);
            printf("Edad modificada.\n");
            break;
        }
        case 4:
        {
            int pos;
            printf("Ingrese el numero de persona a mostrar (1-%d): ", MAX_PERSONAS);
            scanf("%d", &pos);
            if (pos < 1 || pos > MAX_PERSONAS)
            {
                printf("Posición invalida.\n");
                break;
            }
            mostrarPersona(&personas[pos - 1], pos - 1);
            break;
        }
        case 5:
            mostrarTodasLasPersonas(personas, MAX_PERSONAS);
            break;
        case 6:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opción no valida.\n");
        }

    } while (opcion != 6);

    return 0;
}
