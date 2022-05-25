/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 5: ordenar numeros e imprimirlos palante y patras
*/

#include <stdio.h>

int main() {
    int n, min;
    scanf("%d", &n);
    int arr[n]; // números

    for(int i = 0; i < n; ++i) { // escanear números
        scanf("%d", &arr[i]);
    }
    
    min = arr[0]; // min = primer numero

    for(int i = 0; i < n; ++i) { // recorre el arreglo de izquierda a derecha pasando una vez por número
        for(int j = i; j < n; ++j) { // 
            if(arr[j] < arr[i]) {
                min = arr[j]; // si arr j es menor que el minimo
                arr[j] = arr[i];
                arr[i] = min;    
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    for(int i = n-1; i >= 0; --i) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
