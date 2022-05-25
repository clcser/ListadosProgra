/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Intercambiar dos números
*/

#include <stdio.h>

int main() {
    int n1, n2;
    scanf("%d%d", &n1, &n2);

    if(n1 < 0 && n2 < 0) {
        int temp = n1;  //variable temporal que almacena el primer numero

        n1 = n2;
        n2 = temp;
    }

    return 0;
}
