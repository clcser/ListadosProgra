/* 

Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 10: Escribe un programa que pida y lea una cadena de caracteres e imprima la misma cadena 
convirtiendo las letras mayúsculas en minúsculas y viceversa, manteniendo los caracteres que no 
son letras sin alterar. 

*/

#include <stdio.h>

int main() {
    char txt[0xFF];
    scanf("%[^\n]", txt);

    for(int i = 0; txt[i] != '\0'; i++) {
        if(txt[i] >= 'A' && txt[i] <= 'Z')
            printf("%c",txt[i] |= ' ');
        
        else if(txt[i] >= 'a' && txt[i] <= 'z')
            printf("%c",txt[i] &= '_');
        
        else printf("%c",txt[i]);
    }

    printf("\n");

    return 0;
}
