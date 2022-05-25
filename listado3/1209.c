/*

Autor: Claudia Cser
Usuario Timus: clcser
Para este problema revisé la seccion de discusion(1s are located at (i-th Tri-angular number + 1)th 
position (by A. A. Noman Ansary))

Ej 16: 1209 Timus

*/

#include <stdio.h>
#include <math.h>

int main() {
    long long int pos, auxB;
    double auxA;
    int n;
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        // recibir una posicion
        scanf("%lld",&pos);
        
        // si (pos*8)-7 es un cuadrado perfecto, en esa posicion hay un 1
        auxA = sqrt((pos*8)-7);
        // revisar si el numero es un cuadrado perfecto (si su raiz cuadrada no tiene decimales != 0)
        auxB = auxA;
        
        if(auxA == auxB) {
            printf("1 ");
        } else 
            printf("0 ");
    }

    return 0;
}
