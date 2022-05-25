/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Verificar si la tercera coordenada está contenida en el rectangulo delimitado por las primeras dos
*/

#include <stdio.h>

int main() {
    int x1, y1, x2, y2, x3, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    if((x3 <= x1 && x3 >= x2 && y3 <= y1 && y3 >= y2) || (x3 >= x1 && x3 <= x2 && y3 >= y1 && y3 <= y2))
        printf("contenido\n");
    else printf("no contenido\n");

    return 0;
}
