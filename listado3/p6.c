/*

Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de forma individual

Ej 6: Escribe un programa que lea un número de punto flotante e imprima por pantalla la suma de todos 
los dígitos que lo componen. 

*/

#include <stdio.h>
#include <string.h>

int main() {
    char num[0xF];
    scanf("%[^\n]",num);
    int sum = 0, len = strlen(num);

    for(int i = 0; i < len; i++) {
        if(num[i] != '.') {
            sum += num[i]-'0';
        }
    }

    printf("%d\n",sum);

    return 0;
}

