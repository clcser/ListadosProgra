/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio con ayuda de Ana Villagran 

Ej 7: Imprimir todas las combinaciones de n numeros en 3 lugares
*/

#include <stdio.h>

int main() {
    int n, cont;
    scanf("%d", &n);

    int nums[n];
    int pos1[n];
    int pos2[n];
    int pos3[n];

    for(int i = 0; i < n; i++) {
        scanf("%d",&nums[i]);
        pos1[i] = pos2[i] = pos3[i] = nums[i];
    }

    cont = 1;
    for(int i = 0; i < n-2 ; i++) {
        for(int j = i+1; j < n-1; j++) {
            for(int k = j+1; k < n; k++) {
                printf("%d %d %d\n", nums[i], nums[j], nums[k]);
            }
        }
    }

    return 0;
}
