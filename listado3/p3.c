/*

Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de forma individual

Ej 3: Escribe un programa que pida un número entero n, a continuación, pida ingresar n números de 
coma flotante (usar precisión doble) y luego imprima: el menor (en notación científica), el mayor 
(siempre incluyendo el signo y ocupando, al menos, 10 caracteres), la media (que ocupe, al menos, 
10 caracteres y tenga dos decimales de precisión), la mediana (con 4 decimales de precisión), la 
desviación media(con 2 decimales de precisión), la desviación estándar (en el formato más corto, 
con 3 decimales de precisión) y la varianza (en el formato más corto) del conjunto de números.

*/

#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {
    int n;
    double may=INT_MIN, men=INT_MAX, med=0, medn, dMed=0, dEst, var=0,sum;
    
    scanf("%d",&n);
    double num[n];

    // recibir input y calcular mayor, menor y media
    for(int i = 0; i < n; i++) {
        scanf("%lf", &num[i]);
        if(num[i] > may) may = num[i];
        if(num[i] < men) men = num[i];
        med += num[i];
    }
    med /= n;
    
    // calcular varianza, desviacion media y desviacion estandar
    for(int i = 0; i < n; i++) {
        var += (num[i]-med)*(num[i]-med);
        
        sum = num[i]-med;
        if(sum<0) sum *= -1; // valor absoluto   
        dMed += sum;
    }
    dMed /= n;
    var /= n;
    dEst = sqrt(var);
 
    // ordenar el arreglo
    for(int i = 0; i < n-1; i++) {
        int min = num[i];
        int posmin = i;
        for(int j = i+1; j < n; j++) {
            if(num[j] < min) {
                min = num[j];
                posmin = j;
            }
        }
        num[posmin] = num[i];
        num[i] = min;
    }

    // calcular mediana
    if(n % 2) medn = num[n/2];
    else medn = (num[n/2]+num[n/2-1])/2;
   
    printf("menor: %e\nmayor: %010f\nmedia: %010.2f\nmediana: %.4f\ndesviacion media: %.2f\ndesviacion estandar: %.4g\nvarianza: %g\n",men,may,med,medn,dMed,dEst,var);
    
    return 0;
}
