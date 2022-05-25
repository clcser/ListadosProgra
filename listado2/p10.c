/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 10: Determinante matriz 4x4
*/

#include <stdio.h>

int main() {
    int mat[4][4], m3x3[4][3][3];
    // obtener input
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    int det1,det2,det3,det4;
    det1 = det2 = det3 = det4 = 0;
    // obtener matrices 3x3
    for (int ignore = 0; ignore < 4; ignore++) {
        for (int i = 0, cont = 0; i < 4; i++) {
            if (i == ignore) continue;
            for (int j = 1; j < 4; j++) {
                m3x3[ignore][cont][j-1] = mat[i][j];
            }    
            cont++;
        }
    }
    // imprimir matrices 3x3
    for (int ignore = 0; ignore < 4; ignore++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) 
                printf("%d ", m3x3[ignore][i][j]);
            printf("\n");
        }
        printf("\n");
    }
    // obtener determinantes de cada matriz 3x3
    int det = 0;
    for (int ignore = 0; ignore < 4; ignore++) {
        int aux = 
            m3x3[ignore][0][0]*m3x3[ignore][1][1]*m3x3[ignore][2][2] +
            m3x3[ignore][0][1]*m3x3[ignore][1][2]*m3x3[ignore][2][0] +
            m3x3[ignore][0][2]*m3x3[ignore][1][0]*m3x3[ignore][2][1] -
            m3x3[ignore][2][0]*m3x3[ignore][1][1]*m3x3[ignore][0][2] -
            m3x3[ignore][2][1]*m3x3[ignore][1][2]*m3x3[ignore][0][0] -
            m3x3[ignore][2][2]*m3x3[ignore][1][0]*m3x3[ignore][0][1];
        //printf("%d\n",aux);
        //printf("%c%d * %d +\n",ignore%2==0 ? '+' : '-',mat[ignore][0],aux);
        //printf("%d\n",ignore%2==0 ? 1 : -1 * mat[ignore][0] * aux);
        det += mat[ignore][0] * aux * (ignore%2==0 ? 1 : -1);
    }
    printf("determinante = %d\n", det);

    return 0;
}
