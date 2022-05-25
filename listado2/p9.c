/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Ej 9: imprimir punto medio de la region formada por las coordenadas mayor y menor
*/


#include <stdio.h>

int main() {
    int n, absMay, absMen, ordMay, ordMen;
    scanf("%d", &n);

    int abs, ord;
    scanf("%d%d", &absMen, &ordMen);
    absMay = absMen;
    ordMay = ordMen;

    for(int i = 0; i < n-1; i++) {
        scanf("%d%d", &abs, &ord);
        
        if(absMay < abs) absMay = abs;
        else if(absMen > abs) absMen = abs;
        
        if(ordMay < ord) ordMay = ord;
        else if(ordMen > ord) ordMen = ord;
    }
    // debug
    //printf("absMen: %d, absMay: %d, ordMen: %d, ordMay: %d\n", absMen,absMay,ordMen,ordMay);
    printf("%d , %d\n", (absMen+absMay)/2 ,(ordMay+ordMen)/2);

    return 0;
}
