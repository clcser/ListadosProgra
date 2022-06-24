/*
Claudia Cser
Solucion propia

Escriba una función int longitudPalabraMasLarga(int n, char crucigrama[n][n]) que recibe una matriz de caracteres
que guarda la información de un crucigrama. Cada casilla de la matriz puede contener una letra minúscula o el 
caracter '-', que significa una celda bloqueada. Cada palabra del crucigrama puede ser horizontal (de izquierda a
derecha) o vertical (de arriba a abajo) y puede comenzar o bien en una celda exterior o justo después (a la 
derecha o abajo) de una celda bloqueada. La función deberá devolver la longitud de la palabra más larga del 
crucigrama. 
*/

#include <stdio.h>
#include <limits.h>

int longitudPalabraMasLarga(int n, char crucigrama[n][n]) {
    int len, maxLen = INT_MIN;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            len = 0;
            for(int a = i; a < n; a++) {
                if(crucigrama[a][j] == '-') 
                    break;
                else 
                    len++;
            }
            maxLen = len > maxLen ? len:maxLen;
            len = 0;
            for(int b = j; b < n; b++) {
                if(crucigrama[i][b] == '-')
                    break;
                else
                    len++;
            }
            maxLen = len > maxLen ? len:maxLen;
            len = 0;
        }
    }
    return(maxLen);
}

// Incluí el main para probar la funcion
// Ingresar tamaño del crucigrama, luego ingresar letras de izquierda a derecha y de arriba hacia abajo 

int main() {
    int n, l;
    scanf("%d", &n);
    getchar();

    char mat[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%c", &mat[i][j]);
        }
        getchar();
    }
 
    l = longitudPalabraMasLarga(n, mat);
    printf("%d\n",l);

    return 0;
}
