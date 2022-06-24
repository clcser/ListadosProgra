/*
Claudia Cser
Solucion propia

Escriba la función char palindromo(char* cadena1) que devuelva 1 si cadena1 es un palı́ndromo y 0 en caso 
contrario. 
*/

#include <stdio.h>
#include <string.h>

char palindromo(char* cadena1) {
    int len = strlen(cadena1);
    for(int i = 0; i < len/2; i++) {
        if(cadena1[i] != cadena1[len-i-1])
            return 0;
    }
    return 1;
}

// Incluí el main para probar la funcion

int main() {
    char palin;
    char c[0xFF];

    scanf("%[^\n]",c);
    getchar();

    palin = palindromo(c);
    printf("%d\n", (int)palin);

    return 0;
}
