/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto con ayuda de la seccion de discusión del problema ("1820 Ural Steaks Explained - Simply - Accepted Solution - Read it before you start" by Manoj Pathak)

Timus #1820 (Ural Steaks)
*/

#include <stdio.h>

int main() {
    int n, k, ans;  // Variables para cantidad de steaks, espacios para cocinar y respuesta
    scanf("%d%d", &n, &k);
    
    if(n <= k) {    // Si la cantidad de espacios es mayor a la de steaks, el tiempo es constante (2 minutos)
        printf("2");
        return 0;
    }

    ans = n*2/k;    // Se cocinan k steaks a la vez, 1 minuto por lado 
    if(n*2%k != 0)  // Si la cantidad de steaks por 2 no es multiplo de la cantidad de espacios, se demorarán una tanda extra.
        ans++;
   
    printf("%d", ans);

    return 0;
}
