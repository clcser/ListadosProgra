/*

Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de forma individual

Ej 8: Escribe un programa que pida un número entero (de 4 Bytes) y luego imprima tanto la 
representación entera como el código ASCII correspondientes a cada uno de los bytes que componen 
el número ingresado. 

*/

#include <stdio.h>

int main() {
    int num, c;
    scanf("%d", &num);

    for(int i = 0; i<4; i++) {
        c = (num & 0xFF);
        printf("%d - %c\n",c,c);
        num >>= 8;
    }

    return 0;
}
