/*
Autor: Claudia Cser
Usuario Timus: clcser
Ejercicio resuelto de manera individual

Timus #1785 (Lost in Localization)
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if(1 <= n && n <= 4)
        printf("few");
    else if(5 <= n && n <= 9)
        printf("several");
    else if(10 <= n && n <= 19)
        printf("pack");
    else if(20 <= n && n <= 49)
        printf("lots");
    else if(50 <= n && n <= 99)
        printf("horde");
    else if(100 <= n && n <= 249)
        printf("throng");
    else if(250 <= n && n <= 499)
        printf("swarm");
    else if(500 <= n && n <= 999)
        printf("zounds");
    else printf("legion");

    return 0;
}
