/*
Los creditos por esta respuesta van completamente para Leoardo Lovera
Claudia Cser
Usuario Timus: clcser
Ej 11:wq
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Leer orden de la matriz
    int n;

    do
    {
        printf("Ingrese un numero entero positivo: ");
        scanf("%d", &n);
    }
    while (n <= 0);

    int original[n][n], distancias[n][n];
    int i, j, p, q, diff, dist, minDiff, minDist, flag;

    // Leer entradas de original
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
        {
            printf("#%d/%d Ingrese un numero entero: ", i * n + j + 1, n * n);
            scanf("%d", &original[i][j]);
        }

    // Iterar sobre cada elemento de original para encontrar
    // la distancia minima del elemento que minimiza la
    // diferencia positiva de original[i][j] con original[p][q]
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
        {
            flag = 0;

            for (p = 0; p < n; ++p)
                for (q = 0; q < n; ++q)
                {
                    // No revisar la misma entrada
                    if (i == p && j == q)
                        continue;

                    // Calcular diferencia y distancia actuales
                    diff = abs(original[i][j] - original[p][q]);
                    dist = abs(p - i) + abs(q - j);

                    // Si es la primera vez que se ingresa
                    // inicializar las variables minimas
                    if (flag == 0)
                    {
                        minDiff = diff;
                        minDist = dist;
                        ++flag;
                    }
                    // Buscar minima diferencia e ir guardando su distancia
                    else if (diff < minDiff)
                    {
                        minDiff = diff;
                        minDist = dist;
                    }
                    // Si encontramos una entrada con la minima diferencia
                    // y una menor distancia, actualizar la distancia
                    else if (diff == minDiff && dist < minDist)
                        minDist = dist;
                }

            // Guardar el valor obtenido
            distancias[i][j] = minDist;
        }

    // Imprimir la matriz distancias
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
            printf("%d ", distancias[i][j]);

        printf("\n");
    }

    return 0;
}
 
