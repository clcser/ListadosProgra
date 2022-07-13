/*
Claudia Cser
Solucion propia

Escriba una función void modificarMatriz(int n, int m, int mat1[n][m]) que recibe una matriz, mat1 y reemplaza 
todas las apariciones del número 1, por un -1.  
*/

#include <stdio.h>

void modificarMatriz(int n, int m, int mat1[n][m]) {
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(mat1[i][j] == 1) 
                mat1[i][j] = -1;
}

// Incluí el main para probar la funcion

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int mat[a][b];
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    modificarMatriz(a,b,mat);

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
