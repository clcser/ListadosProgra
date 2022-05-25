/*

Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de forma individual

Ej 4: Escribe un programa que pida un caracter e imprima mayuscula, minuscula, numero u otro según 
sea el caso. 

*/

#include <stdio.h>

int main() {
    char l;
    scanf("%c", &l);

    if('A' <= l && l <= 'Z') printf("mayuscula\n");
    else if('a' <= l && l <= 'z') printf("minuscula\n");
    else if('0' <= l && l <= '9') printf("numero\n");
    else printf("otro\n");
    
    return 0;
}
