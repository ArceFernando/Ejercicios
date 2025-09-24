#include <stdio.h>
#include <string.h>
#include "persona.h"

void crearPersona(Persona *p, const char *nombre, int edad)
{
    if (p == NULL)
        return;
    strncpy(p->nombre, nombre, sizeof(p->nombre) - 1);
    p->nombre[sizeof(p->nombre) - 1] = '\0';
    p->edad = edad;
    p->activa = 1;
}

void modificarNombre(Persona *p, const char *nuevoNombre)
{
    if (p == NULL || !p->activa)
        return;
    strncpy(p->nombre, nuevoNombre, sizeof(p->nombre) - 1);
    p->nombre[sizeof(p->nombre) - 1] = '\0';
}

void modificarEdad(Persona *p, int nuevaEdad)
{
    if (p == NULL || !p->activa)
        return;
    p->edad = nuevaEdad;
}

void mostrarPersona(const Persona *p, int indice)
{
    if (p == NULL || !p->activa)
    {
        printf("Persona %d: [Vacia]\n", indice + 1);
        return;
    }
    printf("Persona %d:\n", indice + 1);
    printf("  Nombre: %s\n", p->nombre);
    printf("  Edad: %d\n", p->edad);
}

void mostrarTodasLasPersonas(const Persona personas[], int total)
{
    for (int i = 0; i < total; i++)
    {
        mostrarPersona(&personas[i], i);
    }
}
