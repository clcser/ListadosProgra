/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 3: Imprimir minimo, maximo, promedio y mediana de un grupo de n numeros
*/

#include <stdio.h>

int main() {
    int n, min, med, avrg; // cantidad de números, mínimo, mediana
    scanf("%d", &n);
    int arr[n]; // números

    for(int i = 0; i < n; ++i) { // escanear números
        scanf("%d", &arr[i]);
    }
    
    min = arr[0]; // min = primer numero
    avrg = 0;
    for(int i = 0; i < n; ++i) { // recorre el arreglo de izquierda a derecha pasando una vez por número
        for(int j = i; j < n; ++j) { // 
            if(arr[j] < arr[i]){
                min = arr[j]; // si arr j es menor que el minimo
                arr[j] = arr[i];
                arr[i] = min;    
            }
        }
        avrg += arr[i];
    }

    med = n/2;    
    if(n%2 != 0) med += 1;
    printf("minimo = %d\nmaximo = %d\npromedio = %d\nmediana = %d\n", arr[0], arr[n-1],avrg/n, arr[med]);    
    return 0;
}
