#include <stdio.h>  // Para funciones de entrada/salida como printf, scanf, fgets
#include <string.h> // Para funciones de manejo de cadenas como strcspn
#include <ctype.h>  // Para funciones de clasificación de caracteres como isspace

// Verifica que el nombre ingresado no esté vacío ni sea solo espacios.

// Recorre cada carácter de la cadena nombre y si encuentra al menos un carácter que no sea espacio, retorna 1 (válido).

// Si termina el bucle sin encontrar caracteres visibles, retorna 0 (inválido).

int es_nombre_valido(const char *nombre)
{
    int tiene_letra = 0;

    // Verificar que la longitud no exceda 30 caracteres
    if (strlen(nombre) > 30)
    {
        return 0;
    }

    for (int i = 0; nombre[i] != '\0'; i++)
    {
        if (!isspace((unsigned char)nombre[i]))
        {
            if (!isalpha((unsigned char)nombre[i]))
            {
                // Encontró un carácter que no es letra ni espacio
                return 0;
            }
            else
            {
                tiene_letra = 1;
            }
        }
    }

    return tiene_letra; // Debe tener al menos una letra
}

int main()
{
    char nombre[30];
    int edad;

    // Solicita el nombre con validación
    do
    {
        printf("Ingrese su nombre: ");
        fgets(nombre, sizeof(nombre), stdin);
        /* Aquí, fgets lee una línea de texto desde el flujo estándar de entrada (stdin)
         y la almacena en el arreglo nombre.*/

        // Elimina el salto de línea (\n) si existe

        /* fgets() no retorna nada hasta que se presiona Enter. Así que, en la consola:
         Si el usuario solo presiona la barra espaciadora y
         luego Enter eso se detecta como solo espacios.*/

        nombre[strcspn(nombre, "\n")] = '\0';

        // la función strcspn calcula la longitud del segmento inicial de una cadena.

        if (!es_nombre_valido(nombre))
        {
            printf("El nombre no puede estar vacio ni contener solo espacios.\n");
        }

    } while (!es_nombre_valido(nombre));

    // Se llama a es_nombre_valido(nombre):

    // Si el nombre es solo espacios o. vacío, se muestra un mensaje de advertencia.

    // El bucle se repite hasta que se ingrese un nombre válido.

    // Solicita la edad con validación y rango
    do
    {
        printf("Ingrese su edad (entre 0 y 120): ");
        if (scanf("%d", &edad) != 1)
        {
            printf("Entrada invalida.\n");
            while (getchar() != '\n')
                ;      // Limpia el búfer
            edad = -1; // Para repetir el bucle
        }
        else if (edad < 0 || edad > 120)
        {
            printf(" La edad debe estar entre 0 y 120 anos.\n");
        }
    } while (edad < 0 || edad > 120);

    // scanf("%d", &edad) intenta leer un número entero:
    // Si el usuario escribe letras, se imprime un error y se limpia el búfer con while (getchar() != '\n').
    //  Se asigna -1 a edad para asegurar que el bucle se repita.

    // Imprime los datos
    printf("\n Datos ingresados:\n");
    printf("Nombre: %s\n", nombre);
    printf("Edad: %d\n", edad);

    return 0;
}
