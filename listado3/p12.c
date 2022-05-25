/*

Autor: Claudia Cser
Usuario Timus: clcser
Para este ejercicio usé codigo de la pagina cplusplus.com para utilizar la funcion strtok 
(link: https://cplusplus.com/reference/cstring/strtok/)

Ej 12: Escribe un programa que lea dos líneas de texto e imprima todas las palabras (sin repetir) 
que se encuentran en las dos líneas ingresadas. 

*/

#include <stdio.h>
#include <string.h>

int main() {
    char s1[0xFF], s2[0xFF];
    int s1Len, s2Len, s1Wrds = 1, s2Wrds = 1, pos = 0, flag;
    
    // obtener primera string
    scanf("%[^\n]", s1);
    getchar();
    // obtener segunda string
    scanf("%[^\n]", s2);
    
    s1Len = strlen(s1);
    s2Len = strlen(s2);

    // contar palabras de la primera string
    for(int i = 0; i < s1Len; i++) {
        if(s1[i] == ' ')
            s1Wrds++;
    }
    // contar palabras de la segunda string
    for(int i = 0; i < s2Len; i++) {
        if(s2[i] == ' ')
            s2Wrds++;
    }

    // crear arreglo con las palabras de la primera string
    char *cmp1[s1Wrds], *cmp2[s2Wrds], *word;

    word = strtok(s1," ");
    while (word != NULL) {
        cmp1[pos] = word;
        word = strtok(NULL," ");
        pos++;
    }
    // crear arreglo con las palabras de la segunda string
    pos = 0;
    word = strtok(s2," ");
    while (word != NULL) {
        cmp2[pos] = word;
        word = strtok(NULL," ");
        pos++;
    }

    // comparar primera string con la segunda e imprimir
    for(int i = 0; i < s1Wrds; i++) {
        flag = 0;
        for(int j = 0; j < s2Wrds; j++) {
            if(strcmp(cmp1[i],cmp2[j]) == 0) {
                flag = 1;
            }
        }
        if(flag == 0) printf("%s ",cmp1[i]);
    }
    // comparar segunda string con la primera e imprimir
    for(int i = 0; i < s2Wrds; i++) {
        flag = 0;
        for(int j = 0; j < s1Wrds; j++) {
            if(strcmp(cmp1[i],cmp2[j]) == 0) {
                flag = 1;
            }
        }
        if(flag == 0) printf("%s ",cmp2[i]);
    }
    printf("\n");

    return 0;
}
