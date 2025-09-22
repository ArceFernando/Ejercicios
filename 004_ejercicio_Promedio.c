#include <stdio.h>
#include <stdlib.h> // Para atoi, strtol. Conversión de cadenas a números
#include <string.h> // Para strlen. Operaciones con cadenas
#include <ctype.h>  // Para isdigit. Verificar caracteres
#include <limits.h> // Para INT_MIN y INT_MAX. Límites de tipos de datos

#define N 3 // Cambia este valor si deseas promediar más números

int esNumeroValido(char *cadena)
/* Verifica si una cadena representa un número entero válido,
 de hasta 10 dígitos, incluyendo signo, y que quepa en un int.*/
{
    int len = strlen(cadena);

    // Eliminar salto de línea final si existe
    if (len > 0 && cadena[len - 1] == '\n')
    {
        cadena[len - 1] = '\0';
        len--;
    }
    // Se hace esto para no interferir con la validación de caracteres

    // Verificar si la cadena está vacía o excede longitud (signo + 10 dígitos)
    if (len == 0 || len > 11)
    {
        return 0;
    }

    int i = 0;

    // Permitir signo inicial
    if (cadena[0] == '-' || cadena[0] == '+')
    {
        if (len == 1)
            return 0; // Solo un signo no es válido
        i = 1;
    }

    int digitCount = 0;
    for (; i < len; i++)
    {
        if (!isdigit(cadena[i]))
        {
            return 0;
        }
        digitCount++;
    }

    if (digitCount > 10) // Máximo 10 dígitos sin signo
    {
        return 0;
    }

    // Validar rango de int
    char *endptr;
    long numero = strtol(cadena, &endptr, 10);
    if (*endptr != '\0') // Asegura que toda la cadena sea válida
    {
        return 0;
    }

    if (numero < INT_MIN || numero > INT_MAX)
    {
        return 0;
    }

    return 1;
}

int main()
{
    int numeros[N];
    int suma = 0;

    for (int i = 0; i < N; i++)
    {
        char linea[100]; // Tamaño suficientemente grande

        while (1)
        {
            printf("Ingrese el numero %d (hasta 10 digitos): ", i + 1);
            if (!fgets(linea, sizeof(linea), stdin))
            {
                printf("Error al leer la entrada.\n");
                return 1;
            }

            if (esNumeroValido(linea))
            {
                int valor = atoi(linea); // Ya validado
                numeros[i] = valor;
                suma += valor;
                break;
            }
            else
            {
                printf("Entrada invalida. Ingrese un numero entero valido de hasta 10 digitos.\n");
            }
        }
    }

    float promedio = (float)suma / N;
    printf("El promedio de los %d numeros es: %.2f\n", N, promedio);

    return 0;
}
