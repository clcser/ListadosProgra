/*
Claudia Cser
Solucion propia

P8: Escriba una función recursiva que reciba un arreglo y devuelva el mayor de los números en el arreglo.
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int mayor(int n, int *v) {
    if(n == 0) 
        return INT_MIN;
    if(n == 1) 
        return v[0];
    else {
        int compare = v[0] > mayor(n-1,v+1) ? v[0] : mayor(n-1,v+1);
        return compare;
    }
}

/*
int main() {
    int num, m, *vec;

    scanf("%d",&num);
    vec = malloc(num * sizeof(int));

    for(int i = 0; i<num; i++) {
        scanf("%d",&vec[i]);
    }
    
    m = mayor(num,vec);
    printf("%d\n", m);

    return 0;
}
*/
