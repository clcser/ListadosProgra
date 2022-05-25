/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Si exactamente dos numeros son pares o dos son impares imprimir variadito, en cualquier otro caso imprimir uniforme
*/

#include <stdio.h>

int main() {
    int evn = 0;    // Contador numeros pares
    int unvn = 0;   // Conrador numeros impares

    // Verificar cuantos numeros son pares/impares
    for(int i = 0; i < 3; i++) {
        int tmp;
        scanf("%d", &tmp);
        if ((tmp % 2) == 0) evn++;
        else unvn++;
    }

    // Imprimir
    if((evn == 2) || (unvn == 2)) 
        printf("variadito");
    else printf("uniforme");

    return 0;
}
