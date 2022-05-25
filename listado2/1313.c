/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual + 3 tazas de cafe

Ej 17: 1313 timus
*/


#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    int arr[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    if(n == 1) {
        printf("%d\n", arr[n-1][n-1]);
        return 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0, k = i; j <= i; j++, k--) {
            printf("%d ", arr[k][j]);
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = n-1, k = i; k < n; j--, k++) {
            printf("%d ", arr[j][k]);
        }
    }

    return 0;
}

