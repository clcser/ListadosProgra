/*

Autor: Claudia Cser
Usuario Timus: clcser
Para la parte de imprimir solo las vocales me inspire en una respuesta al ejercicio "Vowel Count" de
la pagina codewars (link: https://www.codewars.com/kata/reviews/5c1a6c7a235e28bdc80013f3/groups/5d5d18172c5aee0001ba675d)

Ej 13: Escribe un programa que lea dos líneas de texto, a continuación, el programa deberá concatenar 
el resultado de invertir cada una de las líneas, para finalmente imprimir las vocales del resultado 
en el orden final. 

*/ 

#include <stdio.h>
#include <string.h>
#define VOW "aeiouAEIOU"

int main() {
    char c1[0xFF],c2[0xFF];
    int c1len, c2len;

    scanf("%[^\n] %[^\n]",c1,c2);
    
    c1len = strlen(c1);
    c2len = strlen(c2);
    int totLen = c1len + c2len;
    char conc[totLen+1];
    
    // dar vuelta ambas strings y concatenar
    int pos = 0;
    for(int i = c1len-1; i>=0; i--){ 
        conc[pos] = c1[i]; 
        pos++;    
    }
    for(int i = c2len-1; i>=0; i--) { 
        conc[pos] = c2[i];  
        pos++;
    }
    conc[totLen] = '\0';

    // imprimir solo las vocales 
    for(int i = 0; i < totLen; i++)
        if(strchr(VOW,conc[i]) != NULL)
            printf("%c",conc[i]);

    printf("\n");

    return 0;
}
