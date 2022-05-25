/*

Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de forma individual

Ej 5: Escribe un programa que pida un número entero y un caracter e imprima: contenido en caso de 
que el 8 bits codificando caracter se corresponda con alguno de los 4Bytes que constituyen el número 
entero. En caso contrario, imprimir el número entero que se formaría al concatenar los bits 
correspondientes al caracter cuatro veces. 

*/

#include <stdio.h>

int main() {
    int n, aux, conc;
    char c;

    scanf("%d %c", &n, &c);

    for(int i = 0; i<4; i++) {
        aux = 0xFF << (8*i) & n;
        
        if((aux >> 8*i) == c) {
            printf("contenido\n");
            return 0;
        }
    }
    
    conc = 0;
    
    for(int i = 0; i<4; i++) {
        conc += (c << i*8);
    }
    printf("%d\n", conc); 

    return 0;
}
