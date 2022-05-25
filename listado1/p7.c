/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ordenar 4 números sin usar ciclos
*/

#include <stdio.h>

int main() {
    int num[4];
    scanf("%d%d%d%d", &num[0], &num[1], &num[2], &num[3]);

    // Encontrar primer numero

    int tmp0, tmp1, aux;

    if(num[0] < num[1]) {
        tmp0 = num[0];
    } else tmp0 = num[1];
    
    if(num[2] < num[3]) {
        tmp1 = num[2];
    } else tmp1 = num[3];

    if(tmp0 < tmp1) {
        if(tmp0 == num[1]) {    // swap num[0] y num[1]
            aux = num[0];  
            num[0] = num[1];
            num[1] = aux;
        }
    } else {
        if(tmp1 == num[2]) {    // swap num[0] y num[2]
            aux = num[0];  
            num[0] = num[2];
            num[2] = aux;
        } else if(tmp1 == num[3]) {    // swap num[0] y num[3]
            aux = num[0];  
            num[0] = num[3];
            num[3] = aux;
        }
    }
    
    // Encontrar segundo numero
    
    if(num[1] < num[2]) {
        tmp1 = num[1];
    } else tmp1 = num[2];

    if(tmp1 < num[3]) {
        if(tmp1 == num[2]) {    // swap num[1] y num[2]
            aux = num[1];  
            num[1] = num[2];
            num[2] = aux;
        }
    } else {    // swap num[1] y num[3]
        aux = num[1];  
        num[1] = num[3];
        num[3] = aux;
    }

    // Encontrar tercer y cuarto numeros
    
    if(num[3] < num[2]) {   // swap num[2] y num[3]
        aux = num[2];  
        num[2] = num[3];
        num[3] = aux;
    }
    
    // Imprimir

    printf("%d, %d, %d, %d\n", num[0], num[1], num[2], num[3]);

    return 0;
}
