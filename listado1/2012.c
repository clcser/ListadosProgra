/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Timus #2012 (About Grisha N)
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if((12-n)*0.75 < 4) 
        printf("YES");
    else printf("NO");

    return 0;
}
