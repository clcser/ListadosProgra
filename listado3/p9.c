/*

Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de forma individual

Ej 9: Escribe un programa que redondee un número decimal, recibido por entrada, al entero 
correspondiente. Entregue el resultado como un número entero. 

*/

#include <stdio.h>

int main() {
    float n;
    scanf("%f",&n);
    
    int dec = (n-(int)n)*10;

    if(dec >= 5) printf("%d\n",(int)n+1);
    else printf("%d\n",(int)n);

    return 0;
}
