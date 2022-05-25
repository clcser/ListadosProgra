/*

Autor: Claudia Cser
Usuario Timus: clcser
Ejerciio resuelto de forma individual

Ej 2: Escribe la representación en binario, octal y hexadecimal de los siguientes números en base 10:
29,131,2048,1211817,4000000001

*/

#include <stdio.h>

int main() {
    long int num, nums[5] = {29,131,2048,121817,4000000001};
    int c,bin[0xFF];

    // recorrer el arreglo
    for(int i = 0; i < 5; i++) {
        num = nums[i];
        c = 0;
        
        // convertir a binario
        while(num > 0) {
            bin[c] = (num & 1);
            num >>= 1;
            c++;
        }
        // imprimir
        printf("bin: ");
        for(int i = c-1; i >= 0; i--)
            printf("%d",bin[i]);

        printf(", oct: %lo, hex: %lx\n",nums[i],nums[i]);    
    }

    return 0;
}
