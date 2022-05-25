/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Imprimir todos los divisores de un numero sin usar ciclos.
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    if(n%2 == 0)
        printf("2 ");

    if(n%3 == 0)
        printf("3 ");

    if(n%4 == 0)
        printf("4 ");
    
    if(n%5 == 0)
        printf("5 ");
    
    if(n%6 == 0)
        printf("6 ");
    
    if(n%7 == 0)
        printf("7 ");
    
    if(n%8 == 0)
        printf("8 ");
    
    if(n%9 == 0)
        printf("9 ");
    
    if(n%10 == 0)
        printf("10 ");

    return 0;
}
