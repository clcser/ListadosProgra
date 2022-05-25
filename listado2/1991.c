/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 14: 1991 timus 
*/

#include <stdio.h>

int main() {
    int n, k, num, surv, unused;
    scanf("%d%d", &n, &k);
    
    surv = unused = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        if(num > k) unused += num-k;
        else if(num < k) surv += k-num;
    }
    printf("%d %d\n", unused, surv);

    return 0;
}
