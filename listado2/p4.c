/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 4: calculadora de numeros primos
*/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            printf("compuesto\n");
            return 0;
        }
    }
    printf("primo\n"); 

    return 0;
}
