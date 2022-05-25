/*
Autor: Claudia Cser
Usuario Timus: clcser
Ana Villagran me ayudo a comprender este ejercicio, muchas gracias Ana<3

Ej 12: 1787 timus
*/



#include <stdio.h>

int main() {
    int k, n, cars, tot;
    scanf("%d%d", &k, &n);
    tot = 0;

    int arr[n];
    for(int i = 0; i< n; i++) {
        scanf("%d", &arr[i]);
        tot += arr[i];

        if(tot >= k) {
            tot -= k;
        } else tot = 0;
    }
    printf("%d\n",tot);   
 
    return 0;
}
