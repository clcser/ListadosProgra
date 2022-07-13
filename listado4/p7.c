/*
Claudia Cser
Solucion propia

Escriba la función int caracteresComunes(char* cadena1, char* cadena2) y devuelva el número de caracteres 
comunes que tienen la cadena1 y la cadena2. 

Codigo hecho tomando en cuenta la tabla ASCII no extendida
*/

#include <stdio.h>
#include <string.h>

int caracteresComunes(char *cadena1, char *cadena2){
    int c1Words[128] = {0};
    int c2Words[128] = {0};
    int c1Len = strlen(cadena1);
    int c2Len = strlen(cadena2);
    int inCommon = 0, pos;

    for(int i = 0; i < c1Len; i++) {
        pos = cadena1[i];
        c1Words[pos] = 1;
    }
    for(int i = 0; i < c2Len; i++) {
        pos = cadena2[i];
        c2Words[pos] = 1;
    }

    for(int i = 0; i < 128; i++) {
        if(c1Words[i] && c2Words[i]) {
            inCommon += 1; 
        }
    }
    return inCommon;
}

// Incluí el main para probar la funcion

int main() {
    int comunes;
    char c1[0xFF], c2[0xFF];

    scanf("%[^\n]",c1);
    getchar();
    scanf("%[^\n]",c2);
    getchar();
    comunes = caracteresComunes(c1,c2);

    printf("%d\n",comunes);

    return 0;
}
