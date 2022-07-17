/*
Claudia Cser
Solucion propia

Implemente la función busquedaBinaria, que reciba un arreglo (ordenado), un elemento a buscar y los ı́ndices 
inferior y superior entre los cuales buscar el elemento y devuelva la primera posición en la que se encuentra. 
En caso de no encontrar el elemento, deberá retornar −1:
*/

#include <stdio.h>
#include <stdlib.h>

int busquedaBinaria(int * v, int elem, int limInferior, int limSuperior) {
    
    if(limInferior >= limSuperior)
        return -1;

    int mitad = (limSuperior+limInferior)/2;
    if(v[mitad] == elem) 
        return mitad;
    
    else if(elem > v[mitad])
        busquedaBinaria(v,elem,mitad+1,limSuperior);
    
    else if(elem < v[mitad])
        busquedaBinaria(v,elem,limInferior,mitad-1);
}

/*
int main() {
    int *v, elem, inf, sup, existe;
    v = malloc(10 * sizeof(int));
 
    for(int i = 0; i<10; i++) {
        scanf("%d", &v[i]);
    }
    scanf("%d", &elem);
    scanf("%d", &inf);
    scanf("%d", &sup);
    
    existe = busquedaBinaria(v,elem,inf,sup);

    printf("%d\n", existe);
    return 0;
}
*/
