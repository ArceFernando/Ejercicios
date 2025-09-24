#ifndef PERSONA_H
#define PERSONA_H

#define MAX_PERSONAS 5

typedef struct
{
    char nombre[50];
    int edad;
    int activa; // 1 si hay datos, 0 si está vacía
} Persona;

// Declaraciones de funciones
void crearPersona(Persona *p, const char *nombre, int edad);
void modificarNombre(Persona *p, const char *nuevoNombre);
void modificarEdad(Persona *p, int nuevaEdad);
void mostrarPersona(const Persona *p, int indice);
void mostrarTodasLasPersonas(const Persona personas[], int total);

#endif // PERSONA_H
