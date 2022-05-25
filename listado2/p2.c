/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 2: Imprimir las n primeras potencias de 2
*/

#include <stdio.h>

int main() {
    int n, pow;
    do (scanf("%d",&n));
    while (n < 0);

    if(n == 0) {
        printf("1\n");
        return 0;
    }
    
    pow = 2;
    for(int i = 0; i < n; i++) {
        printf("%d\n", pow);
        pow *= 2;
    }

    return 0;
}
