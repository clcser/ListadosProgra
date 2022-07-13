/*
Claudia Cser
Solucion propia

Escriba una función long long mcm(long long n1, long long n2) que recibe un par de números enteros y 
devuelve el mı́nimo común múltiplo de ellos. 
*/

#include <stdio.h>

long long mcm(long long n1, long long n2) {
    long long i = 2, mcm = 1;
    while(n1 != n2) {
        while((n1%i == 0) || (n2%i == 0)) {
            if(n1%i == 0) {
                n1 /= i;
            }
            if(n2%i == 0) {
                n2 /= i;
            }
            mcm *= i;
        }
        i++;
    }
    return mcm;
}

// Incluí el main para probar la funcion

int main() {
    long long num1, num2, res;
    scanf("%lld %lld", &num1, &num2);
    res = mcm(num1,num2);
    printf("%lld\n", res);

    return 0;
}
