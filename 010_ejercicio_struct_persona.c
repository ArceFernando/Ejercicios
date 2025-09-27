#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dni;
    char nombre[100];
} Persona;

// Antes copiábamos los parámetros al stack de la función de esta manera:
// void printStackPersona(Persona persona) {
//   printf("%d %s \n", persona.dni, persona.nombre);
// }

// Ahora podemos simplemente pasar el puntero:
void printPunteroPersona(Persona *persona)
{
    printf("%d %s \n", persona->dni, persona->nombre);
}

// Si usábamos el stack de la función, teníamos que pisar la variable con el
// return:
Persona modificarRetornaPersona(Persona persona, int dni, char *nombre)
{
    persona.dni = dni;
    strcpy(persona.nombre, nombre);
    return persona;
}

// Ahora podemos modificar la posición de memoria directamente:
void modificarPunteroPersona(Persona *persona, int dni, char *nombre)
{
    persona->dni = dni;
    strcpy(persona->nombre, nombre);
}

int main()
{
    // Una persona definida en el stack de la función. Se reserva la memoria al
    // iniciar la aplicación.
    Persona personaEnStack;

    // Pisamos la variable:
    personaEnStack = modificarRetornaPersona(personaEnStack, 123, "nombre");
    // Podemos usar nuestro print con puntero usando & para acceder a la posición
    // de memoria independientemente de cómo definimos el struct
    printPunteroPersona(&personaEnStack);

    // O sino, modificamos directamente la posición de memoria:
    modificarPunteroPersona(&personaEnStack, 456, "nombre2");
    printPunteroPersona(&personaEnStack);

    // Creamos un struct en el Heap o memoria de ejecución.
    // Muy útil para cuando queramos agregar entidades dinámicas a un array.
    Persona *personaEnHeap = malloc(sizeof(Persona));

    // Probamos lo mismo de antes pero con el struct en heap:

    // Necesitamos usar * para pisar el valor del puntero
    *personaEnHeap = modificarRetornaPersona(*personaEnHeap, 123, "nombre");
    // No es necesario & porque ya está definido como puntero
    printPunteroPersona(personaEnHeap);

    // O bien, directamente modificamos la memoria. En este caso queda más
    // natural:
    modificarPunteroPersona(personaEnHeap, 456, "nombre2");
    printPunteroPersona(personaEnHeap);

    // Recordemos que debemos liberar la memoria manualmente cuando ya no la
    // necesitemos:
    free(personaEnHeap);

    return 0;
}