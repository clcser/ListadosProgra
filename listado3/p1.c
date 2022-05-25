/*

Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de forma individual

Escribe un programa que, dado un número entero entre 0 y 255, imprima su representación como: 
Caracter, Entero sin signo, Número octal, Número hexadecimal.

*/

#include <stdio.h>

int main() {
    int l;
    scanf("%d", &l);
    
    printf("%c %u %o %x\n",l,l,l,l);

    return 0;
}
