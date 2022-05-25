/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 16: 1910 timus
*/


#include <stdio.h>

int main() {
    int n, sum, mdl;
    scanf("%d",&n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    sum = 0;
    for(int i = 0; i < n-2; i++) {
        if(arr[i]+arr[i+1]+arr[i+2] > sum) {
            sum = arr[i]+arr[i+1]+arr[i+2];
            mdl = i+2;
        }
    }
    printf("%d %d\n", sum, mdl);
    return 0;
}
