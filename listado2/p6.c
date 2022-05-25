/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 6: Imprimir n niveles del triangulo de pascal
*/

#include <stdio.h>

int main() { 
    int n;
    scanf("%d", &n);

    int arr[n];
    
    arr[0] = 1;
    arr[1] = 1;

    for(int i = 1; i < n; ++i) {
        arr[i] = 1;
        for(int j = i-1; j > 1; j--){
            arr[j] += arr[j-1];
        }
        for(int k = 1; k <= i; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    return 0;
}
