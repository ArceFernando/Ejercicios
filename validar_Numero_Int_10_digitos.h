#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>

int esNumeroValido(char *cadena)
{
    int len = strlen(cadena);

    // Eliminar el salto de línea al final (si existe)
    if (len > 0 && cadena[len - 1] == '\n')
    {
        cadena[len - 1] = '\0';
        len--;
    }

    // Verificar si la cadena está vacía o es demasiado larga
    if (len == 0 || len > 11) // 1 para el signo y 10 para los dígitos
    {
        return 0;
    }

    int i = 0;

    // Si hay un signo al principio, saltarlo
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

    // No permitir más de 10 dígitos sin contar el signo
    if (digitCount > 10)
    {
        return 0;
    }

    // Convertir a número usando strtol y verificar que esté dentro del rango de int
    char *endptr;
    long numero = strtol(cadena, &endptr, 10);

    // Verificar que toda la cadena fue convertida correctamente
    if (*endptr != '\0')
    {
        return 0;
    }

    // Verificar que el número esté dentro del rango válido para int
    if (numero < INT_MIN || numero > INT_MAX)
    {
        return 0;
    }

    return 1; // Es un número válido
}
