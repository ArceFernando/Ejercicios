#include <stdio.h>

int main()
{
    int a = 10;
    float b = 3.14;
    char c = 'X';

    // Punteros a cada variable
    int *ptrA = &a;
    float *ptrB = &b;
    char *ptrC = &c;

    // Imprimir valores y direcciones
    printf("Contenido y direcciones de memoria:\n\n");

    printf("Variable a: valor = %d\t\t direccion = %p\n", a, (void *)&a);
    printf("Variable b: valor = %.2f\t direccion = %p\n", b, (void *)&b);
    printf("Variable c: valor = %c\t\t direccion = %p\n", c, (void *)&c);

    printf("\nAccediendo a traves de punteros:\n\n");
    printf("Contenido de ptrA: %d\t\t Direccion apuntada: %p\n", *ptrA, (void *)ptrA);
    printf("Contenido de ptrB: %.2f\t Direccion apuntada: %p\n", *ptrB, (void *)ptrB);
    printf("Contenido de ptrC: %c\t\t Direccion apuntada: %p\n", *ptrC, (void *)ptrC);

    return 0;
}
