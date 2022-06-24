/*
Claudia Cser
Solucion propia

Escriba una función int buscar(int n, double* v, double e) que recibe un arreglo de números de coma flotante de 
doble precisión v, su tamaño n y un elemento a buscar e. La función deberá devolver la posición del elemento en 
el arreglo, en caso de estar contenido, o −1 en caso contrario. Recuerde que para la comparación de números de 
punto flotante, se debe utilizar un margen de error, por posibles errores de precisión. Utilice la constante 
1 × 10 ^−6 como constante para error de precisión. Implemente esta función sin utilizar el operador [ ].
 */

#include <stdio.h>
#include <stdlib.h>

const double ERROR = 0.000001;

int buscar(int n, double *v, double e) {
    for(int i = 0; i < n; i++) {
        if(abs(*(v+i) - e) <= ERROR)
            return i;
    }
    return -1;
}

// Incluí el main para probar la funcion
// Ingresar tamaño del arreglo, numero a buscar, y luego los elementos del arreglo

int main() {
    int n, pos;
    scanf("%d",&n);
    
    double num;
    scanf("%lf",&num);
    printf("\n");

    double *arr = malloc(n*sizeof(double));

    for(int i = 0; i<n; i++) {
        scanf("%lf",&arr[i]);
    }

    pos = buscar(n,arr,num);
    printf("\n%d\n",pos);
    free(arr);

    return 0;
}
