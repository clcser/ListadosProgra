/* 
Claudia Cser
Solucion propia

P1: Escriba una función llamada operacion que reciba tres parámetros: op, v1, v2.
op es un caracter, y v1 y v2 son números de coma flotante de precisión doble. La función
deberá devolver un número de precisión doble, que corresponde al resultado de sumar, restar,
multiplicar o dividir v1 y v2, dependiendo de si el valor de op es +, -, * o / 
*/

#include <stdio.h>

double operacion(char op, double v1, double v2) {
    double res;
    if(op == '+') { 
        res = v1 + v2;
        return(res);
    }
    else if(op == '-') {
        res = v1 - v2;
        return(res);
    }
    else if(op == '*') {
    res = v1 * v2;
        return(res);
    }
    else if(op == '/') {
        res = v1 / v2;
        return(res);
    }
}

// Incluí el main para probar la funcion 

int main() {
    char c;
    double n1,n2,r;

    scanf("%c", &c);
    scanf("%lf %lf", &n1,&n2);
    
    r = operacion(c,n1,n2);
    printf("%lf", r);

    return 0;
}
