#include <stdio.h>
#include <string.h>

// Estructura personalizada
struct Persona
{
    char inicial;
    int edad;
    float altura;
};

void mostrar_bytes(void *ptr, size_t size)
{
    unsigned char *byte = (unsigned char *)ptr;

    for (size_t i = 0; i < size; i++)
    {
        printf("Byte %zu: 0x%02X\n", i, byte[i]);
    }
    printf("\n");
}

int main()
{
    // Tipos atómicos
    int entero = 12345;
    float flotante = 3.14f;
    char caracter = 'A';

    // Tipo estructurado
    struct Persona p;
    p.inicial = 'J';
    p.edad = 25;
    p.altura = 1.75f;

    // Arreglo
    int arreglo[3] = {10, 20, 30};

    printf("=== Representacion de bajo nivel ===\n\n");

    printf("int (entero = %d):\n", entero);
    mostrar_bytes(&entero, sizeof(entero));

    printf("float (flotante = %.2f):\n", flotante);
    mostrar_bytes(&flotante, sizeof(flotante));

    printf("char (caracter = %c):\n", caracter);
    mostrar_bytes(&caracter, sizeof(caracter));

    printf("struct Persona:\n");
    mostrar_bytes(&p, sizeof(p));

    printf("int arreglo[3] = {10, 20, 30}:\n");
    mostrar_bytes(arreglo, sizeof(arreglo));

    return 0;
}
