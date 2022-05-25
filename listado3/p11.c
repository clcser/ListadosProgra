/*

Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de forma individual

Ej 11: Escribe un programa que lea una línea de texto e imprima el número de caracteres, palabras, 
mayúsculas y minúsculas que componen la línea. 

*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[0xFF];
    int car = 0, pal = 1, may = 0, min = 0;

    scanf("%[^\n]", s);
    int len = strlen(s);
    
    for(int i = 0; i < len; i++) {
        car++;
        if(s[i] == ' ') pal++;
        else if(s[i] >= 'A' && s[i] <= 'Z') may++;
        else if(s[i] >= 'a' && s[i] <= 'z') min++;
    }

    printf("caracteres: %d, palabras: %d, mayusculas: %d, minusculas: %d\n",car,pal,may,min);
    
    return 0;
}
