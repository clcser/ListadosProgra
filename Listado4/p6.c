/*
Claudia Cser
Solucion propia

Escriba la función int determinante(int n, int m1[n][n]) que reciba una matriz m1 de tamaño n × n y devuelva el
determinante de la matriz. El valor de n solo puede ser 2, 3 o 4, en caso de que n tome un valor diferente, la 
función deberá devolver la constante INT_MIN. 
*/

#include <stdio.h>
#include <limits.h>

int det2(int m00, int m01, int m10, int m11) {
    int det = m00*m11 - m01*m10;
    return det;
}

int det3(int m00, int m01, int m02, int m10, int m11, int m12, int m20, int m21, int m22) {
    int det = m00*det2(m11,m12,m21,m22) 
        - m01*det2(m10,m12,m20,m22) 
        + m02*det2(m10,m11,m20,m21);
    return det;
}

int det4(int m00, int m01, int m02, int m03, int m10, int m11, int m12, int m13, int m20, int m21, int m22, int m23, int m30, int m31, int m32, int m33) {
    int det = m00 * det3(m11,m12,m13,m21,m22,m23,m31,m32,m33) 
        - m01 * det3(m10,m12,m13,m20,m22,m23,m30,m32,m33) 
        + m02 * det3(m10,m11,m13,m20,m21,m23,m30,m31,m33) 
        - m03 * det3(m10,m11,m12,m20,m21,m22,m30,m31,m32);
    return det;
}

int determinante(int n, int m1[n][n]) {
    int det;
    if(n == 2) {
        det2(m1[0][0],m1[0][1],m1[1][0],m1[1][1]);    
    }
    else if(n == 3) {
        det3(m1[0][0],m1[0][1],m1[0][2],m1[1][0],m1[1][1],m1[1][2],m1[2][0],m1[2][1],m1[2][2]);
    }
    else if(n == 4) {
        det4(m1[0][0],m1[0][1],m1[0][2],m1[0][3],m1[1][0],m1[1][1],m1[1][2],m1[1][3],m1[2][0],m1[2][1],m1[2][2],m1[2][3],m1[3][0],m1[3][1],m1[3][2],m1[3][3]);
    }
    else return(INT_MIN);
}

// Incluí el main para probar la funcion

int main() {
    int n,det;
    scanf("%d",&n);

    int m[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    det = determinante(n,m);

    printf("%d\n", det);

    return 0;
}
