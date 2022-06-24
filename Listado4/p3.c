/*
Claudia Cser
Solucion propia

Escriba una función long long mcd(long long n1, long long n2) que recibe un par de números enteros y devuelve
el máximo común divisor de ellos. 
*/

#include <stdio.h>

long long mcd(long long n1, long long n2) {
    long long i;
    i = n1 > n2 ? n1 : n2;
    while((n1%i != 0) || (n2%i != 0)) {
        i--;
    }
    return i;
}

// Inclui el main para probar la funcion

int main() {
    long long num1, num2, res;
    scanf("%lld %lld", &num1, &num2);

    res = mcd(num1, num2);
    printf("%lld\n", res);

    return 0;
}

