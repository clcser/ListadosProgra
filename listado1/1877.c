/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Timus #1877 (Bicycle Codes)
*/

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);

    if(a%2 == 0 || b%2 == 1)
        printf("yes");
    else printf("no");

    return 0;
}
