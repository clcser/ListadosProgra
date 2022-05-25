/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 8: ordenar coordenadas
*/


#include <stdio.h>

int main() {
    int n;
    do {
        scanf("%d", &n);
    } while(n < 0);

    int mat[n][2];
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &mat[i][0], &mat[i][1]);
    }
    int min[1][2];
    min[0][0] = mat[0][0];
    min[0][1] = mat[0][1];

    for(int i = 0; i < n; i++) {
        //printf("%d %d\n", mat[i][0], mat[i][1]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(mat[j][0] < mat[i][0]) {
                min[0][0] = mat[j][0];
                min[0][1] = mat[j][1];

                mat[j][0] = mat[i][0];
                mat[j][1] = mat[i][1];

                mat[i][0] = min[0][0];
                mat[i][1] = min[0][1];
            }
            
            else if(mat[j][0] == mat[i][0]) {
                if(mat[j][1] < mat[i][1]){
                    min[0][1] = mat[j][1];

                    mat[j][1] = mat[i][1];
                    
                    mat[i][1] = min[0][1]; 
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d, %d\n", mat[i][0], mat[i][1]);
    }

    return 0;
}
