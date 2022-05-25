/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Imprimir el doble del menor de dos numeros
*/

#include <stdio.h>

int main() {
    int n1, n2, menor;
    scanf("%d%d",&n1, &n2);

    menor = n1 < n2 ? n1 : n2;  // menor = menor entre n1 y n2
    printf("%d",menor*2);
 
    return 0;
}
