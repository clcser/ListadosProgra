/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 1: Imprimir n terminos de la sucesion de fibonacci
*/

#include <stdio.h>

int main() {
    int n, fib;
    scanf("%d",&n);

    int arr[2];
    arr[0] = 1;
    arr[1] = 1;
    printf("%d\n%d\n", arr[0], arr[1]);
    
    fib = 0;
    for(int i = 0; i < n-2; i++) {
        fib = arr[0] + arr[1];
        arr[0] = arr[1];
        arr[1] = fib;
        printf("%d\n", fib);
    }
    return 0;
}
