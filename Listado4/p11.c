/*
Claudia Cser
Solucion propia

Escriba una función:

void estadisticos( int n, double* v, double* min, double* max, double* devEst, double* prom, double* med)

que recibe un arreglo de números de coma flotante de doble precisión v y su tamaño n y calcula y almacena en los 
parámetros por referencia min,max,mediana,promedio,devEst su valor mı́nimo, el máximo, la mediana, el promedio y 
la desviación estándar respectivamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void estadisticos(int n, double* v, double* min, double* max, double* devEst, double* prom, double* med) {
    double aux;
    
    // ordenar arreglo
    for(int i = 0; i < n; i++) { 
        for(int j = i + 1; j < n; j++) {
            if(v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    // mediana
    if(n%2) {
        *med = v[n/2];
    } else {
        *med = (v[n/2] + v[n/2-1])/2;
    }
    // minimo y maximo
    *min = v[0];
    *max = v[n-1];
    
    // promedio
    *prom = 0;
    for(int i = 0; i < n; i++) {
        *prom += v[i];
    }
    *prom /= n;

    //desviacion estandar
    *devEst = 0;
    for(int i = 0; i < n; i++) {
        *devEst += (v[i] - *prom) * (v[i] - *prom);
    }
    *devEst /= n;
    *devEst = sqrt(*devEst);
}

// Incluí el main para probar la funcion
// Ingresar tamaño del vector, luego los elementos separados por espacio o enter

int main() {
    int a;
    scanf("%d",&a);

    double *v = malloc(a*sizeof(double));
    double min=0,max=0,devEst=0,prom=0,med=0;
     
    for(int i = 0; i < a; i++) {
        scanf("%lf", &v[i]);
    }
     
    estadisticos(a, v, &min, &max, &devEst, &prom, &med);

    printf("min: %lf\nmax: %lf\ndevEst: %lf\nprom: %lf\nmed: %lf\n", min,max,devEst,prom,med);

    free(v);

    return 0;
}
