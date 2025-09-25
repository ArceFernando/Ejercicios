#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PERSONAS 5
#define MAX_NOMBRE 50
#define MAX_APELLIDO 50
#define MAX_CARRERA 50
#define MAX_MATERIAS 5
#define MAX_MATERIA_NOMBRE 30
#define ARCHIVO_PERSONAS "personas.txt"

int ultimoID = 0; // ID incremental global

typedef struct
{
    int id; // Identificador único
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    int edad;
    char carrera[MAX_CARRERA];
    char materias[MAX_MATERIAS][MAX_MATERIA_NOMBRE];
} Persona;

// ---------------------- VALIDACIONES -------------------------

void leerCadena(char *cadena, int max)
{
    fgets(cadena, max, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

int esNumeroEntero(const char *cadena)
{
    if (*cadena == '\0')
        return 0;
    if (*cadena == '-' || *cadena == '+')
        cadena++;
    if (*cadena == '\0')
        return 0;
    while (*cadena)
    {
        if (!isdigit(*cadena))
            return 0;
        cadena++;
    }
    return 1;
}

int esCadenaSoloLetras(const char *cadena)
{
    while (*cadena)
    {
        if (!isalpha(*cadena) && !isspace(*cadena))
            return 0;
        cadena++;
    }
    return 1;
}

int leerEntero(const char *mensaje)
{
    char buffer[100];
    int valor;
    while (1)
    {
        printf("%s", mensaje);
        leerCadena(buffer, sizeof(buffer));
        if (esNumeroEntero(buffer))
        {
            valor = atoi(buffer);
            return valor;
        }
        else
        {
            printf("Entrada invalida. Ingrese un numero entero.\n");
        }
    }
}

int leerEdad(const char *mensaje)
{
    int edad;
    while (1)
    {
        edad = leerEntero(mensaje);
        if (edad >= 0 && edad <= 120)
            return edad;
        else
            printf("Edad invalida. Debe estar entre 0 y 120.\n");
    }
}

void leerCadenaSoloLetras(char *destino, int max, const char *mensaje)
{
    while (1)
    {
        printf("%s", mensaje);
        leerCadena(destino, max);
        if (strlen(destino) == 0)
        {
            printf("No puede estar vacio. Intente de nuevo.\n");
        }
        else if (!esCadenaSoloLetras(destino))
        {
            printf("Solo se permiten letras y espacios. Intente de nuevo.\n");
        }
        else
        {
            return;
        }
    }
}

// ---------------------- PERSONA ----------------------------

Persona *crearPersona()
{
    Persona *p = (Persona *)malloc(sizeof(Persona));
    if (!p)
    {
        printf("Error al asignar memoria.\n");
        return NULL;
    }

    p->id = ++ultimoID;

    leerCadenaSoloLetras(p->nombre, MAX_NOMBRE, "Nombre: ");
    leerCadenaSoloLetras(p->apellido, MAX_APELLIDO, "Apellido: ");
    p->edad = leerEdad("Edad (0 - 120): ");
    leerCadenaSoloLetras(p->carrera, MAX_CARRERA, "Carrera: ");

    int n = leerEntero("¿Cuantas materias desea ingresar? (max 5): ");
    if (n < 0)
        n = 0;
    else if (n > MAX_MATERIAS)
        n = MAX_MATERIAS;

    for (int i = 0; i < n; i++)
    {
        char mat[MAX_MATERIA_NOMBRE];
        char msg[60];
        snprintf(msg, sizeof(msg), "Materia %d: ", i + 1);
        leerCadenaSoloLetras(mat, MAX_MATERIA_NOMBRE, msg);
        strncpy(p->materias[i], mat, MAX_MATERIA_NOMBRE - 1);
        p->materias[i][MAX_MATERIA_NOMBRE - 1] = '\0';
    }

    for (int i = n; i < MAX_MATERIAS; i++)
        p->materias[i][0] = '\0';

    return p;
}
void modificarPersona(Persona *p)
{
    if (!p)
    {
        printf("Persona no existe.\n");
        return;
    }

    printf("Modificando persona (ID %d):\n", p->id);

    char buffer[100];

    // Nombre
    while (1)
    {
        printf("Nombre actual: %s\n", p->nombre);
        printf("Nuevo nombre (enter para mantener): ");
        leerCadena(buffer, sizeof(buffer));
        if (strlen(buffer) == 0)
        {
            // Mantener actual
            break;
        }
        else if (!esCadenaSoloLetras(buffer))
        {
            printf("Solo se permiten letras y espacios. Intente de nuevo.\n");
        }
        else
        {
            strncpy(p->nombre, buffer, MAX_NOMBRE - 1);
            p->nombre[MAX_NOMBRE - 1] = '\0';
            break;
        }
    }

    // Apellido
    while (1)
    {
        printf("Apellido actual: %s\n", p->apellido);
        printf("Nuevo apellido (enter para mantener): ");
        leerCadena(buffer, sizeof(buffer));
        if (strlen(buffer) == 0)
        {
            break;
        }
        else if (!esCadenaSoloLetras(buffer))
        {
            printf("Solo se permiten letras y espacios. Intente de nuevo.\n");
        }
        else
        {
            strncpy(p->apellido, buffer, MAX_APELLIDO - 1);
            p->apellido[MAX_APELLIDO - 1] = '\0';
            break;
        }
    }

    // Edad
    while (1)
    {
        printf("Edad actual: %d\n", p->edad);
        printf("Nueva edad (enter para mantener): ");
        leerCadena(buffer, sizeof(buffer));
        if (strlen(buffer) == 0)
        {
            break;
        }
        else if (esNumeroEntero(buffer))
        {
            int edad = atoi(buffer);
            if (edad >= 0 && edad <= 120)
            {
                p->edad = edad;
                break;
            }
            else
                printf("Edad invalida. Debe estar entre 0 y 120.\n");
        }
        else
        {
            printf("Entrada invalida. Ingrese un numero entero.\n");
        }
    }

    // Carrera
    while (1)
    {
        printf("Carrera actual: %s\n", p->carrera);
        printf("Nueva carrera (enter para mantener): ");
        leerCadena(buffer, sizeof(buffer));
        if (strlen(buffer) == 0)
        {
            break;
        }
        else if (!esCadenaSoloLetras(buffer))
        {
            printf("Solo se permiten letras y espacios. Intente de nuevo.\n");
        }
        else
        {
            strncpy(p->carrera, buffer, MAX_CARRERA - 1);
            p->carrera[MAX_CARRERA - 1] = '\0';
            break;
        }
    }

    // Materias
    printf("Materias actuales:\n");
    int materiasActuales = 0;
    for (int i = 0; i < MAX_MATERIAS; i++)
    {
        if (p->materias[i][0] != '\0')
        {
            printf("  %d. %s\n", i + 1, p->materias[i]);
            materiasActuales++;
        }
    }
    if (materiasActuales == 0)
        printf("  (Ninguna)\n");

    int n;
    while (1)
    {
        printf("Cuantas materias desea ingresar? (0 a %d, enter para mantener actuales): ", MAX_MATERIAS);
        leerCadena(buffer, sizeof(buffer));
        if (strlen(buffer) == 0)
        {
            // Mantener actuales
            n = materiasActuales;
            break;
        }
        else if (esNumeroEntero(buffer))
        {
            n = atoi(buffer);
            if (n >= 0 && n <= MAX_MATERIAS)
                break;
            else
                printf("Numero invalido. Intente de nuevo.\n");
        }
        else
        {
            printf("Entrada invalida. Intente de nuevo.\n");
        }
    }

    if (strlen(buffer) != 0) // Si ingresó un nuevo número de materias, modificar
    {
        for (int i = 0; i < n; i++)
        {
            while (1)
            {
                char msg[60];
                snprintf(msg, sizeof(msg), "Materia %d: ", i + 1);
                printf("%s", msg);
                leerCadena(buffer, sizeof(buffer));
                if (strlen(buffer) == 0)
                {
                    printf("La materia no puede estar vacia.\n");
                    continue;
                }
                if (!esCadenaSoloLetras(buffer))
                {
                    printf("Solo se permiten letras y espacios. Intente de nuevo.\n");
                    continue;
                }
                strncpy(p->materias[i], buffer, MAX_MATERIA_NOMBRE - 1);
                p->materias[i][MAX_MATERIA_NOMBRE - 1] = '\0';
                break;
            }
        }
        for (int i = n; i < MAX_MATERIAS; i++)
            p->materias[i][0] = '\0';
    }

    printf("Persona modificada.\n");
}

void mostrarPersona(const Persona *p, int indice)
{
    if (!p)
    {
        printf("Persona %d: [Vacia]\n", indice + 1);
        return;
    }

    printf("Persona %d:\n", indice + 1);
    printf("  ID: %d\n", p->id);
    printf("  Nombre: %s %s\n", p->nombre, p->apellido);
    printf("  Edad: %d\n", p->edad);
    printf("  Carrera: %s\n", p->carrera);
    printf("  Materias:\n");

    int vacias = 1;
    for (int i = 0; i < MAX_MATERIAS; i++)
    {
        if (p->materias[i][0] != '\0')
        {
            printf("    - %s\n", p->materias[i]);
            vacias = 0;
        }
    }
    if (vacias)
        printf("    (Ninguna)\n");
}

// ---------------------- ARCHIVOS -----------------------

void guardarEnArchivo(Persona *personas[], int total)
{
    FILE *f = fopen(ARCHIVO_PERSONAS, "w");
    if (!f)
    {
        printf("No se pudo abrir el archivo para guardar.\n");
        return;
    }

    for (int i = 0; i < total; i++)
    {
        if (personas[i])
        {
            fprintf(f, "ID: %d\n", personas[i]->id);
            fprintf(f, "%s\n%s\n%d\n%s\n", personas[i]->nombre, personas[i]->apellido, personas[i]->edad, personas[i]->carrera);

            int count = 0;
            for (int j = 0; j < MAX_MATERIAS; j++)
                if (personas[i]->materias[j][0] != '\0')
                    count++;

            fprintf(f, "Materias: %d\n", count);
            for (int j = 0; j < count; j++)
                fprintf(f, "%s\n", personas[i]->materias[j]);

            fprintf(f, "---\n");
        }
    }

    fclose(f);
    printf("Personas guardadas en '%s'.\n", ARCHIVO_PERSONAS);
}

void cargarDesdeArchivo(Persona *personas[], int total)
{
    FILE *f = fopen(ARCHIVO_PERSONAS, "r");
    if (!f)
    {
        printf("Archivo '%s' no encontrado.\n", ARCHIVO_PERSONAS);
        return;
    }

    char buffer[100];
    int index = 0;

    while (fgets(buffer, sizeof(buffer), f) && index < total)
    {
        Persona *p = (Persona *)malloc(sizeof(Persona));
        if (!p)
            break;

        sscanf(buffer, "ID: %d", &p->id);
        if (p->id > ultimoID)
            ultimoID = p->id;

        fgets(buffer, sizeof(buffer), f);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(p->nombre, buffer, MAX_NOMBRE);

        fgets(buffer, sizeof(buffer), f);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(p->apellido, buffer, MAX_APELLIDO);

        fgets(buffer, sizeof(buffer), f);
        p->edad = atoi(buffer);

        fgets(buffer, sizeof(buffer), f);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(p->carrera, buffer, MAX_CARRERA);

        fgets(buffer, sizeof(buffer), f);
        int numMaterias = 0;
        sscanf(buffer, "Materias: %d", &numMaterias);

        for (int i = 0; i < MAX_MATERIAS; i++)
            p->materias[i][0] = '\0';

        for (int i = 0; i < numMaterias && i < MAX_MATERIAS; i++)
        {
            fgets(buffer, sizeof(buffer), f);
            buffer[strcspn(buffer, "\n")] = '\0';
            strncpy(p->materias[i], buffer, MAX_MATERIA_NOMBRE - 1);
        }

        fgets(buffer, sizeof(buffer), f); // separador ---
        personas[index++] = p;
    }

    fclose(f);
    printf("%d persona(s) cargadas desde '%s'.\n", index, ARCHIVO_PERSONAS);
}

// ---------------------- MAIN -------------------------

int main()
{
    Persona *personas[MAX_PERSONAS] = {0};
    int opcion;

    printf("Nota: Solo se permiten letras y espacios en los campos de texto.\n");

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Crear persona\n");
        printf("2. Mostrar una persona\n");
        printf("3. Mostrar todas\n");
        printf("4. Guardar en archivo\n");
        printf("5. Cargar desde archivo\n");
        printf("6. Modificar persona\n");
        printf("7. Borrar persona\n");
        printf("8. Salir\n");

        opcion = leerEntero("Opcion: ");

        switch (opcion)
        {
        case 1:
        {
            int i;
            for (i = 0; i < MAX_PERSONAS; i++)
                if (!personas[i])
                    break;

            if (i == MAX_PERSONAS)
                printf("Límite alcanzado.\n");
            else
            {
                personas[i] = crearPersona();
                printf("Persona creada con ID %d.\n", personas[i]->id);
            }
            break;
        }

        case 2:
        {
            int pos = leerEntero("Numero de persona (1-5): ");
            if (pos < 1 || pos > MAX_PERSONAS || !personas[pos - 1])
                printf("Posición invalida o vacia.\n");
            else
                mostrarPersona(personas[pos - 1], pos - 1);
            break;
        }

        case 3:
            for (int i = 0; i < MAX_PERSONAS; i++)
                mostrarPersona(personas[i], i);
            break;

        case 4:
            guardarEnArchivo(personas, MAX_PERSONAS);
            break;

        case 5:
            for (int i = 0; i < MAX_PERSONAS; i++)
            {
                if (personas[i])
                {
                    free(personas[i]);
                    personas[i] = NULL;
                }
            }
            cargarDesdeArchivo(personas, MAX_PERSONAS);
            break;

        case 6:
        {
            int pos = leerEntero("Numero de persona a modificar (1-5): ");
            if (pos < 1 || pos > MAX_PERSONAS || !personas[pos - 1])
                printf("Posicion invalida o vacia.\n");
            else
                modificarPersona(personas[pos - 1]);
            break;
        }

        case 7:
        {
            int pos = leerEntero("Numero de persona a borrar (1-5): ");
            if (pos < 1 || pos > MAX_PERSONAS || !personas[pos - 1])
                printf("Posicion invalida o vacia.\n");
            else
            {
                free(personas[pos - 1]);
                personas[pos - 1] = NULL;
                printf("Persona borrada.\n");
            }
            break;
        }

        case 8:
            printf("Saliendo...\n");
            for (int i = 0; i < MAX_PERSONAS; i++)
            {
                if (personas[i])
                {
                    free(personas[i]);
                    personas[i] = NULL;
                }
            }
            break;

        default:
            printf("Opcion no valida.\n");
        }

    } while (opcion != 8);

    return 0;
}
