/*
Claudia Cser
Solucion propia

Escriba la función void ordenParcial(int* v1, int n, int cant) que recibe un vector de enteros v1, su tamaño n 
y un número entero cant y modifica el vector v1 de tal manera que las primeras cant posiciones contengan los 
cant números más grandes de v1 y éstos se encuentren ordenados ascendentemente. v1 deberá mantener todos los 
elementos inicialmente almacenados, sólo cambiar su posición para que se cumpla el invariante antes descrito.
 */

#include <stdio.h>

void ordenParcial(int *v1, int n, int cant) {
    for(int i = 0; i < cant; i++) {
        for(int j = i+1; j < n; j++) {
            if(v1[j] > v1[i]) {
                int aux = v1[i];
                v1[i] = v1[j];
                v1[j] = aux;
            }
        }
    }
    for(int i = 0; i < cant/2; i++) {
        int aux = v1[i];
        v1[i] = v1[cant-1-i];
        v1[cant-1-i] = aux;
    }
}

// Incluí el main para probar la funcion

int main() {
    int n, cant;

    scanf("%d %d", &n, &cant);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    ordenParcial(a,n,cant);

    for(int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}
