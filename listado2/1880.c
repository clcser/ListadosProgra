/*
Autor: Claudia Cser
Usuario Timus: clcser
Resolví este ejercicio con ayuda de Leonardo Lovera. Muchas gracias Leo, sin ti no lo hubiese logrado

Ej 15: timus 1880
*/


// codigo escrito con ayuda de Leonardo Lovera

#include <stdio.h>

int main() {
    int n1,n2,n3,may,cont;
    
    scanf("%d", &n1);
    int arr1[n1];
    for(int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);
    
    scanf("%d", &n2);
    int arr2[n2];

    for(int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    scanf("%d", &n3);
    int arr3[n3];
       
    for(int i = 0; i < n3; i++)
        scanf("%d", &arr3[i]);

    cont = 0;
    for(int i = 0; i < n1; i++)
        for(int j = 0; j < n2; j++)
            if(arr1[i] == arr2[j])
                for(int k = 0; k < n3; k++)
                    if(arr1[i] == arr3[k]) {
                        cont ++;
                        break;
                    }
    printf("%d", cont);
    return 0;
}
