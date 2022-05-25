/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

En una tripleta de números verificar cuantos son negativos
*/

#include <stdio.h>

int main() {
    int n1, n2, n3;
    scanf("%d%d%d", &n1, &n2, &n3);

    int c = 0;
    if(n1 < 0)
        c++;
    if(n2 < 0)
        c++;
    if(n3 < 0)
        c++;

    switch(c) {
        case 0: printf("ninguno");
                break;
        case 1: printf("al menos uno");
                break;
        case 2: printf("al menos dos");
                break;
        case 3: printf("todos");
                break;
    }

    return 0;
}
