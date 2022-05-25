/*

Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de forma individual

Ej 7: Escribe un programa que lea una línea de texto con el siguiente formato: "2xN1 3xN2", donde 
N1 y N2 son números, e imprima el menor entre ellos. Note que no hay espacios en cada una de las 
dos expresiones. Se exige que se lea la entrada como una cadena de caracteres. 

*/

#include <stdio.h>
#include <string.h>

int main() {
    int n1 = 0, n2 = 0, pow = 1, c1Len, c2Len, min;
    char c1[0xFF];
    char c2[0xFF];

    scanf("%s %s",c1,c2);

    c1Len = strlen(c1);
    for(int i = c1Len-1; i >= 2; i--) {
        n1 += (c1[i]-48)*pow;
        pow *= 10;
    }

    pow = 1;

    c2Len = strlen(c2);
    for(int i = c2Len-1; i >= 2; i--) {
        n2 += (c2[i]-48)*pow;
        pow *= 10;    
    }

    min = n1 < n2 ? n1 : n2;
    printf("%d\n", min);

    return 0;
}
