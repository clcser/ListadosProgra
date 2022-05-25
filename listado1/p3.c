/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Verifcar si una tripleta de numeros cumple la condicion
*/

#include <stdio.h>

int main() {
    int n1, n2, n3;
    scanf("%d%d%d", &n1, &n2, &n3);

    if((n1 + n2) < ((n3*n3)/n1))
        printf("Cumple invariante");
    
    return 0;
}
